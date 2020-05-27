#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
#include "header.h"


double ** copier( double **A, int n, int m){
double ** res=malloc(n*sizeof(double*));
for (int i=0; i<n ; i++) res[i]=malloc(m*sizeof(double));
for (int i=0; i<n ; i++){
for (int j=0; j<m ; j++){ res[i][j]=A[i][j];
}
}
return res;
for (int i=0; i<n ; i++) free(res[i]);
free(res);
}
