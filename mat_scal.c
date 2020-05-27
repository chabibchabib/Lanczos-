#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
#include"header.h"
void mat_scal(double **A, double lambda, double ** C, int n ){

for (int i =0; i<n;i++){
for (int j =0; j<n;j++){
C[i][j]=lambda*A[i][j];
}

}



}
