#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

bool ArticuloStock(){
Habitaciones reg;
int contador=0;

FILE *pHabitaculos;
pHabitaculos=fopen("Habitaciones.dat", "rb");

if(pHabitaculos==NULL){
    return false;
}
cout << "ARTICULOS: " << endl;
cout << "------------------------------------" << endl;
while(fread(&reg, sizeof reg, 1, pHabitaculos)==1){
        contador++;
    if(reg.getStock()>100){
        cout << contador << ". " << reg.getDescripcion() << endl;
    }
}

fclose(pHabitaculos);
return true;
}

void Nomes(int mesmayor){

if(mesmayor==1){
    cout << "ENERO" << endl;
}
if(mesmayor==2){
    cout << "FEBRERO" << endl;
}
if(mesmayor==3){
    cout << "MARZO" << endl;
}
if(mesmayor==4){
    cout << "ABRIL" << endl;
}
if(mesmayor==5){
    cout << "MAYO" << endl;
}
if(mesmayor==6){
    cout << "JUNIO" << endl;
}
if(mesmayor==7){
    cout << "JULIO" << endl;
}
if(mesmayor==8){
    cout << "AGOSTO" << endl;
}
if(mesmayor==9){
    cout << "SETIEMBRE" << endl;
}
if(mesmayor==10){
    cout << "OCTUBRE" << endl;
}
if(mesmayor==11){
    cout << "NOVIEMBRE" << endl;
}
if(mesmayor==12){
    cout << "DICIEMBRE" << endl;
}

}

bool MesMayor(){
VentasCab reg;
int annio;
float mes[12]={0};

FILE *pVentasCab;
pVentasCab=fopen("ventasCab.dat", "rb");

if(pVentasCab==NULL){
    return false;
}
cout << "INGRESE EL AÑO: ";
cin >> annio;
while(fread(&reg, sizeof reg, 1, pVentasCab)==1){
        if(reg.getFechaDelDia().getAnio()==annio){
             mes[reg.getFechaDelDia().getMes()-1]+=reg.getImporteTotal();
        }
}

float may=0;
int mesmayor=0;

for(int i=0; i<12; i++){

if(may<mes[i]) {
mesmayor= i+1;
may = mes[i];
}

}

fclose(pVentasCab);
cout << "MES DE MAYOR RECAUDACION DEL AÑO " << annio << ": ";
Nomes(mesmayor);
return true;
}

bool MenuReportes(){
setlocale(LC_ALL, "spanish");
    setConsoleTitle("VIVIRE");
    AjustarVentana(120,30);
    const int ANCHO_MENU = 54;
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
      cout << "MENU REPORTES";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "1. LISTAR LOS ARTICULOS CUYO STOCK SEA MAYOR A 100";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "2. EL MES DEL AÑO DE MAYOR RECAUDACION POR VENTAS";
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
        case 1: ArticuloStock();
                system("pause");
                break;

        case 2: MesMayor();
                system("pause");
                break;

        case 0: return false;
                break;

        default:cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
    }

}

#endif // REPORTES_H_INCLUDED
