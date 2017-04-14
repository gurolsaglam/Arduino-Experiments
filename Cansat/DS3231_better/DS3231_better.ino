#include <Wire.h>
#define DS3231_I2C_ADDRESS 0x68 //$$DS3231 satırı

String missionTime; //$$DS3231 satırı

// Convert normal decimal numbers to binary coded decimal //$$DS3231 satırı
byte decToBcd(byte val){
  return( (val/10*16) + (val%10) );
}
// Convert binary coded decimal to normal decimal numbers //$$DS3231 satırı
byte bcdToDec(byte val){
  return( (val/16*10) + (val%16) );
}

// Zamanı okuyan metod bu//$$DS3231 satırı
void readDS3231time(byte *second, byte *minute, byte *hour,
  byte *dayOfWeek, byte *dayOfMonth, byte *month, byte *year){
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set DS3231 register pointer to 00h
  Wire.endTransmission(true);
  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
  // request seven bytes of data from DS3231 starting from register 00h
  *second = bcdToDec(Wire.read() & 0x7f);
  *minute = bcdToDec(Wire.read());
  *hour = bcdToDec(Wire.read() & 0x3f);
  *dayOfWeek = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month = bcdToDec(Wire.read());
  *year = bcdToDec(Wire.read());
}

String getTime(){//$$DS3231 satırı
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  // retrieve data from DS3231
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
  &year);
  String timing=String(hour,DEC)+":"+String(minute,DEC)+":"+String(second,DEC);
  return timing;
}

void setDS3231time(byte second, byte minute, byte hour, byte dayOfWeek, byte
dayOfMonth, byte month, byte year){
  // sets time and date data to DS3231
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set next input to start at the seconds register
  Wire.write(decToBcd(second)); // set seconds
  Wire.write(decToBcd(minute)); // set minutes
  Wire.write(decToBcd(hour)); // set hours
  Wire.write(decToBcd(dayOfWeek)); // set day of week (1=Sunday, 7=Saturday)
  Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31)
  Wire.write(decToBcd(month)); // set month
  Wire.write(decToBcd(year)); // set year (0 to 99)
  Wire.endTransmission(true);
}

void setup() {
  Wire.begin();
  Serial.begin(9600);
  // set the initial time here:
  // DS3231 seconds, minutes, hours, day, date, month, year
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  // retrieve data from DS3231
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
  &year);
  /*setDS3231time(00,00,00,5,08,12,56); bu satırı yarışmadan önce saati
   *sıfırlamak için çalıştıracağız, alttaki if satırlarını kullanmadan,
   *daha sonra bu satırı kullanmadan yarışmada kodu normal çalıştıracağız.
   *yani yarışmadaki arduinoda kodumuz if satırlı olan iken DS3231 saatimiz
   *bu satırdaki saat olacak*/
  if (year==56){
    setDS3231time(00,00,00,5,07,12,16);
  } else {
    setDS3231time(second,minute,hour,dayOfWeek,dayOfMonth,month,year);
  }
}

void loop() {
  missionTime=getTime(); //$$DS3231 satırı
  Serial.println(missionTime);
  delay(1000);
}
