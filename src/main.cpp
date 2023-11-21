#include <Arduino.h>
#include <TelnetStream.h>

#include "wifi_ruts.h"
#include "mqtt.h"
#include "hw.h"
#include "push.h"
#include "button.h"  // Include the button class header

int board;
Button penicilinButton;  // Create an instance for the PENICILIN button
Button tafirolButton;   // Create an instance for the TAFIROL button


void setup(void)
{
    Serial.begin(BAUD);

    // Connect to Wi-Fi
    connect_wifi(); // Implement this function to connect to Wi-Fi. 
    Serial.println("Connected to the wifi");

    init_hw();
    board = get_board_num();
    Serial.print("Board = ");
    Serial.println(board);
    TelnetStream.begin();

    Serial.println("Telnet Stream Begun.");
    Serial.println("Setup succesful.");

    penicilinButton.begin(PENICILIN_BUTTON);
    tafirolButton.begin(TAFIROL_BUTTON);
}

void loop(void)
{
    if (push_done(PENICILIN)) {

        do_publish("Penicilin", "buying");
        // Buy and do stuff
    }
    if (push_done(TAFIROL)) {

        do_publish("Tafiol", "buying");
        // Buy and do stuff
    }

    test_mqtt();
}
