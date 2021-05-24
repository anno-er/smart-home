/*D7=13 D0=16 D8=15 D5=14 D6=12 D2=4 D9=3 D4=2 D10=1 D3=0*/

void setup() {
  pinMode(13,OUTPUT);
}

void loop() {
  digitalWrite(13,LOW);
  delay(200);
  digitalWrite(13,HIGH);
  delay(200);
}
