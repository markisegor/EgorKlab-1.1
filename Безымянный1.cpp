#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <math.h>
struct complex {
	int real, im;
};
struct Line_int {
	int n;
	int *pa;
};
struct Line_real {
	int n;
	double *pa;
};
struct Line_complex {
	int n;
	complex *pa;
};
struct matrix_real {
	int lines;
	Line_real *pmatr;//указатель на 1 строку
};
struct matrix_int {
	int lines;
	Line_int *pmatr;
};
struct matrix_complex {
	int lines;
	Line_complex *pmatr;
};
int getint(int *pa)
{
	int r = 0, b, t, k = 1;
	char s;
	*pa = 0;
	do
	{
		scanf("%c", &s);
		if (s >= '0'&& s <= '9')
		{
			*pa += k*(s - 48);
			k *= 10;
		}
	} while (s != '\n');
	if (*pa == 0)
	{
		r = 1;
		printf("Error\n");
	}
	else
	{
		k /= 10;
		b = *pa;
		*pa = 0;
		while (b)
		{
			t = b % 10;
			*pa += t*k;
			k /= 10;
			b /= 10;
		}
	}
	return r;
}
int getreal(double *p)
{
	int r = 1;
	do {
		r = scanf("%lf", p);
		if (r == 0)
		{
			printf("Error\n");
			scanf("%*c");
		}


	} while (r == 0);
	return r < 0 ? 1 : 0;
}
int getcomplex(complex *a)
{
	int r = 0, b, t, k1 = 1, k2 = 1;
	char s;
	bool per = true, mr = false, mm = false;
	a->real = 0;
	a->im = 0;
	do
	{
		scanf("%c", &s);
		if (s == 'i')
			per = false;
		if ((s == '-') && (per))
			mr = true;
		if ((s == '-') && (!per))
			mm = true;
		if (per)
		{

			if (s >= '0'&& s <= '9')
			{
				a->real += k1*(s - 48);
				k1 *= 10;
			}
		}
		else
		{
			if (s >= '0'&& s <= '9')
			{
				a->im += k2*(s - 48);
				k2 *= 10;
			}
		}

	} while (s != '\n');



	if ((a->real == 0) && (a->im == 0))
	{
		r = 1;
		printf("Error\n");
	}
	else
	{
		k1 /= 10;
		b = a->real;
		a->real = 0;
		while (b)
		{
			t = b % 10;
			a->real += t*k1;
			k1 /= 10;
			b /= 10;
		}

		k2 /= 10;
		b = a->im;
		a->im = 0;
		while (b)
		{
			t = b % 10;
			a->im += t*k2;
			k2 /= 10;
			b /= 10;
		}
	}
	if (mr)
		a->real = -a->real;
	if (mm)
		a->im = -a->im;
	return r;
}
int getline_int_file(Line_int *pl, int n, FILE *in)
{
	int i, lgg;
	pl->n = n;//число переменных
	pl->pa = (int *)calloc(n, sizeof(int));
	for (i = 0; i < n; ++i)
	{
		*(pl->pa + i) = 0;
		fscanf(in, "%d", pl->pa + i);
	}

	return 0;
}
int getline_int(Line_int *pl, int n)
{
	int i, lgg;
	pl->n = n;//число переменных
	pl->pa = (int *)calloc(n, sizeof(int));
	for (i = 0; i < n; ++i)
		do {
			*(pl->pa + i) = 0;
			printf("vvedite chislo\n");
			lgg = getint(pl->pa + i);//результат, который вернёт гетинт
		} while (lgg == 1);

		return 0;
}
int getline_complex(Line_complex *pl, int n)
{
	int i, lgg;
	complex *p1;
	pl->n = n;
	pl->pa = (complex *)calloc(n, sizeof(complex));
	for (i = 0; i < n; ++i)
		do {
			p1 = pl->pa + i;
			p1->real = 0;
			p1->im = 0;
			printf("vvedite chislo\n");
			lgg = getcomplex(pl->pa + i);
		} while (lgg == 1);

		return 0;
}

