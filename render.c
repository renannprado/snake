#include <stdio.h>

#include "render.h"

// Desnha a cobra e a comida no buffer
void desenhaTela ( BITMAP *buffer, comida com, snake cobra )
{
    int cont;
    TipoCauda *temp;
 	// vamos imprimir os bitmaps cobra e comida no buffer
 	// vamos pegar da posicao 0,0 desses dois bitmaps
 	// e colocar na posicao x*TILE_X,y*TILE_Y, com tamanhos definidos

 	// sempre blit ou masked blit eh:
	// do bitmap origem, para o destino, posicao de origem para posicao de destino
  	// e o tamanho a ser desenhado
 	masked_blit(cobra.bmp, buffer, 0,0,cobra.x*TILE_X,cobra.y*TILE_Y, cobra.tamanho, cobra.tamanho);
    masked_blit(com.bmp, buffer, 0,0,com.x*TILE_X,com.y*TILE_Y, TILE_X, TILE_Y);


    cont = 0;
    temp = cobra.cauda;
    while (temp != NULL)
    {
        cont++;
        masked_blit(temp->bmp, buffer, 0,0,temp->x*TILE_X,temp->y*TILE_Y, TILE_X, TILE_Y);
        temp = temp->proxima;
    }
    printf("executou %d loops\n", cont);
//        printf("Dados da cauda: \n");
//        printf("cauda->x: %d| * 32 = %d\n", cobra.cauda->x, cobra.cauda->x * TILE_X);
//        printf("cauda->y: %d| * 32 = %d\n", cobra.cauda->y, cobra.cauda->y * TILE_Y);
        //system("pause");
        //system("cls");

     // Prototipos
    // void masked_blit(BITMAP *source, BITMAP *dest, int source_x, int source_y, int dest_x, int dest_y, int width, int height);
    // void blit	    (BITMAP *source, BITMAP *dest, int source_x, int source_y, int dest_x, int dest_y, int width, int height);

    // a diferenca entre as duas funcoes eh o padrao masked
    // esse padrao faz com que os pixels do BITMAP * source que sao da cor makecol(255,0,255)
    // nao sejam imprimidos, ou seja, uma "mascara"
    // porem a funcao masked_blit eh mais rapida, portanto
    // sempre usaremos ela
}

// Duplo buffer
void bufferDuplo ( BITMAP * buffer )
{
 	 // sincronizar
 	 // como em jogos 3D modernos
 	 vsync();

   	 // imprime o buffer na tela  (use sempre masked_blit - eh mais rapido)
			  // do buffer-> para as creen
			  //  pega da posicao 0,0 do buffer e poe na
			  // 0,0 da screen, de tamanho RES_W e RES_H
  	 masked_blit(buffer, screen, 0,0,0,0, RES_W, RES_H);

  	 // o BITMAP * buffer eh como se fosse uma caixa, quando um frame comeca
  	 // ( um novo loop do while(!key[KEY_ESC])  nos jogamos tudo fora
  	 // e comecamos a colocar coisas novas
  	 // depois nos jogamos o conteudo desta caixa na tela
  	 // quando estiver tudo pronto
     rest(180);
}
