
	/*
	**********************************************************
	*
	* Programme : lliste.c
	*
	* ecrit par : NTUMBA W. Patient et LOTOY B. Vianney
	*
	* resume : Enregistrement des voisins d'un sommet avec 
	*          une liste doublement chainee avec sentinelle
	*
	* date : 12/10/2014
	*
	***********************************************************
	*/
	
	#include <stdio.h>
	#include <stdlib.h>
	#include "lliste.h"
	
	
	ListVoisin *initListeVoisins(){
		
		ListVoisin *listeVoisin = malloc( sizeof * listeVoisin );
		
		if(listeVoisin != NULL){
			
			listeVoisin->nbMaxVoisin = 0;
			listeVoisin->voisinEnFinDeListe = NULL;
			listeVoisin->voisinEnDebutDeListe = NULL;
		}
		return listeVoisin;
	}
	
	
	
	ListVoisin *updateListeVoisins(ListVoisin *listeVoisin, int voinsin, int poidsVoisin){
			
		if(listeVoisin != NULL){
			
			struct TypVoisin *noeudVoisin = malloc(sizeof * noeudVoisin);
			if( noeudVoisin != NULL ){
				
				noeudVoisin->voisin = voinsin;
				noeudVoisin->poidsVoisin = poidsVoisin;
				noeudVoisin->voisinSuivant = NULL;
				
				if(listeVoisin->voisinEnDebutDeListe == NULL){// On teste si la liste est vide
					
					noeudVoisin->voisinPrecedent = NULL;
					listeVoisin->voisinEnDebutDeListe = noeudVoisin;
					listeVoisin->voisinEnFinDeListe = noeudVoisin;
					
				}
				else{// Si la liste n'est pas vide
					
					
					listeVoisin->voisinEnFinDeListe->voisinSuivant = noeudVoisin;
					noeudVoisin->voisinPrecedent = listeVoisin->voisinEnFinDeListe;
					listeVoisin->voisinEnFinDeListe = noeudVoisin;
					
				}
				listeVoisin->nbMaxVoisin++;
			
			}
			
		}
		return listeVoisin;
	}
	
	ListVoisin *addVoisin(ListVoisin *listeVoisin, int voisin, int poidsVoisin, int position){
		
		
		if (listeVoisin != NULL)
		{
			struct TypVoisin *voisin_temp = listeVoisin->voisinEnDebutDeListe;
			int i = 1;
			while (voisin_temp != NULL && i <= position)
			{
				
				if (position == i)
				{
					if (voisin_temp->voisinSuivant == NULL)
					{
						listeVoisin = updateListeVoisins(listeVoisin, voisin,poidsVoisin);
					}
					else if (voisin_temp->voisinPrecedent == NULL)
					{
						listeVoisin = updateListeVoisins(listeVoisin, voisin,poidsVoisin);
					}
					else
					{
						struct TypVoisin *voisin_to_add = malloc(sizeof *voisin_to_add);
						if (voisin_to_add != NULL)
						{
							voisin_to_add->voisin = voisin;
							voisin_to_add->poidsVoisin = poidsVoisin;
							voisin_to_add->voisinSuivant->voisinPrecedent = voisin_to_add;
							voisin_to_add->voisinPrecedent->voisinSuivant = voisin_to_add;
							voisin_to_add->voisinPrecedent = voisin_temp->voisinPrecedent;
							voisin_to_add->voisinSuivant = voisin_temp;
							listeVoisin->nbMaxVoisin++;
						}
					}
				}
				else
				{
					voisin_temp = voisin_temp->voisinSuivant;
				}
				i++;
			}
		}
		return listeVoisin;
	}
	
	ListVoisin *removeVoisin(ListVoisin *listeVoisin, int voisin){
			
		if(listeVoisin != NULL){
			
			struct TypVoisin *voisin_tmp = listeVoisin->voisinEnDebutDeListe;
			int trouve = 0;
			while (voisin_tmp != NULL && !trouve)
			{
				if (voisin_tmp->voisin == voisin)
				{
					if (voisin_tmp->voisinSuivant == NULL)
					{
						listeVoisin->voisinEnFinDeListe = voisin_tmp->voisinPrecedent;
						
						listeVoisin->voisinEnFinDeListe->voisinSuivant = NULL;
					}
					else if (voisin_tmp->voisinSuivant == NULL)
					{
						listeVoisin->voisinEnFinDeListe = voisin_tmp->voisinSuivant;
						listeVoisin->voisinEnDebutDeListe->voisinPrecedent = NULL;
					}
					else
					{
						voisin_tmp->voisinSuivant->voisinPrecedent = voisin_tmp->voisinPrecedent;
						voisin_tmp->voisinPrecedent->voisinSuivant = voisin_tmp->voisinSuivant;
					}
					free(voisin_tmp);
					listeVoisin->nbMaxVoisin--;
					trouve = 1;
				}
				else
				{
					voisin_tmp = voisin_tmp->voisinSuivant;
				}
			}
		}
		return listeVoisin;
	}
	
	
	void libererMemoireListeVoisins(ListVoisin **listeVoisin){
		
		if(*listeVoisin != NULL){
			
			struct TypVoisin *voisin_bkp = (*listeVoisin)->voisinEnDebutDeListe;
			while(voisin_bkp != NULL){
				
				struct TypVoisin *voisin_supp = voisin_bkp;
				voisin_bkp = voisin_bkp->voisinSuivant;
				free(voisin_supp);
			} 
			free(*listeVoisin);
			*listeVoisin = NULL;
			
		}
	
	}
	
	
	void afficherListeVoisins(ListVoisin *listeVoisin){
	
		if( listeVoisin != NULL ){
			
			struct TypVoisin *voisin_bkp = listeVoisin->voisinEnDebutDeListe;
			while( voisin_bkp != NULL ){
			
				 printf("( %d, %d ) -> ", voisin_bkp->voisin, voisin_bkp->poidsVoisin );
				 voisin_bkp = voisin_bkp->voisinSuivant;
			}
			printf("\n\n");
		}
	
	}
	
	
	
	
	
