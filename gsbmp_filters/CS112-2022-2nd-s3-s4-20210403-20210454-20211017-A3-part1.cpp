#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;
int check =0;

unsigned char image[SIZE][SIZE];
unsigned char image1[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char result[SIZE][SIZE];
char filteredImage[SIZE][SIZE];
unsigned char rotated_image[SIZE][SIZE];
unsigned char image270[SIZE][SIZE];

// merge filter
void getimg1(){
    char directory[100];
    cout<<"enter the image u want to merge:";
    cin>>directory;
    strcat(directory,".bmp");
    readGSBMP(directory,image1);
}
void getimg2(){
    char directory[100];
    cout<<"enter the image u want to merge:";
    cin>>directory;
    strcat(directory,".bmp");
    readGSBMP(directory,image2);
}

void merge(){
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        result [i][j]= (image1 [i][j] + image2[i][j]) /2;
        }
    }
}

void saveimg1(){
    char directory[100];
    cout<<"enter what name do u want to save ur image with:";
    cin>>directory;
    strcat(directory,".bmp");
    writeGSBMP(directory,result);
}



// black and white fillter and 
void loadImage()
{
    // intiliazing char to recieve file name from the user 
    char fileName[100];
    cout << "Enter the source image file name: ";
    cin >> fileName;
    //converting file taken from the user to bmp
    strcat(fileName, ".bmp");
    //reading file taken from the user 
    readGSBMP(fileName, image);
}


//Filter no (1) Black and white filter
void applyBinaryFilter()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            //scaling up every bit more than 127 to 255(white)
            if (image[i][j] > 127)
            {
                image[i][j] = 255;
            }
            else
            {
                //scalling down every bit less than 127 to 0(black)
                image[i][j] = 0;
            }
        }
    }
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
                    filteredImage[i][j] = image[i - 255][j - 255];
                }
            }
        }
    }
    else if (choice == 'h')
    {
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
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = filteredImage[i][j];
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
    writeGSBMP(imageFileName, image);
}

void getimg(){
    char directory[100];
    cout<<"enter the image u want to invert:";
    cin>>directory;
    strcat(directory,".bmp");
    readGSBMP(directory,image);
}

void invert(){
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            int pixel = image[i][j];
            if (pixel>0 && pixel<255){
                image[i][j]=255-pixel;
            }
            else if (pixel==255)
            {
                image[i][j]=0;
            }
            else if(pixel==0){
                image[i][j]=255+pixel;
            }
        }
        
    }
    
}
void saveimg(){
    char directory[100];
    cout<<"enter what name do u want to save ur image with:";
    cin>>directory;
    strcat(directory,".bmp");
    writeGSBMP(directory,image);
}

// rotate filter

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
void saveimg2(){
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

// darken/lighten filter

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

// main function
int main()
{
    int num;
    cout<<"Enter the number of the required cipher"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"black and white image filter                           1"<<endl;
    cout<<"invert image filter                                    2"<<endl;
    cout<<"merge image filter                                     3"<<endl;
    cout<<"flip image filter                                      4"<<endl;
    cout<<"rotate image filter                                    5"<<endl;
    cout<<"darken and lighten filter                              6"<<endl;
    cout<<"exit                                                   7"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"Enter the Number:";
    cin>>num;
    cin.ignore();
    switch (num)
    {
    case 1:
        loadImage();
        applyBinaryFilter();
        saveImage();
        break;
    case 2:
        getimg();
        invert();
        saveimg();
        break;
    case 3:
        getimg1();
        getimg2();
        merge();
        saveimg1();
        break;
    case 4:
        loadImage();
        applyFlippingFilter();
        saveImage();
        break;
    case 5:
        getimg();
        rotate();
        saveimg();
        break;
    case 6:
        getimg();
        darken_lighten();
        saveimg();
        break;
    case 7:
        system("pause");
        break;
    default:
        cout<<"choose a right choice"<<endl;
        main();
        break;
    }
    return 0;
}
