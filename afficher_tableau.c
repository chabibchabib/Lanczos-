#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<lapacke.h>

// Fonction pour afficher un tableeau 
void afficher_tableau( double *tab, int n ){
for (int i =0 ; i<n ; i++){
printf("%2.8e \n", tab[i]);
}

} // Fin fonction 

