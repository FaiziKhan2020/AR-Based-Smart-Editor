 int LED = 11;
 String inString="";
 int voltageLevel =0;
void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  while (!Serial) {
 
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
   int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char
      // and add it to the string:
      inString += (char)inChar;
    }
    // if you get a newline, print the string,
    // then the string's value:
    if (inChar == '\n') {
      voltageLevel = inString.toInt();
      inString = "";
    }
    }
    else
    analogWrite(LED,voltageLevel);
}
