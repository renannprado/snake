#include <stdio.h>

#include "game.h"

// Inicia os dados do jogador
void iniciaJogador ( snake * cobra )
{
 	 cobra->x = 0;
     cobra->y = 0;
     cobra->tamanho = 32;
     cobra->pontos = 0;
     cobra->cauda = NULL;
     cobra->ultima = NULL;

     // Aqui iniciamos os dados da cobra
     // Passamos como parametro um ponteiro para uma
     // estrutura snake de nome cobra

     // E deve ser chamada apenas quando o jogo for comecar
     // ou der game-over, o que significa que comecara do 0
     // novamente
}

// Marca Ponto
void marcaPonto ( snake *cobra , comida *com)
{
 	 // Se a posicao da cobra na matriz de tiles
 	 // for igual a da comida, isso significa que
 	 // a cobra esta em cima da comida, portanto, o
 	 // jogador marcou um ponto!
 	 if (cobra->x == com->x && cobra->y == com->y )
	 {
        cobra->pontos++;

        // Ja que o usuario "comeu" a comida que havia
        // na tela, vamos criar outra novamente, em outro
        // lugar da tela
        criaComida ( com );

        //Criando a cauda
        criaCauda(cobra);
//        else if (cobra->pontos > 1)
//            criaCauda(cobra->ultima->proxima, cobra);
    }

}

// Cria a comida
void criaComida ( comida * com )
{
 	// Isso gera a posicao da comida na tela normalmente
    com->x = rand() % RES_W;
    com->y = rand() % RES_H;

	// Retirando um bug
	if (com->x >= ( RES_W - TILE_Y ) )
 	    com->x -= TILE_Y;

    if (com->y >= ( RES_H - TILE_X ) )
 	    com->y -= TILE_X;

	// O Bug citado acima eh como se a comida ficasse para fora
	// da tela ou entao parcialmente fora, o que faria que quando
	// a cobra passar por cima, nao ira "comer", entao a gente coloca
	// a comida mais para "dentro" da tela,
	// tente ver como uma colisao qualquer


	// Transformando as posicoes
	// ---------------------------------------------------------------------- //
    com->x /= TILE_X;
    com->y /= TILE_Y;
    //
    // Essa transformacao nada mais nada menoas eh do que
    // pegar as posicoes em pixels do ponto gerado randomicamente
    // P = (com->x,com->y) e dividir as coordenadas pelo tamanho dos
    // TILES, que foram definidos por macros
    // ---------------------------------------------------------------------- //
}

//Criando outra cauda
void criaCauda (snake *cobra)
{
    TipoCauda *cauda;
    cauda = (TipoCauda*) malloc(sizeof(TipoCauda));

    if (cobra->pontos == 1)
    {
        cauda->x = cobra->x;
        cauda->y = cobra->y;
        cauda->direcao = cobra->direcao;
    }
    else
    {
        cauda->x = cobra->x;
        cauda->y = cobra->y;
//        cauda->y = cobra->ultima->y;
//        cauda->x = cobra->ultima->x;
        cauda->direcao = cobra->ultima->direcao;
    }
    cauda->bmp = create_bitmap(cobra->tamanho, cobra->tamanho);
    rectfill(cauda->bmp, 0, 0, cobra->tamanho, cobra->tamanho, makecol(100, 100, 100));
    cauda->proxima = NULL;
    if (cobra->pontos == 1)
    {
        cobra->cauda = cauda;
        cobra->ultima = cauda;
    }
    else
    {
        cobra->ultima->proxima = cauda;
        cobra->ultima = cauda;
    }
}

// Iniciacao do allegro
void inicia ( void )
{
 	allegro_init();
    set_color_depth(16);
    install_keyboard();
    set_gfx_mode(GFX_DIRECTX_WIN, RES_W, RES_H, 0, 0);
    srand(time(0));

    // O proposito desta funcao eh iniciar a allegro
    // com as partes que iremos utilizar no jogo
    // podemos considerar com inline, pois ela serve
    // apenas para nao deixar esses callbacks na main
    // fazendo com que o codigo fique desorganizado
}
