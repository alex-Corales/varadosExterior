#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "varado.h"
#include "listabi.h"

int controlIngresoNum(char numero[])
{

    int i;
    for(i=0; i < strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
            printf("Error. ingrese nuevamente un numero.\n");
            //getch();
            return 0;
        }
    }

    return 1;
}
int controlIngresoLetras(char palabra[])
{
    int i;
    for(i=0; i<strlen(palabra); i++)
    {
        if(!((palabra[i] >= 65 && palabra[i] <= 90) || (palabra[i] >= 97 && palabra[i] <= 122) || (palabra[i] == 32) || (palabra[i] == 164) || (palabra[i] == 165)))
        {
            printf("Error. ingrese nuevamente la palabra sin numeros.\n");
            return 0;
        }
    }
    return 1;
}
int buscarPorDni(lista *p, int busDni)
{

    reset(p);
    while((isOos(*p)!=1)&&(most_numDni(copyc(*p))!= busDni))
    {
        forwardlist(p);
    }
    if(isOos(*p)==1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int buscarPorProvincia(lista *p, int busProv)
{

    reset(p);
    while(((isOos(*p)!=1))&&(most_provinciaIngreso(copyc(*p))!=busProv))
    {
        forwardlist(p);
    }
    if(isOos(*p)==1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
datos cargardatos(lista *p)
{
    datos datPerson;
    char nombre[20], apellido[20], cantPersonas1[10], pais1[10], provinciaIngreso1[10], dia1[10], mes1[10], anio1[10], num1[10], personRiesgo1[10];
    long int dni;
    char dni1[10];
    int pais, cantPersonas, personRiesgo, provinciaIngreso, num, dia, mes, anio, aux;

    init_varado(&datPerson);

     do
    {
        printf("Ingrese el o los apellidos: ");
        getchar();
        gets(apellido);
        num=controlIngresoLetras(apellido);
    }
    while(num==0);

    cargar_apellido(&datPerson, apellido);

    do
    {
        printf("Ingrese el o los nombres: ");
        getchar();
        gets(nombre);
        num=controlIngresoLetras(nombre);
    }
    while(num==0);
    cargar_nombre(&datPerson, nombre);

    do
    {
        printf("Ingrese el DNI: ");
        scanf("%s", dni1);
        num = controlIngresoNum(dni1);
    }
    while(num == 0);
    dni = atoi(dni1);
    while(dni < 1000000 || dni > 99999999)
    {
        do
        {
            printf("Opcion incorrecta, Ingrese nuevamente el dni\n");
            printf("Ingrese el DNI: ");
            scanf("%s", dni1);
            num = controlIngresoNum(dni1);
        }
        while(num == 0);
        dni = atoi(dni1);
    }
    cargar_numDni(&datPerson, dni);
    system("cls");
    printf("----------------------------------\n");
    printf("Ingrese la fecha en la que salio del pais\n");
    do
    {
        printf("-Año: ");
        scanf("%s", anio1);
        num = controlIngresoNum(anio1);
    }
    while(num==0);
    anio = atoi(anio1);
    while(anio < 2019 || anio > 2020)
    {
        do
        {
            printf("-Año: ");
            scanf("%s", anio1);
            num = controlIngresoNum(anio1);
        }
        while(num==0);
        anio = atoi(anio1);
    }

    do
    {
        printf("----------------------------------\n");
        printf("-Mes\n");
        printf("<1> Enero\n");
        printf("<2> Febrero\n");
        printf("<3> Marzo\n");
        printf("<4> Abril\n");
        printf("<5> Mayo\n");
        printf("<6> Junio\n");
        printf("<7> Julio\n");
        printf("<8> Agosto\n");
        printf("<9> Septiembre\n");
        printf("<10> Octubre\n");
        printf("<11> Noviembre\n");
        printf("<12> Diciembre\n");
        printf("-mes: ");
        scanf("%s", mes1);
        num = controlIngresoNum(mes1);
    }
    while(num==0);
    mes = atoi(mes1);
    while(mes < 1 || mes > 12)
    {
        do
        {
            printf("----------------------------------\n");
            printf("-Mes\n");
            printf("<1> Enero\n");
            printf("<2> Febrero\n");
            printf("<3> Marzo\n");
            printf("<4> Abril\n");
            printf("<5> Mayo\n");
            printf("<6> Junio\n");
            printf("<7> Julio\n");
            printf("<8> Agosto\n");
            printf("<9> Septiembre\n");
            printf("<10> Octubre\n");
            printf("<11> Noviembre\n");
            printf("<12> Diciembre\n");
            printf("-mes: ");
            scanf("%s", mes1);
            num = controlIngresoNum(mes1);
        }
        while(num==0);
        mes = atoi(mes1);
    }

    switch(mes)
    {

    case 1:
        do
        {
            printf("----------------------------------\n");
            printf("-Dia: ");
            fflush(stdin);
            scanf("%s", dia1);
            num = controlIngresoNum(dia1);
        }
        while(num==0);
        dia = atoi(dia1);
        while(dia < 1 || dia > 31)
        {
            do
            {
                printf("----------------------------------\n");
                printf("-Dia: ");
                fflush(stdin);
                scanf("%s", dia1);
                num = controlIngresoNum(dia1);
            }
            while(num==0);
            dia = atoi(dia1);
        }
        break;

    case 2:

        if((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)
        {
            do
            {
                printf("----------------------------------\n");
                printf("-Dia: ");
                fflush(stdin);
                scanf("%s", dia1);
                num = controlIngresoNum(dia1);
            }
            while(num==0);
            dia = atoi(dia1);
            while(dia< 1 || dia > 29)
            {
                do
                {
                    printf("----------------------------------\n");
                    printf("-Dia: ");
                    fflush(stdin);
                    scanf("%s", dia1);
                    num = controlIngresoNum(dia1);
                }
                while(num==0);
                dia = atoi(dia1);
            }
        }
        else
        {

            do
            {
                printf("----------------------------------\n");
                printf("-Dia: ");
                fflush(stdin);
                scanf("%s", dia1);
                num = controlIngresoNum(dia1);
            }
            while(num==0);
            dia = atoi(dia1);
            while(dia < 1 || dia > 28)
            {
                do
                {
                    printf("----------------------------------\n");
                    printf("-Dia: ");
                    fflush(stdin);
                    scanf("%s", dia1);
                    num = controlIngresoNum(dia1);
                }
                while(num==0);
                dia = atoi(dia1);
            }

        }
        break;

    case 3:
        do
        {
            printf("----------------------------------\n");
            printf("-Dia: ");
            fflush(stdin);
            scanf("%s", dia1);
            num = controlIngresoNum(dia1);
        }
        while(num==0);
        dia = atoi(dia1);
        while(dia < 1 || dia > 31)
        {
            do
            {
                printf("----------------------------------\n");
                printf("-Dia: ");
                fflush(stdin);
                scanf("%s", dia1);
                num = controlIngresoNum(dia1);
            }
            while(num==0);
            dia = atoi(dia1);
        }
        break;

    case 4:
        do
        {
            printf("----------------------------------\n");
            printf("-Dia: ");
            fflush(stdin);
            scanf("%s", dia1);
            num = controlIngresoNum(dia1);
        }
        while(num==0);
        dia = atoi(dia1);
        while(dia < 1 || dia > 30)
        {
            do
            {
                printf("----------------------------------\n");
                printf("-Dia: ");
                fflush(stdin);
                scanf("%s", dia1);
                num = controlIngresoNum(dia1);
            }
            while(num==0);
            dia = atoi(dia1);
        }
        break;

    case 5:
        do
        {
            printf("----------------------------------\n");
            printf("-Dia: ");
            fflush(stdin);
            scanf("%s", dia1);
            num = controlIngresoNum(dia1);
        }
        while(num==0);
        dia = atoi(dia1);
        while(dia < 1 || dia > 31)
        {
            do
            {
                printf("----------------------------------\n");
                printf("-Dia: ");
                fflush(stdin);
                scanf("%s", dia1);
                num = controlIngresoNum(dia1);
            }
            while(num==0);
            dia = atoi(dia1);
        }
        break;

    case 6:
        do
        {
            printf("----------------------------------\n");
            printf("-Dia: ");
            fflush(stdin);
            scanf("%s", dia1);
            num = controlIngresoNum(dia1);
        }
        while(num==0);
        dia = atoi(dia1);
        while(dia < 1 || dia > 30)
        {
            do
            {
                printf("----------------------------------\n");
                printf("-Dia: ");
                fflush(stdin);
                scanf("%s", dia1);
                num = controlIngresoNum(dia1);
            }
            while(num==0);
            dia = atoi(dia1);
        }
        break;

    case 7:
        do
        {
            printf("----------------------------------\n");
            printf("-Dia: ");
            fflush(stdin);
            scanf("%s", dia1);
            num = controlIngresoNum(dia1);
        }
        while(num==0);
        dia = atoi(dia1);
        while(dia < 1 || dia > 31)
        {
            do
            {
                printf("----------------------------------\n");
                printf("-Dia: ");
                fflush(stdin);
                scanf("%s", dia1);
                num = controlIngresoNum(dia1);
            }
            while(num==0);
            dia = atoi(dia1);
        }
        break;

    case 8:
        do
        {
            printf("----------------------------------\n");
            printf("-Dia: ");
            fflush(stdin);
            scanf("%s", dia1);
            num = controlIngresoNum(dia1);
        }
        while(num==0);
        dia = atoi(dia1);
        while(dia < 1 || dia > 31)
        {
            do
            {
                printf("----------------------------------\n");
                printf("-Dia: ");
                fflush(stdin);
                scanf("%s", dia1);
                num = controlIngresoNum(dia1);
            }
            while(num==0);
            dia = atoi(dia1);
        }
        break;

    case 9:
        do
        {
            printf("----------------------------------\n");
            printf("-Dia: ");
            fflush(stdin);
            scanf("%s", dia1);
            num = controlIngresoNum(dia1);
        }
        while(num==0);
        dia = atoi(dia1);
        while(dia < 1 || dia > 30)
        {
            do
            {
                printf("----------------------------------\n");
                printf("-Dia: ");
                fflush(stdin);
                scanf("%s", dia1);
                num = controlIngresoNum(dia1);
            }
            while(num==0);
            dia = atoi(dia1);
        }
        break;

    case 10:
        do
        {
            printf("----------------------------------\n");
            printf("-Dia: ");
            fflush(stdin);
            scanf("%s", dia1);
            num = controlIngresoNum(dia1);
        }
        while(num==0);
        dia = atoi(dia1);
        while(dia < 1 || dia > 31)
        {
            do
            {
                printf("----------------------------------\n");
                printf("-Dia: ");
                fflush(stdin);
                scanf("%s", dia1);
                num = controlIngresoNum(dia1);
            }
            while(num==0);
            dia = atoi(dia1);
        }
        break;

    case 11:
        do
        {
            printf("----------------------------------\n");
            printf("-Dia: ");
            fflush(stdin);
            scanf("%s", dia1);
            num = controlIngresoNum(dia1);
        }
        while(num==0);
        dia = atoi(dia1);
        while(dia < 1 || dia > 30)
        {
            do
            {
                printf("----------------------------------\n");
                printf("-Dia: ");
                fflush(stdin);
                scanf("%s", dia1);
                num = controlIngresoNum(dia1);
            }
            while(num==0);
            dia = atoi(dia1);
        }
        break;

    case 12:
        do
        {
            printf("----------------------------------\n");
            printf("-Dia: ");
            fflush(stdin);
            scanf("%s", dia1);
            num = controlIngresoNum(dia1);
        }
        while(num==0);
        dia = atoi(dia1);
        while(dia < 1 || dia > 31)
        {
            do
            {
                printf("----------------------------------\n");
                printf("-Dia: ");
                fflush(stdin);
                scanf("%s", dia1);
                num = controlIngresoNum(dia1);
            }
            while(num==0);
            dia = atoi(dia1);
        }
        break;

    default:
        printf("----------------------------------\n");
        printf("Mes incorrecto");
        printf("----------------------------------\n");
    }

    cargar_fecha(&datPerson, dia, mes, anio);


    system("cls");
    do
    {
        printf("----------------------------------\n");
        printf("Ingrese el pais en el que se encuentra\n");
        printf("----------------------------------\n");
        printf("<1>España\n");
        printf("<2>Italia\n");
        printf("<3>Estados Unidos\n");
        printf("<4>Brasil\n");
        printf("<5>Chile\n");
        printf("<6>Uruguay\n");
        printf("<7>Mexico\n");
        printf("<8>Alemania\n");
        printf("<9>Francia\n");
        printf("<10>Cuba\n");
        printf("<11>Perú\n");
        printf("<12>Rusia\n");
        printf("<13>Japon\n");
        printf("<14>China\n");
        printf("<15>Venezuela\n");
        printf("<16>Australia\n");
        printf("<17>Bolivia\n");
        printf("<18>Canadá\n");
        printf("<19>Croacia\n");
        printf("<20>Guatemala\n");
        printf("-");
        scanf("%s", pais1);
        num = controlIngresoNum(pais1);
    }
    while(num==0);
    pais = atoi(pais1);
    while(pais < 1 || pais > 20)
    {
        do
        {
            printf("----------------------------------\n");
            printf("Ingrese el pais en el que se encuentra\n");
            printf("----------------------------------\n");
            printf("<1>España\n");
            printf("<2>Italia\n");
            printf("<3>Estados Unidos\n");
            printf("<4>Brasil\n");
            printf("<5>Chile\n");
            printf("<6>Uruguay\n");
            printf("<7>Mexico\n");
            printf("<8>Alemania\n");
            printf("<9>Francia\n");
            printf("<10>Cuba\n");
            printf("<11>Perú\n");
            printf("<12>Rusia\n");
            printf("<13>Japon\n");
            printf("<14>China\n");
            printf("<15>Venezuela\n");
            printf("<16>Australia\n");
            printf("<17>Bolivia\n");
            printf("<18>Canadá\n");
            printf("<19>Croacia\n");
            printf("<20>Guatemala\n");
            printf("-");
            scanf("%s", pais1);
            num = controlIngresoNum(pais1);
        }
        while(num==0);
        pais = atoi(pais1);
    }
    cargar_pais(&datPerson, pais);

    system("cls");

    do
    {
        printf("----------------------------------\n");
        printf("¿Usted viene acompañado?\n");
        printf("----------------------------------\n");
        printf("<1> Si\n");
        printf("<2> No\n");
        printf("-");
        scanf("%s", num1);
        aux = controlIngresoNum(num1);
    }
    while(aux == 0);
    num = atoi(num1);
    while(num < 1 || num > 2)
    {
        do
        {
            printf("----------------------------------\n");
            printf("Opcion incorrecta, Ingrese nuevamente una opcion\n");
            printf("¿Usted viene acompañado?\n");
            printf("----------------------------------\n");
            printf("<1> Si\n");
            printf("<2> No\n");
            printf("-");
            scanf("%s", num1);
            aux = controlIngresoNum(num1);
        }
        while(aux == 0);
        num = atoi(num1);
    }
    if(num==1)
    {
        int n;
        do
        {
            printf("----------------------------------\n");
            printf("Ingrese la cantidad de acompañantes\n");
            printf("----------------------------------\n");
            printf("-");
            scanf("%s", cantPersonas1);
            n=controlIngresoNum(cantPersonas1);
        }
        while(n==0);
        cantPersonas=atoi(cantPersonas1);
        while(cantPersonas < 1 || cantPersonas > 15)
        {
            do
            {
                printf("----------------------------------\n");
                printf("Ingrese la cantidad de acompañantes\n");
                printf("----------------------------------\n");
                printf("-");
                scanf("%s", cantPersonas1);
                n=controlIngresoNum(cantPersonas1);
            }
            while(n==0);

            cantPersonas=atoi(cantPersonas1);
        }

        cantPersonas = cantPersonas + 1;
        cargar_cantPersonas(&datPerson, cantPersonas);
        do
        {
            printf("----------------------------------\n");
            printf("Existe alguna persona de riesto?\n");
            printf("<1> Si\n");
            printf("<2> No\n");
            printf("----------------------------------\n");
            printf("-");
            scanf("%s", personRiesgo1);
            aux = controlIngresoNum(personRiesgo1);
        }
        while(aux==0);
        personRiesgo = atoi(personRiesgo1);
        while(personRiesgo < 1 || personRiesgo > 2)
        {
            do
            {
                printf("----------------------------------\n");
                printf("Opcion incorrecta. Existe alguna persona de riesto?\n");
                printf("<1> Si\n");
                printf("<2> No\n");
                printf("----------------------------------\n");
                printf("-");
                scanf("%s", personRiesgo1);
                aux = controlIngresoNum(personRiesgo1);
            }
            while(aux==0);
            personRiesgo = atoi(personRiesgo1);
        }
        cargar_personRiesgo(&datPerson, personRiesgo);
    }
    else
    {
        do
        {
            printf("----------------------------------\n");
            printf("Usted es una persona de riesgo?\n");
            printf("<1> Si\n");
            printf("<2> No\n");
            printf("----------------------------------\n");
            printf("-");
            scanf("%s", personRiesgo1);
            aux = controlIngresoNum(personRiesgo1);
        }
        while(aux==0);
        personRiesgo = atoi(personRiesgo1);
        while(personRiesgo < 1 || personRiesgo > 2)
        {
            do
            {
                printf("----------------------------------\n");
                printf("Opcion incorrecta, Ingrese nuevamente una opcion\n");
                printf("<1> Si\n");
                printf("<2> No\n");
                printf("----------------------------------\n");
                printf("-");
                scanf("%s", personRiesgo1);
                aux = controlIngresoNum(personRiesgo1);
            }
            while(aux==0);
            personRiesgo = atoi(personRiesgo1);
        }
        cargar_personRiesgo(&datPerson, personRiesgo);
        cargar_cantPersonas(&datPerson, 1);
    }

    system("cls");

    do
    {
        printf("----------------------------------\n");
        printf("Ingrese la provincia a la que desea ingresar\n");
        printf("----------------------------------\n");
        printf("<1>Buenos Aires\n");
        printf("<2>Catamarca\n");
        printf("<3>Chaco\n");
        printf("<4>Chubut\n");
        printf("<5>Cordoba\n");
        printf("<6>Corrientes\n");
        printf("<7>Entre Ríos\n");
        printf("<8>Formosa\n");
        printf("<9>Jujuy\n");
        printf("<10>La Pampa\n");
        printf("<11>La Rioja\n");
        printf("<12>Mendoza\n");
        printf("<13>Misiones\n");
        printf("<14>Neuquén\n");
        printf("<15>Rio Negro\n");
        printf("<16>Salta\n");
        printf("<17>San Juan\n");
        printf("<18>San Luis\n");
        printf("<19>Santa Cruz\n");
        printf("<20>Santa Fe\n");
        printf("<21>Santiago del Estero\n");
        printf("<22>Tierra del Fuego\n");
        printf("<23>Tucuman\n");
        printf("-");
        scanf("%s", provinciaIngreso1);
        num = controlIngresoNum(provinciaIngreso1);
    }
    while(num==0);
    provinciaIngreso = atoi(provinciaIngreso1);
    while(provinciaIngreso < 1 || provinciaIngreso > 23)
    {
        do
        {
            printf("----------------------------------\n");
            printf("Ingrese la provincia a la que desea ingresar\n");
            printf("----------------------------------\n");
            printf("<1>Buenos Aires\n");
            printf("<2>Catamarca\n");
            printf("<3>Chaco\n");
            printf("<4>Chubut\n");
            printf("<5>Cordoba\n");
            printf("<6>Corrientes\n");
            printf("<7>Entre Ríos\n");
            printf("<8>Formosa\n");
            printf("<9>Jujuy\n");
            printf("<10>La Pampa\n");
            printf("<11>La Rioja\n");
            printf("<12>Mendoza\n");
            printf("<13>Misiones\n");
            printf("<14>Neuquén\n");
            printf("<15>Rio Negro\n");
            printf("<16>Salta\n");
            printf("<17>San Juan\n");
            printf("<18>San Luis\n");
            printf("<19>Santa Cruz\n");
            printf("<20>Santa Fe\n");
            printf("<21>Santiago del Estero\n");
            printf("<22>Tierra del Fuego\n");
            printf("<23>Tucuman\n");
            printf("-");
            scanf("%s", provinciaIngreso1);
            num = controlIngresoNum(provinciaIngreso1);
        }
        while(num==0);
        provinciaIngreso = atoi(provinciaIngreso1);
    }
    cargar_provinciaIngreso(&datPerson, provinciaIngreso);

    while(isOos(*p)==0)
    {
        forwardlist(p);
    }

    insertlist(p, datPerson);
    return datPerson;
}
int contadorDePersonas(lista p, int cant, int pais)
{

    if(isOos(p)==1)
    {
        return cant;

    }
    else if(pais == most_pais(copyc(p)))
    {
        cant += most_cantPersonas(copyc(p));
        forwardlist(&p);
        contadorDePersonas(p, cant, pais);
    }
    else
    {
        forwardlist(&p);
        contadorDePersonas(p, cant, pais);
    }

}
datos modificarPais(datos nuevo)
{
    int pais, aux;
    char pais1[10];
    do
    {
        printf("----------------------------------\n");
        printf("Ingrese el nuevo pais\n");
        printf("----------------------------------\n");
        printf("<1>España\n");
        printf("<2>Italia\n");
        printf("<3>Estados Unidos\n");
        printf("<4>Brasil\n");
        printf("<5>Chile\n");
        printf("<6>Uruguay\n");
        printf("<7>Mexico\n");
        printf("<8>Alemania\n");
        printf("<9>Francia\n");
        printf("<10>Cuba\n");
        printf("<11>Perú\n");
        printf("<12>Rusia\n");
        printf("<13>Japon\n");
        printf("<14>China\n");
        printf("<15>Venezuela\n");
        printf("<16>Australia\n");
        printf("<17>Bolivia\n");
        printf("<18>Canadá\n");
        printf("<19>Croacia\n");
        printf("<20>Guatemala\n");
        printf("-");
        scanf("%s", pais1);
        aux = controlIngresoNum(pais1);
    }
    while(aux==0);
    pais = atoi(pais1);
    while(pais < 1 || pais > 20)
    {
        do
        {
            printf("----------------------------------\n");
            printf("Ingrese el nuevo pais\n");
            printf("----------------------------------\n");
            printf("<1>España\n");
            printf("<2>Italia\n");
            printf("<3>Estados Unidos\n");
            printf("<4>Brasil\n");
            printf("<5>Chile\n");
            printf("<6>Uruguay\n");
            printf("<7>Mexico\n");
            printf("<8>Alemania\n");
            printf("<9>Francia\n");
            printf("<10>Cuba\n");
            printf("<11>Perú\n");
            printf("<12>Rusia\n");
            printf("<13>Japon\n");
            printf("<14>China\n");
            printf("<15>Venezuela\n");
            printf("<16>Australia\n");
            printf("<17>Bolivia\n");
            printf("<18>Canadá\n");
            printf("<19>Croacia\n");
            printf("<20>Guatemala\n");
            printf("-");
            scanf("%s", pais1);
            aux = controlIngresoNum(pais1);
        }
        while(aux==0);
        pais = atoi(pais1);
    }
    modi_pais(&nuevo, pais);
    return nuevo;
}
void menuModificarPais(lista *listDat)
{

    if(isEmpty(*listDat)==0)
    {
        int numDni, num;
        char numDni1[10];
        do
        {
            printf("----------------------------------\n");
            printf("Ingrese el dni del varado que desea buscar\n");
            printf("-");
            scanf("%s", numDni1);
            num = controlIngresoNum(numDni1);
        }
        while(num==0);
        numDni = atoi(numDni1);
        while(numDni < 1000000 || numDni > 99999999)
        {
            do
            {
                printf("----------------------------------\n");
                printf("Ingrese el dni del varado que desea buscar nuevamente\n");
                printf("-");
                scanf("%s", numDni1);
                num = controlIngresoNum(numDni1);
            }
            while(num==0);
            numDni = atoi(numDni1);
        }

        int aux = buscarPorDni(listDat, numDni);

        if(aux==1)
        {
			datos nuevo = copyc(*listDat);
           	suppress(listDat);
           	insertlist(listDat, modificarPais(nuevo));
           	system("cls");
           	printf("----------------------------------\n");
           	printf("Pais modificado\n");
      	 	printf("----------------------------------\n");
		}
        }else{
        	printf("El varado no esta en la lista\n");
        }
    }
datos modificarProvincia(datos nuevo)
{
    int prov, num;
    char prov1[10];
    do
    {
        printf("----------------------------------\n");
        printf("Ingrese la nueva provincia a la que desea ingresar\n");
        printf("----------------------------------\n");
        printf("<1>Buenos Aires\n");
        printf("<2>Catamarca\n");
        printf("<3>Chaco\n");
        printf("<4>Chubut\n");
        printf("<5>Cordoba\n");
        printf("<6>Corrientes\n");
        printf("<7>Entre Ríos\n");
        printf("<8>Formosa\n");
        printf("<9>Jujuy\n");
        printf("<10>La Pampa\n");
        printf("<11>La Rioja\n");
        printf("<12>Mendoza\n");
        printf("<13>Misiones\n");
        printf("<14>Neuquén\n");
        printf("<15>Rio Negro\n");
        printf("<16>Salta\n");
        printf("<17>San Juan\n");
        printf("<18>San Luis\n");
        printf("<19>Santa Cruz\n");
        printf("<20>Santa Fe\n");
        printf("<21>Santiago del Estero\n");
        printf("<22>Tierra del Fuego\n");
        printf("<23>Tucuman\n");
        printf("-");
        scanf("%s", prov1);
        num = controlIngresoNum(prov1);
    }
    while(num==0);
    prov = atoi(prov1);
    while(prov < 1 || prov > 23)
    {
        do
        {
            printf("----------------------------------\n");
            printf("Ingrese la nueva provincia a la que desea ingresar\n");
            printf("----------------------------------\n");
            printf("<1>Buenos Aires\n");
            printf("<2>Catamarca\n");
            printf("<3>Chaco\n");
            printf("<4>Chubut\n");
            printf("<5>Cordoba\n");
            printf("<6>Corrientes\n");
            printf("<7>Entre Ríos\n");
            printf("<8>Formosa\n");
            printf("<9>Jujuy\n");
            printf("<10>La Pampa\n");
            printf("<11>La Rioja\n");
            printf("<12>Mendoza\n");
            printf("<13>Misiones\n");
            printf("<14>Neuquén\n");
            printf("<15>Rio Negro\n");
            printf("<16>Salta\n");
            printf("<17>San Juan\n");
            printf("<18>San Luis\n");
            printf("<19>Santa Cruz\n");
            printf("<20>Santa Fe\n");
            printf("<21>Santiago del Estero\n");
            printf("<22>Tierra del Fuego\n");
            printf("<23>Tucuman\n");
            printf("-");
            scanf("%s", prov1);
            num = controlIngresoNum(prov1);
        }
        while(num==0);
        prov = atoi(prov1);
    }

    modi_provinciaIngreso(&nuevo, prov);
    return nuevo;
}
void menuModificarProvincia(lista *listDat)
{

    if(isEmpty(*listDat)==0)
    {
        int numDni, num;
        char numDni1[10];
        do
        {
            printf("----------------------------------\n");
            printf("Ingrese el dni del varado que desea buscar\n");
            printf("----------------------------------\n");
            printf("-");
            scanf("%s", numDni1);
            num = controlIngresoNum(numDni1);
        }
        while(num==0);
        numDni = atoi(numDni1);
        while(numDni < 1000000 || numDni > 99999999)
        {
            do
            {
                printf("----------------------------------\n");
                printf("Ingrese el dni del varado que desea buscar nuevamente\n");
                printf("----------------------------------\n");
                printf("-");
                scanf("%s", numDni1);
                num = controlIngresoNum(numDni1);
            }
            while(num==0);
            numDni = atoi(numDni1);
        }

        int aux = buscarPorDni(listDat, numDni);

        if(aux==1)
        {
            datos nuevo = copyc(*listDat);
            suppress(listDat);
            insertlist(listDat, modificarProvincia(nuevo));
            system("cls");
            printf("----------------------------------\n");
            printf("Provincia modificada\n");
            printf("----------------------------------\n");
        }else{
        	printf("El varado no esta en la lista\n");
        }
    }
}
datos modificarPersonaRiesgo(datos nuevo)
{
    int riesgo, num;
    char riesgo1[10];
    do
    {
        printf("----------------------------------\n");
        printf("Existe alguna persona de riesgo?\n");
        printf("<1> Si\n");
        printf("<2> No\n");
        printf("-");
        scanf("%s", riesgo1);
        num=controlIngresoNum(riesgo1);
    }
    while(num==0);
    riesgo = atoi(riesgo1);
    while(riesgo < 1 || riesgo > 2)
    {
        do
        {
            printf("----------------------------------\n");
            printf("Opcion incorrecta. Existe alguna persona de riesgo?\n");
            printf("<1> Si\n");
            printf("<2> No\n");
            printf("-");
            scanf("%s", riesgo1);
            num=controlIngresoNum(riesgo1);
        }
        while(num==0);
        riesgo = atoi(riesgo1);
    }
    modi_personRiesgo(&nuevo, riesgo);
    return nuevo;
}
void menuModificarPersonaRiesgo(lista *listDat)
{

    if(isEmpty(*listDat)==0)
    {
        int numDni, num;
        char numDni1[10];
        do
        {
            printf("----------------------------------\n");
            printf("Ingrese el dni del varado que desea buscar\n");
            printf("----------------------------------\n");
            printf("-");
            scanf("%s", numDni1);
            num = controlIngresoNum(numDni1);
        }
        while(num==0);
        numDni = atoi(numDni1);
        while(numDni < 1000000 || numDni > 99999999)
        {
            do
            {
                printf("----------------------------------\n");
                printf("Ingrese el dni del varado que desea buscar nuevamente\n");
                printf("----------------------------------\n");
                printf("-");
                scanf("%s", numDni1);
                num = controlIngresoNum(numDni1);
            }
            while(num==0);
            numDni = atoi(numDni1);
        }

        int aux = buscarPorDni(listDat, numDni);

        if(aux==1)
        {
            datos nuevo = copyc(*listDat);
            suppress(listDat);
            insertlist(listDat, modificarPersonaRiesgo(nuevo));
            system("cls");
            printf("----------------------------------\n");
            printf("Existencia de persona de riesgo modificada\n");
            printf("----------------------------------\n");
        }else{
        	printf("El varado no esta en la lista\n");
        }
    }
}
void mostraDatos(datos p)
{

    printf("\n--------------------------\n");
    printf("Nombre y Apellido: %s %s\n", most_nombre(p), most_apellido(p));
    printf("Numero de documento: %d\n", most_numDni(p));
    printf("Fecha de salida: %d/%d/%d\n", most_dia(p), most_mes(p), most_anio(p));

    printf("Pais en el que se encuentra: ");
    int num = most_pais(p);
    switch(num)
    {
    case 1:
        printf("España\n");
        break;
    case 2:
        printf("Italia\n");
        break;
    case 3:
        printf("Estados Unidos\n");
        break;
    case 4:
        printf("Brasil\n");
        break;
    case 5:
        printf("Chile\n");
        break;
    case 6:
        printf("Uruguay\n");
        break;
    case 7:
        printf("Mexico\n");
        break;
    case 8:
        printf("Alemania\n");
        break;
    case 9:
        printf("Francia\n");
        break;
    case 10:
        printf("Cuba\n");
        break;
    case 11:
        printf("Perú\n");
        break;
    case 12:
        printf("Rusia\n");
        break;
    case 13:
        printf("Japon\n");
        break;
    case 14:
        printf("China\n");
        break;
    case 15:
        printf("Venezuela\n");
        break;
    case 16:
        printf("Australia\n");
        break;
    case 17:
        printf("Bolivia\n");
        break;
    case 18:
        printf("Canadá\n");
        break;
    case 19:
        printf("Croacia\n");
        break;
    case 20:
        printf("Guatemala\n");
        break;
    }

    printf("Cantidad de personas en el grupo: %d\n", most_cantPersonas(p));

    int numR = most_personRiesgo(p);
    switch(numR)
    {
    case 1:
        printf("Si existe una persona de riesgo\n");
        break;
    case 2:
        printf("No existe una persona de riesgo\n");
        break;
    }

    printf("Provincia a que desea ingresar: ");
    int numP = most_provinciaIngreso(p);
    switch(numP)
    {
    case 1:
        printf("Buenos Aires\n");
        break;
    case 2:
        printf("Catamarca\n");
        break;
    case 3:
        printf("Chaco\n");
        break;
    case 4:
        printf("Chubut\n");
        break;
    case 5:
        printf("Cordoba\n");
        break;
    case 6:
        printf("Corrientes\n");
        break;
    case 7:
        printf("Entre Ríos\n");
        break;
    case 8:
        printf("Formosa\n");
        break;
    case 9:
        printf("Jujuy\n");
        break;
    case 10:
        printf("La Pampa\n");
        break;
    case 11:
        printf("La Rioja\n");
        break;
    case 12:
        printf("Mendoza\n");
        break;
    case 13:
        printf("Misiones\n");
        break;
    case 14:
        printf("Neuquén\n");
        break;
    case 15:
        printf("Rio Negro\n");
        break;
    case 16:
        printf("Salta\n");
        break;
    case 17:
        printf("San Juan\n");
        break;
    case 18:
        printf("San Luis\n");
        break;
    case 19:
        printf("Santa Cruz\n");
        break;
    case 20:
        printf("Santa Fe\n");
        break;
    case 21:
        printf("Santiago del Estero\n");
        break;
    case 22:
        printf("Tierra del Fuego\n");
        break;
    case 23:
        printf("Tucuman\n");
        break;
        printf("\n--------------------------\n");
    }
}
void eliminarVarados(lista *p, int numPais)
{
    reset(p);
    int aux = 0;
    while(isOos(*p)!=1)
    {
        if(most_pais(copyc(*p))== numPais)
        {
            suppress(p);
            aux++;
        }
        else
        {
            forwardlist(p);
        }
    }

}
void archivoPersonasDeRiesgo(datos p)
{
    int num;
    char nomPais[20], nomPerson[50], nomProvincia[50];

    FILE *f;
    f=fopen("viajan.txt", "a+");

    if(f==NULL)
    {
        printf("Error. el archivo no se abrio\n");
        exit(1);
    }
    else
    {

        num = most_pais(p);
        switch(num)
        {
        case 1:
            strcpy(nomPais, "España");
            break;
        case 2:
            strcpy(nomPais, "Italia");
            break;
        case 3:
            strcpy(nomPais, "Estados Unidos");
            break;
        case 4:
            strcpy(nomPais, "Brasil");
            break;
        case 5:
            strcpy(nomPais, "Chile");
            break;
        case 6:
            strcpy(nomPais, "Uruguay");
            break;
        case 7:
            strcpy(nomPais, "Mexico");
            break;
        case 8:
            strcpy(nomPais, "Alemania");
            break;
        case 9:
            strcpy(nomPais, "Francia");
            break;
        case 10:
            strcpy(nomPais, "Cuba");
            break;
        case 11:
            strcpy(nomPais, "Perú");
            break;
        case 12:
            strcpy(nomPais, "Rusia");
            break;
        case 13:
            strcpy(nomPais, "Japon");
            break;
        case 14:
            strcpy(nomPais, "China");
            break;
        case 15:
            strcpy(nomPais, "Venezuela");
            break;
        case 16:
            strcpy(nomPais, "Australia");
            break;
        case 17:
            strcpy(nomPais, "Bolivia");
            break;
        case 18:
            strcpy(nomPais, "Canadá");
            break;
        case 19:
            strcpy(nomPais, "Croacia");
            break;
        case 20:
            strcpy(nomPais, "Guatemala");
            break;
        }

        num = most_personRiesgo(p);
        switch(num)
        {
        case 1:
            strcpy(nomPerson, "Existe una persona de riesgo");
        }

        num = most_provinciaIngreso(p);
        switch(num)
        {
        case 1:
            strcpy(nomProvincia, "Buenos Aires");
            break;
        case 2:
            strcpy(nomProvincia, "Catamarca");
            break;
        case 3:
            strcpy(nomProvincia, "Chaco");
            break;
        case 4:
            strcpy(nomProvincia, "Chubut");
            break;
        case 5:
            strcpy(nomProvincia, "Cordoba");
            break;
        case 6:
            strcpy(nomProvincia, "Corrientes");
            break;
        case 7:
            strcpy(nomProvincia, "Entre Rios");
            break;
        case 8:
            strcpy(nomProvincia, "Formosa");
            break;
        case 9:
            strcpy(nomProvincia, "Jujuy");
            break;
        case 10:
            strcpy(nomProvincia, "La Pampa");
            break;
        case 11:
            strcpy(nomProvincia, "La Rioja");
            break;
        case 12:
            strcpy(nomProvincia, "Mendoza");
            break;
        case 13:
            strcpy(nomProvincia, "Misiones");
            break;
        case 14:
            strcpy(nomProvincia, "Neuquén");
            break;
        case 15:
            strcpy(nomProvincia, "Rio Negro");
            break;
        case 16:
            strcpy(nomProvincia, "Salta");
            break;
        case 17:
            strcpy(nomProvincia, "San Juan");
            break;
        case 18:
            strcpy(nomProvincia, "San Luis");
            break;
        case 19:
            strcpy(nomProvincia, "Santa Cruz");
            break;
        case 20:
            strcpy(nomProvincia, "Santa Fe");
            break;
        case 21:
            strcpy(nomProvincia, "Santiago del Estero");
            break;
        case 22:
            strcpy(nomProvincia, "Tierra del Fuego");
            break;
        case 23:
            strcpy(nomProvincia, "Tucuman");
            break;

        }

        fprintf(f, "%s %s, %d, %d/%d/%d, %s, %d, %s, %s\n", most_nombre(p), most_apellido(p), most_numDni(p), most_dia(p), most_mes(p), most_anio(p), nomPais, most_cantPersonas(p), nomPerson, nomProvincia);
        fclose(f);
    }

}
void menuArchivosPersonaDeRiesgo(lista li)
{
    reset(&li);

    while(isOos(li)!=1)
    {
        if(most_personRiesgo(copyc(li))==1)
        {
            archivoPersonasDeRiesgo(copyc(li));
            forwardlist(&li);
        }
        else
        {
            forwardlist(&li);
        }
    }
}
int precargaVarados(lista *li)
{
        int dev=0;
        datos var;
        char nombre[30], apellido[30];
        int numDni, pais, cantPerson, personRiesgo, prov, dia, mes, anio;

        FILE *fp;
        fp = fopen("precarga.txt", "r");
        if(fp==NULL)
        {
            printf("Error. El archivo no existe");
            exit(1);
        }
        else
        {
            rewind(fp);
            reset(&li);
            while(feof(fp) == 0)
            {
                fscanf(fp,"%s%s%d%d%d%d%d%d%d%d", nombre, apellido, &numDni, &dia, &mes, &anio, &pais, &cantPerson, &personRiesgo, &prov);
                cargar_nombre(&var, nombre);
                cargar_apellido(&var, apellido);
                cargar_numDni(&var, numDni);
                cargar_fecha(&var, dia, mes, anio);
                cargar_pais(&var, pais);
                cargar_cantPersonas(&var, cantPerson);
                cargar_personRiesgo(&var, personRiesgo);
                cargar_provinciaIngreso(&var, prov);
                while(isOos(*li)==0)
                {
                    forwardlist(li);
                }
                insertlist(li, var);
                dev++;
            }
        }
        fclose(fp);
        return dev;
    }
int main()
{

    char prov1[10], opc1[10];
    int opc;
    int numDni, dev;
    int prov, pais, riesgo, auxopc, auxmodi;
    int aux, numcant, auxcant=0, numaux;
    char numcant1[10];
    lista lisDat;
    init(&lisDat);
    do
    {
        printf("----------------------------------\n");
        printf("BIENVENIDO AL MENU\n");
        printf("----------------------------------\n");
        printf("<1> Cargar datos de varados\n");
        printf("<2> Mostrar datos de un varado\n");
        printf("<3> Modificar datos de un varado\n");
        printf("<4> Eliminar datos de un varado\n");
        printf("<5> Cantidad de varados\n");
        printf("<6> Precarga de varados\n");
        printf("<7> Salir\n");
        printf("Opcion: ");
        do
        {
            scanf("%s", opc1);
            auxopc = controlIngresoNum(opc1);
        }
        while(auxopc==0);
        opc = atoi(opc1);
        switch(opc)
        {

        case 1:
            if(isFull(lisDat)==0)
            {
                int cant, numcant;
                char cant1[10];
                do
                {
                    system("cls");
                    printf("----------------------------------\n");
                    printf("Ingrese la cantidad de varados que desea cargar\nO ingrese 0 si no desea cargar\n");
                    printf("-");
                    scanf("%s", cant1);
                    numcant = controlIngresoNum(cant1);
                }
                while(numcant == 0);
                cant = atoi(cant1);
                while(cant < 0)
                {
                    do
                    {
                        system("cls");
                        printf("----------------------------------\n");
                        printf("Error, Ingrese la cantidad de varados que desea cargar\nO ingrese 0 si no desea cargar\n");
                        scanf("%s", cant1);
                        numcant = controlIngresoNum(cant1);
                    }
                    while(numcant == 0);
                    cant = atoi(cant1);
                }

                system("cls");

                if(cant == 0)
                {
                    printf("----------------------------------------\n");
                    printf("No se cargara ningun varado\n");
                    printf("----------------------------------------\n");
                }
                else
                {
                    int i=0;
                    while((isFull(lisDat) != 1) && (i < cant))
                    {
                        printf("----------------------------------\n");
                        printf("Ingrese los datos del varado numero %d\n", i+1);
                        printf("----------------------------------\n");
                        reset(&lisDat);
                        while(isOos(lisDat)!=1)
                        {
                            forwardlist(&lisDat);
                        }
                        cargardatos(&lisDat);
                        system("cls");
                        printf("----------------------------------------\n");
                        printf("el varado fue cargado exitosamente\n");
                        printf("----------------------------------------\n");
                        i++;
                    }
                }

                menuArchivosPersonaDeRiesgo(lisDat);

            }
            else
            {
                system("cls");
                printf("----------------------------------------\n");
                printf("Error, lista de varado llena\n");
                printf("----------------------------------------\n");
            }
            break;
        case 2:
            if(isEmpty(lisDat)==0){
            do
            {
                printf("--------------------------------\n");
                printf("Buscar datos de un varado por\n");
                printf("--------------------------------\n");
                printf("<1> Dni\n");
                printf("<2> Provincia a la que desea ingresar\n");
                printf("<3> Volver atras\n");
                printf("Opcion: ");
                do
                {
                    scanf("%s", opc1);
                    auxopc = controlIngresoNum(opc1);
                }
                while(auxopc==0);
                opc = atoi(opc1);
                switch(opc)
                {
                case 1:
                    if(isEmpty(lisDat) == 0)
                    {
                        reset(&lisDat);

                        int numDni, num;
                        char numDni1[10];
                        do
                        {
                            system("cls");
                            printf("------------------------------------------\n");
                            printf("Ingrese el dni del varado que desea buscar\n");
                            printf("-");
                            scanf("%s", numDni1);
                            num = controlIngresoNum(numDni1);
                        }
                        while(num==0);
                        numDni = atoi(numDni1);
                        while(numDni < 1000000 || numDni > 99999999)
                        {
                            do
                            {
                                system("cls");
                                printf("------------------------------------------\n");
                                printf("Ingrese el dni del varado que desea buscar nuevamente\n");
                                printf("-");
                                scanf("%s", numDni1);
                                num = controlIngresoNum(numDni1);
                            }
                            while(num==0);
                            numDni = atoi(numDni1);
                        }

                        while((isOos(lisDat)!=1)&&(most_numDni(copyc(lisDat))!=numDni))
                        {
                            forwardlist(&lisDat);
                        }
                        if(isOos(lisDat)==1)
                        {
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("No se encontro el Dni buscado\n");
                            printf("----------------------------------------\n");
                        }
                        else
                        {
                            ("----------------------------------\n");
                            mostraDatos(copyc(lisDat));
                            ("----------------------------------\n\n");
                        }
                    }
                    else
                    {
                        printf("----------------------------------------\n");
                        printf("Error. Lista de varados vacia\n");
                        printf("----------------------------------------\n");
                    }
                    break;
                case 2:
                    if(isEmpty(lisDat) == 0)
                    {
                        reset(&lisDat);
                        int auxprov;
                        do
                        {
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("Ingrese la provincia a que desea ingresar el varado\n");
                            printf("<1>Buenos Aires\n");
                            printf("<2>Catamarca\n");
                            printf("<3>Chaco\n");
                            printf("<4>Chubut\n");
                            printf("<5>Cordoba\n");
                            printf("<6>Corrientes\n");
                            printf("<7>Entre Ríos\n");
                            printf("<8>Formosa\n");
                            printf("<9>Jujuy\n");
                            printf("<10>La Pampa\n");
                            printf("<11>La Rioja\n");
                            printf("<12>Mendoza\n");
                            printf("<13>Misiones\n");
                            printf("<14>Neuquén\n");
                            printf("<15>Rio Negro\n");
                            printf("<16>Salta\n");
                            printf("<17>San Juan\n");
                            printf("<18>San Luis\n");
                            printf("<19>Santa Cruz\n");
                            printf("<20>Santa Fe\n");
                            printf("<21>Santiago del Estero\n");
                            printf("<22>Tierra del Fuego\n");
                            printf("<23>Tucuman\n");
                            printf("-");
                            scanf("%s", prov1);
                            auxprov = controlIngresoNum(prov1);
                        }
                        while(auxprov==0);
                        prov = atoi(prov1);
                        while(prov < 1 || prov > 23)
                        {
                            do
                            {
                                system("cls");
                                printf("----------------------------------------\n");
                                printf("Ingrese la provincia a que desea ingresar el varado\n");
                                printf("<1>Buenos Aires\n");
                                printf("<2>Catamarca\n");
                                printf("<3>Chaco\n");
                                printf("<4>Chubut\n");
                                printf("<5>Cordoba\n");
                                printf("<6>Corrientes\n");
                                printf("<7>Entre Ríos\n");
                                printf("<8>Formosa\n");
                                printf("<9>Jujuy\n");
                                printf("<10>La Pampa\n");
                                printf("<11>La Rioja\n");
                                printf("<12>Mendoza\n");
                                printf("<13>Misiones\n");
                                printf("<14>Neuquén\n");
                                printf("<15>Rio Negro\n");
                                printf("<16>Salta\n");
                                printf("<17>San Juan\n");
                                printf("<18>San Luis\n");
                                printf("<19>Santa Cruz\n");
                                printf("<20>Santa Fe\n");
                                printf("<21>Santiago del Estero\n");
                                printf("<22>Tierra del Fuego\n");
                                printf("<23>Tucuman\n");
                                printf("-");
                                scanf("%s", prov1);
                                auxprov = controlIngresoNum(prov1);
                            }
                            while(auxprov==0);
                            prov = atoi(prov1);
                        }
                        int aux=0;
                        while((isOos(lisDat)!=1))
                        {
                            if((most_provinciaIngreso(copyc(lisDat))==prov))
                            {
                                ("----------------------------------\n");
                                mostraDatos(copyc(lisDat));
                                ("----------------------------------\n\n");
                                forwardlist(&lisDat);
                                aux++;
                            }
                            else
                            {
                                forwardlist(&lisDat);
                            }

                        }
                        if(aux==0)
                        {
                            system("cls");
                            printf("----------------------------------\n");
                            printf("No se encontro el varado buscado\n");
                            printf("----------------------------------\n");
                        }
                    }
                    else
                    {
                        printf("--------------------------------\n");
                        printf("Error. Lista de varados vacia\n");
                        printf("--------------------------------\n");
                    }
                    break;
                case 3:
                    printf("--------------------------------\n");
                    printf("Saliendo del menu de informacion\n");
                    printf("--------------------------------\n");
                    system("cls");
                    break;
                default:
                    printf("--------------------------------\n");
                    printf("Opcion invalida");
                    printf("\n--------------------------------\n");
                    break;
                }
            }
            while(opc != 3);
            }else{
                system("cls");
                printf("--------------------------------\n");
                printf("Error. Lista de varados vacia\n");
                printf("--------------------------------\n");
            }
            break;
            case 3:
            if(isEmpty(lisDat)==0){
                do
                {
                printf("------------------------------------\n");
                printf("BIENVENIDO AL MENU DE MODIFICACION\n");
                printf("------------------------------------\n");
                printf("Que desea modificar?\n");
                printf("<1> Pais en el que se encuentra\n");
                printf("<2> Provincia a la que desea ingresar\n");
                printf("<3> Existencia de persona de grupo de riesgo\n");
                printf("<4> Volver atras\n");
                printf("Opcion: ");
                do
                {
                    scanf("%s", opc1);
                    auxmodi = controlIngresoNum(opc1);
                }
                while(auxmodi==0);
                opc = atoi(opc1);

                switch(opc)
                {
                case 1:
                    if(isEmpty(lisDat)==0)
                    {
                        system("cls");
                        menuModificarPais(&lisDat);
                    }
                    else
                    {
                        printf("----------------------------------------\n");
                        printf("Error. Lista de varados vacia\n");
                        printf("----------------------------------------\n");
                    }

                    break;
                case 2:
                    if(isEmpty(lisDat)==0)
                    {
                        system("cls");
                        menuModificarProvincia(&lisDat);
                    }
                    else
                    {
                        printf("----------------------------------------\n");
                        printf("Error. Lista de varados vacia\n");
                        printf("----------------------------------------\n");
                    }
                    break;
                case 3:
                    if(isEmpty(lisDat)==0)
                    {
                        system("cls");
                        menuModificarPersonaRiesgo(&lisDat);
                        menuArchivosPersonaDeRiesgo(lisDat);
                    }
                    else
                    {
                        printf("----------------------------------------\n");
                        printf("Error. Lista de varados vacia\n");
                        printf("----------------------------------------\n");
                    }
                    break;
                case 4:

                    break;
                default:
                    printf("-------------------\n");
                    printf("Error.\nOpcion invalida\n");
                    printf("-------------------\n");
                    break;
                }
            }
            while(opc!=4);
            system("cls");
            }else{
                system("cls");
                printf("--------------------------------\n");
                printf("Error. Lista de varados vacia\n");
                printf("--------------------------------\n");
            }
            break;
        case 4:
            if(isEmpty(lisDat)==0)
            {
                printf("----------------------------------------\n");
                printf("Ingrese el pais de los varados a eliminar\n");
                printf("----------------------------------------\n");
                printf("<1>España\n");
                printf("<2>Italia\n");
                printf("<3>Estados Unidos\n");
                printf("<4>Brasil\n");
                printf("<5>Chile\n");
                printf("<6>Uruguay\n");
                printf("<7>Mexico\n");
                printf("<8>Alemania\n");
                printf("<9>Francia\n");
                printf("<10>Cuba\n");
                printf("<11>Perú\n");
                printf("<12>Rusia\n");
                printf("<13>Japon\n");
                printf("<14>China\n");
                printf("<15>Venezuela\n");
                printf("<16>Australia\n");
                printf("<17>Bolivia\n");
                printf("<18>Canadá\n");
                printf("<19>Croacia\n");
                printf("<20>Guatemala\n");
                printf("----------------------------------------\n");
                printf("-");
                int numPais;
                fflush(stdin);
                scanf("%d", &numPais);

                reset(&lisDat);
                printf("------------------------\n");
                printf("Datos de los varados eliminados\n");
                printf("------------------------\n");
                int contaux = 0;
                while(isOos(lisDat)!=1)
                {
                    if(most_pais(copyc(lisDat))==numPais)
                    {
                        printf("------------------------\n");
                        printf("Nombre y Apellido: %s %s\n", most_nombre(copyc(lisDat)), most_apellido(copyc(lisDat)));
                        printf("Dni: %d\n", most_numDni(copyc(lisDat)));
                        printf("------------------------\n");
                        contaux++;
                        forwardlist(&lisDat);
                    }
                    else
                    {
                        forwardlist(&lisDat);
                    }
                }

                if(contaux==0){
                    system("cls");
                    printf("\n----------------------------------------\n");
                    printf("Error. no hay varados para eliminar en ese pais\n");
                    printf("------------------------------------------\n");
                }

                eliminarVarados(&lisDat, numPais);
                system("pause");
                system("cls");
            }
            else
            {
                system("cls");
                printf("\n----------------------------------------\n");
                printf("Error. Lista de varados vacia\n");
                printf("----------------------------------------\n");

            }
            break;
        case 5:
            reset(&lisDat);
            if(isEmpty(lisDat)==0)
            {
                do
                {
                    printf("----------------------------------------\n");
                    printf("Ingrese el pais en el que desea contar los varados\n");
                    printf("<1>España\n");
                    printf("<2>Italia\n");
                    printf("<3>Estados Unidos\n");
                    printf("<4>Brasil\n");
                    printf("<5>Chile\n");
                    printf("<6>Uruguay\n");
                    printf("<7>Mexico\n");
                    printf("<8>Alemania\n");
                    printf("<9>Francia\n");
                    printf("<10>Cuba\n");
                    printf("<11>Perú\n");
                    printf("<12>Rusia\n");
                    printf("<13>Japon\n");
                    printf("<14>China\n");
                    printf("<15>Venezuela\n");
                    printf("<16>Australia\n");
                    printf("<17>Bolivia\n");
                    printf("<18>Canadá\n");
                    printf("<19>Croacia\n");
                    printf("<20>Guatemala\n");
                    printf("----------------------------------------\n");
                    printf("-");
                    scanf("%s", numcant1);
                    numaux = controlIngresoNum(numcant1);
                }
                while(numaux==0);
                numcant = atoi(numcant1);
                while(numcant < 1 || numcant > 20)
                {
                    do
                    {
                        printf("----------------------------------------\n");
                        printf("Ingrese el pais en el que desea contar los varados\n");
                        printf("<1>España\n");
                        printf("<2>Italia\n");
                        printf("<3>Estados Unidos\n");
                        printf("<4>Brasil\n");
                        printf("<5>Chile\n");
                        printf("<6>Uruguay\n");
                        printf("<7>Mexico\n");
                        printf("<8>Alemania\n");
                        printf("<9>Francia\n");
                        printf("<10>Cuba\n");
                        printf("<11>Perú\n");
                        printf("<12>Rusia\n");
                        printf("<13>Japon\n");
                        printf("<14>China\n");
                        printf("<15>Venezuela\n");
                        printf("<16>Australia\n");
                        printf("<17>Bolivia\n");
                        printf("<18>Canadá\n");
                        printf("<19>Croacia\n");
                        printf("<20>Guatemala\n");
                        printf("----------------------------------------\n");
                        printf("-");
                        scanf("%s", numcant1);
                        numaux = controlIngresoNum(numcant1);
                    }
                    while(numaux==0);
                    numcant = atoi(numcant1);
                }
                auxcant = contadorDePersonas(lisDat, auxcant, numcant);
                printf("----------------------------------------\n");
                printf("La cantidad de personas varadas en el pais es de: %d\n", auxcant);
                printf("----------------------------------------\n");
                system("pause");
                system("cls");

            }
            else
            {
                system("cls");
                printf("\n----------------------------------------\n");
                printf("Error. Lista de varados vacia\n");
                printf("----------------------------------------\n");
            }
            break;
        case 6:
            if(isFull(lisDat)==0)
            {
                dev = precargaVarados(&lisDat);
                if(dev == 1)
                {
                    system("cls");
                    printf("\n----------------------------------------\n");
                    printf("No hay varados para cargar\n");
                    printf("----------------------------------------\n");
                }
                else
                {
                    system("cls");
                    printf("\n----------------------------------------\n");
                    printf("Varados precargados correctamente\n");
                    printf("----------------------------------------\n");
                }
            }
            else
            {
                system("cls");
                printf("\n----------------------------------------\n");
                printf("Error. Lista de varados vacia\n");
                printf("----------------------------------------\n");
            }

            break;
        case 7:
            printf("----------------------------\n");
            printf("Ya puede cerrar la ventana\n");
            printf("----------------------------\n");
            break;
        default:
            printf("-------------------\n");
            printf("Error.\nOpcion invalida\n");
            printf("-------------------\n");
            break;

        }
    }
    while(opc != 7);
}

