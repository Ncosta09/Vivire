#ifndef VENTAS_CAB_DET_H_INCLUDED
#define VENTAS_CAB_DET_H_INCLUDED

/// ----- CLASE VENTAS DETALLE
class VentasDet{
private:
    int nVentaDetalle;
    int idHabitaculo;
    int cantV;
    float ImporteSubTotal;
    bool Estado;

public:

    ///CONSTRUCTOR
    VentasDet(int nV=000, int iD=000, int cV=000, float It=000){
        nVentaDetalle=nV;
        idHabitaculo=iD;
        cantV=cV;
        ImporteSubTotal=It;
    }


    void Cargar(int ContadorDetalle);
    void Mostrar();

    ///sets
    void setNumVenta(int nV){
        nVentaDetalle=nV;
    }

    void setIdArticulo(int iD){
        idHabitaculo=iD;
    }

    void setCantVend(int cV){
        cantV=cV;
    }

    void setImporteSubTotal(float It){
        ImporteSubTotal=It;
    }

    void setEstado(bool e){
        Estado=e;
    }

    ///gets
    int getNumVenta(){
        return nVentaDetalle;
        }

    int getIdArticulo(){
        return idHabitaculo;
        }

    int getCantVend(){
        return cantV;
        }

    float getImporteSubTotal(){
        return ImporteSubTotal;
        }

    int getEstado(){
        return Estado;
        }

        bool GrabarEnDisco();
        bool LeerDeDisco(int pos);
};

/// ----- CLASE VENTAS CABECERA
class VentasCab{
private:
    int nVenta;
    int dniCliente;
    float importeTotal=0;
    int MedPago;
    FechaAuto FechaDelDia;
    bool Estado;

public:

        ///CONSTRUCTOR
        VentasCab(int nV=000, int dC=000, float Imp=000, int Mdp=000){
        nVenta=nV;
        dniCliente=dC;
        importeTotal=Imp;
        MedPago=Mdp;
    }

    void Cargar();
    void CargarDetalle();
    void Mostrar();
    void Modificar(int );

    ///sets
    void setNumVenta(int nV){
        nVenta=nV;
    }
    void setDniCliente(int dC){
        dniCliente=dC;
    }
    void setImporteTotal(float Imp){
        importeTotal=Imp;
    }

    void setMedpago(int Mdp){
        MedPago=Mdp;
    }

    void setFechaDelDia(FechaAuto f){
        FechaDelDia = f;
    }

    void setEstado(bool e){
        Estado=e;
    }

    ///gets
    int getNumVenta(){
        return nVenta;
        }

    int getDniCliente(){
        return dniCliente;
        }

    float getImporteTotal(){
        return importeTotal;
        }

    int getMedpago(){
        return MedPago;
        }

    FechaAuto getFechaDelDia(){
        return FechaDelDia;
        }

    int getEstado(){
        return Estado;
        }

        bool GrabarEnDisco();
        bool LeerDeDisco(int pos);
};

/// --------------- VENTAS DETALLE ----------------------------------------------------------------------------------------------------------

///GRABAR EN DISCO VENTAS DETALLE
bool VentasDet::GrabarEnDisco(){
    FILE *p;
    bool escribio;
    p=fopen("ventasDet.dat", "ab");
    if(p==NULL) return false;
    escribio=fwrite(this, sizeof(VentasDet),1,p);
    fclose(p);
    return escribio;
}

///LEER DE DISCO VENTAS DETALLE
bool VentasDet::LeerDeDisco(int pos){
    FILE *pVentasDet;

    pVentasDet= fopen("ventasDet.dat", "rb");

    if(pVentasDet==NULL){
    return false;
    }
    fseek(pVentasDet, pos*sizeof(VentasDet), 0);
    bool Leyo = fread(this, sizeof(VentasDet), 1, pVentasDet);

    fclose(pVentasDet);
    return Leyo;
}

///CUENTA LOS REGISTROS
int ContarRegistrosVD(){
    int Posicion;
    int Tam;
    FILE *pVentasDet;

    pVentasDet=fopen("ventasDet.dat", "rb");
    if(pVentasDet==NULL){//verificacion
            pVentasDet=fopen("ventasDet.dat","ab");
            if(pVentasDet==NULL){
                cout << "no se puede abrir el archivo" << endl;
                exit(1);

        }
        Posicion=0;
        return Posicion;
        fclose(pVentasDet);
    }
    fseek(pVentasDet, 0, 2);//2(desde el final)y 0 (hasta el comienzo)
    Tam=ftell(pVentasDet);
    fclose(pVentasDet);
    Posicion=Tam/sizeof(VentasDet);//tamaño dividido el de los registros
    return Posicion;
}

