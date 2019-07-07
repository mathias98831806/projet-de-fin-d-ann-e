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

#define NB_columns_MAX 100
#define NB_rows_MAX 100

void getArray(float array[NB_rows_MAX][NB_columns_MAX], int rows, int columns);
void addArray(float array1[NB_rows_MAX][NB_columns_MAX], float array2[NB_rows_MAX][NB_columns_MAX], float array3[NB_rows_MAX][NB_columns_MAX] ,int rows, int columns);
void displayArray(float array[NB_rows_MAX][NB_columns_MAX], int rows, int columns);
void factorizeArray(float array[NB_rows_MAX][NB_columns_MAX], float new_array[NB_rows_MAX][NB_columns_MAX], int rows, int columns, int index);
float determinant(float array[NB_rows_MAX][NB_columns_MAX], int rows, int columns);
void multiplyArray(float array1[NB_rows_MAX][NB_columns_MAX], float array2[NB_rows_MAX][NB_columns_MAX], float array3[NB_rows_MAX][NB_columns_MAX] ,int rows1, int columns1, int rows2, int columns2);
int zeroFinder(float current_array[NB_rows_MAX][NB_columns_MAX], int current_row, int rows);
void linearRow(float array[NB_rows_MAX][NB_columns_MAX], int pivot, int current_row, int current_column, int columns);
void gradeArray(float array[NB_rows_MAX][NB_columns_MAX], int rows, int columns);
int arrangeArray(float array[NB_rows_MAX][NB_columns_MAX], int current_row, int rows, int current_column, int columns);
float trace(float array[NB_rows_MAX][NB_columns_MAX], int rows);
int rang(float array[NB_rows_MAX][NB_columns_MAX], int rows, int columns);
void transpose(float array[NB_rows_MAX][NB_columns_MAX], float t_array[NB_rows_MAX][NB_columns_MAX], int rows, int columns);
int zeroOnLine(float array[NB_rows_MAX][NB_columns_MAX], int current_row, int columns);



void getArray(float array[NB_rows_MAX][NB_columns_MAX], int rows, int columns)
{
	/* getArray prend en paramètre le tableau, le nombres de lignes et le nombre de colonnes*/ 
	
	for(int i=0; i < rows; i++){
		// On crée une boucle qui parcourt chaque ligne du tableau
		for(int j=0; j<columns; j++){
			// et qui grâce à un scanf et à une autre boucle sur les colonnes y insère
			// les coefficients du tableau
			printf("Veuillez saisir le coefficient [%d] - [%d] : ", i+1, j+1); // On affiche l'invite de saisie
			scanf("%f", &(array[i][j]));									   // On récupère la saisie
		}
		
	}
	// Et on ne renvoie absolument rien
}

void addArray(float array1[NB_rows_MAX][NB_columns_MAX], float array2[NB_rows_MAX][NB_columns_MAX], float array3[NB_rows_MAX][NB_columns_MAX] ,int rows, int columns)
{
	/* addArray prend en paramètre trois tableaux dont les deux premiers sont les
		opérandes de l'opération et le résultat est sauvegardé dans le troisième tableau */ 	
	
	for(int i=0; i<rows; i++) {
		// On crée une boucle qui parcourt chaque ligne du tableau
		for(int j=0; j<columns; j++) {
		// On crée une seconde boucle qui parcout chaque colonne en fonction de la ligne dans le tableau
			array3[i][j] = array1[i][j] + array2[i][j];	// On fait la somme des coefficients qu'on sauvegarde dans le tableau 
		}
	}
	// On ne renvoie rien
}


void displayArray(float array[NB_rows_MAX][NB_columns_MAX], int rows, int columns)
{
	// Fonction hyper-puissante qui affiche un tableau sous sa forme matricielle
	for(int i=0; i<rows; i++){

		for(int j=0; j<columns; j++){
			printf("%.1f\t", array[i][j]);
		}
		printf("\n");
	}
}



