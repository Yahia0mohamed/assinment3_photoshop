#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;

int get=0;
int rotated =0;

unsigned char image[SIZE][SIZE];
unsigned char extra[SIZE][SIZE];
unsigned char filteredimage[SIZE][SIZE];

void menu();
void getting_image();
void saving_image();
void black_white();
void invert();
void merge();
void flip();
void rotate();
void darken_lighten();
void detect_edges();
void enlarge();
void shrink();
void mirror();
void shuffle();
void blur();


int main()
{
    bool flag = true;
    while (flag)
    {
        int check;
        cout<<"do u want to continue to the program\n1 ->true\n2 ->false\nenter:";
        cin>>check;
        if(check==1){
            menu();
        }
        else{
            flag=false;
        }
    }
    
    return 0;
}

void getting_image()
{
    // intiliazing char to recieve file name from the user 
    char fileName[100];
    cout << "Enter the source image file name: ";
    cin >> fileName;
    //converting file taken from the user to bmp
    strcat(fileName, ".bmp");
    //reading file taken from the user 
    readGSBMP(fileName, image);
    if (get==1){
        cin.ignore();
        // intiliazing char to recieve file name from the user 
        char fileName[100];
        cout << "Enter the source image file name: ";
        cin >> fileName;
        //converting file taken from the user to bmp
        strcat(fileName, ".bmp");
        //reading file taken from the user 
        readGSBMP(fileName, extra);
    }
}

void saving_image(){
    //receiving the new filtered image file name from the user
    char imageFileName[100];
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, filteredimage);
}

void menu(){
    char choice;
    cout<<"Enter the number of the filter"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"black & white       ||                        1"<<endl;
    cout<<"invert              ||                        2"<<endl;
    cout<<"merge               ||                        3"<<endl;
    cout<<"flip                ||                        4"<<endl;
    cout<<"rotate              ||                        5"<<endl;
    cout<<"darken & lighten    ||                        6"<<endl;
    cout<<"detect edges        ||                        7"<<endl;
    cout<<"enlarge             ||                        8"<<endl;
    cout<<"shrink              ||                        9"<<endl;
    cout<<"mirror              ||                        a"<<endl;
    cout<<"shuffle             ||                        b"<<endl;
    cout<<"blur                ||                        c"<<endl;
    cout<<"exit                ||                        x"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"Enter the Number:";
    cin>>choice;
    switch (choice)
    {
    case '1':
        getting_image();
        black_white();
        saving_image();
        break;
    case '2':
        getting_image();
        invert();
        saving_image();
        break;
    case '3':
        get+=1;
        getting_image();
        merge();
        saving_image();
        break;
    case '4':
        getting_image();
        flip();
        saving_image();
        break;
    case '5':
        getting_image();
        rotate();
        saving_image();
        break;
    case '6':
        getting_image();
        darken_lighten();
        saving_image();
        break;
    case '7':
        getting_image();
        detect_edges();
        saving_image();
        break;
    case '8':
        getting_image();
        enlarge();
        saving_image();
        break;
    case '9':
        getting_image();
        shrink();
        saving_image();
        break;
    case 'a':
        getting_image();
        mirror();
        saving_image();
        break;
    case 'b':
        getting_image();
        shuffle();
        saving_image();
        break;
    case 'c':
        getting_image();
        blur();
        saving_image();
        break;
    case 'x':
        exit(0);
        break;
    default:
        cout<<"wrong choice"<<endl;
        menu();
        break;
    }
}

void black_white(){
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            //scaling up every bit more than 127 to 255(white)
            if (image[i][j] > 127)
            {
                filteredimage[i][j] = 255;
            }
            else
            {
                //scalling down every bit less than 127 to 0(black)
                filteredimage[i][j] = 0;
            }
        }
    }
}

void invert(){
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            int pixel = image[i][j];
            if (pixel>0 && pixel<255){
                filteredimage[i][j]=255-pixel;
            }
            else if (pixel==255)
            {
                filteredimage[i][j]=0;
            }
            else if(pixel==0){
                filteredimage[i][j]=255+pixel;
            }
        }
        
    }
}

void merge(){
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        filteredimage [i][j]= (image [i][j] + extra[i][j]) /2;
        }
    }
}

