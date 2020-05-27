#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
#include "header.h"

void inverse_matrice(double *A, int n){
int lda=n; int lwork=n; int info=0;
double *work=malloc(n*sizeof(double));
int *ipiv=malloc(n*sizeof(int));
   LAPACK_dgetrf(&n,&n,A,&lda,ipiv,&info);

LAPACK_dgetri(&n,  A,&lda,ipiv,work,&lwork,&info); 
//printf("work: %f\n",work[0]);
free(work); free(ipiv);
//printf("info inverse matrice: %d\n",info);
}

/*int main(){
double *A; int n=3;
A=malloc(n*n*sizeof(double));

for (int i=0; i<n*n;i++) scanf("%lf",&A[i]);
inverse_matrice(A,n);

for (int i=0; i<n*n;i++)
		printf("%f\n",A[i]);

}*/
