
	/*
	**********************************************************
	*
	* Programme : utilitaire.c
	*
	* ecrit par : NTUMBA W. Patient et LOTOY B. Vianney
	*
	* resume : Gestion des fonction qui gere les different cas
	*          du menu
	*
	* date : 12/10/2014
	*
	***********************************************************
	*/
	
	#include "utilitaire.h"
	
	
	void quitter ()
	{

		printf ( "\nAu revoir et a bientot!...\n\n" );
		exit(0);

	}
	
	void questionSaveFichier(TypGraphe *graphe, char *p_fichierAlire){
			
			if(p_fichierAlire == NULL){
				
				int saveGraphe;
				printf("\n\nVoulez-vous sauvegarder ce graphe dans un fichier ? 1 pour Oui et 0 pour non : ");
				scanf("%d", &saveGraphe);
				if(saveGraphe == 1){
					char nomFichierGraphe[15];
					nomFichierGraphe[15] = '\0';
					printf("\nBien vouloir saisir le nom du fihier avec extention .txt, pas plus de 12 caracteres : ");
					scanf("%12s",nomFichierGraphe);
					stockerGrapheEnFichier(graphe, nomFichierGraphe);
				}
			
			}else{
				
			   char cheminAndFichier[20];
			   cheminAndFichier[0] = '\0';
			   strcat(cheminAndFichier,"obj/");
			   strcat(cheminAndFichier,p_fichierAlire);
			   FILE *fichier = fopen (cheminAndFichier, "a");
			   if(fichier != NULL){
					
					remove(cheminAndFichier);
			   }
			   fclose(fichier);
			   stockerGrapheEnFichier(graphe, p_fichierAlire);
				
			}
					
				
				
	}
	
	
	void processCreationGraphe(){
		
		int nbMaxSommets = 0;
		int estOriente = 0;
		int grapheSiOriente;
		printf("Saisir nombre maximun des sommets du graphe : ");
		scanf("%d", &nbMaxSommets);
		printf("\nSi le graphe est oriente saisir 1, si non saisir 0 : ");
		scanf("%d", &estOriente);
		
		if((estOriente == 1 || estOriente == 0) && nbMaxSommets > 0){
			TypGraphe *grapheC = remplissageGrapheManuel(estOriente,nbMaxSommets);
			printf("\n");
			affichageGrapheSaisi(grapheC);
			grapheSiOriente = grapheEstOriente(grapheC);
			if( (grapheC->estOriente == 0 && ( grapheSiOriente > 0 || grapheSiOriente == 0 ) )||
				(grapheC->estOriente == 1 && grapheSiOriente == 0 ) ){
				char *p_fichierAlireC;
				p_fichierAlireC = NULL;	
				questionSaveFichier(grapheC, p_fichierAlireC);
			}
			else{
				if( grapheC->estOriente == 1 && grapheSiOriente > 0 ){
					printf("\nVotre graphe n'est pas oriente, bien vouloir reprendre l'operation \n");
				}
			}
		}else{
			printf("\nBien vouloir verifier le nombre des sommtes ou si le graphe est oriente ou pas \n");
		}
		/*free(p_fichierAlireC);
		free(grapheC);*/
	}
	
	
	void processAjoutSommet(){
		
		aficherGrapheSaved();
		int choixInsertS =0;
		printf("\nFaites le choix du fichier de travail : ");
		scanf("%d",&choixInsertS);	
		printf("\n\n");
		char *fichierInsertS = malloc(sizeof(char) * 15);
		int nbLigne = 0;
		fichierInsertS[0] = '\0';
		strcat(fichierInsertS,selectionFichierGraphe(choixInsertS));
		char fichierATraiter[15];
		fichierATraiter[0] = '\0';
		strcat(fichierATraiter,fichierInsertS);
		nbLigne = nbrLigneGrapheFromFichier(fichierInsertS);
		TypGraphe *graphe = remplissageGrapheAutomatic(fichierInsertS, nbLigne);
		printf("\n\n\nGraphe généré\n");
		affichageGrapheSaisi(graphe);
		free(fichierInsertS);
		TypGraphe *grapheUpdate = ajoutSommetAuGraphe(graphe);
		affichageGrapheSaisi(grapheUpdate);
		questionSaveFichier(grapheUpdate, fichierATraiter);
		printf("\n");
		free(fichierInsertS);
		free(graphe);
		free(grapheUpdate);
	
	}
	
	void processLectureGraphe(){
		
		aficherGrapheSaved();
		int choixLecture =0;
		printf("\nFaites le choix du fichier a lire : ");
		scanf("%d",&choixLecture);	
		printf("\n\n");
		char *fichierLecture = malloc(sizeof(char) * 15);
		fichierLecture = selectionFichierGraphe(choixLecture);
		lireGrapheFromFichier(fichierLecture);
		free(fichierLecture);
		printf("\n\n");

	}
	
	void processAjoutArete(){
	
		aficherGrapheSaved();
		int choixInsertA =0;
		int saisiSommet = 0;
		int saisiPosition = 0;
		int valideSaisi = 0;
		printf("\nFaites le choix du fichier de travail : ");
		scanf("%d",&choixInsertA);	
		char *fichierInsertS = malloc(sizeof(char) * 15);
		int nbLigne = 0;
		fichierInsertS[0] = '\0';
		strcat(fichierInsertS,selectionFichierGraphe(choixInsertA));
		char fichierATraiter[15];
		fichierATraiter[0] = '\0';
		strcat(fichierATraiter,fichierInsertS);
		nbLigne = nbrLigneGrapheFromFichier(fichierInsertS);
		TypGraphe *graphe = remplissageGrapheAutomatic(fichierInsertS, nbLigne);
		affichageGrapheSaisi(graphe);
		while(valideSaisi == 0){
					
			printf("\nBien vouloir saisir le sommet : ");
			scanf("%d",&saisiSommet);	
			printf("\nBien vouloir saisir le position : ");
			scanf("%d",&saisiPosition);	
			printf("\nVotre arete sera insere a la liste des vosins du sommet %d ",saisiSommet);
			printf(" a la position %d ",saisiPosition);
			printf("\nSaisir 1 si vous etes d'accord si non 0 : ");
			scanf("%d",&valideSaisi);
		}
		TypGraphe *grapheUpdate = ajoutAreteAuGraphe(graphe, saisiSommet, saisiPosition);
		affichageGrapheSaisi(grapheUpdate);
		questionSaveFichier(grapheUpdate, fichierATraiter);
		printf("\n");
		free(fichierInsertS);
		free(graphe);
		free(grapheUpdate);
		
		
	}
	
	void processSuppressionArrete(){
	
		int saisiSommet = 0;
		int valideSaisi = 0;
		aficherGrapheSaved();
		int choixRemoveA =0;
		printf("\nFaites le choix du fichier de travail : ");
		scanf("%d",&choixRemoveA);	
		printf("\n");
		char *fichierInsertSup = malloc(sizeof(char) * 15);
		int nbLigneSup = 0;
		fichierInsertSup[0] = '\0';
		strcat(fichierInsertSup,selectionFichierGraphe(choixRemoveA));
		char fichierATraiterSup[15];
		fichierATraiterSup[0] = '\0';
		strcat(fichierATraiterSup,fichierInsertSup);
		nbLigneSup = nbrLigneGrapheFromFichier(fichierInsertSup);
		TypGraphe *graphe = remplissageGrapheAutomatic(fichierInsertSup, nbLigneSup);
		affichageGrapheSaisi(graphe);
	    while(valideSaisi == 0){		
			
			printf("\nBien vouloir saisir le sommet : ");
			scanf("%d",&saisiSommet);	
			printf("\nLa suppression de l'arrete se portera sur le sommet %d choisi ",saisiSommet);
			printf("\nSaisir 1 si vous etes d'accord si non 0 : ");
			scanf("%d",&valideSaisi);
		}
		TypGraphe *grapheUpdate = supprimerAreteDuGraphe(graphe,saisiSommet);	
		affichageGrapheSaisi(grapheUpdate);
		questionSaveFichier(grapheUpdate, fichierATraiterSup);
		free(fichierInsertSup);
		free(graphe);
		free(grapheUpdate);
	} 
	
	
	void processSuppressionSommet(){
	
		int saisiSommetR = 0;
		int valideSaisiR = 0;
		aficherGrapheSaved();
		int choixRemoveR =0;
		printf("\nFaites le choix du fichier de travail : ");
		scanf("%d",&choixRemoveR);	
		printf("\n");
		char *fichierInsertSup = malloc(sizeof(char) * 15);
		int nbLigneSup = 0;
		fichierInsertSup[0] = '\0';
		strcat(fichierInsertSup,selectionFichierGraphe(choixRemoveR));
		char fichierATraiterSup[15];
		fichierATraiterSup[0] = '\0';
		strcat(fichierATraiterSup,fichierInsertSup);
		nbLigneSup = nbrLigneGrapheFromFichier(fichierInsertSup);
		TypGraphe *grapheR = remplissageGrapheAutomatic(fichierInsertSup, nbLigneSup);
		affichageGrapheSaisi(grapheR);
	    while(valideSaisiR == 0){		
			
			printf("\nBien vouloir saisir le sommet : ");
			scanf("%d",&saisiSommetR);	
			printf("\nle sommet %d est le sommet a supprimer du graphe ",saisiSommetR);
			printf("\nSaisir 1 si vous etes d'accord si non 0 : ");
			scanf("%d",&valideSaisiR);
		}
		printf("\nLa mise a jour sera faite dans la prochaine release Merci de votre comprehension: ");
		/*TypGraphe *grapheUpdateR = supprimerSommetDuGraphe(grapheR,saisiSommetR);	
		affichageGrapheSaisi(grapheUpdateR);
		stockerGrapheEnFichierS(grapheUpdateR,fichierATraiterSup,saisiSommetR);
		free(fichierInsertSup);
		free(grapheR);
		free(grapheUpdateR);*/
		
	}
	
	
