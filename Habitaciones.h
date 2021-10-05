#ifndef HABITACIONES_H_INCLUDED
#define HABITACIONES_H_INCLUDED

///CLASE HABITACIONES
class Habitaciones{

private:
    int IDarticulo;
    char Descripcion[30];
    float Precio;
    int Stock;
    bool Estado;

public:

    ///CONSTRUCTOR
    Habitaciones(int ID=000, const char *d="000", int p=000, int s=000){
        IDarticulo=ID;
        strcpy(Descripcion,d);
        Precio=p;
        Stock=s;
    }

    void Cargar();
    void Mostrar();

    ///sets
    void setIDarticulo(int ID){
        IDarticulo=ID;
    }
    void setDescripcion(char *d){
        strcpy(Descripcion,d);
    }
    void setPrecio(float p){
        Precio=p;
    }
    void setStock(int s){
        Stock=s;
    }
    void setEstado(bool e){
        Estado=e;
    }

    ///gets
    int getIDarticulo(){
        return IDarticulo;
    }
    const char * getDescripcion(){
        return Descripcion;
    }
    float getPrecio(){
        return Precio;
    }
    int getStock(){
        return Stock;
    }
    int getEstado(){
        return Estado;
    }

    bool GrabarEnDisco();
    bool LeerDeDisco(int pos);
};

///GRABAR EN DISCO HABITACIONES
bool Habitaciones::GrabarEnDisco(){
    FILE *p;
    bool escribio;
    p=fopen("Habitaciones.dat", "ab");
    if(p==NULL) return false;
    escribio=fwrite(this, sizeof(Habitaciones),1,p);
    fclose(p);
    return escribio;
}

///LEER DE DISCO HABITACIONES
bool Habitaciones::LeerDeDisco(int pos){
    FILE *pHabitaculos;

    pHabitaculos = fopen("Habitaciones.dat", "rb");

    if(pHabitaculos==NULL){
    return false;
    }
    fseek(pHabitaculos, pos*sizeof(Habitaciones), 0);
    bool Leyo = fread(this, sizeof(Habitaciones), 1, pHabitaculos);

    fclose(pHabitaculos);
    return Leyo;
}

///CONTAR REGISTRO
int ContarRegistrosHabitaculos(){
  int cantReg;
  FILE *pHabitaculos;
  pHabitaculos=fopen("Habitaciones.dat", "rb");
  if(pHabitaculos==NULL) return -1;
  fseek(pHabitaculos,0,2);
  cantReg=ftell(pHabitaculos)/sizeof(Habitaciones);
  fclose(pHabitaculos);
  return cantReg;
}

///AUTONUMERICO
int ContarRegistrosHB(){
    int Posicion;
    int Tam;
    FILE *pHabitaculos;

    pHabitaculos=fopen("Habitaciones.dat", "rb");
    if(pHabitaculos==NULL){//verificacion
            pHabitaculos=fopen("Habitaciones.dat","ab");
            if(pHabitaculos==NULL){
                cout << "no se puede abrir el archivo" << endl;
                exit(1);

        }
        Posicion=0;
        return Posicion;
        fclose(pHabitaculos);
    }
    fseek(pHabitaculos, 0, 2);//2(desde el final)y 0 (hasta el comienzo)
    Tam=ftell(pHabitaculos);
    fclose(pHabitaculos);
    Posicion=Tam/sizeof(Habitaciones);//tamaño dividido el de los registros
    return Posicion;
}

