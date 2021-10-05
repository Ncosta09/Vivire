#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED

///COMPROBAR QUE EL NUMERO DE FACTURA EXISTA
int Comprobar_NUM(int NUMventa){
VentasDet obj;
int regV=0;

FILE *pVentasDet;
pVentasDet=fopen("ventasDet.dat", "rb");

if(pVentasDet==NULL){
    return -2;
}
while(fread(&obj, sizeof obj, 1, pVentasDet)==1){
    if(obj.getNumVenta()==NUMventa){
        fclose(pVentasDet);
        return regV;
    }
    regV++;
}

fclose(pVentasDet);
return -1;
}

///BUSCAR NOMBRE DEL CLIENTE
void BuscarNombre(int Nick){
Cliente reg;

FILE *pCliente;
pCliente=fopen("Cliente.dat", "rb");

if(pCliente==NULL){
    cout << "ERROR DE CARGA" << endl;
    return;
}

while(fread(&reg, sizeof reg, 1, pCliente)==1){
        if(Nick==reg.getDni()){
            cout << "NOMBRE Y APELLIDO: " << reg.getNombre() << " " << reg.getApellido() << endl;
        }
}
fclose(pCliente);
}

///DATOS DE LA COMPRA DEL CLIENTE
void FacCabe(int Vent, int cant){

VentasCab reg;
int Nick;

FILE *pVentasCab;
pVentasCab=fopen("ventasCab.dat", "rb");

if(pVentasCab==NULL){
    cout << "ERROR DE CARGA" << endl;
    return;
}

while(fread(&reg, sizeof reg, 1, pVentasCab)==1){
        if(reg.getNumVenta()==Vent){
                ///reg.Mostrar();
                rlutil::locate(2,3); ///(ARRIBA)
                cout << "DNI DEL CLIENTE: " << reg.getDniCliente() << endl;
                Nick = reg.getDniCliente();
                rlutil::locate(2,4); ///(ARRIBA)
                BuscarNombre(Nick);
                rlutil::locate(70,3); ///(ARRIBA)
                cout << "FECHA DE LA VENTA: " << reg.getFechaDelDia().getDia() << "/" << reg.getFechaDelDia().getMes() << "/" << reg.getFechaDelDia().getAnio() << endl;

                if(reg.getMedpago()==1){
                        rlutil::locate(2,cant+2); ///(ABAJO)
                        cout << "MEDIO DE PAGO: DEBITO"<< endl;
                }
                if(reg.getMedpago()==2){
                        rlutil::locate(2,cant+2); ///(ABAJO)
                        cout << "MEDIO DE PAGO: CREDITO"<< endl;
                }
                if(reg.getMedpago()==3){
                        rlutil::locate(2,cant+2); ///(ABAJO)
                        cout << "MEDIO DE PAGO: TRANSFERENCIA"<< endl;
                }

                rlutil::locate(2,cant+3); ///(ABAJO)
                cout << "IMPORTE TOTAL DE LA VENTA: $" << reg.getImporteTotal() << endl;
        }
}

fclose(pVentasCab);
}

///VER DESCRIPCION DEL HABITACULO
void verDesc(int Art){
Habitaciones reg;

FILE *pHabitaculos;
pHabitaculos=fopen("Habitaciones.dat", "rb");

if(pHabitaculos==NULL){
    cout << "ERROR DE CARGA" << endl;
    return;
}

while(fread(&reg, sizeof reg, 1, pHabitaculos)==1){
        if(reg.getIDarticulo()==Art){
            cout << reg.getDescripcion();
        }
}

fclose(pHabitaculos);
}

