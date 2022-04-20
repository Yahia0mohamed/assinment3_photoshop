#include<string>
#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;

unsigned char image[SIZE][SIZE][RGB];
unsigned char newimage[SIZE][SIZE][RGB];

void getimg(){
    char directory[100];
    cout<<"enter the image u want to shuffle:";
    cin>>directory;
    strcat(directory,".bmp");
    readRGBBMP(directory,image);
    readRGBBMP(directory,newimage);
}



void shuffle(){
    string order;
    cout<<"enter the order";
    cin>>order;
    int length = order.length();
    for (int k = 0; k < RGB; k++)
    {
        int index =0;
    while (index<4){
        if (index==0){
            if (order[index]=='1'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    image[i][j][k]=newimage[i][j][k];
                }
            }
            
        }else if (order[index]=='2'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    image[i][j][k]=newimage[i][j+SIZE/2][k];
                }
            }
        }else if (order[index]=='3'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    image[i][j][k]=newimage[i+SIZE/2][j][k];
                }
                
            }
        }else if (order[index]=='4'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    image[i][j][k]=newimage[i+SIZE/2][j+SIZE/2][k];
                }
                
            }
        }
    }
    // --------------------
        else if (index ==1){
            if (order[index]=='1'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    image[i][j+SIZE/2][k]=newimage[i][j][k];
                }
                
            }
            
        }else if (order[index]=='2'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    image[i][j+SIZE/2][k]=newimage[i][j+SIZE/2][k];
                }
                
            }
        }else if (order[index]=='3'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    image[i][j+SIZE/2][k]=newimage[i+SIZE/2][j][k];
                }
                
            }
        }else if (order[index]=='4'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    image[i][j+SIZE/2][k]=newimage[i+SIZE/2][j+SIZE/2][k];
                }
                
            }
        }
    }
    // -------------
    else if (index==2){
        if (order[index]=='1'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    image[i+SIZE/2][j][k]=newimage[i][j][k];
                }
                
            }
            
        }else if (order[index]=='2'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    image[i+SIZE/2][j][k]=newimage[i][j+SIZE/2][k];
                }
                
            }
        }else if (order[index]=='3'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    image[i+SIZE/2][j][k]=newimage[i+SIZE/2][j][k];
                }
                
            }
        }else if (order[index]=='4'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    image[i+SIZE/2][j][k]=newimage[i+SIZE/2][j+SIZE/2][k];
                }
                
            }
    }
    }// ---------
    else if (index ==3){
        if (order[index]=='1'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    image[i+SIZE/2][j+SIZE/2][k]=newimage[i][j][k];
                }
                
            }
        }else if (order[index]=='2'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    image[i+SIZE/2][j+SIZE/2][k]=newimage[i][j+SIZE/2][k];
                }
                
            }
        }else if (order[index]=='3'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    image[i+SIZE/2][j+SIZE/2][k]=newimage[i+SIZE/2][j][k];
                }
                
            }
        }else if (order[index]=='4'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    image[i+SIZE/2][j+SIZE/2][k]=newimage[i+SIZE/2][j+SIZE/2][k];
                }
                
            }
        }
    }
    index++;
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
        cout<<"hello user here u ca shuffle the photo what do u like to do"<<"\n";
        cout<<"to shuffle->1"<<"\n"<<"to exit->2"<<"\n"<<"enter ur choice:";
        cin>>op;
        switch (op)
        {
        case 1:
            cin.ignore();
            getimg();
            shuffle();
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
