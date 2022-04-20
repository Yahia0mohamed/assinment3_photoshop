#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;

int check =0;

unsigned char image[SIZE][SIZE][RGB];
unsigned char rotated_image[SIZE][SIZE][RGB];
unsigned char image270[SIZE][SIZE][RGB];


void rotate(){
    int choice;
    cout<<"please enter the orentation that you want:";
    cin>>choice;
    switch (choice)
    {
    case 90:{
        for (int k = 0; k < RGB; ++k)
        {
        for (int i = 0; i < SIZE; ++i)
            {
                for (int j = 0; j < SIZE; ++j)
                {
                    image[j][i][k]=rotated_image[i][j][k];
                }
                
            }
        }
        break;
    }
        
    case 180:{
        for (int k=0; k<RGB; k++){
            int row = 255;
            int column = 255;
            for (int i = 0; i < SIZE; ++i)
            {
            for (int j = 0; j < SIZE; ++j)
            {
                rotated_image[row][column][k]=image[i][j][k];
                column-=1;
                if (column==0){
                    row-=1;
                }
            }
        }
        }
        break;
    }
    case 270:{
        check+=1;
        for (int k =0 ; k<RGB; k++){
            for (int i = 0; i < SIZE; ++i)
        {
        for (int j = 0; j < SIZE; ++j)
            {
                rotated_image[j][i][k]=image[i][j][k];
            }
        }
        if (check==1){
            int row = 255;
            int column = 255;
        for (int i = 0; i < SIZE; ++i)
        {
        for (int j = 0; j < SIZE; ++j)
            {
                image270[row][column][k]=rotated_image[i][j][k];
                column-=1;
                if (column==0){
                    row-=1;
                }
            }
        }
        }
        }
        break;
    }
    default:{
        cout<<"wrong orenintation\n";
        rotate();
        break;
    }
    }
    
}
void getimg(){
    char directory[100];
    cout<<"enter the image u want to rotate:";
    cin>>directory;
    strcat(directory,".bmp");
    readRGBBMP(directory,image);
    // readRGBBMP(directory,rotated_image);
}
void saveimg(){
    char directory[100];
    cout<<"enter what name do u want to save ur image with:";
    cin>>directory;
    strcat(directory,".bmp");
    if (check==0){
        writeRGBBMP(directory,rotated_image);
    }else if (check==1){
        writeRGBBMP(directory,image270);
    }
}

int main()
{
    bool flag=true;
    while (flag)
    {
        int op;
        cout<<"hello user here u can rotate the photo what do u like to do"<<"\n";
        cout<<"to rotate->1"<<"\n"<<"to exit->2"<<"\n"<<"enter ur choice:";
        cin>>op;
        switch (op)
        {
        case 1:
            cin.ignore();
            getimg();
            rotate();
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