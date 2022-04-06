// FCI -Programming 1 - 2022 - Assignment 3
// Program name : invert filter
//Last Modification Date: /4/2022
//Author and ID and Group: yahia mohamed nabil,20210454,GroupA
//Teaching assistant: Eng Yousra Ayman
//Purpose: This application enables the user to convert gray scale image to a negative version of it

// including the nessesary libraries
#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;
// array to store pixels of the image
unsigned char image[SIZE][SIZE];

// getting the image from the user
void getimg(){
    char directory[100];
    cout<<"enter the image u want to invert:";
    cin>>directory;
    strcat(directory,".bmp");
    readGSBMP(directory,image);
}

// the invert function
void invert(){
    // looping over the array    
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            // check the pixel color (brightness)            
            int pixel = image[i][j];
            if (pixel>0 && pixel<255){
                // if between the black and white we invert the brightness
                image[i][j]=255-pixel;
            }
            else if (pixel==255)
            {
                // if white invert black
                image[i][j]=0;
            }
            else if(pixel==0){
                //if black invert white
                image[i][j]=255+pixel;
            }
        }
        
    }
    
}
// savvin image
void saveimg(){
    char directory[100];
    cout<<"enter what name do u want to save ur image with:";
    cin>>directory;
    strcat(directory,".bmp");
    writeGSBMP(directory,image);
}
// main function
int main()
{
    //  boolien for starting the infinte loop of the program   
    bool flag=true;
    while (flag)
    {
        int op;
        cout<<"hello user here u can invert the photo what do u like to do"<<"\n";
        cout<<"to invert->1"<<"\n"<<"to exit->2"<<"\n"<<"enter ur choice:";
        cin>>op;
        // switch case for the operations
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


