#include <LedControl.h>
int DIN = 11;
int CS =  10;
int CLK = 9;
LedControl lc=LedControl(DIN,CLK,CS,0);
const int del = 900;  // הגדרת פורט ה-LED הפנימי
byte fullhear[] = {0x00,0x66,0xFF,0xFF,0xFF,0x7E,0x3C,0x18};
byte heart[] = {0x00,0x66,0x99,0x81,0x81,0x42,0x24,0x18};
byte Robot[] = {0x14,0x14,0x7E,0xDB,0xFF,0xFF,0xA5,0x24};
byte Robot2[] = {0x15,0x15,0x7F,0xDB,0xFE,0xFE,0xA4,0x24};
byte Robot3[] = {0x94,0x94,0xFF,0xDB,0x7F,0x7F,0x25,0x24};
byte smile[] = {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C};
byte smile2[] = {0x3C,0x42,0xA5,0x81,0x81,0xBD,0x42,0x3C};
byte smile3[] = {0x3C,0x42,0xA5,0x99,0xA5,0x99,0x42,0x3C};
byte smile4[] = {0x3C,0x42,0xA5,0x81,0xBD,0x99,0x42,0x3C};
byte UM[]    = {0x18,0x3C,0x7E,0xFF,0x18,0x58,0x78,0x00};
byte UM1[]    = {0x19,0xBC,0x7E,0xFF,0x18,0x5A,0x78,0x00};
byte UM2[]    = {0x58,0xBD,0x7E,0xFF,0x18,0x58,0x78,0x82};
byte Zero[]    = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
void setup() {
  Serial.begin(9600);

  pinMode (13,OUTPUT);
  pinMode (12,OUTPUT);
  digitalWrite (13,HIGH);
  digitalWrite (12,LOW);
   
 lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,15);      // Set the brightness to maximum value
 lc.clearDisplay(0);         // and clear the display
}

void loop() {
  static String receivedString = "";  // משתנה לאחסון המחרוזת הנקלטת

  while (Serial.available() > 0) {
    char currentChar = Serial.read();
    Serial.print(currentChar);

    // הוספת התו למחרוזת
    receivedString += currentChar;
  }

  // בדיקה ופעולות ב- switch case
  switch (receivedString.toInt()) {
    
   
    case 1:
             for (int j = 0; j < 2; j++){
                    // הצגת המספרים ברצף על התאורה
                 for (int i = 0; i < 8; i++) {
                     lc.setRow(0, i, heart[i]);
                      }
                   delay(200);  // המתנה 1 שנייה
                      for (int i = 0; i < 8; i++) {
                     lc.setRow(0, i,fullhear[i]);
                     delay(del-100);  // המתנה 1 שנייה
                    }
                    for (int K=0; K<2;K++){
                     for (int i = 0; i < 8; i++) {
                     lc.setRow(0, i,Zero[i]);
                    }
                    delay(500);
                    for (int i = 0; i < 8; i++) {
                     lc.setRow(0, i,fullhear[i]);
                    }
                     delay(500);
                    }
                    delay(200);  // המתנה 1 שנייה
                      for (int i = 0; i < 8; i++) {
                     lc.setRow(0, i,Zero[i]);
                      delay(del-100);  // המתנה 1 שנייה
                    } 
            }
      break;
    case 2:
               for (int j = 0;j< 2; j++){  
               for (int i = 0; i < 8; i++) {
               lc.setRow(0, i, Robot[i]);
                    }
                 delay (1000);

                for (int i = 0; i < 8; i++) {
               lc.setRow(0, i, Robot2[i]);
               }

                 delay(1000);

                 for (int i = 0; i < 8; i++) {
               lc.setRow(0, i, Robot3[i]);
               }
               delay(1000);
               }
                for (int i = 0; i < 8; i++) {
               lc.setRow(0, i, Robot[i]);
                    }
                delay(1000);
         break;
      case 3:
            for (int i = 0; i < 5; i++) {
              for (int i = 0; i < 8; i++) {
               lc.setRow(0, i, UM[i]);
            }
             delay(1000);
              for (int i = 0; i < 8; i++) {
               lc.setRow(0, i, UM1[i]);
            }
             delay(1000);
            
            for (int i = 0; i < 8; i++) {
               lc.setRow(0, i, UM2[i]);
            }
             delay(1000);
            }
      break;
      case 4:
           for (int i = 0; i < 5; i++) {
              for (int i = 0; i < 8; i++) {
               lc.setRow(0, i, smile[i]);
            }
            delay(1000);
            for (int i = 0; i < 8; i++) {
               lc.setRow(0, i, smile2[i]);
            }
            delay(1000);
            for (int i = 0; i < 8; i++) {
               lc.setRow(0, i, smile3[i]);
            }
            delay(1000);
            for (int i = 0; i < 8; i++) {
               lc.setRow(0, i, smile4[i]);
            }
            delay(1000);
           }
            break;
          case 5:  for (int i = 0; i < 8; i++) {
                      lc.setRow(0, i, Zero[i]);
                     }
                    break;
          case 6: lc.setIntensity(0,2);
                 break;
          case 7: lc.setIntensity(0,15);
                 break;
    default:
      // פעולות או קוד נוסף במקרה שלא מתקבלת ערך מתאים
      break;
  }

  // איפוס המחרוזת לקבלת מחרוזת חדשה
  receivedString = "";
}
