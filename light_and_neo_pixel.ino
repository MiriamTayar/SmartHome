
// חיישן תאורה+ נאו פיקסל

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

// light
#define LDR 34

#define pinNeoPix1 2
#define numPixels1 12
Adafruit_NeoPixel pixels1(numPixels1, pinNeoPix1, NEO_GRB + NEO_KHZ800);

#define pinNeoPix2 4
#define numPixels2 24
Adafruit_NeoPixel pixels2(numPixels2, pinNeoPix2, NEO_GRB + NEO_KHZ800);


void setup_light_sensor() {
  Serial.begin(9600);

  pixels1.begin();
  pixels2.begin();

  pinMode(LDR, INPUT);

}
//פונקציה להדלקת לדים על ידי חיישן תאורה
void light_sensor() {
  int LDR_sensor = analogRead(LDR);
  Serial.print("light:  ");
  Serial.println(LDR_sensor);
  if (LDR_sensor < 2000) {  // If light level is below 500, turn on the NeoPixels
    for (int i = 0; i < numPixels1; i++) {
      pixels1.setPixelColor(i, pixels1.Color(255, 000, 000));
    }
    for (int i = 0; i < numPixels2; i++) {
      pixels2.setPixelColor(i, pixels2.Color(255, 255, 255));
    }
    pixels1.show();
    pixels2.show();

  } else {
    pixels1.clear();
    pixels1.show();
    pixels2.clear();
    pixels2.show();
  }
}

