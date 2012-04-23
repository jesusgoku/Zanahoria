#include <stdio.h>
#include <string.h>
#include <colores.h>

void printZanahoria(){
	fijarColorTextoEstilo(COLOR_VERDE, ESTILO_CLARO);
	clearScr();
	printf("                                                          Lliii                 \n");
	printf("  !!BIENVENIDO!!                                         F iIiii                \n");
	printf("                                                        I  Sv in                \n");
	printf("          AL                                           xiili iii                \n");
	printf("                                              iiii    isiiilIcivl               \n");
	printf("        JUEGO                              iiiiiiiiXLTDucMDUiiii                \n");
	printf("                                        ivOF        iigDQZLvii                  \n");
	printf("         DE LA                       ivciiiiui       ioO  iiioL                 \n");
	printf("                                   vISi      x   ii   bv                        \n");
	printf("       ZANAHORIA               iiiiiixi           Di  Xi                        \n");
	printf("                             iLi      i   i       lc  x             by          \n");
	printf("                           lLi     i      ic     iokii                          \n");
	printf("         cvii           iiLCz      iX     iH   iiii              JESUSGOKU      \n");
	printf("         iiTkMci   iivii        c   zi   ivncii                                 \n");
	printf("              iiiilsF    ii     Hi iSviiFUTii                                   \n");
	printf("              icsi  l     F   ilZiii vI icLzIUnTviiiiiiiiiii                    \n");
	printf("           ivii          iBiiiii ii iOi    iilCvlCv Lnciiiiiki                  \n");
	printf("        ilii   iXi  iiiiivinli  iB     vc    Ci      iiiiv  ivi                 \n");
	printf("      lsi   iiilHvi          iiiiGi    gI   MM   i     i    i oiiilcxiiiiiix    \n");
	printf("   vFboiiiiiiii                    iiivGF   i   Zi    oL   iiLggEMZOMFviiii     \n");
	printf("   ii                                   ivii   iM    iB    v QFiiiilSgGlviiiii  \n");
	printf("                                           iiiiiMv   iT   i skiiiiii  iLi iiii  \n");
	printf("                                                  iiiii ikiii     iiii iii      \n");
	printf(" presione cualquier tecla para comenzar...              ii            iiil      \n");
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
	printf("  __  ___  _   __  _   _   __   ___  _  ___     _  _ _  __   _   ___ ||\n");
	printf(" / _|| o \\/ \\ / _|| | / \\ / _| | o \\/ \\| o \\   | || | |/ _| / \\ | o \\L|\n");
	printf("( |_n|   / o ( (_ | || o |\\_ \\ |  _( o )   / n_| || U ( |_n| o ||   /  \n");
	printf(" \\__/|_|\\\\_n_|\\__||_||_n_||__/ |_|  \\_/|_|\\\\ \\__/ |___|\\__/|_n_||_|\\\\()\n");
	fijarColorNormal();
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
