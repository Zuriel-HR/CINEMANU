#include "CINELIB.h"

using namespace std;

int main()
{
    srand(time(NULL));
    char c = 219; int Opcion; char Resp;
    Cine Est;

    /* 16-17 Nov*/
    Funciones Pelis[9]={Funciones("AVENGERS: END GAME", "99", "13:30", "1", "16-Noviembre-2019"),
                        Funciones("AVENGERS: END GAME", "99", "17:00", "1", "16-Noviembre-2019"),
                        Funciones("AVENGERS: END GAME", "99", "12:00", "2", "17-Noviembre-2019"),
                        Funciones(" 500 DIAS CON ELLA", "98", "13:30", "2", "17-Noviembre-2019"),
                        Funciones(" 500 DIAS CON ELLA", "98", "14:00", "3", "16-Noviembre-2019"),
                        Funciones(" 500 DIAS CON ELLA", "98", "18:30", "3", "17-Noviembre-2019"),
                        Funciones("   MENTE INDOMABLE", "91", "11:00", "2", "16-Noviembre-2019"),
                        Funciones("   MENTE INDOMABLE", "91", "14:00", "1", "16-Noviembre-2019"),
                        Funciones("   MENTE INDOMABLE", "91", "18:00", "2", "17-Noviembre-2019")};

    // INSERTAMOS LAS FUNCIONES EN EL TXT
    int i;
    FILE *Fun;
    if ((Fun = fopen("ARCHIVOS/FUNCIONES.txt", "r")) == NULL){
        for (i=0;i<9;i++){
        string Text;
        Text = Pelis[i].getInformacion();
        Pelis[i].InsertarTxT(Text,i);
        }
    } fclose(Fun);

    // INICIALIAMOS LAS SALAS A 10 LUGARES COMO INICIO
    for (i=0;i<9;i++){
    Pelis[i].IniciarSala();
    }

    Vendedor Ven[2]={Vendedor("MIGUEL AGUILERA",18,0),
                     Vendedor("ITZEL CABRERA",18,0) };

    // INSERTAMOS LA INFO DE LOS VENDEDORES EN EL TXT
    FILE *Tra;
    if ((Tra = fopen("ARCHIVOS/VENDEDORES.txt", "r")) == NULL){
        for (i=0;i<2;i++){
        string Text;
        Text = Ven[i].get_Ganancias(); // AUN NO ESTAN
        Ven[i].InsertarTxT(Text,i);
        }
    }  fclose(Tra);


    //MENU INICIAL
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    int Num_Ven;
    Num_Ven = ValidarVen();
    int P,No_P,No_F;
    float Din;

    do{
        system("COLOR 0B");
        system("cls");
        fflush(stdin);
        int x,y;
        SetConsoleTextAttribute(H,7);
        for(x=0;x<85;x++){gotoxy(x,0); cout<<c;}
        //for(y=0;y<20;y++){gotoxy(0,y); cout<<c;gotoxy(89,y); cout<<c;}
        cout<<"\n\n                      __________  ________  ______   _  ____  __\n";
        cout<<"                     / ___/  _/ |/ / __/  |/  / _ | / |/ / / / /\n";
        cout<<"                    / /___/ //    / _// /|_/ / __ |/    / /_/ / \n";
        cout<<"                    \\___/___/_/|_/___/_/  /_/_/ |_/_/|_/\\____/ \n\n";
        SetConsoleTextAttribute(H,11);
        cout<<"                     "<<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<endl;
        cout<<"                     "<<c<<"          1.- VER CARTELERA           "<<c<<endl;
        cout<<"                     "<<c<<"          2.- VER GANANCIAS           "<<c<<endl;
        cout<<"                     "<<c<<"          3.- VER TRAILER             "<<c<<endl;
        cout<<"                     "<<c<<"          4.- CONSULTAR FUNCION       "<<c<<endl;
        cout<<"                     "<<c<<"          5.- COMPRAR BOLETOS         "<<c<<endl;
        cout<<"                     "<<c<<"          6.- CERRAR SESION           "<<c<<endl;
        cout<<"                     "<<c<<"          7.- SALIR                   "<<c<<endl;
        cout<<"                     "<<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<endl;
        fflush(stdin);
        cout<<"\n                                   TECLEE OPCION: ";    cin>>Opcion;
        cout<<"\n";
        switch(Opcion){
            case 1:
                Est.VerFunciones();
                break;
            case 2:
                Ven[Num_Ven].Ver_Ganancias(Ven[Num_Ven].getNombre());
                break;
            case 3:
                Ven[Num_Ven].Reproducir_Trailer();
                break;
            case 4:
                Est.VerFunciones();
                Pelis[Est.NoFun()].MostrarSala();
                break;
            case 5:
                No_P = Est.FiltrarPelicula();
                No_F = Ven[Num_Ven].Selec_Funcion(No_P);
                Din = Pelis[No_F].Vender_Boletos();
                Ven[Num_Ven].set_Ganancias(Din);
                FILE *Tra;
                if ((Tra = fopen("ARCHIVOS/VENDEDORES.txt", "w")) == NULL){
                }
                for (i=0;i<2;i++){
                    string Text;
                    Text = Ven[i].get_Ganancias();
                    Ven[i].InsertarTxT(Text,i);
                }fclose(Tra);
                break;
            case 6:
                Num_Ven = ValidarVen();
                break;
            case 7:
                exit(0);
                break;
            default:
                system ("COLOR 0C");
                cout<< "\n                              OPCION NO VALIDA"<<endl;
        }
        cout<<"\n                          ¿DESEA REGRESAR AL MENU? (S/N) "; cin>>Resp; cout<<"\n";
        Resp=toupper(Resp);
    }while (Resp!='N');

    getchar();
    return 0;

}
