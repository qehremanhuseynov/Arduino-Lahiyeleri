int led = 3;
int sespin = 2;
int led1 = 4;
int led2 = 5;
int led3 = 6;
int alkis=0;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(sespin, INPUT);
  

}

void loop() {
  int sesdegeri =digitalRead(sespin);

  if (sesdegeri == HIGH)
  {
    digitalWrite(led, HIGH);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(10000);
    
  }
  else {
    digitalWrite(led, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  
}
