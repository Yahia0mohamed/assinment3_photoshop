#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;

unsigned char image1[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
unsigned char result[SIZE][SIZE][RGB];

void getimg1(){
    char directory[100];
    cout<<"enter the image u want to merge:";
    cin>>directory;
    strcat(directory,".bmp");
    readRGBBMP(directory,image1);
}
void getimg2(){
    char directory[100];
    cout<<"enter the image u want to merge:";
    cin>>directory;
    strcat(directory,".bmp");
    readRGBBMP(directory,image2);
}

void merge(){
    for (int k = 0; k < RGB; k++)
    {
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image1[i][j][k]= (image1 [i][j][k] + image2[i][j][k]) /2;
        }
    }
    }
    
}

void saveimg(){
    char directory[100];
    cout<<"enter what name do u want to save ur image with:";
    cin>>directory;
    strcat(directory,".bmp");
    writeRGBBMP(directory,image1);
}
int main()
{
    bool flag=true;
    while (flag)
    {
        int op;
        cout<<"hello user here u can merge the photo what do u like to do"<<"\n";
        cout<<"to invert->1"<<"\n"<<"to exit->2"<<"\n"<<"enter ur choice:";
        cin>>op;
        switch (op)
        {
        case 1:
            cin.ignore();
            getimg1();
            getimg2();
            merge();
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