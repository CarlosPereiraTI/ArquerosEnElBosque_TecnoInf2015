#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 26
#define MAX_NICK 11
#define MAX_CEDULA 9
#define MAX_PARTIDAS 20
#define MAX_JUGADORES 20

using namespace std;

//GUARDA DATOS DEL JUGADOR
struct jugador{
char nombre[MAX_NOMBRE];
char nick[MAX_NICK];
char cedula[MAX_CEDULA];
int partidas_ganadas;
};

//GUARDA DATOS DE TODOS LOS JUGADORES
typedef struct jugadores{
jugador registros[MAX_JUGADORES];	
int tope;
}topejugadores;

//GUARDA DATOS DE CADA PARTIDA
struct partida{
char nick1[MAX_NICK];
char nick2[MAX_NICK];
int res1;
int res2;
};

//GUARDA DATOS DE TODAS LAS PARTIDAS
typedef struct partidas{
partida partidas_totales[MAX_PARTIDAS];
int tope;
}topepartidas;

void opcion1(char nick[], char nombreA[], char nickA[], char cedulaA[], char nombreB[], char nickB[], char cedulaB[], char nick1[], char nick2[], bool &regDatos, topepartidas &par, topejugadores &jug);//REGISTRO DE JUGADORES.
void opcion2(char nick1[], char nick2[], struct partida &res1, struct partida &res2, topepartidas &par, bool &regDatos, topejugadores &jug, struct jugador &partidas_ganadas);//JUGAR.
void opcion3(bool &regDatos, char nick[], topejugadores &jug);//CONSULTA DE PERFIL
void opcion4(topepartidas &par);//HISTORICO DE PARTIDAS
void opcion5(char nick[], topepartidas &par);//VER PARTIDAS DE UN JUGADOR
void opcion6(topejugadores &jug);//RANKING

int main(){
int opcion=0;//PARA QUE SOLAMENTE ACEPTE NUMEROS
struct jugador partidas_ganadas;
bool regDatos=false;
jugadores jug;
struct partida res1;
struct partida res2;
partidas par;
char nombreA[MAX_NOMBRE];
char nickA[MAX_NICK];
char cedulaA[MAX_CEDULA];
char nombreB[MAX_NOMBRE];
char nickB[MAX_NICK];
char cedulaB[MAX_CEDULA];
char nick1[MAX_NICK];
char nick2[MAX_NICK];
char nick[MAX_NICK];
jug.tope=0;
par.tope=0;

printf("\n");
printf("  -----------------------------------------\n");
printf("  BIENVENIDO AL JUEGO ARQUEROS EN EL BOSQUE\n");
printf("  -----------------------------------------\n");

do{
   printf("\n");
   printf("  -----------------------------------------\n");
   printf("  MENU OPCIONES.\n");
   printf("  -----------------------------------------\n");
   printf("  |1| Registrarse como jugador.\n");
   printf("  |2| Jugar.\n");
   printf("  |3| Consulta de perfil.\n");
   printf("  |4| Ver historico de partidas.\n");
   printf("  |5| Ver partidos de un jugador.\n");
   printf("  |6| Ranking de partidas.\n");
   printf("  |7| Salir del juego.\n");
   printf("  -----------------------------------------\n");
   printf("\n");
   printf("  OPCION: ");
   fflush (stdin);//LIMPIO LA ENTRADA PARA NO CAUSAR ERRORES.
   scanf("%d", &opcion);
   switch(opcion){
                  case 1:
                        opcion1(nick,nombreA,nickA,cedulaA,nombreB,nickB,cedulaB,nick1,nick2,regDatos,par,jug);
                  break;
                  case 2:
                        if(!regDatos){
							printf("\n");
							printf(" Antes de jugar debe ingresar los datos del juegador en la opcion1.\n");
                        }
                        else
                            opcion2(nick1,nick2,res1,res2,par,regDatos,jug,partidas_ganadas);
                  break;
                  case 3:
                        if(!regDatos){
							printf("\n");
							printf(" No hay jugadores registrados.\n");
                        }
                        else
                            opcion3(regDatos,nick,jug);
                  break;
                  case 4:
						opcion4(par);
                  break;
                  case 5:
                        opcion5(nick,par);
                  break;
				  case 6:
                        opcion6(jug);
                  break;
				  case 7:
                        printf("\n");
						printf("Saliendo...");
						printf("\n\n\n");
                  break;
                  default:
                          printf("\n");
                          printf(" Error, ingrese una de las 7 opciones.\n");
                  break;
    }
}while((opcion==1 || opcion==2 || opcion==3 || opcion==4 || opcion==5 || opcion==6) || (opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=5 && opcion!=6 && opcion!=7));

return 0;
}

