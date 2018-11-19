#include <LiquidCrystal.h>

LiquidCrystal lcd (7,6,5,4,3,2);
//                RS,EN,D4,D5,D6,D7

//pines de conexion
int pinEcho = 22;
int pinTiger= 23;

//variables para el calculo
int tiempo=0;
int distancia=0;

int boton1 = 24; //Fuente y receptor movil
int boton2 = 25;//Fuente en movimiento, receptor en reposo
int boton3 = 26;//Fuente en reposo, receptor en movimiento

int v=344; //velocidad del sonido: 344 m/s
int ff=40000; //freceuncia del foco: 40000Hz
int fra=40016.3372; //frecuencia del receptor cuando se acerca: 40016.3372Hz
int frl=39983.6627; //frecuencia del receptor cuanod se aleja: 39983.6627Hz
int vR=0.1405; //velocidad del receptor: 0.1405 m/s
int vF=0.1404; //velocidad del emisor: 0.1404 m/s
int veR=0;
int veF=0;
int frRc=0;
int frRa=0;

void setup() { 
 pinMode(pinEcho, INPUT);
 pinMode(pinTiger, OUTPUT);

 pinMode (boton1, INPUT);
  pinMode (boton2, INPUT);
  pinMode (boton3, INPUT);

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
  /*
   v=344; //velocidad del sonido: 344 m/s
   ff=40000; //freceuncia del foco: 40000Hz
   fra=40016.3372; //frecuencia del receptor cuando se acerca: 40016.3372Hz
   frl=39983.6627; //frecuencia del receptor cuanod se aleja: 39983.6627Hz
   vR=0.1405; //velocidad del receptor: 0.1405 m/s
   vF=0.1404; //velocidad del emisor: 0.1404 m/s
*/
   lcd.setCursor(0,1);
   lcd.print("Distancia= ");
   lcd.print(distancia);
   lcd.print(" [cm]");

   Caso1();
   Caso2();
   Caso3();
   //delay(1000);
}

void Caso1()
  {
    int estadoBoton1 = digitalRead (boton1);
    if (estadoBoton1 ==1)
    {
      veF=((ff*(v+vR))-fra*v)/fra;
      veR=((fra*(v+veF))/ff)-v;
      frRc=((v+veR)/(v-veF))*ff;
      frRa=((v-veR)/(v+veF))*ff;
      
      lcd.home();
      lcd.print("Velocidad del emisor: ");
      lcd.print(veF);
      lcd.print(" [m/s]");
      lcd.setCursor(0,1);
      lcd.print("Velocidad del receptor: ");
      lcd.print(veR);
      lcd.print(" [m/s]");
      delay(3000);
      lcd.clear();
      
      lcd.home();
      lcd.print("Frecuencia de acercamiento: ");
      lcd.print(frRc);
      lcd.print(" [Hz]");
      lcd.setCursor(0,1);
      lcd.print("Frecuencia de alejamiento: ");
      lcd.print(frRa);
      lcd.print(" [Hz]");
      delay(3000);
      //lcd.setCursor(5,1);
      //delay(3000);
      //lcd.clear();
      //lcd.print("Distancia: ");
      //lcd.print(distancia);
    }
  }

  void Caso2()
  {
    int estadoBoton2 = digitalRead (boton2);
    if (estadoBoton2 ==1)
    {
      veF=v-((v*ff)/fra);
      //veR=((fra*(v+veF))/ff)-v;
      frRc=(v/(v-veF))*ff;
      frRa=(v/(v+veF))*ff;
      
      lcd.home();
      lcd.print("Velocidad del emisor: ");
      lcd.print(veF);
      lcd.print(" [m/s]");
      delay(3000);
      lcd.clear();
      
      lcd.home();
      lcd.print("Frecuencia de acercamiento: ");
      lcd.print(frRc);
      lcd.print(" [Hz]");
      lcd.setCursor(0,1);
      lcd.print("Frecuencia de alejamiento: ");
      lcd.print(frRa);
      lcd.print(" [Hz]");
      delay(3000);
      //lcd.setCursor(0,1);
      /*lcd.print("Velocidad del receptor: ");
      lcd.print(veR);
      lcd.setCursor(5,1);
      delay(3000);
      lcd.clear();
      lcd.print("Distancia: ");
      lcd.print(distancia);*/
    }
  }

  void Caso3()
  {
    int estadoBoton3 = digitalRead (boton3);
    if (estadoBoton3 ==1)
    {
      //veF=((ff*(v+vR))-fra*v)/fra;
      veR=v*((fra/ff)-1);
      frRc=((v+veR)/v)*ff;
      frRa=((v-veR)/v)*ff;
     
      
      lcd.home();
      lcd.print("Velocidad del receptor: ");
      lcd.print(veR);
      lcd.print(" [m/s]");
      delay(3000);
      lcd.clear();
      
      lcd.home();
      lcd.print("Frecuencia de acercamiento: ");
      lcd.print(frRc);
      lcd.print(" [Hz]");
      lcd.setCursor(0,1);
      lcd.print("Frecuencia de alejamiento: ");
      lcd.print(frRa);
      lcd.print(" [Hz]");
      delay(3000);
      /*lcd.print("Velocidad del receptor: ");
      lcd.print(veR);
      lcd.setCursor(5,1);
      delay(3000);
      lcd.clear();
      lcd.print("Distancia: ");
      lcd.print(distancia);*/
    }
  }
