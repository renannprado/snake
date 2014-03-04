#ifndef MOVIMENTO_H
#define MOVIMENTO_H

#include <allegro.h>
#include "general.h"

void zeraDir  		 ( direc * direcao );
void marcaPonto      ( snake * cobra , comida * com);
void movimento 	     ( snake * cobra, direc * direcao );
void movimentaCauda  ( snake *cobra, TipoCauda *anterior, TipoCauda *proximaCauda);
void teleport 		 ( snake * cobra );

#endif
