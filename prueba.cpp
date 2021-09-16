#include <iostream>
#include <string>
#include <cstdlib>

using namespace::std;
string tablero[8][8];
string piezas1[6]={"p1", "t1", "c1", "a1", "q1", "k1"};
string piezas2[6]={"p2", "t2", "c2", "a2", "q2", "k2"};
char number[8]={'1','2','3','4','5','6','7','8'};
char letter[8]={'a','b','c','d','e','f','g','h'};
int turno=0;



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



bool movimientoPieza (int xinic,int yinic,int xfin, int yfin)//, string tablero[8][8])
{
    bool saltoPieza=false;
    int a;
    if ((xinic==xfin)&&(yinic==yfin))
    {
        return false;
    }
    if (tablero[xinic][yinic]=="p1")
    {
        a=0;
        if (xinic==xfin)
        {
            if (((yinic+1==yfin)||(yinic-1==yfin))
                &&(tablero[xinic][yfin][1]!='2'))
            {
                a++;
            }
            if (((yinic+2==yfin)&&(xinic==xfin))
                &&(yinic=1)
                &&(tablero[xinic][yfin][1]!='2')&&(tablero[xinic][yinic+1]=="  "))
            {
                a++;
            }
            if (a>0)
            {
                if (tablero[xfin][yfin][1]!=tablero[xinic][yinic][1])
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }

        if (((xinic+1==xfin)||(xinic-1==xfin))&&(yinic=yfin-1)&&(tablero[xfin][yfin][1]=='2'))
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    if (tablero[xinic][yinic]=="p2")
    {
        a=0;
        if (xinic==xfin)
        {
            if (((yinic+1==yfin)||(yinic-1==yfin))
                &&(tablero[xinic][yfin][1]!='1'))
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
                    return true;
                }
            }
            else
            {
                return false;
            }
        }

        if (((xinic+1==xfin)||(xinic-1==xfin))&&(yinic=yfin+1)&&(tablero[xfin][yfin][1]=='1'))
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    if ((tablero[xinic][yinic]=="t1")||(tablero[xinic][yinic]=="t2"))
    {
        saltoPieza=false;
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
                return true;
            }
        }
        else
        {
            return false;
        }
    }

    if ((tablero[xinic][yinic]=="a1")||(tablero[xinic][yinic]=="a2"))
    {
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
                return false;
            }
            else
            {
                if (tablero[xfin][yfin][1]!=tablero[xinic][yinic][1])
                {
                    return true;
                }
            }
        }
        else
        {
            return false;
        }
    }
    if ((tablero[xinic][yinic]=="q1")||(tablero[xinic][yinic]=="q2"))
    {
        saltoPieza=false;
        if (abs((xfin-xinic))==abs((yinic-yfin))||(xinic==xfin)||(yinic==yfin))
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

            if (saltoPieza=true)
            {
                return false;
            }
            else
            {
                if (tablero[xfin][yfin][1]!=tablero[xinic][yinic][1])
                {
                    return true;
                }
            }
        }
        else
        {
            return false;
        }
    }
    if ((tablero[xinic][yinic]=="k1")||(tablero[xinic][yinic]=="k2"))
    {
        if ((abs(xfin-xinic)==1)||(abs((yinic-yfin))==1))
        {
            if (tablero[xfin][yfin][1]!=tablero[xinic][yinic][1])
            {
                return true;
            }
        }
        else
            return false;
    }
    if ((tablero[xinic][yinic]=="c1")||(tablero[xinic][yinic]=="c2"))
    {
        if (((abs(xfin-xinic)==2)&&(abs(yinic-yfin)==1))||((abs(xfin-xinic)==1)&&(abs(yinic-yfin)==2)))
        {
            if (tablero[xfin][yfin][1]!=tablero[xinic][yinic][1])
            {
                return true;
            }
        }
        else
        {
            return false;
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

void celdaInicial (char *celdInicLet, char *celdInicNum)//, string tablero[8][8])
{
    bool turnoCorrecto=false;
    while (turnoCorrecto==false)
    {
        cout<<"Ingrese letra de celda a mover"<<endl;
        cin>>*celdInicLet;
        while (*celdInicLet != 'A'&&*celdInicLet != 'B'&&*celdInicLet != 'C'&&*celdInicLet != 'D'&&*celdInicLet != 'E'&&
               *celdInicLet != 'F'&&*celdInicLet != 'G'&&*celdInicLet != 'H'&&*celdInicLet != 'a'&&*celdInicLet != 'b'&&*celdInicLet != 'c'&&
               *celdInicLet != 'd'&&*celdInicLet != 'e'&&*celdInicLet != 'f'&&*celdInicLet != 'g'&&*celdInicLet != 'h')
        {
            cout<<"La celda ingresada no es valida, ingrese letra de celda entre A y H"<<endl;
            cin>>*celdInicLet;
        }
        cout<<"Ingrese numero de celda para mover pieza (1-8)"<<endl;
        cin>>*celdInicNum;
        while (*celdInicNum != '1'&&*celdInicNum != '2'&&*celdInicNum != '3'&&*celdInicNum != '4'&&*celdInicNum != '5'&&
               *celdInicNum != '6'&&*celdInicNum != '7'&&*celdInicNum != '8')
        {
            cout<<"La celda ingresada no es valida, ingrese un numero entre 1 y 8"<<endl;
            cin>>*celdInicNum;
        }
        if (((tablero[c2i(*celdInicLet)][c2i(*celdInicNum)][1]=='1')&&(turno%2==0))
            ||((tablero[c2i(*celdInicLet)][c2i(*celdInicNum)][1]=='2')&&(turno%2!=0)))
        {
            turnoCorrecto=true;
        }
        else
        {
            turnoCorrecto=false;
        }
        if (turnoCorrecto==true)
        {
            cout<<"Ok, la celda de la pieza a mover sera: "<<*celdInicLet<<*celdInicNum<<endl;
            cout<<"La coordenada especificada ("<<*celdInicLet<<*celdInicNum<<") tiene la pieza "
                <<tablero[c2i(*celdInicLet)][c2i(*celdInicNum)]<<endl;

        }
        else
        {
            cout<<"La celda seleccionada no contiene una pieza suya"<<endl;
        }
    }
}

void celdaFinal (char *celdFinLet, char *celdFinNum)//, string tablero[8][8])
{
    bool turnoCorrecto=false;

    while (turnoCorrecto==false)
    {
        cout<<"Ingrese letra de celda destino"<<endl;
        cin>>*celdFinLet;

        while (*celdFinLet != 'A'&&*celdFinLet != 'B'&&*celdFinLet != 'C'&&*celdFinLet != 'D'&&*celdFinLet != 'E'&&
               *celdFinLet != 'F'&&*celdFinLet != 'G'&&*celdFinLet != 'H'&&*celdFinLet != 'a'&&*celdFinLet != 'b'&&*celdFinLet != 'c'&&
               *celdFinLet != 'd'&&*celdFinLet != 'e'&&*celdFinLet != 'f'&&*celdFinLet != 'g'&&*celdFinLet != 'h')
        {
            cout<<"La celda ingresada no es valida, ingrese letra de celda entre A y H"<<endl;
            cin>>*celdFinLet;
        }
        cout<<"Ingrese numero de celda destino (1-8)"<<endl;
        cin>>*celdFinNum;
        while (*celdFinNum != '1'&&*celdFinNum != '2'&&*celdFinNum != '3'&&*celdFinNum != '4'&&*celdFinNum != '5'&&
               *celdFinNum != '6'&&*celdFinNum != '7'&&*celdFinNum != '8')
        {
            cout<<"La celda ingresada no es valida, ingrese un numero entre 1 y 8"<<endl;
            cin>>*celdFinNum;
        }
        if (((tablero[c2i(*celdFinLet)][c2i(*celdFinNum)][1]=='1')&&(turno%2==0))
            ||((tablero[c2i(*celdFinLet)][c2i(*celdFinNum)][1]=='2')&&(turno%2!=0)))
        {
            turnoCorrecto=false;
            cout<<"No puedes comerte piezas aliadas"<<endl;
        }
        else
        {
            turnoCorrecto=true;
        }
        if (turnoCorrecto==true)
        {
            cout<<"Ok, la celda destino sera: "<<*celdFinLet<<*celdFinNum<<endl;
        }
    }
}

void moverPieza()//string tablero[8][8])
{
    char celdInicLet='z';
    char celdInicNum='z';
    char celdFinLet='z';
    char celdFinNum='z';
    char verificador='z';

    while (verificador!='s')
    {
        celdaInicial(&celdInicLet,&celdInicNum);//,tablero);
        celdaFinal(&celdFinLet,&celdFinNum);// tablero);
        cout<<"Esta seguro que desea mover su "<<tablero[c2i(celdInicLet)][c2i(celdInicNum)]<<" a "<<celdFinLet<<celdFinNum<<"? (s/n)"<<endl;
        cin>>verificador;
        while (verificador!='s'&&verificador!='n')
        {
            cout<<"Ingrese opcion correcta"<<endl;
            cin>>verificador;
        }
    }
    if (movimientoPieza(c2i(celdInicLet),c2i(celdInicNum),c2i(celdFinLet),c2i(celdFinNum)))//,tablero))
    {
        tablero[c2i(celdFinLet)][c2i(celdFinNum)]=tablero[c2i(celdInicLet)][c2i(celdInicNum)];
        tablero[c2i(celdInicLet)][c2i(celdInicNum)]="  ";
        //turno=turno*(-1);
    }
    else
        cout<<"Movimiento incorrecto"<<c2i(celdFinLet)<<c2i(celdFinNum)<<c2i(celdInicLet)<<c2i(celdInicNum)<<endl;

}

bool juegoTerminado()//string tablero[8][8])
{
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
        return false;
    }
    else
        return true;
}
int valorPieza(int x, int y)//, string tablero[8][8])
{
    switch (tablero[x][y][0])
    {
        case 'p': return 1;
            break;
        case 't': return 5;
            break;
        case 'c': return 4;
            break;
        case 'a': return 4;
            break;
        case 'q': return 12;
            break;
        case 'k': return 1000;
            break;
        case ' ': return 0;
            break;
    }
}
int valorMaxArray(int arreglo[40],int* cantJugadas)
{
    int max=arreglo[0];
    for (int i=1;i<=*cantJugadas;i++)
    {
        if (max<arreglo[i])
        {
            max=arreglo[i];
        }
    }
    return max;
}
int numAleatorio07()
{
    return (rand()%8);
}

/*
void algoritmoShuperLoco()//string tablero[8][8])  // ACA EL ALGORITMOOOOOO
{


    int valorJugada1;
    int mejoresJugadas[40];
    int contadorJugadasTotales=0;
    int mejorJugada1[4];
    int sdaMejorJugada1[4];
    int valorSegundaMejorJugada;
    int contadorJugadasTotales2=0;
    for (int i=0;i<=7;i++)
    {
        for (int j=0;j<=7;j++)
        {
            for (int iDest=0;iDest<=7;iDest++)
            {
                for (int jDest=0;jDest<=7;jDest++)
                {
                    if ((movimientoPieza(i,j,iDest,jDest))&&(tablero[i][j][1]=='2'))
                    {
                        valorJugada1=valorPieza(iDest,jDest);
                        contadorJugadasTotales++;
                        mejoresJugadas[contadorJugadasTotales-1]=valorJugada1;
                    }
                }
            }
        }
    }
    for (int i=0;i<=7;i++)
    {
        for (int j=0;j<=7;j++)
        {
            for (int iDest=0;iDest<=7;iDest++)
            {
                for (int jDest=0;jDest<=7;jDest++)
                {
                    if ((movimientoPieza(i,j,iDest,jDest))&&(tablero[i][j][1]=='2'))
                    {
                        if (valorPieza(iDest,jDest)==
                            valorMaxArray(mejoresJugadas,&contadorJugadasTotales))
                        {
                            mejorJugada1[0]=i;
                            mejorJugada1[1]=j;
                            mejorJugada1[2]=iDest;
                            mejorJugada1[3]=jDest;
                        }


                    }
                }
            }
        }
    }


    for (int i=0;i<=7;i++)
    {
        for (int j=0;j<=7;j++)
        {
            for (int iDest=0;iDest<=7;iDest++)
            {
                for (int jDest=0;jDest<=7;jDest++)
                {
                    if ((movimientoPieza(i,j,iDest,jDest))&&((i!=mejorJugada1[0])||(j!=mejorJugada1[1])||
                                                                     (iDest!=mejorJugada1[2])||(jDest!=mejorJugada1[3]))&&(tablero[i][j][1]=='2'))
                    {
                        valorJugada1=valorPieza(iDest,jDest);
                        contadorJugadasTotales2++;
                        mejoresJugadas[contadorJugadasTotales2-1]=valorJugada1;
                    }
                }
            }
        }
    }
    for (int i=0;i<=7;i++)
    {
        for (int j=0;j<=7;j++)
        {
            for (int iDest=0;iDest<=7;iDest++)
            {
                for (int jDest=0;jDest<=7;jDest++)
                {
                    if ((movimientoPieza(i,j,iDest,jDest))&&(tablero[i][j][1]=='2'))
                    {
                        if (valorPieza(iDest,jDest)==
                            valorMaxArray(mejoresJugadas,&contadorJugadasTotales2))
                        {
                            sdaMejorJugada1[0]=i;
                            sdaMejorJugada1[1]=j;
                            sdaMejorJugada1[2]=iDest;
                            sdaMejorJugada1[3]=jDest;
                            valorSegundaMejorJugada=valorMaxArray(mejoresJugadas,&contadorJugadasTotales2);
                        }


                    }
                }
            }
        }
    }
    //Ver cuanto se pierde si el oponente hace la mejor jugada posible con cada jugada
    //Caso 1: Hacer la mejor jugada posible (la que come la pieza de mayor puntaje)

    int valorJugada1Op;
    int mejoresJugadasOp[40];
    int contadorJugadasTotalesOp=0;
    int contadorJugadasTotalesOp2=0;
    int mejorJugada1Op[4];
    int valorJugadaTotal1;
    int valorJugadaTotal2;
    string loQueHabiaFin, loQueHabiaInic;
    turno=turno*-1;
    loQueHabiaFin=tablero[mejorJugada1[2]][mejorJugada1[3]];
    loQueHabiaInic=tablero[mejorJugada1[0]][mejorJugada1[1]];

    tablero[mejorJugada1[2]][mejorJugada1[3]]=tablero[mejorJugada1[0]][mejorJugada1[1]];
    tablero[mejorJugada1[0]][mejorJugada1[1]]="  ";
    for (int i=0;i<=7;i++)
    {
        for (int j=0;j<=7;j++)
        {
            for (int iDest=0;iDest<=7;iDest++)
            {
                for (int jDest=0;jDest<=7;jDest++)
                {
                    if ((movimientoPieza(i,j,iDest,jDest))&&(tablero[i][j][1]=='1'))
                    {
                        valorJugada1Op=valorPieza(iDest,jDest);
                        contadorJugadasTotalesOp++;
                        mejoresJugadasOp[contadorJugadasTotalesOp-1]=valorJugada1Op;
                    }
                }
            }
        }
    }
    for (int i=0;i<=7;i++)
    {
        for (int j=0;j<=7;j++)
        {
            for (int iDest=0;iDest<=7;iDest++)
            {
                for (int jDest=0;jDest<=7;jDest++)
                {
                    if ((movimientoPieza(i,j,iDest,jDest))&&(tablero[i][j][1]=='1'))
                    {
                        if (valorPieza(iDest,jDest)==
                            valorMaxArray(mejoresJugadasOp,&contadorJugadasTotalesOp))
                        {
                            mejorJugada1Op[0]=i;
                            mejorJugada1Op[1]=j;
                            mejorJugada1Op[2]=iDest;
                            mejorJugada1Op[3]=jDest;
                        }
                    }
                }
            }
        }
    }

    valorJugadaTotal1=valorMaxArray(mejoresJugadas,&contadorJugadasTotales)
                      -valorMaxArray(mejoresJugadasOp,&contadorJugadasTotalesOp);

    tablero[mejorJugada1[2]][mejorJugada1[3]]=loQueHabiaFin;
    tablero[mejorJugada1[0]][mejorJugada1[1]]=loQueHabiaInic;
    tablero[sdaMejorJugada1[2]][sdaMejorJugada1[3]]=tablero[sdaMejorJugada1[0]][sdaMejorJugada1[1]];
    tablero[sdaMejorJugada1[0]][sdaMejorJugada1[1]]="  ";
    for (int i=0;i<=7;i++)
    {
        for (int j=0;j<=7;j++)
        {
            for (int iDest=0;iDest<=7;iDest++)
            {
                for (int jDest=0;jDest<=7;jDest++)
                {
                    if (movimientoPieza(i,j,iDest,jDest))
                    {
                        valorJugada1Op=valorPieza(iDest,jDest);
                        contadorJugadasTotalesOp2++;
                        mejoresJugadasOp[contadorJugadasTotalesOp2-1]=valorJugada1Op;
                    }
                }
            }
        }
    }
    for (int i=0;i<=7;i++)
    {
        for (int j=0;j<=7;j++)
        {
            for (int iDest=0;iDest<=7;iDest++)
            {
                for (int jDest=0;jDest<=7;jDest++)
                {
                    if ((movimientoPieza(i,j,iDest,jDest))&&(tablero[i][j][1]=='1'))
                    {
                        if (valorPieza(iDest,jDest)==
                            valorMaxArray(mejoresJugadasOp,&contadorJugadasTotalesOp2))
                        {
                            mejorJugada1Op[0]=i;
                            mejorJugada1Op[1]=j;
                            mejorJugada1Op[2]=iDest;
                            mejorJugada1Op[3]=jDest;
                        }
                    }
                }
            }
        }
    }
    int a=1;
    int numAleatorio1,numAleatorio2,numAleatorio3,numAleatorio4;
    valorJugadaTotal2=valorSegundaMejorJugada-valorMaxArray(mejoresJugadasOp,&contadorJugadasTotalesOp2);
    tablero[mejorJugada1[2]][mejorJugada1[3]]=loQueHabiaFin;
    tablero[mejorJugada1[0]][mejorJugada1[1]]=loQueHabiaInic;
    int contadorDeEmergencia=0;
    if (valorJugadaTotal2!=valorJugadaTotal1)
    {
        if (valorJugadaTotal1>valorJugadaTotal2)
        {
            tablero[mejorJugada1[2]][mejorJugada1[3]]=tablero[mejorJugada1[0]][mejorJugada1[1]];
            tablero[mejorJugada1[0]][mejorJugada1[1]]="  ";
        }
        else
        {
            tablero[sdaMejorJugada1[2]][sdaMejorJugada1[3]]=tablero[sdaMejorJugada1[0]][sdaMejorJugada1[1]];
            tablero[sdaMejorJugada1[0]][sdaMejorJugada1[1]]="  ";
        }
    }
    else
    {
        if (tablero[mejorJugada1[2]][mejorJugada1[3]]!=tablero[mejorJugada1[0]][mejorJugada1[1]])
        {
            tablero[mejorJugada1[2]][mejorJugada1[3]]=tablero[mejorJugada1[0]][mejorJugada1[1]];
            tablero[mejorJugada1[0]][mejorJugada1[1]]="  ";
        }
        else
        {
            //algoritmoDeMovimientoAleatorio(tablero)
            while (a!=0)
            {
                numAleatorio1=numAleatorio07();
                numAleatorio2=numAleatorio07();
                numAleatorio3=numAleatorio07();
                numAleatorio4=numAleatorio07();

                if (movimientoPieza(numAleatorio1,numAleatorio2,numAleatorio3,numAleatorio4))
                {
                    a=0;
                    tablero[numAleatorio1][numAleatorio2]=tablero[numAleatorio3][numAleatorio4];
                    tablero[numAleatorio1][numAleatorio2]=tablero[numAleatorio3][numAleatorio4];
                }
                else
                {
                    contadorDeEmergencia++;
                }
                if (contadorDeEmergencia>2500)
                {
                    break;
                    cout<<endl<<"Se uso salida de emergencia del algorimo de movimiento aleatorio"<<endl;
                }

            }
        }

    }
    turno=turno*-1;
}
*/

int main ()
{
    //string tablero[8][8];  //definición de tablero

  /*  llenado_de_tablerop1();
    llenado_de_tablerop2();*/
    iniciaTablero();
    impTablero(/*tablero*/);

    while (juegoTerminado(/*tablero*/)==false)
    {
        if (turno%2==0)
        {
            moverPieza(/*tablero*/);
            impTablero(/*tablero*/);
        }
        if (turno%2!=0)
        {
            //algoritmoShuperLoco(/*tablero*/);
            moverPieza();
            impTablero(/*tablero*/);
            //turno=turno*-1;
        }
        turno++;
    }

    int noTeCierres;
    cin>>noTeCierres;

}