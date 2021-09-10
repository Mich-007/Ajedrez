//
// Created by Fabio Villalobos on 10/9/2021.
//

#include <vcl.h>
#pragma hdrstop

#include "UntCuadro.h"
#include "UntPrincipal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmCuadro *FrmCuadro;
TImage* Tablero[8][8];   //La imagen del la matriz de imagenes para el ajedrez
//Es mejor que las imagenes de las piezas sean transparentes
//Estas 3 matrices podrian haberse metido en una clase y luego seleccionar un dato
char  MatrizTipo[8][8];  //Esto fue para saber el tipo de matriz si estaba Con pieza o no
int Matrizcolor[8][8];   //Esto es para saber el color de la pieza
int MatrizSeleccion[8][8]; //esto es para saber cual de todas las piezas esta seleccionada

int blanco=1;
int negro=2;
int selec=1;
int noselec=0;
int nocolor=0;
int turno=blanco;

void fichas(int i, int j, int color, char tipo, int seleccion,TImage* nuevoimagen){
    Tablero[i][j]=nuevoimagen;
    MatrizTipo[i][j]=tipo;
    Matrizcolor[i][j]= color;
    MatrizSeleccion[i][j]=seleccion;
    if( MatrizTipo[i][j]=='V')
    {
        Tablero[i][j]->Picture->LoadFromFile("fondotablero.jpg");  //carga los cuadros vacios
        Tablero[i][j]->Visible=false;
    }
}
void fichas2(int i, int j, int color, char tipo, int seleccion){

    MatrizTipo[i][j]=tipo;
    Matrizcolor[i][j]= color;
    MatrizSeleccion[i][j]=seleccion;
    if( MatrizTipo[i][j]=='V')
    {
        Tablero[i][j]->Picture->LoadFromFile("fondotablero.jpg");
        Tablero[i][j]->Visible=false;
    }
}
int  marcarPieza(int f, int c,int color)
{
    if(f>-1&&f<8&&c>-1&&c<8)
    {
        if(color!=Matrizcolor[f][c])
        {
            if('V'==MatrizTipo[f][c])
            {
                Tablero[f][c]->Visible=true;

            }
            MatrizSeleccion [f][c]=3;
            if('V'!=MatrizTipo[f][c])
            {
                return 0;
            }
            return 1;
        }

    }
    return 0;

}
int  ValidarPieza(int f, int c,int color)
{
    if(f>-1&&f<8&&c>-1&&c<8)
    {
        if(color!=Matrizcolor[f][c])
        {
            return 1;
        }

    }
    return 0;

}


