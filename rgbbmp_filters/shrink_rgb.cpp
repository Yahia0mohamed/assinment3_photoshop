#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;

unsigned char image[SIZE][SIZE][RGB];
unsigned char newimage[SIZE][SIZE][RGB];

void getimg(){
    char directory[100];
    cout<<"enter the image u want to shrink:";
    cin>>directory;
    strcat(directory,".bmp");
    readRGBBMP(directory,newimage);
}

void shrink(){
    int choice;
    cout<<"for 1/4 ->1\nfor 1/3 ->2\nfor 1/2 ->3\nenter:" ;
    cin>>choice;
    for (int k = 0; k < RGB; k++)
    {
        if (choice==1){
        for (int i = 0; i < SIZE ; i+=2)
        {
            for (int j = 0; j < SIZE; j+=2)
            {
                image[i/2][j/2][k]=newimage[i][j][k];
            }
            
        }
        
    }else if (choice == 2)
    {
        for (int i = 0; i < SIZE; i+=3)
        { for (int j = 0; j < SIZE; j+=3)
        {
            image[i/3][j/3][k] = newimage[i][j][k];
        }
        }
    }else if (choice == 3)
    {
        for (int i = 0; i < SIZE; i+=4)
        { for (int j = 0; j < SIZE; j+=4)
        {
            image[i/ 4][j/4][k] = newimage[i][j][k];
        }
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

int main (){
    bool flag=true;
    while (flag)
    {
        int op;
        cout<<"hello user here u can shrink the photo what do u like to do"<<"\n";
        cout<<"to shrink->1"<<"\n"<<"to exit->2"<<"\n"<<"enter ur choice:";
        cin>>op;
        switch (op)
        {
        case 1:
            cin.ignore();
            getimg();
            shrink();
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