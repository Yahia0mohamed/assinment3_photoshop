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
    writeRGBBMP(imageFileName, image);
}
void Mirror()
{
    char choice1, choice2;

    cout << "Choose whether you want to mirror the image horizontally (h) or vertically (v)" << endl;
    cin >> choice1;
    if (choice1 == 'v') {
        cout << "Choose either the left part (l) or the right part (r)" << endl;
        cin >> choice2;
        if (choice2 == 'l') {
            for (int k = 0; k < RGB; k++) {
                for (int i = 0; i < SIZE; i++) {
                    // half size of vertical mirror
                    for (int j = 0; j < SIZE / 2; j++) {
                        int temp = image[i][j][k];
                        //check if first half
                        if (j < SIZE / 2)
                            image[i][SIZE - j][k] = temp;
                        else
                            image[i][j][k] = image[i][SIZE - j][k];

                    }
                }
            }
        }
        if (choice2 == 'r')
        {
            for (int k = 0; k < RGB; k++)
            {
                for (int i = 0; i < SIZE; i++)
                {
                    // half size of vertical mirror
                    for (int j = 0; j < SIZE / 2; j++)
                    {
                        int temp = image[i][j][k];
                        // check if second half
                        if (j > SIZE / 2)
                            image[i][SIZE - j][k] = temp;
                        else
                            image[i][j][k] = image[i][SIZE - j][k];

                    }
                }
            }

        }
    }
    if (choice1 == 'h') {
        cout << "Choose either the upper part (u) or the lower part (l)" << endl;
        cin >> choice2;
        if (choice2 == 'u') {
            // half size of horizontal mirror
            for (int k = 0; k < RGB; k++) {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        int temp = image[i][j][k];
                        // check if first half
                        if (i < SIZE / 2)
                            image[SIZE - i][j][k] = temp;
                        else
                            image[i][j][k] = image[SIZE - i][j][k];
                    }
                }
            }
        }
        if (choice2 == 'l') {
            // half size of horizontal mirror
            for (int k = 0; k < RGB; k++)
            {
                for (int i = 0; i < SIZE / 2; i++)
                {
                    for (int j = 0; j < SIZE; j++)
                    {
                        int temp = image[i][j][k];
                        // check if second half
                        if (i > SIZE / 2)
                            image[SIZE - i][j][k] = temp;
                        else
                            image[i][j][k] = image[SIZE - i][j][k];
                    }
                }
            }

        }
    }
}
int main()
{
    loadImage();
    Mirror();
    saveImage();
    system("pause");
}