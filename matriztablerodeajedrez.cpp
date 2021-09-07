//PLANTILLA TABLERO AJEDREZ
//Bibliotecas a usar en el codigo
#include <iostream>
#include "conio.h"
#include <fstream>
using namespace std;

int main(){
    string tablero[8][8] ={" "};
    ofstream file;
    file.open("tablero.txt");
    for(int i = 0; i <8; i++){
        for(int j=0; j<8; j++){

            if(j == 1 || j == 6){
                tablero[i][j] = 'P';


            }else if((i==0 || i ==7) && (j==0|| j==7)){
                tablero[i][j]='T';


            }else if((i==1 || i ==6) && (j==0|| j==7)){
                tablero[i][j] = 'C';


            }else if((i==2 || i ==5) && (j==0|| j==7)){
                tablero[i][j] = 'A';


            }else if(i==3  && (j==0|| j==7)){
                tablero[i][j]= 'D';


            }else if( i == 4  && (j==0 || j==7 )){
                tablero[i][j]= 'R';


            }

        }
    }

    for(int i = 0; i<8; i++){
        for(int j =0; j<8; j++){
            file << tablero[i][j]<<"\t";
        }
        file <<endl;
    }
    file.close();
    _getch();
}
