#define IR_SENSOR_PIN 32
#define VIBRATION_SENSOR_PIN 33
#define FORCE_SENSOR_PIN 34  // Analog
// #define TOUCH_SENSOR_PIN 27    // Capacitive touch
#define BUZZER_PIN 25
#define LED_PIN 26

void setup() {
  Serial.begin(115200);

  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(VIBRATION_SENSOR_PIN, INPUT);
  pinMode(FORCE_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.println("Sensors Initialized");
}

void loop() {
  int irStatus = digitalRead(IR_SENSOR_PIN);
  int vibrationStatus = digitalRead(VIBRATION_SENSOR_PIN);
  int forceValue = analogRead(FORCE_SENSOR_PIN);
  // int touchValue = touchRead(TOUCH_SENSOR_PIN);

  Serial.print("IR: "); Serial.print(irStatus);
  Serial.print(" | Vibration: "); Serial.print(vibrationStatus);
  Serial.print(" | Force: "); Serial.println(forceValue);
  // Serial.print(" | Touch: "); Serial.println(touchValue);

  // If IR detects an object, turn on LED
  if (irStatus == 0) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  // If vibration is detected, sound the buzzer
  if (vibrationStatus == HIGH) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(500);
    digitalWrite(BUZZER_PIN, LOW);
  }

  // If force sensor is pressed above a threshold, turn on LED
  if (forceValue > 1000) {
    digitalWrite(LED_PIN, HIGH);
  } 
  // else {
  //   digitalWrite(LED_PIN, LOW);
  // }

  // If touch sensor is activated, turn on buzzer
  // if (touchValue > 30) {  // Adjust sensitivity
  //   digitalWrite(BUZZER_PIN, HIGH);
  //   delay(500);
  //   digitalWrite(BUZZER_PIN, LOW);
  // }

  delay(200);
}
