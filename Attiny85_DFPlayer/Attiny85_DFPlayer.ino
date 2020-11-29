/*
 * Just Barran 28/110/2020
 * www.youtube.com/c/justbarran
 * 
 * Full Video https://youtu.be/GLvS-KOgH4k
 * 
 */

#include "Arduino.h"
#include <SoftSerial.h>     /* Allows Pin Change Interrupt Vector Sharing */
#include <TinyPinChange.h>  /* Ne pas oublier d'inclure la librairie <TinyPinChange> qui est utilisee par la librairie <RcSeq> */
#include "DFRobotDFPlayerMini.h"

SoftSerial mySoftwareSerial(1, 2); // RX, TX

DFRobotDFPlayerMini myDFPlayer;
const int buttonPin1 = 0;  // Will need to be pulled up
const int buttonPin2 = 3;  // will need to be pulled up

unsigned int randomNumber = 0;
void setup()
{
  pinMode(buttonPin1, INPUT); 
  pinMode(buttonPin2, INPUT); 
  
  randomSeed(analogRead(A0));
  mySoftwareSerial.begin(9600);  
  myDFPlayer.begin(mySoftwareSerial);
  myDFPlayer.volume(30);  //Set volume value. From 0 to 30
  myDFPlayer.play(1);  //Play the first mp3
}

void loop()
{
  if(digitalRead(buttonPin1) == LOW ||digitalRead(buttonPin2) == LOW )
  {
    randomNumber = random(0, 20);
    myDFPlayer.play(randomNumber);  //Play the first mp3
    delay(1000);
  }   
}
