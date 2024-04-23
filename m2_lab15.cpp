#include<stdio.h> //���������� �������
#include <math.h>
#include <locale.h>

#define Nx 2
#define Ny 3//���������� ������ ������ 
#define Nz 4
#define Nq 5

//�������� �. ��� ��������
void input(double x[], int n, char q);
// �������� �. ��� ���������
double calcul(double x[], int n, double (*f1)(double), double(*f2)(double));
// �������� �. ��� ��������� 
void pp(double x[], int k, char q);


int main() {
	//������������ ����������
	setlocale(LC_CTYPE, "ukr");
	double x[Nx], y[Ny], z[Nz], q[Nq];
	//������������ ������� ����� 
	input(x, Nx, 'x');
	input(y, Ny, 'y');
	input(z, Nz, 'z');
	input(q, Nq, 'q');
	printf("\n");
	//������������ �. ������ 
	pp(x, Nx, 'x');
	pp(y, Ny, 'y');
	pp(z, Nz, 'z');
	pp(q, Nq, 'q');
	printf("\n");
	//������������ �. ��� ���������
	double A = calcul(x, Nx, sin, cos);
	printf("��������� ��� ������ �:%.2lf", A);
	printf("\n");
	double B = calcul(y, Ny, cos, sin);
	printf("��������� ��� ������ y:%.2lf", B);
	printf("\n");
	double C = calcul(z, Nz, sin, sin);
	printf("��������� ��� ������ z:%.2lf", C);
	printf("\n");
	double D = calcul(q, Nq, cos, cos);
	printf("��������� ��� ������ q:%.2lf", D);
}
//���������� �. ��� ���������
double calcul(double x[], int n, double (*f1)(double), double(*f2)(double)) {
	double resalt = 0;
	for (int i = 0; i < n; i++) {
		resalt += x[i] * f1(x[i]) + pow(x[i], 2) * f2(x[i]);
	}
	return resalt;
}
// ���������� �. ��� ����� 
void input(double x[], int n, char q) {
	int i;
	printf("����� %c \n", q);
	for (i = 0; i < n; i++)
	{
		printf("����i�� %c [%i] = ", q, i + 1);
		scanf_s("%lf", &x[i]);
	}
	return;
}
// ���������� �. ��� ������
void pp(double x[], int k, char q) {

	printf("����� %c \n", q);
	for (int i = 0; i < k; i++)
	{
		printf(" %.1lf ", x[i]);

	}
	printf("\n");
	return;
}
