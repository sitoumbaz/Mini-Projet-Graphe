
	/*
	**********************************************************
	*
	* Programme : menu.c
	*
	* ecrit par : NTUMBA W. Patient et LOTOY B. Vianney
	*
	* resume : Gestion de l'affichage des menus 
	*
	* date : 12/10/2014
	*
	***********************************************************
	*/

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "menu.h"
	#include "utilitaire.h"

	void menuChoisi(int choixMenu){
		
			int nbFichier = nombreGrapheSaved();
			if(nbFichier > 0){
				
				switch ( choixMenu )
				{
					case 1:
						printf("********************** \n");
						printf("* Creation du graphe *\n");
						printf("********************** \n");
						processCreationGraphe();
						break;
					case 2:
						printf("******************\n");
						printf("* Lecture graphe *\n");
						printf("******************\n");
						processLectureGraphe();
						break;
					case 3:
						printf("***********************************\n");
						printf("* Insertion d'un sommet au graphe *\n");
						printf("***********************************\n");
						processAjoutSommet();
						break;
					case 4:
						printf("************************************\n");
						printf("* Insertion d'une arete au graphe *\n");
						printf("************************************\n");
						processAjoutArete();
						break;

					case 5:
						printf("*************************************\n");
						printf("* Suppression de sommet d'un graphe *\n");
						printf("*************************************\n");
						processSuppressionSommet();
						break;
						
					case 6:
						printf("************************************\n");
						printf("* Suppression d'arrete d'un graphe *\n");
						printf("************************************\n");
						processSuppressionArrete();
						break;

					case 7:
						
						printf("***********\n");
						printf("* Quitter *\n");
						printf("***********\n");
						quitter();
						break;

					default:
						printf("************************\n");
						printf("* Faites le bon choix! *\n");
						printf("************************\n");
						break;
				}
			
			}
			else{
				
				
				switch ( choixMenu )
				{
					case 1:
						printf("********************** \n");
						printf("* Creation du graphe *\n");
						printf("********************** \n");
						processCreationGraphe();
						break;
					case 2:
						printf("***********\n");
						printf("* Quitter *\n");
						printf("***********\n");
						quitter();
							
							
						break;

					default:
						printf("************************\n");
						printf("* Faites le bon choix! *\n");
						printf("************************\n");
						break;
				}
			
			}
			 
	}

	int affichageMenu()
	{
		int nbFichier = nombreGrapheSaved();
		if(nbFichier > 0){
			int choixMenu;
			printf("\n\n-----Menu Principale du programme-----\n\n");
			printf("1. Creation du graphe\n");
			printf("2. Lecture graphe\n");
			printf("3. Insertion d'un sommet au graphe\n");
			printf("4. Insertion d'une arrete au graphe\n");
			printf("5. Suppression de sommet d'un graphe\n");
			printf("6. Suppression d'arrete d'un graphe\n");
			printf("7. Quitter le programme\n");
			printf("\nFaites votre choix : ");
			scanf("%d", &choixMenu);
			return choixMenu;
		}else{
		
			int choixMenu;
			printf("\n\n-----Menu Principale du programme-----\n");
			printf("1. Creation du graphe\n");
			printf("2. Quitter le programme\n");
			printf("\nFaites votre choix : ");
			scanf("%d", &choixMenu);
			return choixMenu;
			
		}
	}


