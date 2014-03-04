#ifndef GENERAL_H
#define GENERAL_H

// Resolucao
#define RES_W 800// Tamanho em X
#define RES_H 600 // Tamanho em Y

// Para a movimentacao
// Essas macros sao o tamanho
// de cada quadradinho na tela
// ou seja, teremos a seguinte quantidade de
// quadradinhos:

// Em x: RES_W / TILE_X = 800 / 32 = 25
// Em y: RES_H / TILE_Y = 600 / 32 = 18,75
// Ou seja, apenas 18, o outro pedaco a cobra ira pular
// ou seja, havera o teleport
#define TILE_X 32
#define TILE_Y 32

// Portanto, a matriz de tiles sera de tamanho 25x18
// ou seja, 25 linhas e 18 colunas

// Para entender melhor essa matriz, eh como se a tela fosse dividida
// em quadradinhos, cada quadradinho de 32x32 pixels, e sabemos que essa
// matriz possui 25 linhas e 18 colunas, portanto serao 25x18 = 450
// Isso mesmo, 450 quadrados (TILES)

//
// Comida
//

typedef enum _bool {false, true} bool;

// Define tipo de estrutura
typedef struct
{
    int x;
    int y;

    BITMAP *bmp;
} comida;


//
// Direcao
//

// Define tipo de estrutura
typedef struct
{
    bool up;
    bool down;
    bool left;
    bool right;
} direc;



//
//CAUDA
//
// Define tipo de estrutura Cauda
typedef struct _Cauda TipoCauda;

struct _Cauda
{
    int x; //está andando na horizontal
    int y; //está andando na vertical
    BITMAP *bmp; //ponteiro pro BITMAP
    direc direcao; //direcao que ele esta andando
    TipoCauda *proxima; //proxima cauda
};

//
// SNAKE
//
// Define tipo de estrutura
typedef struct
{
    int x;
    int y;
    int tamanho;
    int pontos;
    BITMAP *bmp;
    direc direcao;
    TipoCauda *cauda;
    TipoCauda *ultima;
} snake;

// Como a matriz de tiles eh de tamanho 25x18
// a posicao maxima da snake em X sera 25
// e em Y 18

#endif