///DIBUJO RECUADRO
void Recuadro(){
setlocale(LC_ALL, "C");

 ///LADO HORIZONTAL
    for(int i=2; i<78; i++){
        rlutil::locate(i,2);
        cout << (char) 205;
    }
    for(int i=2; i<78; i++){
        rlutil::locate(i,4);
        cout << (char) 205;
    }
    for(int i=2; i<78; i++){
        rlutil::locate(i,6);
        cout << (char) 205;
    }

 ///LADO VERTICAL
    rlutil::locate(2,3);
    cout << (char) 186;
    rlutil::locate(78,3);
    cout << (char) 186;
    rlutil::locate(2,5);
    cout << (char) 186;
    rlutil::locate(78,5);
    cout << (char) 186;
    rlutil::locate(24,3);
    cout << (char) 186;
    rlutil::locate(47,3);
    cout << (char) 186;
    rlutil::locate(65,3);
    cout << (char) 186;
    rlutil::locate(24,5);
    cout << (char) 186;
    rlutil::locate(47,5);
    cout << (char) 186;
    rlutil::locate(65,5);
    cout << (char) 186;

 ///ESQUINAS
    rlutil::locate(2,2);
    cout << (char) 201;
    rlutil::locate(2,6);
    cout << (char) 200;
    rlutil::locate(78,2);
    cout << (char) 187;
    rlutil::locate(78,6);
    cout << (char) 188;

 ///T
    rlutil::locate(2,4);
    cout << (char) 204;
    rlutil::locate(78,4);
    cout << (char) 185;
    rlutil::locate(24,2);
    cout << (char) 203;
    rlutil::locate(47,2);
    cout << (char) 203;
    rlutil::locate(65,2);
    cout << (char) 203;
    rlutil::locate(24,4);
    cout << (char) 206;
    rlutil::locate(47,4);
    cout << (char) 206;
    rlutil::locate(65,4);
    cout << (char) 206;
    rlutil::locate(24,6);
    cout << (char) 202;
    rlutil::locate(47,6);
    cout << (char) 202;
    rlutil::locate(65,6);
    cout << (char) 202;
}

///DATOS DE CARGA HABITACULOS
void Habitaciones::Cargar(){
    bool pasa;
    Recuadro();

    rlutil::locate(4,3);
    IDarticulo=ContarRegistrosHB()+1;
    cout << "ID DE ARTICULO:";
    rlutil::locate(4,5);
    cout << IDarticulo << endl;
    setIDarticulo(IDarticulo);

    rlutil::locate(53,3);
    cout << "PRECIO: " << endl;
    rlutil::locate(30,3);
    cout << "DESCRIPCION: ";
    rlutil::locate(71,3);
    cout << "STOCK: ";

    rlutil::locate(30,5);
    cin >> Descripcion;

    do{
    rlutil::locate(53,5);
    cout << "$";
    cin >> Precio;
    if(Precio>0){
            pasa=true;
    }
    else{
    rlutil::locate(2,7);
    cout << "EL PRECIO ES MENOR QUE CERO (0), VUELVA A INGRESAR EL PRECIO" << endl;
    pasa=false;
    }

    }while(pasa==false);

    rlutil::locate(71,5);
    cin >> Stock;

    Estado=true;
}

///MUESTRA PARTE DE LOS DATOS CARGADOS
void Habitaciones::Mostrar(){
    if(getEstado()==true){
    Recuadro();
    rlutil::locate(4,3);
    cout << "ID DEL HABITACULO: ";
    rlutil::locate(4,5);
    cout << IDarticulo << endl;
    rlutil::locate(30,3);
    cout << "DESCRIPCION: ";
    rlutil::locate(30,5);
    cout << Descripcion << endl;
    rlutil::locate(53,3);
    cout << "PRECIO: " << "$";
    rlutil::locate(53,5);
    cout << Precio << endl;
    rlutil::locate(71,3);
    cout << "STOCK: ";
    rlutil::locate(71,5);
    cout << Stock << endl;
    }
}

///CARGA DE HABITACULOS EN EL ARCHIVO
bool CargarHabitaculos(){
Habitaciones reg;
reg.Cargar();

FILE *pHabitaculos;

pHabitaculos=fopen("Habitaciones.dat", "ab");
if(pHabitaculos==NULL){
    return false;
}

bool Escribio;
Escribio = fwrite(&reg, sizeof reg, 1, pHabitaculos);
fclose(pHabitaculos);

return Escribio;
}

///DIBUJO RECUADRO
void Recuadro_M(int Cantidad){
setlocale(LC_ALL, "C");

 ///LADO HORIZONTAL
    for(int i=2; i<78; i++){
        rlutil::locate(i,2);
        cout << (char) 205;
    }
    for(int i=2; i<78; i++){
        rlutil::locate(i,4);
        cout << (char) 205;
    }

 ///LADO VERTICAL
    rlutil::locate(1,3);
    cout << (char) 186;
    rlutil::locate(78,3);
    cout << (char) 186;
    rlutil::locate(24,3);
    cout << (char) 186;
    rlutil::locate(47,3);
    cout << (char) 186;
    rlutil::locate(65,3);
    cout << (char) 186;

 ///ESQUINAS
    rlutil::locate(1,2);
    cout << (char) 201;
    rlutil::locate(1,Cantidad+4);
    cout << (char) 200;
    rlutil::locate(78,2);
    cout << (char) 187;
    rlutil::locate(78,Cantidad+4);
    cout << (char) 188;

 ///T
    rlutil::locate(1,4);
    cout << (char) 204;
    rlutil::locate(78,4);
    cout << (char) 185;
    rlutil::locate(24,2);
    cout << (char) 203;
    rlutil::locate(47,2);
    cout << (char) 203;
    rlutil::locate(65,2);
    cout << (char) 203;
    rlutil::locate(24,4);
    cout << (char) 206;
    rlutil::locate(47,4);
    cout << (char) 206;
    rlutil::locate(65,4);
    cout << (char) 206;
}

