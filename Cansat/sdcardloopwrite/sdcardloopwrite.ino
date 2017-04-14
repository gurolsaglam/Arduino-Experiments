/** SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4
 * (5V ve ground bağlamayı unutma)

*Analog pin A0 (Potansiyometre ile denedim, 0 ile 1023 arasında değer gönderen bir şey)
*
*Potansiyometreden analog değer alıp bunu seri portta print edip SD kartta dosyaya kaydediyor, 
*daha sonra sentinel değerini aldığında duruyor, böylece dosyaya kaydettiği değerleri çağırma 
*kısmına geçiyor. Dosyayı silmek için en alttaki kısmı kullanmak yeterli.
*/

#include <SPI.h>
#include <SD.h>

File myFile;

void intwrite(){
  for (int i=0;i<256;i++){
    myFile.println(i);
    delay(150);
  }
}

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  
  //checks if the file exists
  if (SD.exists("example.txt")) {
    Serial.println("example.txt exists.");
    SD.remove("example.txt");
  } else {
    Serial.println("example.txt doesn't exist.");
  }
  
  // open a new file:
  Serial.println("Creating example.txt...");
  myFile = SD.open("example.txt", FILE_WRITE);
  intwrite();
  //close the file
  Serial.println("done.");
  myFile.close();
  
  // delete the file:
  //Serial.println("Removing example.txt...");
  //SD.remove("example.txt");
}

void loop() {
  // put your main code here, to run repeatedly:
}

