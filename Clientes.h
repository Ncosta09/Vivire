#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

///CLASE CLIENTE
class Cliente{
private:
    int DNI;
    char Nombre[25];
    char Apellido[25];
    char Email[30];
    Fecha fechaIncorporacion;
    char Tel[20];
    bool Estado;

public:

    ///CONSTRUCTOR
    Cliente(int d=000, const char *n="000", const char *a="000", const char *e="000",const char *t="000"){
        DNI=d;
        strcpy(Nombre,n);
        strcpy(Apellido,a);
        strcpy(Email,e);
        strcpy(Tel,t);
    }

    void Cargar();
    void Mostrar();

    ///sets
    void setDni(int d){
        DNI=d;
    }
    void setNombre(char *n){
        strcpy(Nombre,n);
    }
    void setApellido(char *a){
        strcpy(Apellido,a);
    }
    void setEmail(char *e){
        strcpy(Email,e);
    }
    void setTel(char *t){
        strcpy(Tel,t);
    }
    void setfechaIncorporacion(Fecha f){
        fechaIncorporacion = f;
    }
    void setEstado(bool e){
        Estado=e;
    }

    ///gets
    int getDni(){
        return DNI;
        }
    const char *getNombre(){
        return Nombre;
        }
    const char *getApellido(){
        return Apellido;
        }
    const char *getEmail(){
        return Email;
        }
    const char *getTel(){
        return Tel;
        }
    Fecha getfechaIncorporacion(){
        return fechaIncorporacion;
        }
    int getEstado(){
        return Estado;
        }

        bool GrabarEnDisco();
        bool LeerDeDisco(int pos);

};

///GRABAR EN DISCO CLIENTE
bool Cliente::GrabarEnDisco(){
    FILE *p;
    bool escribio;
    p=fopen("Cliente.dat", "ab");
    if(p==NULL) return false;
    escribio=fwrite(this, sizeof(Cliente),1,p);
    fclose(p);
    return escribio;
}

///LEER DE DISCO CLIENTE
bool Cliente::LeerDeDisco(int pos){
    FILE *pCliente;

    pCliente= fopen("Cliente.dat", "rb");

    if(pCliente==NULL){
    return false;
    }
    fseek(pCliente, pos*sizeof(Cliente), 0);
    bool Leyo = fread(this, sizeof(Cliente), 1, pCliente);

    fclose(pCliente);
    return Leyo;
}

///VERIFICA QUE EL DNI NO ESTE EN USO
int BuscarPorDNI(int DNI){

Cliente reg;
int pos=0;

FILE *p;
p=fopen("cliente.dat", "rb");

if(p==NULL){
    return -2;
}
while(fread(&reg, sizeof reg, 1, p)==1){
    if(reg.getDni()==DNI){
        fclose(p);
        return pos;
    }
    pos++;
}

fclose(p);
return -1;

}

