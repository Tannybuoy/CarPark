// Pairing Example _device 2
const int buttonPin1 = D2;    // the number of the pushbutton pin
const int buttonPin2 = D3;    // the number of the pushbutton pin
const int ledPin = D7;      // the number of the LED pin


void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, LOW);
  
}

void loop() {

  int reading1 = digitalRead(buttonPin1);
  int reading2 = digitalRead(buttonPin2);
    
  
  if(reading1 == LOW){
      digitalWrite(ledPin,HIGH);
      Particle.publish("touch001","leave",60,PUBLIC);
      delay(2000);
      digitalWrite(ledPin,LOW);
  }
  
  if(reading2 == LOW){
      digitalWrite(ledPin,HIGH);
      Particle.publish("touch002","enter",60,PUBLIC);
      delay(2000);
      digitalWrite(ledPin,LOW);
  }
  
}
