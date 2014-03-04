#include <stdio.h>

#include "movimento.h"

// Auxiliar do movimento
void zeraDir ( direc *direcao )
{
 	 direcao->up = false;
     direcao->down = false;
     direcao->left = false;
   	 direcao->right = false;
}

// Movimento
void movimento (snake *cobra, direc *direcao)
{
 	// Teclas
 	// Isso define a direcao para que
 	// o jogador deseja ir
    if (key[KEY_UP] && !direcao->down)
    {
//        movimentaCauda(cobra, cobra->cauda, cobra->cauda);
        zeraDir( direcao );
		direcao->up = true;
    }
    else if (key[KEY_DOWN] && !direcao->up)
    {
//        movimentaCauda(cobra, cobra->cauda, cobra->cauda);
        zeraDir( direcao );
		direcao->down = true;
    }
    else if (key[KEY_LEFT] && !direcao->right)
    {
//        movimentaCauda(cobra, cobra->cauda, cobra->cauda);
        zeraDir( direcao );
		direcao->left = true;
    }
    else if  (key[KEY_RIGHT] && !direcao->left)
    {
//        movimentaCauda(cobra, cobra->cauda, cobra->cauda);
        zeraDir( direcao );
		direcao->right = true;
    }
//    else if ((direcao->right) || (direcao->up) || (direcao->left) || (direcao->down))
//        movimentaCauda(cobra, cobra->cauda, cobra->cauda);

	// Efetua a movimentacao
	// ---------------------------------------------------------------------- //
    if (direcao->up)
    {
        cobra->y --;
	}
    else if (direcao->down)
    {
        cobra->y ++;
	}
	else if (direcao->left)
    {
	    cobra->x --;
	}
	else if (direcao->right)
    {
	    cobra->x ++;
	}
	//
    // A movimentacao eh feita de
    // 1 em 1 unidade por quadro (frame)
    // ou loop do jogo
    // Essa uma unidade faz referencia
    // a matriz de tiles, nos vamos nos
    // mover uma posicao para a direcao
    // desejada
    //
    // ---------------------------------------------------------------------- //

    movimentaCauda(cobra, cobra->cauda, cobra->cauda);
    // Teleport (callback da funcao)
    teleport ( cobra );
}

