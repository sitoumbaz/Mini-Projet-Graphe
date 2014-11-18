
	/*
	**********************************************************
	*
	* Programme : main.c
	*
	* ecrit par : NTUMBA W. Patient et LOTOY B. Vianney
	*
	* resume : Fonction principal du Projet
	*
	* date : 12/10/2014
	*
	***********************************************************
	*/
	
	#include <stdio.h>
	#include <stdlib.h>
	#include "menu.h"

	int main(int argc, char **argv)
	{
		
		int choix = 0;
		
		do{
		
			choix = affichageMenu();
			menuChoisi(choix);
		
		}while(choix < 7);
		
		return 0;
	}

