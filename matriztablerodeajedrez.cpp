//PLANTILLA TABLERO AJEDREZ
//Bibliotecas a usar en el codigo
#include <iostream>
//#include "conio.h"
#include <fstream>
using namespace std;
string tablero[8][8] ={" "};
string eleccion[4]={"Ar","Ab","D","I"};
string piezasN[6]={"Pn", "Tn", "Cn", "An", "Dn", "Rn"};
string piezasB[6]={"Pb", "Tb", "Cb", "Ab", "Db", "Rb"};
ofstream file;

void llenado_de_tablero_B(){
    for(int i = 0; i <8; i++){
        for(int j=0; j<8; j++){


            if(j == 1){
                tablero[i][j] = piezasB[0];


            }else if((i==0 || i ==7) && (j==0)){
                tablero[i][j]=piezasB[1];


            }else if((i==1 || i ==6) && (j==0)){
                tablero[i][j] = piezasB[2];


            }else if((i==2 || i ==5) && (j==0)){
                tablero[i][j] = piezasB[3];


            }else if(i==3  && (j==0)){
                tablero[i][j]= piezasB[4];


            }else if( i == 4  && (j==0 )){
                tablero[i][j]= piezasB[5];


            }

        }
    }

    file.open("tablero.txt");
    for(int i = 0; i<8; i++){
        for(int j =0; j<8; j++){
            file << tablero[i][j]<<"__|";

        }
        file <<endl;
    }
    file.close();
    //_getch();
}

void llenado_de_tablero_N(){
    for(int i = 0; i <8; i++){
        for(int j=0; j<8; j++){


            if(j == 6){
                tablero[i][j] = piezasN[0];


            }else if((i==0 || i ==7) && (j==7)){
                tablero[i][j]=piezasN[1];


            }else if((i==1 || i ==6) && (j==7)){
                tablero[i][j] = piezasN[2];


            }else if((i==2 || i ==5) && (j==7)){
                tablero[i][j] = piezasN[3];


            }else if(i==3  && (j==7)){
                tablero[i][j]= piezasN[4];


            }else if( i == 4  && (j==7 )){
                tablero[i][j]= piezasN[5];


            }

        }
    }

    file.open("tablero.txt");
    for(int i = 0; i<8; i++){
        for(int j =0; j<8; j++){
            file << tablero[i][j]<<"__|";

        }
        file <<endl;
    }
    file.close();
    //_getch();
}

bool verificador_pieza(string pieza){
    bool correcto = false;
    for (int i = 0; i < piezasN->size(); ++i) {
        if(pieza == piezasN[i]){
            correcto = true;
        } else{
            correcto = false;
        }
    }
    for (int i = 0; i < piezasB->size(); ++i) {
        if(pieza == piezasN[i]){
            correcto = true;
        } else{
            correcto = false;
        }
    }
    return  correcto;
}


void eleccion_pieza(string pieza){
  if(pieza == "T"){

  }else if(pieza == "C"){

  }else if(pieza == "A"){

  }else if(pieza == "D"){

  }else if(pieza == "R"){

  }else{

  }
}
void mov_Rey(int posx, int posy){

}
void mov_Torre(){

}
void mov_Arfil(){

}
void mov_Reina(){

}
void mov_Caballo(){

}
void mov_Peon(){

}


int main(){
    string pieza=" ";
  /*  do {
        cout << "Elija la pieza que va a mover (Pb, Tb, Cb, Ab, Db, Rb): " << endl;
        cin >> pieza;
        verificador_pieza(pieza);
        if(verificador_pieza(pieza)==false){
            cout << "Pieza inexistente" << endl;
        }
    }while(verificador_pieza(pieza)==false);*/
    llenado_de_tablero_N();
    llenado_de_tablero_B();


}
