#include <Arduino.h>
#include <TelnetStream.h>

#include "wifi_ruts.h"
#include "mqtt.h"
#include "hw.h"
#include "push.h"
#include "button.h"  // Include the button class header
extern void client_connect(void);

int board;
Button ibuprofenButton;  
Button diphemhydramineButton;   
Button paracetamolButton;
Button aspirinButton;
Button creditButton;
Button restockButton;




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
    init_mqtt(board);
    Serial.println("MQTT succesfully initialized");
    TelnetStream.begin();

    Serial.println("Telnet Stream Begun.");
    Serial.println("Setup succesful.");

    ibuprofenButton.begin(IBUPROFEN_BUTTON);
    diphemhydramineButton.begin(DIPHEMHYDRAMINE_BUTTON);
    paracetamolButton.begin(PARACETAMOL_BUTTON);
    aspirinButton.begin(ASPIRIN_BUTTON);
    creditButton.begin(CREDIT_BUTTON);
    restockButton.begin(RESTOCK_BUTTON);
    
}

void loop(void)
{
    if (push_done(IBUPROFEN)) {

        do_publish("vending-machine", "{\"product\": \"Ibuprofen\"}");
        // Buy and do stuff
    }
    if (push_done(DIPHEMHYDRAMINE)) {

        do_publish("vending-machine", "{\"product\": \"Diphemhydramine\"}");
        // Buy and do stuff
    }
    if (push_done(PARACETAMOL)) {

        do_publish("vending-machine", "{\"product\": \"Paracetamol\"}");
        // Buy and do stuff
    }
    if (push_done(ASPIRIN)) {

        do_publish("vending-machine", "{\"product\": \"Pepto Bismol\"}");
        // Buy and do stuff
    }
    if (push_done(CREDIT)) {

        do_publish("vending-machine-credit", "");
        // Buy and do stuff
    }
    if (push_done(RESTOCK)) {

        do_publish("vending-machine-restock", "");
        // Buy and do stuff
    }
    test_mqtt();
}
