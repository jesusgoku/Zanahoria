@echo off
rem Programa de Configuracion Zanahoria:run.bat
rem Establesco algunas variables
set FILE_TMP=%TMP%\borrar.txt
set PATH_DEVCPP=%SystemDrive%\Dev-Cpp\bin
set PATH_CODEBLOCKS=%ProgramFiles(x86)%\CodeBlocks\MinGW\bin
set DEVCPP_GCC=%PATH_DEVCPP%\gcc.exe
set CODEBLOCKS_GCC="%PATH_CODEBLOCKS%\gcc.exe"
rem Coloco titulo a la ventana
title Juego de la Zanahoria - Programa de Configuracion
:Menu
cls
echo *******************************
echo ** Programa de Configuracion **
echo **** Juego de la Zanahoria ****
echo *******************************
echo.
echo 1. Asistente de Compilacion
echo 2. Agregar gcc al PATH
echo 3. Habilitar ANSICON
echo 4. Compilar
echo 5. Ejecutar
echo S. Salir
echo.
choice /M "Escoje una opcion: " /C 12345s /N /T 15 /D s
if errorlevel 6 goto Salir 
if errorlevel 5 goto Ejecutar
if errorlevel 4 goto Compilar
if errorlevel 3 goto Ansicon
if errorlevel 2 goto AgregarPath
if errorlevel 1 goto Asistente
if errorlevel 0 goto Menu

