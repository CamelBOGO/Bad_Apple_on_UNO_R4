#include <SoftwareSerial.h>  // SoftwareSerial library

#include "Arduino_LED_Matrix.h"  // LED_Matrix library
#include "DFPlayerMini_Fast.h"   // DFPlayerMini_Fast library
#include "badapple.h"            // Raw data of the Bad Apple video

// Create an instance of the SoftwareSerial and DFPlayerMini_Fast class.
SoftwareSerial softSerial(/*rx =*/10, /*tx =*/11);
// #define FPSerial softSerial
DFPlayerMini_Fast myDFPlayer;

// Video frame rate = 30fps.
uint32_t period = 33333;  // us
uint32_t lastTime = 0;    // us

// Create an instance of the ArduinoLEDMatrix class
ArduinoLEDMatrix matrix;

void setup() {
    // Initialize the LED matrix.
    matrix.begin();
    // Initialize the software serial port.
    softSerial.begin(9600);

    // Serial.begin(115200);

    // Use serial to communicate with mp3.
    Serial.println();
    if (!myDFPlayer.begin(softSerial, true)) {
        // Serial.println(F("DFPlayer ERROR."));
    }
    // Serial.println(F("DFPlayer OK."));

    // Initial settings of the DFPlayer Mini.
    myDFPlayer.volume(22);  // Set volume value. From 0 to 30
    myDFPlayer.play(3);     // Play the third mp3
}

void loop() {
    static int frameCounter = 0;
    byte frame[8][12] = {0};
    uint16_t wordDatas[8] = {0};

    // Handle the frame display at a fixed rate.
    if (micros() - lastTime > period) {
        lastTime = micros();

        // Get the frame data from the program memory, store it in the wordDatas
        for (byte j = 0; j < 8; j++) {
            wordDatas[j] = pgm_read_word_near(&badapple[frameCounter][j]);
        }

        // Convert the wordDatas to the frame data, which is preferred by the renderBitmap() function.
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 12; x++) {
                frame[y][x] = (wordDatas[y] >> (11 - x)) & 0x01;
            }
        }

        // Render the frame data to the LED matrix.
        matrix.renderBitmap(frame, 8, 12);

        // Frame counter + 1. If the frame counter is greater than the last frame, reset it to 0 and replay song.
        if (++frameCounter >= 6569) {
            frameCounter = 0;
            myDFPlayer.play(3);
        }
    }
}
