
const int WATER_LVEVEL_SENSOR_PIN = 7;
const int BUZZER_PIN = 5;

boolean waterLow = false;

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT); // Set buzzer - pin 5 as an output
}

void loop() {
  int waterLevel = analogRead(WATER_LVEVEL_SENSOR_PIN); 
  Serial.println(waterLevel);
  
  if (waterLevel >= 0 && waterLevel <= 300) {
    Serial.println("water level: LOW");
    waterLow = true;
  } else  {
    Serial.println("water level: HIGH");
    waterLow = false;
  } 

  if (waterLow) {
    tone(BUZZER_PIN, 1000); // Send 1KHz sound signal...
    delay(1000);       
    noTone(BUZZER_PIN);     
  }
  delay(1000);        
}
