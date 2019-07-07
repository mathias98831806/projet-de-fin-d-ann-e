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

void extendEuclide(long a, long b, long* bezout)
{
	long x = 1, xx = 0;
	long y = 0, yy = 1;
	long q = 0;
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

long rapidPow(long x, long k, long n)
{
	long pow = 1;
	while(k>0)
	{
		if (k%2 != 0)
			pow = (pow*x) %n;
		x = x*x %n;
		k = (long) k/2;
	}
	return pow;
}
int inverse(int a, int n)
{
	// Cette fonction calcule l'inverse de a modulo n
	long results[3];
	extendEuclide(a, n, results); 	// On récupère le pgcd et les coefficients de bezout dans le tableau results
	if (results[0] != 1)
		return 0;
	else
		return results[1]%n; 

}

long privateKey(long p, long q, long e)
{
	long n = p*q;
	long phi = (p-1)*(q-1);
	long results[3];
	extendEuclide(p, q, results);
	long d = results[1];
	return (d%phi);
}

long encodeRsa(long , long n, long e)
{
	long pow = rapidPow(m, e, n);
	return pow;
}

long decodeRsa(long x, long n, long d)
{
	long pow = rapidPow(x, d, n);
	return pow;
}


// Implémentation d'un algorithme de codage avec e groupe quotient Z/26Z
char encodeCar(char n, char x, char y)
{
	// Cette fonction prend un caractère n et le crypte
	char p = ((x*n) + y)%26;
	return p;
}

char searchQ(char x)
{
	long int i = 1;
	while((i*x % 26) != 1)
	{
		i++;
	}
	return i;

}

char decodeCar(char p, char x, char y, char q)
{
	// Cette fonction prend un caractère p et le décrypte
	
	char n = ((p-y)*q)%26;
	return n;
}

char encodeAscii(char n)
{
	// Cette fonction prend un paramètre n et le crypte suivant la formule ci-dessous
	char p = (7*n)%256;
	return p;
}

char decodeAscii(char p, char x)
{
	char n = (183*x)%256;
}
