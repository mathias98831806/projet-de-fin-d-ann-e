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
#include <errno.h>		
#include <stdlib.h>


// Ce module me permet de tester si les entrées de l'utilisateur sont valides ou pas et aussi de pouvoir afficher les erreurs
// En gros c'est ma version du bloc try except de python

void getInt(int* value, char* msg)
{
	// Cette fonction prend un pointeur sur la variable dans laquelle il faut
	// mettre la valeur saisie par l'utilisateur et le message de prompt
	printf("%s : ", msg);
	if(! scanf("%d", value))
	{
		printf("Veuillez saisir un entier.\n");
		getInt(value, msg);

	}
}

void getFloat(float* value, char* msg)
{
	// Cette fonction permet d'avoir de la part de l'utilisateur un réel en gérant les potentielles erreurs
	if(! scanf("%f", value))
	{
		printf("Veuillez saisir un réel.\n");
		getFloat(value, msg);
	}
}

void getString(char* value, char* msg)
{
	// Cette fonction permet de renvoyer en intégrant un gestionnaire d'erreur une chaine de caractère
	printf("%s\n", msg);
	if(! scanf("%20s", value)) // Si la chaine fournie par l'utilisateur dépasse 20
	{
		printf("Veuillez saisir une chaine ayant au plus 20 caractère.\n");
		getString(value, msg);
	}
}
