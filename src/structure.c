#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"



node_t create_node(char *mot, char *condensat)
{
	node_t my_node;
	my_node.mot = mot;
	my_node.condensat = condensat;
	my_node.g = NULL;
	my_node.d = NULL;
	
	return my_node;	
}

void free_node(node_t *my_node)
{
	if(my_node !=  NULL)
	{
		free(my_node->mot);
		free(my_node->condensat);
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
		if(my_tree->g != NULL)
		{
			display_tree(my_tree->g);
		}
		else if(my_tree->d != NULL)
		{
			display_tree(my_tree->d);
		}
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

node_t *from_file(FILE *fichier)
{	
	fprintf(stdout,"\nOn récupère un arbre depuis un fichier");

	char *ligne;
	fscanf(fichier,"%s", ligne);
	
	

	node_t my_tree;
	node_t my_node;

	int indice = 0;
	while(fscanf(fichier,"%s", ligne) != EOF)
	{

		printf("\n\t\tVivant");	
		fprintf(stdout,"\n[%d] - %s", indice, &ligne);
		printf("\n\t\tVivant");	
		

		char *mot = strtok(ligne, " ; ");	
		char *condensat = strtok(NULL, " ; ");

		fprintf(stdout,"\n\t%s", mot);
		fprintf(stdout,"\n\t%s", condensat);
		

		if(indice == 0)
		{	
			my_tree = create_node(mot, condensat);
			display_node(&my_tree);
		}
		else 
		{
			my_node = create_node(mot, condensat);
			display_node(&my_node);
			insert_node(&my_tree, &my_node);
			display_tree(&my_tree);
		}

		fprintf(stdout,"\nMise à jour de l'arbre");
		indice = indice + 1;
		free_node(&my_node);
		free(mot);
		free(condensat);

	}
	fprintf(stdout,"\nOn affiche l'arbre obtenu");
	display_tree(&my_tree);
	return NULL;
}



int main()
{
	printf("Hello, Main\n");

		
	printf("\nOn affiche la racine");
	char *mot0 = "TestRacine";
	char *condensat0 = "ffeljbflkejbfffezfkje";
	node_t tree = create_node(mot0, condensat0);
	//display_node(&tree);

	printf("\nOn affiche le premier noeud");
	char *mot1 = "LeMotDePasseDeVincent";
	char *condensat1 = "fjlhqvfjknfqlkhjcbelf";
	node_t obj1 = create_node(mot1, condensat1);
	//display_node(&obj1);

	printf("\nOn affiche le second noeud");
	char *mot2 = "LeMotDePasseDeThomas";
	char *condensat2 = "mjklfjnzefnzekfnezkfn";
	node_t obj2 = create_node(mot2, condensat2);
	//display_node(&obj2);
	
	printf("\nOn affiche la racine après chaque insert");
	insert_node(&tree, &obj1);
	//display_node(&tree);
	insert_node(&tree, &obj2);
	//display_node(&tree);
	
	printf("\nOn affiche l'arbre");
	display_tree(&tree);

	FILE *fichier1;
	fichier1 = fopen("./fichierT3C", "w");
	to_file(&tree, fichier1);
	fclose(fichier1);

	FILE *fichier2;
	fichier2 = fopen("./fichierT3C", "r");
	node_t *test = from_file(fichier2);
	fclose(fichier2);



	return 0;
}