void factorizeArray(float array[NB_rows_MAX][NB_columns_MAX], float new_array[NB_rows_MAX][NB_columns_MAX], int rows, int columns, int index)
{
	// Cette fonction prend en paramètre une matrice et met ses coefficients dans une seconde matrice en omettant
	// les coefficients de la ligne et de la colonne désignée par l'index	
	// On parcourt le tableau donné en commentaire à partir de la deuxième ligne
	for (int i = 1; i<rows; i++)
	{
		// On parcourt les colonnes
		for (int j = 0; j<columns; j++)
		{
			if (j!=index)
			{
				// On insére les élements trouvés dans le nouveau tableau sauf les éléments de la index colonnes
				new_array[i-1][j] = array[i][j];
			}
		}

	}

}



float determinant(float array[NB_rows_MAX][NB_columns_MAX], int rows, int columns)
{
	// On pose les règles de calcul du déterminant d'une matrice d'ordre 2
	if (rows==2)
		{
			float value = 0;
			float a = array[0][0];	// On récupère le premier coefficient de la matrice
			float b = array[0][1];	// On récupère le second coefficient de la matrice
			float c = array[1][0];	// On récupère le troisième coefficient de la matrice
			float d = array[1][1];	// On récupère le quatrième coefficient de la matrice
			value = a*d - b*c;		// On calcule le déterminant 
			
			return value;				// Et on le renvoie
		}

	else						// Sinon si notre matrice n'est pas une matrice carrée:
		{
			float value = 0;			// On suppose que le déterminant est null
			for (int i = 0; i<columns; i++)	// On applique la formule de calcul du déterminant
			{
				// On crée une matrice vide
				float new_array[NB_rows_MAX][NB_columns_MAX];
				/* On remplie la matrice vide avec les coefficients de la matrice principale 
					sauf les coefficients de la ligne et de la colonne qu'on doit omettre */
				factorizeArray(array, new_array, rows, columns, i);
				// On calcule le déterminant de la nouvelle matrice selon la propriété
				float factor = array[0][0];
				if (i % 2 != 0)
					factor = -1 * factor;
				value = value + factor*determinant(new_array, rows-i, columns-i);
			}
			
			return value;				// Et on renvoie le déterminant calculé
		}
}


void multiplyArray(float array1[NB_rows_MAX][NB_columns_MAX], float array2[NB_rows_MAX][NB_columns_MAX], float array3[NB_rows_MAX][NB_columns_MAX] ,int rows1, int columns1, int rows2, int columns2)
{
	
	float coef;
	for (int i=0; i<rows1; i++)
	{
		/* On bloucle d'abord le nombre de colonnes de la matrice 2 fois
		   vous l'aurez compris, on remplira les colonnes de la 3 ème matrice
		   avant les lignes */
		for(int j2=0; j2<columns2; j2++)
		{
			// On boucle la première colonne fois 
			for(int j=0; j<columns1; j++)
			{
				// On éffectue le produit scalaire des lignes par les colonnes grâce à cette boucle
				coef = 0;
				coef = coef + array1[i][j] * array2[j][j2];

			}
			array3[i][j2] = coef;	// On met le coefficient obtenu dans la matrice 3

		}

	}
}

int arrangeArray(float array[NB_rows_MAX][NB_columns_MAX], int current_row, int rows, int current_column, int columns)
{
	// Procédure mettant en place un pivot dans une matrice qui est indispensable à la methode de gauss
	int arrange = 0, buffer;
	int pivot = zeroFinder(array, current_row, rows);
	if (pivot)
	{
		if (pivot != current_row)
		{
			for(int j=current_column; j<columns; j++)
			{
				// Sous mini procédure échangeant les coefficient de deux lignes en se servant d'un buffer
				buffer = array[pivot][j];
				array[pivot][j] = array[current_row][j];
				array[current_row][j] = buffer;
			}
			
		}
		arrange = 1;	// Si le pivot est trouvé et mise en place, on renvoie un true
	}

	return arrange;
}

int zeroFinder(float current_array[NB_rows_MAX][NB_columns_MAX], int current_row, int rows)
{
	// Cette fonction vérifie si les coefficients de toutes les lignes sont non nuls
	int limit = 1 + rows - current_row;
	int pivot = 0;
	for (int i=current_row; i<limit; i++)
	{
		if(current_array[i][0] != 0)
		{
			pivot = i;
			break;
		}

	}
	return pivot;
}

