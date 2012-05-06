#include <stdio.h>
#include <string.h>
#include <colores.h>

void printZanahoria(){
	fijarColorTextoEstilo(COLOR_VERDE, ESTILO_CLARO);
	clearScr();
	printf("                                                         %sF iIiii%s                \n", COLOR_VERDE_CLARO_S, ESTILO_NORMAL_S);
	printf("                  %s/\\/\\      / \\/\\                   %sI  Sv in%s                \n", COLOR_GRIS_CLARO_S, COLOR_VERDE_CLARO_S, ESTILO_NORMAL_S);
	printf("                    %s\\ \\    / /                       %sxiili iii%s                \n", COLOR_GRIS_CLARO_S, COLOR_VERDE_CLARO_S, ESTILO_NORMAL_S);
	printf("  %s¡¡BIENVENIDO!!     %s\\ \\_/ /              %siiii    %sisiiilIcivl%s               \n", COLOR_MARRON_CLARO_S, COLOR_GRIS_CLARO_S, COLOR_ROJO_CLARO_S, COLOR_VERDE_CLARO_S, ESTILO_NORMAL_S);
	printf("      %sAL JUEGO       %s( o o )             %siiiiiiiiX%sLTDucMDUiiii%s                \n", COLOR_MARRON_CLARO_S, COLOR_GRIS_CLARO_S, COLOR_ROJO_CLARO_S, COLOR_VERDE_CLARO_S, ESTILO_NORMAL_S);
	printf("         %sDE LA   %s--ooO--uu-Ooo--      %sivOF        iig%sDQZLvii%s                  \n", COLOR_MARRON_CLARO_S, COLOR_GRIS_CLARO_S, COLOR_ROJO_CLARO_S, COLOR_VERDE_CLARO_S, ESTILO_NORMAL_S);
	printf("       %sZANAHORIA                   %sivciiiiui       ioO%s  iiioL%s                 \n", COLOR_MARRON_CLARO_S, COLOR_ROJO_CLARO_S, COLOR_VERDE_CLARO_S, ESTILO_NORMAL_S);
	printf("                                   %svISi      x   ii   bv%s                        \n", COLOR_ROJO_CLARO_S, ESTILO_NORMAL_S);
	printf("                               %siiiiiixi           Di  Xi%s                        \n", COLOR_ROJO_CLARO_S, ESTILO_NORMAL_S);
	printf("                             %siLi      i   i       lc  x             %sby%s          \n", COLOR_ROJO_CLARO_S, COLOR_PURPURA_CLARO_S, ESTILO_NORMAL_S);
	printf("                           %slLi     i      ic     iokii%s                          \n", COLOR_ROJO_CLARO_S, ESTILO_NORMAL_S);
	printf("         %scvii           iiLCz      iX     iH   iiii              %sJESUSGOKU%s      \n", COLOR_ROJO_CLARO_S, COLOR_PURPURA_CLARO_S, ESTILO_NORMAL_S);
	printf("         %siiTkMci   iivii        c   zi   ivncii%s                                 \n", COLOR_ROJO_CLARO_S, ESTILO_NORMAL_S);
	printf("              %siiiilsF    ii     Hi iSviiFUTii%s                                   \n", COLOR_ROJO_CLARO_S, ESTILO_NORMAL_S);
	printf("              %sicsi  l     F   ilZiii vI icLzIUnTviiiiiiiiiii%s                    \n", COLOR_ROJO_CLARO_S, ESTILO_NORMAL_S);
	printf("           %sivii          iBiiiii ii iOi    iilCvlCv Lnciiiiiki%s                  \n", COLOR_ROJO_CLARO_S, ESTILO_NORMAL_S);
	printf("        %silii   iXi  iiiiivinli  iB     vc    Ci      iiiiv  ivi%s                 \n", COLOR_ROJO_CLARO_S, ESTILO_NORMAL_S);
	printf("      %slsi   iiilHvi          iiiiGi    gI   MM   i     i    i o%siiilcxiiiiiix%s    \n", COLOR_ROJO_CLARO_S, COLOR_VERDE_CLARO_S, ESTILO_NORMAL_S);
	printf("   %svFboiiiiiiii                    iiivGF   i   Zi    oL   iiLg%sgEMZOMFviiii%s     \n", COLOR_ROJO_CLARO_S, COLOR_VERDE_CLARO_S, ESTILO_NORMAL_S);
	printf("   %sii                                   ivii   iM    iB    v QF%siiiilSgGlviiiii%s  \n", COLOR_ROJO_CLARO_S, COLOR_VERDE_CLARO_S, ESTILO_NORMAL_S);
	printf("                                           %siiiiiMv   iT   i ski%siiiii  iLi iiii%s  \n", COLOR_ROJO_CLARO_S, COLOR_VERDE_CLARO_S, ESTILO_NORMAL_S);
	printf("                                                  %siiiii ikiii     %siiii iii%s      \n", COLOR_ROJO_CLARO_S, COLOR_VERDE_CLARO_S, ESTILO_NORMAL_S);
	printf(" presione cualquier tecla para comenzar...              %sii            %siiil%s      \n", COLOR_ROJO_CLARO_S, COLOR_VERDE_CLARO_S, ESTILO_NORMAL_S);
	fijarColorNormal();
}

