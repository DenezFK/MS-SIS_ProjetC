#ifndef MODEG_H
#define MODEG_H


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

#include"sha256.h"
#include"md5.h"
#include"structure.h"


void modeG_sans_fichier();

void modeG_avec_fichier(FILE *fichier);



#endif
