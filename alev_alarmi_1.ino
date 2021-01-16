int alov=A5;
int gelen;
int buzzer=4;
void setup() {
pinMode(alov,INPUT);
Serial.begin(9600);

}

void loop() {
 gelen=analogRead(alov);
if(gelen<=200){
  digitalWrite(buzzer,HIGH);
}
}
