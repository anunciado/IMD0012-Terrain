/**
 * @file    mapa.c
 * @brief   ...
 * @author  Erik de Oliveira Silva e Luís Eduardo Anunciado Silva.
 * @since   --/--/2016
 * @date    --/--/2016
 */

/* Aqui encontram-se as bibliotecas necessárias para o funcionamento do programa */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mapa.h"
#include "mountain.h"

void iniciaMapa(PIXEL mapa[513][513], int sorteio) {
	int a = 0, i, j;
	if (sorteio == noiteTerra) {
/* Inicia a matriz inteira com o degrade sorteado aleatoriamente a cada execuçao
equivalente à noite */
		for (i=0; i<513; i++) {
			for (j=0; j<513; j++) {
				if(0 <= i < 171){
					mapa[i][j].r = 0;
					mapa[i][j].g = 0;
					mapa[i][j].b = 1.5 * i;
				} else if(171 <= i < 342){
					mapa[i][j].r = 0;
					mapa[i][j].g = 1.5 * (i%171);
					mapa[i][j].b =  255;
				} else if(342 <= i < 513){
					mapa[i][j].r = 1.5 * (i%342);
					mapa[i][j].g = 255;
					mapa[i][j].b =  255;
				}
			}
		}
		// Processo utilizada para pintar a Lua
		int med = 25;
		int raio = 50;
		for(i = 0; i < 513; i++){
			for(j = 0; j < 513; j++){
				if((i-med)*(i-med)+(j-med)*(j-med) <= raio*raio){
					mapa[i][j].r = 235;
					mapa[i][j].g = 235;
					mapa[i][j].b = 250;
				}
			}
		}
		// Processo utilizada para pintar as estrelas
		int x, y;
		for(i = 0; i < 20; i++){
			x = rand()%513;
			y = rand()%513;
			mapa[x][y].r = 255;
			mapa[x][y].g = 255;
			mapa[x][y].b = 255;
			mapa[x-1][y].r = 255;
			mapa[x-1][y].g = 255;
			mapa[x-1][y].b = 255;
			mapa[x+1][y].r = 255;
			mapa[x+1][y].g = 255;
			mapa[x+1][y].b = 255;
			mapa[x][y-1].r = 255;
			mapa[x][y-1].g = 255;
			mapa[x][y-1].b = 255;
			mapa[x][y+1].r = 255;
			mapa[x][y+1].g = 255;
			mapa[x][y+1].b = 255;
		}
	}
 	else if (sorteio == tardeTerra)  {
		/* Inicia a matriz inteira com o degrade sorteado aleatoriamente a cada execuçao
		equivalente à tarde */
		for (i=0; i<513; i++) {
			for (j=0; j<513; j++) {
				if(0 <= i < 256){
					if (i%2==0) {
						a = i/2;
					} else {
						a = (i-1)/2;
					}
					mapa[i][j].r = 255;
					mapa[i][j].g = a;
					mapa[i][j].b = 0;
				} else if(256 <= i < 512){
					if (i%2==0) {
						a = i/2;
					} else {
						a = (i-1)/2;
					}
					mapa[i][j].r = 255;
					mapa[i][j].g = a;
					mapa[i][j].b = 0;
				}
			}
		}
		// Processo utilizada para pintar a Sol
		int med = 10;
		int raio = 50;
		for(i = 0; i < 513; i++){
			for(j = 0; j < 513; j++){
				if((i-med)*(i-med)+(j-med)*(j-med) <= raio*raio){
					mapa[i][j].r = 255;
					mapa[i][j].g = 210;
					mapa[i][j].b = 30;
				}
			}
		}
	} else if (sorteio == manhaTerra) {
		/* Inicia a matriz inteira com o degrade sorteado aleatoriamente a cada execuçao
		equivalente à manhã */
		for (i=0; i<513; i++) {
			for (j=0; j<513; j++) {
				if(i < 256){
					if (i%2==0) {
						a = i/2;
					} else {
						a = (i-1)/2;
					}
					mapa[i][j].r = 0;
					mapa[i][j].g = a;
					mapa[i][j].b = 255;
				}
				else if(256 <= i < 511){
					if (i%2==0) {
						a = i/2;
					} else {
						a = (i-1)/2;
					}
					mapa[i][j].r = 0;
					mapa[i][j].g = a;
					mapa[i][j].b = 255;
				}
			}
		}
		// Processo utilizada para pintar a Sol
		int med = 25;
		int raio = 50;
		for(i = 0; i < 513; i++){
			for(j = 0; j < 513; j++){
				if((i-med)*(i-med)+(j-med)*(j-med) <= raio*raio){
					mapa[i][j].r = 240;
					mapa[i][j].g = 255;
					mapa[i][j].b = 170;
				}
			}
		}
	}
}

/*Função responsável por construir e salva a imagem final em .ppm*/
void construirTerreno(int linha, int coluna, int max, PIXEL mapa[linha][coluna], char *nomeArquivo) {
    int i, j;
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "w");
		// Criar o arquivo com o nome padrão ou colocado no parâmetro e depois pinta ele
    fprintf (arquivo, "P3\n");
    fprintf (arquivo, "%d\n ", coluna);
    fprintf (arquivo, "%d\n", linha);
    fprintf (arquivo, "%d\n", max);

    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            fprintf(arquivo, "%d ", mapa[i][j].r);
            fprintf(arquivo, "%d ", mapa[i][j].g);
            fprintf(arquivo, "%d\n", mapa[i][j].b);
        }
    }

    fclose(arquivo);
}
