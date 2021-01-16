int led1=2;
int led2=3;
int led3=4;
int led4=5;


void setup() {
 Serial.begin(9600);

pinMode(led1 , OUTPUT);
pinMode(led2 , OUTPUT);
pinMode(led3 , OUTPUT);
pinMode(led4 , OUTPUT);

}

void loop() {
  int isik = analogRead(A0); 
  if (isik>150){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3 , LOW);
  digitalWrite(led4 , LOW);
  }

 if(isik>300){
 digitalWrite(led1 ,HIGH);
 digitalWrite(led2 , HIGH);
 digitalWrite(led3 , LOW);
 digitalWrite(led4 ,LOW);
 
}
if(isik>600){
  digitalWrite(led1 ,HIGH);
 digitalWrite(led2 , HIGH);
 digitalWrite(led3 , HIGH);
 digitalWrite(led4 ,LOW);
}

if(isik>900){
  digitalWrite(led1 ,HIGH);
 digitalWrite(led2 , HIGH);
 digitalWrite(led3 , HIGH);
 digitalWrite(led4 ,HIGH);
}












}
