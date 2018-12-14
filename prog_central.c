#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "hadamard.h"
#include "canal.h"

int determinerNbUtilisateur(int nbUtilisateur)
{
	int ligne = 1;

	for (int i = 1; i <= nbUtilisateur; ++i)
	{
		if(ligne >= nbUtilisateur)
			return ligne;
		ligne *= 2;
	}
}
/*
int recupLigne(int ligne, int nbLigne, int matrice[], int canal[])
{
	
	for (int i = 0; i < nbLigne; ++i)
		canal[i] = matrice[nbLigne*ligne+i];
	return canal;
}
*/

int main() 
{
	int ligne, nbUser, nbLigne;

	int *ptrToInt;

	do
	{
		printf("Sélectionner le nombre d'utilisateur : ");
		scanf("%i", &nbUser);
	}
	while(nbUser < 1 );

	nbLigne = determinerNbUtilisateur(nbUser);

	int canal[nbLigne];

	int *mat = initialiserMatriceHadamard(nbLigne);


	afficherMatriceHadamard(mat, nbLigne);

		do
		{
			printf("Choisissez votre utilisateur : ");
			scanf("%i", &ligne);
		}
		while(ligne < 1 || ligne > nbLigne);

		ligne--;

		//canal = recupLigne(ligne, nbLigne, mat, canal);
		for (int i = 0; i < nbLigne; ++i)
		{
			ptrToInt =  &mat[nbLigne*ligne+i];
			canal[i] = *ptrToInt;
		}

		codage(canal, nbLigne);
	detruireMatriceHadamard(mat);
}
