/**
 * @file TemperatureDatalogger.ino
 * This program periodically reads temperature from multiple Termopar Nanoshields and logs it into
 * an SD card.
 * 
 * Copyright (c) 2016 Circuitar
 * This software is released under the MIT license. See the attached LICENSE file for details.
 */
#include <SPI.h>
#include <SD.h>
#include "Nanoshield_Termopar.h"

#define FILENAME "datalog.txt" // Name of the file to use in the SD card (max 8+3 characters)
#define SAMPLE_TIME 10000      // Sample time, in milliseconds

// Create an array of five type K thermocouples
Nanoshield_Termopar tc[] = {
  Nanoshield_Termopar(7, TC_TYPE_K),  // Jumper on D7
  Nanoshield_Termopar(8, TC_TYPE_K),  // Jumper on D8
  Nanoshield_Termopar(10, TC_TYPE_K), // Jumper on D10
  Nanoshield_Termopar(A3, TC_TYPE_K)  // Jumper on A3
};
const int numModules = sizeof(tc) / sizeof(Nanoshield_Termopar);

// Use pin D4 as the SD card CS pin
const int cardChipSelect = 4;

void setup()
{
  Serial.begin(9600);
  Serial.println("------------------------");
  Serial.println(" Temperature Datalogger");
  Serial.println("------------------------");
  Serial.println();

  // Initialize each Termopar Nanoshield
  for(int i = 0; i < numModules; i++) {
    tc[i].begin();
  }

  // Initialize the SD card
  if (!SD.begin(cardChipSelect)) {
    Serial.println("Unable to find SD card, aborting");
    while (true);
  }
  Serial.println("SD card initialized");
}

void loop()
{
  File dataFile = SD.open(FILENAME, FILE_WRITE);

  if (dataFile) {
    // Write current time to the file, in milliseconds
    unsigned long t = millis();
    dataFile.print(t);

    for(int i = 0; i < numModules; i++) {
      // Read thermocouple data
      tc[i].read();
      
      // Write temperature data to the file
      dataFile.print(',');
      if (!tc[i].hasError()) {
        dataFile.print(tc[i].getExternal());
      }
    }
    dataFile.println();
    dataFile.close();
    dataFile.flush();

    Serial.print("Temperature data logged at ");
    Serial.print(t);
    Serial.println("ms");
  } else {
    Serial.println("Unable to open file");
  }

  // Save temperature data every 10 seconds
  delay(SAMPLE_TIME);
}
