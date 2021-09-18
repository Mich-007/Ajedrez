#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace::std;
string tablero[8][8];
string piezas1[6]={"p1", "t1", "c1", "a1", "q1", "k1"};
string piezas2[6]={"p2", "t2", "c2", "a2", "q2", "k2"};
char number[8]={'1','2','3','4','5','6','7','8'};
char letter[8]={'a','b','c','d','e','f','g','h'};
int turno=0;
ofstream file;


void impTablero()//string tablero[8][8])
{
    int cont=0;
    cout<<"\311";
    while (cont<7)
    {
        for (int i=1;i<=4;i++)    // dibujando límite superior
        {
            if (i%4!=0)
            {
                cout<<"\315";
            }
            else
            {
                cout<<"\313";
                cont++;
            }
            if (cont==7)
            {
                cout<<"\315\315\315\273"<<endl;
            }
        }
    }
    for (int j=7;j>=0;j--)
    {
        for (int i=0;i<8;i++)
        {
            cout<<"\272"<<tablero[i][j]<<" ";   //imprimiendo tablero
            if (i==7)
            {
                cout<<"\272 "<<(j+1);

            }
        }
        cout<<endl;
        if (j!=0)
        {
            cout<<"\314";
            cont=0;
            while (cont<=7)
            {
                for (int k=1;k<=4;k++)
                {
                    if (k%4!=0)
                    {
                        cout<<"\315"; //dibujando rayas entre cuadrantes
                    }
                    else
                    {
                        cout<<"\316";
                        cont++;
                    }

                }
                if (cont==7)
                {
                    cout<<"\315\315\315\271"<<endl;
                    cont++;
                }
            }

        }
    }
    cout<<"\310";
    cont=0;
    while (cont<7)
    {
        for (int i=1;i<=4;i++)    // dibujando límite inferior
        {
            if (i%4!=0)
            {
                cout<<"\315";
            }
            else
            {
                cout<<"\312";
                cont++;
            }
            if (cont==7)
            {
                cout<<"\315\315\315\274"<<endl;
            }
        }
    }
    for(int i=65;i<(65+8);i++)
    {
        printf("  %c ",i);
        if (i==(65+7))
        {
            cout<<"\n\n";
            cout<<"***********************************\n\n";

        }
    }
}

int c2i( char a) {
    int cont = 0;
    for (int i = 0; i < 8; ++i) {
        if (a == number[i] || a == letter[i]) {
            cont = i;
        }

    }
    return cont;
}

void iniciaTablero()
{

    for (int i=0;i<8;i++)
    {
        tablero[i][1]=piezas1[0];   //ubicación de peones
        tablero[i][6]=piezas2[0];
    }

    tablero[0][0]=piezas1[1];
    tablero[1][0]=piezas1[2];    //ubicación otras piezas jugador 1
    tablero[2][0]=piezas1[3];
    tablero[3][0]=piezas1[4];
    tablero[4][0]=piezas1[5];
    for (int i=5;i<8;i++)
    {
        tablero[i][0]=tablero[7-i][0];
    }
    tablero[0][7]=piezas2[1];
    tablero[1][7]=piezas2[2];
    tablero[2][7]=piezas2[3];
    tablero[3][7]=piezas2[4];    //ubicación otras piezas jugador 2
    tablero[4][7]=piezas2[5];

    for (int i=5;i<8;i++)
    {
        tablero[i][7]=tablero[7-i][7];
    }

    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if (tablero[i][j]=="\0")    //Dibujando espacitos vacíos
            {
                tablero[i][j]="  ";
            }
        }
    }
}

bool movPeon(int xinic,int yinic,int xfin, int yfin){
    bool i=false;
    int a=0;
    if (xinic==xfin)
    {
        if (((yinic+1==yfin)||(yinic-1==yfin))
            &&(tablero[xinic][yfin][1]!='2'))
        {
            a++;
        }
        if (((yinic+1==yfin)||(yinic-1==yfin))
            &&(tablero[xinic][yfin][1]!='1'))
        {
            a++;
        }
        if (((yinic+2==yfin)&&(xinic==xfin))
            &&(yinic=1)
            &&(tablero[xinic][yfin][1]!='2')&&(tablero[xinic][yinic+1]=="  "))
        {
            a++;
        }
        if (((yinic-2==yfin)&&(xinic==xfin))
            &&(yinic=6)
            &&(tablero[xinic][yfin][1]!='1')&&(tablero[xinic][yinic-1]=="  "))
        {
            a++;
        }
        if (a>0)
        {
            if (tablero[xfin][yfin][1]!=tablero[xinic][yinic][1])
            {
                i= true;
            }
        }
        else
        {
            i= false;
        }
    }

    if (((xinic+1==xfin)||(xinic-1==xfin))&&(yinic=yfin-1)&&(tablero[xfin][yfin][1]=='2'))
    {
        i= true;
    }
    if (((xinic+1==xfin)||(xinic-1==xfin))&&(yinic=yfin+1)&&(tablero[xfin][yfin][1]=='1')){
        i = true;
    }

    return i;
}

