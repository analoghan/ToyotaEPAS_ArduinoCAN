// CAN Bus Transmitter Code - Blake McBride/M^2
// Based on Code from Adafruit and MCP_CAN

#include <mcp_can.h>
#include <SPI.h>

MCP_CAN CAN0(10);   // Set CS to pin 10

void setup()
{
  Serial.begin(115200);

  // CAN Control Setup
  // Initialize MCP2515 running at 8MHz with a baudrate of 500kb/s and the masks and filters disabled.
  if(CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK) Serial.println("MCP2515 Initialized Successfully!");
  else Serial.println("Error Initializing MCP2515...");

  CAN0.setMode(MCP_NORMAL);   // Change to normal mode to allow messages to be transmitted  
}

byte data[8] = {0x06, 0x8A, 0x00, 0x19, 0x00, 0x00, 0x92, 0x09};

void loop()

{
  // send data:  ID = 0x2C4, Standard CAN Frame, Data length = 8 bytes, 'data' = array of data bytes to send
  byte sndStat = CAN0.sendMsgBuf(0x2C4, 0, 8, data);
  if(sndStat == CAN_OK){
    Serial.println("Message Sent Successfully!");
  } else {
    Serial.println("Error Sending Message...");
  }
  delay(20);   // send data per 20ms

}
