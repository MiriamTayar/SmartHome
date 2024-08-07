
#include <DHT.h>
#define DHTPIN 14         
#define DHTTYPE DHT11      
DHT dht(DHTPIN, DHTTYPE);  

//עבור המאוורר
#define INB_FAN 26
#define INA_FAN 27

void setup_temperature() {
  dht.begin();
  Serial.begin(9600);
  //עבור המאוורר
  pinMode(INA_FAN, OUTPUT);
  pinMode(INB_FAN, OUTPUT);
}


//פונקציה שמדליקה או מכבה מאוורר, אם היא מקבלת אחד היא מדליקה אחרת, מכבה
void on_off_fan(int mode) {
  if (mode == 1) {
    Serial.println("fan on (forward)");
    digitalWrite(INA_FAN, HIGH);
    digitalWrite(INB_FAN, LOW);  // המנוע יסתובב בכיוון הקדמי

  } else {
    // Serial.println("fan off");
    digitalWrite(INA_FAN, LOW);
    digitalWrite(INB_FAN, LOW);  // המנוע יפסיק לסובב
  }
}


//פונקציה שדוגמת את הטמפרטורה, אם חם מחזירה אמת אם לא מחזירה שקר
void is_hot() {
   Serial.println("Temperature: ");
Serial.println(dht.readTemperature());
  if (dht.readTemperature() > 28) {
    on_off_fan(1);
  } else {
    on_off_fan(0);
  }
}


