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

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  if (!SD.begin(SDPin)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  if(SD.exists(fileName)){
    myFile=SD.open(fileName,FILE_READ);
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
  }

void loop() {
  // put your main code here, to run repeatedly:

}
