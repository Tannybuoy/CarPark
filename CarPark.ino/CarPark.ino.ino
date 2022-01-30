// ------------
// Night Light
// ------------
int top=D6;
int bottom=D2;
int middle=D4;
int top_right=D8;
int top_left=D5;
int bottom_right=D1;
int bottom_left=D0;
int dot=D3;

int count = 0;

int ledPin = D7;  // pin for our LED signal
int photoresistor = A5;  // pin for our photoresistor analog input
int analogValue = 0; // a variable so we can store readings from our sensor


int lightThreshold = 105; // a threshold value so we know when the lights are on or off.

void setup() {
    pinMode(bottom_left, OUTPUT);
    pinMode(bottom, OUTPUT);
    pinMode(bottom_right, OUTPUT);
    pinMode(dot, OUTPUT);
    pinMode(middle, OUTPUT);
    pinMode(top_left, OUTPUT);
    pinMode(top, OUTPUT);
    pinMode(top_right, OUTPUT);
    zero();
    Particle.subscribe("touch001", myHandler);
    Particle.subscribe("touch002", myHandler2);
  pinMode(ledPin, OUTPUT);  // our LED is our output, therefore we need to configure the pin to output voltage.
  pinMode(photoresistor, INPUT);  // our sensor is an input, therefore we need to configure the pin to read voltage coming in.
    

}

void loop() {
    
// analogValue = analogRead(photoresistor); // take a reading of our sensor

//     if (analogValue < lightThreshold){  // compare that reading against our threshold
//         digitalWrite(ledPin, HIGH);  // if we have more light than our threshold, we dont need our night light
//     }
//     else  {
//         //digitalWrite(ledPin, HIGH);  // if we have less light than our threshold, we need our night light!
//         //clear();
//         digitalWrite(ledPin, LOW); 
//         clear();
//         four();
//     }
}

void myHandler(const char *event, const char *data)
{
  /* Particle.subscribe handlers are void functions, which means they don't return anything.
  They take two variables-- the name of your event, and any data that goes along with your event.
  In this case, the event will be "buddy_unique_event_name" and the data will be "intact" or "broken"

  Since the input here is a char, we can't do
     data=="intact"
    or
     data=="broken"

  chars just don't play that way. Instead we're going to strcmp(), which compares two chars.
  If they are the same, strcmp will return 0.
  */

  if (strcmp(data,"leave")==0) {
    count++;
  }
  number(count);
    
//   if (strcmp(data,"notpushed")==0) {
//     noTone(buzzer); 
//   }
}

void myHandler2(const char *event, const char *data)
{
  /* Particle.subscribe handlers are void functions, which means they don't return anything.
  They take two variables-- the name of your event, and any data that goes along with your event.
  In this case, the event will be "buddy_unique_event_name" and the data will be "intact" or "broken"

  Since the input here is a char, we can't do
     data=="intact"
    or
     data=="broken"

  chars just don't play that way. Instead we're going to strcmp(), which compares two chars.
  If they are the same, strcmp will return 0.
  */

  if (strcmp(data,"enter")==0) {
    count--;
  }
  number(count);
    
//   if (strcmp(data,"notpushed")==0) {
//     noTone(buzzer); 
//   }
}


void number(int c)
{
    if (c<0)
    {
        c=c+10;
    }
    c=c%10;
    if (c==0)
    {
        clear();
        zero();
    }
    if (c==1)
    {
        clear();
        one();
    }
    if (c==2)
    {
        clear();
        two();
    }
    if (c==3)
    {
        clear();
        three();
    }
    if (c==4)
    {
        clear();
        four();
    }
    if (c==5)
    {
        clear();
        five();
    }
    if (c==6)
    {
        clear();
        six();
    }
    if (c==7)
    {
        clear();
        seven();
    }
    if (c==8)
    {
        clear();
        eight();
    }
    if (c==9)
    {
        clear();
        nine();
    }
}


void clear()
{
    digitalWrite(middle, LOW);
    digitalWrite(bottom_right, LOW);
    digitalWrite(top_left, LOW);
    digitalWrite(top, LOW);
    digitalWrite(top_right, LOW);
    digitalWrite(bottom_left, LOW);
    digitalWrite(bottom, LOW);
}

void one()
{
    digitalWrite(top_right, HIGH);
    digitalWrite(bottom_right, HIGH);
}
void two()
{
    digitalWrite(middle, HIGH);
    digitalWrite(top, HIGH);
    digitalWrite(top_right, HIGH);
    digitalWrite(bottom_left, HIGH);
    digitalWrite(bottom, HIGH);
}
void three()
{
    digitalWrite(middle, HIGH);
    digitalWrite(bottom_right, HIGH);
    digitalWrite(top, HIGH);
    digitalWrite(top_right, HIGH);
    digitalWrite(bottom, HIGH);
}
void four()
{
    digitalWrite(middle, HIGH);
    digitalWrite(bottom_right, HIGH);
    digitalWrite(top_left, HIGH);
    digitalWrite(top_right, HIGH);
}
void five()
{
    digitalWrite(middle, HIGH);
    digitalWrite(bottom_right, HIGH);
    digitalWrite(D5, HIGH);
    digitalWrite(top, HIGH);
    digitalWrite(bottom, HIGH);
}
void six()
{
    digitalWrite(middle, HIGH);
    digitalWrite(bottom_right, HIGH);
    digitalWrite(top_left, HIGH);
    digitalWrite(top, HIGH);
    digitalWrite(bottom_left, HIGH);
    digitalWrite(bottom, HIGH);
}
void seven()
{
    digitalWrite(bottom_right, HIGH);
    digitalWrite(top, HIGH);
    digitalWrite(top_right, HIGH);
}
void eight()
{
    digitalWrite(middle, HIGH);
    digitalWrite(bottom_right, HIGH);
    digitalWrite(top_left, HIGH);
    digitalWrite(top, HIGH);
    digitalWrite(top_right, HIGH);
    digitalWrite(bottom_left, HIGH);
    digitalWrite(bottom, HIGH);
}
void nine()
{
    digitalWrite(middle, HIGH);
    digitalWrite(bottom_right, HIGH);
    digitalWrite(top_left, HIGH);
    digitalWrite(top, HIGH);
    digitalWrite(top_right, HIGH);
    digitalWrite(bottom, HIGH);
}
void zero()
{
    digitalWrite(bottom_right, HIGH);
    digitalWrite(top_left, HIGH);
    digitalWrite(top, HIGH);
    digitalWrite(top_right, HIGH);
    digitalWrite(bottom_left, HIGH);
    digitalWrite(bottom, HIGH);
}
