// Import libraries
#include <SPI.h>
#include "printf.h"
#include "nRF24L01.h"
#include "RF24.h"
#include "Mesh.h"
#include "timer.h"
#include "EtherCard.h"

// Declare SPI bus pins
#define CE_PIN  9
#define CS_RADIO_PIN  10
#define CS_ETHERNET_PIN  11

// Set up nRF24L01 radio
RF24 radio(CE_PIN, CS_RADIO_PIN);
// Set up Mesh network
Mesh mesh(radio);
// Declare radio channel 0-127
const uint8_t channel = 76;
// Declare base id, it should be 00
const uint16_t base_id = 00;

// Declare ethernet mac address
static byte mymac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };
// Declare ethernet buffer
byte Ethernet::buffer[700];

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
  // initialize mesh radio network
  mesh.begin(channel, base_id);

  // initialize ethernet
  ether.begin(sizeof Ethernet::buffer, mymac, CS_ETHERNET_PIN);
  // setup dhcp client
  bool ok = ether.dhcpSetup();
  if(ok) {
    if(DEBUG) {
      ether.printIp("DHCP: Info: IP: ", ether.myip);
      ether.printIp("DHCP: Info: Gateway: ", ether.gwip);
      ether.printIp("DHCP: Info: DNS: ", ether.dnsip);
    }
  } else {
    printf("DHCP: Error: DHCP failed!\n\r");
  } 
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
