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


#include <stdlib.h>


void polynomeEnregistror(float* polynome, int degree)
{
	// Création de notre incrément
	int i;
	// On crée une boucle nous permettant de récuperer les coefficients
	printf("Registration of coefficients\n");
	for(i=0; i<degree; i++)
	{
		printf("Please enter the coeffient a[%d] : ",i);
		scanf("%f", &polynome[i]);
	}
	printf("Thank for your comprehension !!!\n");

}


float polynomeEvalutor(float* polynome, float x, int degree) 
{
	// Création de notre incrément
	int i;
	// Création de l'évaluateur
	float value=1;
	// Création la boucle d'évaluation du polynome
	if (degree == 1)
		return polynome[0];
	else
	{
		for(i=0; i<degree-1; i++)
		{
			value = value*polynome[i] + polynome[i+1];
		}

	}
	
	return value;
}