void printConejoZanahoria(){
	printf("       ii                           \n");
	printf("       i ic       ii i              \n");
	printf("      ii v c    ii   i     GAME     \n");
	printf("      C  i i  vi   iiv        OVER! \n");
	printf("     iv ii iii   i  vi              \n");
	printf("     ii i  il  ii ivi               \n");
	printf("     ii i iii ii ii                 \n");
	printf("      u  i iiviii                   \n");
	printf("       v     i  ilv                 \n");
	printf("        i i     i in                \n");
	printf("        ii  i       ii      ii   ii \n");
	printf("       ii    i  vQT iiiii  i      i \n");
	printf("       ii   QB   BS     ii    li i  \n");
	printf("       ui i BQ  i       i   HQi   i \n");
	printf("      c        cCi  iiiii nBv   ii  \n");
	printf("      L          viiii   io    i    \n");
	printf("       ii    i  i    iMi   i ii     \n");
	printf("           lM   c i    Sc i         \n");
	printf("       i  ii sii  iO   ii           \n");
	printf("     ii i  Lsii     l  z  ii        \n");
	printf("    ii   i ii  F    ii c   v        \n");
	printf("    ii i i i    LvXci    i ii       \n");
	printf("     iii i vviiiiiiii i  iii        \n");
}

void printConejoGameOver(){
	fijarColorTextoEstilo(COLOR_PURPURA, ESTILO_CLARO);
	clearScr();
	printf("__**_**                       _______      ___      .___  ___.  _______ \n");
	printf("_**___**                     /  _____|    /   \\     |   \\/   | |   ____|\n");
	printf("_**___**_________****       |  |  __     /  ^  \\    |  \\  /  | |  |__   \n");
	printf("_**___**_______**___****    |  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|  \n");
	printf("_**__**_______*___**___**   |  |__| |  /  _____  \\  |  |  |  | |  |____ \n");
	printf("__**__*______*__**__***__**  \\______| /__/     \\__\\ |__|  |__| |_______|\n");
	printf("___**__*____*__**_____**__* \n");
	printf("____**_**__**_**________**    ______   ____    ____  _______ .______       __ \n");
	printf("____**___**__**              /  __  \\  \\   \\  /   / |   ____||   _  \\     |  | \n");
	printf("___*___________*            |  |  |  |  \\   \\/   /  |  |__   |  |_)  |    |  | \n");
	printf("__*_____________*           |  |  |  |   \\      /   |   __|  |      /     |  | \n");
	printf("_*____0_____0____*          |  `--'  |    \\    /    |  |____ |  |\\  \\----.|__| \n");
	printf("_*_______@_______*           \\______/      \\__/     |_______|| _| `._____|(__) \n");
	printf("_*_______________* \n");
	printf("___*_____U_____* \n");
	printf("_____**_____**\n");
	fijarColorNormal();
}

