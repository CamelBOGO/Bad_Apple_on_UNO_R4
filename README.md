<h1 align="center">Bad Apple on UNO R4</h1>

<p align="center">Can Arduino UNO R4 play Bad Apple?</p>
<p align="center">According to <a href="https://www.urbandictionary.com/define.php?term=Rule%2086"><strong>Rule 86</strong></a>:</p>

```
If it exists, you can play Bad Apple on it.
```

<p align="center">the answer is <strong>YES</strong>.</p>

## 🧐 About the Project

One year ago, BOGO has sucessfully played Bad Apple on an Arduino UNO R3 using an 8x8 LED matrix. Now, with the recent release of the Arduino UNO R4, which features a built-in 12x8 LED matrix, we have an exciting opportunity to take playing animation on LED matrix to the next level. So why not we also play Bad Apple on it?

### Demo

YouTube: [Link](https://youtu.be/vlPAYCViuuo "Bad Apple on Arduino UNO R4")

## 🏁 Getting Started

Before you embark on the exciting journey of playing Bad Apple on your Arduino UNO R4, make sure you have the necessary hardware components ready:

-   Arduino UNO R4 WiFi
-   DFPlayer Mini
-   Micro SD card
-   Speaker
-   Breadboard
-   Computer with Arduino IDE installed
-   USB cable for code uploading
-   Jumper wires (a few of them)

The code can be compiled and uploaded to Arduino UNO R4 directly by using Arduino IDE. If you're feeling adventurous and want to explore further possibilities, refer to the "Play My Own Video" section below to learn how you can customize and play your own videos. Get ready to unleash the full potential of your Arduino UNO R4 and immerse yourself in the captivating world of Bad Apple!

### Connections

Please connect the hardware as the following diagram:

(Diagram 1)

### Prepare the Micro SD Card

1. Format the Micro SD card to FAT32 format.
2. Download the Bad Apple MP3 and rename it to "3_BadApple.mp3".
3. Put "3_BadApple.mp3" in the root directory of the Micro SD card.
4. Insert the Micro SD card into the DFPlayer Mini.

### Defferent of 2 Folders

There are 2 Arduino project folders: "badapple_on_uno_r4" and "badapple_on_uno_r4_12bit_data". For general users, please use the "badapple_on_uno_r4". "badapple_on_uno_r4_12bit_data" stores the data of the video by using uint16_t array, and each element contains 12 bits of data, which is a row of the data of a single frame. However, this method wastes 4 bits of data for each element, so it is not recommended.

### Dependencies

To compile the code, you should install the following libraries in Arduino IDE:

Boards:

-   **Arduino UNO R4 Boards** by Arduino

Libraries:

-   **DFPlayerMini_Fast** by PowerBroker2

### Uploading Code

After connecting the UNO R4 to your computer, select the correct board and port in Arduino IDE, then click "Upload" button to upload the code to your UNO R4. When finished, Bad Apple will be played on your UNO R4.

## 🎥 Play My Own Video

If you want to convert your own Bad Apple or even other video to the format that this project can play, you can follow the steps below:

(More details will be added later)

## 🆘 How to Get Help

No support provided currently.

## 📃 License

This project is licensed under the MIT License - see [LICENSE.md](LICENSE.md) file for details. Feel free to fork and modify the code.

## ✍️ Authors

-   **[BOGO](https://youtu.be/dQw4w9WgXcQ)**

## 🎉 Acknowledgments

The people who created Bad Apple.
