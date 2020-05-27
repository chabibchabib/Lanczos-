#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
double * mat_vec(double ** A, double *x, int n, int m){
double *res= malloc(n* sizeof(double));
for (int i =0 ; i< n ; i++){
res[i]=0;
for (int j =0 ; j< m ; j++){
res[i]+=A[i][j]*x[j];
} // fin for j
} // fin for i
return res;
free(res);
}


