const int wakePin = 4;     // External wakeup pin
RTC_DATA_ATTR int startCounter = 0;   // Stored in RTC memory

void setup()
{
  Serial.begin(115200);
  delay(1000);

  pinMode(wakePin, INPUT_PULLUP);   // Button connected to GND

  startCounter++;
  Serial.print("System wake count: ");
  Serial.println(startCounter);

  Serial.println("Entering deep sleep soon...");

  // Configure EXT0 wakeup (wake when pin goes LOW)
  esp_sleep_enable_ext0_wakeup((gpio_num_t)wakePin, 0);

  delay(1000);   // small delay before sleep

  esp_deep_sleep_start();
}

void loop()
{

}