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
#define KLEUR_ROOD 0xFF0000   // Rood
#define KLEUR_GROEN 0x00FF00  // Groen
#define KLEUR_BLAUW 0x0000FF  // Blauw

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
  /*
  Ziet dat er ingewikkeld uit? Meer uitleg:
  - Wat wil je doen?
    Je wilt alle pixels één voor één rood maken.
    Maar je hebt er bijvoorbeeld 8, 16 of 64 — dat zijn er wel veel om apart op te schrijven.
  - De for-herhaling helpt daarbij ('for' is Engels en betekent 'voor')
    For zorgt ervoor dat de computer iets steeds opnieuw doet, zolang een bepaalde regel geldt.
  - Wat gebeurt er?
    int i = 0; → we beginnen bij pixel nummer 0 (de eerste pixel).
    i < AANTAL_PIXELS; → zolang i kleiner is dan het totaal aantal pixels, blijft de herhaling doorgaan.
  - i++; → na elke ronde wordt i één groter (dus eerst 0, dan 1, dan 2, enzovoort).
    Je kan het ook schrijven als i = i + 1, maar i++ is korter.

  Wat gebeurt er binnen de herhaling?
  - De pixel met nummer i krijgt de kleur rood.
  - Dus eerst pixel 0, dan pixel 1, enzovoort. Totdat alle pixels rood zijn.

  In mensentaal:
  - De computer telt van 0 tot de laatste pixel en maakt elke pixel rood.
  */
  // Toon de pixels
  pixels.show();
  // Wacht 1 seconde (= 1000 milliseconden)
  delay(1000);
  // Alle pixels uit
  pixels.clear();
  // Toon nu de gedoofde pixels
  pixels.show();
  // Eén seconde wachten
  delay(1000);

  /*
  Dit is al heel wat leuker, we gaan nu weer wat meer kleur toevoegen.
  Vul de sketch aan dat zodat de leds niet meer uit gaan, maar telkens oplichten in de volgorde:
  - Eén seconde lang rood
  - Twee seconden lang groen
  - Drie seconden lang blauw
  - En weer terug naar het begin van de lus.
  */
}
