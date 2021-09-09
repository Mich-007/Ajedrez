//PLANTILLA TABLERO AJEDREZ
//Bibliotecas a usar en el codigo
#include <iostream>
#include "conio.h"
#include <fstream>
using namespace std;
string tablero[8][8] ={" "};
string eleccion[4]={"Ar","Ab","D","I"};
string piezas[6]={"P", "T", "C", "A", "D", "R"};

void llenado_de_tablero(){
    for(int i = 0; i <8; i++){
        for(int j=0; j<8; j++){


            if(j == 1 || j == 6){
                tablero[i][j] = piezas[0];


            }else if((i==0 || i ==7) && (j==0|| j==7)){
                tablero[i][j]=piezas[1];


            }else if((i==1 || i ==6) && (j==0|| j==7)){
                tablero[i][j] = piezas[2];


            }else if((i==2 || i ==5) && (j==0|| j==7)){
                tablero[i][j] = piezas[3];


            }else if(i==3  && (j==0|| j==7)){
                tablero[i][j]= piezas[4];


            }else if( i == 4  && (j==0 || j==7 )){
                tablero[i][j]= piezas[5];


            }

        }
    }
    ofstream file;
    file.open("tablero.txt");
    for(int i = 0; i<8; i++){
        for(int j =0; j<8; j++){
            file << tablero[i][j]<<"__|";

        }
        file <<endl;
    }
    file.close();
    _getch();
}

bool verificador_pieza(string pieza){
    bool correcto = false;
    for (int i = 0; i < piezas->size(); ++i) {
        if(pieza == piezas[i]){
            correcto = true;
        } else{
            correcto = false;
        }
    }
    return  correcto;
}

/*
void eleccion_pieza(string pieza){
    bool correcto = false;
    for (int i = 0; i < piezas->size(); ++i) {
        if(pieza == piezas[i]){
            correcto = true;
        } else{
            correcto = false;
        }
    }

}*/
/*void mov_Rey(){

}*/


int main(){
    string pieza=" ";
    do {
        cout << "Elija la pieza que va a mover (P, T, C, A, D, R): " << endl;
        cin >> pieza;
        verificador_pieza(pieza);
        if(verificador_pieza(pieza)==false){
            cout << "Pieza inexistente" << endl;
        }
    }while(verificador_pieza(pieza)==false);
    llenado_de_tablero();


}