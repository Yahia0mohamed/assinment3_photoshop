#include <iostream>
#include <cstring>
#include"bmplib.cpp"
using namespace std;


// intiliazing Unsigned char for the image and char to save the new filtered image
unsigned char Image[SIZE][SIZE];
char filteredImage[SIZE][SIZE];


//recieving image from the user
void loadImage()
{
    // intiliazing char to recieve file name from the user 
    char fileName[100];
    cout << "Enter the source image file name: ";
    cin >> fileName;
    //converting file taken from the user to bmp
    strcat(fileName, ".bmp");
    //reading file taken from the user 
    readGSBMP(fileName, Image);
}
//Filter no (4) Flipping Filter
void applyFlippingFilter()
{
    char choice;
    // getting the user choice input to flip the image horizontally or vertically
    cout << "Press (h) to flip horizontally , (v) to flip vertically " << endl;
    cin >> choice;
    if (choice == 'v')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (i < SIZE)
                {
                    filteredImage[i][j] = Image[i - 255][j - 255];
                }
            }
        }
    }
    else if (choice == 'h')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (j < SIZE)
                {
                    filteredImage[j][i] = Image[j][255 - i];
                }
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            Image[i][j] = filteredImage[i][j];
        }
    }
}


//saving the new filtered image 
void saveImage()
{
    //receiving the new filtered image file name from the user
    char imageFileName[100];
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, Image);
}

int main()
{
    while (true)
    {
        loadImage();
        cout << "4-Flip Image \n0-To End " << endl;
        string x;
        while (true)
        {
            cout << "Enter your choice please " << endl;
            cin.ignore();
            cin >> x;
             if (x == "4")
            {
                applyFlippingFilter();
                saveImage();
            }
            else if (x == "0")
            {
                cout << "Exit" << endl;
                break;
            }
        }
        break;
    }
    system("pause");
}