void linearRow(float array[NB_rows_MAX][NB_columns_MAX], int pivot, int current_row, int current_column, int columns)
{
	/* Cette fonction fait ce qu'on fait lorsqu'on constate que le premier coefficient de la colonne
	   courrante et de la ligne courrante est non nulle. Donc par rapport au pivot, on utilise
	   la formule qui permet d'avoir un zero à la ligne et à la colonne courrante */
	float factor = array[pivot][current_column]/array[current_row][current_column];	// On calcule le facteur
	for(int j=current_column; j<columns; j++)	// On boucle sur les coefficients de la ligne courrante
	{
		array[current_row][j] = array[pivot][j] - factor*array[current_row][j];	// On les remplace
	}
}

void gradeArray(float array[NB_rows_MAX][NB_columns_MAX], int rows, int columns) // Peu importe; cette procédure est hyper difficile à mettre en place mais j'ai réussi à la programmer
{
	// La fonction gradeArray met une matrice désordonnée sous sa forme échelonnée
	// D'abord on place bien les pivot et le reste
	int phased_row = 0, pivot;	
	for(int current_column=0; current_column<columns-1; current_column++)	// Pour chaque coefficient de la ligne courante
	{
		if (phased_row == rows)	// Bout de code indispensable pour permettre au programme de traiter tous types de matrices
			break;
		else
		{
			if(arrangeArray(array, phased_row, rows, current_column, columns))	// Si la matrice courante n'est pas bien arrangée
			{
				// On l'arrange
				pivot = phased_row;
				for(int current_row=pivot+1; current_row<rows; current_row++) // Pour chaque ligne en dessous du pivot
				{
					// Si le coefficient de la ligne courante et de la colonne courante est différent du coefficient du pivot
					if (array[current_row][current_column] !=0)
						// On fait de la combinaison linéaire
						linearRow(array, pivot, current_row, current_column, columns);
				}
			}				

		}
		phased_row = phased_row+1;
	}
}


float trace(float array[NB_rows_MAX][NB_columns_MAX], int rows)	//On ne calcule que la trace d'une matrice carrée
{
	// Fonction permettant de calculer la trace d'une matrice
	float value = 0;
	for(int i=0; i<rows; i++)
		value = value + array[i][i];
	return value;
}

void transpose(float array[NB_rows_MAX][NB_columns_MAX], float t_array[NB_rows_MAX][NB_columns_MAX], int rows, int columns) // On peut trouver la transposée de n'importe quelle matrice
{
	// Fonction permettant de calculer la transposee d'une matrice
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<columns; j++)
			t_array[j][i] = array[i][j];
	}
}

int zeroOnLine(float array[NB_rows_MAX][NB_columns_MAX], int current_row, int columns)
{
	int found = 1;
	for (int j=0; j<columns; j++)
	{
		if (array[current_row][j] != 0)
		{
			found = 0;
			break;
		}
	}
	return found;
}

int rang(float array[NB_rows_MAX][NB_columns_MAX], int rows, int columns)
{
	// fonction permettant de calculer le rang d'une matrice
	int rang = 0;
	gradeArray(array, rows, columns); // On met notre matrice sous sa forme échelonnée
	// On compte le nombre de ligne toute non nulle
	for (int i=0; i<rows; i++)
	{
		if (!zeroOnLine(array, i, columns))
			rang++;
	}
	return rang;
}

void equationSolver(float first_member[NB_rows_MAX][NB_columns_MAX], float second_member[NB_rows_MAX][NB_columns_MAX], int rows)
{
	concatenateArray(first_member, second_member, array, rows);	// On fait une concatenation
	gradeArray(array, rows, rows);	// On utilise le pivot de gauss
	// On crée un tableau des solution
	float solutions[rows]; // Il y a autant de solution que de lignes
	// On remplie le tableau en remontant
	for (int i=rows-1; i<-1; i--) // On part du dernier coefficient
	{
		solutions[i] = array[i][rows];
		
	}
}


int main(int argc, char *argv)
{
	
	return 0;
}
