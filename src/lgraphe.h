	#ifndef LGRAPHE_H
	#define LGRAPHE_H
	#include <dirent.h> 
	#ifndef WIN32
		#include <sys/types.h>
	#endif
	#include <stdio.h>
	#include <stdlib.h>
	#include "lliste.h"


	typedef struct{
			
			int estOriente;
			int nbMaxSommets;
			struct TypVoisin *listesAdjacences[100][100];

	}TypGraphe;

	TypGraphe *remplissageGrapheManuel( int estOriente, int nbMaxSommets );
	TypGraphe *remplissageGrapheAutomatic(char *fichierATraiter, int nbLigne);
    TypGraphe *ajoutSommetAuGraphe(TypGraphe *graphe);
    TypGraphe *ajoutAreteAuGraphe(TypGraphe *graphe, int sommet, int position);
    TypGraphe *supprimerAreteDuGraphe(TypGraphe *graphe, int sommet);
    TypGraphe *supprimerSommetDuGraphe(TypGraphe *graphe, int sommet);
	
	void AjoutListeVoisinsAuGraphe(ListVoisin *listeVoisin, TypGraphe *graphe, int iemeSommet );
	void supprimerListeVoisinAuGraphe(ListVoisin *listeVoisin, TypGraphe *graphe, int iemeSommet );
	void stockerGrapheEnFichier( TypGraphe *graphe, char nomFichierGraphe[] );
	void stockerGrapheEnFichierS( TypGraphe *graphe, char nomFichierGraphe[], int sommet);
	void affichageGrapheSaisi(TypGraphe *graphe);
	void lireGrapheFromFichier(char *p_fichierAlire);
    void aficherGrapheSaved();
	
	int grapheEstOriente(TypGraphe *graphe);
	int nbrLigneGrapheFromFichier(char *p_fichierAlire);
	int nombreGrapheSaved();
	
	
	char *selectionFichierGraphe(int choix);
	
	#endif
