#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<lapacke.h>

// Fonction pour afficher matrice 
void afficher_matrice( double **A, int n, int m ){
printf("\n");
for (int i =0 ; i<n; i++){
printf("\n");
for (int j =0 ; j<m; j++){
printf("%f \t", A[i][j]);

}// fin for j 
} // fin for i
printf("\n");
}

