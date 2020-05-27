#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
void transpose(double **A, int n, int m, double **At){

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			At[j][i]= A[i][j];
		}
	}
}

