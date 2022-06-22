#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <sstream>
#include <time.h>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// FUNCIONES EXTRAS
void text_animation(char a[100]){

    int i;
    double k;

    for(i=0;a[i]!='\0';++i){
        for(k=0;k<3000000;++k);
        printf("%c",a[i]);
    }

}

int ValidarVen(){

    int CODIGO, x;

    for(x=0;x<3;x++){
        system("cls");
        system("COLOR 0B");
        system("mode con: cols=50 lines=9");
        text_animation("            __   ____  _____  _____  __\n");
        text_animation("           / /  / __ \\/ ___/ /  _/ |/ /\n");
        text_animation("          / /__/ /_/ / (_ / _/ //    / \n");
        text_animation("         /____/\\____/\\___/ /___/_/|_/  \n");
        cout<< "\n      INGRESE SU CODIGO DE VENDEDOR: ";
        cin >> CODIGO;

        if (CODIGO == 1234){ system("mode con: cols=85 lines=20"); return 0;}
        if (CODIGO == 5678){ system("mode con: cols=85 lines=20"); return 1;}
        if (CODIGO != 1234 && CODIGO != 5678){
            system("COLOR 0C");
            cout << "     CODIGO INVALIDO " << (3-(x+1)) << " INTENTOS RESTANTES" <<endl;
            Sleep(1500);
        }
    }

    cout <<"INTENTOS AGOTADOS";
    getchar();
    exit(0);

}

string ConvertToString (float number){

    std::ostringstream buff;
    buff<<number;
    return buff.str();

}

 void gotoxy(int x,int y){

    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);

 }

// CLASE CINE
class Cine{

    protected:
    string Direccion;
	string Nombre_Cine;

	public:
    Cine();
    void VerFunciones();
    int FiltrarPelicula();
    int NoFun();

};

Cine::Cine(){

    Direccion = "MEXICO, CDMX, COYOACAN";
    Nombre_Cine = "CINEMANU";

}

void Cine::VerFunciones(){

    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    SetConsoleTextAttribute(H,7); int x; char c = 219;
    for(x=0;x<85;x++){gotoxy(x,0); cout<<c;}
    cout<<"\n                       ______  ___  _______________  _  __________\n";
    cout<<"                      / __/ / / / |/ / ___/  _/ __ \\/ |/ / __/ __/\n";
    cout<<"                     / _// /_/ /    / /___/ // /_/ /    / _/_\\ \\  \n";
    cout<<"                    /_/  \\____/_/|_/\\___/___/\\____/_/|_/___/___/ ";
    cout<<"\n\n\n\n";
    SetConsoleTextAttribute(H,11);
    char CADENA[1000];
    FILE *archivo;
    if ((archivo = fopen("ARCHIVOS/FUNCIONES.txt", "rb")) == NULL){
        fprintf(stderr,"NO SE PUEDE ABRIR EL ARCHIVO");
        exit(0);
    }
    fread(&CADENA,sizeof(CADENA),1,archivo);
    cout << CADENA;
    fclose(archivo);

}

