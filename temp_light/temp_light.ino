// DHT Temperature & Humidity Sensor
// Unified Sensor Library Example
// Written by Tony DiCola for Adafruit Industries
// Released under an MIT license.

// Depends on the following Arduino libraries:
// - Adafruit Unified Sensor Library: https://github.com/adafruit/Adafruit_Sensor
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library

// temp
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN            12         // Pin which is connected to the DHT sensor.
#define DHTTYPE           DHT11     // DHT 11 

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

// lights
#define LED1 7
#define LED2 6
#define LED3 5
#define LED4 4

uint8_t led[4];

void setup() 
{
  // lights
  led[0] = LED1;
  led[1] = LED2;
  led[2] = LED3;
  led[3] = LED4;

  // temp
  for(unsigned int i=0; i < 4; i++)
  {
        pinMode(led[i], OUTPUT);
        LEDoff(i+1);
  }
  Serial.begin(9600); 
  // Initialize device.
  dht.begin();
  Serial.println("DHTxx Unified Sensor Example");
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;
}


void loop() 
{
  // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;  
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) 
  {
    Serial.println("Error reading temperature!");
  }
  else 
  {
    Serial.print("Temperature: ");
    Serial.print(event.temperature);
    Serial.println(" *C");

    // zogenaamd infrarood voor minder dan 21 graden (oplopend naar groen en blauw licht)
    if(event.temperature < 21.00) {
      LEDoffAll();
      digitalWrite(led[3], HIGH);
    } else if(event.temperature < 22.00) {
      LEDoffAll();
      digitalWrite(led[2], HIGH);
    } else if(event.temperature < 23.00) {
      LEDoffAll();
      digitalWrite(led[1], HIGH);
    }
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) 
  {
    Serial.println("Error reading humidity!");
  }
  else 
  {
    Serial.print("Humidity: ");
    Serial.print(event.relative_humidity);
    Serial.println("%");
  }

  int time = 9;
  if (time < 10) {
    Serial.print("Good morning.");
  } else if (time < 20) {
    Serial.print("Good day.");
  } else {
    Serial.print("Good evening.");
  }
}

void LEDon(uint8_t num)//num = 1, 2, 3, 4
{
 if((num > 0) && (num < 5))
digitalWrite(led[num-1], HIGH);
}

void LEDoff(uint8_t num)//num = 1, 2, 3, 4
{
 if((num > 0) && (num < 5))
   digitalWrite(led[num-1], LOW);
}

void LEDoffAll()
{
  for(unsigned int i=0; i < 4; i++)
  {
        pinMode(led[i], OUTPUT);
        LEDoff(i+1);
  }
}