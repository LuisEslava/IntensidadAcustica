#include <LiquidCrystal.h>

LiquidCrystal lcd (7,6,5,4,3,2);
//                RS,EN,D4,D5,D6,D7

//pines de conexion
int pinEcho = 7;
int pinTiger= 6;

//variables para el calculo
int tiempo=0;
int distancia=0;

void setup() { 
 pinMode(pinEcho, INPUT);
 pinMode(pinTiger, OUTPUT);
 pinMode (pinLed, OUTPUT);

 lcd.begin(16,2);
 // begin(columnas,filas)
 lcd.home(); //lcd.setCursor(0,0);
 
}

void loop() {
   digitalWrite(pinTiger, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTiger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTiger,LOW);

  tiempo = pulseIn(pinEcho, HIGH);

   distancia = tiempo/59;

   //distancia = tiempo*(349)/2*100;

   delay(1000);


   lcd.home();
  lcd.print("Velocidad: ");
  lcd.print(veloz);
  lcd.setCursor(5,1);
  lcd.print("Distancia: ");
  lcd.print(distancia);
}
