#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

///CLASE FECHA
class Fecha{
private:
    int dia, mes, anio;

public:
    Fecha(){
    dia=00;
    mes=00;
    anio=0000;
    }

    void Carga();
    void Muestra();

    ///sets
    void setDia(int d){
            dia=d;

        /*if(d>0 && d<32){
            dia=d;
        }
        else{
            dia=0;
        }*/
    }

    void setMes(int d){
            mes=d;

        /*if(d>0 && d<13){
            mes=d;
        }
        else{
            mes=0;
        }*/
    }

    void setAnio(int d){
        anio=d;
        /*f(d>0){
            anio=d;
        }
        else{
            anio=0;
        }*/

    }

    ///gets
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

};

/// CARGA Y MUESTRA DE FECHA
void Fecha::Carga(){
int aux;
bool PasaDia;
bool PasaMes;
bool PasaAnio;

/*
cout << "INGRESE EL DIA: ";
cin >> aux;
setDia(aux);
cout << "INGRESE EL MES: ";
cin >> aux;
setMes(aux);
cout << "INGRESE EL ANIO: ";
cin >> aux;
setAnio(aux);
*/
///DIA
do{
rlutil::locate(23,11);
cin >> aux;
    if(aux>0 && aux<32){
        PasaDia=true;
    }
    else{
        rlutil::locate(2,15);
        cout << "EL DIA UTILIZADO NO EXISTE, INTENTE NUEVAMENTE" << endl;
        PasaDia=false;
    }
}while(PasaDia==false);
setDia(aux);

rlutil::locate(25,11);
cout << "/";

///MES
do{
rlutil::locate(26,11);
cin >> aux;
    if(aux>0 && aux<13){
        PasaMes=true;
    }
    else{
        rlutil::locate(2,15);
        cout << "EL MES UTILIZADO NO EXISTE, INTENTE NUEVAMENTE" << endl;
        PasaMes=false;
    }
}while(PasaMes==false);
setMes(aux);

rlutil::locate(28,11);
cout << "/";

///AÑO
do{
rlutil::locate(29,11);
cin >> aux;
    if(aux>0){
        PasaAnio=true;
    }
    else{
        rlutil::locate(2,15);
        cout << "EL ANIO UTILIZADO NO EXISTE, INTENTE NUEVAMENTE" << endl;
        PasaAnio=false;
    }
}while(PasaAnio==false);
setAnio(aux);
}

void Fecha::Muestra(){
        cout << dia << "/" << mes << "/" << anio << endl;
    }


#endif // FECHA_H_INCLUDED
