#include <stdio.h>
#include <stdlib.h>

#include "hadamard.h" // Importation des prototypes de fonctions


int * creerMatriceHadamard(int tailleMatrice) {
	int *matrice = (int *) malloc(tailleMatrice * tailleMatrice * sizeof(int));
	
	return matrice;
}


int * initialiserMatriceHadamard(int tailleMatrice) {
    int *mat = creerMatriceHadamard(tailleMatrice);
    nbUsers tailleRemplissage = H0;

    // Remplissage de la matrice
    while(tailleRemplissage <= tailleMatrice) {
        if(tailleRemplissage == 1) mat[tailleMatrice*0+0] = 1;
        else {
            for(int i = 0; i < tailleRemplissage; i++)
                for(int j = 0; j < tailleRemplissage; j++) {
                    if(i < tailleRemplissage/2) { // Première moitié horizontale
                        if(j >= tailleRemplissage/2)
                        	mat[tailleMatrice*i+j] = mat[tailleMatrice*i+(j-tailleRemplissage/2)]; // Seconde moitié verticale
                    }
                    else { // Seconde moitié horizontale
                        if(j < tailleRemplissage/2) // Première moitié verticale
                        	mat[tailleMatrice*i+j] = mat[tailleMatrice*(i-tailleRemplissage/2)+j];
                        else // Quart inférieur droit
                        	mat[tailleMatrice*i+j] = -mat[tailleMatrice*(i-tailleRemplissage/2)+(j-tailleRemplissage/2)];
                    }
                }
        }
        tailleRemplissage *= 2;
    }
    return mat;
}


void afficherMatriceHadamard(int *matrice, int nbUsers) 
{
    if(nbUsers == 1)
        printf("Matrice pour %i utilisateur :\n",nbUsers);
    else
        printf("Matrice pour %i utilisateurs :\n",nbUsers);
    for(int i = 0; i < nbUsers; i++) 
    {
        printf("   Utilisateur : %i  ", i+1);
        for(int j = 0; j < nbUsers; j++) 
        {
            printf("| ");
            if (matrice[nbUsers*i+j] > 0)
                printf(" 1 ");
            else
                printf("-1 ");

        }
        printf("\n");
    }
    printf("\n");
}


void detruireMatriceHadamard(int *matrice) {
	free(matrice);
}
