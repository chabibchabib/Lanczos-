#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
 void add_matrice(double **A, double **B , double** C,int n ){
for (int i =0; i<n;i++){
for (int j =0; j<n;j++){
C[i][j]=A[i][j]+B[i][j];
}

}

}
