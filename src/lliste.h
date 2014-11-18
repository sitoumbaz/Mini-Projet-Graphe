	#ifndef LLISTE_H
	#define LLISTE_H
	
	#include <stdio.h>
	#include <stdlib.h>

	struct TypVoisin{
			
			int voisin;
			int poidsVoisin;
			struct TypVoisin *voisinSuivant;
			struct TypVoisin *voisinPrecedent;
	};


	typedef struct {
		
		int nbMaxVoisin;
		struct TypVoisin *voisinEnFinDeListe;
		struct TypVoisin *voisinEnDebutDeListe;
		
	}ListVoisin;


	ListVoisin *initListeVoisins();
	ListVoisin *updateListeVoisins(ListVoisin *listeVoisin, int voinsin, int poidsVoisin);
	ListVoisin *removeVoisin(ListVoisin *listeVoisin, int voisin);
	ListVoisin *addVoisin(ListVoisin *listeVoisin, int voisin, int poidsVoisin, int position);
	
	void libererMemoireListeVoisins(ListVoisin **listeVoisin);
	void afficherListeVoisins(ListVoisin *listeVoisin);
	
	
	#endif