int Cine::FiltrarPelicula(){

    int No_P, x;
    char c = 219;
    string Nom_P;

    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    SetConsoleTextAttribute(H,7);
    for(x=0;x<85;x++){gotoxy(x,0); cout<<c; }
    cout<<"\n\n                      __________  ________  ______   _  ____  __\n";
    cout<<"                     / ___/  _/ |/ / __/  |/  / _ | / |/ / / / /\n";
    cout<<"                    / /___/ //    / _// /|_/ / __ |/    / /_/ / \n";
    cout<<"                    \\___/___/_/|_/___/_/  /_/_/ |_/_/|_/\\____/ \n\n";
    SetConsoleTextAttribute(H,11);
    cout<<"                          "<<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c<<c <<c<< c <<c<< c <<c<< c<<endl;
    cout<<"                          "<<c<<"     1.- END GAME            " << c <<endl;
    cout<<"                          "<<c<<"     2.- 500 DIAS CON ELLA   " << c <<endl;
    cout<<"                          "<<c<<"     3.- MENTE INDOMABLE     " << c << endl;
    cout<<"                          "<<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c<<c <<c<< c <<c<< c <<c<< c<<endl;
    cout << "\n                                 TECLEE NO. PELICULA: "; cin >> No_P;

    if ( No_P == 1 ){
        Nom_P = "END GAME"; int Index;
        string Linea;
        ifstream Archivo;
        Archivo.open("ARCHIVOS/FUNCIONES.txt");
        if (Archivo.is_open()){
            while (!Archivo.eof()){
                getline(Archivo,Linea);
                if ((Index = Linea.find(Nom_P,0)) != string::npos){
                    cout << "\n" << Linea;
                }
            }
            Archivo.close();
        }
    }

    if ( No_P == 2 ){
        Nom_P = "500 DIAS CON ELLA"; int Index;
        string Linea;
        ifstream Archivo;
        Archivo.open("ARCHIVOS/FUNCIONES.txt");
        if (Archivo.is_open()){
            while (!Archivo.eof()){
                getline(Archivo,Linea);
                if ((Index = Linea.find(Nom_P,0)) != string::npos){
                    cout << "\n" << Linea;
                }
            }
            Archivo.close();
        }
    }

    if ( No_P == 3 ){
        Nom_P = "MENTE INDOMABLE";int Index;
        string Linea;
        ifstream Archivo;
        Archivo.open("ARCHIVOS/FUNCIONES.txt");
        if (Archivo.is_open()){
            while (!Archivo.eof()){
                getline(Archivo,Linea);
                if ((Index = Linea.find(Nom_P,0)) != string::npos){
                    cout << "\n" << Linea;
                }
            }
            Archivo.close();
        }
    }

    if ( No_P > 3 || No_P<1) {system("COLOR 0C");cout << "\n                                   OPCION INVALIDA";}
    return No_P;

}

int Cine::NoFun(){

    int No_Fun;

    cout << "\n                                   SELECCIONE EL NUMERO DE LA FUNCION: ";
    fflush(stdin);
    cin >> No_Fun;
    if(No_Fun>9 || No_Fun<1){system("COLOR 0C"); cout<< "\n                                   OPCION INVALIDA"; Sleep(1500); exit(0);}
    No_Fun--;
    return No_Fun;

}

// CLASE FUNCIONES
class Funciones{

    bool Sala[40];
    string Nombre_Pelicula;
    string Duracion;
    string Horario;
    string No_Sala;
    string Fecha;

    public:
    Funciones(string N_Peli, string Dur, string Hor, string Sal, string Fec);
    string getInformacion();
    void InsertarTxT(string Func,int indx);
    void IniciarSala();
    void MostrarSala();
    float Vender_Boletos();

};

Funciones::Funciones(string N_Peli, string Dur, string Hor, string Sal, string Fec){

    Nombre_Pelicula= N_Peli;
    Duracion=Dur;
    Horario=Hor;
    No_Sala = Sal;
    Fecha = Fec;

}

string Funciones::getInformacion(){

    string Info;
    Info = Nombre_Pelicula + "  /  " + Duracion + " MIN    HORARIO: " + Horario + "   " + Fecha + "  SALA: " + No_Sala + "  \n";

    return Info;

}

void Funciones::InsertarTxT(string Func,int indx){

    FILE *archivo;
    indx++;
    string Escribir = ConvertToString(indx) + ".- " +  Func;
    string s(Escribir);
    char c[s.length()];

    int i;
    for (i = 0; i < sizeof(c); i++) {
        c[i] = s[i];
    }
    if ((archivo = fopen("ARCHIVOS/FUNCIONES.txt", "at")) == NULL){
        fprintf(stderr,"                                   NO SE PUEDE ABRIR EL ARCHIVO");
        exit(0);
    }
    fwrite(&c, sizeof(c),1,archivo);
    fclose(archivo);

}

