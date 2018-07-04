/**
 * @file    main.c
 * @brief   ...
 * @author  Erik de Oliveira Silva e Luís Eduardo Anunciado Silva.
 * @since   --/--/2016
 * @date    --/--/2016
 */
 
/* Aqui encontram-se as bibliotecas necessárias para o funcionamento do programa */

#include "mapa.h"

#ifndef MONTANHA_H
#define MONTANHA_H

/* Aqui se encontram as chamadas das funções responsáveis pela pintura das
montanhas contidas nas imagens ("pintarMontanha") e pelo cálculo dos pontos
para preenchimento do vetor linha de contorno ("linhaContorno")*/

void linhaContorno(PIXEL mapa[513][513], PONTO inicial, PONTO final, PONTO vetorLinha[513], int deslocamentoFinal);
void pintarMontanha(PIXEL mapa[513][513], PONTO vetorLinha[513], int sorteio, int ordem);

#endif
