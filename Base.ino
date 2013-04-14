// Import libraries
#include <SPI.h>
#include "printf.h"
#include "nRF24L01.h"
#include "RF24.h"
#include "Mesh.h"
#include "SimpleMap.h"
#include "timer.h"

// Set up nRF24L01 radio on SPI bus pin CE and CS
RF24 radio(9,10);
// Set up Mesh network
Mesh mesh(radio);
// Declare radio channel 0-127
const uint8_t channel = 76;
// Declare base id, it should be 00
const uint16_t base_id = 00;

// Declare state map keys
#define RELAY_1  "relay_1"
#define RELAY_2  "relay_2"

// Declare delay manager in ms
timer_t send_timer(7000);

// Debug info.
const bool DEBUG = true;

//
// Setup
//
void setup()
{
  // Configure console
  Serial.begin(57600);
  printf_begin();
  
  // initialize radio
  radio.begin();
  // initialize network
  mesh.begin(channel, base_id);
}

//
// Loop
//
void loop()
{
  // update network
  mesh.update();
  
  
  // new message available
  while( mesh.available() ) {
    Payload payload;
    mesh.read(payload);
  }
  
  if ( mesh.ready() && send_timer ) {

    //Payload payload1(RELAY_1, true);
    //mesh.send(payload1, 1001);
    //Payload payload2(RELAY_2, true);
    //mesh.send(payload2, 1001);
  }
}
