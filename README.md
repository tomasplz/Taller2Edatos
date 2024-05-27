# Taller2Edatos
Segundo taller del ramo de estructura de datos de la Universidad Catolica del Norte) el cual simula una farmacia que necesita un programa para organizar las ventas del local.

Se requeriere que el software sea capaz de poder conocer la cantidad de
productos en bodega por categoría y sub-categoría, generar boletas de venta y
manejo de clientes utilizando un sistema de colas con preferencia.

## Requirements

[Windows: compilador MinGW]([url](https://sourceforge.net/projects/mingw-w64/))

Linux: compilador gcc

### Comando para compilar y ejecutar en Windows

g++ .\main.cpp .\Classes\*.cpp .\System\*.cpp -o programa.exe

.\programa.exe
[Requerido el compilador de g++]

### Comando para compilar y ejecutar en Linux

make [Requerido compilador gcc]

./programa.exe

## Funcionamiento

El programa desde el main una instancia del objeto "Sys.cpp", y dentro de el se almacenarán colas con ventas (que
serán temporales de la sesión) y instanciará las categorias clientes que a su vez almacenarán en colas que irán por
el orden de llegada de estos mismos.
También se ocuparán hashmaps para almacenar los productos divididos por categoria y subcategoria.

Si no existe un archivo ya creado de productos, se creará uno automaticamente.

@author Tomas Vargas Williams 
21076318K 
tomas.vargas@alumnos.ucn.cl
