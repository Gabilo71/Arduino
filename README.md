

Esta es una guía breve sobre cómo se va a construir el proyecto. También contiene la estructura elemental del código para asegurar que sea más fácil de entender.
El objetivo principal es crear un alimentador para la industria. En nuestro caso, alimenta láminas de acero que tienen un ancho exacto. Para activar el alimentador utilizaremos un controlador mediante botones. El controlador compartirá los datos a través de pines digitales. El proyecto se supone que se hará con Arduino Uno, por lo que el lenguaje de programación será Arduino. El hardware consistirá en 3 motores para mover el alimentador y un electroimán. Los tipos de sensores que usaremos serán tanto analógicos como digitales. Algunos de ellos son finales de carrera, sensor láser, botones (pull-down)... etc. El resto se explicará sobre la marcha.
Nota: el ancho podría cambiarse añadiendo un monitor serie. (Al final habrá algo de código; si deseas esta opción, simplemente reemplaza la función original por la que prefieras ___).

--- CONSTRUCCIÓN DEL PROYECTO ---

El proyecto necesita una base para soportar el alimentador y debe poder subir y bajar en posiciones determinadas. Se usarán algunas columnas como en la ilustración. Sobre la columna más grande colocaremos las cadenas para mover el alimentador de derecha a izquierda. En ambos lados pondremos los dos motores que permiten que el electroimán suba y baje en cualquiera de los dos lados. Luego conectaremos los motores a nuestro Arduino.
Primero conectaremos los 3 motores a GND y a 5V con dos relés por motor para poder cambiarles el sentido de giro. Los motores serán controlados desde un controlador de botones.

Llamaremos posición 1 cuando el alimentador esté con la lámina.
La posición 2 será cuando la lámina esté elevada hasta arriba.
La posición 3 será cuando el movimiento horizontal termine y se suponga que debe bajar.
La última posición es cuando el alimentador deja la lámina.
Así que el alimentador se moverá de la posición 1 a la 4.

--- FUNDAMENTOS DE PROGRAMACIÓN ---

SALIDAS 3 DIGITALES 13,12,11
ENTRADAS 2,3,4,5,6

Imagen en Arduino/Esquema básico de los pines a utilizar.png

