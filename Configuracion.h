#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

///BKP HABITACULOS
bool BKPhabitaculos(){
    FILE *p,*i;
    Habitaciones reg;

    int pos=0;
    p=fopen("Habit.bkp","wb");
    if(p==NULL) return false;

    while(reg.LeerDeDisco(pos++)==1){
        fwrite(&reg, sizeof reg, 1, p);
    }
    fclose(p);

    pos=0;
    i=fopen("ARCHINIhabit.bkp","wb");
    if(i==NULL) return false;
    while(reg.LeerDeDisco(pos++)==1){
        fwrite(&reg, sizeof reg, 1,i);
    }
    fclose(i);
    cout<<"ARCHIVO CON DATOS DE INICIO!"<<endl;
    return true;
}

bool RestablecerArchHabitaculos(){
    FILE *p, *bk;
    Habitaciones reg;

    bk=fopen("Habit.bkp", "rb");
    if(bk==NULL) return false;

    p=fopen("Habitaciones.dat","wb");
    if(p==NULL) {
            fclose(bk);
            return false;
    }

    fclose(p);

    while(fread(&reg, sizeof reg, 1, bk)==1){
         reg.GrabarEnDisco();
    }

    fclose(bk);
    system("pause");

    return true;
}

///BKP CLIENTES
bool BKPclientes(){
    FILE *p,*i;
    Cliente reg;

    int pos=0;
    p=fopen("Client.bkp","wb");
    if(p==NULL) return false;

    while(reg.LeerDeDisco(pos++)==1){
        fwrite(&reg, sizeof reg, 1, p);
    }
    fclose(p);

    pos=0;
    i=fopen("ARCHINIclient.bkp","wb");
    if(i==NULL) return false;
    while(reg.LeerDeDisco(pos++)==1){
        fwrite(&reg, sizeof reg, 1,i);
    }
    fclose(i);
    cout<<"ARCHIVO CON DATOS DE INICIO!"<<endl;
    return true;
}

bool RestablecerArchClientes(){
    FILE *p, *bk;
    Cliente reg;

    bk=fopen("Client.bkp", "rb");
    if(bk==NULL) return false;

    p=fopen("cliente.dat","wb");
    if(p==NULL) {
            fclose(bk);
            return false;
    }

    fclose(p);

    while(fread(&reg, sizeof reg, 1, bk)==1){
         reg.GrabarEnDisco();
    }

    fclose(bk);
    system("pause");

    return true;
}

///BKP VENTAS CABECERA
bool BKPventasCab(){
    FILE *p,*i;
    VentasCab reg;

    int pos=0;
    p=fopen("ventCab.bkp","wb");
    if(p==NULL) return false;

    while(reg.LeerDeDisco(pos++)==1){
        fwrite(&reg, sizeof reg, 1, p);
    }
    fclose(p);

    pos=0;
    i=fopen("ARCHINIventCab.bkp","wb");
    if(i==NULL) return false;
    while(reg.LeerDeDisco(pos++)==1){
        fwrite(&reg, sizeof reg, 1,i);
    }
    fclose(i);
    cout<<"ARCHIVO CON DATOS DE INICIO!"<<endl;
    return true;
}

bool RestablecerArchVentasCab(){
    FILE *p, *bk;
    VentasCab reg;

    bk=fopen("ventCab.bkp", "rb");
    if(bk==NULL) return false;

    p=fopen("ventasCab.dat","wb");
    if(p==NULL) {
            fclose(bk);
            return false;
    }

    fclose(p);

    while(fread(&reg, sizeof reg, 1, bk)==1){
         reg.GrabarEnDisco();
    }

    fclose(bk);
    system("pause");

    return true;
}

///BKP VENTAS DETALLE
bool BKPventasDet(){
    FILE *p,*i;
    VentasDet reg;

    int pos=0;
    p=fopen("ventDet.bkp","wb");
    if(p==NULL) return false;

    while(reg.LeerDeDisco(pos++)==1){
        fwrite(&reg, sizeof reg, 1, p);
    }
    fclose(p);

    pos=0;
    i=fopen("ARCHINIventDab.bkp","wb");
    if(i==NULL) return false;
    while(reg.LeerDeDisco(pos++)==1){
        fwrite(&reg, sizeof reg, 1,i);
    }
    fclose(i);
    cout<<"ARCHIVO CON DATOS DE INICIO!"<<endl;
    return true;
}

bool RestablecerArchVentasDet(){
    FILE *p, *bk;
    VentasDet reg;

    bk=fopen("ventDet.bkp", "rb");
    if(bk==NULL) return false;

    p=fopen("ventasDet.dat","wb");
    if(p==NULL) {
            fclose(bk);
            return false;
    }

    fclose(p);

    while(fread(&reg, sizeof reg, 1, bk)==1){
         reg.GrabarEnDisco();
    }

    fclose(bk);
    system("pause");

    return true;
}

///MENU
bool MenuConfig(){

setlocale(LC_ALL, "spanish");
    setConsoleTitle("VIVIRE");
    AjustarVentana(120,30);
    const int ANCHO_MENU = 40;
    const int ALTO_MENU = 9;
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
      cout << "MENU CONFIGURACION";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "1. RESTABLECER ARCHIVO HABITACULOS";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "2. RESTABLECER ARCHIVO CLIENTES";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "3. RESTABLECER ARCHIVO V. CABECERA";
      locate(POSMENUX+3,POSMENUY+7);
      cout << "4. RESTABLECER ARCHIVO V. DETALLE";
      locate(POSMENUX+3,POSMENUY+8);
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
            if(opc < 4){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 0){
                opc--;
            }else{
                opc=4;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 3;
        }else{
            cursorY = POSMENUY + 8;
        }
        locate(cursorX,cursorY);
        cout<<">";
        key = getkey();
      }
      setBackgroundColor(BLUE);
      cls();
      showcursor();
      switch(opc){
        case 1: RestablecerArchHabitaculos();
                system("pause");
                break;

        case 2: RestablecerArchClientes();
                system("pause");
                break;

        case 3: RestablecerArchVentasCab();
                system("pause");
                break;

        case 4: RestablecerArchVentasDet();
                system("pause");
                break;

        case 0: return false;
                break;

        default:cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
    }

}

#endif // CONFIGURACION_H_INCLUDED