//FUNCION 1
void opcion1(char nick[], char nombreA[], char nickA[], char cedulaA[], char nombreB[], char nickB[], char cedulaB[], char nick1[], char nick2[], bool &regDatos, topepartidas &par, topejugadores &jug){
int largo_nombre=0;
int largo_nick=0;
int largo_cedula=0;

//INGRESO DATOS JUGADOR 1
do{
   printf("\n");
   printf(" Ingrese nombre del jugador A: ");
   fflush(stdin);
   scanf("%s", nombreA);
   printf("\n");
   largo_nombre=strlen(nombreA);//LO USO PARA CONTROLAR LA CANTIDAD DE CARACTERES INGRESADAS
   if(largo_nombre==0 || largo_nombre==' ')
   {
   printf(" El nombre no puede ser vacio.\n");
   }else
        if(largo_nombre>25)//CONTROLO EL M?XIMO PARA NO PASARME DEL ARRAY Y GENERAR ERRORES EN EL PROG
        {
        printf("\n");
        printf(" Error, el nombre no puede tener mas de 25 caracteres.\n");
        }
}while(largo_nombre==0 || largo_nombre==' ' || largo_nombre>25);

//INGRESO DEL NICK
do{
   printf("\n");
   printf(" Ingrese el nick para el jugador A: ");
   fflush(stdin);
   scanf("%s",nickA);
   printf("\n");
   largo_nick=strlen(nickA);//LO USO PARA CONTROLAR LA CANTIDAD DE CARACTERES INGRESADAS.

    if(largo_nick==0 || largo_nick==' '){
		printf(" El nick no puede ser vacio.\n");
    }else
        if(largo_nick>9){//CONTROLO EL M?XIMO PARA NO PASARME DEL ARRAY Y GENERAR ERRORES EN EL PROG.
			printf("\n");
			printf(" Error, el nick no puede tener mas de 10 caracteres.\n");
        }
}while(largo_nick==0 || largo_nick==' ' || largo_nick>10);

//INGRESO DE LA CEDULA.
do{
   printf("\n");
   printf(" Ingrese la cedula del jugador A: ");
   fflush(stdin);
   scanf("%s",cedulaA);
   printf("\n");
   largo_cedula=strlen(cedulaA);//LO USO PARA CONTROLAR LA CANTIDAD DE CARACTERES INGRESADAS.
   if(largo_cedula==0 || largo_cedula==' '){
		printf(" La cedula no puede ser vacia.\n");
   }else
        if(largo_cedula>8){//CONTROLO EL M?XIMO PARA NO PASARME DEL ARRAY Y GENERAR ERRORES EN EL PROG.
			printf("\n");
			printf(" Error, la cedula no puede tener mas de 8 caracteres.\n");
        }
}while(largo_cedula==0 || largo_cedula==' ' || largo_cedula>8);

strcpy(jug.registros[jug.tope].nombre,nombreA);//COPIA EL NOMBRE A LA ESTRUCTURA
strcpy(jug.registros[jug.tope].nick,nickA);//COPIA EL NICK A LA ESTRUCTURA
strcpy(par.partidas_totales[par.tope].nick1,nickA);
strcpy(jug.registros[jug.tope].cedula,cedulaA);//COPIA LA CEDULA A LA ESTRUCTURA
jug.registros[jug.tope].partidas_ganadas=0;
jug.tope++;

//INGRESO DATOS JUGADOR 2
do{
   printf("\n");
   printf(" Ingrese nombre del jugador B: ");
   fflush(stdin);
   scanf("%s",nombreB);
   printf("\n");
   largo_nombre=strlen(nombreB);//LO USO PARA CONTROLAR LA CANTIDAD DE CARACTERES INGRESADAS
   if(largo_nombre==0 || largo_nombre==' ')
   {
   printf(" El nombre no puede ser vacio.\n");
   }else
        if(largo_nombre>25)//CONTROLO EL M?XIMO PARA NO PASARME DEL ARRAY Y GENERAR ERRORES EN EL PROG
        {
        printf("\n");
        printf(" Error, el nombre no puede tener mas de 25 caracteres.\n");
        }
}while(largo_nombre==0 || largo_nombre==' ' || largo_nombre>25);

//INGRESO DEL NICK
do{
   printf("\n");
   printf(" Ingrese el nick para el jugador B: ");
   fflush(stdin);
   scanf("%s",nickB);
   printf("\n");
   largo_nick=strlen(nickB);//LO USO PARA CONTROLAR LA CANTIDAD DE CARACTERES INGRESADAS.

   if(largo_nick==0 || largo_nick==' '){
		printf(" El nick no puede ser vacio.\n");
   }else
        if(largo_nick>9){//CONTROLO EL M?XIMO PARA NO PASARME DEL ARRAY Y GENERAR ERRORES EN EL PROG.
			printf("\n");
			printf(" Error, el nick no puede tener mas de 10 caracteres.\n");
        }
}while(largo_nick==0 || largo_nick==' ' || largo_nick>10);

//INGRESO DE LA CEDULA.
do{
   printf("\n");
   printf(" Ingrese la cedula del jugador B: ");
   fflush(stdin);
   scanf("%s", cedulaB);
   printf("\n");
   largo_cedula=strlen(cedulaB);//LO USO PARA CONTROLAR LA CANTIDAD DE CARACTERES INGRESADAS.
   if(largo_cedula==0 || largo_cedula==' '){
		printf(" La cedula no puede ser vacia.\n");
   }else
        if(largo_cedula>8){//CONTROLO EL M?XIMO PARA NO PASARME DEL ARRAY Y GENERAR ERRORES EN EL PROG.
			printf("\n");
			printf(" Error, la cedula no puede tener mas de 8 caracteres.\n");
        }
}while(largo_cedula==0 || largo_cedula==' ' || largo_cedula>8);

strcpy(jug.registros[jug.tope].nombre,nombreB);//COPIA EL NOMBRE A LA ESTRUCTURA
strcpy(jug.registros[jug.tope].nick,nickB);//COPIA EL NICK A LA ESTRUCTURA
strcpy(par.partidas_totales[par.tope].nick2,nickB);
strcpy(jug.registros[jug.tope].cedula,cedulaB);//COPIA LA CEDULA A LA ESTRUCTURA
jug.registros[jug.tope].partidas_ganadas=0;
jug.tope++;

regDatos=true;
//LO PONGO EN TRUE, HABILITANDO A ELEGIR LA OPCION 2 LUEGO DE REGISTRAR LOS DOS JUGADORES.
//LO ARRANCO EN FALSE EN EL MAIN() PARA QUE NO PUEDA JUGAR SIN REGISTRARSE ANTES.
}

