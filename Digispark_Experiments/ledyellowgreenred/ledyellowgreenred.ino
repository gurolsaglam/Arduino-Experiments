#define USB_CFG_DEVICE_NAME     'D','i','g','i','B','l','i','n','k'
#define USB_CFG_DEVICE_NAME_LEN 9
#include <DigiUSB.h>
byte in = 0;
int Yellow = 0;
int Red = 0;
int Green = 0;

int next = 0;

void setup() {
    DigiUSB.begin();
    pinMode(0,OUTPUT); //yellow
    pinMode(1,OUTPUT); //green
    pinMode(2,OUTPUT); //red
}


void loop() {
  setYellow();
      DigiUSB.refresh();
      setYellow();
     if (DigiUSB.available() > 0) {
       in = 0;
       
       in = DigiUSB.read();
       if (next == 0){
         if(in == 115){
           next = 1;
           DigiUSB.println("Start");
         }
       }
       else if (next == 1){
            Red = in;
            DigiUSB.print("Red ");
            DigiUSB.println(in,DEC);
            next = 2;
       }
       else if (next == 2){
            Green = in;
            DigiUSB.print("Green ");
            DigiUSB.println(in,DEC);
            next = 3;
       }
       else if (next == 3){
            Yellow = in;
            DigiUSB.print("Yellow ");
            DigiUSB.println(in,DEC);
            next = 0;
       }


        
        
     }
     

    analogWrite(2,Red);
    analogWrite(1,Green);
     setYellow();

     
   
}

void setYellow(){
    if(Yellow == 0){
      digitalWrite(0,LOW);
      return;
    }
    else if(Yellow == 255){
      digitalWrite(0,HIGH);
      return;
    }
    // On period  
    for (int x=0;x<Yellow;x++){
    digitalWrite(0,HIGH);
    } 
    
    // Off period
    
    for(int x=0;x<(255-Yellow);x++){
    digitalWrite(0,LOW);
    }
  
} 

