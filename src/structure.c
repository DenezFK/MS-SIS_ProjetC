#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"



node_t *create_node(char *mot, char *condensat)
{
	node_t *my_node = malloc(sizeof(node_t));
	
	my_node->mot = strdup(mot);
	my_node->condensat = strdup(condensat);
	my_node->g = NULL;
	my_node->d = NULL;
	
	return my_node;	
}

void free_node(node_t *my_node)
{
	if(my_node !=  NULL)
	{
		free(my_node->mot);
		free(my_node->condensat);
		free(my_node);
	}
}

void free_tree(node_t *my_tree)
{
	if(my_tree != NULL)
	{
		if(my_tree->g != NULL){ free_tree(my_tree->g); }
		if(my_tree->d != NULL){ free_tree(my_tree->d); }
		free_node(my_tree);
	}
}

void display_node(node_t *my_node)
{
	if(my_node != NULL)
	{
		printf("\nAffichage du nœud %p ;", my_node);
		printf("\n\tMot : %s", my_node->mot);
		printf("\n\tCondensat : %s", my_node->condensat);
		printf("\n\t->Gauche : %p", my_node->g);
		printf("\n\t->Droite : %p", my_node->d);
	}
}

void display_tree(node_t *my_tree)
{
	if(my_tree != NULL)
	{
		display_node(my_tree);
		if(my_tree->g != NULL){ display_tree(my_tree->g); }
		if(my_tree->d != NULL){ display_tree(my_tree->d); }
	}
}


void insert_node(node_t *my_tree, node_t *my_node)
{
	if(my_tree != NULL)
	{
		if(strcmp(my_node->condensat, my_tree->condensat) < 0)
		{
			if(my_tree->g != NULL){ insert_node(my_tree->g, my_node); }
			else if(my_tree->g == NULL){ my_tree->g = my_node; }
		}
		else if(strcmp(my_node->condensat, my_tree->condensat) > 0)
		{
			if(my_tree->d != NULL){ insert_node(my_tree->d, my_node); }
			else if(my_tree->d == NULL){ my_tree->d = my_node; }
		}	
	}
	else
	{
		my_tree = my_node;
	}
}

void to_file(node_t *my_tree, FILE *fichier)
{
	if(my_tree != NULL)
	{
		to_file(my_tree->g, fichier);
		fprintf(fichier,"%s;%s\n", my_tree->mot, my_tree->condensat);
		to_file(my_tree->d, fichier);
	}	
}

//Si j'étais quelqu'un de propre je devrais faire un fichier .c et .h pour contenir
//cette fonction et l'appeler proprement ici. Mais je ne suis pas quelqu'un de propre
//i.e. j'ai la flemme, en plus ça va complexifier le makefile pour rien alors que
//j'ai déjà du mal...
void split_line(const char *line, char *mot, char *condensat)
{
	const char *debut = line;
	const char *fin = debut + strlen(debut);

	const char *separateur = debut;
	while(separateur < fin && *separateur != ';')
	{
		separateur++;
	}

	size_t taille_mot = separateur - debut;
	strncpy(mot, debut, taille_mot);
	mot[taille_mot] = '\0';

	if(separateur < fin)
	{
		strncpy(condensat, separateur + 1, fin - (separateur + 1));
		condensat[fin - (separateur + 1)] = '\0';
	}
	else
	{
		condensat[0] = '\0';
	}
	//Spécial dédicace, merci à ce monsieur sur Reddit : 
	//https://www.reddit.com/r/cprogramming/comments/189qdn3/comment/kbsuso3/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button
}

node_t *from_file(FILE *fichier)
{
	char ligne[200];
	node_t *my_tree;
	int indice = 0;	

	while(fscanf(fichier,"%s", ligne) != EOF)
	{
		printf("\n\n[%d] - %s", indice, ligne);
		
		char mot[100];
		char condensat[65];
		split_line(ligne, mot, condensat);
		printf("\n\tMot : %s\n\tCondensat : %s", mot, condensat);
		
		node_t *my_node = create_node(mot, condensat);	
		//display_node(my_node);
		
		if(indice == 0)
		{
			printf("\nOn initialise la racine de l'arbre");
			my_tree = my_node;
		}
		else
		{
			printf("\nOn initialise un nouveau noeud de l'arbre");
			insert_node(my_tree, my_node);
		}

		indice++;
 	}

	return my_tree;		
}

node_t *search_from_hash(node_t *my_tree, char *condensat)
{	
	if(my_tree == NULL)
	{
		return NULL;
	}
	else
	{
		int comparaison = strcmp(condensat, my_tree->condensat);

		if(comparaison == 0)
		{
			return my_tree;
		}
		else if(comparaison > 0)
		{
			if(my_tree->d != NULL)
			{ 
				return search_from_hash(my_tree->d, condensat); 
			}
			else { return NULL; }
		}
		else if(comparaison < 0)
		{
			if(my_tree->g != NULL)
			{
				return search_from_hash(my_tree->g, condensat); 
			}
			else { return NULL; }
		}
	}
}



/*int main()
{
	printf("Hello, Main\n");

		
	printf("\n\nOn affiche la racine");
	char *mot0 = "TestRacine";
	char *condensat0 = "b";
	node_t *tree = create_node(mot0, condensat0);
	display_node(tree);

	printf("\n\nOn affiche le premier noeud");
	char *mot1 = "LeMotDePasseDeVincent";
	char *condensat1 = "c";
	node_t *obj1 = create_node(mot1, condensat1);
	display_node(obj1);

	printf("\n\nOn affiche le second noeud");
	char *mot2 = "LeMotDePasseDeThomas";
	char *condensat2 = "a";
	node_t *obj2 = create_node(mot2, condensat2);
	display_node(obj2);
	
	printf("\n\nOn affiche la racine après chaque insert");
	insert_node(tree, obj1);
	display_node(tree);
	insert_node(tree, obj2);
	display_node(tree);
	
	printf("\n\nOn affiche l'arbre");
	display_tree(tree);

	FILE *fichier1;
	fichier1 = fopen("./fichierT3C", "w");
	to_file(tree, fichier1);
	fclose(fichier1);
	
	printf("\n\n\tTEST from_file");
	FILE *fichier2;
	fichier2 = fopen("./fichierT3C", "r");
	node_t *test = from_file(fichier2);
	fclose(fichier2);
	display_tree(test);

	
	printf("\n\n\t Search_From_Hash");
	char *condensat = "a";
	node_t *trouve = search_from_hash(tree, condensat);
	if(trouve != NULL){ display_node(trouve); }
	else{ printf("\nTrouve était null"); }	



	return 0;
}*/
