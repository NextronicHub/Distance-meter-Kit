#include <LiquidCrystal.h>

#define trigPin 10
#define echoPin 11
#define BUZZER 8


long tempEcho;
int  distance ;
const int RS =2, E =3, D4 =4, D5 =5, D6 =6, D7 = 7;   //RS = 12, E = 6, D4 = 5, D5 = 4, D6 = 3, D7 = 2;
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

void setup() {
Serial.begin(9600) ;
pinMode(BUZZER, OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);


lcd.begin(16, 2);       // initial nombres columns and rows   
lcd.print("distance: ") ;

}

void loop() {
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW) ;


tempEcho = pulseIn(echoPin,HIGH);       // temps d'impulsion
distance = tempEcho*0.034/2 ;          //  Etalonnage
Serial.println(distance);

lcd.home();
lcd.print("distance en cm : ") ;
lcd.setCursor(0,1);
lcd.print(distance);
delay(100);
lcd.clear();





}
