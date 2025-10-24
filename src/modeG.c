#include"modeG.h"



void modeG_sans_fichier()
{
	printf("\n------------{ Début du mode G sans fichier: }-------------\n\n");
	
	printf("\n!============================================================!");
	printf("\n!             Les algorithmes disponibles sont :             !");
	printf("\n! 1. SHA256                                                  !");
	printf("\n!============================================================!");
	
	int choix = 0;
	printf("\nVeuillez saisir le numéro associé à l'algorithme souhaité : ");
	scanf("%d", &choix);

	switch (choix)
	{	
		case 1 : 
			printf("/!\\ Vous avez choisi l'algo 1\n");
			break;

		default : 
			printf("\n\tVotre choix n'est pas dans la liste. SHA256 par défaut");
	}


	printf("\n!============================================================!");
	printf("\n!     Veuillez entrer une chaîne de caractère à hasher!      !");
	printf("\n!            (Entrez 'FIN' pour quitter ce mode)!            !");
	printf("\n!============================================================!");

	char input[100];
	int indice = 0;
	node_t *my_tree;

	while(1)
	{
		printf("\n[%d] - ", indice);
		scanf("%99s", input);

		if(strcmp(input, "FIN") == 0){ break; }
		

		char condensat[SHA256_HEX_SIZE];
		sha256_hex(input, strlen(input), condensat);
		printf("-> %s\n", condensat);

		node_t *my_node = create_node(input, condensat);
		if(my_node != NULL){ printf("\n/!\\ Vous avez initialisé un nouveau noeud"); }
		//display_node(my_node);
		

		if(indice == 0){ my_tree = my_node; }
		else{ insert_node(my_tree, my_node); }

		//display_tree(my_tree);
		indice++;
	}
	//printf("\nL'arbre que vous avez construit ressemble donc à :");
	//display_tree(my_tree);


	printf("\n!============================================================!");
	printf("\n!  Souhaitez-vous sauvegarder l'arbre dans un fichier T3C ?  !");
	printf("\n!                      1. Oui | 2. Non                       !");
	printf("\n!============================================================!");
	printf("\n[choix] - "); 
	
	int sauvegarde = 0;
	scanf("%d", &sauvegarde);
	
	switch (sauvegarde)
	{	
		case 1 : 
			printf("/!\\ Vous avez choisi de sauvegarder\n");

			printf("\nVeuillez entrer le nom de votre fichier de sauvegarde : ");
			char nom[50];
			scanf("%s", nom);

			FILE *fichier1 = fopen(nom, "w");
			to_file(my_tree, fichier1);
			fclose(fichier1);

			break;

		case 2 : 
			printf("/!\\ Vous avez choisi de ne pas sauvegarder\n");
			break;

		default : 
			printf("\n\tVotre choix n'est pas dans la liste. Sauvegarde dans ./default");
			
			FILE *fichier2 = fopen("default", "w");
			to_file(my_tree, fichier2);
			fclose(fichier2);
	}

			
	
	printf("\n-------------{ Fin du mode G sans fichier: }--------------\n\n");
}

void modeG_avec_fichier(FILE *fichier)
{
	printf("\n\n--------{ Début du mode G avec fichier: }--------\n\n");
	
	//Prompter un choix pour les algorithmes de chifffrement des mots

	//Lire chaque mots du fichier, 
	//Générer un condensat
	//Stocker la données dans un nouvel élément de la structure de données
	//'Ranger' cet élément dans l'arbre
	//Une fois le fichier fini, exporter l'arbre vers un fichier T3C
	//
	//Proposer des algo différents pour le condensat
	
	printf("\n-----------{ Fin du mode G avec fichier: }-----------\n");
}
