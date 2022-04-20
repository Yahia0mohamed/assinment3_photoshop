#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;

unsigned char image1[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char result[SIZE][SIZE];

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
            saveimg1();
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