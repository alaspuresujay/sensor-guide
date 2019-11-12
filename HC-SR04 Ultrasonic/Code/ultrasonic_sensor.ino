#define echopin  12 // echo pin to the 12th pin of the arduino
#define trigpin 9 // Trigger pin to the 9th pin of the arduino
int maximumRange = 30; // sets the maximum sensor range to the 30 cm
long duration, distance; // sets duration and distance to long data type

void setup() {
  Serial.begin (9600); // begin the serial communication to the baud rate of 9600 
  pinMode (trigpin, OUTPUT);   //sets the trig pin of sensor for o/p
  pinMode (echopin, INPUT );  //sets echo pin of sensor i/p
}

void loop () {
    digitalWrite(trigpin,LOW);     //initially set the trig pin to the low state
    delayMicroseconds(2);           // delay of 2 milli seconds
    
    digitalWrite(trigpin,HIGH);     //sets trig pin to high state
    delayMicroseconds(10);           //delay of 10millis
    
    duration=pulseIn (echopin,HIGH);  //duration for echo pin to  go in to the high state
    
    distance= duration/58.2; //measuring the distance of an object from sensor
    delay (50);// delay of 50 millis
    Serial.println(distance);//taking the distance 
}
