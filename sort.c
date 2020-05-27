#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>

void sort(double *t, int n ){
//double * t=malloc(n*sizeof(double));
double aide;
//for (int i =0 ;i<n ; i++) t[i]=tab[i];
for (int i =0 ;i<n ; i++){
for (int j =0 ;j<n-i ; j++){
if(t[j]<t[j+1]){ aide=t[j];
t[j]=t[j+1];
t[j+1]=aide;

}
}
}}
