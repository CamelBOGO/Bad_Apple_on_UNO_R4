import os
from pathlib import Path
from PIL import Image

ASCII_BITS = "0", "1"

# Delete output.txt if it is existed.
if os.path.exists("output.txt"):
    os.remove("output.txt")

# Get a list of all the files in the "images" folder
files = os.listdir(os.getcwd() + "\\images")
# Filter out the ones that start with "badapple" and end with ".png"
images = [file for file in files if file.startswith("badapple") and file.endswith(".png")]
# Get the number of such files
num_images = len(images)

for i in range(1, num_images + 1):
    imageStr = os.getcwd() + "\\images\\badapple" + str(i) + ".png"
    image = Path(imageStr)

    img = Image.open(image).convert("1")  # Convert image to bitmap.
    width, height = img.size
    # Convert image data to a list of ASCII bits.
    data = [ASCII_BITS[bool(val)] for val in img.getdata()]
    # Convert that to 2D list (list of character lists)
    data = [data[offset: offset + width] for offset in range(0, width * height, width)]

    # Write the data to output.txt. Format: {0b000000000000, ...},
    # with open("output.txt", "a") as file:
    #     file.write("{")
    #     for row in data:
    #         file.write(f"0b{''.join(row)}, ")
    #     file.write("},\n")
    # print(f"{i} converted.")

    # Write the data to output.txt. Format: {0b00000000000000000000000000000000, ...},
    with open("output.txt", "a") as file:
        file.write("{")
        # Combine 8 12-bit data to 1 96-bit data, and store it in bitData as string.
        bitData = ""
        for row in data:
            bitData = bitData + "".join(row)
        # Split the 96-bit data into 3 32-bit chunks.
        file.write(f"0b{bitData[:32]}, 0b{bitData[32:64]}, 0b{bitData[64:]}")
        file.write("},\n")
    print(f"{i} converted.")

print("Finished.")