void Funciones::IniciarSala(){

    int x,P; int Cont = 0;

    for (x = 0; x < 40; x++){Sala[x] = true;}
    do
    {
        P = rand()%40;
        if(Sala[P] == true){Sala[P] = false; Cont++;}
    } while (Cont < 10);

}

void Funciones::MostrarSala(){

    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    SetConsoleTextAttribute(H,7); int x; char c = 219;
    for(x=0;x<85;x++){gotoxy(x,0); cout<<c; }
    cout<<"\n                           _______   __   ___ \n";
    cout<<"                          / __/ _ | / /  / _ |\n";
    cout<<"                         _\\ \\/ __ |/ /__/ __ |\n";
    cout<<"                        /___/_/ |_/____/_/ |_|\n\n";

    int i;
    for (i = 0 ; i <40; i++){
        if( i==8 || i==16 || i==24 || i==32 || i==40 ){cout<<"\n\n";}
        if (Sala[i] == false) {
            SetConsoleTextAttribute(H,12);
            printf(" | ## | ");
        }
        if (Sala[i] == true) {
            SetConsoleTextAttribute(H,10);
            printf(" | %.2d | ",i+1);
        }
    }
    gotoxy(65,6); SetConsoleTextAttribute(H, 12); cout << c << " OCUPADO" << endl;
    gotoxy(65,8); SetConsoleTextAttribute(H, 10); cout << c << " DESOCUPADO";
    SetConsoleTextAttribute(H,15);
    for(x=0;x<63;x++){gotoxy(x,16); cout<<c;} cout << " <- PANTALLA";
    cout<<"\n"; SetConsoleTextAttribute(H,7);

}

float Funciones::Vender_Boletos(){

    HANDLE H = GetStdHandle( STD_OUTPUT_HANDLE );
    float Dinero;
    system("cls");
    int nBoletos;
    SetConsoleTextAttribute(H, 7);
    cout<<"\n                         CUANTOS BOLETOS DESEA COMPRAR: ";
    cin>>nBoletos;
    int x; int Cont = 0;
    for (x=0;x<40;x++){if(Sala[x]==true){Cont++;}}
    if (nBoletos>Cont){
        system("COLOR 0C");
        cout<<"\n                      NO HAY ESE NUMERO DE BOLETOS DISPONIBLES ";
    } else {
        int c,nAsiento;
        for(c=0;c<nBoletos;c++){
            for(;;){
                system("cls");
                MostrarSala();
                SetConsoleTextAttribute(H, 7);
                fflush(stdin);
                cout<<"\n                          INGRESE EL NUMERO DEL ASIENTO ["<<c+1<<"] :";
                cin>>nAsiento;
                if (Sala[nAsiento-1]==false){ SetConsoleTextAttribute(H,12); system("COLOR 0C"); cout<<"\n                          ASIENTO OCUPADO"; Sleep(500);}
                if (Sala[nAsiento-1]==true){ Sala[nAsiento-1]=false; SetConsoleTextAttribute(H,11); system("cls");
                MostrarSala(); cout<<"\n                          ASIENTO ASIGNADO"; Sleep(500); break;}
            }
        } Dinero = nBoletos*75.25;
    }
    return Dinero;

}

// CLASE VENDEDOR
class Vendedor{

	string Nombre;
	int Edad;
	float Ventas;

	public:
	Vendedor(string Nom, int Eda,int Vent);
	void Reproducir_Trailer();
	string get_Ganancias();
	void InsertarTxT(string Text,int indx);
	void set_Ganancias(float Dinero);
	void Ver_Ganancias(string Busqueda);
	string getNombre();
	int Selec_Funcion(int N_P);

};

Vendedor::Vendedor(string Nom, int Eda,int Vent){

    Nombre = Nom;
    Edad = Eda;
    Ventas = Vent;

}

