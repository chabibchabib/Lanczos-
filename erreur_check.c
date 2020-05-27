#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
#include "header.h"

double norme_vec(double *tab, int n){
double norme=0.0;
for (int i=0;i<n ;i++) norme+=tab[i]*tab[i];
norme=sqrt(norme);
return norme; 
}

double erreur_check(double **A, double ** res,double *lambda, int n, int r, int *ind, int *ind2){
double ** Id= malloc(n*sizeof(double*));
for(int i=0; i<n;i++) Id[i]= malloc(n*sizeof(double));
 double *tab=malloc(r*sizeof(double));
//for(int i=0; i<n;i++) tab[i]=res[i][m];
double ** Li= malloc(n*sizeof(double*));
for(int i=0; i<n;i++) Li[i]= malloc(n*sizeof(double));
double ** M= malloc(n*sizeof(double*));
for(int i=0; i<n;i++) M[i]= malloc(n*sizeof(double));
double *tmp=malloc(n*sizeof(double));
double *tmp2=malloc(n*sizeof(double));
for (int i=0 ; i<n ; i++){
for (int j=0 ; j<n ; j++){ Id[i][j]=0;
if (i==j) Id[i][j]=1;
}}


for (int i=0 ; i<r ; i++){
mat_scal(Id, -lambda[ind2[i]], Li,n);
add_matrice(A,Li ,M,n);
//afficher_matrice(M,n,n);
for (int k=0;k<n; k++) tmp[k]=res[k][ind[i]];
tmp2=mat_vec(M,tmp,n,n);
//afficher_tableau( tmp2, n );
tab[i]=norme_vec(tmp2,n);
}
//printf("tab\n");
//afficher_tableau( tab, m );
sort(tab,r);
return tab[0];
// desallouer
for(int i=0; i<n;i++) free(Id[i]);
free(Id);
free(tab);
for(int i=0; i<n;i++) free(Li[i]);
free(Li);
for(int i=0; i<n;i++) free(M[i]);
free(M);
free(tmp);
free(tmp2);
}

/*int main(){
int n=3; int m=2;
double ** A= malloc(n*sizeof(double*));
for(int i=0; i<n;i++) A[i]= malloc(n*sizeof(double));
double ** res= calloc(n,sizeof(double*));
for(int i=0; i<n;i++) res[i]= calloc((m+1),sizeof(double));
printf("\n A\n");
for(int i=0; i<n;i++){
for(int j=0; j<n;j++){scanf("%lf",&A[i][j]);
}}
printf("\n res\n");
for(int i=0; i<n;i++){
for(int j=0; j<m;j++){scanf("%lf",&res[i][j]);
}}
printf("\n coeff\n");
for(int i=0; i<m;i++) scanf("%lf",&res[i][m]);
double err=erreur_check(A,res,n,m);
printf("\n err=%f\n",err);
for(int i=0; i<n;i++) free(A[i]);
free(A);
for(int i=0; i<n;i++) free(res[i]);
free(res);
}*/
