/* Illustration de la fonction system(). */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	/* Déclaration d'une mémoire tampon pour y ranger les données
		entrées. */

	char input[40];

	while(1)
	{
		// Lecture de la commande utilisateur.
		puts("\nEntrez une commande système, ou une ligne blanche pour sortir");
		printf(">>>> ");
		scanf("%s", input);
		// Sortir en cas de ligne blanche.

		if(input[0] == '\0')
			exit(EXIT_SUCCESS);
		
		// Exécution de la commande.
		system(input);
	}
	exit(EXIT_SUCCESS);
	return 0;
}