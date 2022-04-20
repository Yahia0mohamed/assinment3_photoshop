#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;

unsigned char image[SIZE][SIZE];
unsigned char newimage[SIZE][SIZE];

void getimg(){
    char directory[100];
    cout<<"enter the image u want to enlarge:";
    cin>>directory;
    strcat(directory,".bmp");
    readGSBMP(directory,newimage);
}

void enlarge(){
    int quarter;
    cout<<"please enter the quarter u want to enlarge:";
    cin>>quarter;
    for (int i = 0; i < SIZE; i+=2){
        for (int j =0; j<SIZE;j+=2){
            if (quarter==1){
                image[i][j]=newimage[i/2][j/2];
                image[i][j+1]=newimage[i/2][j/2];
                image[i+1][j]=newimage[i/2][j/2];
                image[i+1][j+1]=newimage[i/2][j/2];
            }else if (quarter==2){
                image[i][j]=newimage[i/2][(j+SIZE)/2];
                image[i][j+1]=newimage[i/2][(j+SIZE)/2];
                image[i+1][j]=newimage[i/2][(j+SIZE)/2];
                image[i+1][j+1]=newimage[i/2][(j+SIZE)/2];
            }else if (quarter==3){
                image[i][j]=newimage[(i+SIZE)/2][j/2];
                image[i][j+1]=newimage[(i+SIZE)/2][j/2];
                image[i+1][j]=newimage[(i+SIZE)/2][j/2];
                image[i+1][j+1]=newimage[(i+SIZE)/2][j/2];
            }else if (quarter==4){
                image[i][j]=newimage[(i+SIZE)/2][(j+SIZE)/2];
                image[i][j+1]=newimage[(i+SIZE)/2][(j+SIZE)/2];
                image[i+1][j]=newimage[(i+SIZE)/2][(j+SIZE)/2];
                image[i+1][j+1]=newimage[(i+SIZE)/2][(j+SIZE)/2];
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

int main()
{
    bool flag=true;
    while (flag)
    {
        int op;
        cout<<"hello user here u ca enlarge the photo what do u like to do"<<"\n";
        cout<<"to enlarge->1"<<"\n"<<"to exit->2"<<"\n"<<"enter ur choice:";
        cin>>op;
        switch (op)
        {
        case 1:
            cin.ignore();
            getimg();
            enlarge();
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
