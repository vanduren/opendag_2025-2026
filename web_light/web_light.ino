
#include "WiFiS3.h"
#include "arduino_secrets.h" 
///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;                 // your network key index number (needed only for WEP)

int status = WL_IDLE_STATUS;

WiFiServer server(80);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }

  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }
  server.begin();
  // you're connected now, so print out the status:
  printWifiStatus();
}


void loop() {
  // list for incoming clients
  WiFiClient client = server.available();

  if (client) {
    Serial.print("New client connected...");    
    if (client.connected()) {
      int bytes = client.available();
      if (bytes > 0) {
        // read the whole http request 
        String request = "";    
        for (int i = 0; i < bytes; i++) {
          char c = client.read();
          request += c;
        }
        // print the http request
        Serial.println(request);        

        // parse http request 
        if (request.indexOf("GET /H") != -1) {
          // digitalWrite(ledPin, HIGH);
          digitalWrite(LED_BUILTIN, HIGH);
        }

        if (request.indexOf("GET /L") != -1) {
          // digitalWrite(ledPin, LOW);
          digitalWrite(LED_BUILTIN, LOW);
        }

        // send response 
        client.println("HTTP/1.1 200 OK");
        client.println("Content-type:text/html");
        client.println();
      } 
    }

    // close the connection
    client.stop();
    Serial.println("Client disconnected");
    delay(1000);
  }
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}