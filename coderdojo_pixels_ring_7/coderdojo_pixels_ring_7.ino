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

void kleurAllePixels(uint32_t kleur) {
  for (int i = 0; i < AANTAL_PIXELS; i++)
    pixels.setPixelColor(i, kleur);
  pixels.show();
}

// Alles klaar zetten
void setup() {
  // De pixels klaarmaken voor gebruik
  pixels.begin();                          // initialisatie pixels
  pixels.setBrightness(PIXEL_HELDERHEID);  // Helderheid aanpassen van 0 (donker) tot 255 (helder)
}

// Hoofdlus
void loop() {
  kleurAllePixels(pixels.Color(255, 0, 0));
  delay(500);
  kleurAllePixels(pixels.Color(255, 255, 0));
  delay(1000);
  kleurAllePixels(pixels.Color(0, 255, 0));
  delay(1500);
  kleurAllePixels(pixels.Color(0, 255, 255));
  delay(2000);
  kleurAllePixels(pixels.Color(0, 0, 255));
  delay(2500);
  kleurAllePixels(pixels.Color(255, 0, 255));
  delay(3000);
  kleurAllePixels(pixels.Color(255, 255, 255));
  delay(3500);

  /*
  Jouw volgende opdracht

  We kunnen nog veel meer kleuren maken door waarden tussen 0 en 255
  of 0x00 en 0xFF) te kiezen. We laten het toeval ons hier een beetje helpen.
  De functie 'random(255);' keert een willekeurige waarde van 0 tot en met 255 terug.
  Schrijf nu een programma dat elke 100 milliseconden alle pixels een willekeurige kleur geeft.
  Tip: je hebt maar twee programmaregels nodig.
  */
}
