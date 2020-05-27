#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>

void val_vec_propre(double *B, int n, double *wr, double *wi, double *vr){
	char balanc= 'B';
	char jobvl = 'N';
	char jobvr = 'V'; 
	char sense = 'V';
	int ldb = n;
	int ldvl = n;
	double* vl = calloc(ldvl*n,sizeof(double));
	int ldvr = n; 
	int ilo=0, ihi=0;
	double* scale = calloc(n,sizeof(double));
	double abnrm=0.;
	double* rconde = calloc(n,sizeof(double));
	double* rcondv = calloc(n,sizeof(double));
	int *iwork = calloc(2*n-2,sizeof(int));
	double wkopt=0.;
	int lwork = -1;
	int info; 	LAPACK_dgeevx(&balanc,&jobvl,&jobvr,&sense,&n,B,&ldb,wr,wi,vl,&ldvl,vr,&ldvr,&ilo,&ihi,scale,&abnrm,rconde,rcondv,&wkopt,&lwork,iwork,&info);
	lwork = (int)wkopt;
	double* work = calloc(lwork,sizeof(double));	LAPACK_dgeevx(&balanc,&jobvl,&jobvr,&sense,&n,B,&ldb,wr,wi,vl,&ldvl,vr,&ldvr,&ilo,&ihi,scale,&abnrm,rconde,rcondv,work,&lwork,iwork,&info);
	if( info > 0 ) {
		printf( "Erreur: Valeurs et vecteurs propres non calculés.\n" );
		exit( 1 );
	}
	free(vl);free(scale);free(rconde);free(rcondv);free(iwork);free(work);
}
/*int main(){
int n=2;
double *A=malloc(n*n*sizeof(double));
for(int i=0; i<n*n;i++) scanf("%lf", &A[i]);
double *wr=calloc(n,sizeof(double));
 double *wi=calloc(n,sizeof(double));
double *vr=calloc(n*n,sizeof(double));
val_vec_propre(A, n,wr,wi, vr);
for(int i=0; i<n;i++) printf("\n%f+i %f\n", wr[i],wi[i]);
for(int i=0; i<n*n;i++) printf("%f\n",vr[i]);



free(wr); free(A); free(wi); free(vr);

}*/
