#define trigPin 11
#define echoPin 10
#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define BUZZER 8

long tempEcho;
int  distance ;

void setup() {
  
Serial.begin(9600) ;
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(LED3,OUTPUT);
pinMode(LED4,OUTPUT);
pinMode(BUZZER,OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

digitalWrite(LED1,LOW); digitalWrite(LED2,LOW);  //initialisation des LEDs
digitalWrite(LED3,LOW); digitalWrite(LED4,LOW);


}

void loop() {
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW) ;

tempEcho = pulseIn(echoPin,HIGH);   // temps d'impulsion
distance = tempEcho*0.034/2 ;
Serial.println(distance);

  if ( distance <22) {  digitalWrite(LED1,HIGH);digitalWrite(BUZZER,HIGH);} 
            else     {  digitalWrite(LED1,LOW);digitalWrite(BUZZER,LOW); }
  if ( distance <27)    digitalWrite(LED2,HIGH); 
            else        digitalWrite(LED2,LOW);
  if ( distance <32)    digitalWrite(LED3,HIGH);
            else        digitalWrite(LED3,LOW);
  if ( distance <37 )   digitalWrite(LED4,HIGH); 
            else        digitalWrite(LED4,LOW);
       
delay(100);





}