//FUNCION 2
void opcion2(char nick1[], char nick2[], struct partida &res1, struct partida &res2, topepartidas &par, bool &regDatos, topejugadores &jug, struct jugador &partidas_ganadas){
	//Definicion de variables
    int fil, col, f, c, arboles, cont_arboles=0, max_arboles, dist_flecha, max_dist_flecha, puntosA=0, puntosB=0, roundsA=0, roundsB=0, partidasA=0, partidasB=0;
    char jug1='A', jug2='B', arbol='X', select_jug, mov, fle, accion, opcion;
    srand(time(0));

    system("cls");
    printf("\n");
    printf("  >> Debe elegir las dimensiones del bosque:\n\n");
    printf("  Ingrese la cantidad de filas: ");
    fflush(stdin);
    scanf("%d", &fil);
    printf("\n");

    //Control del tama?o de la matriz
    do{
        printf("  Ingrese la cantidad de columnas: ");
        fflush(stdin);
        scanf("%d", &col);
        printf("\n");

        if(col!=fil){
            printf("  >> ATENCION <<\n\n");
            printf("  Valor incorrecto, el numero de columnas debe ser igual al de filas!\n");
        }
    }while(col!=fil);

    //Defino las variables a utilizar en los movimientos
    char bosque[fil+1][col+1];
    int posaf=fil, posac=1, posbf=1, posbc=col, ant_posaf, ant_posac, ant_posbf, ant_posbc;
    int fle_af, fle_ac, fle_bf, fle_bc;

    //Defino la matriz
    for(f=0; f<fil+1; f++){
        for(c=0; c<col+1; c++){
            bosque[f][c]=' ';
            bosque[0][0]=' ';
            bosque[f][0]=48+f;
            bosque[0][c]=64+c;
            bosque[fil][1]=jug1;
            bosque[1][col]=jug2;
        }
    }

    //Controlo la cantidad de arboles segun las dimensiones
    max_arboles=(fil*col)*0.25;
    do{
        printf("  Ingrese la cantidad de arboles que tendra el bosque: ");
	fflush(stdin);
        scanf("%d", &arboles);
        printf("\n");

        if(arboles>max_arboles){
            printf("  >> ATENCION <<\n");
            printf("  La cantidad de arboles debe ser menor o igual a %d\n\n", max_arboles);
        }
    }while(arboles>max_arboles);

    //Distancia maxima que puede alcanzar una flecha
    max_dist_flecha=fil*0.5;

    //Indica distancia que debe alcanzar la flecha
    do{
        printf("  Ingrese la distancia maxima que puede alcanzar la flecha: ");
	fflush(stdin);
        scanf("%d", &dist_flecha);
        printf("\n");

        if(dist_flecha>max_dist_flecha){
            printf("  >> ATENCION <<\n\n");
            printf("  La distancia maxima no puede superar %d\n", max_dist_flecha);
        }
    }while(dist_flecha>max_dist_flecha);

    //Eleccion del jugador que comienza la partida
    do{
        printf("  Seleccione el jugador que comenzara jugando A: %s | B: %s: ", par.partidas_totales[par.tope].nick1, par.partidas_totales[par.tope].nick2);
        fflush(stdin);
        scanf("%c", &select_jug);
        printf("\n");

        if(select_jug!='A' && select_jug!='B'){
            printf("  >> ATENCION <<\n\n");
            printf("  Error, debe seleccionar el jugador A o B!\n");
        }
    }while(select_jug!='A' && select_jug!='B');

    //Desparramo los arboles en el bosque.
    while(cont_arboles!=arboles){
        int arbolf=1+rand()%(fil);
        int arbolc=1+rand()%(col);
        bosque[arbolf][arbolc]=arbol;
        bosque[fil][1]=jug1;
        bosque[1][col]=jug2;
        cont_arboles++;
    }

    //Llevo el contador de arboles a cero
    //Esto me va ser de utilidad cuando tenga que comenzar una nueva partida luego que uno de los jugadores marca un punto.
    cont_arboles=0;

    system("cls");
    //Imprimo la matriz
    for(f=0; f<fil+1; f++){
        printf("\n");
        for(c=0; c<col+1; c++){
            printf(" %c |", bosque[f][c]);
        }
    printf("\n");
    }

    //Comienzo del juego
    do{
    //Si juega el A
    do{
    if(select_jug=='A'){
        printf("  Juega %s.\n", par.partidas_totales[par.tope].nick1);
        bosque[posaf][posac]=jug1;

        printf("  Seleccione una de las siguientes acciones:\n");
        printf("  M - Para moverse a otra celda.\n");
        printf("  F - Para disparar una flecha.\n");
        printf("  Accion -> ");
		fflush(stdin);
        scanf("%c", &accion);
        printf("\n");

        //Jugador A selecciona el movimiento
        if(accion=='M'){
                do{
                    printf("  Seleccione el movimiento:\n");
                    printf("  U - Arriba.\n");
                    printf("  H - Izquierda.\n");
                    printf("  J - Abajo.\n");
                    printf("  K - Derecha.\n");
                    printf("  Movimiento -> ");
		    fflush(stdin);
                    scanf("%c", &mov);
                    printf("\n\n");

                    switch(mov){
                        case 'U': case 'u'://MOVIMIENTO ARRIBA
                            ant_posaf=posaf--;
                            ant_posac=posac;

                            //Control en caso de que haya un arbol
                            if(bosque[posaf][posac]=='X'){
                                ant_posaf=posaf++;
                                ant_posac=posac;
                                printf("  No puede moverse ahi, hay un arbol!\n");
                                bosque[ant_posaf][ant_posac]='X';
                                bosque[posaf][posac]=jug1;
                                for(f=0; f<fil+1; f++){
                                    printf("\n");
                                    for(c=0; c<col+1; c++){
                                        printf(" %c |", bosque[f][c]);
                                    }
                                printf("\n");
                                }
                            select_jug='B';
                            }
                            else
                                if(posaf==0){
                                    ++posaf;
                                    bosque[ant_posaf][ant_posac]=jug1;
                                    for(f=0; f<fil+1; f++){
                                        printf("\n");
                                        for(c=0; c<col+1; c++){
                                            printf(" %c |", bosque[f][c]);
                                        }
                                    printf("\n");
                                    }
                                    select_jug='B';
                                }
                                else
                                    if(bosque[posaf][posac]!='X' && posaf!=0){
                                        bosque[ant_posaf][ant_posac]='-';
                                        bosque[posaf][posac]=jug1;
                                        for(f=0; f<fil+1; f++){
                                            printf("\n");
                                            for(c=0; c<col+1; c++){
                                            printf(" %c |", bosque[f][c]);
                                            }
                                        printf("\n");
                                        }
                                    select_jug='B';
                                    bosque[ant_posaf][ant_posac]=' ';
                                    }
                            break;
                        case 'H': case 'h'://MOVIMIENTO IZQUIERDA
                            ant_posaf=posaf;
                            ant_posac=posac--;

                            //Control en caso que hay un arbol
                            if(bosque[posaf][posac]=='X'){
                                ant_posaf=posaf;
                                ant_posac=posac++;
                                printf("  No puede moverse ahi, hay un arbol!\n");
                                bosque[ant_posaf][ant_posac]='X';
                                bosque[posaf][posac]=jug1;
                                for(f=0; f<fil+1; f++){
                                    printf("\n");
                                    for(c=0; c<col+1; c++){
                                        printf(" %c |", bosque[f][c]);
                                    }
                                printf("\n");
                                }
                            select_jug='B';
                            }
                            else
                                if(posac==0){
                                    ++posac;
                                    bosque[ant_posaf][ant_posac]=jug1;
                                    for(f=0; f<fil+1; f++){
                                        printf("\n");
                                        for(c=0; c<col+1; c++){
                                            printf(" %c |", bosque[f][c]);
                                        }
                                    printf("\n");
                                    }
                                    select_jug='B';
                                }
                                else
                                    if(bosque[posaf][posac]!='X' && posac!=0){
                                        bosque[ant_posaf][ant_posac]='-';
                                        bosque[posaf][posac]=jug1;
                                        for(f=0; f<fil+1; f++){
                                            printf("\n");
                                            for(c=0; c<col+1; c++){
                                                printf(" %c |", bosque[f][c]);
                                            }
                                        printf("\n");
                                        }
                                    select_jug='B';
                                    bosque[ant_posaf][ant_posac]=' ';
                                    }
                            break;
                        case 'J': case 'j'://MOVIMIENTO ABAJO
                            ant_posaf=posaf++;
                            ant_posac=posac;

                            //Control en caso que haya un arbol
                            if(bosque[posaf][posac]=='X'){
                                ant_posaf=posaf--;
                                ant_posac=posac;
                                printf("  No puede moverse ahi, hay un arbol!\n");
                                bosque[ant_posaf][ant_posac]='X';
                                bosque[posaf][posac]=jug1;
                                for(f=0; f<fil+1; f++){
                                    printf("\n");
                                    for(c=0; c<col+1; c++){
                                        printf(" %c |", bosque[f][c]);
                                    }
                                printf("\n");
                                }
                            select_jug='B';
                            }
                            else
                                if(posaf==fil+1){
                                    --posaf;
                                    bosque[ant_posaf][ant_posac]=jug1;
                                    for(f=0; f<fil+1; f++){
                                        printf("\n");
                                        for(c=0; c<col+1; c++){
                                            printf(" %c |", bosque[f][c]);
                                        }
                                    printf("\n");
                                    }
                                    select_jug='B';
                                }
                                else
                                    if(bosque[posaf][posac]!='X' && posaf!=fil+1){
                                        bosque[ant_posaf][ant_posac]='-';
                                        bosque[posaf][posac]=jug1;
                                        for(f=0; f<fil+1; f++){
                                            printf("\n");
                                            for(c=0; c<col+1; c++){
                                                printf(" %c |", bosque[f][c]);
                                            }
                                        printf("\n");
                                        }
                                    select_jug='B';
                                    bosque[ant_posaf][ant_posac]=' ';
                                    }
                            break;
                        case 'K': case 'k'://MOVIMIENTO DERECHA
                            ant_posaf=posaf;
                            ant_posac=posac++;

                            //Control en caso que hay un arbol
                            if(bosque[posaf][posac]=='X'){
                                ant_posaf=posaf;
                                ant_posac=posac--;
                                printf("  No puede moverse ahi, hay un arbol!\n");
                                bosque[ant_posaf][ant_posac]='X';
                                bosque[posaf][posac]=jug1;
                                for(f=0; f<fil+1; f++){
                                printf("\n");
                                for(c=0; c<col+1; c++){
                                    printf(" %c |", bosque[f][c]);
                                }
                                printf("\n");
                                }
                            select_jug='B';
                            }
                            else
                                if(posac==col+1){
                                    --posac;
                                    bosque[ant_posaf][ant_posac]=jug1;
                                    for(f=0; f<fil+1; f++){
                                        printf("\n");
                                        for(c=0; c<col+1; c++){
                                            printf(" %c |", bosque[f][c]);
                                        }
                                    printf("\n");
                                    }
                                    select_jug='B';
                                }
                                else
                                    if(bosque[posaf][posac]!='X' && posac!=col+1){
                                        bosque[ant_posaf][ant_posac]='-';
                                        bosque[posaf][posac]=jug1;
                                        for(f=0; f<fil+1; f++){
                                            printf("\n");
                                            for(c=0; c<col+1; c++){
                                                printf(" %c |", bosque[f][c]);
                                            }
                                        printf("\n");
                                        }
                                    select_jug='B';
                                    bosque[ant_posaf][ant_posac]=' ';
                                    }
                            break;
                        default:
                            printf("  >> ATENCION <<\n\n");
                            printf("  Movimiento incorrecto, seleccione uno valido!\n");
                            break;
                    }
                }while(mov!='U' && mov!='u' && mov!='H' && mov!='h' && mov!='J' && mov!='j' && mov!='K' && mov!='K' && bosque[posaf][posac]!='X');
        }
        else
            if(accion=='F'){//Jugador A selecciona disparar el flechazo
                do{
                    printf("  Elija hacia donde disparar la flecha:\n");
                    printf("  U - Arriba.\n");
                    printf("  H - Izquierda.\n");
                    printf("  J - Abajo.\n");
                    printf("  K - Derecha.\n");
                    printf("  Disparo -> ");
		    fflush(stdin);
                    scanf("%c", &fle);
                    printf("\n\n");

                    switch(fle){
                        case 'U': case 'u'://FLECHAZO ARRIBA
                            bosque[posaf][posac]=jug1;
                            for(int rec_flecha=1; rec_flecha<=dist_flecha; rec_flecha++){
                                fle_af=posaf-rec_flecha;
                                fle_ac=posac;
                                if(fle_af==0){
                                    ++fle_af;
                                    select_jug='A';
                                }
                                else
                                    if(bosque[fle_af][fle_ac]=='X' && bosque[fle_af][fle_ac]!='B'){
                                        printf("  Disparo erroneo, hay un arbol!\n");
                                        dist_flecha=rec_flecha;
                                        select_jug='B';
                                    }
                                    else
                                        if(bosque[fle_af][fle_ac]!='X' && bosque[fle_af][fle_ac]!='B'){
                                            printf("  Disparo al vacio!\n");
                                            select_jug='B';
                                        }
                                        else
                                            if(bosque[fle_af][fle_ac]!='X' && bosque[fle_af][fle_ac]=='B'){
                                                printf("  ------------------------------\n");
                                                printf("           BUEN DISPARO !!\n");
                                                printf("  ------------------------------\n");
                                                dist_flecha=rec_flecha;
                                                bosque[posbf][posbc]='>';
                                                select_jug='B';
                                                puntosA++;
                                                roundsA++;
                                            }
                            }
                            for(f=0; f<fil+1; f++){
                                printf("\n");
                                for(c=0; c<col+1; c++){
                                    printf(" %c |", bosque[f][c]);
                                }
                                printf("\n");
                            }
                            select_jug='B';
                            break;
                        case 'H': case 'h'://FLECHAZO IZQUIERDA
                            bosque[posaf][posac]=jug1;
                            for(int rec_flecha=1; rec_flecha<=dist_flecha; rec_flecha++){
                                fle_af=posaf;
                                fle_ac=posac-rec_flecha;
                                if(fle_ac==0){
                                    ++fle_ac;
                                    select_jug='A';
                                }
                                else
                                    if(bosque[fle_af][fle_ac]=='X' && bosque[fle_af][fle_ac]!='B'){
                                        printf("  Disparo erroneo, hay un arbol!\n");
                                        dist_flecha=rec_flecha;
                                        select_jug='B';
                                    }
                                    else
                                        if(bosque[fle_af][fle_ac]!='X' && bosque[fle_af][fle_ac]!='B'){
                                            printf("  Disparo al vacio!\n");
                                            select_jug='B';
                                        }
                                        else
                                            if(bosque[fle_af][fle_ac]!='X' && bosque[fle_af][fle_ac]=='B'){
                                                printf("  ------------------------------\n");
                                                printf("           BUEN DISPARO !!\n");
                                                printf("  ------------------------------\n");
                                                dist_flecha=rec_flecha;
                                                bosque[posbf][posbc]='>';
                                                select_jug='B';
                                                puntosA++;
                                                roundsA++;
                                            }
                            }
                            for(f=0; f<fil+1; f++){
                                printf("\n");
                                for(c=0; c<col+1; c++){
                                    printf(" %c |", bosque[f][c]);
                                }
                                printf("\n");
                            }
                            select_jug='B';
                            break;
                        case 'J': case 'j'://FLECHAZO ABAJO
                            bosque[posaf][posac]=jug1;
                            for(int rec_flecha=1; rec_flecha<=dist_flecha; rec_flecha++){
                                fle_af=posaf+rec_flecha;
                                fle_ac=posac;
                                if(fle_af==dist_flecha){
                                    --fle_af;
                                    select_jug='A';
                                }
                                else
                                    if(bosque[fle_af][fle_ac]=='X' && bosque[fle_af][fle_ac]!='B'){
                                        printf("  Disparo erroneo, hay un arbol!\n");
                                        dist_flecha=rec_flecha;
                                        select_jug='B';
                                    }
                                    else
                                        if(bosque[fle_af][fle_ac]!='X' && bosque[fle_af][fle_ac]!='B'){
                                            printf("  Disparo al vacio!\n");
                                            select_jug='B';
                                        }
                                        else
                                            if(bosque[fle_af][fle_ac]!='X' && bosque[fle_af][fle_ac]=='B'){
                                                printf("  ------------------------------\n");
                                                printf("           BUEN DISPARO !!\n");
                                                printf("  ------------------------------\n");
                                                dist_flecha=rec_flecha;
                                                bosque[posbf][posbc]='>';
                                                select_jug='B';
                                                puntosA++;
                                                roundsA++;
                                            }
                            }
                            for(f=0; f<fil+1; f++){
                                printf("\n");
                                for(c=0; c<col+1; c++){
                                    printf(" %c |", bosque[f][c]);
                                }
                                printf("\n");
                            }
                            select_jug='B';
                            break;
                        case 'K': case 'k'://FLECHAZO DERECHA
                            bosque[posaf][posac]=jug1;
                            for(int rec_flecha=1; rec_flecha<=dist_flecha; rec_flecha++){
                                fle_af=posaf;
                                fle_ac=posac+rec_flecha;
                                if(fle_ac==dist_flecha){
                                    --fle_ac;
                                    select_jug='A';
                                }
                                else
                                    if(bosque[fle_af][fle_ac]=='X' && bosque[fle_af][fle_ac]!='B'){
                                        printf("  Disparo erroneo, hay un arbol!\n");
                                        dist_flecha=rec_flecha;
                                        select_jug='B';
                                    }
                                    else
                                        if(bosque[fle_af][fle_ac]!='X' && bosque[fle_af][fle_ac]!='B'){
                                            printf("  Disparo al vacio!\n");
                                            select_jug='B';
                                        }
                                        else
                                            if(bosque[fle_af][fle_ac]!='X' && bosque[fle_af][fle_ac]=='B'){
                                                printf("  ------------------------------\n");
                                                printf("           BUEN DISPARO !!\n");
                                                printf("  ------------------------------\n");
                                                dist_flecha=rec_flecha;
                                                bosque[posbf][posbc]='>';
                                                select_jug='B';
                                                puntosA++;
                                                roundsA++;
                                            }
                            }
                            for(f=0; f<fil+1; f++){
                                printf("\n");
                                for(c=0; c<col+1; c++){
                                    printf(" %c |", bosque[f][c]);
                                }
                                printf("\n");
                            }
                            select_jug='B';
                            break;
                        default:
                            printf("  Opcion incorrecta, elija un objetivo valido!\n");
                            break;
                    }
                }while(fle!='U' && fle!='u' && fle!='H' && fle!='h' && fle!='J' && fle!='j' && fle!='K' && fle!='K');
        }
    }
    else
        if(select_jug=='B'){

            printf("  Juega %s.\n", par.partidas_totales[par.tope].nick2);

            bosque[posbf][posbc]=jug2;

            printf("  Seleccione una de las siguientes acciones:\n");
            printf("  M - Para moverse a otra celda.\n");
            printf("  F - Para disparar una flecha.\n");
            printf("  Accion -> ");
	    fflush(stdin);
            scanf("%c", &accion);
            printf("\n\n");

            //Jugador B selecciona movimiento
            if(accion=='M'){
                    do{
                        printf("  Seleccione el movimiento:\n");
                        printf("  U - Arriba.\n");
                        printf("  H - Izquierda.\n");
                        printf("  J - Abajo.\n");
                        printf("  K - Derecha.\n");
                        printf("  Movimiento -> ");
		        fflush(stdin);
                        scanf("%c", &mov);
                        printf("\n\n");

                        switch(mov){
                            case 'U': case 'u'://MOVIMIENTO ARRIBA
                                ant_posbf=posbf--;
                                ant_posbc=posbc;

                                //Control que no haya un arbol
                                if(bosque[posbf][posbc]=='X'){
                                    ant_posbf=posbf++;
                                    ant_posbc=posbc;
                                    printf("  No puede moverse ahi, hay un arbol!\n");
                                    bosque[ant_posbf][ant_posbc]='X';
                                    bosque[posbf][posbc]=jug2;
                                    for(f=0; f<fil+1; f++){
                                        printf("\n");
                                        for(c=0; c<col+1; c++){
                                            printf(" %c |", bosque[f][c]);
                                        }
                                    printf("\n");
                                    }
                                select_jug='A';
                                }
                                else
                                    if(posbf==0){
                                        ++posbf;
                                        bosque[ant_posbf][ant_posbc]=jug2;
                                        for(f=0; f<fil+1; f++){
                                            printf("\n");
                                            for(c=0; c<col+1; c++){
                                                printf(" %c |", bosque[f][c]);
                                            }
                                        printf("\n");
                                        }
                                    select_jug='A';
                                    }
                                    else
                                        if(bosque[posbf][posbc]!='X' && posbf!=0){
                                            bosque[ant_posbf][ant_posbc]='-';
                                            bosque[posbf][posbc]=jug2;
                                            for(f=0; f<fil+1; f++){
                                                printf("\n");
                                                for(c=0; c<col+1; c++){
                                                    printf(" %c |", bosque[f][c]);
                                                }
                                            printf("\n");
                                            }
                                        select_jug='A';
                                        bosque[ant_posbf][ant_posbc]=' ';
                                        }
                                break;
                            case 'H': case 'h'://MOVIMIENTO IZQUIERDA
                                ant_posbf=posbf;
                                ant_posbc=posbc--;

                                //Controlo que no hay un arbol
                                if(bosque[posbf][posbc]=='X'){
                                    ant_posbf=posbf;
                                    ant_posbc=posbc++;
                                    printf("  No puede moverse ahi, hay un arbol!\n");
                                    bosque[ant_posbf][ant_posbc]='X';
                                    bosque[posbf][posbc]=jug2;
                                    for(f=0; f<fil+1; f++){
                                        printf("\n");
                                        for(c=0; c<col+1; c++){
                                            printf(" %c |", bosque[f][c]);
                                        }
                                    printf("\n");
                                    }
                                select_jug='A';
                                }
                                else
                                    if(posbc==0){
                                        ++posbc;
                                        bosque[ant_posbf][ant_posbc]=jug2;
                                        for(f=0; f<fil+1; f++){
                                            printf("\n");
                                            for(c=0; c<col+1; c++){
                                                printf(" %c |", bosque[f][c]);
                                            }
                                        printf("\n");
                                        }
                                    select_jug='A';
                                    }
                                    else
                                        if(bosque[posbf][posbc]!='X' && posbc!=0){
                                            bosque[ant_posbf][ant_posbc]='-';
                                            bosque[posbf][posbc]=jug2;
                                            for(f=0; f<fil+1; f++){
                                                printf("\n");
                                                for(c=0; c<col+1; c++){
                                                    printf(" %c |", bosque[f][c]);
                                                }
                                            printf("\n");
                                            }
                                        select_jug='A';
                                        bosque[ant_posbf][ant_posbc]=' ';
                                        }
                                break;
                            case 'J': case 'j'://MOVIMIENTO ABAJO
                                ant_posbf=posbf++;
                                ant_posbc=posbc;

                                //Controlo que no haya un arbol
                                if(bosque[posbf][posbc]=='X'){
                                    ant_posbf=posbf--;
                                    ant_posbc=posbc;
                                    printf("  No puede moverse ahi, hay un arbol!\n");
                                    bosque[ant_posbf][ant_posbc]='X';
                                    bosque[posbf][posbc]=jug2;
                                    for(f=0; f<fil+1; f++){
                                        printf("\n");
                                        for(c=0; c<col+1; c++){
                                        printf(" %c |", bosque[f][c]);
                                        }
                                    printf("\n");
                                    }
                                select_jug='A';
                                }
                                else
                                    if(posbf==fil+1){
                                        --posbf;
                                        bosque[ant_posbf][ant_posbc]=jug2;
                                        for(f=0; f<fil+1; f++){
                                            printf("\n");
                                            for(c=0; c<col+1; c++){
                                                printf(" %c |", bosque[f][c]);
                                            }
                                        printf("\n");
                                        }
                                        select_jug='A';
                                    }
                                    else
                                        if(bosque[posbf][posbc]!='X' && posbf!=fil+1){
                                        bosque[ant_posbf][ant_posbc]='-';
                                        bosque[posbf][posbc]=jug2;
                                        for(f=0; f<fil+1; f++){
                                            printf("\n");
                                            for(c=0; c<col+1; c++){
                                                printf(" %c |", bosque[f][c]);
                                            }
                                        printf("\n");
                                        }
                                        select_jug='A';
                                        bosque[ant_posbf][ant_posbc]=' ';
                                        }
                                break;
                            case 'K': case 'k'://MOVIMIENTO DERECHA
                                ant_posbf=posbf;
                                ant_posbc=posbc++;

                                //Controlo que no haya un arbol
                                if(bosque[posbf][posbc]=='X'){
                                    ant_posbf=posbf;
                                    ant_posbc=posbc--;
                                    printf("  No puede moverse ahi, hay un arbol!\n");
                                    bosque[ant_posbf][ant_posbc]='X';
                                    bosque[posbf][posbc]=jug2;
                                    for(f=0; f<fil+1; f++){
                                        printf("\n");
                                        for(c=0; c<col+1; c++){
                                            printf(" %c |", bosque[f][c]);
                                        }
                                    printf("\n");
                                    }
                                select_jug='A';
                                }
                                else
                                    if(posbc==col+1){
                                        --posbf;
                                        bosque[ant_posbf][ant_posbc]=jug2;
                                        for(f=0; f<fil+1; f++){
                                            printf("\n");
                                            for(c=0; c<col+1; c++){
                                                printf(" %c |", bosque[f][c]);
                                            }
                                        printf("\n");
                                        }
                                    select_jug='A';
                                    }
                                    else
                                        if(bosque[posbf][posbc]!='X' && posbc!=col+1){
                                            bosque[ant_posbf][ant_posbc]='-';
                                            bosque[posbf][posbc]=jug2;
                                            for(f=0; f<fil+1; f++){
                                                printf("\n");
                                                for(c=0; c<col+1; c++){
                                                    printf(" %c |", bosque[f][c]);
                                                }
                                            printf("\n");
                                            }
                                        select_jug='A';
                                        bosque[ant_posbf][ant_posbc]=' ';
                                        }
                                break;
                            default:
                                printf("  Movimiento incorrecto, seleccione uno valido!\n");
                                break;
                        }
                    }while(mov!='U' && mov!='u' && mov!='H' && mov!='h' && mov!='J' && mov!='j' && mov!='K' && mov!='K');
            }
            else
                if(accion=='F'){//Jugador B selecciona el flechazo
                do{
                    printf("  Elija hacia donde disparar la flecha:\n");
                    printf("  U - Arriba.\n");
                    printf("  H - Izquierda.\n");
                    printf("  J - Abajo.\n");
                    printf("  K - Derecha.\n");
                    printf("  Disparo -> ");
		    fflush(stdin);
                    scanf("%c", &fle);
                    printf("\n\n");

                    switch(fle){
                        case 'U': case 'u'://FLECHAZO ARIIBA
                            bosque[posbf][posbc]=jug2;
                            for(int rec_flecha=1; rec_flecha<=dist_flecha; rec_flecha++){
                                fle_bf=posbf-rec_flecha;
                                fle_bc=posbc;
                                if(fle_bf==0){
                                    ++fle_bf;
                                    select_jug='B';
                                }
                                else
                                    if(bosque[fle_bf][fle_bc]=='X' && bosque[fle_bf][fle_bc]!='A'){
                                        printf("  Disparo erroneo, hay un arbol!\n");
                                        dist_flecha=rec_flecha;
                                        select_jug='A';
                                    }
                                    else
                                        if(bosque[fle_bf][fle_bc]!='X' && bosque[fle_bf][fle_bc]!='A'){
                                            printf("  Disparo al vacio!\n");
                                            select_jug='A';
                                        }
                                        else
                                            if(bosque[fle_bf][fle_bc]!='X' && bosque[fle_bf][fle_bc]=='A'){
                                                printf("  ------------------------------\n");
                                                printf("           BUEN DISPARO !!\n");
                                                printf("  ------------------------------\n");
                                                dist_flecha=rec_flecha;
                                                bosque[posaf][posac]='<';
                                                select_jug='A';
                                                puntosB++;
                                                roundsB++;
                                            }
                            }
                            for(f=0; f<fil+1; f++){
                                printf("\n");
                                for(c=0; c<col+1; c++){
                                    printf(" %c |", bosque[f][c]);
                                }
                                printf("\n");
                            }
                            select_jug='A';
                            break;
                        case 'H': case 'h'://FLECHAZO IZQUIERDA
                            bosque[posbf][posbc]=jug2;
                            for(int rec_flecha=1; rec_flecha<=dist_flecha; rec_flecha++){
                                fle_bf=posbf;
                                fle_bc=posbc-rec_flecha;
                                if(fle_bc==0){
                                    ++fle_bc;
                                    select_jug='B';
                                }
                                else
                                    if(bosque[fle_bf][fle_bc]=='X' && bosque[fle_bf][fle_bc]!='A'){
                                        printf("  Disparo erroneo, hay un arbol!\n");
                                        dist_flecha=rec_flecha;
                                        select_jug='A';
                                    }
                                    else
                                        if(bosque[fle_bf][fle_bc]!='X' && bosque[fle_bf][fle_bc]!='A'){
                                            printf("  Disparo al vacio!\n");
                                            select_jug='A';
                                        }
                                        else
                                            if(bosque[fle_bf][fle_bc]!='X' && bosque[fle_bf][fle_bc]=='A'){
                                                printf("  ------------------------------\n");
                                                printf("           BUEN DISPARO !!\n");
                                                printf("  ------------------------------\n");
                                                dist_flecha=rec_flecha;
                                                bosque[posaf][posac]='<';
                                                select_jug='A';
                                                puntosB++;
                                                roundsB++;
                                            }
                            }
                            for(f=0; f<fil+1; f++){
                                printf("\n");
                                for(c=0; c<col+1; c++){
                                    printf(" %c |", bosque[f][c]);
                                }
                                printf("\n");
                            }
                            select_jug='A';
                            break;
                        case 'J': case 'j'://FLECHAZO ABAJO
                            bosque[posbf][posbc]=jug2;
                            for(int rec_flecha=1; rec_flecha<=dist_flecha; rec_flecha++){
                                fle_bf=posbf+rec_flecha;
                                fle_bc=posbc;
                                if(fle_bf==dist_flecha){
                                    --fle_bf;
                                    select_jug='B';
                                }
                                else
                                    if(bosque[fle_bf][fle_bc]=='X' && bosque[fle_bf][fle_bc]!='A'){
                                        printf("  Disparo erroneo, hay un arbol!\n");
                                        dist_flecha=rec_flecha;
                                        select_jug='A';
                                    }
                                    else
                                        if(bosque[fle_bf][fle_bc]!='X' && bosque[fle_bf][fle_bc]!='A'){
                                            printf("  Disparo al vacio!\n");
                                            select_jug='A';
                                        }
                                        else
                                            if(bosque[fle_bf][fle_bc]!='X' && bosque[fle_bf][fle_bc]=='A'){
                                                printf("  ------------------------------\n");
                                                printf("           BUEN DISPARO !!\n");
                                                printf("  ------------------------------\n");
                                                dist_flecha=rec_flecha;
                                                bosque[posaf][posac]='<';
                                                select_jug='A';
                                                puntosB++;
                                                roundsB++;
                                            }
                            }
                            for(f=0; f<fil+1; f++){
                                printf("\n");
                                for(c=0; c<col+1; c++){
                                    printf(" %c |", bosque[f][c]);
                                }
                                printf("\n");
                            }
                            select_jug='A';
                            break;
                        case 'K': case 'k'://FLECHAZO DERECHA
                            bosque[posbf][posbc]=jug2;
                            for(int rec_flecha=1; rec_flecha<=dist_flecha; rec_flecha++){
                                fle_bf=posbf;
                                fle_bc=posbc+rec_flecha;
                                if(fle_bc==dist_flecha){
                                    --fle_bc;
                                    select_jug='B';
                                }
                                else
                                    if(bosque[fle_bf][fle_bc]=='X' && bosque[fle_bf][fle_bc]!='A'){
                                        printf("  Disparo erroneo, hay un arbol!\n");
                                        dist_flecha=rec_flecha;
                                        select_jug='A';
                                    }
                                    else
                                        if(bosque[fle_bf][fle_bc]!='X' && bosque[fle_bf][fle_bc]!='A'){
                                            printf("  Disparo al vacio!\n");
                                            select_jug='A';
                                        }
                                        else
                                            if(bosque[fle_bf][fle_bc]!='X' && bosque[fle_bf][fle_bc]=='A'){
                                                printf("  ------------------------------\n");
                                                printf("           BUEN DISPARO !!\n");
                                                printf("  ------------------------------\n");
                                                dist_flecha=rec_flecha;
                                                bosque[posaf][posac]='<';
                                                select_jug='A';
                                                puntosB++;
                                                roundsB++;
                                            }
                            }
                            for(f=0; f<fil+1; f++){
                                printf("\n");
                                for(c=0; c<col+1; c++){
                                    printf(" %c |", bosque[f][c]);
                                }
                                printf("\n");
                            }
                            select_jug='A';
                            break;
                        default:
                            printf("  Opcion incorrecta, elija un objetivo valido!\n");
                            break;
                    }
                }while(fle!='U' && fle!='u' && fle!='H' && fle!='h' && fle!='J' && fle!='j' && fle!='K' && fle!='k');
                }
        }
    }while(puntosA!=1 && puntosB!=1);

    //Llevo los puntos a cero para jugar un nuevo punto
    puntosA=0;
    puntosB=0;

    //Reinicio todas las posiciones
        posaf=fil, posac=1, posbf=1, posbc=col;
        ant_posaf=posaf;
        ant_posac=posac;
        ant_posbf=posbf;
        ant_posbc=posbc;

        //Defino la matriz nuevamente.
        for(f=0; f<fil+1; f++){
            for(c=0; c<col+1; c++){
                bosque[f][c]=' ';
                bosque[0][0]=' ';
                bosque[f][0]=48+f;
                bosque[0][c]=64+c;
                bosque[fil][1]=jug1;
                bosque[1][col]=jug2;
            }
        }

        //Desparramo los arboles nuevamente
        while(cont_arboles!=arboles){
            int arbolf=1+rand()%(fil);
            int arbolc=1+rand()%(col);
            bosque[arbolf][arbolc]=arbol;
            bosque[fil][1]=jug1;
            bosque[1][col]=jug2;
            cont_arboles++;
        }

        cont_arboles=0;

        //Imprimo la matriz
        for(f=0; f<fil+1; f++){
            printf("\n");
            for(c=0; c<col+1; c++){
                printf(" %c |", bosque[f][c]);
            }
        printf("\n");
        }
    }while(roundsA!=2 && roundsB!=2);

    //Controla los rounds de la partida, quien gana 2, gana el total
    if(roundsA==2){
        for(int j=0;j<jug.tope;j++)
            if(strcmp(par.partidas_totales[par.tope].nick1,jug.registros[j].nick)==0){
                jug.registros[j].partidas_ganadas++;
            }
        printf("  ------------------------------\n");
        printf("  %s ES EL GANADOR !!\n", par.partidas_totales[par.tope].nick1);
        printf("  ------------------------------\n");
        printf("\n");
    }
    else
        if(roundsB==2){
            for(int j=0;j<jug.tope;j++)
                if(strcmp(par.partidas_totales[par.tope].nick2,jug.registros[j].nick)==0){
                    jug.registros[j].partidas_ganadas++;
                }
            printf("  ------------------------------\n");
            printf("  %s ES EL GANADOR !!\n", par.partidas_totales[par.tope].nick2);
            printf("  ------------------------------\n");
            printf("\n");
        }

    //COPIO EL RESULTADO DE LA PARTIDA A LA ESTRUCTURA
    par.partidas_totales[par.tope].res1=roundsA;
    par.partidas_totales[par.tope].res2=roundsB;
    par.tope++;

    //Menu para seguir jugando luego de cada punto jugado
    do{
	printf(" Quiere seguir jugando (S/N)?: ");
        fflush(stdin);
        scanf("%c", &opcion);
        if(opcion=='N' || opcion=='n'){
        	printf("\n");
        	printf(" << GRACIAS POR JUGAR >> \n\n");
        }
        if(opcion!='S' && opcion!='s' && opcion!='N' && opcion!='n'){
        	printf(" Error, debe elegir S(si) o N(no)\n");
        }
     }while(opcion!='S' && opcion!='s' && opcion!='N' && opcion!='n');

     if(opcion=='S' || opcion=='s'){
	//Reinicio todas las posiciones
        posaf=fil, posac=1, posbf=1, posbc=col;
        ant_posaf=posaf;
        ant_posac=posac;
        ant_posbf=posbf;
        ant_posbc=posbc;
        roundsA=0;
        roundsB=0;

        //Defino la matriz nuevamente.
        for(f=0; f<fil+1; f++){
            for(c=0; c<col+1; c++){
                bosque[f][c]=' ';
                bosque[0][0]=' ';
                bosque[f][0]=48+f;
                bosque[0][c]=64+c;
                bosque[fil][1]=jug1;
                bosque[1][col]=jug2;
            }
        }

        //Desparramo los arboles nuevamente
        while(cont_arboles!=arboles){
            int arbolf=1+rand()%(fil);
            int arbolc=1+rand()%(col);
            bosque[arbolf][arbolc]=arbol;
            bosque[fil][1]=jug1;
            bosque[1][col]=jug2;
            cont_arboles++;
        }

        cont_arboles=0;

        //Imprimo la matriz
        for(f=0; f<fil+1; f++){
            printf("\n");
            for(c=0; c<col+1; c++){
                printf(" %c |", bosque[f][c]);
            }
        printf("\n");
        }
    }
    system("cls");
}

