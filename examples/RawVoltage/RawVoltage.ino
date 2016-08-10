/**
 * @file RawVoltage.ino
 * Read a raw thermocouple voltage using the Termopar Nanoshield.
 * 
 * Copyright (c) 2016 Circuitar
 * This software is released under the MIT license. See the attached LICENSE file for details.
 */
#include <SPI.h>
#include "Nanoshield_Termopar.h"

// Termopar Nanoshield on CS pin D8, raw voltage reading with gain 32 (+/- 19.531mV range), no averaging
Nanoshield_Termopar tc(8, TC_TYPE_VOLTAGE_GAIN_32, TC_AVG_OFF);

void setup()
{
  Serial.begin(9600);
  Serial.println("--------------------------");
  Serial.println(" Thermocouple Raw Voltage");
  Serial.println("--------------------------");
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
    Serial.print("Cold junction: ");
    Serial.print(tc.getInternal());
    Serial.print(" degC | Thermocouple voltage: ");
    Serial.print(tc.getExternal() * 1000, 3);
    Serial.print(" mV");
  }
  Serial.println();

  // Wait for next second
  delay(1000);
}
