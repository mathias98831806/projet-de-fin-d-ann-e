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
#include "arithme.h"

int euclide(int number1, int number2)
{
	if (number1%number2==0)
		return number2;
	else
		return euclide(number2, number1%b);
}

int euclidePPCM(int number1, int number2)
{
	int pgcd = euclide(number1, number2);
	int ppcm = (number1*number2)/pgcd;
	return ppcm;
}

void extendEuclide(int a, int b, int* bezout)
{
	int x = 1, xx = 0;
	int y = 0, yy = 1;
	int q = 0;
	while(b!=0)
	{
		q = a/b;
		a = b;
		b = a%b;
		xx = x - q*xx;
		x = xx;
		yy = y - q*yy;
		y = yy;

	}
	bezout[0] = a;
	bezout[1] = x;
	bezout[2] = y;
}

int isFirst(int number)
{
	int trouve = 1;
	if (number == 2)
		return trouve;
	else
		for (int i=2; i<=(int) sqrt(number); i++)
		{
			if (number%i == 0)
			{
				trouve = 0;
				break;
			}
		}
		return trouve;
}


int firstGenerator(int limit)
{
	
	printf("La liste des nombres premiers de 0 à %d est : ", limit);
	for (int i=2; i<=limit; i++)
	{
		if (isFirst(i))
			printf("%d\t", i);
	}

}

