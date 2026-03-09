#define WAKEUP_PINS 0x14   // GPIO2 and GPIO4 (2^2 + 2^4)

RTC_DATA_ATTR int restartCount = 0;

void setup() {

  Serial.begin(115200);
  delay(1000);

  restartCount++;
  Serial.print("Restart count: ");
  Serial.println(restartCount);

  // Check which pin caused wakeup
  uint64_t wakeup_pin = esp_sleep_get_ext1_wakeup_status();

  if (wakeup_pin != 0) {
    Serial.print("Wakeup caused by GPIO: ");
    Serial.println(log(wakeup_pin) / log(2));
  } 
  else {
    Serial.println("Normal startup");
  }

  Serial.println("Going to deep sleep...");

  // Enable EXT1 wakeup
  esp_sleep_enable_ext1_wakeup(WAKEUP_PINS, ESP_EXT1_WAKEUP_ANY_HIGH);

  delay(1000);

  esp_deep_sleep_start();
}

void loop() {
  // Not used
}