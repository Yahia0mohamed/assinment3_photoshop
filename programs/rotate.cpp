// FCI -Programming 1 - 2022 - Assignment 3
// Program name : invert filter
//Last Modification Date: 2/4/2022
//Author and ID and Group: yahia mohamed nabil,20210454,GroupA
//Teaching assistant: Eng Yousra Ayman
//Purpose: This application enables the user to rotate gray scale image in 90,180,270 orentation

// including the needed libraries
#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;

int check =0;

// array for the image and for the result
unsigned char image[SIZE][SIZE];
unsigned char rotated_image[SIZE][SIZE];

void rotate(){
    int choice;
    cout<<"please enter the orentation that you want:";
    cin>>choice;
    switch (choice)
    {
    case 90:{
        for (int i = 0; i < SIZE; ++i)
        {
        for (int j = 0; j < SIZE; ++j)
            {
                // we change [0][0] with [0][255] etc,
                rotated_image[j][i]=image[i][j];
            }
        }
        break;
    }
        
    case 180:{
        // row variable
        int row = 255;
        // column variable
        int column = 255;
        for (int i = 0; i < SIZE; ++i)
        {
        for (int j = 0; j < SIZE; ++j)
            {
                // we change [0][0] with [255][255] etc,
                rotated_image[row][column]=image[i][j];
                column-=1;
                if (column==0){
                    row-=1;
                }
            }
        }
        break;
    }
    case 270:{
        // we combine the first two methods to achive this one
        for (int i = 0; i < SIZE; ++i)
        {
        for (int j = 0; j < SIZE; ++j)
            {
                rotated_image[j][i]=image[i][j];
            }
        }
        check+=1;
        if (check==1){
            int row = 255;
        int column = 255;
        for (int i = 0; i < SIZE; ++i)
        {
        for (int j = 0; j < SIZE; ++j)
            {
                image270[row][column]=rotated_image[i][j];
                column-=1;
                if (column==0){
                    row-=1;
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
// getting image
void getimg(){
    char directory[100];
    cout<<"enter the image u want to rotate:";
    cin>>directory;
    strcat(directory,".bmp");
    readGSBMP(directory,image);
}
// saving image
void saveimg(){
    char directory[100];
    cout<<"enter what name do u want to save ur image with:";
    cin>>directory;
    strcat(directory,".bmp");
    if (check==1)
    {
        writeGSBMP(directory,image270);
    }
    else{
        writeGSBMP(directory,rotated_image);
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
