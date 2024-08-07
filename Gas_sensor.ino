// חיישן גז+ באזר- צפצפה

#define smokeDetector 35
float value;
int buzzer = 23;

void setup_gas() {
  Serial.begin(9600);  //Initialize serial port - 9600 bps
  pinMode(buzzer, OUTPUT);
}

// הפונקציה קוראת את החיישן מספר פעמים ומחשבת את הממוצע של הערכים. כך, מתקבלות תוצאות יציבות יותר
float getAverageReading(int numReadings)
{
  float total = 0;
  for (int i = 0; i < numReadings; i++)
  {
    total += analogRead(smokeDetector);
    delay(50); // Short delay between readings
  }
  return total / numReadings;
}

void gas_test() {
   value = getAverageReading(10); // Get the average of 10 readings
  Serial.print(value);
  
  if (value > 140)
  {
    Serial.println(" Smoke Detected ");
    digitalWrite(buzzer, HIGH);
  } else {
    Serial.println("Smoke not Detected  ");
    digitalWrite(buzzer, LOW);
  }

}
