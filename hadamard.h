#ifndef _HADAMARD_H_
#define _HADAMARD_H_

typedef enum { H0 = 1, H1 = 2, H2 = 4, H3 = 8, H4 = 16 } nbUsers;

// Création de la matrice de Hadamar en fonction du nombre d'utilisateurs renseigné
int * creerMatriceHadamard(int tailleMatrice);

// Remplissage de la matrice nouvellement créée
int * initialiserMatriceHadamard(int tailleMatrice);

// Affichage d'une matrice de Hadamar
void afficherMatriceHadamard(int *matrice, int nbUsers);

// Destruction de la matrice - libération de la mémoire allouée
void detruireMatriceHadamard(int *matrice);

#endif
