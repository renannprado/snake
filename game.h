#ifndef GAME_H
#define GAME_H

#include <allegro.h>
#include "general.h"

void iniciaJogador ( snake * cobra );
void marcaPonto    ( snake * cobra , comida * com);
void criaComida	   ( comida * com );
void inicia ( void );
void criaCauda (snake *cobra);

#endif