///BUSCAR LA EXISTENCIA DEL HABITACULO
int BuscarCodHabit(int idHabitaculo){
Habitaciones obj;
int regID=0;

FILE *pHabitaculos;
pHabitaculos=fopen("Habitaciones.dat", "rb");

if(pHabitaculos==NULL){
    return -2;
}
while(fread(&obj, sizeof obj, 1, pHabitaculos)==1){
    if(obj.getIDarticulo()==idHabitaculo && obj.getEstado()==true){
        fclose(pHabitaculos);
        return regID;
    }
    regID++;
}

fclose(pHabitaculos);
return -1;
}

///VALIDAR LA CANTIDAD A COMPRAR
int ValidarCantidad(int cantV, int idHabitaculo){

Habitaciones obj;
int Vc=0;

FILE *pHabitaculos;
pHabitaculos=fopen("Habitaciones.dat", "rb");

if(pHabitaculos==NULL){
    return -2;
}
while(fread(&obj, sizeof obj, 1, pHabitaculos)==1){
    if(idHabitaculo==obj.getIDarticulo()){
        if(cantV>0 && cantV<=obj.getStock()){
            fclose(pHabitaculos);
            return Vc;
        }
    }
    Vc++;
}

fclose(pHabitaculos);
return -1;
}

///CAMBIA EL STOCK UNA VEZ REALIZADA LA COMPRA
bool CambiarStock(int cantV, int idHabitaculo){

Habitaciones des;

FILE *pHabitaculos;
pHabitaculos=fopen("Habitaciones.dat", "rb+");

if(pHabitaculos==NULL){
    return false;
}

while(fread(&des, sizeof des, 1, pHabitaculos)==1){

    if(idHabitaculo==des.getIDarticulo()){
            des.setStock(des.getStock()-cantV);
            fseek(pHabitaculos, ftell(pHabitaculos)-sizeof (Habitaciones), 0);
            fwrite(&des, sizeof des, 1, pHabitaculos);
            fseek(pHabitaculos,0,2);
        }
}

fclose(pHabitaculos);
return true;
}

///PRECIO TOTAL
int Subtotal(int cantV, int idHabitaculo){

Habitaciones obj;
float importeT=0;

FILE *pHabitaculos;
pHabitaculos=fopen("Habitaciones.dat", "rb");

if(pHabitaculos==NULL){
    return 0;
}
while(fread(&obj, sizeof obj, 1, pHabitaculos)==1){
        if(idHabitaculo==obj.getIDarticulo()){
            importeT = obj.getPrecio()*cantV;
    }
 }
    fclose(pHabitaculos);
    return importeT;
}

float PrecioPreParcial(int idArticulo, int cantV){ ///INT

Habitaciones obj;
float importeV=0;

FILE *pHabitaculos;
pHabitaculos=fopen("Habitaciones.dat", "rb");

if(pHabitaculos==NULL){
    return 0;
}
while(fread(&obj, sizeof obj, 1, pHabitaculos)==1){
        if(idArticulo==obj.getIDarticulo()){
            importeV = obj.getPrecio()*cantV;
    }
 }
    fclose(pHabitaculos);
    return importeV;
}

float PrecioFinal(int MedPago, float Importe){ ///INT

float importeV=0;

switch(MedPago){
            case 1:
                importeV = Importe*1.07; ///DEBITO
                break;

            case 2:
                importeV = Importe*1.15; ///CREDITO
                break;

            case 3:
                importeV = Importe;
                break;

            default:
                break;
                }

return importeV;
}

float PrecioPracial(int MedPago, int nVenta){ ///INT

VentasDet reg;
int IDH=0;
int CVH=0;
float Importe=0;
float ImporteFinal=0;

FILE *pVentasDet;
pVentasDet=fopen("ventasDet.dat", "rb");

if(pVentasDet==NULL){
    cout << "ERROR DE CARGA" << endl;
    return 0;
}

while(fread(&reg, sizeof reg, 1, pVentasDet)==1){
    IDH=reg.getIdArticulo();
    CVH=reg.getCantVend();

if(nVenta==reg.getNumVenta()){
    float importeF = PrecioPreParcial(IDH, CVH);
    Importe+=importeF;
    ImporteFinal = PrecioFinal(MedPago, Importe);
    }
}

fclose(pVentasDet);
return ImporteFinal;
}

