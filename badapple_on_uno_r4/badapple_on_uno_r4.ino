#include <SoftwareSerial.h>  // SoftwareSerial library

#include "Arduino_LED_Matrix.h"  // LED_Matrix library
#include "DFPlayerMini_Fast.h"   // DFPlayerMini_Fast library
#include "badapple.h"            // Raw data of the Bad Apple video

// Create an instance of the ArduinoLEDMatrix class
ArduinoLEDMatrix matrix;

// Create an instance of the SoftwareSerial and DFPlayerMini_Fast class.
SoftwareSerial softSerial(/*rx =*/10, /*tx =*/11);
DFPlayerMini_Fast myDFPlayer;

// Video frame rate = 30fps.
uint32_t period = 33333;  // us
uint32_t lastTime = 0;    // us

void setup() {
    // Initialize the LED matrix.
    matrix.begin();
    // Initialize the software serial port.
    softSerial.begin(9600);

    // Initialize the serial port for debugging.
    // Serial.begin(115200);

    // Use serial to communicate with mp3.
    if (!myDFPlayer.begin(softSerial, true)) {
        // Serial.println(F("DFPlayer ERROR."));
    }
    // Serial.println(F("DFPlayer OK."));

    // Initial settings of the DFPlayer Mini.
    myDFPlayer.volume(20);  // Set volume value. From 0 to 30
    myDFPlayer.play(3);     // Play the third mp3
}

void loop() {
    static int frameCounter = 0;
    uint32_t frameData[3] = {0};

    // Handle the frame display at a fixed rate.
    if (micros() - lastTime > period) {
        lastTime = micros();

        // Get the frame data from the program memory, store it in the wordDatas
        for (byte i = 0; i < 3; i++) {
            frameData[i] = pgm_read_dword_near(&badapple[frameCounter][i]);
        }

        // Render the frame data to the LED matrix.
        matrix.loadFrame(frameData);

        // Frame counter + 1. If the frame counter is greater than the last frame, reset it to 0 and replay song.
        if (++frameCounter >= 6569) {
            frameCounter = 0;
            myDFPlayer.play(3);
        }
    }
}
