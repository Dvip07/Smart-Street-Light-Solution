// Code to change the Intensity of LED using delay

int LED = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Serial Working");
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int ledval = 0; ledval <= 255; ledval += 1) {
    Serial.println(ledval);
    analogWrite(LED, ledval);
    // You can change the LED delay through here
    delay(0);
  }
}
