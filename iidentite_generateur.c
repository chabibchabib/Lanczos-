#include<stdio.h>
#include<stdlib.h>

void iidentite_generateur(double ** A, int n){
for (int i=0; i<n ;i++){
for (int j=0; j<n ;j++){
A[i][j]=0;
if ( i==j) A[i][j]=1; 
}
}

}
