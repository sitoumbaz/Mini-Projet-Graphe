
	/*
	**********************************************************
	*
	* Programme : llgraphe.c
	*
	* ecrit par : NTUMBA W. Patient et LOTOY B. Vianney
	*
	* resume : Gestion du graphe 
	*
	* date : 12/10/2014
	*
	***********************************************************
	*/
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "lgraphe.h"
	#include "lliste.h"

	TypGraphe *remplissageGrapheManuel( int estOriente, int nbMaxSommets ){
		
		TypGraphe *graphe = malloc(sizeof * graphe);
		graphe->estOriente = estOriente;
		graphe->nbMaxSommets = nbMaxSommets;
		int i, j = 0;
		
		for(i=0; i<nbMaxSommets; i++){
			ListVoisin *listeVoisin = initListeVoisins();	
			int nbMaxVoisins = 0;
			printf("Traitement du sommet  %d", (i+1));
			printf("\nBien vouloir saisir le nombre des voisins du sommet %d :  ",(i+1));
			scanf("%d", &nbMaxVoisins);
			if(nbMaxVoisins == 0){
				
				listeVoisin = updateListeVoisins(listeVoisin, 0, 0);	
			}
			else{
				
				for(j=0; j < nbMaxVoisins; j++){		
					int voisin = 0;
					int poidsVoisin = 0;
					printf("\nBien vouloir saisir le voisin %d du sommet courant %d :  " ,(j+1),(i+1));
					scanf("%d", &voisin);
					printf("\nBien vouloir saisir le poids du voisin %d du sommet courant %d :  " ,(j+1),(i+1));
					scanf("%d", &poidsVoisin);
					printf("\n\n");
					listeVoisin = updateListeVoisins(listeVoisin, voisin, poidsVoisin);
					if( (j+1) == nbMaxVoisins ){
						listeVoisin = updateListeVoisins(listeVoisin, -1, 0);	
					}
					printf("\n\n");		
				}
			}
			
			AjoutListeVoisinsAuGraphe(listeVoisin,graphe,i);  
		}
		return 	graphe;
	}
	
	TypGraphe *remplissageGrapheAutomatic(char *fichierATraiter, int nbLigne){
		
		TypGraphe *graphe = malloc(sizeof * graphe);
		FILE * fichier;
		char ligne_lue[512];
		char dirObj[] = "obj/";
		char *cheminAndFichier = malloc(sizeof(char) * 20);
	   	cheminAndFichier[0] = '\0';
	    strcat(cheminAndFichier,dirObj);
	    strcat(cheminAndFichier,fichierATraiter);
		fichier = fopen(cheminAndFichier, "r");
		int i = 0;
		if(fichier != NULL){	
		  while(fgets(ligne_lue, 512, fichier) != NULL){
				
				if(i==1){
					int nbMaxSommets = atoi(ligne_lue);
					graphe->nbMaxSommets = nbMaxSommets;
				}
				if(i==3){
					int estOriente = atoi(ligne_lue);
					graphe->estOriente = estOriente;
				}
				ListVoisin *listeVoisin = initListeVoisins();
				if(i > 4){
					char *listeVoisins = malloc(sizeof(char) * 512);
					listeVoisins[0]='\0';
					strcat(listeVoisins,ligne_lue);
					int j=0;
					while(listeVoisins[j] != '\0'){	
						if( listeVoisins[j] == '('){
							int voisin = 0;
							if(listeVoisins[j+3]  != '/'){
							   char v[5];
							   v[0] = '\0';
							   strcat(v,&listeVoisins[j+2]);
							   strcat(v,&listeVoisins[j+3]);
							   voisin = atoi(v);
							}
							else{
								voisin = atoi(&listeVoisins[j+2]);
							}
							int poidsVoisin = 0;
							if(listeVoisins[j+5]  != ' '){
							   char pv[5];
							   pv[0] = '\0';
							   strcat(pv,&listeVoisins[j+4]);
							   strcat(pv,&listeVoisins[j+5]);
							   
							   poidsVoisin = atoi(pv);
							}
							else{
								poidsVoisin = atoi(&listeVoisins[j+4]);
							}
							listeVoisin = updateListeVoisins(listeVoisin, voisin, poidsVoisin);
						}
						j++;
					}
					if(listeVoisins[j] == '\0'){
						listeVoisin = updateListeVoisins(listeVoisin, -1, 0);
					}
					free(listeVoisins);
					listeVoisins = NULL;
				}
				i++;
				int j = (i-6);
				if(j > -1){
					AjoutListeVoisinsAuGraphe(listeVoisin,graphe,(j));
				}
		  }
		  
		}
		fclose(fichier);
		free(cheminAndFichier);
		return graphe;
	}
	
	TypGraphe *ajoutSommetAuGraphe(TypGraphe *graphe){
		
		TypGraphe *tmp_graphe = malloc(sizeof(TypGraphe));
		tmp_graphe = graphe;
		int nbMaxSommets = tmp_graphe->nbMaxSommets;
		
		int i, j = 0;
		for(i=nbMaxSommets; i<(nbMaxSommets+1); i++){
			
			ListVoisin *listeVoisin = initListeVoisins();	
			int nbMaxVoisins = 0;
			printf("\n\nAjout du sommet  %d", (i+1));
			printf("\nBien vouloir saisir le nombre des voisins du sommet %d :  ",(i+1));
			scanf("%d", &nbMaxVoisins);
			if(nbMaxVoisins == 0){
				
				listeVoisin = updateListeVoisins(listeVoisin, 0, 0);	
			}
			else{
				
				for(j=0; j < nbMaxVoisins; j++){		
					int voisin = 0;
					int poidsVoisin = 0;
					printf("\nBien vouloir saisir le voisin %d du sommet courant %d :  " ,(j+1),(i+1));
					scanf("%d", &voisin);
					printf("\nBien vouloir saisir le poids du voisin %d du sommet courant %d :  " ,(j+1),(i+1));
					scanf("%d", &poidsVoisin);
					printf("\n");
					listeVoisin = updateListeVoisins(listeVoisin, voisin, poidsVoisin);
					if( (j+1) == nbMaxVoisins ){
						listeVoisin = updateListeVoisins(listeVoisin, -1, 0);	
					}
					printf("\n");		
				}
			}
			AjoutListeVoisinsAuGraphe(listeVoisin,tmp_graphe,i);  
		}
		tmp_graphe->nbMaxSommets = nbMaxSommets+1;
		return 	tmp_graphe;
	}
	
	TypGraphe *ajoutAreteAuGraphe(TypGraphe *graphe, int sommet, int position){
		
		
		TypGraphe *tmp_graphe = malloc(sizeof(TypGraphe));
		
		tmp_graphe = graphe;
		int j = 0;
		    
		    ListVoisin *listeVoisin = initListeVoisins();
			
			while( tmp_graphe->listesAdjacences[sommet-1][j]->voisin > 0 ){	
				
				int voisin = tmp_graphe->listesAdjacences[sommet-1][j]->voisin;
				int poidsVoisin = tmp_graphe->listesAdjacences[sommet-1][j]->poidsVoisin;
				listeVoisin = updateListeVoisins(listeVoisin, voisin, poidsVoisin);
				
				if(graphe->listesAdjacences[sommet-1][j+1]->voisin < 0){
						
					int new_voisin = 0;
					int new_poidsVoisin = 0;
					printf("\nBien vouloir saisir le voisin de l'arete : ");
					scanf("%d", &new_voisin);
					printf("\nBien vouloir saisir le poids de l'arete du voisin  : ");
					scanf("%d", &new_poidsVoisin);
					listeVoisin = addVoisin(listeVoisin, new_voisin, new_poidsVoisin, position);
						
					int voisin_fin = graphe->listesAdjacences[sommet-1][j+1]->voisin;
					int poidsVoisin_fin = graphe->listesAdjacences[sommet-1][j+1]->poidsVoisin;
					listeVoisin = updateListeVoisins(listeVoisin, voisin_fin, poidsVoisin_fin);
				}
				j++;
			}
			afficherListeVoisins(listeVoisin);
			AjoutListeVoisinsAuGraphe(listeVoisin,tmp_graphe,sommet-1);
			free(listeVoisin);  
		
		return 	tmp_graphe;
	}
	
	
	
	TypGraphe *supprimerAreteDuGraphe(TypGraphe *graphe, int sommet)
	{
	
		TypGraphe *tmp_graphe = malloc(sizeof(TypGraphe));
		tmp_graphe = graphe;
		int j = 0;
		    
		ListVoisin *listeVoisin = initListeVoisins();
		while( tmp_graphe->listesAdjacences[sommet-1][j]->voisin > 0 ){	
			
			int voisin = tmp_graphe->listesAdjacences[sommet-1][j]->voisin;
			int poidsVoisin = tmp_graphe->listesAdjacences[sommet-1][j]->poidsVoisin;
			listeVoisin = updateListeVoisins(listeVoisin, voisin, poidsVoisin);
			
			if(graphe->listesAdjacences[sommet-1][j+1]->voisin < 0){
					
				int voisin_fin = graphe->listesAdjacences[sommet-1][j+1]->voisin;
				int poidsVoisin_fin = graphe->listesAdjacences[sommet-1][j+1]->poidsVoisin;
				listeVoisin = updateListeVoisins(listeVoisin, voisin_fin, poidsVoisin_fin);
			}
			j++;
		}
		
		int new_voisin = 0;
		printf("\nBien vouloir saisir le voisin (sommet) de l'arete a supprimer : ");
		scanf("%d", &new_voisin);
		listeVoisin = removeVoisin(listeVoisin, new_voisin);	
		AjoutListeVoisinsAuGraphe(listeVoisin,tmp_graphe,sommet-1);
		free(listeVoisin);
		
		return 	tmp_graphe;
    }
	
	TypGraphe *supprimerSommetDuGraphe(TypGraphe *graphe, int sommet)
	{
	
		TypGraphe *tmp_graphe = malloc(sizeof(TypGraphe));
		tmp_graphe = graphe;
		int j = 0;
		int nbMaxSommets =  graphe->nbMaxSommets;   
		int i = 0;
		while( i<nbMaxSommets ){
		
			ListVoisin *listeVoisin = initListeVoisins();
			while( tmp_graphe->listesAdjacences[i][j]->voisin > 0 && i != (sommet-1)){	
				
				int voisin = tmp_graphe->listesAdjacences[i][j]->voisin;
				int poidsVoisin = tmp_graphe->listesAdjacences[i][j]->poidsVoisin;
				listeVoisin = updateListeVoisins(listeVoisin, voisin, poidsVoisin);
				
				if(graphe->listesAdjacences[i][j+1]->voisin < 0){
						
					int voisin_fin = graphe->listesAdjacences[i][j+1]->voisin;
					int poidsVoisin_fin = graphe->listesAdjacences[i][j+1]->poidsVoisin;
					listeVoisin = updateListeVoisins(listeVoisin, voisin_fin, poidsVoisin_fin);
				}
				j++;
			}
			listeVoisin = removeVoisin(listeVoisin, sommet);
			afficherListeVoisins(listeVoisin);
			if(sommet != i){
					
				AjoutListeVoisinsAuGraphe(listeVoisin,tmp_graphe,i);
			}
			free(listeVoisin);
			i++;
		}
		return 	tmp_graphe;
    }
    
	void AjoutListeVoisinsAuGraphe(ListVoisin *listeVoisin, TypGraphe *graphe, int iemeSommet ){
		
		if( listeVoisin != NULL ){
			
			struct TypVoisin *voisin_bkp = listeVoisin->voisinEnDebutDeListe;
			int j=0;
			while( voisin_bkp != NULL ){
			
				 graphe->listesAdjacences[iemeSommet][j] = voisin_bkp;
				 voisin_bkp = voisin_bkp->voisinSuivant; 
				 j++;
			}
			
		}
	
	}
	
	
	
	int grapheEstOriente(TypGraphe *graphe){
		
		  int i = 0;
		  int estOriente = 0;
		  for(i=0; i < graphe->nbMaxSommets; i++){
			int j = 0;
			while( graphe->listesAdjacences[i][j]->voisin > 0 ){
				
				int voisin = graphe->listesAdjacences[i][j]->voisin;
				int k=0;
				while(graphe->listesAdjacences[voisin-1][k]->voisin > 0){
				
					if( graphe->listesAdjacences[voisin-1][k]->voisin == (i+1)){
					
						estOriente++;
					}
					k++;
				}
				
				j++;
				
			}
				
		 }
		 
		 return estOriente;
	
	}
	
	void affichageGrapheSaisi(TypGraphe *graphe){
		
		  printf ("#  nombre maximum des sommets\n");
		  printf ("%d\n", graphe->nbMaxSommets);
		  printf ("#  oriente\n");
		  printf ("%d\n", graphe->estOriente);
		  printf ("#  sommets   :  voisins\n");
		  int i = 0;
		  for(i=0; i < graphe->nbMaxSommets; i++){
			printf ("\n%d  :  ", (i+1));
			int j = 0;
			while( graphe->listesAdjacences[i][j]->voisin > 0 ){
		
				if(graphe->listesAdjacences[i][j+1]->voisin < 0){
					printf ("( %d/%d )",graphe->listesAdjacences[i][j]->voisin
					                     ,graphe->listesAdjacences[i][j]->poidsVoisin );
				}
				else{
					printf ("( %d/%d ),",graphe->listesAdjacences[i][j]->voisin
					                    ,graphe->listesAdjacences[i][j]->poidsVoisin );
				}
				
				j++;
				
			}	
		 }
	}
	
	void stockerGrapheEnFichierS( TypGraphe *graphe, char nomFichierGraphe[], int sommet){
	   
	   char cheminAndFichier[20];
	   cheminAndFichier[0] = '\0';
	   strcat(cheminAndFichier,"obj/");
	   strcat(cheminAndFichier,nomFichierGraphe);
	   FILE *fichier = fopen (cheminAndFichier, "a");
	   if (fichier != NULL){
			  fprintf (fichier, "#  nombre maximum des sommets\n");
			  fprintf (fichier, "%d\n", graphe->nbMaxSommets);
			  fprintf (fichier, "#  oriente\n");
			  fprintf (fichier, "%d\n", graphe->estOriente);
			  fprintf (fichier, "#  sommets   :  voisins\n");
			  int i;
			  for(i=0; i < graphe->nbMaxSommets; i++){
					
					if(i != sommet){
					
							fprintf (fichier, "%d  :  ", (i+1));
							int j = 0;
							while( graphe->listesAdjacences[i][j]->voisin > 0 ){
						
								if(graphe->listesAdjacences[i][j+1]->voisin < 0){
									
									fprintf (fichier,"( %d/%d )",graphe->listesAdjacences[i][j]->voisin
																 ,graphe->listesAdjacences[i][j]->poidsVoisin );
								}
								else{
									fprintf (fichier,"( %d/%d ),",graphe->listesAdjacences[i][j]->voisin
																  ,graphe->listesAdjacences[i][j]->poidsVoisin );
								}
								j++;
							}
							fprintf (fichier, "\n");
					}
			 }
			 fclose (fichier);
	   }
	   else{
			printf("\nProbleme");
		}
	}
	
	
	
	void stockerGrapheEnFichier( TypGraphe *graphe, char nomFichierGraphe[]){
	   char cheminAndFichier[20];
	   cheminAndFichier[0] = '\0';
	   strcat(cheminAndFichier,"obj/");
	   strcat(cheminAndFichier,nomFichierGraphe);
	   FILE *fichier = fopen (cheminAndFichier, "a");
	   if (fichier != NULL){
			  fprintf (fichier, "#  nombre maximum des sommets\n");
			  fprintf (fichier, "%d\n", graphe->nbMaxSommets);
			  fprintf (fichier, "#  oriente\n");
			  fprintf (fichier, "%d\n", graphe->estOriente);
			  fprintf (fichier, "#  sommets   :  voisins\n");
			  int i;
			  for(i=0; i < graphe->nbMaxSommets; i++){
					fprintf (fichier, "%d  :  ", (i+1));
					int j = 0;
					while( graphe->listesAdjacences[i][j]->voisin > 0 ){
				
						if(graphe->listesAdjacences[i][j+1]->voisin < 0){
							
							fprintf (fichier,"( %d/%d )",graphe->listesAdjacences[i][j]->voisin
							                             ,graphe->listesAdjacences[i][j]->poidsVoisin );
						}
						else{
							fprintf (fichier,"( %d/%d ),",graphe->listesAdjacences[i][j]->voisin
							                              ,graphe->listesAdjacences[i][j]->poidsVoisin );
						}
						j++;
					}
					fprintf (fichier, "\n");
			 }
			 fclose (fichier);
	   }
	   else{
			printf("\nProbleme");
		}
	}
	
	
	char *selectionFichierGraphe(int choix){
	
		DIR *rep = NULL;
		rep = opendir("obj/");
		char * p_fichierAlire = malloc(sizeof(char) * 15);
		p_fichierAlire[0] = '\0';
		struct dirent* fichierLu = NULL;
		
		if(rep == NULL){	
			printf("\n Impossible d'ouvrir le fichier");
		}
		else{
			int count=0;
			while((fichierLu = readdir(rep)) ){
				
					if ( !strcmp(fichierLu->d_name, ".") || !strcmp(fichierLu->d_name, "..") ){}
					else{
						count++;
						if(count == choix){
							
							strcat(p_fichierAlire,(char*)fichierLu->d_name);
							break;	
						}
					}		
			}
		
		}
		closedir(rep);
		return p_fichierAlire;
	}
	
	void lireGrapheFromFichier(char *p_fichierAlire){
	    
		FILE * fichier;
		char ligne_lue[512];
		char dirObj[] = "obj/";
		char *cheminAndFichier = malloc(sizeof(char) * 20);
	   	cheminAndFichier[0] = '\0';
	    strcat(cheminAndFichier,dirObj);
	    strcat(cheminAndFichier,p_fichierAlire);
		fichier = fopen(cheminAndFichier, "r");
		int nbLigne = 0;
		if(fichier != NULL){
			
		  while(fgets(ligne_lue, 512, fichier) != NULL){
			printf("\t%s", ligne_lue);
			nbLigne++;
		  }
		 
		}
		fclose(fichier);
		free(cheminAndFichier);
	}
	
	int nbrLigneGrapheFromFichier(char *p_fichierAlire){
	    
		FILE * fichier;
		char ligne_lue[512];
		char dirObj[] = "obj/";
		char *cheminAndFichier = malloc(sizeof(char) * 20);
	   	cheminAndFichier[0] = '\0';
	    strcat(cheminAndFichier,dirObj);
	    strcat(cheminAndFichier,p_fichierAlire);
		fichier = fopen(cheminAndFichier, "r");
		int nbLigne = 0;
		if(fichier != NULL){
			
		  while(fgets(ligne_lue, 512, fichier) != NULL){
			//printf("\t%s", ligne_lue);
			nbLigne++;
		  }
		 
		}
		fclose(fichier);
		free(cheminAndFichier);
		return nbLigne;
	}
	
	
	
	
	int nombreGrapheSaved(){
	
		DIR *rep = NULL;
		rep = opendir("obj/");
		int nbFichier = 0;
		struct dirent* fichierLu = NULL;
		
		if(rep != NULL){
			
			while((fichierLu = readdir(rep)) != NULL){
					if ( !strcmp(fichierLu->d_name, ".") || !strcmp(fichierLu->d_name, "..") )
					{}
					else{
						nbFichier++;				
					}
			}
			
		}
		closedir(rep);
		return nbFichier;
	}
	
	void aficherGrapheSaved(){
	
		DIR *rep = NULL;
		rep = opendir("obj/");
		struct dirent* fichierLu = NULL;
		char *p_fichierAlire = malloc(sizeof(char) * 15);
		if(rep != NULL){
			int i=0;
			while((fichierLu = readdir(rep)) != NULL){
				
					if ( !strcmp(fichierLu->d_name, ".") || !strcmp(fichierLu->d_name, "..") )
					{}
					else{
						
						p_fichierAlire = strdup(fichierLu->d_name);
						printf("%d. %s\n", ++i, p_fichierAlire);
					
					}
					
			}
			
		}
		closedir(rep);
	}
	