int getline_file_complex(Line_complex *pl, int n, FILE *in)
{
	int i, lgg,a,b;
	complex *p1;
	pl->n = n;
	pl->pa = (complex *)calloc(n, sizeof(complex));
	for (i = 0; i < n; ++i)
 {
 
			p1 = pl->pa + i;
			p1->real = 0;
			p1->im = 0;
			fscanf(in, "%d%d" , &a, &b);
			p1->real = a;
			p1->im = b;
			
		}
	

		return 0;
}
int getline_real(Line_real *pl, int n)
{
	int i, lgg;
	pl->n = n;
	pl->pa = (double *)calloc(n, sizeof(double));
	for (i = 0; i < n; ++i)
		do {
			*(pl->pa + i) = 0;
			printf("vvedite chislo\n");
			lgg = getreal(pl->pa + i);
		} while (lgg == 1);

		return 0;
}
int getline_file_real(Line_real *pl, int n, FILE *in)
{
	int i, lgg;
	pl->n = n;//число переменных
	pl->pa = (double *)calloc(n, sizeof(double));
	for (i = 0; i < n; ++i)
	{
		*(pl->pa + i) = 0;
		fscanf(in, "%lf", pl->pa + i);
	}

		return 0;
}
void printmatr_int(matrix_int *pm)//пм-указатель на матрицу
{
	int i, j, *p1;
	struct Line_int *p2 = pm->pmatr;//п2-указ на линию пматр на 1 линию
	for (j = 0; j < pm->lines; ++j) {//пм лийнс-число линий    	тут идём по линиям
		p1 = p2->pa;
		for (i = 0; i < p2->n; ++i, ++p1)//тут по массиву
			printf("%d ", *p1);
		printf("\n");
		p2++;
	};
	printf("\n");
}
void printmatr_real(matrix_real *pm)
{
	int i, j;
	double *p1;
	struct Line_real *p2 = pm->pmatr;
	for (j = 0; j < pm->lines; ++j) {
		p1 = p2->pa;
		for (i = 0; i < p2->n; ++i, ++p1)
			printf("%f ", *p1);
		printf("\n");
		p2++;
	};
	printf("\n");
}
void printmatr_complex(matrix_complex *pm)
{
	int i, j;
	complex *p1;
	struct Line_complex *p2 = pm->pmatr;
	for (j = 0; j < pm->lines; ++j) {
		p1 = p2->pa;
		for (i = 0; i < p2->n; ++i, ++p1)
		{

			printf("%d", p1->real);
			if (p1->im>0)
				printf("+%di ", p1->im);
			else
				printf("-%di ", -p1->im);
		}

		printf("\n");
		p2++;
	};
	printf("\n");
}
int getmatrix_int(matrix_int *a, int n)//выделяет память под линии и запускает гетлайн
{
	int i;
	a->pmatr = (Line_int *)calloc(n, sizeof(Line_int));
	a->lines = n;
	for (i = 0; i < n; ++i)
		getline_int(a->pmatr + i, n);
	return 0;
}
int getmatrix_int_file(matrix_int *a, int n, FILE *in)//выделяет память под линии и запускает гетлайн
{
	int i;
	a->pmatr = (Line_int *)calloc(n, sizeof(Line_int));
	a->lines = n;
	for (i = 0; i < n; ++i)
		getline_int_file(a->pmatr + i, n, in);
	return 0;
}
int getmatrix_real(matrix_real *a, int n)
{
	int i;
	a->pmatr = (Line_real *)calloc(n, sizeof(Line_real));
	a->lines = n;
	for (i = 0; i < n; ++i)
		getline_real(a->pmatr + i, n);
	return 0;
}
int getmatrix_file_real(matrix_real *a, int n, FILE *in)
{
	int i;
	a->pmatr = (Line_real *)calloc(n, sizeof(Line_real));
	a->lines = n;
	for (i = 0; i < n; ++i)
		getline_file_real(a->pmatr + i, n, in);
	return 0;
}
int getmatrix_complex(matrix_complex *a, int n)
{
	int i;
	a->pmatr = (Line_complex *)calloc(n, sizeof(Line_complex));
	a->lines = n;
	for (i = 0; i < n; ++i)
		getline_complex(a->pmatr + i, n);
	return 0;
}
int getmatrix_file_complex(matrix_complex *a, int n, FILE *in)
{
	int i;
	a->pmatr = (Line_complex *)calloc(n, sizeof(Line_complex));
	a->lines = n;
	for (i = 0; i < n; ++i)
		getline_file_complex(a->pmatr + i, n, in);
	return 0;
}
void erase_int(matrix_int *pm)
{
	int i;
	for (i = 0; i < pm->lines; ++i)
		free(pm->pmatr[i].pa);
	free(pm->pmatr);
	pm->pmatr = NULL;
}
void erase_real(matrix_real *pm)
{
	int i;
	for (i = 0; i < pm->lines; ++i)
		free(pm->pmatr[i].pa);
	free(pm->pmatr);
	pm->pmatr = NULL;
}
void erase_complex(matrix_complex *pm)
{
	int i;
	for (i = 0; i < pm->lines; ++i)
		free(pm->pmatr[i].pa);
	free(pm->pmatr);
	pm->pmatr = NULL;
}
int work1_int(matrix_int *a, matrix_int *b, matrix_int *c, int n)
{
	int i, j;
	Line_int *pla, *plb, *plc;
	for (i = 0; i < n; i++)
	{
		pla = a->pmatr + i;
		plb = b->pmatr + i;//загоняем значения в указатели, чтобы работать
		plc = c->pmatr + i;
		plc->n = n;
		plc->pa = (int *)calloc(n, sizeof(int));//выделяем память под массив и возвращаем указ на 1 элт
		for (j = 0; j < n; j++)
			*(plc->pa + j) = *(pla->pa + j) + *(plb->pa + j);
	}
	return 1;
}
int work1_real(matrix_real *a, matrix_real *b, matrix_real *c, int n)
{
	int i, j;
	Line_real *pla, *plb, *plc;
	for (i = 0; i < n; i++)
	{
		pla = a->pmatr + i;
		plb = b->pmatr + i;
		plc = c->pmatr + i;
		plc->n = n;
		plc->pa = (double *)calloc(n, sizeof(double));
		for (j = 0; j < n; j++)
			*(plc->pa + j) = *(pla->pa + j) + *(plb->pa + j);
	}
	return 1;
}
int work1_complex(matrix_complex *a, matrix_complex *b, matrix_complex *c, int n)
{
	int i, j;
	Line_complex *pla, *plb, *plc;
	for (i = 0; i < n; i++)
	{
		pla = a->pmatr + i;
		plb = b->pmatr + i;
		plc = c->pmatr + i;
		plc->n = n;
		plc->pa = (complex *)calloc(n, sizeof(complex));
		for (j = 0; j < n; j++)
		{
			plc->pa[j].real = pla->pa[j].real + plb->pa[j].real;
			plc->pa[j].im = pla->pa[j].im + plb->pa[j].im;
		}

	}
	return 1;
}
int work2_int(matrix_int *a, matrix_int *b, matrix_int *c, int n)
{
	Line_int *pla, *plb, *plc;
	int i, j, k;
	for (i = 0; i<n; i++)//выделяем память для с
	{
		plc = c->pmatr + i;
		plc->n = n;
		plc->pa = (int *)calloc(n, sizeof(int));
	}
	for (i = 0; i<n; i++)//сдвиг по вертикали в  а и с
	{
		pla = a->pmatr + i;
		plc = c->pmatr + i;
		for (k = 0; k<n; k++)//
			for (j = 0; j<n; j++)//сдвиг по строкам б, к отвечает за сдвиг по горизонтали
			{
				plb = b->pmatr + j;
				*(plc->pa + k) += *(pla->pa + j)*(*(plb->pa + k));
			}
	}
	return 1;
}
int work2_real(matrix_real *a, matrix_real *b, matrix_real *c, int n)
{
	Line_real *pla, *plb, *plc;
	int i, j, k;
	for (i = 0; i<n; i++)
	{
		plc = c->pmatr + i;
		plc->n = n;
		plc->pa = (double *)calloc(n, sizeof(double));
	}
	for (i = 0; i<n; i++)
	{
		pla = a->pmatr + i;
		plc = c->pmatr + i;
		for (k = 0; k<n; k++)
			for (j = 0; j<n; j++)
			{
				plb = b->pmatr + j;
				*(plc->pa + k) += *(pla->pa + j)**(plb->pa + k);
			}
	}
	return 1;
}
int work2_complex(matrix_complex *a, matrix_complex *b, matrix_complex *c, int n)
{
	Line_complex *pla, *plb, *plc;
	int i, j, k;
	for (i = 0; i<n; i++)//выделяем память
	{
		plc = c->pmatr + i;
		plc->n = n;
		plc->pa = (complex *)calloc(n, sizeof(complex));
	}
	for (i = 0; i<n; i++)//сдвиг по строкам а и с
	{
		pla = a->pmatr + i;
		plc = c->pmatr + i;
		for (k = 0; k<n; k++)//сдвиг по стоблцу в б
			for (j = 0; j<n; j++)//сдвиг по столбцам а и с
			{
				plb = b->pmatr + j;

				plc->pa[k].real += pla->pa[j].real*plb->pa[k].real - pla->pa[j].im*plb->pa[k].im;//плц-указ на строку, па[k]указ на элт строки, в ц исп к, в а исп а
				plc->pa[k].im += pla->pa[j].real*plb->pa[k].im + pla->pa[j].im*plb->pa[k].real;
			}
	}
	return 1;
}
void case_int(matrix_int *a, matrix_int *b, matrix_int *c)
{
	int n, lgg, temp;
	do {
		do
		{
			printf("Vvedite razmer matric\n");
			lgg = getint(&n);
		} while (lgg == 1);
		printf("Vvedite matrucy A\n");
		getmatrix_int(a, n);
		printf("\nMatrica A:\n");
		printmatr_int(a);
		printf("Vvedite matrucy B\n");
		getmatrix_int(b, n);
		printf("Matrica B:\n");
		printmatr_int(b);
		c = (matrix_int *)calloc(1, sizeof(matrix_int));
		c->lines = n;
		c->pmatr = (Line_int *)calloc(n, sizeof(Line_int));
		printf("Viberite deistvie:\n");
		printf("1:Slojenie\n");
		printf("2:Umnojenie\n");

		do {
			do
			{
				lgg = getint(&temp);
			} while (lgg == 1);

			if (temp == 1)
			{
				temp = work1_int(a, b, c, n);
				break;
			}
			else
				if (temp == 2)
				{
					temp = work2_int(a, b, c, n);
					break;
				}
				else
					printf("Error\n");
		} while (true);
		printf("\nMatrica C:\n");
		printmatr_int(c);
		erase_int(c);
		erase_int(a);
		erase_int(b);
	} while (true);
}
void case_real(matrix_real *a, matrix_real *b, matrix_real *c)
{
	int lgg, n, temp;
	do {
		do
		{
			printf("Vvedite razmer matric\n");
			lgg = getint(&n);
		} while (lgg == 1);
		printf("Vvedite matrucy A\n");
		getmatrix_real(a, n);
		printf("\nMatrica A:\n");
		printmatr_real(a);
		printf("Vvedite matrucy B\n");
		getmatrix_real(b, n);
		printf("Matrica B:\n");
		printmatr_real(b);
		c = (matrix_real *)calloc(1, sizeof(matrix_real));
		c->lines = n;
		c->pmatr = (Line_real *)calloc(n, sizeof(Line_real));
		printf("Viberite deistvie:\n");
		printf("1:Slojenie\n");
		printf("2:Umnojenie\n");
		scanf("%*c");
		do {
			do
			{
				lgg = getint(&temp);
			} while (lgg == 1);

			if (temp == 1)
			{
				temp = work1_real(a, b, c, n);
				break;
			}
			else
				if (temp == 2)
				{
					temp = work2_real(a, b, c, n);
					break;
				}
				else
					printf("Error\n");
		} while (true);
		printf("\nMatrica C:\n");
		printmatr_real(c);
		erase_real(c);
		erase_real(a);
		erase_real(b);

	} while (true);
}
void case_complex(matrix_complex *a, matrix_complex *b, matrix_complex *c)
{
	int lgg, n, temp;
	do {
		do
		{
			printf("Vvedite razmer matric\n");
			lgg = getint(&n);
		} while (lgg == 1);
		printf("For correct input, write down the numbers as:\n");
		printf("1 i7 = 1+7i\n");
		printf("1 i-7 = 1-7i\n");
		printf("-1 i7 = -1+7i\n");
		printf("-1 i-7 = -1-7i\n");
		printf("Vvedite matrucy A\n");
		getmatrix_complex(a, n);
		printf("\nMatrica A:\n");
		printmatr_complex(a);
		printf("Vvedite matrucy B\n");
		getmatrix_complex(b, n);
		printf("Matrica B:\n");
		printmatr_complex(b);
		c = (matrix_complex *)calloc(1, sizeof(matrix_complex));
		c->lines = n;
		c->pmatr = (Line_complex *)calloc(n, sizeof(Line_complex));
		printf("Viberite deistvie:\n");
		printf("1:Slojenie\n");
		printf("2:Umnojenie\n");
		do {
			do
			{
				lgg = getint(&temp);
			} while (lgg == 1);

			if (temp == 1)
			{
				temp = work1_complex(a, b, c, n);
				break;
			}
			else
				if (temp == 2)
				{
					temp = work2_complex(a, b, c, n);
					break;
				}
				else
					printf("Error\n");
		} while (true);
		printf("\nMatrica C:\n");
		printmatr_complex(c);
		erase_complex(c);
		erase_complex(a);
		erase_complex(b);
	} while (true);
}
int sravnenie_int(matrix_int *c1, matrix_int *c2, int n)
{

	int i, j;
	Line_int *plc1, *plc2;
	for (i = 0; i < n; i++)
	{
		plc1 = c1->pmatr + i;
		plc2 = c2->pmatr + i;//загоняем значения в указатели, чтобы работать
		for (j = 0; j < n; j++)
		{
			if (*(plc1->pa + j) != *(plc2->pa + j))
				return 0;
		}
	}
	return 1;
}
int sravnenie_real(matrix_real *c1, matrix_real *c2, int n)
{

	int i, j;
	Line_real *plc1, *plc2;
	for (i = 0; i < n; i++)
	{
		plc1 = c1->pmatr + i;
		plc2 = c2->pmatr + i;//загоняем значения в указатели, чтобы работать
		for (j = 0; j < n; j++)
		{
			if (fabs(*(plc1->pa + j) - *(plc2->pa + j))>0.0001)
				return 0;
		}
	}
	return 1;
}
int sravnenie_complex(matrix_complex *c1, matrix_complex *c2, int n)
{

	int i, j;
	Line_complex *plc1, *plc2;
	for (i = 0; i < n; i++)
	{
		plc1 = c1->pmatr + i;
		plc2 = c2->pmatr + i;//загоняем значения в указатели, чтобы работать
		for (j = 0; j < n; j++)
		{
			if ((plc1->pa[j].real!=plc2->pa[j].real)||(plc1->pa[j].im!=plc2->pa[j].im))
				return 0;
		}
	}
	return 1;
}
void case_file_int(int N, FILE *in)
{
	int temp1,temp2;
	matrix_int a = { 0, NULL };
	matrix_int b = { 0, NULL };
	matrix_int *c1_int;
	matrix_int *d1_int;
	matrix_int *c2_int;
	matrix_int *d2_int;
	c1_int = (matrix_int *)calloc(1, sizeof(matrix_int));
	c2_int = (matrix_int *)calloc(1, sizeof(matrix_int));
	d1_int = (matrix_int *)calloc(1, sizeof(matrix_int));
	d2_int = (matrix_int *)calloc(1, sizeof(matrix_int));
	c1_int->lines = N;
	c1_int->pmatr = (Line_int *)calloc(N, sizeof(Line_int));
	c2_int->lines = N;
	c2_int->pmatr = (Line_int *)calloc(N, sizeof(Line_int));
	d1_int->lines = N;
	d1_int->pmatr = (Line_int *)calloc(N, sizeof(Line_int));
	d2_int->lines = N;
	d2_int->pmatr = (Line_int *)calloc(N, sizeof(Line_int));
	getmatrix_int_file(&a, N, in);
	getmatrix_int_file(&b, N, in);
	temp1 = work1_int(&a, &b, c1_int, N);
	temp2 = work2_int(&a, &b, d1_int, N);
	getmatrix_int_file(c2_int, N, in);
	getmatrix_int_file(d2_int, N, in);
	temp1 = sravnenie_int(c1_int, c2_int, N);
	temp2 = sravnenie_int(d1_int, d2_int, N);
	if (temp1&&temp2)
		printf("Test is correct");
	else
		printf("Incorrect\n");
		if (!temp1)
		printf("Error in summa");
		if (!temp2)
		printf("Error in umnojenie");
		erase_int(c1_int);
		erase_int(c2_int);
    	erase_int(d1_int);
		erase_int(d2_int);			
		erase_int(&a);
		erase_int(&b);
}
void case_file_real(int N, FILE *in)
{
	int temp1,temp2;
	matrix_real a = { 0, NULL };
	matrix_real b = { 0, NULL };
	matrix_real *c1_real;
	matrix_real *d1_real;
	matrix_real *c2_real;
	matrix_real *d2_real;
	c1_real = (matrix_real *)calloc(1, sizeof(matrix_real));
	c2_real = (matrix_real *)calloc(1, sizeof(matrix_real));
	d1_real = (matrix_real *)calloc(1, sizeof(matrix_real));
	d2_real = (matrix_real *)calloc(1, sizeof(matrix_real));
	c1_real->lines = N;
	c1_real->pmatr = (Line_real *)calloc(N, sizeof(Line_real));
	c2_real->lines = N;
	c2_real->pmatr = (Line_real *)calloc(N, sizeof(Line_real));
	d1_real->lines = N;
	d1_real->pmatr = (Line_real *)calloc(N, sizeof(Line_real));
	d2_real->lines = N;
	d2_real->pmatr = (Line_real *)calloc(N, sizeof(Line_real));
	getmatrix_file_real(&a, N, in);
	getmatrix_file_real(&b, N, in);
	temp1 = work1_real(&a, &b, c1_real, N);
	temp2 = work2_real(&a, &b, d1_real, N);
	getmatrix_file_real(c2_real, N, in);
	getmatrix_file_real(d2_real, N, in);
	temp1 = sravnenie_real(c1_real, c2_real, N);
	temp2 = sravnenie_real(d1_real, d2_real, N);
	if (temp1&&temp2)
		printf("Test is correct");
	else
		printf("Incorrect\n");
		if (!temp1)
		printf("Error in summa");
		if (!temp2)
		printf("Error in umnojenie");
		erase_real(c1_real);
		erase_real(c2_real);
		erase_real(d1_real);
		erase_real(d2_real);
		erase_real(&a);
		erase_real(&b);
}
void case_file_complex(int N, FILE *in)
{
	int temp1,temp2;
	matrix_complex a = { 0, NULL };
	matrix_complex b = { 0, NULL };
	matrix_complex *c1_complex;
	matrix_complex *d1_complex;
	matrix_complex *c2_complex;
	matrix_complex *d2_complex;
	c1_complex = (matrix_complex *)calloc(1, sizeof(matrix_complex));
	c2_complex = (matrix_complex *)calloc(1, sizeof(matrix_complex));
	d1_complex = (matrix_complex *)calloc(1, sizeof(matrix_complex));
	d2_complex = (matrix_complex *)calloc(1, sizeof(matrix_complex));
	c1_complex->lines = N;
	c1_complex->pmatr = (Line_complex *)calloc(N, sizeof(Line_complex));
	c2_complex->lines = N;
	c2_complex->pmatr = (Line_complex *)calloc(N, sizeof(Line_complex));
	d1_complex->lines = N;
	d1_complex->pmatr = (Line_complex *)calloc(N, sizeof(Line_complex));
	d2_complex->lines = N;
	d2_complex->pmatr = (Line_complex *)calloc(N, sizeof(Line_complex));
	getmatrix_file_complex(&a, N, in);
	getmatrix_file_complex(&b, N, in);
	temp1 = work1_complex(&a, &b, c1_complex, N);
	temp2 = work2_complex(&a, &b, d1_complex, N);
	getmatrix_file_complex(c2_complex, N, in);
	getmatrix_file_complex(d2_complex, N, in);
	temp1 = sravnenie_complex(c1_complex, c2_complex, N);
	temp2 = sravnenie_complex(d1_complex, d2_complex, N);
	if (temp1&&temp2)
		printf("Test is correct");
	else
		printf("Incorrect\n");
		if (!temp1)
		printf("Error in summa");
		if (!temp2)
		printf("Error in umnojenie");
		erase_complex(c1_complex);
		erase_complex(c2_complex);
    	erase_complex(d1_complex);
		erase_complex(d2_complex);			
		erase_complex(&a);
		erase_complex(&b);
}
bool read_test_file(FILE *in)
{
	bool res = true;
	int N = 0;
	int type_data = 0;
	int k, temp1,temp2;
	fscanf(in, "%d%d", &type_data, &N);
	if (type_data==1)
		case_file_int(N, in);		
	if (type_data==2)
	case_file_real(N,in);
	if (type_data==3)
	case_file_complex(N,in);
	return res;
}
int main()
{
	int n, lgg = 1, temp = 0;
	printf("choose deystvie\n");
	printf("1: Tests\n");
	printf("2: Hand-made\n");
	do {
		do
		{
			lgg = getint(&temp);
		} while (lgg == 1);

		if (temp == 1)
		{
			FILE *pFile = fopen("test_square_matrix.txt", "rt");
			if (pFile == NULL)
			{
				printf("Error opening file!\n");
				return -1;
			}
			int inx = 1;
			while (!feof(pFile))
			{
				printf("Number Test: %d\n", inx);
				read_test_file(pFile);
				printf("\n");
				inx++;
			}
			fclose(pFile);
			return 0;
		}
		if (temp == 2)
		{
			printf("Choose tip dannyh:\n");
			printf("1: Integer\n");
			printf("2: Real\n");
			printf("3: Complex\n");
			do {
				do
				{
					lgg = getint(&temp);
				} while (lgg == 1);

				if (temp == 1)
				{
					Line_int pa = { 0, NULL };
					matrix_int a = { 0, NULL };
					matrix_int b = { 0, NULL };
					matrix_int *c;
					case_int(&a, &b, c);
				}
				else
					if (temp == 2)
					{
						Line_real pa = { 0, NULL };
						matrix_real a = { 0, NULL };
						matrix_real b = { 0, NULL };
						matrix_real *c;
						case_real(&a, &b, c);
					}
					else
						if (temp == 3)
						{
							Line_complex pa = { 0, NULL };
							matrix_complex a = { 0, NULL };
							matrix_complex b = { 0, NULL };
							matrix_complex *c;
							case_complex(&a, &b, c);
						}
						else
							printf("Error\n");
			} while (true);
		}
		else
			printf("Error\n");
	} while (true);
	return 0;
}
