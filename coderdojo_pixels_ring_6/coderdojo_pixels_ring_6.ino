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
  kleurAllePixels(KLEUR_ROOD);
  delay(500);
  kleurAllePixels(KLEUR_GEEL);
  delay(1000);
  kleurAllePixels(KLEUR_GROEN);
  delay(1500);
  kleurAllePixels(KLEUR_INDIGO);
  delay(2000);
  kleurAllePixels(KLEUR_BLAUW);
  delay(2500);
  kleurAllePixels(KLEUR_MAGENTA);
  delay(3000);
  kleurAllePixels(KLEUR_WIT);
  delay(3500);

  /*
  Mooi met al die kleuren.
  Zoals was beloofd, hier wat meer uitleg over de kleuren.

  Verschillende kleuren van licht mengen.
  De pixels werken met 3 lichtkleuren, rood, groen, en blauw om vele andere kleuren te maken.
  Dit gebeurt ook met het beeldscherm van jouw computer.
  Dat heet additieve kleurmenging en dat betekent: Je voegt kleuren van licht samen (je “telt” ze op).

  De drie lichtkleuren
  De pixels gebruiken drie basis-lichtkleuren: rood, groen en blauw.
  Elke pixel bevat een kleine rode, groene en blauwe LED. Door die drie LEDs
  met verschillende sterktes te laten branden, kun je bijna alle kleuren van de
  regenboog maken.

  Enkele voorbeelden:

  Rood   | Groen  | Blauw  | Resultaat
  ------ | ------ | ------ | --------------------
  🔴 aan | ⚫ uit | ⚫ uit | Rood 
  ⚫ uit | 🟢 aan | ⚫ uit | Groen
  ⚫ uit | ⚫ uit | 🔵 aan | Blauw
  🔴 aan | 🟢 aan | ⚫ uit | Geel
  🔴 aan | ⚫ uit | 🔵 aan | Magenta (rozeachtig)
  ⚫ uit | 🟢 aan | 🔵 aan | Cyaan (blauwgroen)
  🔴 aan | 🟢 aan | 🔵 aan | Wit (alle kleuren samen)

  Samengevat:
  - Additieve kleurmenging betekent dat je lichtkleuren optelt.
  - Hoe meer licht je toevoegt, hoe lichter de kleur.
  - Met rood, groen en blauw kun je bijna alle kleuren maken.

  Er zijn twee manieren om een kleur in code te zetten:
  - Met een vooraf ingestelde kleur, bijvoorbeeld: pixels.setPixelColor(i, KLEUR_ROOD);
    Hier gebruik je een naam die je eerder hebt vastgelegd. Dit is wat we tot nu toe gedaan hebben.
    #define KLEUR_ROOD 0xFF0000, #define KLEUR_GEEL 0xFFFF00, enz legt de kleuren vast met hexadecimale getallen.
    Hexadecimaal betekent letterlijk: tellen met 16 cijfers in plaats van 10.
    We tellen normaal met 10 cijfers: 0 1 2 3 4 5 6 7 8 9
    Maar als we nog verder willen tellen, komen er in hexadecimaal nieuwe symbolen bij: A, B, C, D, E, F.

    Decimaal	Hexadecimaal
    10        A
    11        B
    12        C
    13        D
    14        E
    15        F
    
    Een kleur in hexadecimaal
    Een kleur bestaat uit drie delen: Rood, Groen en Blauw (RGB).
    Elke kleur krijgt twee hexadecimale cijfers (0 tot FF).
    Dat betekent:
    Kleur | Waarde                      | Betekenis
    ------+-----------------------------+----------
    FF    | maximaal (255 in decimaal)  | maximaal
    00    | minimaal (0 in decimaal)    | alles uit

    #FF0000 betekent dan “veel rood, geen groen, geen blauw” → rood licht.
    #FFFF00 betekent dan “veel rood, veel groen, geen blauw” → geel licht.
    
  - Soms is het handiger om met afzonderlijke rood, groen en blauw te werken,
    bijvoorbeeld: pixels.setPixelColor(i, pixels.Color(255, 100, 0));
    In dit voorbeeld brandt het rode lampje maximaal. (255 = maximaal),
    het groene lampje een beetje (100), en het blauwe lampje helemaal niet (0).
    Samen geeft dat een oranje kleur. Je kan de getallen ook hexadecimaal schrijven.
    Dan krijg je bijvoorbeeld pixels.setPixelColor(i, pixels.Color(0xFF, 0x64, 0));
    https://www.rapidtables.org/nl/convert/number/decimal-to-hex.html kan je helpen
    om te vertalen van decimaal naar hexadecimaal of omgekeerd.

  En nu jouw opdracht:
  - Vervang alle kleuren eens door pixels.Color(...) het resultaat zou net hetzelfde moeten zijn.
  */
}
