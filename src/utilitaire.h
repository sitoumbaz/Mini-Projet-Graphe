	#ifndef UTILITAIRE_H
	#define UTILITAIRE_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <dirent.h> 
	#ifndef WIN32
		#include <sys/types.h>
	#endif
	#include "lliste.h"
	#include "lgraphe.h"
		void processCreationGraphe();
		void processAjoutSommet();
		void processLectureGraphe();
		void processAjoutArete();
		void processSuppressionSommet();
		void processSuppressionArrete();
		void questionSaveFichier(TypGraphe *graphe, char *p_fichierAlire);
		extern void quitter(void);
	#endif
