// Proper and final code for the IR Sensor
int IRSensor = 4;  // connect IR sensor module to Arduino pin D9
int LED = 10;     // connect LED to Arduino pin 13
int MotionSensor = 5;
// int ledval = 0;
// int ledval1 = 0;

// int ledval = 255;

void setup() {
  Serial.begin(9600);                // Init Serial at 115200 Baud Rate.
  Serial.println("Serial Working");  // Test to check if serial is working or not
  pinMode(IRSensor, INPUT);  
  // pinMode(MotionSensor, INPUT);        // IR Sensor pin INPUT
  pinMode(LED, OUTPUT);              // LED Pin Output
}

void loop() {
  int sensorStatus = digitalRead(IRSensor);  // Set the GPIO as Input
  // int sensorStatus1 = digitalRead(MotionSensor);
  Serial.println(sensorStatus);
  if (sensorStatus == 1)  // Check if the pin high or not
  {
    // if the pin is high turn off the onboard Led
     //else turn on the onboard LED
     for (int ledval = 0; ledval <= 255; ledval += 250) {
      Serial.println(ledval);
      // delay(0);
      // analogWrite(LED, HIGH);              // LED High
      Serial.println("Motion Ended!");  // print Motion Ended! on the serial monitor window
     }
  } else if (sensorStatus == 0) {
 // if the pin is high turn off the onboard Led
      for (int ledval = 255; ledval >= 100; ledval -= 20) {
      Serial.println(ledval);
      analogWrite(LED, ledval);           // LED LOW
      delay(200);
      Serial.println("Motion Detected!");  // print Motion Detected! on the serial monitor window
    }
    // delay(100);
  }



//   // Code for the Motion Sensor
// if (sensorStatus == 1) {
//   for (int ledval = 0; ledval <= 255; ledval += 250) {
//       Serial.println(ledval);
//       // delay(0);
//       // analogWrite(LED, HIGH);              // LED High
//       Serial.println("Motion Ended!");  // print Motion Ended! on the serial monitor window
//   }
// }
// else if (sensorStatus == 1) {
//   for (int ledval1 = 255; ledval <= 100; ledval -= 20) {
//   Serial.println(ledval1);
//   analogWrite(LED, ledval1);
//   delay(200);
//   }
// }
}