/**
 * @file OpenCircuitDetection.ino
 * This is an example showing how to disable the open circuit detectionor change its parameters.
 * 
 * Copyright (c) 2017 Circuitar
 * This software is released under the MIT license. See the attached LICENSE file for details.
 */
#include <SPI.h>
#include "Nanoshield_Termopar.h"

// Termopar Nanoshield on CS pin D8, type K thermocouple, no averaging, open circuit detection off
// Possible values for the open circuit detection parameter:
//   - TC_OCD_OFF: no open circuit detection
//   - TC_OCD_15_MS: open circuit detection with maximum test time of 15ms (default if not specified)
//   - TC_OCD_37_MS: open circuit detection with maximum test time of 37ms
//   - TC_OCD_125_MS:  open circuit detection with maximum test time of 125ms
Nanoshield_Termopar tc(8, TC_TYPE_K, TC_AVG_OFF, TC_OCD_OFF);

void setup()
{
  Serial.begin(9600);
  Serial.println("-----------------------------------------------------------");
  Serial.println(" Nanoshield Serial Thermometer - No Open Circuit Detection");
  Serial.println("-----------------------------------------------------------");
  Serial.println();

  tc.begin();
}

void printErrors() {
  if (tc.isOpen()) {
    Serial.print("Open circuit");
  } else if (tc.isOverUnderVoltage()) {
    Serial.print("Overvoltage/Undervoltage");
  } else if (tc.isInternalOutOfRange()) {
    Serial.print("Internal temperature (cold junction) out of range)");
  } else if (tc.isExternalOutOfRange()) {
    Serial.print("External temperature (hot junction) out of range");
  }
}

void loop()
{
  // Read thermocouple data
  tc.read();

  // Print temperature in the serial port, checking for errors
  if (tc.hasError()) {
    printErrors();
  } else {
    Serial.print("Internal: ");
    Serial.print(tc.getInternal());
    Serial.print(" | External: ");
    Serial.print(tc.getExternal());
  }
  Serial.println();

  // Wait for next reading
  delay(1000);
}

