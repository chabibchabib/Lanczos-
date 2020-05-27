#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void normaliser_matrice_colonne(double **vec, int n, int r){
double norme;
double *x=calloc(n,sizeof(double));
for (int j=0; j<r; j++){
norme=0;
for(int k=0; k<n; k++) x[k]=vec[k][j];
for (int i=0 ; i<n;i++) norme+=x[i]*x[i];
norme=sqrt(norme);
for (int i=0 ; i<n;i++) vec[i][j]=vec[i][j]/norme;
}

free(x);
}


/*int main(){ int n =3 ; int r=2;
double ** vec = malloc(n*sizeof(double*));
for (int i=0; i<n;i++) vec[i]=malloc(r*sizeof(double));
for (int i=0; i<n;i++){
for (int j=0; j<r;j++){
scanf("%lf", &vec[i][j]);}}
normaliser_matrice_colonne(vec,n,r);
for (int i=0; i<n;i++){ printf("\n");
for (int j=0; j<r;j++){
printf("%f", vec[i][j]);}}
for (int i=0; i<n;i++) free(vec [i]);
free(vec);
}*/