///DIBUJO RECUADRO
void RecuadroCL(){
setlocale(LC_ALL, "C");

 ///LADO HORIZONTAL
    for(int i=2; i<78; i++){
        rlutil::locate(i,2);
        cout << (char) 205;
        rlutil::locate(i,4);
        cout << (char) 205;
        rlutil::locate(i,6);
        cout << (char) 205;
        rlutil::locate(i,8);
        cout << (char) 205;
        rlutil::locate(i,10);
        cout << (char) 205;
        rlutil::locate(i,12);
        cout << (char) 205;
        rlutil::locate(i,14);
        cout << (char) 205;
    }

 ///LADO VERTICAL
        rlutil::locate(1,3);
        cout << (char) 186;
        rlutil::locate(1,5);
        cout << (char) 186;
        rlutil::locate(1,7);
        cout << (char) 186;
        rlutil::locate(1,9);
        cout << (char) 186;
        rlutil::locate(1,11);
        cout << (char) 186;
        rlutil::locate(1,13);
        cout << (char) 186;
        rlutil::locate(78,3);
        cout << (char) 186;
        rlutil::locate(78,5);
        cout << (char) 186;
        rlutil::locate(78,7);
        cout << (char) 186;
        rlutil::locate(78,9);
        cout << (char) 186;
        rlutil::locate(78,11);
        cout << (char) 186;
        rlutil::locate(78,13);
        cout << (char) 186;
        rlutil::locate(21,3);
        cout << (char) 186;
        rlutil::locate(21,5);
        cout << (char) 186;
        rlutil::locate(21,7);
        cout << (char) 186;
        rlutil::locate(21,9);
        cout << (char) 186;
        rlutil::locate(21,11);
        cout << (char) 186;
        rlutil::locate(21,13);
        cout << (char) 186;

///ESQUINAS
    rlutil::locate(1,2);
    cout << (char) 201;
    rlutil::locate(1,14);
    cout << (char) 200;
    rlutil::locate(78,2);
    cout << (char) 187;
    rlutil::locate(78,14);
    cout << (char) 188;

///T
    rlutil::locate(1,4);
    cout << (char) 204;
    rlutil::locate(1,6);
    cout << (char) 204;
    rlutil::locate(1,8);
    cout << (char) 204;
    rlutil::locate(1,10);
    cout << (char) 204;
    rlutil::locate(1,12);
    cout << (char) 204;
    rlutil::locate(78,4);
    cout << (char) 185;
    rlutil::locate(78,6);
    cout << (char) 185;
    rlutil::locate(78,8);
    cout << (char) 185;
    rlutil::locate(78,10);
    cout << (char) 185;
    rlutil::locate(78,12);
    cout << (char) 185;

    rlutil::locate(21,2);
    cout << (char) 203;
    rlutil::locate(21,14);
    cout << (char) 202;

    rlutil::locate(21,4);
    cout << (char) 206;
    rlutil::locate(21,6);
    cout << (char) 206;
    rlutil::locate(21,8);
    cout << (char) 206;
    rlutil::locate(21,10);
    cout << (char) 206;
    rlutil::locate(21,12);
    cout << (char) 206;
}

///DATOS DE CARGA CLIENTE
void Cliente::Cargar(){
    bool pasaDNI;
    RecuadroCL();

    rlutil::locate(3,3);
    cout << "DNI DEL CLIENTE: ";
    rlutil::locate(3,5);
    cout << "NOMBRE: ";
    rlutil::locate(3,7);
    cout << "APELLIDO: ";
    rlutil::locate(3,9);
    cout << "EMAIL: ";
    rlutil::locate(3,11);
    cout << "F. DE NACIMIENTO: " << endl;
    rlutil::locate(3,13);
    cout << "TELEFONO: ";

    do{
    rlutil::locate(23,3);
    cin >> DNI;
    int pos=BuscarPorDNI(DNI);
    if(pos<0){
        pasaDNI = true;
    }
    else{
        rlutil::locate(2,15);
        cout << "ESTE DNI YA FUE INGRESADO, INTENTE NUEVAMENTE" << endl;
        pasaDNI = false;
    }
    }while(pasaDNI == false);

    rlutil::locate(23,5);
    cin >> Nombre;
    rlutil::locate(23,7);
    cin >> Apellido;
    rlutil::locate(23,9);
    cin >> Email;
    rlutil::locate(23,11);
    fechaIncorporacion.Carga();
    rlutil::locate(23,13);
    cin >> Tel;

    Estado=true;
}

