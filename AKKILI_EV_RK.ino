
#include "DHT.h"

#define DHTPIN 2
#include <math.h>

#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

#include <Wire.h>

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(7, 8); // TX | RX


#include <IRremote.h>

IRrecv irrecv(9);

decode_results results;


#include <Servo.h>
#define BUTON1 0xE0E020DF
#define BUTON2 0xE0E0A05F
#define BUTON3 0xE0E0609F
#define BUTON4 0xE0E010EF
#define BUTON5 0xE0E0906F
#define BUTON6 0xE0E050AF
#define BUTON7 0xE0E030CF
#define BUTON8 0xE0E0B04F
#define mute  0xE0E0F00F
#define ACIL 0xE0E036C9



double Thermistor(int RawADC) {
  double Temp;
  Temp = log(10000.0*((1024.0/RawADC-1))); 
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
  Temp = Temp - 273.15;            // Convert Kelvin to Celcius
  Temp = Temp/2;
   return Temp;
}
int deger;
#define echoPin 12

#define trigPin 11
#define buzzer 13
int sensorPin = A5;
int ses = A5;
int qaz = A4;
int alov = A0;
int led1 = A3;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6;
int led7;
int led8;
int motor = A1;
int cevap;
int gelen;
int civa = A2;
int qazd;
int vib = 7;
int ldr = A2;
int buttonpin = 7;
int but;
Servo k1;
Servo k2;
void setup() {
  Serial.begin(9600);
  pinMode (buttonpin, INPUT) ;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(civa, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(alov, INPUT);
  pinMode(motor, OUTPUT);
  pinMode(vib, INPUT);
  pinMode(ldr, INPUT);
  pinMode(ses, INPUT);
  dht.begin();
  irrecv.enableIRIn();
  Serial.println(F("Sistem Baslatildi"));

  k1.attach(10);
  k2.attach(8);


}


void loop() {


  if (Serial.available() > 0) {
    cevap = Serial.read();
  }
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin , HIGH);
  distance = duration / 58.2;
  delay(50);
  int ldri;
  ldri = analogRead(ldr);

  delay(200);
 int readVal=analogRead(sensorPin);
 double temp =  Thermistor(readVal);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t))
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);


if(cevap == 'g')

{
  Serial.println(temp);
   delay(500);

}
  if (cevap == 't')
  {
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.println(t);
  }


  if (cevap == '1') {
    digitalWrite(led1, HIGH);


  }

  else if (cevap == '2') {
    digitalWrite(led2, HIGH);

  }
  else if (cevap == '3') {
    digitalWrite(led3, HIGH);
  }
  else if (cevap == '4') {
    digitalWrite(led4, HIGH);

  }

  else if (cevap == '5') {
    digitalWrite(led5, HIGH);
  }

  else if (cevap == '6') {
    digitalWrite(led1, LOW);
  }
  else if (cevap == '7') {
    digitalWrite(led2, LOW);
  }
  else if (cevap == '8') {
    digitalWrite(led3, LOW);
  }
    else if (cevap == '9') {
    digitalWrite(led4, LOW);
  }
    else if (cevap == '0') {
    digitalWrite(led5, LOW);
  }
  else if (cevap == 'a') {
    Serial.println("Tum isiklar kapatildi");
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
  }

  but = digitalRead (buttonpin) ;
  if (but == HIGH)
  {
    k1.write(0);
    delay(200);
    k1.write(90);
  }
  int sesge;
  sesge = analogRead(ses);
  if (sesge >= 1000)
  {
    Serial.println("Hirsiz Ola Bilir Ses duyduk");
    for (int i = 0; i <= 100; i++)
    {
      digitalWrite(buzzer, HIGH);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      delay(100);
      digitalWrite(led1 , LOW);
      digitalWrite(led2 , LOW);
      digitalWrite(led3 , LOW);
      digitalWrite(led4 , LOW);
      digitalWrite(led5 , LOW);
    }
  }


  if (distance <= 7) {
    digitalWrite(buzzer, HIGH);
    Serial.println("Hirsiz Ola bilir sensorun onunden bir seyler gecti");
    for (int i = 0; i <= 100; i++)
    {
      digitalWrite(buzzer, HIGH);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      delay(100);
      digitalWrite(led1 , LOW);
      digitalWrite(led2 , LOW);
      digitalWrite(led3 , LOW);
      digitalWrite(led4 , LOW);
      digitalWrite(led5 , LOW);
    }
  }



  else if (cevap == 'j') {
    k1.write(90);
    delay(50);
  }

  else if (cevap == 'l') {
    k1.write(0);
    delay(50);

  }
  else if (cevap == 'h') {
    analogWrite(motor, 1024);
  }
  else if (cevap == 'b') {
    analogWrite(motor, 0);
  }


  else if (cevap == 'm') {
    digitalWrite(buzzer, LOW);
  }
else if (cevap == 'z')
{
k2.write(120);
}
else if (cevap == 'x')
{
k2.write(0);
}

  qazd = analogRead(qaz);
  
  if (qazd >= 260) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(motor, HIGH);
    Serial.println(" qaz sizintisi var ");
  }
gelen = analogRead(alov);

  if (gelen < 200) {
    digitalWrite(buzzer, HIGH);
    k1.write(0);
    Serial.print("Yangin Var  ACIL EVI BOSALTIN");
    for (int i = 0; i <= 100; i++)
    {
      digitalWrite(buzzer, HIGH);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      delay(100);
      digitalWrite(led1 , LOW);
      digitalWrite(led2 , LOW);
      digitalWrite(led3 , LOW);
      digitalWrite(led4 , LOW);
      digitalWrite(led5 , LOW);
    }
  }
  

  if (irrecv.decode(&results))
  {
    if (results.value == BUTON1)
    {
      digitalWrite(led1, !digitalRead(led1));

    }
    if (results.value == BUTON2)
    {
      digitalWrite(led2, !digitalRead(led2));
    }

    if (results.value == BUTON3)
    {
      digitalWrite(led3, !digitalRead(led3));

    }
    if (results.value == BUTON4)
    {
      digitalWrite(led4, !digitalRead(led4));
    }
    if (results.value == BUTON5)
    {
      digitalWrite(led5, !digitalRead(led5));
    }
    if (results.value == BUTON6)
    {
      digitalWrite(led6, !digitalRead(led6));
    }
    if (results.value == BUTON7)
    {
      digitalWrite(led7, !digitalRead(led7));
    }
    if (results.value == BUTON8)
    {
      digitalWrite(led8, !digitalRead(led8));
    }
    if (results.value == mute)
    {
      digitalWrite(buzzer, LOW);
    }


    irrecv.resume();
  }


}
