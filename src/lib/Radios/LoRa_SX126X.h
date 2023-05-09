#pragma once

#include "RadioManager.h"
#include <RadioLib.h>
#ifdef LORA_FAMILY_SX126X
#define FREQUENCY 915.0 // MHz
#define BANDWIDTH 500 // kHz
#define SPREADING_FACTOR 7 // SF6 5-12
#define CODING_RATE 1 // 1-4 -> CR 4/5,4/6,4/7,4/8
#define SYNC_WORD 0x17 // Arbitrarily chosen
#define PREAMBLE_LENGTH 8 // symbols
#define LNA_GAIN 0 // Automatic gain

#define RECEIVE_TIMEOUT LORA_M3_SLOT_SPACING * LORA_M3_NODES - 1
#endif
class LoRa_SX126X : public Radio
{
public:
    LoRa_SX126X();
    static LoRa_SX127X *getSingleton();

    int begin();
    void transmit(air_type0_t *air_0, uint8_t ota_nonce);
    void receive();
    void flagPacketReceived();
    void loop();
    String getStatusString();
    String getCounterString();
private:
    SX1276* radio = nullptr;
    volatile bool packetReceived = false;
};
