Opendag 2025-2026 Summa ICT

- Laptop met Arduino IDE en VS Code (met plugin live server)
- Arduino met Ethernet shield (WMOSD1)
- USB kabel
- Arduino Uno met Open Smart Rich Shield
- Code in deze repository


Voor code in temp_light map gebruiken je de arduino met shield (zie afbeelding). De code is al geupload.
De temperatuur sensor geeft een temperatuur die te zien is in de seriële monitor van de Arduino IDE. Tevens zijn er enkele if statements die de LED's aansturen op basis van de temperatuur. Je kunt de temperatuur in de if statements zodat deze overeenkomt met de gewenste drempelwaarden in het lokaal.


De WeMos gebruiken we als een webserver. Hiervoor moet je de laptop van het internet halen en een vast ip adres geven (bijv. 192.168.10.1). De WeMos krijgt dan een ip adres in dezelfde range (bijv. 192.168.10.2).

Start de HTML pagina in de map Face-Detection.
Open de live server in VS code (rechter muisknop op index.html -> Open with Live Server)

De pagina maakt verbinding met de WeMos en de api (webserver) op de WeMos en geeft de expressions weer die de camera detecteert. Op basis van de "sad expression" wordt er een lichtje aangezet.

Verhaal 1:
Op basis van de temperatuur gaat een infrarood lamp aan of uit. Een blauwe lamp staat dan voor verkoeling.

Verhaal 2:
Op basis van de gezichtsuitdrukking (blij of verdrietig) gaat er een lamp aan of uit. Een soort van lichttherapie.