///CUANDO NO HAY MAS STOCK, QUITA EL HABITACULO DE LA LISTA
bool Stock_A_False(int idHabitaculo){
Habitaciones des;

FILE *pHabitaculos;
pHabitaculos=fopen("Habitaciones.dat", "rb+");

if(pHabitaculos==NULL){
    return false;
}

while(fread(&des, sizeof des, 1, pHabitaculos)==1){

    if(idHabitaculo==des.getIDarticulo()){
            if(des.getStock()<=0){
            des.setEstado(false);
            fseek(pHabitaculos, ftell(pHabitaculos)-sizeof (Habitaciones), 0);
            fwrite(&des, sizeof des, 1, pHabitaculos);
            fseek(pHabitaculos,0,2);
            }
        }
}

fclose(pHabitaculos);
return true;
}

///MODIFICAR IMPORTE POR CADA NUEVO VENTA DETALLE
bool ModificarImporteTotal(int nVenta){
    VentasCab v;
    int pos=0;
    while(v.LeerDeDisco(pos++)){
        if(nVenta==v.getNumVenta()){
            v.setImporteTotal(PrecioPracial(v.getMedpago(),nVenta));
            v.Modificar(pos-1);
            return true;
        }
    }

  return false;
}

///PASA EL MISMO NUMERO DE VENTA DE CABECERA A DETALLE
int MismoNumero(){
VentasCab reg;
int numero=0;

FILE *pVentasCab;
pVentasCab=fopen("ventasCab.dat", "rb");

if(pVentasCab==NULL){
    return 0;
}
while(fread(&reg, sizeof reg, 1, pVentasCab)==1){
    numero=reg.getNumVenta();
}

fclose(pVentasCab);
return numero;
}

///DIBUJO RECUADRO
void RecuadroVenDet(int ContDet){
setlocale(LC_ALL, "C");

///LADO HORIZONTAL
    for(int i=3; i<48; i++){
        rlutil::locate(i,10);
        cout << (char) 205;
    }
    for(int i=3; i<48; i++){
        rlutil::locate(i,12);
        cout << (char) 205;
    }
    for(int i=3; i<48; i++){
        rlutil::locate(i,ContDet+13);
        cout << (char) 205;
    }

///LADO VERTICAL
    rlutil::locate(2,11);
    cout << (char) 186;
    rlutil::locate(48,11);
    cout << (char) 186;
    rlutil::locate(24,11);
    cout << (char) 186;
    rlutil::locate(48,ContDet+12);
    cout << (char) 186;
    rlutil::locate(2,ContDet+12);
    cout << (char) 186;

///ESQUINAS
    rlutil::locate(2,10);
    cout << (char) 201;
    rlutil::locate(48,10);
    cout << (char) 187;

///T
    rlutil::locate(2,12);
    cout << (char) 204;
    rlutil::locate(48,12);
    cout << (char) 185;
    rlutil::locate(24,10);
    cout << (char) 203;
    rlutil::locate(24,12);
    cout << (char) 202;
    rlutil::locate(2,ContDet+13);
    cout << (char) 204;
    rlutil::locate(48,ContDet+13);
    cout << (char) 185;
}

///DATOS DE CARGA DE VENTAS DETALLE
void VentasDet::Cargar(int ContadorDetalle){
  VentasCab obj;
  bool pasaId;
  bool Cantidad;

    nVentaDetalle = MismoNumero();
    rlutil::locate(4,11);
    cout << "ID DEL HABITACULO: ";
    rlutil::locate(27,11);
    cout << "CANTIDAD A ADQUIRIR: ";

    do{
        do{
    rlutil::locate(4,ContadorDetalle+12);
    cin >> idHabitaculo;
    int regID=BuscarCodHabit(idHabitaculo);
    if(regID<0){
        rlutil::locate(50,11);
        cout << "ESTE ID DE ARTICULO NO EXISTE, INTENTE NUEVAMENTE" << endl;
        pasaId = true;
    }
    else{
        pasaId = false;
    }
    }while(pasaId == true);

    rlutil::locate(27,ContadorDetalle+12);
    cin >> cantV;
    int Vc=ValidarCantidad(cantV, idHabitaculo);
        if(Vc<0){
        rlutil::locate(50,11);
        cout << "ERROR EN EL INGRESO DE CANTIDAD, INTENTE NUEVAMENTE" << endl;
        Cantidad = true;
    }
    else{
        Cantidad = false;
    }
    }while(Cantidad == true);

    ImporteSubTotal = Subtotal(cantV, idHabitaculo);
    setImporteSubTotal(ImporteSubTotal);

    CambiarStock(cantV, idHabitaculo);
    Stock_A_False(idHabitaculo);

    Estado=true;
}

