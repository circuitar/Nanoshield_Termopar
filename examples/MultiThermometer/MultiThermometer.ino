/**
 * @file MultiThermometer.ino
 * Read temperatures from multiple Termopar Nanoshields.
 * 
 * Copyright (c) 2015 Circuitar
 * This software is released under the MIT license. See the attached LICENSE file for details.
 */
#include <SPI.h>
#include "Nanoshield_Termopar.h"

// Create an array of three thermocouples
Nanoshield_Termopar tc[] = {
  Nanoshield_Termopar(4, TC_TYPE_K, TC_AVG_OFF),
  Nanoshield_Termopar(7, TC_TYPE_J, TC_AVG_2_SAMPLES),
  Nanoshield_Termopar(8, TC_TYPE_S, TC_AVG_4_SAMPLES),
  Nanoshield_Termopar(10, TC_TYPE_T, TC_AVG_8_SAMPLES),
  Nanoshield_Termopar(A3, TC_TYPE_B, TC_AVG_16_SAMPLES)
};

const int numModules = sizeof(tc) / sizeof(Nanoshield_Termopar);

void setup()
{
  Serial.begin(9600);
  Serial.println("------------------");
  Serial.println(" MultiThermometer");
  Serial.println("------------------");
  Serial.println();

  // Initialize each Termopar Nanoshield
  for(int i = 0; i < numModules; i++) {
    tc[i].begin();
  }
}

void printErrors(Nanoshield_Termopar tc) {
  if (tc.isOpen()) {
    Serial.print("(Open circuit) ");
  } else if (tc.isOverUnderVoltage()) {
    Serial.print("(Overvoltage/Undervotage) ");
  } else if (tc.isInternalOutOfRange()) {
    Serial.print("(Internal temperature out of range) ");
  } else if (tc.isExternalOutOfRange()) {
    Serial.print("(External temperature out of range) ");
  }
}

void loop()
{
  for(int i = 0; i < numModules; i++) {
    // Read thermocouple data
    tc[i].read();
    
    // Print thermocouple number
    Serial.print(i + 1);
    Serial.print(": ");
  
    // Print temperature in the serial port, checking for errors
    if (tc[i].hasError()) {
      printErrors(tc[i]);
    } else {
      Serial.print("Internal: ");
      Serial.print(tc[i].getInternal());
      Serial.print(" | External: ");
      Serial.print(tc[i].getExternal());
    }
    Serial.println();
  }
  Serial.println();

  // Wait for next second
  delay(1000);
}