:Asistente
	cls
	echo ******************************
	echo ** ASISTENTE DE COMPILACION **
	echo ******************************
	echo.
	gcc --version >%TMP%\%FILE_TMP% 2>NUL
	if errorlevel 0 if not errorlevel 1 goto AsistenteAnsicon
	if exist %DEVCPP_GCC% goto AsistenteDevCpp
	if exist %CODEBLOCKS_GCC% goto AsistenteCodeBlocks
	if not exist %DEVCPP_GCC% if not exist %CODEBLOCKS_GCC% goto AsistenteNoGCC
	:AsistenteDevCpp
		path %PATH%;%PATH_DEVCPP%
	:AsistenteCodeBlocks
		path %PATH%;%PATH_CODEBLOCKS%
	:AsistenteAnsicon
		cls
		echo ANSICON, es una utilidad que le permitira habilitar comandos ANSI
		echo que le permitira disfrutar mas de la experiencia del juego
		echo permitiendole ejecutar a todo color.
		echo.
		echo Para poder habilitarlo debe descargarlo de la siguiente direccion:
		echo http://adoxa.110mb.com/ansicon/dl.php?f=ansicon
		echo Y descomprimirlo en la carpeta del juego.
		echo.
		echo 1. Habilitar ANSICON 32 bits
		echo 2. Habilitar ANSICON 64 bits
		echo 3. No Habilitar ANSICON
		echo.
		echo NOTA: Si tienes mas de 4GB de memeria ram escoje 64 bits.
		echo.
		choice /M "Escoja una opcion: " /C 123 /N /T 15 /D 3
		if errorlevel 3 goto AsistenteCompilar
		if errorlevel 2 goto AsistenteAnsicon64
		if errorlevel 1 goto AsistenteAnsicon32
	:AsistenteCompilar
		echo.
		echo Compilando...
		gcc -DWINDOWS -Iinclude main.c include/*.c -o zanahoria -lm
		goto AsistenteFin
	:AsistenteCompilarAnsicon
		echo.
		echo Compilando...
		gcc -DWINDOWS -DANSICON -Iinclude main.c include/*.c -o zanahoria -lm
		goto AsistenteFin
	:AsistenteAnsicon32
		ansi151\x86\ansicon.exe -i
		goto AsistenteCompilarAnsicon
	:AsistenteAnsicon64
		ansi151\x64\ansicon.exe -i
		goto AsistenteCompilarAnsicon
	:AsistenteNoGCC
		echo No se detecto ninguna instalacion de gcc
		pause
		goto Menu
	:AsistenteFin
		zanahoria.exe
		goto SalirSolo
	goto Menu
:AgregarPath
	cls
	echo *********************
	echo ** Configurar Path **
	echo *********************
	echo.
	echo 1. Dev-Cpp
	echo 2. CodeBlocks
	echo 3. Otro
	echo C. Cancelar
	echo.
	choice /M "Escoja una opcion: " /C 123c /N /T 15 /D c
	if errorlevel 4 goto Menu
	if errorlevel 3 goto AgregarPathOtro
	if errorlevel 2 goto AgregarPathCodeBlocks
	if errorlevel 1 goto AgregarPathDevCpp
	if errorlevel 0 goto Menu
	:AgregarPathDevCpp
		cls
		path %PATH%;%PATH_DEVCPP%
		echo Path de Dev-Cpp agregado
		echo.
		pause
		goto Menu
	:AgregarPathCodeBlocks
		cls
		path %PATH%;%PATH_CODEBLOCKS%
		echo Path de CodeBlocks agregado
		echo.
		pause
		goto Menu
	:AgregarPathOtro
		cls
		echo Ingresa tu path: 
		set /P PATH_OTRO_GCC=
		if exist "%PATH_OTRO_GCC%\gcc.exe" goto AgregarPathOtroAgregar
		if not exist "%PATH_OTRO_GCC%\gcc.exe" goto AgregarPathOtroError
		goto Menu
		:AgregarPathOtroAgregar
			cls
			path %PATH%;%PATH_OTRO_GCC%
			echo Path agregado correctamente
			echo.
			pause
			goto Menu
		:AgregarPathOtroError
			cls
			echo Path ingresado no valido
			echo.
			pause
			goto Menu
:Compilar
	cls
	echo *****************
	echo ** Compilacion **
	echo *****************
	echo.
	echo 1. Version Normal (Sin Colores)
	echo 2. Con soporte para ANSICON (Colores en el juego)
	echo C. Cancelar
	echo.
	choice /M "Escoje una opcion: " /C 12c /N /T 15 /D c
	if errorlevel 3 goto Menu
	if errorlevel 2 goto CompilarAnsicon
	if errorlevel 1 goto CompilarNormal
	if errorlevel 0 goto Menu
:CompilarNormal
	echo.
	echo Compilando...
	gcc -DWINDOWS -Iinclude main.c include/*.c -o zanahoria -lm
	echo.
	echo Compilado con exito!
	pause
	goto Menu
:CompilarAnsicon
	echo Compilando...
	echo.
	gcc -DWINDOWS -DANSICON -Iinclude main.c include/*.c -o zanahoria -lm
	echo.
	echo Ya esta compilado!
	pause
	goto Menu
:Ansicon
	cls
	echo **********************
	echo ** Habilitar ANSICON **
	echo **********************
	echo.
	echo ANSICON, es una utilidad que le permitira habilitar comandos ANSI
	echo que le permitira disfrutar mas de la experiencia del juego
	echo permitiendole ejecutar a todo color.
	echo.
	echo Para poder habilitarlo debe descargarlo de la siguiente direccion:
	echo http://adoxa.110mb.com/ansicon/dl.php?f=ansicon
	echo Y descomprimirlo en la carpeta del juego.
	echo.
	echo 1. Windows 32 bits
	echo 2. Windows 64 bits
	echo c. Cancelar
	echo.
	echo NOTA: Si su sistema tiene mas de 4GB de memoria ram debe escojer Windows 64 bits
	echo.
	choice /M "Escoje una opcion: " /C 12c /N /T 15 /D c
	if errorlevel 3 goto Menu
	if errorlevel 2 goto Ansicon64
	if errorlevel 1 goto Ansicon32
	if errorlevel 0 goto Menu
:Ansicon32
	ansi151\x86\ansicon.exe -i >%TMP%\%FILE_TMP% 2>NUL
	if errorlevel 1 echo No se logro instalar ANSICON
	if errorlevel 0 echo ANSICON Instalado Correctamente
	pause
	goto Menu
:Ansicon64
	ansi151\x86\ansicon.exe -i >%TMP%\%FILE_TMP% 2>NUL
	if errorlevel 1 echo No se logro instalar ANSICON
	if errorlevel 0 echo ANSICON Instalado Correctamente
	pause
	goto Menu
:Ejecutar
	if exist zanahoria.exe zanahoria.exe
	if not exist zanahoria.exe echo EjecutarCompilar
	goto SalirSolo
:EjecutarCompilar
	echo.
	echo No has compilado aun!
	pause
	goto Menu
:Salir
	cls
	echo.
	echo *******************************
	echo **           Adios!          **
	echo **      ------ O -------     **
	echo ** Created by JesusGoku Inc. **
	echo *******************************
	echo.
:SalirSolo
