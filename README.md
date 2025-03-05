# Programacion-1
Proyecto final de programación 1 (Lenguaje C)

Temática: habitantes argentinos que quedaron varados en el exterior por la pandemia y el
DNU de aislamiento.
Se considera varado a la persona que estando en el extranjero completa sus datos para
solicitar el permiso de ingresar al país, a una provincia en particular. El “varado” puede o no
estar acompañado por un grupo familiar.
Consigna: se desea realizar un programa en lenguaje C el cual permita administrar las
solicitudes y permisos de ingreso al país de las personas que se encuentran varadas en el
extranjero. Para esto es necesario implementar dos TDA

1. TDA Varado (varado.h)
El estudiante debe definir la estructura de datos y seleccionar el tipo de datos mas apropiado
para almacenar la información de cada varado. La información que se desea almacenar de
cada varado es la siguiente:
-Apellido
-Nombre
-Documento (el cual debe ser DNI)
-Fecha de salida del país (tipo fecha visto en teoría)
-País en el que se encuentra (busque al menos 20 países)
-Cantidad de personas que integran del grupo (por defecto 1)
-Existen en el grupo personas de riesgo?
-Provincia a la que desea ingresar (debe incluir todas las provincias de Argentina)
Para implementar el TDA debe definir las operaciones propias de un TDA como: inicialización,
setter y getter para manejar la estructura de datos.
Se piden las siguientes operaciones (20)

Inicializar el TDA (1) inicializa valores por defecto
Cargar cada uno de los campos por separado. (8)
Modificar por separado los campos: provincia, persona de grupo de riesgo, país en el que se
encuentra (3)
Mostrar cada uno de los campos por separado. (8)

2. TDA Lista Bidireccional (listabi.h)
La cual es una lista dinámica bidireccional, para implementar la misma use como base la
implementación de la lista dinámica unidireccional entregada por la cátedra, modificándola de
tal manera que se permita mover el UNICO CURSOR en ambas direcciones.
Definir las estructuras de datos y operaciones (10) de la lista bidireccional (insert, suppress,
isempty, isoos, copy, isfull, forward, backward, init, reset) necesarias para administrar una
lista vinculada bidireccional con memoria dinámica.

3. Definir en el programa principal que permita realizar las siguientes funcionalidades, para
esto haga uso de funciones para modularizar lo que se pide:

a) cargar una cantidad n de varados en la lista por teclado. La cantidad es ingresada por el
usuario.

b) mostrar los datos de un varado.

c) buscar un varado por dni.

e) buscar varados por provincia a la que desean ingresar.

f) contar la cantidad de personas que están varadas en un país determinado, para esto
considerar la cantidad de personas del grupo familiar, la función debe ser recursiva.

g) modificar país y/o provincia de un varado por dni.

h) modificar la existencia de persona de grupo de riesgo en el grupo de un varado por dni.

i) eliminar todos los varados de un país determinado, debe mostrar el nombre, apellido y dni
del o los varados eliminados.

j) copiar en un archivo denominado viajan.txt todos los datos de los varados que tienen como
integrante una persona del grupo de riesgo.

k) realizar una precarga de la lista por archivo. Es decir cargar desde el archivo denominado
precarga.txt un grupo de varados.

Realice un menú de opciones que permita realizar las funcionalidades solicitadas en cualquier
orden y las veces que desee un usuario. Considere que se realiza un programa que luego será
utilizado por un usuario, es por esto NO OLVIDAR los carteles!!

Notas:
‐ En el caso que un dato u operación no pueda realizarse debe informarlo por pantalla.
‐ Los archivos deben ser legibles desde un editor de texto.
‐ Recuerde que en todos los casos debe manejar los TDA con las funciones propias de
los mismos sin violar la semántica correspondiente a la estructura de almacenamiento.
‐ Considere el uso de tipo y estructuras auxiliares en caso de ser necesarias.
‐ Pruebe el programa en varias ocasiones con diferentes datos semejantes a los reales,
diferente orden de operaciones.
‐ Abra los archivos y revise que las operaciones se realizaron en forma correcta