bool movTorre(int xinic,int yinic,int xfin, int yfin){
    bool saltoPieza=false;
    bool i = false;
    if ((xinic==xfin)||(yinic==yfin))
        if (xinic==xfin)
        {
            if (yfin>yinic+1)
            {
                for (int i=yinic+1;i<=yfin-1;i++)
                {
                    if (tablero[xinic][i]!="  ")
                    {
                        saltoPieza=true;
                    }
                }
            }
            if (yfin<yinic-1)
            {
                for (int i=yinic-1;i>=yfin+1;i--)
                {
                    if (tablero[xinic][i]!="  ")
                    {
                        saltoPieza=true;
                    }
                }
            }
        }
    if (yinic==yfin)
    {
        if (xfin>xinic+1)
        {
            for (int i=xinic+1;i<=xfin-1;i++)
            {
                if (tablero[i][yinic]!="  ")
                {
                    saltoPieza=true;
                }
            }
        }
        if (xfin<xinic)
        {
            for (int i=xinic-1;i>=xfin+1;i--)
            {
                if (tablero[i][yinic]!="  ")
                {
                    saltoPieza=true;
                }
            }
        }
    }
    if (saltoPieza==false)
    {
        if (tablero[xfin][yfin][1]!=tablero[xinic][yinic][1])
        {
            i= true;
        }
    }

    return i;
}

bool movArfil(int xinic,int yinic,int xfin, int yfin){
    bool saltoPieza=false;
    bool i =false;
    saltoPieza=false;
    if (abs((xfin-xinic))==abs((yinic-yfin)))
    {
        if ((xfin-xinic-1>0)&&(yfin-yinic-1>0))
        {
            for (int i=1;i<=(xfin-xinic)-1;i++)
            {
                if ((tablero[xinic+i][yinic+i]!="  ")&&(tablero[xinic+i][yinic+i]!=tablero[xinic][yinic]))
                {
                    saltoPieza=true;
                }
            }

        }
        if ((xfin-xinic+1<0)&&(yfin-yinic-1>0))
        {
            for (int i=1;i<=(-xfin+xinic)-1;i++)
            {
                if ((tablero[xinic-i][yinic+i]!="  ")&&(tablero[xinic-i][yinic+i]!=tablero[xinic][yinic]))
                {
                    saltoPieza=true;
                }
            }

        }
        if ((xfin-xinic+1<0)&&(yfin-yinic+1<0))
        {
            for (int i=1;i<=(-xfin+xinic)-1;i++)
            {
                if ((tablero[xinic-i][yinic-i]!="  ")&&(tablero[xinic-i][yinic-i]!=tablero[xinic][yinic]))
                {
                    saltoPieza=true;
                }
            }

        }
        if ((xfin-xinic-1>0)&&(yfin-yinic+1<0))
        {
            for (int i=1;i<=(+xfin-xinic)-1;i++)
            {
                if ((tablero[xinic+i][yinic-i]!="  ")&&(tablero[xinic+i][yinic-i]!=tablero[xinic][yinic]))
                {
                    saltoPieza=true;
                }
            }

        }
        if (saltoPieza==true)
        {
            i= false;
        }
        else
        {
            if (tablero[xfin][yfin][1]!=tablero[xinic][yinic][1])
            {
                i= true;
            }
        }
    }

    return i;
}

