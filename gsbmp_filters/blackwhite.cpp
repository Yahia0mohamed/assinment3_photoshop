#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;

unsigned char image[SIZE][SIZE];

void getimg(){
    char directory[100];
    cout<<"enter the image u want to invert:";
    cin>>directory;
    strcat(directory,".bmp");
    readGSBMP(directory,image);
}

void darken_lighten(){
    int check;
    cout<<"do u want darken-->1 or lighten-->2:";
    cin>>check;
    switch (check)
    {
    case 1:{
        for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
        if (image[i][j]<=60){
        image[i][j]=image[i][j];
        }
        else{
        image[i][j]=image[i][j]-60;
            }
        }
    }
        break;
    }
        case 2:{
        for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
        if (image[i][j]>=195){
            image[i][j]=image[i][j];
        }
        else{
            image[i][j]=image[i][j]+60;
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

void saveimg(){
    char directory[100];
    cout<<"enter what name do u want to save ur image with:";
    cin>>directory;
    strcat(directory,".bmp");
    writeGSBMP(directory,image);
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