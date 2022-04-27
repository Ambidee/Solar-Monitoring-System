#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;
void setup(void) 
{
  Serial.begin(115200);
  while (!Serial) {
      delay(1);
  }

  uint32_t currentFrequency;
    
  Serial.println("Hello!");
  // Initialize the INA219.
  // By default the initialization will use the largest range (32V, 2A). 
  if (! ina219.begin()) {
    Serial.println("Failed to find INA219 chip");
    while (1) { delay(10); }
  }
  
  Serial.println("Measuring voltage and current with INA219 ...");
}

void loop(void) 
{
  float shuntvoltage = 0;
  float busvoltage = 0;
  float current_mA = 0;
  float loadvoltage = 0;
  float power_mW = 0;

  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  power_mW = ina219.getPower_mW();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  
  //Prints out voltage and current of Panel connected
  Serial.print("Voltage:  "); Serial.print(loadvoltage); Serial.println(" V");
  Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");

  Serial.println("");

  delay(2000);
}