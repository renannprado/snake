#include "main.h"

int main ( void )
{
 	inicia();

    // Iniciando as estruturas
    // (Declaracao normal, como se fosse variavel)
    snake cobra;
    comida com;

	// Valores inicias
    iniciaJogador ( &cobra );
    zeraDir ( &cobra.direcao );
	cobra.direcao.right = true; //para a snake começar andando

	// Comida
//    com.x = 4;
//	com.y = 4;
    criaComida ( &com );

    // Bitmaos (buffers adicionais)
    cobra.bmp = create_bitmap(cobra.tamanho, cobra.tamanho);
    com.bmp = create_bitmap(32, 32);

    // Pre render dos objetos
    // ---------------------------------------------------------------------- //
    // Comida
    rectfill (com.bmp, 0, 0, 32, 32, makecol(255, 0, 255) );
    circlefill (com.bmp, 16, 16, 10, makecol(255, 255, 255) );
	//
    // Snake
    rectfill (cobra.bmp, 0, 0, cobra.tamanho, cobra.tamanho, makecol(200, 255, 100) );
	//
	// Esse pre-render, nada mais eh do que gerar o buffer para esses objetos
	// ou seja, a gente vai criar primeiro, como se fosse uma variavel com um valor
	// e depois apenas colocar no buffer na posicao que a gente quer...
	// Nao precisamos colocar essas linhas de codigo dentro do while, porque
	// soh precisamos gerar isso uma vez, e nao a todo quadro.
	//
    // ---------------------------------------------------------------------- //

    // Buffer
    // ================

    // O buffer eh muito importante
    // como ja disse, ele eh como se fosse uma caixa, porem, tratamos
    // como se fosse um papel, todo o quadro a gente deixa ele limpo
    // (tiramos tudo o que tem) e comecamos a desenhar coisas novas,
    // depois de tudo pronto, colocamos na screen.
    BITMAP *buffer = NULL;
    buffer = create_bitmap(RES_W, RES_H);
    // O buffer eh do tamanho da screen

    // Laço principal
    while( !key[KEY_ESC] )
    {
	 	// Quero ele limpinho em allegro
        clear (buffer);

		// Funcionalidade do jogo
		// Executa o movimento
        movimento( &cobra, &cobra.direcao );
        // Verifica se marcou ponto
        marcaPonto ( &cobra, &com);
		// Desenha tudo na tela
        desenhaTela ( buffer,  com,  cobra );

        // Imprimimos as coordenadas x e y na tela para o usuário ver
        textprintf_ex (buffer, font, 10, RES_H-20, makecol(255,0,0), 0, "Player Linha %d Coluna %d", cobra.y, cobra.x);
        textprintf_ex (buffer, font, 10, RES_H-10, makecol(255,0,0), 0, "Comida Linha %d Coluna %d", com.y, com.x);
        textprintf_ex (buffer, font, RES_W-90, RES_H-20, makecol(255,0,0), 0, "Pontos: %d", cobra.pontos);

		// Essa funcao pega o buffer e joga na tela
		bufferDuplo ( buffer );
    }

	// Desalocando o bitmap e saindo
	destroy_bitmap ( buffer );
	destroy_bitmap ( com.bmp );
	destroy_bitmap ( cobra.bmp );

    allegro_exit();
    return (0);
}
END_OF_MAIN();


