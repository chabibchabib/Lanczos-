#include <stdlib.h>
#include<stdio.h>


double produit_scalaire (double *x, double *y, int m){

double resultat=0.0;

for(int i =0; i<m; i++){

resultat=resultat+x[i]*y[i];

} // fin FOR
return resultat;
} // Fin produit_scalaire 