bool movReina(int xinic,int yinic,int xfin, int yfin){
    bool saltoPieza=false;
    bool i = false;
    i = movArfil(xinic, yinic, xfin, yfin);
    if (xinic==xfin)
    {
        if (yfin>yinic+1)
        {
            for (int i=yinic+1;i<=yfin-1;i++)
            {
                if (tablero[xinic][i]!="  ")
                {
                    saltoPieza=true;
                }
            }
        }
        if (yfin<yinic-1)
        {
            for (int i=yinic-1;i>=yfin+1;i--)
            {
                if (tablero[xinic][i]!="  ")
                {
                    saltoPieza=true;
                }
            }
        }
    }
    if (yinic==yfin)
    {
        if (xfin>xinic+1)
        {
            for (int i=xinic+1;i<=xfin-1;i++)
            {
                if (tablero[i][yinic]!="  ")
                {
                    saltoPieza=true;
                }
            }
        }
        if (xfin<xinic)
        {
            for (int i=xinic-1;i>=xfin+1;i--)
            {
                if (tablero[i][yinic]!="  ")
                {
                    saltoPieza=true;
                }
            }
        }
    }


    else if (tablero[xfin][yfin][1]!=tablero[xinic][yinic][1])
    {
        i= true;
    }
    return i;
}

