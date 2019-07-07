/*[
 * Copyright 1986 - 1993, 1998, 2004   Thomas Williams, Colin Kelley
 *
 * Permission to use, copy, and distribute this software and its
 * documentation for any purpose with or without fee is hereby granted,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.
 *
 * Permission to modify the software is granted, but not the right to
 * distribute the complete modified source code.  Modifications are to
 * be distributed as patches to the released version.  Permission to
 * distribute binaries produced by compiling modified sources is granted,
 * provided you
 *   1. distribute the corresponding source modifications from the
 *    released version in the form of a patch file along with the binaries,
 *   2. add special version identification to distinguish your version
 *    in addition to the base release version number,
 *   3. provide your name and address as the primary contact for the
 *    support of your modified version, and
 *   4. retain our contact information in regard to use of the base
 *    software.
 * Permission to distribute the released version of the source code along
 * with corresponding source modifications in the form of a patch file is
 * granted with same provisions 2 through 4 for binary distributions.
 *
 * This software is provided "as is" without express or implied warranty
 * to the extent permitted by applicable law.
]*/

/*
 * AUTHORS
 *
 * KALIPE Kossi Mathias
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "matrice_biblio.h"
#include "fonction_biblio.h"
#include "errorPrinter.h"
#include "arithme.h"

static int matriceSubmenu()
{
	// Cette fonction affiche le menu des matrices et permet que tout fonctionne bien
	int* answer = NULL;
	int* n = NULL, p = NULL;
	int exit = 0;

	while (!exit)
	{
		// Boucle principale de ce sous menu
		// On affiche le menu
		printf("1) Faire l'addition de deux matrices\n");
		printf("2) Calculer le déterminant d'une matrice carrée de dimension infinie\n");
		printf("3) Faire la multiplication de deux ou n matrices simultanément\n");
		printf("4) Mettre une matrice sous sa forme échelonnée\n");
		printf("5) Transposer une matrice\n");
		printf("6) Retourner au menu principal\n");
		printf("7) Quitter le programme\n");
		getInt(anwser, "Veuillez saisir une réponse");
		switch(*anwser)
			case 1
			{
				get2Int(n, p, "Veuillez saisir le nombre de lignes et de colonnes de la première matrice");
				float array1[ROWS][COLUMNS];
				float array2[ROWS][COLUMNS];
				float array3[ROWS][COLUMNS];
				getArray(array1, *n, *p);
				getArray(array2, *n, *p);
				addArray(array1, array2, array3);
				displayArray(array3, *n, *p);
				break;
			}
			case 2
			{
				getInt(n, "Veuillez saisir la dimension de la matrice");
				float array[ROWS][COLUMNS];
				getArray(array, *n, *n);
				float value = determinant(array, *n);
				printf("Le déterminant de la matrice saisie est %.3f\n", value);
				break;
			}
			case 3
			{
				int* n1, p1, n2, p2;
				get2Int(n1, p1, "Veuillez saisir le nombre de lignes et de colonnes de la première matrice");
				get2Int(n2, p2, "Veuillez saisir le nombre de lignes et de colonnes de la seconde matrice");	
				float array1[ROWS][COLUMNS];
				float array2[ROWS][COLUMNS];
				float array3[ROWS][COLUMNS];
				getArray(array1, *n1, *p1);
				getArray(array2, *n2, *p2);
				multiplyArray(array1, array2, array3, *n1, *p1, *n2, *p2);
				displayArray(array3, *n1, *p2);
				break;
			}
			case 4
			{
			int* n, p;
				get2Int(n, p, "Veuillez saisir le nombre de lignes et de colonnes de la matrice");
				float array[ROWS][COLUMNS];
				getArray(array, *n, *p);
				gradeArray(array, *n, *p);
				displayArray(array; *n, *p);		
				break;
			}

			case 5
			{
				int* n, p;
				get2Int(n, p, "Veuillez saisir le nombre de lignes et de colonnes de la matrice");
				float array[ROWS][COLUMNS];
				getArray(array, *n, *p);
				transpose(array, *n, *p);
				displayArray(array, *n, *p);
				break;
			}

			case 6
			{
				exit = 1;
				break;
			}
			case 7
			{
				exit = 1;
				break;
			}
			
	}
	return *answer;
}

static int arithmeSubmenu()
{
	int* answer, n, p;
	int exit = 0;
	while(!exit)
	{
		printf("1) Calculer le PGCD de deux entiers\n");
		printf("2) Calculer le PPCM de deux entiers\n");
		printf("3) Resoudre une équation diophantienne\n");
		printf("4) Déterminer les coefficients de bezout\n");
		printf("5) Générer des nombres premiers\n");
		printf("6) Retourner au menu principal\n");
		printf("7) Quitter le programme\n");
		getInt(answer, "Veuillez saisir une réponse");
		switch(*answer)
			case 1
			{
				get2Int(n, p, "Veuillez sasir deux entiers en les séparant par un espace");
				int pgcd = euclide(*n, *p);
				printf("Le pgcd de %d et de %d est %d", *n, *p, pgcd);
				break;
			}
			case 2
			{
				get2Int(n, p, "Veuillez sasir deux entiers en les séparant par un espace");
				int ppcm = PPCM(*n, *p);
				printf("Le ppcm de %d et de %d est %d", *n,*p, ppcm);
				break;
			}
			case 3
			{
				// get3Int(n, p, q, "Veuillez saisir les coefficients de votre équation diophantienne en les séparant par un espace");
				// int* result diophantienne(*n, *p, *q);
				// if (result)
				// 	for (int i=0; i<2; i++)
				// 		// print("")
				break;
			}	
			case 4
			{
				get2Int(n, p, "Veuillez saisir les deux entiers en les séparant par un espace");
				int coefficients[2];
				extendEuclide(*n, *p, coefficients);
				printf("Les coefficients u et v sont: %d %d", coefficients[0], coefficients[1]); 
				break;
			}
			case 5
			{
				getInt(n, "Veuillez saisir le nombre de nombre premiers à générer");
				firstGenerator(*n);
				break;
			}
			case 6
			{
				exit = 1;
				break;
			}
			case 7
			{
				exit = 1;
				break;
			}
	}
	return *answer;
}

static int fonctionSubmenu()
{
	debut:
	int* answer = NULL;
	int exit = 0;
	int* n, x;
	// On demande à l'utilisateur de saisir le degré du polynome qu'il veut traiter
	getInt(n, "Veuillez saisir le degré de votre polynome");
	if (nombre)
		float* polynome = malloc(size_of(int)*(n+1)); // On alloue dynamiquement l'espace memoire
		polynomeEnregistror(polynome, *n); // On demande à l'utilisateur de saisir les coefficients de son polynome
	else
		goto debut;
	while (!exit)
	{
		printf("1) Evaluer un polynome\n");
		printf("2) Afficher la courbe du polynome\n");
		printf("3) Chercher les zeros du polynome\n");
		printf("4) Retourner au menu principal\n");
		printf("5) Quitter le programme\n");

		choix:
			getInt(*answer, "Veuillez faire un choix");
		if (! (1 <= *answer && answer <= 3))
			goto choix;
		switch (* answer)
			case 1
			{
				getFloat(x, "Veuillez saisir le x");
				polynomeEvaluator(polynome, *x, *n); // On evalue le polynome grace à l'algorithme de horner
				break;
			}
			case 2
			{
				drawPolynome(polynome, *n);
				break;
			}
			case 3
			{
				zeroFinder(polynome, *n);
				break;
			}
			case 4
			{
				exit = 1;
				break;
			}
			case 5
			{
				exit = 1;
				break;
			}
	}
	return *answer;
}


int launchMatlab()
{
	// C'est cette fonction qui permettra à mon matlab de se demarrer
	// On démarre le polynomeLab
	// Après le arithmeticLab
	// Et après le matriceLab
	int* answer = NULL;
	int exit = 0, subAnswer = 0;
	choix:
	printf("1) Démarrer le polynomeLab\n");
	printf("2) Démarrer le arithmeticLab\n");
	printf("3) Démarrer le matriceLab\n");
	printf("4) Aller au menu principal\n");
	printf("5) Quitter le programme\n");
	getInt(answer, "Veuillez saisir une réponse");
	if (! (1 <= *answer && answer <= 5))
		goto choix;
	while(! exit)
	{
		switch (*answer)
			case 1
			{
				subAnswer = fonctionSubmenu();
				break;
			}

			case 2
			{
				subAnswer = arithmeSubmenu();
				break;
			}

			case 3
			{
				subAnswer = matriceSubmenu();
				break;
			}

			case 4
			{
				exit = 1;
				break;
			}

			case 5
			{
				exit = 1;
				break;
			}

			if (subAnswer == 6 || subAnswer == 4)
				break;
			else
				break;
				
	}
	if (subAnswer == 6 || subAnswer == 4)
		goto choix;
	return *answer;
	
}