int  marcarPieza_peon(int f, int c,int color)
{
    if(f>-1&&f<8&&c>-1&&c<8)
    {
        if(color!=Matrizcolor[f][c])
        {
            if('V'==MatrizTipo[f][c])
            {
                Tablero[f][c]->Visible=true;

            }
            MatrizSeleccion [f][c]=4;
            return 1;
        }

    }
    return 0;

}
//los movimientos del caballo que es posible que haga
void marcarCaballo(int f,int c,int color)
{
    marcarPieza( f-2,  c-1,color);
    marcarPieza( f-1,  c-2,color);

    marcarPieza( f+1,  c+1,color);
    marcarPieza( f+2,  c+2,color);

    marcarPieza( f-2,  c+1,color);
    marcarPieza( f-1,  c+2,color);

    marcarPieza( f+1,  c-2,color);
    marcarPieza( f+2,  c-1,color);

}
//la torre son 4 for por las lineas rectas
void marcartorre(int f,int c,int color)
{
    //Arriba y abajo
    for(int i=f-1; i>=0;i--)
    {
        if(1!=marcarPieza(i,  c,color))
        {i=0;}
    }
    for(int i=f+1; i<8;i++)
    {
        if(1!=marcarPieza(i,  c,color))
        {i=8;}
    }
    //Izquierda y derecha   i es igual a j
    for(int i=c-1; i>=0;i--)
    {
        if(1!=marcarPieza(f,  i,color))
        {i=0;}
    }
    for(int i=c+1; i<8;i++)
    {
        if(1!=marcarPieza(f,  i,color))
        {i=8;}
    }

}
//el alfil son diagonales
void marcarAlfil(int f,int c,int color)
{

    //Arriba y abajo
    int j=c-1;
    for(int i=f-1; i>=0;i--,j--)
    {
        if(1!=marcarPieza(i,j,color))
        {i=0;}
    }
    j=c+1;
    for(int i=f+1; i<8;i++,j++)
    {
        if(1!=marcarPieza(i, j,color))
        {i=8;}
    }
    //Izquierda y derecha
    j=c+1;
    for(int i=f-1; i>=0;i--,j++)
    {
        if(1!=marcarPieza(i,  j,color))
        {i=0;}
    }
    j=c-1;
    for(int i=f+1; i<8;i++,j--)
    {
        if(1!=marcarPieza(i,  j,color))
        {i=8;}
    }



}
//la dama es una torre con un alfil
void marcarDama(int f,int c,int color)
{
    marcartorre(f,c,color);
    marcarAlfil(f,c,color);
}
//el pion lleva condiciones especiales
void marcar_pion_mueve(int f,int c,int color)
{          if(color==negro)
    {marcarPieza_peon(f+1,  c,color);
        if( MatrizTipo[f+1][ c-1]!='V')  marcarPieza(f+1,  c-1,color);
        if( MatrizTipo[f+1][  c+1]!='V')        marcarPieza(f+1,  c+1,color);
        if(f==1)
        {marcarPieza_peon(f+2, c,color);
        }
    }
    if(color==blanco)
    {marcarPieza_peon(f-1,  c,color);

        if( MatrizTipo[f-1][ c-1]!='V')  marcarPieza(f-1,  c-1,color);
        if( MatrizTipo[f-1][  c+1]!='V')    marcarPieza(f-1,  c+1,color);
        if(f==6)
        { marcarPieza_peon(f-2,  c,color);
        }}
}
//al rey le faltan las condiciones de jake y retriciones
void marcarRey(int f,int c,int color)
{
    for (int i = f-1; i < f+2; i++) {
        for (int j = c-1; j < c+2; j++) {
            if(i!=f&&c!=j)
                marcarPieza(i,  j,color);

        }}

}
//Aqui se llene el cuadro
__fastcall TFrmCuadro::TFrmCuadro(TComponent* Owner)
        : TForm(Owner)
{
//negras
    fichas(0,0,negro,'T',noselec,this->TorreNegraB);
    fichas(0,1,negro,'C',noselec,this->CaballoNegroN);
    fichas(0,2,negro,'A',noselec,this->AlfilNegroB);
    fichas(0,3,negro,'D',noselec,this->DamaNegraN);
    fichas(0,4,negro,'R',noselec,this->ReyNegroB);
    fichas(0,5,negro,'A',noselec,this->AlfilNegroN);
    fichas(0,6,negro,'C',noselec,this->CaballoNegroB);
    fichas(0,7,negro,'T',noselec,this->TorreNegraN);

    fichas(1,0,negro,'P',noselec,this->PeonNegroN1);
    fichas(1,1,negro,'P',noselec,this->PeonNegroB1);
    fichas(1,2,negro,'P',noselec,this->PeonNegroN2);
    fichas(1,3,negro,'P',noselec,this->PeonNegroB2);
    fichas(1,4,negro,'P',noselec,this->PeonNegroN3);
    fichas(1,5,negro,'P',noselec,this->PeonNegroB3);
    fichas(1,6,negro,'P',noselec,this->PeonNegroN4);
    fichas(1,7,negro,'P',noselec,this->PeonNegroB4);

    //blancas

    fichas(7,0,blanco,'T',noselec,this->TorreBlancaN);
    fichas(7,1,blanco,'C',noselec,this->CaballoBlancoB);
    fichas(7,2,blanco,'A',noselec,this->AlfilBlancoN);
    fichas(7,3,blanco,'D',noselec,this->DamaBlancaB);
    fichas(7,4,blanco,'R',noselec,this->ReyBlancoN);
    fichas(7,5,blanco,'A',noselec,this->AlfilBlancoB);
    fichas(7,6,blanco,'C',noselec,this->CaballoBlancoN);
    fichas(7,7,blanco,'T',noselec,this->TorreBlancaB);

    fichas(6,0,blanco,'P',noselec,this->PeonBlancoB1);
    fichas(6,1,blanco,'P',noselec,this->PeonBlancoN1);
    fichas(6,2,blanco,'P',noselec,this->PeonBlancoB2);
    fichas(6,3,blanco,'P',noselec,this->PeonBlancoN2);
    fichas(6,4,blanco,'P',noselec,this->PeonBlancoB3);
    fichas(6,5,blanco,'P',noselec,this->PeonBlancoN3);
    fichas(6,6,blanco,'P',noselec,this->PeonBlancoB4);
    fichas(6,7,blanco,'P',noselec,this->PeonBlancoN4);

    //vacíos

    fichas(2,0,nocolor,'V',noselec,this->VacioB1);
    fichas(2,1,nocolor,'V',noselec,this->VacioN1);
    fichas(2,2,nocolor,'V',noselec,this->VacioB2);
    fichas(2,3,nocolor,'V',noselec,this->VacioN2);
    fichas(2,4,nocolor,'V',noselec,this->VacioB3);
    fichas(2,5,nocolor,'V',noselec,this->VacioN3);
    fichas(2,6,nocolor,'V',noselec,this->VacioB4);
    fichas(2,7,nocolor,'V',noselec,this->VacioN4);

    fichas(3,0,nocolor,'V',noselec,this->VacioN5);
    fichas(3,1,nocolor,'V',noselec,this->VacioB5);
    fichas(3,2,nocolor,'V',noselec,this->VacioN6);
    fichas(3,3,nocolor,'V',noselec,this->VacioB6);
    fichas(3,4,nocolor,'V',noselec,this->VacioN7);
    fichas(3,5,nocolor,'V',noselec,this->VacioB7);
    fichas(3,6,nocolor,'V',noselec,this->VacioN8);
    fichas(3,7,nocolor,'V',noselec,this->VacioB8);

    fichas(4,0,nocolor,'V',noselec,this->VacioB9);
    fichas(4,1,nocolor,'V',noselec,this->VacioN9);
    fichas(4,2,nocolor,'V',noselec,this->VacioB10);
    fichas(4,3,nocolor,'V',noselec,this->VacioN10);
    fichas(4,4,nocolor,'V',noselec,this->VacioB11);
    fichas(4,5,nocolor,'V',noselec,this->VacioN11);
    fichas(4,6,nocolor,'V',noselec,this->VacioB12);
    fichas(4,7,nocolor,'V',noselec,this->VacioN12);

    fichas(5,0,nocolor,'V',noselec,this->VacioN13);
    fichas(5,1,nocolor,'V',noselec,this->VacioB13);
    fichas(5,2,nocolor,'V',noselec,this->VacioN14);
    fichas(5,3,nocolor,'V',noselec,this->VacioB14);
    fichas(5,4,nocolor,'V',noselec,this->VacioN15);
    fichas(5,5,nocolor,'V',noselec,this->VacioB15);
    fichas(5,6,nocolor,'V',noselec,this->VacioN16);
    fichas(5,7,nocolor,'V',noselec,this->VacioB16);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::SBTSalirClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
int  seleccion()
{ for (int i = 0; i < 8; i++) {
        for (int j =0; j < 8; j++) {
            if( MatrizSeleccion[i][j]==selec)
            {
                return 1;
            }

        }
    }
    return 0;
}
//para saber que toco
void pregunta(int i, int j,int color)
{
    if( MatrizTipo[i][j]=='P')
    {
        marcar_pion_mueve(i,j,color);
    }
    if( MatrizTipo[i][j]=='T')
    {
        marcartorre(i,j,color);
    }
    if( MatrizTipo[i][j]=='C')
    {
        marcarCaballo(i,j,color);
    }
    if( MatrizTipo[i][j]=='A')
    {
        marcarAlfil(i,j,color);
    }
    if( MatrizTipo[i][j]=='D')
    {
        marcarDama(i,j,color);
    }
    if( MatrizTipo[i][j]=='R')
    {
        marcarRey(i,j,color);
    }

}
//lleva los turnos de los jugadores.
void piezatipo(int i, int j){



    if( seleccion()==1)
    {
        int j_origianl =0;
        int i_origianl=0;
        for (int ie = 0; ie < 8; ie++) {
            for (int je =0; je < 8; je++) {
                if(       MatrizSeleccion[ie][je]==1)
                {          j_origianl=je;
                    i_origianl=ie; }
            }}

        if(       MatrizSeleccion[i][j]==3)
        {

            Tablero[i][j]->Picture=Tablero[i_origianl][j_origianl]->Picture;
            fichas2(i,j,Matrizcolor[i_origianl][j_origianl],MatrizTipo[i_origianl][j_origianl],noselec);
            fichas2(i_origianl,j_origianl,nocolor,'V',noselec);



            if(turno==   blanco)
            {              turno=negro;     }else
            { turno=blanco;}

        }else
        {                          if(       MatrizSeleccion[i][j]==4)
            {
                if( MatrizTipo[i][j]=='V')
                {
                    Tablero[i][j]->Picture=Tablero[i_origianl][j_origianl]->Picture;
                    fichas2(i,j,Matrizcolor[i_origianl][j_origianl],MatrizTipo[i_origianl][j_origianl],noselec);
                    fichas2(i_origianl,j_origianl,nocolor,'V',noselec);
                    if(turno==  blanco)
                    {              turno=negro;     }else
                    { turno=blanco;}
                }


            }
        }
        for (int ie = 0; ie < 8; ie++) {
            for (int je =0; je < 8; je++) {

                MatrizSeleccion[ie][je]=0;
                if( MatrizTipo[ie][je]=='V')
                {
                    Tablero[ie][je]->Visible=false;
                }
            }
        }

    }
    else
    {
        if(turno==   Matrizcolor[i][j])
        {    if( MatrizTipo[i][j]!='V')
            {
                MatrizSeleccion[i][j]=1;
                pregunta( i,  j,Matrizcolor[i][j]) ;

            }
        }

    }

}
void __fastcall TFrmCuadro::PeonNegroN1Click(TObject *Sender)
{

    piezatipo(1,0);
}



//---------------------------------------------------------------------------

//estos eventos se pueden asignar de forma dinamica
//Pero eso es un tanto elevado y el codigo que esta
//aqui se puede reducir mas y compactar pero despues es
//dificil de entender, como un lenguaje de funciones.
void __fastcall TFrmCuadro::movercaballo(int fila, int columna){


    ShowMessage("HOLA");
}
void __fastcall TFrmCuadro::PeonNegroB1Click(TObject *Sender)
{
    piezatipo(1,1);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::PeonNegroN2Click(TObject *Sender)
{
    piezatipo(1,2);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::PeonNegroB2Click(TObject *Sender)
{
    piezatipo(1,3);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::PeonNegroN3Click(TObject *Sender)
{
    piezatipo(1,4);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::PeonNegroB3Click(TObject *Sender)
{
    piezatipo(1,5);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::PeonNegroN4Click(TObject *Sender)
{
    piezatipo(1,6);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::PeonNegroB4Click(TObject *Sender)
{
    piezatipo(1,7);
}
//---------------------------------------------------------------------------




void __fastcall TFrmCuadro::TorreNegraBClick(TObject *Sender)
{
    piezatipo(0,0);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::CaballoNegroNClick(TObject *Sender)
{
    piezatipo(0,1);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::CaballoBlancoBClick(TObject *Sender)
{
    piezatipo(7,1);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::TorreBlancaNClick(TObject *Sender)
{
    piezatipo(7,0);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::AlfilBlancoNClick(TObject *Sender)
{
    piezatipo(7,2);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::DamaBlancaBClick(TObject *Sender)
{
    piezatipo(7,3);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::ReyBlancoNClick(TObject *Sender)
{
    piezatipo(7,4);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::AlfilBlancoBClick(TObject *Sender)
{
    piezatipo(7,5);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::CaballoBlancoNClick(TObject *Sender)
{
    piezatipo(7,6);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::TorreBlancaBClick(TObject *Sender)
{
    piezatipo(7,7);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::PeonBlancoB1Click(TObject *Sender)
{
    piezatipo(6,0);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::PeonBlancoN1Click(TObject *Sender)
{
    piezatipo(6,1);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::PeonBlancoB2Click(TObject *Sender)
{
    piezatipo(6,2);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::PeonBlancoN2Click(TObject *Sender)
{
    piezatipo(6,3);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::PeonBlancoB3Click(TObject *Sender)
{
    piezatipo(6,4);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::PeonBlancoN3Click(TObject *Sender)
{
    piezatipo(6,5);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::PeonBlancoB4Click(TObject *Sender)
{
    piezatipo(6,6);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::PeonBlancoN4Click(TObject *Sender)
{
    piezatipo(6,7);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioN13Click(TObject *Sender)
{
    piezatipo(5,0);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioB13Click(TObject *Sender)
{
    piezatipo(5,1);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioN14Click(TObject *Sender)
{
    piezatipo(5,2);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioB14Click(TObject *Sender)
{
    piezatipo(5,3);
}
//---------------------------------------------------------------------------



void __fastcall TFrmCuadro::VacioN15Click(TObject *Sender)
{
    piezatipo(5,4);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioB15Click(TObject *Sender)
{
    piezatipo(5,5);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioN16Click(TObject *Sender)
{
    piezatipo(5,6);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioB16Click(TObject *Sender)
{
    piezatipo(5,7);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioB9Click(TObject *Sender)
{
    piezatipo(4,0);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioN9Click(TObject *Sender)
{
    piezatipo(4,1);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioB10Click(TObject *Sender)
{
    piezatipo(4,2);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioN10Click(TObject *Sender)
{
    piezatipo(4,3);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioB11Click(TObject *Sender)
{
    piezatipo(4,4);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioN11Click(TObject *Sender)
{
    piezatipo(4,5);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioB12Click(TObject *Sender)
{
    piezatipo(4,6);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioN12Click(TObject *Sender)
{
    piezatipo(4,7);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioN5Click(TObject *Sender)
{
    piezatipo(3,0);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioB5Click(TObject *Sender)
{
    piezatipo(3,1);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioN6Click(TObject *Sender)
{
    piezatipo(3,2);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioB6Click(TObject *Sender)
{
    piezatipo(3,3);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioN7Click(TObject *Sender)
{
    piezatipo(3,4);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioB7Click(TObject *Sender)
{
    piezatipo(3,5);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioN8Click(TObject *Sender)
{
    piezatipo(3,6);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioB8Click(TObject *Sender)
{
    piezatipo(3,7);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioB1Click(TObject *Sender)
{
    piezatipo(2,0);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioN1Click(TObject *Sender)
{
    piezatipo(2,1);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioB2Click(TObject *Sender)
{
    piezatipo(2,2);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioN2Click(TObject *Sender)
{
    piezatipo(2,3);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioB3Click(TObject *Sender)
{
    piezatipo(2,4);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioN3Click(TObject *Sender)
{
    piezatipo(2,5);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioB4Click(TObject *Sender)
{
    piezatipo(2,6);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::VacioN4Click(TObject *Sender)
{
    piezatipo(2,7);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::AlfilNegroBClick(TObject *Sender)
{
    piezatipo(0,2);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::DamaNegraNClick(TObject *Sender)
{
    piezatipo(0,3);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::ReyNegroBClick(TObject *Sender)
{
    piezatipo(0,4);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::AlfilNegroNClick(TObject *Sender)
{
    piezatipo(0,5);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::CaballoNegroBClick(TObject *Sender)
{
    piezatipo(0,6);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCuadro::TorreNegraNClick(TObject *Sender)
{
    piezatipo(0,7);
}
//---------------------------------------------------------------------------
