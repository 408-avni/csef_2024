//Pin 2 and 3 are the output signal pins. Changing HIGH/LOW for the pins changes the current direction in the electromagnet thus changing the magnetic field direction.
#define in1 2
#define in2 3

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
// a Potentiometer is used to change the frequency within a range of 70 kHz to 5 kHz. t/2 = 1000*1000/2f MicroSeconds in integer value.
int value = analogRead(A0);
//map the Potentiometer inout to the desired t/2 range to achieve the desired frequency range. Unit of t is microseconds.
value = map(value, 0, 1023, 7, 100);

//set one direction of the current
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
//delay of t/2 time causes the half wave of the SQUARE wave
delayMicroseconds(value);

//cange direction of the current
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);

//delay of t/2 time causes the other half wave of the SQUARE wave
delayMicroseconds(value);
}