//FUNCION 3
void opcion3(bool &regDatos, char nick[], topejugadores &jug){
    printf("\n");
    printf("Ingrese el nick del jugador a buscar: ");
    fflush(stdin);
    scanf("%s", nick);
    printf("\n");

    for(int j=0;j<jug.tope;j++)
		if(strcmp(jug.registros[j].nick,nick)==0){
            printf("  ------------------------------\n");
            printf("  Nombre: %s\n", jug.registros[j].nombre);
            printf("  Nick: %s\n", jug.registros[j].nick);
            printf("  Cedula: %s\n", jug.registros[j].cedula);
            printf("  Partidas ganadas: %d\n", jug.registros[j].partidas_ganadas);
            printf("  ------------------------------\n");
        }
        else
            printf("  No existe el jugador ingresado.\n");
}

//FUNCION 4
void opcion4(topepartidas &par){
	for(int p=0; p<par.tope; p++){
    printf("  ------------------------------\n");
    printf("  %s %d\n", par.partidas_totales[p].nick1, par.partidas_totales[p].res1);
	printf("  %s %d\n", par.partidas_totales[p].nick2, par.partidas_totales[p].res2);
    printf("  ------------------------------\n");
}
}

//FUNCION 5
void opcion5(char nick[], topepartidas &par){
    int p;
    printf("\n");
    printf("Ingrese el nick del jugador a buscar: ");
    fflush(stdin);
    scanf("%s", nick);
    printf("\n");

    for(p=0;p<par.tope;p++)
		if((strcmp(par.partidas_totales[p].nick1,nick)==0) || (strcmp(par.partidas_totales[p].nick2,nick)==0)){
            printf("  -------------------------------\n");
            printf("  %s %d\n", par.partidas_totales[p].nick1, par.partidas_totales[p].res1);
            printf("  %s %d\n", par.partidas_totales[p].nick2, par.partidas_totales[p].res2);
            printf("  -------------------------------\n");
		}
        else
            printf("  No hay partidas para el jugador ingresado.\n");
}

//FUNCION 6
void opcion6(topejugadores &jug){
int i, j, temp;

printf("\n");
printf("  -------------------------------\n");
printf("              RANKING\n");
printf("  -------------------------------\n");
for(j=0;j<jug.tope;j++){
        if(jug.registros[j].partidas_ganadas<jug.registros[j+1].partidas_ganadas){
            temp=jug.registros[j].partidas_ganadas;
            jug.registros[j].partidas_ganadas=jug.registros[j+1].partidas_ganadas;
            jug.registros[j+1].partidas_ganadas=temp;
        }
    printf("  %s %d\n", jug.registros[j].nick, jug.registros[j].partidas_ganadas);
}
printf("  -------------------------------\n");
}
