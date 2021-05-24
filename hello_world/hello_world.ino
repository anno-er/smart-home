#define ledpin 13
int val;

void setup() {
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
}

void loop() {
  val = Serial.read();
  if(val == 'R'){
      digitalWrite(ledpin,HIGH);
      delay(500);
      digitalWrite(ledpin,LOW);
      Serial.println("hello world");
    }
}
