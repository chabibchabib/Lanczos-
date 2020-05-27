#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
#include "header.h"

double **construction_Tm( double **A,double *x, int n, int m, double **Vm){
double ** Tm= malloc(m*sizeof(double *));
for (int i=0; i<m;i++) Tm[i]= calloc(m,sizeof(double));
double *beta=calloc(m+1, sizeof(double));
double *y0=malloc(n*sizeof(double ));
double *y0p=malloc(n*sizeof(double ));
double *y1=malloc(n*sizeof(double ));
double *y2=malloc(n*sizeof(double ));
double *y2p=malloc(n*sizeof(double ));
double *y_1=calloc(n,sizeof(double ));
	//Normalisation de x et calcul de y0;
double norme=sqrt(produit_scalaire (x,x,n));
for (int i=0; i<n;i++){
y0[i]=x[i]/norme;
}
for (int i=0; i<n; i++) Vm[i][0]=y0[i];

	// boucle for 
for (int i=0; i<m-1; i++){
y0p=mat_vec( A,y0,n,n);
Tm[i][i]=produit_scalaire (y0,y0p,n);
for (int j=0;j<n;j++) y2p[j]=y0p[j]-Tm[i][i]*y0[j]-beta[i]*y_1[j];
beta[i+1]=sqrt(produit_scalaire (y2p,y2p,n));
for (int k=0;k<n;k++) y2[k]=y2p[k]/beta[i+1];
Tm[i+1][i]=beta[i+1];
Tm[i][i+1]=beta[i+1];
y_1=y0;
y0=y2;
for (int k=0; k<n;k++) Vm[k][i+1]=y2[k];
} // fin FOR
	//alpha_m-1
y0p=mat_vec( A,y2,n,n);
Tm[m-1][m-1]=produit_scalaire (y2,y0p,n);
return Tm;
	// Desallouer 
for (int i=0; i<m; i++) free(Tm[i]);
free(Tm);
free(beta);
free(y0);free(y0p); free(y1);free(y2);free(y2p);free(y_1);
} // Fin Conctruction TM



//main
int main(){


int n=4;int  m=2;
double *x=calloc(n,sizeof(double));
double **A= malloc(n*sizeof(double*));
for (int i=0;i<n;i++) A[i]=malloc(n*sizeof(double));
double **Vm= malloc(n*sizeof(double*));
for (int i=0;i<n;i++) Vm[i]=malloc(m*sizeof(double));
double **Tm= malloc(m*sizeof(double*));
for (int i=0;i<m;i++) Tm[i]=malloc(m*sizeof(double));
// x
for (int i=0; i<n ; i++) x[i]=0; 
x[0]=1;
// 
A[0][0]=9; A[0][1]=1;A[0][2]=-2;A[0][3]=1;A[1][0]=1;A[1][1]=8;A[1][2]=-3 ;A[1][3]=-2;
A[2][0]=-2;A[2][1]=-3;A[2][2]=7;A[2][3]=-1;A[3][0]=1;A[3][1]=-2;A[3][2]=-1;A[3][3]=6;


Tm=construction_Tm( A,x,n,m,Vm);
// 
printf("Matrice Tm\n");
afficher_matrice(Tm,m,m);
printf("Matrice Vm\n");
afficher_matrice(Vm,n,m);
free(x);

for (int i=0; i<n ; i++) free(A[i]);
free(A);

for (int i=0; i<n ; i++) free(Vm[i]);
free(Vm);
for (int i=0; i<m ; i++) free(Tm[i]);
free(Tm);




}


