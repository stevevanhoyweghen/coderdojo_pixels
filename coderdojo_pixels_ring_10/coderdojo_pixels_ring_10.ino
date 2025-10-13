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
  for (int i = 0; i < AANTAL_PIXELS; i++) {
    pixels.setPixelColor(i, kleur);
    pixels.show();
  }
}

// Een functie die enkel de eerste pixel kleurt, daarna enkel de tweede, enzovoort
// tot en met de laatste pixel. Tussen elke stap is er een vertraging van 100 milliseconde.
void draaiendePixel(uint32_t kleur) {
  for (int i = 0; i < AANTAL_PIXELS; i++) {
    pixels.setPixelColor(i, kleur);
    pixels.show();
    delay(100);
    pixels.clear();
    pixels.show();
  }
}

// Een functie die enkel de laatste pixel kleurt, daarna enkel de voorlaatste, enzovoort
// tot en met de eerste pixel. Tussen elke stap is er een vertraging van 100 milliseconde.
void draaiendePixel2(uint32_t kleur) {
  for (int i = AANTAL_PIXELS - 1; i >= 0; i--) {
    pixels.setPixelColor(i, kleur);
    pixels.show();
    delay(100);
    pixels.clear();
    pixels.show();
  }
}
// Alles klaar zetten
void setup() {
  // De pixels klaarmaken voor gebruik
  pixels.begin();                          // initialisatie pixels
  pixels.setBrightness(PIXEL_HELDERHEID);  // Helderheid aanpassen van 0 (donker) tot 255 (helder)
}

// Hoofdlus
void loop() {
  kleurAllePixels(KLEUR_ROOD);
  delay(1000);
  pixels.clear();
  pixels.show();
  delay(100);  // Wacht 100 milliseconde
  draaiendePixel(KLEUR_BLAUW);

  // Hier is een exta functie die in de andere richting draait
  draaiendePixel2(KLEUR_BLAUW);

  /*
  Opdracht
  Pas draaiendePixel()en draaiendePixel2() op dezelfde manier aan zodat je de vertraging van
  100 milliseconden als een parameter kan meegeven.
  */
}
