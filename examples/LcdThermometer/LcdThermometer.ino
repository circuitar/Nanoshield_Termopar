/**
 * @file LcdThermometer.ino
 * This is a thermometer with an LCD display using the Termopar Nanoshield and the LCD Nanoshield.
 * 
 * Copyright (c) 2016 Circuitar
 * This software is released under the MIT license. See the attached LICENSE file for details.
 */
#include <SPI.h>
#include "Nanoshield_Termopar.h"
#include "Nanoshield_LCD.h"

// Termopar Nanoshield on CS pin D8, type K thermocouple, no averaging
Nanoshield_Termopar tc(8, TC_TYPE_K, TC_AVG_OFF);

// LCD Nanoshield
Nanoshield_LCD lcd;

// True if there is a thermocouple error
bool error = false;

void setup()
{
  // Initialize Nanoshields
  tc.begin();
  lcd.begin();
}

void printErrors() {
}

void loop()
{
  // Read thermocouple data
  tc.read();

  if (tc.hasError()) {
    // If there is an error, show it on the LCD
    error = true;
    lcd.clear();
    if (tc.isOpen()) {
      lcd.print("Open circuit");
    } else if (tc.isOverUnderVoltage()) {
      lcd.print("Voltage error");
    } else if (tc.isInternalOutOfRange() || tc.isExternalOutOfRange()) {
      lcd.print("Out of range");
    }
  } else {
    // Thermocouple OK, show cold junction and hot junction temperatures on the LCD
    if (error) {
      lcd.clear();
      error = false;
    } else {
      lcd.home();
    }
    lcd.print("Cold: ");
    lcd.print(tc.getInternal());
    lcd.setCursor(0, 1);
    lcd.print("Hot:  ");
    lcd.print(tc.getExternal());
  }

  // Wait for next reading
  delay(1000);
}

