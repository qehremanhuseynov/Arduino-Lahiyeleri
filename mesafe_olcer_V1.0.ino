#define echoPin 12
#define trigPin 11
int buzzer=2;
void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600);
}


void loop() {
long duration, distance;

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin , HIGH);
  distance = duration / 29.2;
  delay(50);
  Serial.print( distance);
if(distance<10){
  digitalWrite(buzzer,HIGH);
}

}
