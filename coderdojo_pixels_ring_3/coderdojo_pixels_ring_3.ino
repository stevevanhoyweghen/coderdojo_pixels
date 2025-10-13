// Hier gebruiken we code die we gebruiken om de pixels aan te sturen
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
  // De eerste pixel duiden we aan met 0, de tweede met 1 en zo verder.
  pixels.setPixelColor(0, KLEUR_ROOD);
  // De tweede pixel groen laten oplichten
  pixels.setPixelColor(1, KLEUR_GROEN);
  // De derde pixel blauw laten oplichten
  pixels.setPixelColor(2, KLEUR_BLAUW);
  // Toon de pixels
  pixels.show();

  // Wacht 1 seconde (= 1000 milliseconden)
  delay(1000);
  // Alle pixels uit
  pixels.clear();
  // Toon nu de gedoofde pixels
  pixels.show();
  // Eén seconde wachte
  delay(1000);
  // Weer naar het begin van de lus
  
  /*
  Je zou nu nog meer pixels één voor één kunnen toevoegen
  Maar dat is lastig om dat telkens allemaal in te geven.
  Ga naar de volgende sketch om te zien hoe dit beter kan.
  */
}