///DATOS DE MUESTRA DE VENTAS DETALLE
void VentasDet::Mostrar(){
 if(getEstado()==true){
        cout << "ID DEL ARTICULO: ";
        cout << idHabitaculo << endl;
        cout << "CANTIDAD VENDIDA: ";
        cout << cantV << endl;
        cout << "SUBTOTAL: $";
        cout << ImporteSubTotal << endl;
        cout << "-------------------------------" << endl;
    }
}

///CARGAR
bool CargaVentaDet(int ContDet){
VentasDet reg;
int ContadorDetalle=ContDet;
reg.Cargar(ContadorDetalle);

FILE *pVentasDet;

pVentasDet=fopen("ventasDet.dat", "ab");
if(pVentasDet==NULL){
    return false;
}

bool escribio;
escribio = fwrite(&reg, sizeof reg, 1, pVentasDet);
fclose(pVentasDet);

if (escribio){
    ModificarImporteTotal(reg.getNumVenta());
}

return escribio;
}

///CARGA V2
bool CargaVentaDetV2(){
char op;
int ContDet=0;
do{
    ContDet++;
    RecuadroVenDet(ContDet);
    CargaVentaDet(ContDet);
    ContDet=ContDet+1;
    rlutil::locate(2,ContDet+14);
    cout << "DESEA CARGAR OTRO ARTICULO? (s/n): " << endl;
    rlutil::locate(38,ContDet+14);
    cin >> op;
    if(op=='n'){
    rlutil::locate(2,ContDet+12);
    cout << (char) 200;
    rlutil::locate(48,ContDet+12);
    cout << (char) 188;
    }
}while(op!='n');

return true;
}

///LISTAR TODOS
bool ListarRegistroVentaDet(){

VentasDet reg;

FILE *pVentasDet;
pVentasDet=fopen("ventasDet.dat", "rb");

if(pVentasDet==NULL){
    return false;
}

cout << "NUMERO DE VENTA \tARTICULO \t CANTIDAD VENDIDA \t SUBTOTAL" << endl;

while(fread(&reg, sizeof reg, 1, pVentasDet)==1){
    reg.Mostrar();
}

fclose(pVentasDet);
return true;
}

/// --------------- VENTAS CABECERA ---------------------------------------------------------------------------------------------------------

///GRABAR EN DISCO VENTAS CABECERA
bool VentasCab::GrabarEnDisco(){
    FILE *p;
    bool escribio;
    p=fopen("ventasCab.dat", "ab");
    if(p==NULL) return false;
    escribio=fwrite(this, sizeof(VentasCab),1,p);
    fclose(p);
    return escribio;
}

///LEER DE DISCO VENTAS CABECERA
bool VentasCab::LeerDeDisco(int pos){
    FILE *pVentasCab;

    pVentasCab= fopen("ventasCab.dat", "rb");

    if(pVentasCab==NULL){
    return false;
    }
    fseek(pVentasCab, pos*sizeof(VentasCab), 0);
    bool Leyo = fread(this, sizeof(VentasCab), 1, pVentasCab);

    fclose(pVentasCab);
    return Leyo;
}

///MODIFICACION PARA EL VALOR TOTAL
void VentasCab::Modificar(int pos){

    FILE *pVentasCab;
    pVentasCab = fopen("ventasCab.dat","rb+");
    if (pVentasCab==NULL) exit(1);
    fseek(pVentasCab, sizeof *this*pos,0);
    fwrite(this, sizeof *this, 1 ,pVentasCab);
    fclose(pVentasCab);

}

///AUTONUMERICO
int ContarRegistrosVC(){
    int Posicion;
    int Tam;
    FILE *pVentasCab;

    pVentasCab=fopen("ventasCab.dat", "rb");
    if(pVentasCab==NULL){//verificacion
            pVentasCab=fopen("ventasCab.dat","ab");
            if(pVentasCab==NULL){
                cout << "no se puede abrir el archivo" << endl;
                exit(1);

        }
        Posicion=0;
        return Posicion;
        fclose(pVentasCab);
    }
    fseek(pVentasCab, 0, 2);//2(desde el final)y 0 (hasta el comienzo)
    Tam=ftell(pVentasCab);
    fclose(pVentasCab);
    Posicion=Tam/sizeof(VentasCab);//tamaño dividido el de los registros
    return Posicion;
}

