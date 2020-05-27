#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
#include "header.h"
// mult mat (nxm) et mat (mxr)
void mat_mat(double **A, double **B, double **C, int n,int m, int r ){ 
double *col=malloc(m*sizeof(double));
double *res=malloc(n*sizeof(double));
for (int cpt=0; cpt<r;cpt++){
	for (int i =0;i<m;i++)  col[i]=B[i][cpt];

	res=mat_vec( A, col,  n,m);

	for (int i=0; i<n;i++) C[i][cpt]=res[i];

				}

free(col); free(res);
}