void printGraciasPorJugar(){
	fijarColorTextoEstilo(COLOR_ROJO, ESTILO_CLARO);
	clearScr();
	printf("  __  ___  _   __  _   _   __   ___  _  ___     _  _ _  __   _   ___ ||\n");
	printf(" / _|| o \\/ \\ / _|| | / \\ / _| | o \\/ \\| o \\   | || | |/ _| / \\ | o \\L|\n");
	printf("( |_n|   / o ( (_ | || o |\\_ \\ |  _( o )   / n_| || U ( |_n| o ||   /  \n");
	printf(" \\__/|_|\\\\_n_|\\__||_||_n_||__/ |_|  \\_/|_|\\\\ \\__/ |___|\\__/|_n_||_|\\\\()\n");
	fijarColorNormal();
}

void printJuegoDeLaZanahoriaLetras(){
    fijarColorTextoEstilo(COLOR_ROJO, ESTILO_CLARO);
	clearScr();
	printf(",---.o                          o    |              |    \n");
	printf("|---..,---.,---..    ,,---.,---..,---|,---.    ,---.|    \n");
	printf("|   |||---'|   | \\  / |---'|   |||   ||   |    ,---||    \n");
	printf("`---'``---'`   '  `'  `---'`   '``---'`---'    `---^`---'\n");
	printf("    |                            |         |         \n");
	printf("    |.   .,---.,---.,---.    ,---|,---.    |    ,---.\n");
	printf("    ||   ||---'|   ||   |    |   ||---'    |    ,---|\n");
	printf("`---'`---'`---'`---|`---'    `---'`---'    `---'`---^\n");
	printf("               `---'                                 \n");
	printf(",---,               |              o     \n");
	printf(" .-' ,---.,---.,---.|---.,---.,---..,---.\n");
	printf("|    ,---||   |,---||   ||   ||    |,---|\n");
	printf("`---'`---^`   '`---^`   '`---'`    ``---^\n");
	fijarColorTexto(COLOR_PURPURA);
	printf("\n  --:: Creado por JesusGoku ::--\n");
	fijarColorNormal();
	printf("\npresione enter para comenzar...");
}

void printLuminoso(char *cadena){
	int i = 0;
	int len = strlen(cadena);
	// Primera Linea
	printf(" ");
	for(i = 0;i < len; i++) printf(" _  ");
	// Segunda Linea
	printf("\n");
	for(i = 0;i < len; i++) printf(" / \\");
	// Texto
	printf("\n");
	for(i = 0;i < len; i++){
		if( i == 0 ) printf("( ");
		else printf("| ");
		fijarColorTextoEstilo(COLOR_ROJO, ESTILO_PARPADEANTE);
		printf("%c ", cadena[i]);
		fijarColorNormal();
		if( i == len - 1) printf(")");
	}
	// Penultima Linea
	printf("\n");
	for(i = 0;i < len; i++) printf(" \\_/");
	printf("\n");
}

void printMasMenos(char *cadena){
	int i = 0;
	int len = strlen(cadena);
	// Primera Linea
	printf("+");
	for(i = 0; i < len; i++) printf("-+");
	// Linea Central
	printf("\n|");
	for(i = 0; i < len; i++) printf("-+");
	// Ultima Linea
	printf("\n+");
	for(i = 0; i < len; i++) printf("-+");
}

void printMsjError(const char *msj){
	fijarColorTexto(COLOR_ROJO);
	println("%s", msj);
	fijarColorNormal();
}

void printMsjErrorPausa(const char *msj){
	fijarColorTexto(COLOR_ROJO);
	pausaMensaje(msj);
	fijarColorNormal();
}

void printMsjOk(const char * msj){
	fijarColorTexto(COLOR_VERDE);
	println("%s", msj);
	fijarColorNormal();
}

void printMsjOkPausa(const char *msj){
	fijarColorTexto(COLOR_VERDE);
	pausaMensaje(msj);
	fijarColorNormal();
}

void printMsjInfo(const char *msj){
	fijarColorTexto(COLOR_MARRON);
	println("%s", msj);
	fijarColorNormal();	
}

void printMsjInfoPausa(const char *msj){
	fijarColorTexto(COLOR_MARRON);
	pausaMensaje(msj);
	fijarColorNormal();
}