///REFLEJA QUE ES CADA NUMERO DE MEDIO DE PAGO
void NumeroPago(int MedPago){
switch(MedPago){
      case 1:
          cout << "DEBITO" << endl;
          break;
      case 2:
          cout << "CREDITO" << endl;
          break;
      case 3:
          cout << "TRANSFERENCIA" << endl;
          break;

      default:
          cout << "LA OPCION SELECCIONADA ES INCORRECTA" << endl;
          break;
          }
}

///BUSCA POR NUMERO DE VENTA
int BuscarPorNumVentaCab(int nVenta){

VentasCab reg;
int pos=0;

FILE *pVentasCab;
pVentasCab=fopen("ventasCab.dat", "rb");

if(pVentasCab==NULL){
    return -2;
}
while(fread(&reg, sizeof reg, 1, pVentasCab)==1){
    if(reg.getNumVenta()==nVenta){
        fclose(pVentasCab);
        return pos;
    }
    pos++;
}

fclose(pVentasCab);
return -1;

}

///VERIFICA QUE EXISTA EL DNI DEL CLIENTE
int BuscarDniCliente(int dniCliente){

Cliente retorno;
int retDni=0;

FILE *pCliente;
pCliente=fopen("Cliente.dat", "rb");

if(pCliente==NULL){
    return -2;
}
while(fread(&retorno, sizeof retorno, 1, pCliente)==1){
    if(retorno.getDni()==dniCliente && retorno.getEstado()==true){
        fclose(pCliente);
        return retDni;
    }
    retDni++;
}

fclose(pCliente);
return -1;
}

