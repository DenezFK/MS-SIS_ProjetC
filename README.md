# Projet C - Denez FLEGEAU-KIHAL

## Récupération du projet
Il existe diverses manière de récupérer le programme présenté dans ce GitHub.
- En le téléchargeant : *Via l'option "download ZIP" de GitHub web*  
- En le clonant : *Via la commande suivante :*  
```$ git clone https://github.com/DenezFK/MS-SIS_ProjetC```

Une fois le projet récupéré vous devriez disposer le l'aborescence suivante :
```
./MS-SIS_ProjetC
║
╠═══ doc/
║     ╚══ consignes.md
║
╠═══ src/
║     ╠══ main.c
║     ╠══ Makefile
║     ╠══ md5.c
║     ╠══ md5.h
║     ╠══ modeG.c
║     ╠══ modeG.h
║     ╠══ modeL.c
║     ╠══ modeL.h
║     ╠══ sha256.c
║     ╠══ sha256.h
║     ╠══ structure.c
║     ╚══ structure.h
║
╚═══ README.md
```
**Prérequis éventuels :**  
Le projet ayant été réalisé sur une machine virtuel Kali Linux il utilise la version 14.3.0 de gcc. De plus, les librairies de hashage sont directement incluent dans le projet pour plus de simplicité (voir `sha256.c/.h` et `md5.c/.h`). Il ne nécessite donc pas d'installation supplémentaire.

## Compilation du projet
Positionnez-vous à la racine du projet (`./MS-SIS_ProjetC/`).  

**Compilation :**  
```$ make```  
Le terminal doit alors vous renvoyer la réponse suivante :  
```gcc main.c modeG.c modeL.c structure.c sha256.c md5.c -o main```  
Le projet est compilé, vous pouvez passer à l'exécution !

**Nettoyage :**  
```$ make clean```  
Le terminal doit alors vous renvoyer la réponse suivante :  
```rm -f main```  
Le projet est nettoyé, vous pouvez compiler de nouveau !

## Exécution du projet

**Exécution standard :**  
```$ make run```  
Permet de lancer le programme sans aucune option. Le projet vous indiquera une erreur.
```$ make && ./main -OPTION /chemin/vers/fichier```
Permet de lancer le programme avec une option (`-G` ou `-L`) et un chemin vers un fichier (absolu ou relatif).


### Format T3C :
Le formet T3C que j'ai choisi d'implémenter est inclu dans `structure.c`. Chaque nœud de mon arbre binaire de recherche est converti en une ligne de forme : `mot;condensat\n` avec le séparateur `;`. Cela permet de stocker de manière efficace les données et de le récupérer de manière tout autant efficace.  


### Mode G : Generate

#### Sans fichier
Afin de lancer le programme en mode G sans fichier il faut simplement fournir l'argument `-G` à l'exécution ;  
```$ make && ./main -G```  

Dans un premier temps, le programme demande à l'utilisateur de choisir un algorithme de hashage entre SHA256 et MD5 en tapant 1 ou 2.  
- S'il entre 1, les condensat générés seront générés à partir de l'algorithmes SHA256.
- S'il entre 2, les condensat générés seront générés à partir de l'algorithmes MD5.
- S'il entre n'importe quoi d'autre, les condensat générés seront générés à partir de l'algorithmes SHA256 par défaut.  

Le programme permet alors de générer les condensats des chaînes de caractères passées en entrée via cet algorithme. 
- S'il entre une chaîne de caractères le programme lui renvoie son condensat.
- S'il entre `FIN` cette partie prend fin.  

Le programme demande alors à l'utilisateur s'il souhaite sauvegarder son travail dans un fichier T3C en tapant 1 ou 2 (Oui ou Non).
- S'il entre 1, on lui demande le nom du fichier T3C à écrire. 
- S'il entre 2, on ne sauvegarde pas les données dans un fichier T3C. - S'il entre n'importe quoi d'autre les données sont automatiquement sauvegardées dans un fichier T3C `./default`  

#### Avec fichier
Afin de lancer le programme en mode G avec fichier il faut simplement fournir l'argument `-G` ainsi qu'un chemin vers un fichier dictionnaire à l'exécution ;  
```$ make && ./main -G /etc/dictionaries-common/words```  

Dans un premier temps, le programme demande à l'utilisateur de choisir un algorithme de hashage entre SHA256 et MD5 en tapant 1 ou 2.  
- S'il entre 1, les condensat générés seront générés à partir de l'algorithmes SHA256.
- S'il entre 2, les condensat générés seront générés à partir de l'algorithmes MD5.
- S'il entre n'importe quoi d'autre, les condensat générés seront générés à partir de l'algorithmes SHA256 par défaut.  

Le programme génère alors les condensats des chaînes de caractères présentes dans le fichier spécifié ligne à ligne  

Le programme demande alors à l'utilisateur s'il souhaite sauvegarder son travail dans un fichier T3C en tapant 1 ou 2 (Oui ou Non).
- S'il entre 1, on lui demande le nom du fichier T3C à écrire. 
- S'il entre 2, on ne sauvegarde pas les données dans un fichier T3C. - S'il entre n'importe quoi d'autre les données sont automatiquement sauvegardées dans un fichier T3C `./default`  

### Mode L : Lookup
Afin de lancer le programme en mode L il faut simplement fournir l'argument `-L` ainsi qu'un chemin vers un fichier T3C à l'exécution ;  
```$ make && ./main -L ./default```  

Le programme charge alors automatiquement ce fichier T3C en mémoire dans la structure d'un arbre binaire de recherche.  


Une fois cette étape finie il permet alors à l'utilisateur d'entrer des condensats à rechercher.  
- S'il entre un condensat le programme le cherche dans l'arbre binaire de recherche créé. 
    - Si le condensat est trouvé, le programme renvoie le mot associé sur la sortie standard.
    - Si le condensat n'est pas trouvé, le programme renvoi une erreur sur la sortie standard.
- S'il entre le `FIN`cette partie prend fin.