#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"structure.h"
#include"modeG.h"
#include"modeL.h"



FILE *ouverture_dictionnaire(char **argv){

	FILE *fp = fopen(argv[2], "r");

	if(fp == NULL){
		printf("\t[ERREUR] - pas de fichier nommé %s\n", argv[2]);
	}
	else {
		printf("Fichier %s ouvert avec succès\n", argv[2]);
	}
	return fp;
}

void choix(int argc, char **argv){
	
	if(argc == 1)
	{
		printf("\t[ERREUR] - Vous n'avez pas indiqué de mode de fonctionnement !\n"); 
	}
	else if(argc == 2)
	{	
		if(!strcmp(argv[1], "-G"))
		{ 
			printf("Mode G sélectionné !\n"); 
		}
		else if(!strcmp(argv[1], "-L"))
		{ 
			printf("Mode L sélectionné !\n"); 
		}
		else 
		{
			printf("\t[ERREUR] - Le mode %s n'existe pas !\n", argv[1]);
		}
	}
	else if(argc == 3)
	{
		if(!strcmp(argv[1], "-G"))
		{
			printf("Mode G sélectionné !\n");	
			FILE *fichier = ouverture_dictionnaire(argv);
			//Appel fonction
			fclose(fichier);
		}
		else if(!strcmp(argv[1], "-L"))
		{ 
			printf("Mode L sélectionné !\n"); 
			FILE *fichier = ouverture_dictionnaire(argv);
			//Appel fonction
			fclose(fichier);
		}
		else 
		{
			printf("\t[ERREUR] - Le mode %s n'existe pas !\n", argv[1]);
		}		
	}
}


int main(int argc, char *argv[]){
	
	system("clear");
	printf("\n\n------------{ Début du programme \"%s\": }------------\n\n", argv[0]);
	
	choix(argc, argv);
	
	printf("\n-------------{ Fin du programme \"%s\": }-------------\n", argv[0]);	
	return 0;
}

