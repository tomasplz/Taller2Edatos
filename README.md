@author Tomas Vargas Williams 
21076318K tomas.vargas@alumnos.ucn.cl
# Taller2Edatos

Comando para compilar en windows
PARA COMPILAR
g++ .\main.cpp .\Classes\*.cpp .\System\*.cpp -o programa.exe
EJECUTAR
.\programa.exe
este comando creara un archivo programa.exe que se podra ejecutar desde una maquina windows.
[Requerido el compilador de g++]

Comando para compilar en Linux.
make [Requerido compilador gcc]
./programa.exe

El programa desde el main una instancia del objeto "Sys.cpp", y dentro de el se almacenarán colas con ventas (que
serán temporales de la sesión) y instanciará las categorias clientes que a su vez almacenarán en colas que irán por
el orden de llegada de estos mismos.
También se ocuparán hashmaps para almacenar los productos divididos por categoria y subcategoria.

Si no existe un archivo ya creado de productos, se creará uno automaticamente.