///DIBUJO RECUADRO
void RecuadroMostrarCL(int ContCL){
setlocale(LC_ALL, "C");

    ///LADO HORIZONTAL
    for(int i=2; i<120; i++){
        rlutil::locate(i,2);
        cout << (char) 205;
    }
    for(int i=2; i<120; i++){
        rlutil::locate(i,4);
        cout << (char) 205;
    }
    for(int i=2; i<120; i++){
        rlutil::locate(i,ContCL+5);
        cout << (char) 205;
    }

    ///LADO VERTICAL
        rlutil::locate(1,3);
        cout << (char) 186;
        rlutil::locate(120,3);
        cout << (char) 186;
    for(int i=5; i<=ContCL+5; i++){
        rlutil::locate(1,i);
        cout << (char) 186;
    }
    for(int i=5; i<=ContCL+5; i++){
        rlutil::locate(120,i);
        cout << (char) 186;
    }

    ///ESQUINAS
    rlutil::locate(1,2);
    cout << (char) 201;
    rlutil::locate(120,2);
    cout << (char) 187;
    rlutil::locate(1,ContCL+5);
    cout << (char) 200;
    rlutil::locate(120,ContCL+5);
    cout << (char) 188;

    ///T
    rlutil::locate(1,4);
    cout << (char) 204;
    rlutil::locate(120,4);
    cout << (char) 185;
}

///DIBUJO RECUADRO
void Recuadro_PorDni(){
setlocale(LC_ALL, "C");

    ///LADO HORIZONTAL
    for(int i=2; i<120; i++){
        rlutil::locate(i,2);
        cout << (char) 205;
    }
    for(int i=2; i<120; i++){
        rlutil::locate(i,4);
        cout << (char) 205;
    }
    for(int i=2; i<120; i++){
        rlutil::locate(i,6);
        cout << (char) 205;
    }

    ///LADO VERTICAL
        rlutil::locate(1,3);
        cout << (char) 186;
        rlutil::locate(120,3);
        cout << (char) 186;
    for(int i=5; i<=6; i++){
        rlutil::locate(1,i);
        cout << (char) 186;
    }
    for(int i=5; i<=6; i++){
        rlutil::locate(120,i);
        cout << (char) 186;
    }

    ///ESQUINAS
    rlutil::locate(1,2);
    cout << (char) 201;
    rlutil::locate(120,2);
    cout << (char) 187;
    rlutil::locate(1,6);
    cout << (char) 200;
    rlutil::locate(120,6);
    cout << (char) 188;

    ///T
    rlutil::locate(1,4);
    cout << (char) 204;
    rlutil::locate(120,4);
    cout << (char) 185;
}

///MUESTRA PARTE DE LOS DATOS
void Cliente::Mostrar(){
    if(getEstado()==true){
        rlutil::locate(3,3);
        cout << "DNI:";
        rlutil::locate(22,3);
        cout << "NOMBRE:";
        rlutil::locate(41,3);
        cout << "APELLIDO:";
        rlutil::locate(60,3);
        cout << "EMAIL:";
        rlutil::locate(79,3);
        cout << "F. NACIMIENTO:";
        rlutil::locate(98,3);
        cout << "TELEFONO:";

    }
}

///CARGA EN ARCHIVO
bool CargaCliente(){

Cliente reg;
reg.Cargar();

FILE *pCliente;

pCliente=fopen("Cliente.dat", "ab");
if(pCliente==NULL){
    return false;
}

bool escribio;
escribio = fwrite(&reg, sizeof reg, 1, pCliente);
fclose(pCliente);

return escribio;

}

///LISTA TODOS DENTRO DEL ARCHIVO
bool ListarRegistrosCliente(){
Cliente reg;
int ContCL=0;

FILE *pCliente;
pCliente=fopen("cliente.dat", "rb");

if(pCliente==NULL){
    return false;
}
while(fread(&reg, sizeof reg, 1, pCliente)==1){
    ContCL++;
    reg.Mostrar();

    rlutil::locate(3,ContCL+4);
    cout << reg.getDni() << endl;
    rlutil::locate(22,ContCL+4);
    cout << reg.getNombre() << endl;
    rlutil::locate(41,ContCL+4);
    cout << reg.getApellido() << endl;
    rlutil::locate(60,ContCL+4);
    cout << reg.getEmail() << endl;
    rlutil::locate(79,ContCL+4);
    reg.getfechaIncorporacion().Muestra();
    rlutil::locate(98,ContCL+4);
    cout << reg.getTel() << endl;

}
RecuadroMostrarCL(ContCL);
fclose(pCliente);
rlutil::locate(2,ContCL+6);
system("pause");
return true;
}

