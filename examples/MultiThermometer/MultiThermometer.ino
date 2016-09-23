/**
 * @file MultiThermometer.ino
 * Read temperatures from multiple Termopar Nanoshields, with different thermocouple types.
 * 
 * Copyright (c) 2015 Circuitar
 * This software is released under the MIT license. See the attached LICENSE file for details.
 */
#include <SPI.h>
#include "Nanoshield_Termopar.h"

// Create an array of five thermocouples of different types
Nanoshield_Termopar tc[] = {
  Nanoshield_Termopar(4, TC_TYPE_K, TC_AVG_OFF),        // Jumper on D4, type K, no averaging
  Nanoshield_Termopar(7, TC_TYPE_J, TC_AVG_2_SAMPLES),  // Jumper on D7, type J, averaging of 2 samples
  Nanoshield_Termopar(8, TC_TYPE_S, TC_AVG_4_SAMPLES),  // Jumper on D8, type S, averaging of 4 samples
  Nanoshield_Termopar(10, TC_TYPE_T, TC_AVG_8_SAMPLES), // Jumper on D10, type T, averaging of 8 samples
  Nanoshield_Termopar(A3, TC_TYPE_B, TC_AVG_16_SAMPLES) // Jumper on A3, type B, averaging of 16 samples
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