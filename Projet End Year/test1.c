#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NB_rows_MAX 3
#define NB_columns_MAX 3
#define MAX 20


void factorizeArray(float array[NB_rows_MAX][NB_columns_MAX], float new_array[NB_rows_MAX][NB_columns_MAX], int rows, int index)
{
	// Cette fonction prend en paramètre une matrice et met ses coefficients dans une seconde matrice en omettant
	// les coefficients de la ligne et de la colonne désignée par l'index	
	// On parcourt le tableau donné en commentaire à partir de la deuxième ligne
	for (int i = 1; i<rows; i++)
	{
		// On parcourt les colonnes
		for (int j = 0; j<index; j++)
			// On insére les élements trouvés dans le nouveau tableau sauf les éléments de la index colonnes
			new_array[i-1][j] = array[i][j];

	}
	for (int i=1; i<rows; i++)
	{
		for (int j=index; j<rows-1; j++)
			new_array[i-1][j] = array[i][j+1];
	}

}



float determinant(float array[NB_rows_MAX][NB_columns_MAX], int rows)
{
	// On pose les règles de calcul du déterminant d'une matrice d'ordre 2
	// float value = 0;	// On suppose au début que le determinant est nul
	float value = 0;
	int mul = 1;		// On définit ici le coefficient multiplicateur du facteur
	if (rows==2)
		{
			float a = array[0][0];	// On récupère le premier coefficient de la matrice
			float b = array[0][1];	// On récupère le second coefficient de la matrice
			float c = array[1][0];	// On récupère le troisième coefficient de la matrice
			float d = array[1][1];	// On récupère le quatrième coefficient de la matrice
			value = a*d - b*c;		// On calcule le déterminant 
			// return value;		// Ligne de deboggage
		}

	else						// Sinon si notre matrice n'est pas une matrice carrée:
		{
			// float value = 0;	// Ligne de deboggage
			for (int i = 0; i<rows; i++)	// On applique la formule de calcul du déterminant
			{
				// On crée une matrice vide
				float new_array[NB_rows_MAX][NB_columns_MAX] = {{0}};
				/* On remplie la matrice vide avec les coefficients de la matrice principale 
					sauf les coefficients de la ligne et de la colonne qu'on doit omettre */
				factorizeArray(array, new_array, rows, i);
				// for(int k=0; k<rows; k++)
				// {
				// 	for(int o=0; o<rows; o++)				//Code de deboggage
				// 		printf("%.2f\t", new_array[k][o]);
				// 	printf("\n");	
				// }
				// printf("Encore un saut\n"); // Ligne de debogage
				// On calcule le déterminant de la nouvelle matrice selon la propriété
				float factor = array[0][i];	// On récupère le facteur multiplicatif du determinant de la nouvelle matrice à calculer
				printf("%f\n", factor);
				if (i % 2 != 0)				// On précise les conditions de négativité et de positivité du coefficient
					mul = -1;				// Si i est pair et si j est impair ou si i est impair et j est pair
				else
					mul = 1;				// Si i et j sont de même parité
				factor = mul * factor;		// On finalise la valeur du facteur

				value = value + factor*determinant(new_array, rows-1);	// Et on calcule le déterminant
				// printf("%d\t%d\n",rows, i); // Ligne de debogage
			}
			
		}
	return value;				// Et on renvoie le déterminant calculé
}

int main()
{
	float mat[3][3] = {{41, 8, 5}, {4, 7, 5}, {4, 8, 6}};
	float det = determinant(mat, 3);
	printf("%.2f", det);
}