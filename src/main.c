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
#include <string.h>
#include <time.h>
#include "mapa.h"
#include "mountain.h"

int main (int argc, char** argv){

	/* Aqui estão postas as variáveis necessárias no programa, sendo elas: i,
	como uma variável auxiliar; variacao, variavel utilizada para variação da
	geraçao de pontos aleatorios no vetor, em prol de criar montanhas visivelmente
	maiores do que outras; ordem, usada para exprimir em qual montanha está sendo
	criada, onde dependendo da colocação, no caso a "ordem", ela irá receber uma
	coloração diferente; deslocamentoBase, para receber o parâmetro de
	deslocamento, fazendo com que haja ou não grande variação lateral das montanhas
	para ser posto depois na variável deslocamentoFinal que será repassado a
	função ("linhaContorno"); nomeArquivo, para guardar o nome do arquivo final a
	ser salvado em .ppm; mapa, para ser pintada toda a imagem; vet para calcular a
	linha do contorno; e sorteio, para receber o parâmetro do período desejado que
	irá na imagem. */

	int i, variacao, ordem, deslocamentoFinal;
	float deslocamentoBase = 256;
	char *nomeArquivo = "mountain.ppm";
	PIXEL mapa[513][513];
	PONTO vet[513];
	ALEATORIO sorteio=3;

	/* Aqui irá verificar a existência das entradas padrões explicitadas no
	README.TXT para modificação de parâmetros(deslocamento, nome do arquivo de
	saída e período do dia da imagem) desejados pelo usuário na resultado
	final do programa */
	for(i = 1; i < argc; i++){
		if(strcmp(argv[i], "-o") == 0 && argc > (i+1)){
				nomeArquivo = argv[++i];
		}
		if(strcmp(argv[i], "-d") == 0 && argc > (i+1)){
			deslocamentoBase = atoi(argv[++i]);
		}
	}

	//Caso seja digitado o comando -o e n~ao seja digitado nome, o nome do arquivo sera o padrao.
	if (strcmp(nomeArquivo, "-d") == 0){
		nomeArquivo = "mountain.ppm";
	}
	//Caso o deslocamento digitado seja maior que 256, o valor sera atribuido para o maximo que e´ 256.
	if (deslocamentoBase > 256) {
		deslocamentoBase = 256;
	}
	/* Se o parametro para deslocament recebido for menor que 1,
	entra no primeiro if, para transforma ele em um inteiro */

	if(deslocamentoBase < 1){
		deslocamentoFinal = deslocamentoBase*256 + 256;
	}
	/* Se o parametro recebido for maior que 256, some a 256 */
	else if(deslocamentoBase < 256){
		deslocamentoFinal = deslocamentoBase + 256;
	}
	/* Se o parametro não for recebido, que ele continue com seu valor padrão*/
	else if(deslocamentoBase == 256){
		deslocamentoFinal = deslocamentoBase;
	}
	/* Essa mudança no parâmetro deslocamentoBase para deslocamentoFinal, s dar
	pela necessidade de haver uma mudança significativa visual na função
	descolacamento se não haveria do usuário colocar um numero muito grande para
	ver um mudança. Logo após será sorteado o período do dia que sairá a imagem,
	se o usuário não tiver colocado o parâmetro ou tiver colocado um valor não
	tabelado no parâmetro*/
	printf("\n DIGITE UM NUMERO : \n - 0 para manha \n - 1 para tarde \n - 2 para noite\n");
	scanf("%i", &i);
	sorteio = i;
	srand ((unsigned)time(NULL)); // Para que os valores sejam aleatorios baseado no tempo da máquina
	if(sorteio < 0 || sorteio > 2){
		sorteio = rand()%3;
	}
	/* Função para pintar o segundo plano de acordo com período do dia posto */
	iniciaMapa(mapa, sorteio);

	/* Será gerado pontos aleatorios no vetor três vezes com variação no alcance
	dos números, com o aumento da ordem, que também determina qual montanha está
	sendo pintada, com isso, dependendo da ordem, a cor final da montanha será
	diferente*/

	srand ((unsigned)time(NULL));
	for(ordem = 0; ordem < 3; ordem++, variacao -=144){
		vet[0].linha =  (512 - variacao) * 0.5 - rand()%101;
		vet[0].coluna = 0;
		vet[512].linha = (512 - variacao) * 0.5 - rand()%101;
		vet[512].coluna = 512;

		/* Função para o cálculo dos pontos para preenchimento do vetor linha de contorno */
	  linhaContorno (mapa, vet[0], vet[512], vet, deslocamentoFinal);
		//pintura da linha de contorno na matriz mapa
		for (i=0; i<513; i++) {
			PONTO a = vet[i];
				mapa[a.linha][i].r = 0;
				mapa[a.linha][i].g = 0;
				mapa[a.linha][i].b = 0;
		}
		/* Função que "alarga" a linha de contorno para que fique mais visivel,  além de preencher o resto da montanha*/
		pintarMontanha(mapa, vet, sorteio, ordem);
	}
	/* Função para contruçao e impressao do mapa */
	construirTerreno(513, 513, 255, mapa, nomeArquivo);
}
