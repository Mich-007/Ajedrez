//PLANTILLA TABLERO AJEDREZ
//Bibliotecas a usar en el codigo
#include <iostream>
//#include "conio.h"
#include <fstream>
using namespace std;
string tablero[8][8] ={" "};
//string eleccion[4]={"Ar","Ab","D","I"};
char piezas[6]={'P', 'T', 'C', 'A', 'D', 'R'};
ofstream file;


//Funcion eleccion de pieza
void eleccion_pieza(string jugada){
    for(int i = 0; i < piezas.size(); i++){
        if(jugada[0]==piezas[i]){

        }
    }
}


//Funcion movimiento de pieza: rey
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

//Funcion principal
int main(){
    string jugada=" ";
    int cont = 0;


}