bool casosEspeciales(string coordinic, string coordfin){
    bool ver= false;
    if (tablero[0][0]=="t1"&&tablero[1][0]=="  "&&tablero[2][0]=="  "&&tablero[3][0]=="  "&&tablero[4][0]=="k1"){
        tablero[c2i(coordinic[0])-2][c2i(coordinic[1])]=tablero[c2i(coordinic[0])][c2i(coordinic[1])];
        tablero[c2i(coordfin[0])+3][c2i(coordfin[1])]=tablero[c2i(coordfin[0])][c2i(coordfin[1])];
        tablero[c2i(coordinic[0])][c2i(coordinic[1])]="  ";
        tablero[c2i(coordfin[0])][c2i(coordfin[1])]="  ";
        ver = true;
    }else if(tablero[4][0]=="k1"&&tablero[5][0]=="  "&&tablero[6][0]=="  "&&tablero[7][0]=="t1"){
        tablero[c2i(coordinic[0])+2][c2i(coordinic[1])]=tablero[c2i(coordinic[0])][c2i(coordinic[1])];
        tablero[c2i(coordfin[0])-2][c2i(coordfin[1])]=tablero[c2i(coordfin[0])][c2i(coordfin[1])];
        tablero[c2i(coordinic[0])][c2i(coordinic[1])]="  ";
        tablero[c2i(coordfin[0])][c2i(coordfin[1])]="  ";
        ver = true;
    }else if (tablero[0][7]=="t2"&&tablero[1][7]=="  "&&tablero[2][7]=="  "&&tablero[3][7]=="  "&&tablero[4][7]=="k2"){
        tablero[c2i(coordinic[0])-2][c2i(coordinic[1])]=tablero[c2i(coordinic[0])][c2i(coordinic[1])];
        tablero[c2i(coordfin[0])+3][c2i(coordfin[1])]=tablero[c2i(coordfin[0])][c2i(coordfin[1])];
        tablero[c2i(coordinic[0])][c2i(coordinic[1])]="  ";
        tablero[c2i(coordfin[0])][c2i(coordfin[1])]="  ";
        ver = true;
    }else if(tablero[4][7]=="k2"&&tablero[5][7]=="  "&&tablero[6][7]=="  "&&tablero[7][7]=="t2"){
        tablero[c2i(coordinic[0])+2][c2i(coordinic[1])]=tablero[c2i(coordinic[0])][c2i(coordinic[1])];
        tablero[c2i(coordfin[0])-2][c2i(coordfin[1])]=tablero[c2i(coordfin[0])][c2i(coordfin[1])];
        tablero[c2i(coordinic[0])][c2i(coordinic[1])]="  ";
        tablero[c2i(coordfin[0])][c2i(coordfin[1])]="  ";
        ver = true;
    }else{
        ver=false;
    }

    return ver;
}
/*
bool movEnroque(int xinic,int yinic,int xfin, int yfin){
    bool ver= false;
    if (tablero[0][0]=="t1"&&tablero[1][0]==" "&&tablero[2][0]==" "&&tablero[3][0]==" "&&tablero[4][0]=="k1"&&tablero[5][0]==" "&&tablero[6][0]==" "&&tablero[7][0]=="t1"){
        if ((tablero[xinic][yinic] == "k1") || (tablero[xinic][yinic] == "k2")) {
            if ((tablero[xfin][yfin] == "t1") || (tablero[xfin][yfin] == "t2")) {
                tablero[xinic][yinic]=tablero[][c2i(coordinic[1])];
                tablero[c2i(coordinic[0])][c2i(coordinic[1])]="  ";
            }
        }
        ver = true;
    }else if(tablero[0][0]=="t1"&&tablero[1][0]=="c1"&&tablero[2][0]=="a1"&&tablero[3][0]=="q1"&&tablero[4][0]=="k1"&&tablero[5][0]==" "&&tablero[6][0]==" "&&tablero[7][0]=="t1"){
        ver = true;
    }else if(tablero[0][0]=="t1"&&tablero[1][0]==" "&&tablero[2][0]==" "&&tablero[3][0]==" "&&tablero[4][0]=="k1"&&tablero[5][0]=="a1"&&tablero[6][0]=="c1"&&tablero[7][0]=="t1"){
        ver = true;
    }else if (tablero[0][7]=="t2"&&tablero[1][7]==" "&&tablero[2][7]==" "&&tablero[3][7]==" "&&tablero[4][7]=="k2"&&tablero[5][7]==" "&&tablero[6][7]==" "&&tablero[7][7]=="t2"){
        ver = true;
    }else if(tablero[0][7]=="t2"&&tablero[1][7]=="c2"&&tablero[2][7]=="a2"&&tablero[3][7]=="q2"&&tablero[4][7]=="k2"&&tablero[5][7]==" "&&tablero[6][7]==" "&&tablero[7][7]=="t2"){
        ver = true;
    }else if(tablero[0][7]=="t2"&&tablero[1][7]==" "&&tablero[2][7]==" "&&tablero[3][7]==" "&&tablero[4][7]=="k2"&&tablero[5][7]=="a2"&&tablero[6][7]=="c2"&&tablero[7][7]=="t2"){
        ver = true;
    }else{
        ver=false;
    }

    return ver;
    if (casosEspeciales() == true){
        if ((tablero[xinic][yinic] == "k1") || (tablero[xinic][yinic] == "k2")){
            if ((tablero[xfin][yfin] == "t1") || (tablero[xfin][yfin] == "t2")){

                tablero[c2i(coordfin[0])][c2i(coordfin[1])]=tablero[c2i(coordinic[0])][c2i(coordinic[1])];
                tablero[c2i(coordinic[0])][c2i(coordinic[1])]="  ";
            }
        }
    }

}
*/
bool movimientoPieza (int xinic,int yinic,int xfin, int yfin)//, string tablero[8][8])
{
    bool i = false;
    if ((xinic == xfin) && (yinic == yfin)) {
        i = false;
    }
    if (tablero[xinic][yinic] == "p1" || tablero[xinic][yinic] == "p2") {
        i = movPeon(xinic, yinic, xfin, yfin);
    } else if ((tablero[xinic][yinic] == "t1") || (tablero[xinic][yinic] == "t2")) {
        i = movTorre(xinic, yinic, xfin, yfin);
    } else if ((tablero[xinic][yinic] == "a1") || (tablero[xinic][yinic] == "a2")) {
        i = movArfil(xinic, yinic, xfin, yfin);
    } else if ((tablero[xinic][yinic] == "q1") || (tablero[xinic][yinic] == "q2")) {
        i = movReina(xinic, yinic, xfin, yfin);
    } else if ((tablero[xinic][yinic] == "k1") || (tablero[xinic][yinic] == "k2")) {
        if ((abs(xfin - xinic) == 1) || (abs((yinic - yfin)) == 1)) {
            if (tablero[xfin][yfin][1] != tablero[xinic][yinic][1]) {
                i = true;
            }
        }
    }else if ((tablero[xinic][yinic]=="c1")||(tablero[xinic][yinic]=="c2")){
        if (((abs(xfin-xinic)==2)&&(abs(yinic-yfin)==1))||((abs(xfin-xinic)==1)&&(abs(yinic-yfin)==2))){
            if (tablero[xfin][yfin][1]!=tablero[xinic][yinic][1]){
                i= true;
            }
        }
    }
    return i;
}


void verificacion(string coord){
    bool verificacion1 = false;
    bool verificacion2 = false;

    do {
        for (int i = 0; i < 8; ++i) {
            if (coord[0] == letter[i]){
                verificacion1 = true;
            }
            if(coord[1] == number[i]){
                verificacion2=true;
            }
        }
        if (verificacion1 == false || verificacion2 == false) {
            cout << "La coordenada ingresada no es valida, ingrese una valida (entre A y H, entre 1 y 8)" << endl;
            cin >> coord;
        }
    }while(verificacion1==false||verificacion2==false);
}

