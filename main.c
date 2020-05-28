#include<stdio.h>
#include<stdlib.h>
#include<lapacke.h>
#include "header.h"

void poisson1(double **A, int n){
	int i;
	double a=2.0,d=-1.0;
	A[0][0]=a;A[n-1][n-1]=a;A[0][1]=d;A[n-1][n-2]=d;
	for(i=1;i<n-1;i++){
		A[i][i]=a;
		A[i][i+1]=d;
		A[i][i-1]=d;
	}
}
void matA3(double** A, int n){
	
	int i,j;
	//A[0][0] = n;
	for(j=0;j<n;j++){
		for(i=0;i<=j;i++){
			A[i][j] =  n+1-(j+1);
		}
	}
	for(j=0;j<n-1;j++){
		for(i=j+1;i<n;i++){
			A[i][j] =  n+1-(i+1);
		}
	}
}

int main(){

int n;int  m; int r;
printf("donner la dimension de la matrice : ");
scanf("%d",&n);
printf("donner la dimension du sous espace de Krylov : ");
scanf("%d",&m);
do {
printf("donner le nombre de valeurs propres à chercher : ");
scanf("%d",&r);
}while(m<2*r);
double *x=calloc(n,sizeof(double));
double *val= malloc(m*sizeof(double));
double **vec= malloc(n*sizeof(double*));
for (int i=0;i<n;i++) vec[i]=malloc(m*sizeof(double));
double **A= malloc(n*sizeof(double*));
for (int i=0;i<n;i++) A[i]=malloc(n*sizeof(double));
// x
for (int i=0; i<n ; i++) x[i]=1; 
x[0]=1;
// 
/*for (int i=0; i<n ; i++){
for (int j=0; j<n ; j++){
scanf("%lf",&A[i][j]);
}}*/
/*A[0][0]=9; A[0][1]=1;A[0][2]=-2;A[0][3]=1;A[1][0]=1;A[1][1]=8;A[1][2]=-3 ;A[1][3]=-2;
A[2][0]=-2;A[2][1]=-3;A[2][2]=7;A[2][3]=-1;A[3][0]=1;A[3][1]=-2;A[3][2]=-1;A[3][3]=6;*/

//poisson1(A,n);
matA3(A,n);
//afficher_matrice(A,n,n);

lanczos(A,x,val,vec, n , m , r);
afficher_tableau(val,m);
free(x);
free(val);
for (int i=0; i<n ; i++) free(vec[i]);
free(vec);

for (int i=0; i<n ; i++) free(A[i]);
free(A);


}

