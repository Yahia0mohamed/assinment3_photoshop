#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;

unsigned char image[SIZE][SIZE][RGB];

void getimg(){
    char directory[100];
    cout<<"enter the image u want to invert:";
    cin>>directory;
    strcat(directory,".bmp");
    readRGBBMP(directory,image);
}

void invert(){
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; k++)
            {
                image[i][j][k]=255-image[i][j][k];
            }
            
        }
        
    }
    
}
void saveimg(){
    char directory[100];
    cout<<"enter what name do u want to save ur image with:";
    cin>>directory;
    strcat(directory,".bmp");
    writeRGBBMP(directory,image);
}

int main()
{
    bool flag=true;
    while (flag)
    {
        int op;
        cout<<"hello user here u can invert the photo what do u like to do"<<"\n";
        cout<<"to invert->1"<<"\n"<<"to exit->2"<<"\n"<<"enter ur choice:";
        cin>>op;
        switch (op)
        {
        case 1:
            cin.ignore();
            getimg();
            invert();
            saveimg();
            break;
        case 2:
            exit(0);
            break;
        default:
            main();
            break;
        }
    }
    
    return 0;
}