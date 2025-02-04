# 1. Árboles de Expresión
## Árbol de expresión para la inicialización de los contadores

      =
     / \
    nl  =
       / \
      nw  =
         / \
        nc  0

## Árbol de expresión para la expresión de control del segundo if

             ||
           /    \
          ||     ==
        /    \  /  \
       /      \c  '\t'
      ==      ==   
     /  \    /  \   
    c   ' ' c  '\n'  

# 2. Máquina de Estado

## Maquina de estado para n-uplas

M = {Q , Σ , q0 , T}

Q = {In , Out}

Σ = ASCII

 - np = '/t' || ' ' || '/n'

 - p = Σ - np

q0 = Out

T =

|  T  | p    | np     |
|-----|------|--------|
| In  | In   | Out    |
| Out | In   | Out    |

# 3. Implementaciones de Máquinas de Estado

## a. Implementación #1: Una variable para el estado actual.

#### Version de [KR1988]

VENTAJAS:

 - El código es relativamente simple y cumple su función básica de contar líneas, palabras y caracteres de manera eficiente.

 - Utiliza un bucle while para leer cada carácter una vez, lo cual es eficiente en términos de tiempo de ejecución y uso de recursos.

 - El uso de #define IN 1 y #define OUT 0 mejora la claridad al indicar el estado dentro o fuera de una palabra.

DESVENTAJAS:

 - No maneja adecuadamente todos los casos de delimitadores de palabras. Por ejemplo, no cuenta correctamente palabras que están separadas 
   por múltiples espacios o caracteres especiales.

 - El código asume que los delimitadores de palabras son espacios, tabuladores y saltos de línea. Esto puede no ser suficiente para textos 
   más complejos que podrían incluir otros caracteres como delimitadores.

 - No hay un manejo explícito de límites de memoria o manejo de entradas muy grandes. Podría generar un problema si la entrada es demasiado 
   grande para la memoria disponible.

#### Version de histograma-1-enum-switch.c

VENTAJAS:

 - Utiliza un enum t_state para indicar el estado actual del procesamiento de palabras, OUT para fuera de una palabra e IN para dentro de una palabra, 
   lo cual mejora la claridad y estructura del código.

 - La estructura del codigo y el como esta construido se asocia más a un diagrama de estados.

 - Tambien utiliza un bucle while lo cual es eficiente en términos de tiempo de ejecución y manejo de recursos.

 - Maneja explícitamente el caso de EOF, asegurándose de contar y almacenar la palabra que esta siendo leída antes de alcanzar el final del archivo.

 - El código organiza las palabras en un arreglo array_ncp según su longitud, incrementando el conteo en la posición correspondiente.

DESVENTAJAS:

 - Al usar getchar() y detectar EOF para terminar la lectura, puede ser necesario simular EOF para probar o debuggear el código en algunas situaciones.

 - Aunque maneja espacios, tabuladores y saltos de línea como delimitadores de palabras, no maneja caracteres de puntuación o casos especiales como palabras compuestas.

 - No hay validación explícita de entrada, por lo que asume que la entrada es válida y no maneja casos donde la entrada podría ser incorrecta o malformada.

## b. Implementación #2: Sentencias goto

El uso de go to puede llevar a una estructura de código difícil de razonar acerca del comportamiento del programa, especialmente en código grande y complejo, esto puede llevar a errores difíciles de detectar y corregir. El flujo de control lineal usando bucles, condicionales y funciones es mejor porque hace que el código sea más fácil de seguir y de modificar. Sin embargo, hay situaciones específicas donde el rendimiento es necesario y el uso de go to mejora significativamente la eficiencia del código. Por lo tanto existen algunos lenguajes modernos que admiten su uso como C, C++, C#, Fortran, Python, Java y Ruby.