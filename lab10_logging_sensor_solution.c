// Part 1 code
#include <SPI.h>
#include <SD.h>

const int CHIP_SELECT = 8;
const char FILE_NAME[] = "data26.txt";


File f;
unsigned long t1;

void setup() {
  delay(5000);
  Serial.begin(9600); 

  Serial.print("\nInitializing SD card........");

  if (!SD.begin(CHIP_SELECT)) {
    Serial.println("initialization failed. Things to check:");
    Serial.println("* is a card inserted?");
    Serial.println("* is your wiring correct?");
    while (1);
  } else {
    Serial.println("Wiring is correct and a card is present.");
  }

  if (SD.exists(FILE_NAME)) {
    SD.remove(FILE_NAME);
  }
  f = SD.open(FILE_NAME, FILE_WRITE);
  
  if (!f) {
    Serial.println("Could not open the txt file.");
    while (1);
  }

  t1 = millis();
}

void loop() {
  if (millis() - t1 <= 20000) {
    int sensor_value = analogRead(A0);
    Serial.println(sensor_value); 
    f.println(sensor_value);     
    delay(250);   
  } else {
    f.close();
    Serial.println("Data collection is complete!");  
    while (1) {}
  }     
}

// Part 2 Code
#include <stdio.h>
#include <stdlib.h>

const int THRESHOLD = 500;
int counting_blocks() {
    char line[10];
    FILE *in = fopen("DATA26.TXT", "r");

    if (in == NULL) {
        perror("fopen");
        return -1;
    }

    int flag_blocked = -1; // We can use 0 as well.
    int count = 0;
    while (fgets(line, sizeof(line), in) != NULL) {
        int d = atoi(line);
        if (d < THRESHOLD && flag_blocked == -1) {
            flag_blocked = 1;
            count++;
        } else if (d >= THRESHOLD) 
            flag_blocked = -1;
    }
    fclose(in);

    return count;
}

int main(void) {
    printf("%d\n", counting_blocks());
    return 0;
}
