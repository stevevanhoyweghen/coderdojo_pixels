#include <Adafruit_NeoPixel.h>

// Vaste waarden om het programma leesbaarder te maken. Daarvoor gebruiken we #define ...

// Arduino Uno, bordselectie: 'Arduino Uno'
// #define PIXEL_PIN 11  // ESP32 DEV module pin pixels

// ESP32 DEV module, bordselectie: 'ESP32 DEV module'
// #define PIXEL_PIN 13  // ESP32 DEV module pin pixels

// ESP32 C3 Super Mini (Plus), bordselectie: 'Nologo ESPC3 Super Mini'
#define PIXEL_PIN 0  // ESP32 C3 Super Mini (Plus) pin pixels

#define AANTAL_PIXELS 24  // Pas dit aan voor het aantal pixels dat jij op jouw pixelring hebt. 8, 12, 16 of 24.

// Dit zijn de codes om kleuren te kiezen voor de pixel, meer uitleg komt later.
#define KLEUR_ROOD 0xFF0000     // Rood
#define KLEUR_GEEL 0xFFFF00     // Geel
#define KLEUR_GROEN 0x00FF00    // Groen
#define KLEUR_INDIGO 0x00FFFF   // Indigo
#define KLEUR_BLAUW 0x0000FF    // Blauw
#define KLEUR_MAGENTA 0xFF00FF  // Magenta
#define KLEUR_WIT 0xFFFFFF      // Wit

#define PIXEL_HELDERHEID 10  // Pas hier de helderheid aan van de pixels. 0 is donker tot 255 is helder.

// Hier bepaal je het aantal pixels, welke pin aansluiting, welk type pixels.
Adafruit_NeoPixel pixels(AANTAL_PIXELS, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

// Alles klaar zetten
void setup() {
  // De pixels klaarmaken voor gebruik
  pixels.begin();                          // initialisatie pixels
  pixels.setBrightness(PIXEL_HELDERHEID);  // Helderheid aanpassen van 0 (donker) tot 255 (helder)
}

// Hoofdlus
void loop() {
  // Zet alle pixels op rood
  for (int i = 0; i < AANTAL_PIXELS; i++)
    pixels.setPixelColor(i, KLEUR_ROOD);
  // Toon de pixels
  pixels.show();
  // Wacht 1 seconde (= 1000 milliseconden)
  delay(1000);

  for (int i = 0; i < AANTAL_PIXELS; i++)
    pixels.setPixelColor(i, KLEUR_GROEN);
  pixels.show();
  delay(2000);

  for (int i = 0; i < AANTAL_PIXELS; i++)
    pixels.setPixelColor(i, KLEUR_BLAUW);
  pixels.show();
  delay(3000);

  /*
  Als we nog meer kleuren en wachttijden willen toevoegen moeten we steeds bijna dezelfde code schrijven.
  Als we steeds opnieuw hetzelfde of bijna hetzelfde stukje code gebruiken is dat te veel herhaling!
  We willen niet steeds hetzelfde stukje code opnieuw moeten typen.
  Dat is saai en maakt het programma moeilijker om te lezen. Daarom gebruiken we een functie.

  Wat is een functie?
  Een functie is een stukje programma dat je één keer schrijft, en daarna telkens kunt oproepen.

  Hoe maak je een functie?
  We stoppen het herhaalde stukje in een nieuwe functie, bijvoorbeeld:
  
  void kleurAllePixels(uint32_t kleur) {
    for (int i = 0; i < AANTAL_PIXELS; i++)
      pixels.setPixelColor(i, kleur);
    pixels.show();
  }
  Wat uitleg:
  - 'void' betekent 'leeg' in het Engels. We keren dus niets terug.
  - 'kleurAllePixels' is de functienaam. Kies steeds een duidelijk naam dat aangeeft wat de functie doet.
  - 'uint32_t' is een afkorting voor 'unsigned long' en wil zeggen dat we een geheel getal hebben van 32 bits lang.
     https://docs.arduino.cc/language-reference/en/variables/data-types/unsignedLong/
  - kleur is de naam van een variabele die we binnen de functie gebruiken
  -   En zo gebruik je het: 'kleurAlles(KLEUR_GROEN);' om alle pixels groen te kleuren.
  
  Samengevat:
  Een functie is een soort recept.
  Je schrijft één keer op hoe je iets doet (bv. “alle pixels een kleur geven”),
  en daarna kun je gewoon zeggen: “doe het recept voor rood” of “doe het recept voor groen”.

  Als je goed kijkt zie je dat er enkele kleuren zijn toegevoegd.
  Gebruik ze allemaal in de volgorde die je wenst.

  Maar gebruik nu de functie void kleurAllePixels(uint32_t kleur) in plaats
  van telkens alles op te schrijven.
  */
}