///DIBUJO RECUADRO
void Recuadro(int cant){
    setlocale(LC_ALL, "C");

    ///LADO HORIZONTAL
    for(int i=2; i<111; i++){
        rlutil::locate(i,2);
        cout << (char) 205;
    }
    for(int i=2; i<111; i++){
        rlutil::locate(i,cant+1);
        cout << (char) 205;
    }
    for(int i=2; i<111; i++){
        rlutil::locate(i,7);
        cout << (char) 205;
    }
    for(int i=2; i<111; i++){
        rlutil::locate(i,5);
        cout << (char) 205;
    }
        for(int i=2; i<111; i++){
        rlutil::locate(i,cant+4);
        cout << (char) 205;
    }

    ///LADO VERTICAL
    for(int i=3; i<5; i++){
        rlutil::locate(1,i);
        cout << (char) 186;
    }
    for(int i=3; i<5; i++){
        rlutil::locate(111,i);
        cout << (char) 186;
    }
    rlutil::locate(1,6);
    cout << (char) 186;
    rlutil::locate(111,6);
    cout << (char) 186;
    for(int i=8; i<=cant; i++){
        rlutil::locate(1,i);
        cout << (char) 186;
    }
    for(int i=8; i<=cant; i++){
        rlutil::locate(111,i);
        cout << (char) 186;
    }
        for(int i=cant+2; i<=cant+3; i++){
        rlutil::locate(1,i);
        cout << (char) 186;
    }
        for(int i=cant+2; i<=cant+3; i++){
        rlutil::locate(111,i);
        cout << (char) 186;
    }

    ///ESQUINAS
    rlutil::locate(1,2);
    cout << (char) 201;
    rlutil::locate(111,2);
    cout << (char) 187;
    rlutil::locate(1,cant+4);
    cout << (char) 200;
    rlutil::locate(111,cant+4);
    cout << (char) 188;

    ///T
    rlutil::locate(1,5);
    cout << (char) 204;
    rlutil::locate(1,7);
    cout << (char) 204;
    rlutil::locate(1,cant+1);
    cout << (char) 204;
    rlutil::locate(111,5);
    cout << (char) 185;
    rlutil::locate(111,7);
    cout << (char) 185;
    rlutil::locate(111,cant+1);
    cout << (char) 185;
}

///DETALLE DE LA FACTURACION
void FacDetalle(int NUMventa){

VentasDet reg;
int Art=0;
int Vent=0;

FILE *pVentasDet;
pVentasDet=fopen("ventasDet.dat", "rb");

if(pVentasDet==NULL){
    cout << "ERROR DE CARGA" << endl;
    return;
}
rlutil::locate(45,1);
cout << "VIVIRE SA"<< endl;
cout << endl;
rlutil::locate(2,6);
cout << "NUMERO DE VENTA" << endl;
rlutil::locate(27,6);
cout << "ARTICULO" << endl;
rlutil::locate(45,6);
cout << "CANTIDAD VENDIDA" << endl;
rlutil::locate(71,6);
cout << "SUBTOTAL" << endl;
int cant = 7;
while(fread(&reg, sizeof reg, 1, pVentasDet)==1){
        if(reg.getNumVenta()==NUMventa){
            cant++;
                rlutil::locate(2,cant);
                cout << reg.getNumVenta() << endl;
                rlutil::locate(27,cant);
                Art = reg.getIdArticulo();
                verDesc(Art);
                rlutil::locate(52,cant);
                cout << reg.getCantVend() << endl;
                rlutil::locate(71,cant);
                cout << reg.getImporteSubTotal() << endl;
        }
}
Vent=NUMventa;
FacCabe(Vent, cant);
Recuadro(cant);
fclose(pVentasDet);

rlutil::locate(2,cant+5);
system("pause");
}

///MENU GENERAL
void Facturacion(){
  bool pasaComp;
int NUMventa;

    do{
        cout << "INGRESE NUMERO DE VENTA A FACTURAR: ";
        cin >> NUMventa;
        int comp=Comprobar_NUM(NUMventa);
        if(comp<0){
            cout << "ESTE NUMERO DE VENTA NO EXISTE, INTENTE NUEVAMENTE" << endl;
            pasaComp = true;
            system("pause");
            system("cls");
        }
        else{
            pasaComp = false;
        }
    }while(pasaComp == true);


system("cls");
FacDetalle(NUMventa);
}

#endif // FACTURA_H_INCLUDED
