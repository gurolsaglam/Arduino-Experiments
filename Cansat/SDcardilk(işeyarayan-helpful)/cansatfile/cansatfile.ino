/** SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (SDPin variable'ını değiştirirsen değiştirebilirsin)
 * (5V ve ground bağlamayı unutma)
*/

#include <SPI.h>
#include <SD.h>

File myFile;
int SDPin=4;
String fileName="example.txt";
String theData="datas will be stored and/or gathered here.";

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  if (!SD.begin(SDPin)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  
  //checks if the file exists and deletes if it exists
  if (SD.exists(fileName)) {
    SD.remove(fileName);
  }
  
  // creates file:
  Serial.println("Creating "+fileName);
  myFile = SD.open(fileName, FILE_WRITE);
}

void loop() {
  myFile.println(theData);
  //if the data is not a string, remember to convert it to string
  /*remember to add flush in the loop because otherwise the data will
   *not be saved in the file since you don't close the file
   *(by closing the file it automatically flushes)*/
  myFile.flush();
}


