							
							
							Readme.txt
							***********


Description
***********

Ce projet de bibliotheque de graphe est constitue de deux trois des dossiers ci-dessous :

1. le repertoire src/ où sont sont garder tous les fichier sources et header

2. le repertoire obj/ sont sauvegarder les fichiers gardes en memoire 
   
3. le repertoire bin/, dans ce repertoire est genere le fichier executatble

4. le repertoire lib/, dans ce repertoire sont gardes les librairies lliste.a et lgraphe.a

Fichiers sources
****************

1. main.c
Contient la Fonction principal du Projet, faisant appel aux fonctions du menu.

2.menu.c
Contient le menu qui fait appel a toutes les fonctionnalites de gestion du graphe : creation du graphe, 
lecture du graphe au besoin de l'utilisateur peut saisir.

3.utilitaire.c
Contient des fonctions qui sont utilisees dans les differents cas du menu pour lagestion du graphe.


4.lliste.c
Contient les fonction des gestion des listes chainees.

5.lgraphe.c
Contient les fonctions de gestion du graphe, il utilise les listes chainees pour bien manipuler les voisins des sommets


Compilation du programe
***********************

En etant a la racine du projet, Lancer le fichier make, il genere ainsi l'executable dans le dossier bin
ensuite lancer en etant a la racine du projet ./bin/executable