///DIBUJO RECUADRO
void Mostrar_Interac(int Cantidad){

for(int i=2; i<78; i++){
        rlutil::locate(i,Cantidad+5);
        cout << (char) 205;
    }
    rlutil::locate(1,Cantidad+3);
    cout << (char) 204;
    rlutil::locate(78,Cantidad+3);
    cout << (char) 185;
    rlutil::locate(1,Cantidad+4);
    cout << (char) 186;
    rlutil::locate(78,Cantidad+4);
    cout << (char) 186;
    rlutil::locate(24,Cantidad+5);
    cout << (char) 202;
    rlutil::locate(47,Cantidad+5);
    cout << (char) 202;
    rlutil::locate(65,Cantidad+5);
    cout << (char) 202;
    rlutil::locate(24,Cantidad+3);
    cout << (char) 206;
    rlutil::locate(47,Cantidad+3);
    cout << (char) 206;
    rlutil::locate(65,Cantidad+3);
    cout << (char) 206;
    rlutil::locate(24,Cantidad+4);
    cout << (char) 186;
    rlutil::locate(47,Cantidad+4);
    cout << (char) 186;
    rlutil::locate(65,Cantidad+4);
    cout << (char) 186;

}

///LISTA TODOS LOS CARGADOS EN EL ARCHIVO
bool ListarRegistros(){
Habitaciones reg;
int Cantidad=0;

FILE *pHabitaculos;
pHabitaculos=fopen("Habitaciones.dat", "rb");

if(pHabitaculos==NULL){
    return false;
}

rlutil::locate(3,3);
cout << "ID DEL ARTICULO: ";
rlutil::locate(30,3);
cout << "DESCRIPCION: ";
rlutil::locate(53,3);
cout << "PRECIO: ";
rlutil::locate(71,3);
cout << "STOCK: ";

while(fread(&reg, sizeof reg, 1, pHabitaculos)==1){
setlocale(LC_ALL, "C");
    Cantidad++;

    rlutil::locate(3, Cantidad+4);
    cout << reg.getIDarticulo();
    rlutil::locate(30,Cantidad+4);
    cout << reg.getDescripcion();
    rlutil::locate(53,Cantidad+4);
    cout << "$" << reg.getPrecio();
    rlutil::locate(71,Cantidad+4);
    cout << reg.getStock();

    Mostrar_Interac(Cantidad);
    Cantidad=Cantidad+1;
}
Recuadro_M(Cantidad);

fclose(pHabitaculos);
rlutil::locate(2,Cantidad+6);
system("pause");
return true;
}

///BUSCA EN EL ARCHIVO Y LISTA POR ID
bool ListarRegistrosPorID(){
Habitaciones reg;
int ID;
bool idPasa = false;

cout << "INGRESE EL ID DE ARTICULO A BUSCAR: ";
cin >> ID;
cout << endl;
system("cls");

FILE *pHabitaculos;
pHabitaculos=fopen("Habitaciones.dat", "rb");

if(pHabitaculos==NULL){
    return false;
}

while(fread(&reg, sizeof reg, 1, pHabitaculos)==1){

    if(ID==reg.getIDarticulo()){
    reg.Mostrar();
    idPasa = true;
    }
}

fclose(pHabitaculos);

if(idPasa==false){
    rlutil::locate(2,7);
    cout << "ESTE ID DE ARTICULO NO EXISTE" << endl;
}
rlutil::locate(2,8);
system("pause");
return true;
}

///CAMBIAR PRECIO
bool CambiarPrecio(){

Habitaciones reg;
int ID;
float pR;

FILE *pHabitaculos;
pHabitaculos=fopen("Habitaciones.dat", "rb+");

cout << "INGRESE EL ID DEL HABITACULO A BUSCAR: ";
cin >> ID;
cout << endl;
cout << "INGRESE EL PRECIO DEL HABITACULO A MODIFICAR: ";
cin >> pR;
cout << endl;

if(pHabitaculos==NULL){
    return false;
}

while(fread(&reg, sizeof reg, 1, pHabitaculos)==1){

    if(ID==reg.getIDarticulo()){
            reg.setPrecio(pR);
            fseek(pHabitaculos, ftell(pHabitaculos)-sizeof (Habitaciones), 0);
            fwrite(&reg, sizeof reg, 1, pHabitaculos);
            fseek(pHabitaculos,0,2);
            cout << "SU REGISTRO A SIDO MODIFICADO CON EXITO" << endl;
        }
}

fclose(pHabitaculos);
return true;
}

