#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char edged[SIZE][SIZE][RGB];

void loadImage() {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}


void saveImage() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, edged);
}

void EDGING()
{
    //1- convert greyscale to black and white
    for (int k = 0; k < RGB; k++)
    {
        for (int i = 1; i < SIZE - 1; i++)
        {
            for (int j = 1; j < SIZE - 1; j++)
            {
                //convert to black and white
                if (image[i][j][k] > 127)
                    image[i][j][k] = 255;
                else
                    image[i][j][k] = 0;
            }
        }
    }
    for (int k = 0; k < RGB; k++) {
        for (int i = 1; i < SIZE - 1; i += 1)
        {
            for (int j = 1; j < SIZE - 1; j += 1)
            {
                //2- check detection of current pixel against before/after pixels
                if (image[i][j][k] == image[i][j + 1][k] and image[i][j][k] == image[i][j - 1][k])
                    //set value to white
                    edged[i][j][k] = 255;
                else
                    //set value to black
                    edged[i][j][k] = 0;
            }
        }
    }
}
int main()
{
    loadImage();
    EDGING();
    saveImage();
    system("pause");
}