///DIBUJO RECUADRO
void RecuadroVenCab(){
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

///DATOS DE CARGA VENTAS CABECERA
void VentasCab::Cargar(){
  bool pasaDni;
  bool pasaPago;

    RecuadroVenCab();
    nVenta=ContarRegistrosVC()+1;
    rlutil::locate(4,3);
    cout << "NUMERO DE VENTA:";
    rlutil::locate(4,5);
    cout << "#" << nVenta << endl;
    setNumVenta(nVenta);
    rlutil::locate(26,3);
    cout << "DNI DEL CLIENTE:";
    rlutil::locate(49,3);
    cout << "M. DE PAGO: " << endl;
    rlutil::locate(80,2);
    cout << "MEDIOS DE PAGO ACEPTADOS" << endl;
    rlutil::locate(80,3);
    cout << "(1) - DEBITO" << endl;        ///7%  +
    rlutil::locate(80,4);
    cout << "(2) - CREDITO" << endl;       ///15% +
    rlutil::locate(80,5);
    cout << "(3) - TRANSFERENCIA" << endl; ///MISMO PRECIO
    rlutil::locate(67,3);
    cout << "FECHA: ";

  ///DNI CLIENTE
    do{
    rlutil::locate(26,5);
    cin >> dniCliente;
    int retDni=BuscarDniCliente(dniCliente);
    if(retDni<0){
        rlutil::locate(2,7);
        cout << "ESTE DNI DE CLIENTE NO EXISTE, INTENTE NUEVAMENTE" << endl;
        pasaDni = true;
    }
    else{
        pasaDni = false;
    }
    }while(pasaDni == true);

  ///MEDIO DE PAGO
    do{
    rlutil::locate(49,5);
    cin >> MedPago;
    if(MedPago == 1 || MedPago == 2 || MedPago == 3){
        pasaPago = true;
    }
    else{
        rlutil::locate(2,7);
        cout << "MEDIO DE PAGO INCORRECTO, INTENTE NUEVAMENTE" << endl;
        pasaPago = false;
    }
    }while(pasaPago==false);

    rlutil::locate(67,5);
    FechaDelDia.MostrarFecha();

    Estado=true;
}

///DATOS DE MUESTRA VENTAS CABECERA
void VentasCab::Mostrar(){

  if(getEstado()==true){
        cout << "NUMERO DE VENTA: ";
        cout << nVenta << endl;
        cout << "DNI DEL CLIENTE: ";
        cout << dniCliente << endl;
        cout << "IMPORTE TOTAL DE LA VENTA: $";
        importeTotal = PrecioPracial(MedPago, nVenta);
        setImporteTotal(importeTotal);
        cout << importeTotal << endl;
        cout << "MEDIO DE PAGO: ";
        NumeroPago(MedPago);
        cout << "FECHA DE LA VENTA: ";
        FechaDelDia.MostrarFecha();
        cout << "-------------------------------" << endl;
    }

}

///CARGAR VENTA CABECERA
bool CargaVentaCab(){
VentasCab reg;
reg.Cargar();

FILE *pVentasCab;

pVentasCab=fopen("ventasCab.dat", "ab");
if(pVentasCab==NULL){
    return false;
}

bool escribio;
escribio = fwrite(&reg, sizeof reg, 1, pVentasCab);
fclose(pVentasCab);

return escribio;
}

///LISTAR TODOS
bool ListarRegistroVentaCab(){

VentasCab reg;

FILE *pVentasCab;
pVentasCab=fopen("ventasCab.dat", "rb");

if(pVentasCab==NULL){
    return false;
}
while(fread(&reg, sizeof reg, 1, pVentasCab)==1){
    reg.Mostrar();
}

fclose(pVentasCab);
return true;
}

///LISTAR POR NUMERO VENTA
bool ListarRegistroPorNumeroDeVentaCab(){

VentasCab reg;
int Venta;
bool idPasa = false;

cout << "INGRESE EL NUMERO DE VENTA A BUSCAR: ";
cin >> Venta;
cout << endl;

FILE *pVentasCab;
pVentasCab=fopen("ventasCab.dat", "rb");

if(pVentasCab==NULL){
    return false;
}


while(fread(&reg, sizeof reg, 1,pVentasCab)==1){

    if(Venta==reg.getNumVenta()){
    reg.Mostrar();
    idPasa = true;
    }
}

fclose(pVentasCab);

if(idPasa==false){
    cout << "ESTE NUMERO DE VENTA NO EXISTE" << endl;
}

return true;
}

///DAR BAJA VENTA
bool DarBajaVentaCab(){
VentasCab reg;
int Venta;

cout << "INGRESE EL NUMERO DE VENTA A BUSCAR: ";
cin >> Venta;
cout << endl;

FILE *pVentasCab;
pVentasCab=fopen("ventasCab.dat", "rb+");

if(pVentasCab==NULL){
    return false;
}


while(fread(&reg, sizeof reg, 1, pVentasCab)==1){

    if(Venta==reg.getNumVenta()){
    reg.setEstado(false);
    fseek(pVentasCab, ftell(pVentasCab)-sizeof (VentasCab), 0);
    fwrite(&reg, sizeof reg, 1, pVentasCab);
    fseek(pVentasCab,0,2);
    cout << "SU REGISTRO A SIDO ELIMINADO" << endl;
    }
}

fclose(pVentasCab);
return true;
}

///DAR ALTA VENTA
bool DarAltaVentaCab(){
VentasCab reg;
int Venta;

cout << "INGRESE EL NUMERO DE VENTA A BUSCAR: ";
cin >> Venta;
cout << endl;

FILE *pVentasCab;
pVentasCab=fopen("ventasCab.dat", "rb+");

if(pVentasCab==NULL){
    return false;
}


while(fread(&reg, sizeof reg, 1, pVentasCab)==1){

    if(Venta==reg.getNumVenta()){
    reg.setEstado(true);
    fseek(pVentasCab, ftell(pVentasCab)-sizeof (VentasCab), 0);
    fwrite(&reg, sizeof reg, 1, pVentasCab);
    fseek(pVentasCab,0,2);
    cout << "SU REGISTRO A SIDO DADO DE ALTA" << endl;
    }
}

fclose(pVentasCab);
return true;
}

///MENU GENERAL
bool MenuVentas(){
    setlocale(LC_ALL, "spanish");
    setConsoleTitle("VIVIRE");
    AjustarVentana(120,50);
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
      cout << "MENU VENTAS";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "1. CARGAR VENTA";
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
        case 1: if(CargaVentaCab() && CargaVentaDetV2()==false){
                rlutil::locate(50,12);
                cout << "ERROR EN LA CARGA DEL ARCHIVO" << endl;
            }
            else{
                rlutil::locate(50,12);
                cout << "REGISTRO CARGADO CON EXITO!" << endl;
            }
                rlutil::locate(50,13);
                system("pause");
                break;

        case 2: DarBajaVentaCab();
                system("pause");
                break;

        case 3: DarAltaVentaCab();
                system("pause");
                break;

        case 0: return false;
                break;

        default:cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
    }

}

#endif // VENTAS_CAB_DET_H_INCLUDED
