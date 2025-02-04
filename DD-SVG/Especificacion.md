# NOMBRE DEL LENGUAJE

SIMPLY

# ESPECIFICACION DEL LENGUAJE

## VISION:

Nuestro lenguaje de programación es de propósito general, orientado a la creación y manipulación de gráficos bidimensionales. Está diseñado con una sintaxis concisa y estructurada, lo que permite a los usuarios definir y manipular figuras geométricas, como rectángulos, círculos y elipses, de manera sencilla y directa.

El principal objetivo del lenguaje es facilitar la creación de gráficos en proyectos básicos, manteniendo un equilibrio entre simplicidad y eficiencia. Es ideal para aquellos que buscan portabilidad y flexibilidad, evitando la complejidad de lenguajes gráficos completos o que dependen de interfaces avanzadas, enfocándose en la claridad sin sacrificar el control.

## LEXICO:

DEFINICIONES  

Puntuadores:
~~~
- INICIO = { 
- FIN = } 
- FE = ;
~~~

Constante Numerica:
~~~
- NUMERO = [0-9]+
~~~

Cadena Literal:
~~~
- CADENA = [^"]*
~~~

Keywords de Figuras:
~~~
- RECTANGULO = R
- CIRCULO = C
- ELIPSE = E
~~~

Keywords de atributos:
~~~
- PosicionEnX = x
- PosicionEnY = y 
- PosicionEnXDeCentro = xc
- PosicionEnYDeCentro = yc 
- Ancho = w
- Altura = h
- Radio = r
- RadioEnX = rx
- RadioEnY = ry
- RellenoDeColor = f
~~~

Keywords de Colores:
~~~
- Color = Yellow | Blue | Red | Green
~~~

## SINTAXIS: 

~~~
<unidad de traduccion>::= <INICIO> {<Figura Circulo> | <Figura Elipse> | <Figura Rectangulo>}* <FIN>
~~~
~~~
<Figura Circulo>::= <CIRCULO> {<Atributo Circulo>}* <FE>
<Atributo Circulo>::= <PosicionEnXDeCentro> <NUMERO>
                   | <PosicionEnYDeCentro> <NUMERO>
                   | <Radio> <NUMERO>
                   | <Atributo Color>
~~~
~~~
<Figura Elipse>::= <ELIPSE> {<Atributo Elipse>}* <FE>
<Atributo Elipse>::= <PosicionEnXDeCentro> <NUMERO>
                   | <PosicionEnYDeCentro> <NUMERO>
                   | <RadioEnX> <NUMERO>
                   | <RadioEnY> <NUMERO>
                   | <Atributo Color>
~~~
~~~
<Figura Rectangulo>::= <RECTANGULO> {<Atributo Rectangulo>}* <FE>
<Atributo Rectangulo>::= <PosicionEnX> <NUMERO>  
                      | <PosicionEnY> <NUMERO>
                      | <Ancho> <NUMERO>  
                      | <Altura> <NUMERO>
                      | <Atributo Color>
~~~
~~~
<Atributo Color>::= <RellenoDeColor> <Color>  
~~~
~~~
<Comentario>::= "\"" <CADENA> "\""
~~~

## SEMANTICA Y RESTRICCIONES: 
- **Restriccion General:**
  - Todos las etiquetas/atributos deben de estar separados por espacios/enter/tabs.
- **Unidad de traduccion:**
  
  Semantica:
  - El simbolo de "INICIO" indica el comienzo de una unidad de traduccion.
  - La "Figura Rectangulo/Circulo/Elipse" representa los elementos que serán evaluados o compilados dentro de esta unidad de traducción.
  - El simbolo de "FIN" indica el fin de una unidad de traduccion.
    
  Restriccion:
  - No puede haber anidamiento de etiquetas ni de INICIO/FIN de programa.

- **Figuras:**  
  
  Semantica:
  - "Atributo/Atributos" indica las propiedades que puede tener cada figura.
  - "FE" indica el fin de etiqueta de la figura previamente abierta.

  Reestriccion:
  - No puede haber atributos repetidos en una misma etiqueta.

- **Figura Rectangulo:**
  
  Semantica:
  - "Rectangulo" indica el comienzo de una etiqueta de figura rectangular.
 
- **Figura Circulo:**  
  
  Semantica:
  - "Circulo" indica el comienzo de una etiqueta de figura circular.

- **Figura Elipse:**  
  
  Semantica:  
  - "Elipse" indica el comienzo de una etiqueta de figura eliptica.
      
- **Atributo:**
  
  Semantica:  
  - "PosicionEnX" define la posicion de la figura en X.
  - "PosicionEnY" define la posicion de la figura en Y.
  - "PosicionEnXDeCentro" define la posicion del centro en X.
  - "PosicionEnYDeCentro" define la posicion del centro en Y.
  - "Ancho" define el ancho de la figura.
  - "Altura" define el Alto de la figura.
  - "Radio" define el radio de la figura.
  - "RadioEnX" define el radio en X de la figura.
  - "RadioEnY" define el radio en Y de la figura.
  - "RellenoDeColor" define el color de relleno de la figura.

## EJEMPLOS:
~~~
Simple: { R h15 w25 ; }

Salida SVG:
<svg>
        <rect height="15" width="25" />
</svg>
~~~
~~~
Complejo:
{
    "esto es un comentario"
    R x10 y20 h15 w25 fYellow ;
    C xc80 yc50 r30 fBlue ;
    "esto es una elipse"
    E xc150 yc50 rx15 ry25 fRed ;
}

Salida SVG:
<svg>
        <rect x="10" y="20" height="15" width="25" fill="yellow" />
        <circle cx="80" cy="50" r="30" fill="blue" />
        <ellipse cx="150" cy="50" rx="15" ry="25" fill="red" />
</svg>
~~~
