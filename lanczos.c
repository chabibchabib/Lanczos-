#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
#include "header.h"


void lanczos(double **A, double *x, double *val, double **vec, int n , int m , int r){
	//Allocation mémoire 
double **Tm=malloc(m*sizeof(double*));
for(int i=0;i<m;i++) Tm[i]=malloc(m*sizeof(double));
double **Vm=malloc(n*sizeof(double*));
for(int i=0;i<n;i++) Vm[i]=malloc(m*sizeof(double));
double *Tm_l=malloc(m*m*sizeof(double));
double *vec_l=malloc(m*m*sizeof(double));
double *val_i=malloc(m*sizeof(double));
double ** vec_tm=malloc(m*sizeof(double*));
for(int i=0;i<m;i++) vec_tm[i]=malloc(m*sizeof(double));
	//Boucle
double  err=1; int kmax=200; int k=0; double eps=pow(10,-7);

for(k=0; k<kmax;k++){
Tm=construction_Tm(A,x,n,m,Vm);
Tm_l=lineariser_matrice(Tm,m,m);
val_vec_propre(Tm_l,m,val,val_i,vec_l);
fact_matrice (vec_l,m,vec_tm);
mat_mat(Vm,vec_tm,vec,n,m,m);

}








	//Desallouer la mémoire 
for(int i=0;i<m;i++) free(Tm[i]);
free(Tm)
for(int i=0;i<n;i++) free(Vm[i]);
free(Vm)
free(Tm_l);
free(vec_l); 
free(val_i);
for (int i=0;i<m; i++) free(vec_tm[i]);
free(vec_tm);
} // FIN LANC
