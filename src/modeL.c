#include"modeL.h"



void modeL_avec_fichier(FILE *fichier)
{
	printf("\n\n------------{ Début du mode L avec fichier: }-----------\n\n");

	printf("\n!============================================================!");
	printf("\n!     Nous récupérons les entrées d'un dictionnaire T3C      !");
	printf("\n!============================================================!");
	
	node_t *my_tree = from_file(fichier);
	if(my_tree == NULL)
	{ 
		printf("\nLa lecture des données à échouée"); 
		return;
	} 	


	printf("\n!============================================================!");
	printf("\n!         Veuillez entrer une condensat à rechercher         !");
	printf("\n!            (Entrez 'FIN' pour quitter ce mode)!            !");
	printf("\n!============================================================!");

	char input[100];
	int indice = 0;
	node_t *my_node;

	while(1)
	{
		printf("\n[%d] - ", indice);
		scanf("%99s", input);

		if(strcmp(input, "FIN") == 0){ break; }

		my_node = search_from_hash(my_tree, input);
		if(my_node == NULL){ printf("Le condensat recherché n'est pas connu!\n"); }
		else{ printf("Le condensat recherché correspond à la chaîne de caractères : %s\n", my_node->mot); }
	}
	
	printf("\n------------{ Fin du mode G avec fichier: }-------------\n");
}
