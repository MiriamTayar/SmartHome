
// //TX - RX
// //RX - TX
// #include <SoftwareSerial.h>
// #include <Adafruit_Fingerprint.h> //ספריית Adafruit_Fingerprint.h.

// SoftwareSerial mySerial(17,16);


// Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
// uint8_t id;//משמש לאחסון מזהה טביעת האצבע

// void setup_enroll()
// {
//   Serial.begin(57600);//קביעת קצב בעברת נתונים
//   while (!Serial);  // For Yun/Leo/Micro/Zero/...
//   delay(100);
//   Serial.println("\n\nAdafruit Fingerprint sensor enrollment");

//   // set the data rate for the sensor serial port
//   finger.begin(57600);//קובעת את קצב העברת הנתונים לחיישן ל-57600 סיביות לשנייה

//   // if (finger.verifyPassword()) {//בודק אם סיסמה מוגדרת בחיישן.
//   //   Serial.println("Found fingerprint sensor!");
//   // } else {
//   //   Serial.println("Did not find fingerprint sensor :(");
  
//   //   while (1) { delay(1); }//אם לא מצא את החיישן נכנס ללולאה אין סופית
//   // }

//   Serial.println(F("Reading sensor parameters"));//מדפיס הודעה על קריאת פרמטרים מהחיישן.
//   finger.getParameters();// קורא את הפרמטרים הנוכחיים מהחיישן.
//   //הדפסת פרמטרים שונים
//   Serial.print(F("Status: 0x")); Serial.println(finger.status_reg, HEX);
//   Serial.print(F("Sys ID: 0x")); Serial.println(finger.system_id, HEX);
//   Serial.print(F("Capacity: ")); Serial.println(finger.capacity);
//   Serial.print(F("Security level: ")); Serial.println(finger.security_level);
//   Serial.print(F("Device address: ")); Serial.println(finger.device_addr, HEX);
//   Serial.print(F("Packet len: ")); Serial.println(finger.packet_len);
//   Serial.print(F("Baud rate: ")); Serial.println(finger.baud_rate);
// }




// uint8_t readnumber(void) {
//   uint8_t num = 0;

//   while (num == 0) {
//     while (! Serial.available());
//     num = Serial.parseInt();
//   }
//   return num;
// }


// //פונקציית הלולאה מבקשת מהמשתמש להזין מספר מזהה, בודקת תקינות, ומפעילה את פונקציית הרישום כל עוד היא לא מצליחה.
// //התוכנית ממשיכה לבקש טביעות אצבע עד שהמשתמש ינתק את הלוח מהחשמל.

// void loop_enroll()                     // run over and over again
// {
//   Serial.println("Ready to enroll a fingerprint!"); //התוכנית מוכנה לרישום טביעת אצבע
//   Serial.println("Please type in the ID # (from 1 to 127) you want to save this finger as...");//מדפיס בקשה למשתמש להזין מספר מזהה לטביעת האצבע (בין 1 ל-127)
//   id = readnumber();
//   if (id == 0) {// ID #0 not allowed, try again!
//      return;
//   }
//   Serial.print("Enrolling ID #");
//   Serial.println(id);

//   while (! getFingerprintEnroll() );
// }





// uint8_t getFingerprintEnroll() {

//   int p = -1;
//   Serial.print("Waiting for valid finger to enroll as #"); Serial.println(id);
//   while (p != FINGERPRINT_OK) {  //לולאה שתמשיך כל עוד התמונה לא נקלטה בהצלחה
//     p = finger.getImage();
//     switch (p) {
//     case FINGERPRINT_OK:
//       Serial.println("Image taken");
//       break;
//     case FINGERPRINT_NOFINGER:
//       Serial.print(".");
//       break;
//     case FINGERPRINT_PACKETRECIEVEERR:
//       Serial.println("Communication error");
//       break;
//     case FINGERPRINT_IMAGEFAIL:
//       Serial.println("Imaging error");
//       break;
//     default:
//       Serial.println("Unknown error");
//       break;
//     }
//   }

//   // OK success!

//   p = finger.image2Tz(1);
//   switch (p) {
//     case FINGERPRINT_OK:
//       Serial.println("Image converted");
//       break;
//     case FINGERPRINT_IMAGEMESS:
//       Serial.println("Image too messy");
//       return p;
//     case FINGERPRINT_PACKETRECIEVEERR:
//       Serial.println("Communication error");
//       return p;
//     case FINGERPRINT_FEATUREFAIL:
//       Serial.println("Could not find fingerprint features");
//       return p;
//     case FINGERPRINT_INVALIDIMAGE:
//       Serial.println("Could not find fingerprint features");
//       return p;
//     default:
//       Serial.println("Unknown error");
//       return p;
//   }

//   Serial.println("Remove finger");
//   delay(2000);
//   p = 0;
//   while (p != FINGERPRINT_NOFINGER) {
//     p = finger.getImage();  //ממיר את התמונה לתבנית
//   }
//   Serial.print("ID "); Serial.println(id);
//   p = -1;
//   Serial.println("Place same finger again");
//   while (p != FINGERPRINT_OK) {
//     p = finger.getImage();
//     switch (p) {
//     case FINGERPRINT_OK:
//       Serial.println("Image taken");
//       break;
//     case FINGERPRINT_NOFINGER:
//       Serial.print(".");
//       break;
//     case FINGERPRINT_PACKETRECIEVEERR:
//       Serial.println("Communication error");
//       break;
//     case FINGERPRINT_IMAGEFAIL:
//       Serial.println("Imaging error");
//       break;
//     default:
//       Serial.println("Unknown error");
//       break;
//     }
//   }

//   // OK success!

//   p = finger.image2Tz(2);
//   switch (p) {
//     case FINGERPRINT_OK:
//       Serial.println("Image converted");
//       break;
//     case FINGERPRINT_IMAGEMESS:
//       Serial.println("Image too messy");
//       return p;
//     case FINGERPRINT_PACKETRECIEVEERR:
//       Serial.println("Communication error");
//       return p;
//     case FINGERPRINT_FEATUREFAIL:
//       Serial.println("Could not find fingerprint features");
//       return p;
//     case FINGERPRINT_INVALIDIMAGE:
//       Serial.println("Could not find fingerprint features");
//       return p;
//     default:
//       Serial.println("Unknown error");
//       return p;
//   }

//   // OK converted!
//   Serial.print("Creating model for #");  Serial.println(id);

//   p = finger.createModel();
//   if (p == FINGERPRINT_OK) {
//     Serial.println("Prints matched!");
//   } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
//     Serial.println("Communication error");
//     return p;
//   } else if (p == FINGERPRINT_ENROLLMISMATCH) {
//     Serial.println("Fingerprints did not match");
//     return p;
//   } else {
//     Serial.println("Unknown error");
//     return p;
//   }

//   Serial.print("ID "); Serial.println(id);
//   p = finger.storeModel(id);
//   if (p == FINGERPRINT_OK) {
//     Serial.println("Stored!");
//   } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
//     Serial.println("Communication error");
//     return p;
//   } else if (p == FINGERPRINT_BADLOCATION) {
//     Serial.println("Could not store in that location");
//     return p;
//   } else if (p == FINGERPRINT_FLASHERR) {
//     Serial.println("Error writing to flash");
//     return p;
//   } else {
//     Serial.println("Unknown error");
//     return p;
//   }

//   return true;
// }