void movimentaCauda  ( snake *cobra, TipoCauda *anterior, TipoCauda *proximaCauda)
{
    if (anterior != NULL)
    {
        if (proximaCauda == cobra->cauda)
        {

            movimentaCauda(cobra, proximaCauda, proximaCauda->proxima);
            proximaCauda->direcao = cobra->direcao;
//            movimentaCauda(cobra, proximaCauda, proximaCauda->proxima);

            if (proximaCauda->direcao.up)
            {
                proximaCauda->y = cobra->y + 1;
                proximaCauda->x = cobra->x;
            }
            else if (proximaCauda->direcao.down)
            {
                proximaCauda->y = cobra->y - 1;
                proximaCauda->x = cobra->x;
            }
            else if (proximaCauda->direcao.right)
            {
                proximaCauda->x = cobra->x - 1;
                proximaCauda->y = cobra->y;
            }
            else if (proximaCauda->direcao.left)
            {
                proximaCauda->x = cobra->x + 1;
                proximaCauda->y = cobra->y;
            }
            else
                printf("FUUUUUUUUUUUUUUUUUUUUUUUUUU\n");
//            movimentaCauda(cobra, proximaCauda, proximaCauda->proxima);

        }
        else if (proximaCauda != NULL)
        {

            movimentaCauda(cobra, proximaCauda, proximaCauda->proxima);
            if (anterior->direcao.up)
            {
//                movimentaCauda(cobra, proximaCauda, proximaCauda->proxima);
                proximaCauda->y = anterior->y - 1;
                proximaCauda->x = anterior->x;
                proximaCauda->direcao = anterior->direcao;
                printf("Cima\n");
//                proximaCauda->y = anterior->y;
//                proximaCauda->x = anterior->x;
//                movimentaCauda(cobra, proximaCauda, proximaCauda->proxima);
            }
            else if (anterior->direcao.down)
            {
//                movimentaCauda(cobra, proximaCauda, proximaCauda->proxima);
                proximaCauda->y = anterior->y + 1;
                proximaCauda->x = anterior->x;
                proximaCauda->direcao = anterior->direcao;
                printf("Baixo\n");
//                proximaCauda->y = anterior->y;
//                proximaCauda->x = proximaCauda->x;
//                movimentaCauda(cobra, proximaCauda, proximaCauda->proxima);
            }
            else if (anterior->direcao.right)
            {
//                movimentaCauda(cobra, proximaCauda, proximaCauda->proxima);
                proximaCauda->x = anterior->x - 1;
                proximaCauda->y = anterior->y;
                proximaCauda->direcao = anterior->direcao;
                printf("Direita\n");
//                proximaCauda->x = anterior->x;
//                proximaCauda->y = proximaCauda->y;
//                movimentaCauda(cobra, proximaCauda, proximaCauda->proxima);
            }
            else if (anterior->direcao.left)
            {
//                movimentaCauda(cobra, proximaCauda, proximaCauda->proxima);
                proximaCauda->x = anterior->x + 1;
                proximaCauda->y = anterior->y;
                proximaCauda->direcao = anterior->direcao;
                printf("Esquerda\n");
//                proximaCauda->x = anterior->x;
//                proximaCauda->y = proximaCauda->y;
//                movimentaCauda(cobra, proximaCauda, proximaCauda->proxima);
            }
            else
                printf("FUUUUUUUUUUUUUUUUUUUUUUUUUU\n");
            printf("Anterior->x: %d\n", anterior->x);
            printf("Anterior->y: %d\n", anterior->y);
            printf("Cauda->x: %d\n", proximaCauda->x);
            printf("Cauda->y: %d\n", proximaCauda->y);
//            movimentaCauda(cobra, proximaCauda, proximaCauda->proxima);
            //system("pause");
        }
    }

}

// Teleport
void teleport ( snake * cobra )
{
 	// Como estamos considerando a tela feita de tiles
 	// para pegar a posicao do jogador na matriz de tiles
 	// masta dividir a posicao (as coordenadas - x,y) dele
 	// pelo tamanho do tile, aqui TILE_X e TILE_Y definidas
 	// por macros
    //
    //
    //
    // Para a coordenada X da cobra(Colunas na matriz de TILES)
	//
	//
	// Se a posicao da cobra - x, na matriz da tela
 	// for maior que a ultima coluna da matriz, ela volta
  	// para a primeira coluna, e isto significa que ela esta
    // indo para a direita da tela
    if (cobra->x >= RES_W/TILE_X)
    {
        cobra->x = 0;
	}
	//
	// Mas, se a posicao na matriz da tela de tiles, da cobra
	// for menor que a primeira coluna, ela vai para a ultima
	// coluna, e isto significa que ela esta vindo para a esquerda
	// da tela
	else if (cobra->x < 0)
    {
	    cobra->x = RES_W/TILE_X;
	}
 	//
    //
    //
	// Para a coordenada Y da cobra (Linhas na matriz de TILES)
	//
    //
    //
	// Se a cobra estiver passado da ultima linha da matriz, ou seja
	// ter ido muito passado da parte de baixo da tela, ela vai ir para
	// a primeira linha da matriz, e isto significa que ela esta indo
	// no sentido de cima para baixo
    if (cobra->y >= RES_H/TILE_Y)
    {
	   cobra->y = 0;
	}
	//
	// Mas, se a posicao da cobra for negativa (ou seja, estiver para cima
	// da tela, ela ira para a ultima linha da matriz de tiles, ou seja,
	// isto significa que ela esta indo de baixo para cima na tela
	else if (cobra->y < 0)
    {
	    cobra->y = RES_H/TILE_Y;
	}
}
