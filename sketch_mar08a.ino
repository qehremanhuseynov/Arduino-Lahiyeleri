int civa = 3;
int k=13;
int y=12;
int m=10;
int buzer=11;
int deger;
void setup()
{
Serial.begin(9600);
pinMode(civa, INPUT);
pinMode(k,OUTPUT);
pinMode(y,OUTPUT);
pinMode(m,OUTPUT);
pinMode(buzer,OUTPUT);
}
void loop()
{
deger = digitalRead(civa);
if(deger==HIGH){
  Serial.println("var");

  digitalWrite(buzer,LOW); 
}
else{
   Serial.println("yok");
  digitalWrite(buzer,HIGH);
  digitalWrite(k,HIGH);
  delay(1000);
  digitalWrite(m,HIGH);
  delay(1000);
  digitalWrite(y,HIGH);
  delay(1000);
   digitalWrite(k,LOW);
  delay(1000);
  digitalWrite(m,LOW);
  delay(1000);
  digitalWrite(y,LOW);
  delay(1000);
}















}