void flip(){
    char choice;
    cout << "Press (h) to flip horizontally , (v) to flip vertically " << endl;
    cin >> choice;
    if (choice == 'h')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                    filteredimage[i][j] = image[SIZE-i][SIZE-j];
            }
        }
    }
    else if (choice == 'v')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                    filteredimage[j][i]=image[j][SIZE-i] ;

            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = filteredimage[i][j];
        }
    }
}

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
                filteredimage[j][i]=image[i][j];
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
                filteredimage[row][column]=image[i][j];
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
                filteredimage[j][i]=image[i][j];
            }
        }
        rotated+=1;
        if (rotated==1){
            int row = 255;
        int column = 255;
        for (int i = 0; i < SIZE; ++i)
        {
        for (int j = 0; j < SIZE; ++j)
            {
                extra[row][column]=filteredimage[i][j];
                
                column-=1;
                if (column==0){
                    row-=1;
                }
            }
        }
        }
        int then=0;
        then++;
        if (then>0)
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    filteredimage[i][j]=extra[i][j];
                }
                
            }
            
        }
        
        break;
    }
    }
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
        filteredimage[i][j]=image[i][j];
        }
        else{
        filteredimage[i][j]=image[i][j]-60;
            }
        }
    }
        break;
    }
        case 2:{
        for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
        if (image[i][j]>=195){
            filteredimage[i][j]=image[i][j];
        }
        else{
            filteredimage[i][j]=image[i][j]+60;
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

void detect_edges(){
    //1- convert greyscale to black and white
    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            //convert to black and white
            if (image[i][j] > 127)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
    for (int i = 1; i < SIZE - 1; i += 1) {
        for (int j = 1; j < SIZE - 1; j += 1) {
            //2- check detection of current pixel against before/after pixels
            if (image[i][j] == image[i][j + 1] and image[i][j] == image[i][j - 1])
                //set value to white
                filteredimage[i][j] = 255;
            else
                //set value to black
                filteredimage[i][j] = 0;
        }
    }
}

void enlarge(){
    int quarter;
    cout<<"please enter the quarter u want to enlarge:";
    cin>>quarter;
    for (int i = 0; i < SIZE; i+=2){
        for (int j =0; j<SIZE;j+=2){
            if (quarter==1){
                filteredimage[i][j]=image[i/2][j/2];
                filteredimage[i][j+1]=image[i/2][j/2];
                filteredimage[i+1][j]=image[i/2][j/2];
                filteredimage[i+1][j+1]=image[i/2][j/2];
            }else if (quarter==2){
                filteredimage[i][j]=image[i/2][(j+SIZE)/2];
                filteredimage[i][j+1]=image[i/2][(j+SIZE)/2];
                filteredimage[i+1][j]=image[i/2][(j+SIZE)/2];
                filteredimage[i+1][j+1]=image[i/2][(j+SIZE)/2];
            }else if (quarter==3){
                filteredimage[i][j]=image[(i+SIZE)/2][j/2];
                filteredimage[i][j+1]=image[(i+SIZE)/2][j/2];
                filteredimage[i+1][j]=image[(i+SIZE)/2][j/2];
                filteredimage[i+1][j+1]=image[(i+SIZE)/2][j/2];
            }else if (quarter==4){
                filteredimage[i][j]=image[(i+SIZE)/2][(j+SIZE)/2]; 
                filteredimage[i][j+1]=image[(i+SIZE)/2][(j+SIZE)/2];
                filteredimage[i+1][j]=image[(i+SIZE)/2][(j+SIZE)/2];
                filteredimage[i+1][j+1]=image[(i+SIZE)/2][(j+SIZE)/2];
            }
        }
    }
}

void shrink(){
    int choice;
    cout<<"for 1/4 ->1\nfor 1/3 ->2\nfor 1/2 ->3\nenter:" ;
    cin>>choice;
    if (choice==1){
        for (int i = 0; i < SIZE ; i+=2)
        {
            for (int j = 0; j < SIZE; j+=2)
            {
                filteredimage[i/2][j/2]=image[i][j];
            }
            
        }
        
    }else if (choice == 2)
    {
        for (int i = 0; i < SIZE; i+=3)
        { for (int j = 0; j < SIZE; j+=3)
        {
            filteredimage[i/3][j/3] = image[i][j];
        }
        }
    }else if (choice == 3)
    {
        for (int i = 0; i < SIZE; i+=4)
        { for (int j = 0; j < SIZE; j+=4)
        {
            filteredimage[i/4][j/4] = image[i][j];
        }
        }
    }
}

void mirror(){
        char choice1, choice2;

    cout << "Choose whether you want to mirror the image horizontally (h) or vertically (v)" << endl;
    cin >> choice1;
    if (choice1 == 'v') {
        cout << "Choose either the left part (l) or the right part (r)" << endl;
        cin >> choice2;
        if (choice2 == 'l') {
            for (int i = 0; i < SIZE; i++) {
                // half size of vertical mirror
                for (int j = 0; j < SIZE / 2; j++)
                {
                    int temp = image[i][j];
                    //check if first half
                    if (j < SIZE / 2)
                        filteredimage[i][SIZE - j] = temp;
                    else
                        filteredimage[i][j] = image[i][SIZE - j];
                }
            }
        }
        if (choice2 == 'r') {
            for (int i = 0; i < SIZE; i++) {
                // half size of vertical mirror
                for (int j = 0; j < SIZE / 2; j++) {
                    int temp = image[i][j];
                    // check if second half
                    if (j > SIZE / 2)
                        filteredimage[i][SIZE - j] = temp;
                    else
                        filteredimage[i][j] = image[i][SIZE - j];

                }
            }
        }

    }
    if (choice1 == 'h') {
        cout << "Choose either the upper part (u) or the lower part (l)" << endl;
        cin >> choice2;
        if (choice2 == 'u') {
            // half size of horizontal mirror
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE; j++) {
                    int temp = image[i][j];
                    // check if first half
                    if (i < SIZE / 2)
                        filteredimage[SIZE - i][j] = temp;
                    else
                        filteredimage[i][j] = image[SIZE - i][j];
                }
            }
        }
        if (choice2 == 'l') {
            // half size of horizontal mirror
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE; j++) {
                    int temp = image[i][j];
                    // check if second half
                    if (i > SIZE / 2)
                        filteredimage[SIZE - i][j] = temp;
                    else
                        filteredimage[i][j] = image[SIZE - i][j];
                }
            }
        }

    }
}

