/**
 * @file    main.c
 * @brief   ...
 * @author  Erik de Oliveira Silva e Luís Eduardo Anunciado Silva.
 * @since   --/--/2016
 * @date    --/--/2016
 */
 
#ifndef MAPA_H
#define MAPA_H

/* Aqui se encontra uma estrutura responsável por guardar na variável PIXEL,
as três variáveis inteiras responsáveis pelas cores no sistema RGB,
podendo assim criar imagens coloridas atráves de pontos em uma matriz*/

typedef struct{

	int r, g, b;

}PIXEL;

/* Aqui se encontra uma estrutura responsável por guardar na variável PONTO,
duas variáveis inteiras responsáveis por guardar numa variável em formato
de arranjo, seus pontos em variável em formato de matriz, sendo tal estrutura
necessária na função "linhaContorno" para preencher uma matriz atráves de uma
arranjo */

typedef struct{

	int linha, coluna;

}PONTO;

/* Aqui se encontra o enum responsável pela entrada do parâmetro de período do
dia na imagem, fazendo assim com que seja possível escolher como a imagem será
pintada na função "pintarMontanha"*/

typedef enum{
	manhaTerra=0,
	tardeTerra,
	noiteTerra
}ALEATORIO;

/* Aqui se encontram as chamadas das função responsável ("iniciaMapa") pela pintura
do segundo plano de acordo com a variável do enum ALEATORIO, além da função
responsável ("construirTerreno") que constroi e salva a imagem final em .ppm*/

void iniciaMapa(PIXEL mapa[513][513], int sorteio);
void construirTerreno(int linha, int coluna, int max, PIXEL mapa[linha][coluna], char *nomeArquivo);

#endif
