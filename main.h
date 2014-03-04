// De todos os arquivos HEADER este eh o principal
// ele que inclui todos os outros.

// A estrutura geral de um header eh desse tipo:

// xxx.h
//--------------
// #se nao definido XXX_H
// #definir XXX_H

// bla bla bla

// fim do se
//--------------

// Dentro dos headers podemos incluir bibliotecas, declarar funcoes
// variaveis e tudo mais

// Este tem a funcao de:
// Todos os arquivos que incluirem este header incluirao tambem todos esses
// outros headers que abaixo estao no #include

#ifndef MAIN_H
#define MAIN_H

#include <allegro.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "general.h"
#include "game.h"
#include "movimento.h"
#include "render.h"

#endif
