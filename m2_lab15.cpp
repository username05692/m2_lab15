#include<stdio.h> //підключення бібліотек
#include <math.h>
#include <locale.h>

#define Nx 2
#define Ny 3//оголошення розмірів масивів 
#define Nz 4
#define Nq 5

//прототип ф. для введення
void input(double x[], int n, char q);
// прототип ф. для обрахунків
double calcul(double x[], int n, double (*f1)(double), double(*f2)(double));
// прототип ф. для виведення 
void pp(double x[], int k, char q);


int main() {
	//встановлення локалізації
	setlocale(LC_CTYPE, "ukr");
	double x[Nx], y[Ny], z[Nz], q[Nq];
	//використання функції вводу 
	input(x, Nx, 'x');
	input(y, Ny, 'y');
	input(z, Nz, 'z');
	input(q, Nq, 'q');
	printf("\n");
	//використання ф. виводу 
	pp(x, Nx, 'x');
	pp(y, Ny, 'y');
	pp(z, Nz, 'z');
	pp(q, Nq, 'q');
	printf("\n");
	//використання ф. для обрахунків
	double A = calcul(x, Nx, sin, cos);
	printf("Результат для масиву х:%.2lf", A);
	printf("\n");
	double B = calcul(y, Ny, cos, sin);
	printf("Результат для масиву y:%.2lf", B);
	printf("\n");
	double C = calcul(z, Nz, sin, sin);
	printf("Результат для масиву z:%.2lf", C);
	printf("\n");
	double D = calcul(q, Nq, cos, cos);
	printf("Результат для масиву q:%.2lf", D);
}
//визначення ф. для обрахунків
double calcul(double x[], int n, double (*f1)(double), double(*f2)(double)) {
	double resalt = 0;
	for (int i = 0; i < n; i++) {
		resalt += x[i] * f1(x[i]) + pow(x[i], 2) * f2(x[i]);
	}
	return resalt;
}
// визначення ф. для вводу 
void input(double x[], int n, char q) {
	int i;
	printf("Масив %c \n", q);
	for (i = 0; i < n; i++)
	{
		printf("Введiть %c [%i] = ", q, i + 1);
		scanf_s("%lf", &x[i]);
	}
	return;
}
// визначення ф. для виводу
void pp(double x[], int k, char q) {

	printf("Масив %c \n", q);
	for (int i = 0; i < k; i++)
	{
		printf(" %.1lf ", x[i]);

	}
	printf("\n");
	return;
}