///CAMBIAR STOCK
bool CambiarStock(){

Habitaciones reg;
int ID;
int St;

FILE *pHabitaculos;
pHabitaculos=fopen("Habitaciones.dat", "rb+");

cout << "INGRESE EL ID DE HABITACULO A BUSCAR: ";
cin >> ID;
cout << endl;
cout << "INGRESE EL STOCK DEL HABITACULO A MODIFICAR: ";
cin >> St;
cout << endl;

if(pHabitaculos==NULL){
    return false;
}

while(fread(&reg, sizeof reg, 1, pHabitaculos)==1){

    if(ID==reg.getIDarticulo()){
            reg.setStock(St);
            fseek(pHabitaculos, ftell(pHabitaculos)-sizeof (Habitaciones), 0);
            fwrite(&reg, sizeof reg, 1, pHabitaculos);
            fseek(pHabitaculos,0,2);
            cout << "SU REGISTRO A SIDO MODIFICADO CON EXITO" << endl;
        }
}

fclose(pHabitaculos);
return true;
}

///BAJA LOGICA
bool DarBajaHB(){

Habitaciones reg;
int ID;

cout << "INGRESE EL ID DE ARTICULO A BUSCAR: ";
cin >> ID;
cout << endl;

FILE *pHabitaculos;
pHabitaculos=fopen("Habitaciones.dat", "rb+");

if(pHabitaculos==NULL){
    return false;
}


while(fread(&reg, sizeof reg, 1, pHabitaculos)==1){

    if(ID==reg.getIDarticulo()){
    reg.setEstado(false);
    fseek(pHabitaculos, ftell(pHabitaculos)-sizeof (Habitaciones), 0);
    fwrite(&reg, sizeof reg, 1, pHabitaculos);
    fseek(pHabitaculos,0,2);
    cout << "SU REGISTRO A SIDO ELIMINADO" << endl;
    }
}

fclose(pHabitaculos);
return true;
}

///ALTA LOGICA
bool DarAltaHB(){

Habitaciones reg;
int ID;

cout << "INGRESE EL ID DE ARTICULO A BUSCAR: ";
cin >> ID;
cout << endl;

FILE *pHabitaculos;
pHabitaculos=fopen("Habitaciones.dat", "rb+");

if(pHabitaculos==NULL){
    return false;
}


while(fread(&reg, sizeof reg, 1, pHabitaculos)==1){

    if(ID==reg.getIDarticulo()){
    reg.setEstado(true);
    fseek(pHabitaculos, ftell(pHabitaculos)-sizeof (Habitaciones), 0);
    fwrite(&reg, sizeof reg, 1, pHabitaculos);
    fseek(pHabitaculos,0,2);
    cout << "SU REGISTRO A SIDO DADO DE ALTA" << endl;
    }
}

fclose(pHabitaculos);
return true;
}

