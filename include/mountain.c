/**
 * @file    main.c
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

/* Função para o cálculo dos pontos para preenchimento do vetor linha de contorno */
void linhaContorno(PIXEL mapa[513][513], PONTO inicial, PONTO final, PONTO vetorLinha[513], int deslocamentoFinal) {
	if (inicial.coluna < final.coluna && deslocamentoFinal != 0) {
		PONTO medio;
		medio.coluna = (inicial.coluna+final.coluna)/2;
		//Calcula a linha do ponto medio e atribui a um ponto
		medio.linha = (inicial.linha+final.linha)/2;
		int a = rand()%(deslocamentoFinal);
		medio.linha = medio.linha + (a-deslocamentoFinal/2);
		if (medio.linha > 512) {
			medio.linha = 512;
		}
		else if(medio.linha < 0) {
			medio.linha = 0;
		}
		// Chama recursivamente a função para calcular todos os pontos do arranjo do vetor
		vetorLinha[medio.coluna].linha = medio.linha;
		vetorLinha[medio.coluna].coluna = medio.coluna;
		if (medio.coluna != final.coluna && medio.coluna != inicial.coluna) {
			linhaContorno(mapa, inicial, medio, vetorLinha, deslocamentoFinal/2);
			linhaContorno(mapa, medio, final, vetorLinha, deslocamentoFinal/2);
		}
	}
}

/* Função que irá pintar atráves dos pontos obtidos pela função "linhaContorno"
um montanha, com coloração baseada no período posto, como também na ordem posta
na imagem, no caso se ela é a primeira, média ou última montanha, assim podendo
haver colorações diferentes que dará a idéia de profundidade na imagem */
void pintarMontanha(PIXEL mapa[513][513], PONTO vetorLinha[513], int sorteio, int ordem) {
	int i;
	for (i=0; i<513; i++){
		PONTO a = vetorLinha[i];
		for (a.linha; a.linha<513; a.linha++){
			if (sorteio == noiteTerra){
				if(ordem == 0){
					mapa[a.linha][i].r = 220;
					mapa[a.linha][i].g = 220;
					mapa[a.linha][i].b = 220;
					}
				else if(ordem == 1){
					mapa[a.linha][i].r = 190;
					mapa[a.linha][i].g = 190;
					mapa[a.linha][i].b = 190;
				}
				else if(ordem == 2){
					mapa[a.linha][i].r = 120;
					mapa[a.linha][i].g = 120;
					mapa[a.linha][i].b = 120;
				}
			}
			else if (sorteio == tardeTerra){
				if(ordem == 0){
					mapa[a.linha][i].r = 211;
					mapa[a.linha][i].g = 91;
					mapa[a.linha][i].b = 63;
				}
				else if(ordem == 1){
					mapa[a.linha][i].r = 211;
					mapa[a.linha][i].g = 50;
					mapa[a.linha][i].b = 16;
				}
				else if(ordem == 2){
					mapa[a.linha][i].r = 160;
					mapa[a.linha][i].g = 30;
					mapa[a.linha][i].b = 0;
				}
			}
			else if (sorteio == manhaTerra){
				if(ordem == 0){
					mapa[a.linha][i].r = 196;
					mapa[a.linha][i].g = 128;
					mapa[a.linha][i].b = 59;
				}
				else if(ordem == 1){
					mapa[a.linha][i].r = 142;
					mapa[a.linha][i].g = 93;
					mapa[a.linha][i].b = 43;
				}
				else if(ordem == 2){
					mapa[a.linha][i].r = 120;
					mapa[a.linha][i].g = 60;
					mapa[a.linha][i].b = 0;
				}
			}
		}
	}
}
