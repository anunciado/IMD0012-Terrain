* O que foi feito : 


O programa foi criado com intuito de gerar cenários com montanhas para um jogo 2D, que através do algoritmo de deslocamento do ponto do meio ​(​midpoint displacement algorithm) é possível criar uma linha (1D) contendo as alturas de todos os pontos calculados de acordo com os dois pontos das extremidades definidos aleatoriamente, que é usada para criar uma malha (2D) contendo montanhas construídas aleatoriamente sob perspectiva de profundidade. Além disso, o programa é capaz, através do algoritmo já comentado, de criar até três cenários degradês, representando cada período do dia, com três montanhas em diferentes tonalidades com corpos celestes para incrementar o mesmo, sendo possível também que o usuário escolha via terminal algum período desejado.


* O que deixou de ser feito : 


Todas as funcionalidades requeridas na Etapa 2 deste projeto foram cumpridas.


* O que seria feito diferentemente :
        
        Poderiam ter sido adicionados mais elementos que proporcionasse uma melhor ambientação das imagens, como contorno de árvores, casas, etc. Além de também fazer montanhas em degradê, assim mostrando as diferentes altitudes em tonalidades diversas nas imagens.
        
* Arquivos incluídos no projeto : 
   * main.c
   * mapa.c
   * mapa.h
   * mountain.c
   * mountain.h


* Como compilar : 
1. Acessar a pasta do projeto via terminal;
2. Executar o seguinte comando via terminal : “gcc main.c mapa.c montain.c -o main”; 
3. Após isso será criado um executável do projeto, para executá-lo deve-se digitar o seguinte comando : “./main -d ‘Valor de deslocamento desejado’ -o ‘nome do arquivo de imagem escolhido ’ ”;
4. Durante a execução deve-se fornecer um número correspondente ao periodo do dia desejado;
* OBS: O número de período está restrito a três, sendo eles: Manhã (Digite 0 para gerar uma imagem nesse período), Tarde (Digite 1 para gerar uma imagem nesse período) e Noite (Digite 2 para gerar uma imagem nesse período). Em caso de não digitação do período requerido ou números diferentes dos postos aqui como padrão, será gerado uma imagem em período aleatório.
* OBS : Os parâmetros não são obrigatórios, caso na execução o projeto o usuário não forneça nenhum ou apenas um dos parâmetros o programa traz consigo valores padrões, sendo eles:
   * Valor de deslocamento: 256;
   * Nome da imagem : “montain.ppm”;


* Quem fez o que:
         
O discente Erick de Oliveira foi responsável pela função para cálculo e geração da linha de contorno em um arranjo, pela função criadora de montanha em uma imagem a partir do arranjo com a linha de contorno, criação da sub-rotina responsável pela construção do corpo do arquivo .ppm, pela função que pintar os segundos planos em degradê, e responsável pela correção de bugs pontuais. 
Já o discente Luís Eduardo foi responsável pela função de leitura dos parâmetros de configuração, fator de deslocamento, nome do arquivo de saída e período desejado, em linha de comando, pela modificação da função criadora de montanha, em prol de criar três montanhas, pela criação do corpos celestes nos cenários diversos e pela procura e escolha das colorações utilizadas em todos os cenários.
A modularização do programa, definição dos tipos de dados necessários em typedef, structs ou enums, e correções de bugs foram feitas em conjunto pelos discentes quando necessárias para alguma função.
