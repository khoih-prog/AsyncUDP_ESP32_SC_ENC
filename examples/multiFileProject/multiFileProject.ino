/****************************************************************************************************************************
  multiFileProject.ino
  AsyncUDP_ESP32_SC_ENC is a Async UDP library for the ESP32_SC_ENC (ESP32_S2/S3/C3 + ENC28J60)

  Based on and modified from ESPAsyncUDP Library (https://github.com/me-no-dev/ESPAsyncUDP)
  Built by Khoi Hoang https://github.com/khoih-prog/AsyncUDP_ESP32_SC_ENC
  Licensed under GPLv3 license
*****************************************************************************************************************************/

// To demo how to include files in multi-file Projects

#include "multiFileProject.h"

// Can be included as many times as necessary, without `Multiple Definitions` Linker Error
#include "AsyncUDP_ESP32_SC_ENC.h"

// Select the IP address according to your local network
IPAddress myIP(192, 168, 2, 232);
IPAddress myGW(192, 168, 2, 1);
IPAddress mySN(255, 255, 255, 0);

// Google DNS Server IP
IPAddress myDNS(8, 8, 8, 8);

void setup()
{
  Serial.begin(115200);

  while (!Serial && (millis() < 5000));

  delay(500);

  Serial.print(F("\nStart multiFileProject on "));
  Serial.print(ARDUINO_BOARD);
  Serial.print(F(" with "));
  Serial.println(SHIELD_TYPE);
  Serial.println(WEBSERVER_ESP32_SC_ENC_VERSION);
  Serial.println(ASYNC_UDP_ESP32_SC_ENC_VERSION);

  Serial.setDebugOutput(true);

  ESP32_SC_ENCWARN(F("Default SPI pinout:"));
  ESP32_SC_ENCWARN1(F("SPI_HOST:"), SPI_HOST);
  ESP32_SC_ENCWARN1(F("MOSI:"), MOSI_GPIO);
  ESP32_SC_ENCWARN1(F("MISO:"), MISO_GPIO);
  ESP32_SC_ENCWARN1(F("SCK:"),  SCK_GPIO);
  ESP32_SC_ENCWARN1(F("CS:"),   CS_GPIO);
  ESP32_SC_ENCWARN1(F("INT:"),  INT_GPIO);
  ESP32_SC_ENCWARN1(F("SPI Clock (MHz):"), SPI_CLOCK_MHZ);
  ESP32_SC_ENCWARN(F("========================="));

  ///////////////////////////////////

  // To be called before ETH.begin()
  ESP32_ENC_onEvent();

  //bool begin(int MISO_GPIO, int MOSI_GPIO, int SCLK_GPIO, int CS_GPIO, int INT_GPIO, int SPI_CLOCK_MHZ,
  //           int SPI_HOST, uint8_t *ENC28J60_Mac = ENC28J60_Default_Mac);
  ETH.begin( MISO_GPIO, MOSI_GPIO, SCK_GPIO, CS_GPIO, INT_GPIO, SPI_CLOCK_MHZ, SPI_HOST );

  // Static IP, leave without this line to get IP via DHCP
  //bool config(IPAddress local_ip, IPAddress gateway, IPAddress subnet, IPAddress dns1 = 0, IPAddress dns2 = 0);
  ETH.config(myIP, myGW, mySN, myDNS);

  ESP32_ENC_waitForConnect();

  ///////////////////////////////////

  Serial.print("You're OK now");
}

void loop()
{
  // put your main code here, to run repeatedly:
}
