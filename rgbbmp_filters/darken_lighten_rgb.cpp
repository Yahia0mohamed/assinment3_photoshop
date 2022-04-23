#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;

unsigned char image[SIZE][SIZE][RGB];

void getimg(){
    char directory[100];
    cout<<"enter the image u want to darken\\lighten:";
    cin>>directory;
    strcat(directory,".bmp");
    readRGBBMP(directory,image);
}

void darken_lighten(){
    int check;
    cout<<"do u want darken-->1 or lighten-->2:";
    cin>>check;
    for (int k = 0; k < RGB; k++)
    {
        switch (check)
    {
    case 1:{
        for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
        if (image[i][j][k]<=70){
        image[i][j][k]=image[i][j][k];
        }
        else{
        image[i][j][k]=image[i][j][k]-40;
            }
        }
    }
        break;
    }
        case 2:{
        for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
        if (image[i][j][k]>=220){
            image[i][j][k]=image[i][j][k];
        }
        else{
            image[i][j][k]=image[i][j][k]+35;
            }
        }
    }
        break;
    }
    
    default:
        darken_lighten();
        break;
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
        cout<<"hello user here u can darken\\lighten the photo what do u like to do"<<"\n";
        cout<<"to darken\\lighten->1"<<"\n"<<"to exit->2"<<"\n"<<"enter ur choice:";
        cin>>op;
        switch (op)
        {
        case 1:
            cin.ignore();
            getimg();
            darken_lighten();
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