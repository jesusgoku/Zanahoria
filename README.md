# El Juego de la "Zanahoria"
Esta es la triste historia de una pobre zanahoria que debe escapar de unos conejos feroces y hambrientos que no se cansaran de perseguirle por el escenario para devorarla.

Dependera de ti ayudarla a arrancar confundiendo a los habrientos conejos para que choquen entre ellos y asi poder ir avanzando niveles en esta "emocionante aventura…" (De emocionante no tiene mucho, pero suena bonito decirlo asi!…).

## Reglas del juego
1. Para comenzar debes elegir las dimensiones del tablero de juego y la cantidad de conejos iniciales en el tablero.
2. Puedes introducir las siguientes acciones validas:
	1. Para moverte por el tablero puedes usar el teclado numerico como las teclas aqui listadas:
		* __Arriba:__ U o 8
		* __Arriba Derecha:__ I o 9
		* __Derecha:__ K o 6
		* __Abajo Derecha:__ , o 3
		* __Abajo:__ M o 2
		* __Abajo Izquierda:__ N o 1
		* __Izquierda:__ H o 4
		* __Arriba Izquierda:__ Y o 7
		* __Centro:__ J o 5
	2. Para __Salir__ ingresa __"q"__
	3. Para __Teletransportarte__ presiona __"t"__
	4. Para __Guardar__ presiona __"s"__
3. Pasas de nivel una vez que haz hecho chocar a todos los conejos.
4. Para el siguiente nivel, se limpiara el escenario de los cadaveres que dejaron los conejos al chocar y se sumara un 25% a los conejos iniciales.
5. Cuando alcances el tercer nivel se agregaran 3 trampolines al azar en el escenario, cuando un conejo se pose en ellos puede avanzar de a dos casillas.
6. Por cada etapa que pases desde que entren en juego los trampolines apareceran un 20% mas que en el nivel anterior.
7. La tabla de puntajes es la siguiente:
	* __5 Puntos__ por movimiento exitoso
	* __50 Puntos__ por cada conejo que choque
	* __100 Puntos__ por pasar de nivel

## Compilacion
El programa fue principalmente programado y probado en MacOSX, a pesar de ello el codigo se penso para que funcionara ademas en plataformas Linux, Windows (Aqui es donde se pierden gran cantidad de caracteristicas esteticas), y Cygwin (Emulador de Bash en Windows).

### Sistemas Unix
Para sistemas unix (Linux, MacOSX, Cygwin y otros) al programa se adjunta un script de configracion __configure.sh__ que intentara determinar el sistema en el cual sera compilado el programa o de lo contrario le hara que elija las opciones disponibles. El archivo de configuracion generara un archivo Makefile que le permitira compilar el juego.

#### Paso 1 - Ejecutar el Script Configure

	./configure.sh

### Paso 2 - Ejecutar el Makefile

	make

### Paso 3 - Ejecutar el Juego

	./zanahoria

### Sistemas Windows

En sistemas windows no se cuenta con una consola bash y solo contamos con la consola de ms-dos por lo tanto no se puede utilizar ni el archivo de configuracion y tampoco el archivo Makefile. por lo tanto aqui la compilacion debe ser a mano.

Para llamar a __gcc__ y el programa funcione correctamente se debe llamar a gcc con las siguientes opciones:

	gcc -DWINDOWS -Iinclude main.c include/*.c -o zanahoria -lm

Esto generara un ejecutable __zanahoria.exe__ listo para poder disfrutar del juego.

#### Mejorar experiencia windows

El juego cuenta con algunas pantallas de colores que ayudan a resaltar distintos elementos del juego y ayudan a hacer mas rica la experiencia, el problema es que solo funciona en plataformas unix que cuentas con consolas que tienen soporte para comandos ANSI.

Pero existe una solucion para poder disfrutar de esta experiencia en un entorno windows, ya que por defecto vienen deshabilitados. La solucion se llama __ANSICON__ y es un programa que permite habilitar de manera facil los comandos ANSI en la consola de MS-DOS.

##### Instalacion ANSICON

Descargar desde la siguiente direccion:

	http://adoxa.110mb.com/ansicon/dl.php?f=ansicon

Ahora debes seguir los siguientes pasos:

1. Descomprime el archivo
2. Abre una consola de MS-DOS y dirigite a la carpeta que acabas de descomprimir
3. Ingresa a la carpeta __x86__ o __x64__ dependiendo de tu sistema
4. ejecuta el siguiente comando:

	ansicon -i

Esto habilitara a __ANSICON__ en el autorun de MS-DOS para habilitar los comandos ANSI cada vez que ejecutes la consola de forma normal.

##### Compilacion con soporte para ANSICON

Ahora que ya tienes instalado __ANSICON__ debes volver a compilar tu codigo en windows para habilitar la presentacion con comandos ANSI.

	gcc -DWINDOWS -DANSICON -Iinclude main.c include/*.c -o zanahoria -lm

Prueba! y Disfruta de la experiencia!

## Bibliografia
Aqui hay algunos libros que me ayudaron a entender todas las posibilidades que nos ofrece el lenguaje C.

+ El lenguaje de programacion C (Segunda Edicion) / __Brian W. Kernighan__ - __Dennis M. Ritchie__
+ Introduccion a la programacion en C / __Andres Marzal__ - __Isabel Gracia__

## Desarrollador

Jesus Urrutia

Twitter: [@jesusgoku](http://www.twitter.com/jesusgoku)
