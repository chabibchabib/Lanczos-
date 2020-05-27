#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// fonction pour rendre  une matrice sous la forme d'un tableau
double* lineariser_matrice( double **A,int N, int M){
double *tab;
tab=malloc((N*M)*sizeof(double));
for(int i=0;i<N;i++){
for(int j=0;j<M;j++){
tab[j*N+i]=A[i][j];
}}
return tab;
free(tab);
}