///OPCIONES LISTAR
bool ListarHB(){
    setlocale(LC_ALL, "spanish");
    setConsoleTitle("VIVIRE");
    AjustarVentana(120,30);
    const int ANCHO_MENU = 34;
    const int ALTO_MENU = 7;
    int key, opc, cursorX, cursorY;

    while(true){
      cursorX=POSMENUX+1;
      cursorY=POSMENUY + 4;
      setBackgroundColor(FONDO);
      cls();
      opc=1;
      setColor(LETRA);
      setBackgroundColor(FONDO);
      recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
      separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
      locate(POSMENUX+5,POSMENUY+1);
      cout << "FORMAS PARA LISTAR";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "1. MOSTRAR HB CARGADOS";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "2. MOSTRAR HB POR ID";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "0. VOLVER AL MENU";
      locate(POSMENUX+2,POSMENUY+3);
      cout << " SELECCIONE UNA OPCION: ";
      hidecursor();

      locate(cursorX,cursorY);
      cout<<">";
      key = getkey();
      while(key != KEY_ENTER){
        locate(cursorX,cursorY);
        cout<<" ";
        switch(key){
        case KEY_DOWN:
            if(opc < 2){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 0){
                opc--;
            }else{
                opc=2;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 3;
        }else{
            cursorY = POSMENUY + 6;
        }
        locate(cursorX,cursorY);
        cout<<">";
        key = getkey();
      }
      setBackgroundColor(BLUE);
      cls();
      showcursor();
      switch(opc){
        case 1: ListarRegistros();
                break;

        case 2: ListarRegistrosPorID();
                break;

        case 0: return false;
                break;

        default:cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
    }


}

///OPCIONES DE MODIFICACION
bool ModificarHB(){
    setlocale(LC_ALL, "spanish");
    setConsoleTitle("VIVIRE");
    AjustarVentana(120,30);
    const int ANCHO_MENU = 26;
    const int ALTO_MENU = 8;
    int key, opc, cursorX, cursorY;

    while(true){
      cursorX=POSMENUX+1;
      cursorY=POSMENUY+4;
      setBackgroundColor(FONDO);
      cls();
      opc=1;
      setColor(LETRA);
      setBackgroundColor(FONDO);
      recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
      separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
      locate(POSMENUX+5,POSMENUY+1);
      cout << "MENU HABITACIONES";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "1. PRECIO";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "2. STOCK";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "3. DAR DE BAJA";
      locate(POSMENUX+3,POSMENUY+7);
      cout << "0. VOLVER AL MENU";
      locate(POSMENUX+2,POSMENUY+3);
      cout << " SELECCIONE UNA OPCION: ";
      hidecursor();

      locate(cursorX,cursorY);
      cout<<">";
      key = getkey();
      while(key != KEY_ENTER){
        locate(cursorX,cursorY);
        cout<<" ";
        switch(key){
        case KEY_DOWN:
            if(opc < 3){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 0){
                opc--;
            }else{
                opc=3;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 3;
        }else{
            cursorY = POSMENUY + 7;
        }
        locate(cursorX,cursorY);
        cout<<">";
        key = getkey();
      }
      setBackgroundColor(BLUE);
      cls();
      showcursor();
      switch(opc){
        case 1: CambiarPrecio();
                system("pause");
                break;

        case 2: CambiarStock();
                system("pause");
                break;

        case 3: DarBajaHB();
                system("pause");
                break;

        case 0: return false;
                break;

        default:cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
    }

}

///MENU GENERAL
bool MenuHabitaciones(){
    setlocale(LC_ALL, "spanish");
    setConsoleTitle("VIVIRE");
    AjustarVentana(120,30);
    const int ANCHO_MENU = 26;
    const int ALTO_MENU = 8;
    int key, opc, cursorX, cursorY;

    while(true){
      cursorX=POSMENUX+1;
      cursorY=POSMENUY + 4;
      setBackgroundColor(FONDO);
      cls();
      opc=1;
      setColor(LETRA);
      setBackgroundColor(FONDO);
      recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
      separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
      locate(POSMENUX+5,POSMENUY+1);
      cout << "MENU HABITACIONES";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "1. CARGAR HABITACULOS";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "2. MOSTRAR (LISTAR)";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "3. MODIFICAR DATOS";
      locate(POSMENUX+3,POSMENUY+7);
      cout << "0. VOLVER AL MENU";
      locate(POSMENUX+2,POSMENUY+3);
      cout << " SELECCIONE UNA OPCION: ";
      hidecursor();

      locate(cursorX,cursorY);
      cout<<">";
      key = getkey();
      while(key != KEY_ENTER){
        locate(cursorX,cursorY);
        cout<<" ";
        switch(key){
        case KEY_DOWN:
            if(opc < 3){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 0){
                opc--;
            }else{
                opc=3;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 3;
        }else{
            cursorY = POSMENUY + 7;
        }
        locate(cursorX,cursorY);
        cout<<">";
        key = getkey();
      }
      setBackgroundColor(BLUE);
      cls();
      showcursor();
      switch(opc){
        case 1: if(CargarHabitaculos()==false){
                rlutil::locate(2,8);
                cout << "ERROR EN LA CARGA DEL ARCHIVO" << endl;
            }
            else{
                rlutil::locate(2,8);
                cout << "REGISTRO CARGADO CON EXITO!" << endl;
            }
                rlutil::locate(2,9);
                system("pause");
                break;

        case 2: ListarHB();
                break;

        case 3: ModificarHB();
                break;

        case 0: return false;
                break;

        default:cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
    }

}

#endif // HABITACIONES_H_INCLUDED