void Vendedor::Reproducir_Trailer(){

    int No_P; char c = 219;
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    SetConsoleTextAttribute(H,7); int x;
    for(x=0;x<85;x++){gotoxy(x,0); cout<<c; }
    cout<<"\n\n                      _________  ___   ______   _______\n";
    cout<<"                     /_  __/ _ \\/ _ | /  _/ /  / __/ _ \\\n";
    cout<<"                      / / / , _/ __ |_/ // /__/ _// , _/\n";
    cout<<"                     /_/ /_/|_/_/ |_/___/____/___/_/|_| \n\n";
    SetConsoleTextAttribute(H,11);
    cout<<"                      "<<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c<<c <<c<< c <<c<< c <<c<< c<<endl;
    cout<<"                      "<<c<<"     1.- END GAME            " << c <<endl;
    cout<<"                      "<<c<<"     2.- 500 DIAS CON ELLA   " << c <<endl;
    cout<<"                      "<<c<<"     3.- MENTE INDOMABLE     " << c << endl;
    cout<<"                      "<<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c <<c<< c<<c <<c<< c <<c<< c <<c<< c<<endl;
    cout << "\n                           TECLEE NO. PELICULA: "; cin >> No_P;
    if (No_P == 1) {system("start VIDEOS/ENDGAME.mp4");}
    if (No_P == 2) {system("start VIDEOS/500.mp4");}
    if (No_P == 3) {system("start VIDEOS/MENTE.mp4");}
    if (No_P != 1 && No_P != 2 && No_P != 3) { system("COLOR 0C"); cout<<"\n                                   OCURRIO UN ERROR CON EL TRAILER "; }

}

string Vendedor::get_Ganancias(){

    string Cadena;
    string Ganancia = ConvertToString(Ventas);

    Cadena = "EMPLEADO: " + Nombre + " GANANCIAS: " + Ganancia + "\n";
    return Cadena;

}

void Vendedor::InsertarTxT(string Text,int indx){

    FILE *archivo;
    indx++ ;
    string Escribir = ConvertToString(indx) + ".- " +  Text;
    string s(Escribir);
    char c[s.length()];
    int i;

    for (i = 0; i < sizeof(c); i++) {
        c[i] = s[i];
    }
    if ((archivo = fopen("ARCHIVOS/VENDEDORES.txt", "at")) == NULL){
        fprintf(stderr,"                                   NO SE PUEDE ABRIR EL ARCHIVO");
        exit(0);
    }
    fwrite(&c, sizeof(c),1,archivo);
    fclose(archivo);

}

void Vendedor::set_Ganancias(float Dinero){

    Ventas+=Dinero;

}

void Vendedor::Ver_Ganancias(string Busqueda){

    int Index;
    string Linea;
    ifstream Archivo;

    Archivo.open("ARCHIVOS/VENDEDORES.txt");
    if (Archivo.is_open()){
        while (!Archivo.eof()){
            getline(Archivo,Linea);
            if ((Index = Linea.find(Busqueda,0)) != string::npos){
                cout << "                    " << Linea;
            }
        }
        Archivo.close();
    }

}

string Vendedor::getNombre(){

    return Nombre;

}

int Vendedor::Selec_Funcion(int N_P){

    int NF;

    if (N_P == 1){ cout << "\n\n                         SELECCIONE FUNCION 1 / 2 / 3 : "; cin >> NF;}
    if (N_P == 2){ cout << "\n\n                         SELECCIONE FUNCION 4 / 5 / 6 : "; cin >> NF; }
    if (N_P == 3){ cout << "\n\n                         SELECCIONE FUNCION 7 / 8 / 9 : "; cin >> NF; }
    if (NF > 9 || NF < 1) {system("COLOR 0C"); cout<<"\n                              ERROR AL SELECCIONAR SALA"; Sleep(1000); exit(0); }
    return (NF-1);

}




