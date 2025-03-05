typedef struct{
    int dia, mes, anio;
}fecha;

typedef struct{
    char nombre[30];
    char apellido[30];
    long int numDni;
    fecha salida;
    int pais;
    int cantPersonas;
    int personRiesgo;
    int provinciaIngreso;
}datos;

void init_varado(datos *p){
    (*p).cantPersonas = 1;
}

void cargar_nombre(datos *p, char nombre1[]){
    strcpy((*p).nombre, nombre1);
}

void cargar_apellido(datos *p, char apellido1[]){
    strcpy((*p).apellido, apellido1);
}

void cargar_numDni(datos *p, long int numDni1){
    (*p).numDni = numDni1;
}

void cargar_fecha(datos *p, int dia1, int mes1, int anio1){
    (*p).salida.dia = dia1;
    (*p).salida.mes = mes1;
    (*p).salida.anio = anio1;
}

void cargar_pais(datos *p, int pais1){
    (*p).pais = pais1;
}

void cargar_cantPersonas(datos *p, int cantPersonas1){
    (*p).cantPersonas = cantPersonas1;
}

void cargar_personRiesgo(datos *p, int personRiesgo1){
    (*p).personRiesgo = personRiesgo1;
}

void cargar_provinciaIngreso(datos *p, int provinciaIngreso1){
    (*p).provinciaIngreso = provinciaIngreso1;
}

void modi_pais(datos *p, int pais1){
    (*p).pais = pais1;
}

void modi_personRiesgo(datos *p, int personRiesgo1){
    (*p).personRiesgo = personRiesgo1;
}

void modi_provinciaIngreso(datos *p, int provinciaIngreso1){
    (*p).provinciaIngreso = provinciaIngreso1;
}

char* most_nombre(datos p){
    char *nombre1=(char*)malloc(sizeof(char)*30);
    strcpy(nombre1, p.nombre);
    return nombre1;
}

char* most_apellido(datos p){
    char *apellido1=(char*)malloc(sizeof(char)*30);
    strcpy(apellido1, p.apellido);
    return apellido1;
}

long int most_numDni(datos p){
    return p.numDni;
}

int most_dia(datos p){
    return p.salida.dia;
}

int most_mes(datos p){
    return p.salida.mes;
}

int most_anio(datos p){
    return p.salida.anio;
}

int most_pais(datos p){
    return p.pais;
}

int most_cantPersonas(datos p){
    return p.cantPersonas;
}

int most_personRiesgo(datos p){
    return p.personRiesgo;
}

int most_provinciaIngreso(datos p){
    return p.provinciaIngreso;
}