void shuffle(){
    int index =0;
    string order;
    cout<<"enter the order";
    cin>>order;
    int length = order.length();
    while (index<4){
        if (index==0){
            if (order[index]=='1'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    filteredimage[i][j]=image[i][j];
                }
            }
            
        }else if (order[index]=='2'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    filteredimage[i][j]=image[i][j+SIZE/2];
                }
            }
        }else if (order[index]=='3'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    filteredimage[i][j]=image[i+SIZE/2][j];
                }
                
            }
        }else if (order[index]=='4'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    filteredimage[i][j]=image[i+SIZE/2][j+SIZE/2];
                }
                
            }
        }
    }
    // --------------------
        else if (index ==1){
            if (order[index]=='1'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    filteredimage[i][j+SIZE/2]=image[i][j];
                }
                
            }
            
        }else if (order[index]=='2'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    filteredimage[i][j+SIZE/2]=image[i][j+SIZE/2];
                }
                
            }
        }else if (order[index]=='3'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    filteredimage[i][j+SIZE/2]=image[i+SIZE/2][j];
                }
                
            }
        }else if (order[index]=='4'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    filteredimage[i][j+SIZE/2]=image[i+SIZE/2][j+SIZE/2];
                }
                
            }
        }
    }
    // -------------
    else if (index==2){
        if (order[index]=='1'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    filteredimage[i+SIZE/2][j]=image[i][j];
                }
                
            }
            
        }else if (order[index]=='2'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    filteredimage[i+SIZE/2][j]=image[i][j+SIZE/2];
                }
                
            }
        }else if (order[index]=='3'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    filteredimage[i+SIZE/2][j]=image[i+SIZE/2][j];
                }
                
            }
        }else if (order[index]=='4'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    filteredimage[i+SIZE/2][j]=image[i+SIZE/2][j+SIZE/2];
                }
                
            }
    }
    }// ---------
    else if (index ==3){
        if (order[index]=='1'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    filteredimage[i+SIZE/2][j+SIZE/2]=image[i][j];
                }
                
            }
        }else if (order[index]=='2'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    filteredimage[i+SIZE/2][j+SIZE/2]=image[i][j+SIZE/2];
                }
                
            }
        }else if (order[index]=='3'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    filteredimage[i+SIZE/2][j+SIZE/2]=image[i+SIZE/2][j];
                }
                
            }
        }else if (order[index]=='4'){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE/2; j++){
                    filteredimage[i+SIZE/2][j+SIZE/2]=image[i+SIZE/2][j+SIZE/2];
                }
                
            }
        }
    }
    index++;
    }
}

void blur(){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            filteredimage[i+1][j+1]=(image[i][j]+image[i][j+1]+image[i][j+2]+image[i+1][j]+image[i+1][j+1]+image[i+1][j+2]+image[i+2][j]+image[i+2][j+1]+image[i+2][j+2])/9;
        }
    }
}