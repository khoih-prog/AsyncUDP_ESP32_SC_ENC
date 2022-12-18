/****************************************************************************************************************************
  multiFileProject.h
  AsyncUDP_ESP32_SC_ENC is a Async UDP library for the ESP32_SC_ENC (ESP32_S2/S3/C3 + ENC28J60)

  Based on and modified from ESPAsyncUDP Library (https://github.com/me-no-dev/ESPAsyncUDP)
  Built by Khoi Hoang https://github.com/khoih-prog/AsyncUDP_ESP32_SC_ENC
  Licensed under GPLv3 license
*****************************************************************************************************************************/

// To demo how to include files in multi-file Projects

#pragma once

#if !( defined(ESP32) )
  #error This code is designed for (ESP32_S2/S3/C3 + LwIP ENC28J60) to run on ESP32 platform! Please check your Tools->Board setting.
#endif

#include <Arduino.h>

#define ASYNC_UDP_ESP32_SC_ENC_DEBUG_PORT      Serial

// Use from 0 to 4. Higher number, more debugging messages and memory usage.
#define _ASYNC_UDP_ESP32_SC_ENC_LOGLEVEL_      2

//////////////////////////////////////////////////////////

// Optional values to override default settings
//#define SPI_HOST            SPI2_HOST
//#define SPI_CLOCK_MHZ       8

// Must connect INT to GPIOxx or not working
//#define INT_GPIO            4

//#define MISO_GPIO           13
//#define MOSI_GPIO           11
//#define SCK_GPIO            12
//#define CS_GPIO             10

//////////////////////////////////////////////////////////

// Can be included as many times as necessary, without `Multiple Definitions` Linker Error
#include "AsyncUDP_ESP32_SC_ENC.hpp"
