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

void pixelsFlitsen(uint32_t kleur) {
  for (int i = 0; i < 10; i++) {
    kleurAllePixels(kleur);
    delay(40);
    pixels.clear();
    pixels.show();
  }
}

// Een functie die enkel de eerste pixel kleurt, daarna enkel de tweede, enzovoort.
// Tot en met de laatste pixel. Tussen elke stap is er een instelbare vertraging.
void draaiendePixel(uint32_t kleur, uint32_t vertraging) {
  for (int i = 0; i < AANTAL_PIXELS; i++) {
    pixels.setPixelColor(i, kleur);
    pixels.show();
    delay(vertraging);
    pixels.clear();
    pixels.show();
  }
}

// Een functie die enkel de laatste pixel kleurt, daarna enkel de voorlaatste, enzovoort.
// Tot en met de eerste pixel. Tussen elke stap is er een instelbare vertraging.
void draaiendePixel2(uint32_t kleur, uint32_t vertraging) {
  for (int i = AANTAL_PIXELS - 1; i >= 0; i--) {
    pixels.setPixelColor(i, kleur);
    pixels.show();
    delay(vertraging);
    pixels.clear();
    pixels.show();
  }
}

void pixelsStapsgewijsOpvullen(uint32_t kleur, uint32_t vertraging) {
  for (int i = 0; i < AANTAL_PIXELS; i++) {
    pixels.setPixelColor(i, kleur);
    pixels.show();
    delay(vertraging);
  }
}

void pixelsStapsgewijsOpvullen2(uint32_t kleur, uint32_t vertraging) {
  for (int i = AANTAL_PIXELS - 1; i >= 0; i--) {
    pixels.setPixelColor(i, kleur);
    pixels.show();
    delay(vertraging);
  }
}

// Elkaar achtervolgende pixels
// Geef een kleur door en een vertraging in milliseconden.
void pixelsAchtervolging(uint32_t kleur, int vertraging) {
  for (int a = 0; a < 10; a++) {   // Herhaal 10 keer
    for (int b = 0; b < 3; b++) {  // 'b' telt van 0 tot 2
      pixels.clear();              // Zet alle pixels uit
      // 'c' telt op van 'b' tot het einde van de pixels in stappen van 3
      for (int c = b; c < pixels.numPixels(); c += 3)
        pixels.setPixelColor(c, kleur);  // Kleur pixel 'c'
      pixels.show();                     // Pixels bijwerken met nieuwe inhoud
      delay(vertraging);                 // Pauzeer even
    }
  }
}

void pixelsSchittering(uint32_t kleur, int herhaling, int vertraging) {
  pixels.clear();
  pixels.show();

  for (int i = 0; i < herhaling; i++) {
    pixels.setPixelColor(random(AANTAL_PIXELS), kleur);
    pixels.show();
    delay(vertraging);
      pixels.clear();
      pixels.show();
  }

  delay(vertraging);
}

// Alles klaar zetten
void setup() {
  // De pixels klaarmaken voor gebruik
  pixels.begin();                          // initialisatie pixels
  pixels.setBrightness(PIXEL_HELDERHEID);  // Helderheid aanpassen van 0 (donker) tot 255 (helder)
}

// Hoofdlus
void loop() {
  pixelsSchittering(KLEUR_WIT, 50, 50);
  kleurAllePixels(pixels.Color(random(0xFF), random(0xFF), random(0xFF)));
  delay(300);
  kleurAllePixels(KLEUR_ROOD);
  delay(300);
  kleurAllePixels(KLEUR_GROEN);
  delay(300);
  kleurAllePixels(KLEUR_BLAUW);
  delay(300);
  pixelsFlitsen(KLEUR_WIT);
  pixelsStapsgewijsOpvullen(KLEUR_GEEL, 100);
  pixelsStapsgewijsOpvullen2(KLEUR_BLAUW, 100);
  draaiendePixel(KLEUR_INDIGO, 50);
  draaiendePixel2(KLEUR_MAGENTA, 100);
  pixelsAchtervolging(KLEUR_WIT, 40);
  pixelsAchtervolging(KLEUR_INDIGO, 60);
  pixelsAchtervolging(KLEUR_MAGENTA, 80);
}
