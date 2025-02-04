1- Preprocesador
hello2.c

Las conclusiones que sacamos luego de generar el hello2.i, es que antes de copiar las lineas del codigo, pega todo el contrato de la biblioteca stdio. 

hello3.c

La primer linea del archivo hello3.c, lo que hace es incluir unicamente el contrato de la funcion printf. 
La diferencia que hay entre hello3.c y hello3.i, es que en archivo hello3.i antes de tener el codigo del archivo hello3.c, tiene una serie de comandos que ayudan al preprocesador y al compilador. 

2- Compilacion

El objetivo de ese codigo, es ser un archivo escrito en lenguaje assembly para que el ensamblador despues pueda generar el archivo objeto. 
Se usan instrucciones como call en la linea 23 en donde esta llamando a la funcion prontf. 

3- Vinculacion

El analisis que hacemos sobre el resultado de ejecutar el archivo hello5.c, es que logra ejecutar, pero el resultado no es el esperado. Esto sucede porque en la invocacion de la funcion printf, solo se pasa el string que contiene un %d, pero nunca se pasa un segundo parametro con el valor que tiene que imprimir. Por ende agarra cualquier valor. Inclusive ejecuntandolo mas de una vez, los valores son diferentes. 

4- Correcion de Bug

Al agregar el segundo parametro a la funcion printf, se logra el resultado esperado: "La respuesta es 42". 

5- Remocion del Prototipo

El compilador arroja warnings y notas. Arroja warnings por invocar una funcion sin que este definida ni incluida como contrato. La nota sugiere hacer el include de la libreria stdio.h

Un prototipo es la cabezera de la funcion, donde se define el nombre de la funcion y el tipo de los parametros que recibe. Se puede generar de manera directa o indirecta. 

Una declaracion implicita de una funcion, es cuando el compilador compila una funcion invocada en main que no estaba declarada previamente y hace una suposicion del tipo de la funcion y de los tipos de sus parametros, basandose en como se utiliza en el codigo. 

La especificacion indica un conjunto de reglas o normas a seguir para un correcto funcionamiento, definidas por el comite de ANSI C.

Las funciones built-in son funciones que ya estan implementadas en el lenguaje porque se encuentran en la biblioteca estandar.

GCC es uno de los compiladores que mas se apegan a la especificacion definida por el comite, sin embargo hay veces en las que se aleja de esta espeficacion para mejorar la productividad de los desarrolladores y para mantener vigente el codigo antiguo, por ello c no es un lenguaje portable ya que depende del compilador que compile o no. No va a encontra de la espeficacion porque se mueve en zonas grises donde la especificacion no es clara o no esta dada.

6- Compilación Separada: Contratos y Módulos

Se puede generar un programa ejecutable, mediante la previa compilacion de cada archivo fuente y luego linkear sus archivos objetos, obteniendo un unico archivo ejecutable. Esto permite tener la misma funcionalidad que un include pero sin preprocesarlo. 

Sin importar que parametro eliminemos en la invocacion de la funcion prontf, la funcion de igual manera ejecuta. El problema es que el resultado que arroja es erroneo/inconsistente. Esto sucede porque al ser un "wrapper" de la funcion printf, esta ultima va a ejecutar pero teniendo los mismos resultados que en los primeros archivos hello. 

La ventaja que logramos ver de incluir el contrato en el cliente y el proveedor, es que las funciones no pueden ser implicitas y ademas que nos aseguramos de que el preprocesador pegue el contrato una unica vez. 

---------------Creditos Extra-------------------

Bibliotecas:

Una biblioteca es una colección de código reutilizable que facilita el desarrollo de software. Estas bibliotecas contienen funciones, clases y otros componentes precompilados que realizan tareas, lo que permite a los desarrolladores evitar escribir código desde cero.

Entre los tipos de bibliotecas, se encuentran las bibliotecas estaticas y las bibliotecas dinamicas, las cuales de manera resumida se diferencian en:

Bibliotecas Estáticas:

- Se enlazan al programa durante la compilación.
- El código se incorpora al ejecutable final.
- Ejemplos: .lib en Windows, .a en Unix/Linux.

Bibliotecas Dinámicas:

- Se enlazan en tiempo de ejecución.
- El código se carga en la memoria cuando se ejecuta el programa.
- Ejemplos: .dll en Windows, .so en Unix/Linux, .dylib en macOS.

Como ventajas y desventajas de utilizar bibliotecas se encuentran:

Ventajas:

- Reutilización de Código: Aprovechan código ya probado y optimizado.
- Modularidad: Facilitan el mantenimiento y la actualización.
- Reducción del Tiempo de Desarrollo: Permiten enfocarse en la lógica específica de la aplicación.

Desventajas:

- Complejidad de Dependencias: Gestionar dependencias puede ser complicado, especialmente con bibliotecas dinámicas.
- Problemas de Compatibilidad: Las bibliotecas pueden no ser compatibles entre diferentes sistemas operativos o versiones de compiladores.
- Tamaño del Ejecutable: Las bibliotecas estáticas pueden aumentar significativamente el tamaño del ejecutable.

En terminos de portabilidad :

Bibliotecas Estáticas:

- Portabilidad limitada por la compatibilidad del compilador y la arquitectura del sistema.
- Mayor independencia de las versiones del sistema operativo.

Bibliotecas Dinámicas:

- Necesitan estar disponibles en el sistema en tiempo de ejecución.
- Sensibles a las versiones del sistema operativo y las rutas de búsqueda de bibliotecas.

Distribución de Bibliotecas Estáticas:

- Incorporadas en el ejecutable: Al distribuir un programa que usa una biblioteca estática, el código de la biblioteca se incluye en el ejecutable, lo que facilita la distribución ya que no requiere archivos adicionales.
- Desventajas: Incrementa el tamaño del ejecutable y puede requerir recompilación para diferentes sistemas o versiones.

Distribución de Bibliotecas Dinámicas:
- Archivos Separados: Las bibliotecas dinámicas se distribuyen como archivos independientes (.dll, .so, .dylib), que deben acompañar al ejecutable.
- Ventajas: Menor tamaño del ejecutable y posibilidad de actualizar la biblioteca sin recompilar el programa.
- Desventajas: Necesita asegurarse de que las bibliotecas dinámicas estén en el PATH o en el mismo directorio que el ejecutable.