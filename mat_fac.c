#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>


void fact_matrice (double *tab, int m, double **A){
	for(int j=0;j<m;j++){
		for(int k=0;k<m;k++){
			A[j][k]=tab[j*m+k];
		}}}