void celdaInicial (string coordinic)
{
    bool turnoCorrecto=false;

    while (turnoCorrecto==false)
    {
        verificacion(coordinic);
        if (((tablero[c2i(coordinic[0])][c2i(coordinic[1])][1]=='1')&&(turno%2==0))
            ||((tablero[c2i(coordinic[0])][c2i(coordinic[1])][1]=='2')&&(turno%2!=0)))
        {
            turnoCorrecto=true;
        }
        else
        {
            turnoCorrecto=false;
        }
        if (turnoCorrecto==true)
        {
            cout<<"Ok, la pieza a mover en la coordenada especificada ("<<coordinic<<") sera: "
                <<tablero[c2i(coordinic[0])][c2i(coordinic[1])]<<endl;

        }
        else
        {
            cout<<"La celda seleccionada no contiene una pieza suya"<<endl;
        }
    }

}

void celdaFinal (string coordfin)
{
    bool turnoCorrecto=false;

    while (turnoCorrecto==false)
    {
        verificacion(coordfin);
        if (((tablero[c2i(coordfin[0])][c2i(coordfin[1])][1]=='1')&&(turno%2==0))
            ||((tablero[c2i(coordfin[0])][c2i(coordfin[1])][1]=='2')&&(turno%2!=0)))
        {
            turnoCorrecto=false;
            cout<<"No puedes comerte piezas aliadas"<<endl;
        }
        else
        {
            turnoCorrecto=true;
        }

    }
}

bool moverPieza(string coordinic, string coordfin)//string tablero[8][8])
{

    bool ver = false;
    bool ver2 = false;
    if (movimientoPieza(c2i(coordinic[0]),c2i(coordinic[1]),c2i(coordfin[0]),c2i(coordfin[1]))==true)
    {
        celdaInicial(coordinic);
        celdaFinal(coordfin);
        tablero[c2i(coordfin[0])][c2i(coordfin[1])]=tablero[c2i(coordinic[0])][c2i(coordinic[1])];
        tablero[c2i(coordinic[0])][c2i(coordinic[1])]="  ";
        file << tablero[c2i(coordfin[0])][c2i(coordfin[1])];
        ver = true;
    }else if(ver == false){
        ver2=casosEspeciales(coordinic,coordfin);
        if(ver2==true) {
            ver = true;
        }
    }
    else {

        ver = false;
    }
    return  ver;
}

bool juegoTerminado()
{
    bool ver=false;
    int i=0;
    for (int j=0;j<=7;j++)
    {
        for (int k=0;k<=7;k++)
        {
            if ((tablero[j][k]=="k1")||(tablero[j][k]=="k2"))
            {
                i++;
            }
        }
    }
    if (i==2)
    {
        ver= false;
    }
    else {
        ver = true;
    }
    return ver;
}


int main ()
{
    string coordinic;
    string coordfin;
    bool ver = false;
    int cont=1;
    iniciaTablero();
    impTablero();
    file.open("registro.txt");

    do
    {
        cout << "Se está jugando el turno #"<<cont<<endl;
        if (turno%2==0)
        {
            do {
                cout << " Jugador 1, ingrese la coordenada de la pieza que quiere jugar:" << endl;
                cin >> coordinic;
                cout << " Jugador 1, ingrese la coordenada donde quiere enviar la pieza:" << endl;
                cin >> coordfin;
                ver=moverPieza(coordinic, coordfin);
                if(ver==false){
                    cout << "Movimiento incorrecto" << c2i(coordfin[0]) << c2i(coordfin[1]) << c2i(coordinic[0])<< c2i(coordinic[1]) << endl;
                }
            }while(ver==false);
            file<<cont<<". ";
            file<<coordfin<<", ";
            impTablero();
        }
        if (turno%2!=0)
        {
            do {
                cout << " Jugador 2, ingrese la coordenada de la pieza que quiere jugar:" << endl;
                cin >> coordinic;
                cout << " Jugador 2, ingrese la coordenada donde quiere enviar la pieza:" << endl;
                cin >> coordfin;
                ver = moverPieza(coordinic, coordfin);
                if(ver==false){
                    cout << "Movimiento incorrecto" << c2i(coordfin[0]) << c2i(coordfin[1]) << c2i(coordinic[0])<< c2i(coordinic[1]) << endl;
                }
            }while(ver==false);
            impTablero();
            file<<coordfin<<"\n";
            cont++;
        }
        turno++;
    }while (juegoTerminado()==false);

    file.close();
    cout << "Gracias por jugar" << endl;

}