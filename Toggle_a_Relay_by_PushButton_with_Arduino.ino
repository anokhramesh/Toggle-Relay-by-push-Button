//Anokhautomation
//Toggle a Relay by a Push button and Arduino
//follow  the circuit diagram


int relay = 12;//connect relay to digital pin 12 of Arduino)
int button = 11;//push button to digital pin 11 of Arduino(connet a 10 K resiter to Ground keep it PULLDOWN
int relayState = LOW;// at initial relay status is OFF
int buttonCurrent;// cteaed an integer variable name buttonCurrent
int buttonPrevious = LOW;// default state of button is LOW

void setup()
{
  Serial.begin(9600);//baud rate of serial communication
  pinMode(button, INPUT);//Pin 11 is assigned to receive an INPUT Value
  pinMode(relay , OUTPUT);//Pin 12 is assigned to deliver  an OUTPUT Value
}
void loop() {
  buttonCurrent = digitalRead(button);// the variable( buttonCurrent) will store the value of button
  if (buttonCurrent == HIGH && buttonPrevious == LOW)
  {
    if (relayState == HIGH) {
      relayState = LOW;
    }

    else {
      relayState = HIGH;
    }
  }
  digitalWrite(relay, relayState);
  //Serial.println(relayState);
  buttonPrevious = buttonCurrent;
  delay(100);
}
