/**
 * @file SimpleThermometer.ino
 * This a simple serial port thermometer application using the Termopar Nanoshield.
 * 
 * Copyright (c) 2015 Circuitar
 * This software is released under the MIT license. See the attached LICENSE file for details.
 */
#include <SPI.h>
#include "Nanoshield_Termopar.h"

// Termopar Nanoshield on CS pin D8, type K thermocouple, no averaging
Nanoshield_Termopar tc(8, TC_TYPE_K, TC_AVG_OFF);

void setup()
{
  Serial.begin(9600);
  Serial.println("-------------------------------");
  Serial.println(" Nanoshield Serial Thermometer");
  Serial.println("-------------------------------");
  Serial.println();

  tc.begin();
}

void printErrors() {
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

  // Wait for next second
  delay(1000);
}

