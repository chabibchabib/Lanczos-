#include<stdlib.h>
#include<stdio.h>
#include<math.h>


int *tri2( double *t, int m, int r){
int *ind=malloc(m*sizeof(int));
int *res=malloc(r*sizeof(int));
double *tab=malloc(m*sizeof(double));
for (int i =0; i<m ; i++ ) tab[i]=t[i];
 double aide,max =0.0;
  int PMAX,p;
for( int i=0;i<m;i++) ind[i]=i;
for (int i=0; i<m-1;i++){
    // Recherche du max à droite de module[i]
    PMAX=i;
    for (int j=i+1;j<m;j++)
      if (fabs(tab[j])>fabs(tab[PMAX])) PMAX=j;
      //if ((tab[j])>(tab[PMAX])) PMAX=j;
    // Echange de module[i] avec le max
    aide=tab[i];
    tab[i]=tab[PMAX];
    tab[PMAX]=aide;
    p = ind[i];
    ind[i]=ind[PMAX];
    ind[PMAX]=p;
  }
for (int i=0; i<r; i++) res[i]=ind[i];
return res;
free(res);
free(ind);
free(tab);
}

