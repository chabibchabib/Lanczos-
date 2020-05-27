#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>

double produit_scalaire (double *x, double *y, int m);   // Fonction produit scalaire 
//double * mat_vec(double **A, double *x, int n);   // Produit Matrice vecteur 
double * mat_vec(double ** A, double *x, int n, int m);
void afficher_tableau( double *tab, int n ); // Affichage d'un tableau 
void afficher_matrice( double **A, int n, int m ); // Affichage d'un tableau
double* lineariser_matrice( double **A, int N, int M); // Lineariser une matrice 
void fact_matrice (double *tab, int m, double **A); // Passer d'un tableau à matrice
void resolution_systeme(double *A, int m, double *b,int NRHS); // Fonction pour résoudre le SYSTEME
void val_vec_propre(double *B, int n, double *wr, double *wi, double *vr);  // vecteurs propres 
void racine_polynome(double *b, int m, double *racines );  // Polynomes 
void transpose(double **A, int m, int n, double **At); // transpose matrice
void mat_mat(double **A, double **B, double **C, int n, int m,int r); // produit matrice matrice 
void mat_scal(double **A, double lambda, double ** C, int n ); // Produit matrice scalaire 
void add_matrice(double **A, double **B , double** C, int n);
void iidentite_generateur(double **A, int n); // generer l'identité
void inverse_matrice(double *A, int n); // inverser une matrice
double norme_matricielle(double **A, int n);
double norme_vec(double *tab, int n);
void sort(double *t, int n );
double erreur_check(double **A, double ** res,double *lambda, int n, int r, int *ind, int * ind2);
double ** copier( double **A, int n, int m);
int *tri(double *tab, int m,int r);
void normaliser_matrice_colonne(double **vec, int n, int r);
int *tri2( double *t, int m, int r);




