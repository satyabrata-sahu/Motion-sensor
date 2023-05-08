int gled = 2; //green led pin
int rled = 4; //red led pin
int pirpin = 3; //motion sensor pin 

int value = 0;
int pirState = LOW;

void setup() {
  pinMode(gled, OUTPUT); 
  pinMode(rled, OUTPUT); 
  pinMode(pirpin, INPUT);
  Serial.begin(9600);
}

void loop() {

  value = digitalRead(pirpin);

  if (value == HIGH) {
    digitalWrite(rled, HIGH);
    digitalWrite(gled, LOW);

    if (pirState == LOW) {
      Serial.println("PIR Motion Detected ");
      pirState = HIGH;
    }
  }
  
  else{
    digitalWrite(rled, LOW);
    digitalWrite(gled, HIGH);
    
    if(pirState == HIGH){
      Serial.println("PIR Motion Ended ");
      pirState = LOW;
      }
    }
    
}