///LISTA POR DNI
bool ListarRegistroPorDNI(){

Cliente reg;
int DNI;
bool idPasa = false;
int ContCL=0;

cout << "INGRESE EL DNI DEL CLIENTE A BUSCAR: ";
cin >> DNI;
cout << endl;

FILE *pCliente;
pCliente=fopen("cliente.dat", "rb");

if(pCliente==NULL){
    return false;
}


while(fread(&reg, sizeof reg, 1, pCliente)==1){
ContCL++;
    if(DNI==reg.getDni()){
    reg.Mostrar();
    rlutil::locate(3,5);
    cout << reg.getDni() << endl;
    rlutil::locate(22,5);
    cout << reg.getNombre() << endl;
    rlutil::locate(41,5);
    cout << reg.getApellido() << endl;
    rlutil::locate(60,5);
    cout << reg.getEmail() << endl;
    rlutil::locate(79,5);
    reg.getfechaIncorporacion().Muestra();
    rlutil::locate(98,5);
    cout << reg.getTel() << endl;
    idPasa = true;
    }
}
Recuadro_PorDni();
fclose(pCliente);

if(idPasa==false){
    system("cls");
    rlutil::locate(2,6);
    cout << "ESTE DNI DE CLIENTE NO EXISTE" << endl;
}

return true;
}

///CONTAR REGISTRO
int ContarRegistrosCliente(){
  int cantReg;
  FILE *pCliente;
  pCliente=fopen("Cliente.dat", "rb");
  if(pCliente==NULL) return -1;
  fseek(pCliente,0,2);
  cantReg=ftell(pCliente)/sizeof(Cliente);
  fclose(pCliente);
  return cantReg;
}

///COPIA ARCHIVOS
void CopiarArchivoCliente(Cliente *pCliente, int CantClientes){
    int i;
    for(i=0;i<CantClientes;i++){
        pCliente[i].LeerDeDisco(i); ///AGREGAR
    }
}

///ORDENO ARCHIVO
void OrdenarClientes(Cliente *pCliente, int CantClientes){
    int i, j, posMin;
    Cliente aux;
    for(i=0;i<CantClientes-1;i++){
        posMin=i;
        for(j=i+1;j<CantClientes;j++){
            if(pCliente[j].getDni() < pCliente[posMin].getDni()){
                posMin=j;
            }
        }
        aux=pCliente[i];
        pCliente[i]=pCliente[posMin];
        pCliente[posMin]=aux;

    }
 }

///IMPRIMO
void MostrarVectorClientes(Cliente *pCliente,int CantClientes){
    int i;
    for(i=0;i<CantClientes;i++){
        pCliente[i].Mostrar();
    }
}

///LISTA ORDENADOS - A +
void ListarRegistroClienteOrdenadoMM(){
///Contar los registros.
    int CantClientes=ContarRegistrosCliente();
///Crear un vector mediante la asignación dinámica de memoria.
    Cliente *pCliente;
    pCliente=new Cliente[CantClientes];///o una dirección válida, o NULL
    if(pCliente==NULL){
        cout<<"ERROR DE ASIGNACION DE MEORIA";
        return;
    }

///Copiar los registros del archivo en el vector.
    CopiarArchivoCliente(pCliente, CantClientes);
///Ordeno el vector.
    OrdenarClientes(pCliente, CantClientes);
///Muestro (imprimo).
    MostrarVectorClientes(pCliente, CantClientes);
///Devolver la memoria pedida
    delete pCliente;
}

///CAMBIAR MAIL CLIENTE
bool CambiarMailCliente(){

Cliente reg;
int DNI;
char mail[30];

FILE *pCliente;
pCliente=fopen("Cliente.dat", "rb+");

cout << "INGRESE EL DNI DEL CLIENTE A BUSCAR: ";
cin >> DNI;
cout << endl;
cout << "INGRESE EL MAIL DEL CLIENTE A MODIFICAR: ";
cin >> mail;
cout << endl;

if(pCliente==NULL){
    return false;
}

while(fread(&reg, sizeof reg, 1, pCliente)==1){

    if(DNI==reg.getDni()){
            reg.setEmail(mail);
            fseek(pCliente, ftell(pCliente)-sizeof (Cliente), 0);
            fwrite(&reg, sizeof reg, 1, pCliente);
            fseek(pCliente,0,2);
        }
}

fclose(pCliente);
return true;
}

