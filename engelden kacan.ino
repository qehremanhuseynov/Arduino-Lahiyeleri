const int trig = 8;
const int echo = 12;

// l283B kullanildi
const int sag_i=2; 
const int sag_g=3;
const int sol_i=4; 
const int sol_g=5;

 int mesafe=0;
 int sure=0;


void setup() {
pinMode(trig , OUTPUT);
pinMode(echo , INPUT);

pinMode(sag_i , OUTPUT);
pinMode(sag_g , OUTPUT);
pinMode(sol_i , OUTPUT);
pinMode(sol_g , OUTPUT);

}

void loop() {
 digitalWrite(trig , HIGH);
 delayMicroseconds (100);
 digitalWrite( trig , LOW);

 sure=pulseIn(echo , HIGH);
 mesafe = (sure/2)  / 28.5;

 if (mesafe < 30)
 {
digitalWrite(sag_i , LOW);
digitalWrite(sag_g , HIGH);
digitalWrite(sol_i , HIGH);
digitalWrite(sol_g , LOW);
 }
 

else
{
digitalWrite( sag_i , LOW);
digitalWrite( sag_g , LOW);
digitalWrite( sol_i , HIGH);
digitalWrite( sol_g , LOW);
 
}

 }
