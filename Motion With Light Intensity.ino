// Proper and final code for the IR Sensor
int IRSensor = 4;
// int MotionSensor = 3;
// int IRSensor1 = 2;  // connect IR sensor module to Arduino pin D9
// int LED1 = 10;
int LED = 4;      // connect LED to Arduino pin 13
int ledval = 0;
// int ledval1 = 0;
// int ledval = 255;

void setup() {
  Serial.begin(9600);                // Init Serial at 115200 Baud Rate.
  Serial.println("Serial Working");  // Test to check if serial is working or not
  pinMode(IRSensor, INPUT);   
  // pinMode(MotionSensor, INPUT); 
 // pinMode(IRSensor1, INPUT);      // IR Sensor pin INPUT
  pinMode(LED, OUTPUT);              // LED Pin Output
 // pinMode(LED1, OUTPUT);
}

void loop() {
  int sensorStatus = digitalRead(IRSensor);  // Set the GPIO as Input
  // int sensorStatus = digitalRead(MotionSensor);
  // int sensorStatus1 = digitalRead(IRSensor1);
  Serial.println(sensorStatus);
//   if (sensorStatus == 1)  // Check if the pin high or not
//   {
//     // if the pin is high turn off the onboard Led
//      //else turn on the onboard LED
//     //  for (int ledval = 0; ledval <= 255; ledval += 250) {
//       // Serial.println(ledval);
//       // delay(0);
//       analogWrite(LED, HIGH);              // LED High
//       Serial.println("Motion Detected");  // print Motion Ended! on the serial monitor window
//     //  }
//   } else {
//  // if the pin is high turn off the onboard Led
//       for (int ledval = 255; ledval >= 100; ledval -= 20) {
//       Serial.println(ledval);
//       analogWrite(LED, ledval);           // LED LOW
//       delay(500);
//       Serial.println("Motion Ended! ");  // print Motion Detected! on the serial monitor window
//     }
//     // delay(100);
//   }

  if (IRSensor == 0) 
  {
    analogWrite(LED, LOW);
  }
else if (IRSensor == ) {
  for (int ledval1 = 0; ledval1 >= 255; ledval += 100) {
    Serial.println(ledval1);
    analogWrite(LED, ledval1);
  }
}




 // if (sensorStatus1 == 1)  // Check if the pin high or not
//  {
    // if the pin is high turn off the onboard Led
     //else turn on the onboard LED
    //  for (int ledval = 0; ledval <= 255; ledval += 250) {
      // Serial.println(ledval);
      // delay(0);
   //   analogWrite(LED1, HIGH);              // LED High
   //   Serial.println("Motion Detected");  // print Motion Ended! on the serial monitor window
    //  }
 // } else {
 // if the pin is high turn off the onboard Led
  //    for (int ledval = 255; ledval >= 100; ledval -= 20) {
      // Serial.println(ledval);
      // analogWrite(LED1, ledval);           // LED LOW
      // delay(500);
      // Serial.println("Motion Ended! ");  // print Motion Detected! on the serial monitor window
    // }
    // delay(100);
  // }
}