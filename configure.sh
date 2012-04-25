#!/bin/bash
echo Intentando determinar el Sistema Operativo
if [[ $(uname -a | grep -ic 'darwin' ) -gt 0 ]]; then
	echo Sistema Operativo: Mac
	OS='MAC'
elif [[ $(uname -a | grep -ic 'linux' ) -gt 0 ]]; then
	echo Sistema Operativo: Linux
	OS='LINUX'
elif [[ $(uname -a | grep -ic 'cygwin' ) -gt 0 ]]; then
	echo Sistema Operativo: Cygwin
	OS='CYGWIN'
else
	echo No fue posible establecer tu Sistema Operativo
	echo Por favor selecciona una opcion:
	OPCIONES='MAC LINUX CYGWIN WINDOWS'
	select opt in $OPCIONES
	do
		if [[ "$opt" = "MAC" ]]; then
			OS=$opt
			break
		elif [[ "$opt" = 'LINUX' ]]; then
			OS=$opt
			break
		elif [[ "$opt" = 'CYGWIN' ]]; then
			OS=$opt
			break
		elif [[ "$opt" = 'WINDOWS' ]]; then
			OS=$opt
			break
		else
			echo Opcion no valida
		fi
	done
fi
# Establesco el Sistema Operativo en el archivo Makefile
echo Creando el archivo Makefile
sed "s/SISTEMA_OPERATIVO/${OS}/g" Makefile.in > Makefile