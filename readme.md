Opendag 2025-2026 Summa ICT

- Laptop met Arduino IDE en VS Code (met plugin live server)
- Arduino met Ethernet shield (WMOSD1)
- Router (zonder internetverbinding)
- USB kabel
- Arduino Uno met Open Smart Rich Shield
- Code in deze repository



Voor code in temp_light map gebruik je de arduino met shield (zie afbeelding). De code is al geupload op de arduino.
De temperatuur sensor geeft een temperatuur die te zien is in de seriële monitor van de Arduino IDE. Tevens zijn er enkele if statements die de LED's aansturen op basis van de temperatuur. Je kunt de temperatuur in de if statements zodat deze overeenkomt met de gewenste drempelwaarden in het lokaal.


De Arduino R4 gebruiken we als een webserver. Hiervoor moet je de laptop van het internet halen en aan de router hangen. Netwerk naam en wachtwoord staan onder op de router. Dit is al ingesteld in de code. Na aansluiten krijg je als het goed is een IP adres (bijv. 192.168.0.100). De Arduino R4 krijgt dan een ip adres in dezelfde range (bijv. 192.168.0.101). Let op de adres in de code moet overeenkomen met het ip adres van de Arduino R4. Momenteel is dat 192.168.0.101.
Eventueel aan te passen in de code in de map Face-Detection -> face-api.js -> lijn 6513 en 6517.

Start de HTML pagina in de map Face-Detection.
Open de live server in VS code (rechter muisknop op index.html -> Open with Live Server)

De pagina maakt verbinding met de R4 en de api (webserver) op de R4 en geeft de expressions weer die de camera detecteert. Op basis van de "sad expression" wordt er een lichtje aangezet.

Verhaal 1 (arduino met shield):
Op basis van de temperatuur gaat een infrarood lamp aan of uit. Een blauwe lamp staat dan voor verkoeling.

Verhaal 2 (arduino met R4):
Op basis van de gezichtsuitdrukking (blij of verdrietig) gaat er een lamp aan of uit. Een soort van lichttherapie.