#include <iostream>
#include <cstring>
#include"bmplib.cpp"

using namespace std;
unsigned char Image[SIZE][SIZE];
char filteredImage[SIZE][SIZE];

void loadImage()
{
    char fileName[100];
    cout << "Enter the source image file name: ";
    cin >> fileName;
    strcat(fileName, ".bmp");
    readGSBMP(fileName, Image);
}
void applyInvertingFilter()
{
    char choice;
    cout << "Press (h) to flip horizontally , (v) to flip vertically " << endl;
    cin >> choice;
    if (choice == 'h')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                    filteredImage[i][j] = Image[SIZE-i][SIZE-j];
            }
        }
    }
    else if (choice == 'v')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                    filteredImage[j][i]=Image[j][SIZE-i] ;

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
void saveImage()
{
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
        cout << "1-Black and White Image\n4-Flip Image \n0-To End " << endl;
        string x;
        while (true)
        {
            cout << "Enter your choice please " << endl;
            cin.ignore();
            cin >> x;
            if (x == "1")
            {
                applyBinaryFilter();
                saveImage();
            }
            else if (x == "4")
            {
                applyInvertingFilter();
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
