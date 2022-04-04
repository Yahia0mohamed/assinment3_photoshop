#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;

int check =0;

unsigned char image[SIZE][SIZE];
unsigned char rotated_image[SIZE][SIZE];
unsigned char image270[SIZE][SIZE];

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
                rotated_image[j][i]=image[i][j];
            }
        }
        break;
    }
        
    case 180:{
        int row = 255;
        int column = 255;
        for (int i = 0; i < SIZE; ++i)
        {
        for (int j = 0; j < SIZE; ++j)
            {
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
void getimg(){
    char directory[100];
    cout<<"enter the image u want to rotate:";
    cin>>directory;
    strcat(directory,".bmp");
    readGSBMP(directory,image);
}
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