///BAJA LOGICA
bool DarBajaCliente(){

Cliente reg;
int DNI;

cout << "INGRESE EL DNI DEL CLIENTE A BUSCAR: ";
cin >> DNI;
cout << endl;

FILE *pCliente;
pCliente=fopen("Cliente.dat", "rb+");

if(pCliente==NULL){
    return false;
}


while(fread(&reg, sizeof reg, 1, pCliente)==1){

    if(DNI==reg.getDni()){
    reg.setEstado(false);
    fseek(pCliente, ftell(pCliente)-sizeof (Cliente), 0);
    fwrite(&reg, sizeof reg, 1, pCliente);
    fseek(pCliente,0,2);
    cout << "SU REGISTRO A SIDO ELIMINADO" << endl;
    }
}

fclose(pCliente);
return true;
}

///ALTA LOGICA
bool DarAltaCliente(){

Cliente reg;
int DNI;
cout << "INGRESE EL DNI DEL CLIENTE A BUSCAR: ";
cin >> DNI;
cout << endl;

FILE *pCliente;
pCliente=fopen("Cliente.dat", "rb+");

if(pCliente==NULL){
    return false;
}


while(fread(&reg, sizeof reg, 1, pCliente)==1){

    if(DNI==reg.getDni()){
    reg.setEstado(true);
    fseek(pCliente, ftell(pCliente)-sizeof (Cliente), 0);
    fwrite(&reg, sizeof reg, 1, pCliente);
    fseek(pCliente,0,2);
    cout << "SU REGISTRO A SIDO DADO DE ALTA" << endl;
    }
}

fclose(pCliente);
return true;
}

///OPCIONES LISTAR
bool ListarCL(){
    setlocale(LC_ALL, "spanish");
    setConsoleTitle("VIVIRE");
    AjustarVentana(120,30);
    const int ANCHO_MENU = 41;
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
      cout << "1. MOSTRAR CLIENTES CARGADOS";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "2. MOSTRAR CLIENTE POR DNI";
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
        case 1: ListarRegistrosCliente();
                break;

        case 2: ListarRegistroPorDNI();
                rlutil::locate(2,7);
                system("pause");
                break;

        /*
        case 3: ListarRegistroClienteOrdenadoMM();
                system("pause");
                break;*/

        case 0: return false;
                break;

        default:cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
    }


}

///OPCIONES DE MODIFICACION
bool ModificarCL(){
    setlocale(LC_ALL, "spanish");
    setConsoleTitle("VIVIRE");
    AjustarVentana(120,30);
    const int ANCHO_MENU = 26;
    const int ALTO_MENU = 9;
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
      cout << "1. MAIL";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "2. DAR DE BAJA";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "3. DAR DE ALTA";
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
        case 1: CambiarMailCliente();
                system("pause");
                break;

        case 2: DarBajaCliente();
                system("pause");
                break;

        case 3: DarAltaCliente();
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
bool MenuCliente(){
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
      cout << "MENU CLIENTE";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "1. CARGAR CLIENTE";
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
        case 1: if(CargaCliente()==false){
            rlutil::locate(2,16);
                cout << "ERROR EN LA CARGA DEL ARCHIVO" << endl;
            }
            else{
                    rlutil::locate(2,16);
                cout << "REGISTRO CARGADO CON EXITO!" << endl;
            }
                rlutil::locate(2,17);
                system("pause");
                break;

        case 2: ListarCL();
                break;

        case 3: ModificarCL();
                break;

        case 0: return false;
                break;

        default:cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
    }

}

#endif // CLIENTES_H_INCLUDED
