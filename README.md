# Proyecto Final de Programación 1 (Lenguaje C)

## Temática
El proyecto consiste en desarrollar un programa en lenguaje C que permita administrar las solicitudes y permisos de ingreso al país de personas argentinas varadas en el extranjero debido a la pandemia y el DNU de aislamiento. Se considera varado a una persona que, estando en el extranjero, completa sus datos para solicitar el permiso de ingresar al país, a una provincia en particular. El "varado" puede o no estar acompañado por un grupo familiar.

## Descripción General
El programa maneja la información de los varados, permitiendo registrar, modificar, eliminar y consultar los datos. Además, permite realizar operaciones como contar el número de personas varadas en un país determinado y gestionar grupos familiares con personas de riesgo.

## Estructura del Proyecto

### TDA Varado (`varado.h`)
- **Apellido**
- **Nombre**
- **Documento (DNI)**
- **Fecha de salida del país**
- **País en el que se encuentra** (al menos 20 países)
- **Cantidad de personas en el grupo** (por defecto 1)
- **Existencia de personas de riesgo**
- **Provincia a la que desea ingresar** (todas las provincias de Argentina)

Operaciones:
- Inicializar estructura
- Cargar campos por separado
- Modificar provincia, país o riesgo
- Mostrar campos por separado

### TDA Lista Bidireccional (`listabi.h`)
Lista dinámica con cursor que se mueve en ambas direcciones. Operaciones:
- Insertar, eliminar
- Verificar si está vacía o llena
- Avanzar/retroceder cursor
- Inicializar y resetear lista

## Funcionalidades del Programa
- **Cargar varados**: Ingresar datos manualmente o desde archivo (`precarga.txt`).
- **Mostrar datos de un varado**.
- **Buscar por DNI o provincia**.
- **Contar personas varadas en un país** (función recursiva).
- **Modificar país, provincia o grupo de riesgo**.
- **Eliminar varados por país**, mostrando los datos eliminados.
- **Copiar a archivo (`viajan.txt`) los varados con personas de riesgo**.

## Interfaz de Usuario
Menú interactivo con opciones para realizar todas las funcionalidades. El usuario puede repetir operaciones hasta salir del programa.

## Consideraciones
- Informar errores si una operación no puede realizarse.
- Verificar archivos generados.
- Probar con datos reales y diferentes combinaciones de operaciones.

## Instrucciones de Uso
1. **Compilar:**
```bash
gcc -o varados varados.c
```

2. **Ejecutar:**
```bash
./varados
```

3. **Archivos:**
- `precarga.txt`: Datos iniciales.
- `viajan.txt`: Datos de varados con personas de riesgo.

---


