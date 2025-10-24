#ifndef STRUCTURE_H
#define STRUCTURE_H



typedef struct node{
	char *mot;
	char *condensat;
	struct node *g;
	struct node *d;
} node_t;


node_t *create_node(char *mot, char *condensat);

void free_node(node_t *my_node);

void free_tree(node_t *my_tree);

void display_node(node_t *my_node);

void display_tree(node_t *my_tree);

void insert_node(node_t *my_tree, node_t *my_node);

void to_file(node_t *my_tree, FILE *fichier);

void split_line(const char *line, char *mot, char *condensat);

node_t *from_file(FILE *fichier);

node_t *search_from_hash(node_t *my_tree, char *condensat);



#endif
