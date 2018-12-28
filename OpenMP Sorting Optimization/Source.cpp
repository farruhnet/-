#pragma warning(disable: 4996)
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <omp.h>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <algorithm>

#include "sort.h"
using namespace std;

#define less(x,y)  (x < y)
void swap(double& a,double& b)
{
	double temp;
	temp = b;
	b = a;
	a = temp;
}

void insertionsort(double a[], int n, int stride) {
	for (int j=stride; j<n; j+=stride) {
		double key = a[j];
		int i = j - stride;
		while (i >= 0 && a[i] > key) {
			a[i+stride] = a[i];
			i-=stride;
		}
		a[i+stride] = key;
	}
}

void Sort_Shell(double *mas, double *cpmas,int N)
{
	int i, m;
	memcpy( mas, cpmas, N*sizeof(double));
	for(m = N/2; m > 0; m /= 2)
	{
		for(i = 0; i < m; i++)
			insertionsort(&(cpmas[i]), N-i, m);
	}
}


void Sort_Shell_Shared(double *mas, double *cpmas,int N)               // сортировка Шелла
{
	int i, m;
	memcpy( mas, cpmas, N*sizeof(double));
	for (m = N / 2; m > 0; m /= 2)
	{
#pragma omp parallel for shared(cpmas,m,N) private (i) default(none)
		for(i = 0; i < m; i++)
			insertionsort(&(cpmas[i]), N-i, m);
	}
}

/////////////////////////////////////Заполнение //////////////////////////////////////////////////////////////////////

void Fill_Mas_Red(double *mas,int N)
{//Заполнение массива параллельно с использованием For
#pragma omp parallel for 
	for(int i=0; i<N;i++)
	{
		mas[i] = cos((float)i)*sin((float)i);
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OddEvenSort(double *mas, double *cpmas,int N)
{
	memcpy( mas, cpmas, N*sizeof(double));
	int upper_bound;
	if (N%2==0)
		upper_bound = N/2-1;
	else
		upper_bound = N/2;

	for (int i=0; i<N; i++)
	{
		if (i%2 == 0)
		{
			//четная итерация
			for (int j=0; j<N/2; j++)
				if(cpmas[2*j]>cpmas[2*j+1])
					swap(cpmas[2*j], cpmas[2*j+1]);
		}
		else
		{
			//нечетная итерация
			for (int j=0; j<upper_bound; j++)
				if(cpmas[2*j+1]>cpmas[2*j+2])
					swap(cpmas[2*j+1],cpmas[2*j+2]);
		}
	}
}

void OddEvenSortParal(double *mas, double *cpmas,int N)
{
	memcpy( mas, cpmas, N*sizeof(double));
	int i;
#pragma omp parallel for shared(cpmas,N) private (i)
	for (i = 0; i < N; ++i)
	{
		if (i & 1)
		{
			for (int j = 2; j < N; j += 2)
				if (cpmas[j] < cpmas[j - 1])
					swap(cpmas[j - 1], cpmas[j]);
		}
		else
		{
			for (int j = 1; j < N; j += 2)
				if (cpmas[j] < cpmas[j - 1])
					swap(cpmas[j - 1], cpmas[j]);
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Bubble_Sort(double *mas, double *cpmas,int N)
{//Сортировка последовательно
	double tmp;
	memcpy( mas, cpmas, N*sizeof(double));
	for (int i=0; i < N; i++){     // фильтруем массив
		for (int j=N-1; j > i; j-- )
		{    
			if ( cpmas[j-1] < cpmas[j] )
			{
				tmp=cpmas[j-1];
				cpmas[j-1]=cpmas[j];
				cpmas[j]=tmp;
			}
		}
	}
}

void Bubble_Sort_Par_For(double *mas, double *cpmas,int N)
{
	double tmp;
	int i;
	memcpy( mas, cpmas, N*sizeof(double));
#pragma omp parallel for private (i)
	for (i=0; i < N; i++) {      // фильтруем массив
		for (int j=N-1; j > i; j-- )   
			if ( cpmas[j-1] < cpmas[j] ){
				tmp=cpmas[j-1];
				cpmas[j-1]=cpmas[j];
				cpmas[j]=tmp;
			}
	}
}


void Bubble_Sort_Par_Shedule_Dynamic(double *mas, double *cpmas,int N)
{
	double tmp;
	memcpy( mas, cpmas, N*sizeof(double));
#pragma omp parallel for firstprivate(tmp) schedule(dynamic)
	for (int i=0; i < N; i++){       // фильтруем массив
		for (int j=N-1; j > i; j-- )
		{    
			if ( cpmas[j-1] < cpmas[j] ){
				tmp=cpmas[j-1];
				cpmas[j-1]=cpmas[j];
				cpmas[j]=tmp;
			}
		}
	}
}



void Bubble_Sort_Par_Shared(double *mas, double *cpmas,int N)
{
	double tmp;
	int i,j;
	memcpy( mas, cpmas, N*sizeof(double));
#pragma omp parallel for shared(cpmas) private(tmp,i,j)
	for (i=0; i < N; i++) {      // фильтруем массив
		for (j=N-1; j > i; j-- )
		{    
			if ( cpmas[j-1] < cpmas[j] )
			{
				tmp=cpmas[j-1];
				cpmas[j-1]=cpmas[j];
				cpmas[j]=tmp;
			}
		}
	}
}



void quickSortR(double *mas, double *cpmas,int N)
{
	// На входе - массив a[], a[N] - его последний элемент.
	memcpy( mas, cpmas, N*sizeof(double) );
	long i = 0, j = N; 		// поставить указатели на исходные места
	double temp, p;
	p = cpmas[ N>>1 ];		// центральный элемент

	// процедура разделения
	do {
		while ( cpmas[i] < p ) i++;
		while ( cpmas[j] > p ) j--;
		if (i <= j) {
			temp = cpmas[i];
			cpmas[i] = cpmas[j];
			cpmas[j] = temp;
			i++; j--;
		}
	} while ( i<=j );


	// рекурсивные вызовы, если есть, что сортировать 
	if ( j > 0 ) quickSortR(mas,cpmas, j);
	if ( N > i ) quickSortR(mas,cpmas+i, N-i);
}


void quickSortSec(double *mas, double *cpmas,int N)
{
	// На входе - массив a[], a[N] - его последний элемент.
	memcpy( mas, cpmas, N*sizeof(double));
	long i = 0, j = N; 		// поставить указатели на исходные места
	double temp, p;
	p = cpmas[ N>>1 ];		// центральный элемент

	// процедура разделения
	do {
#pragma omp parallel sections
		{
#pragma omp section
				while ( cpmas[i] < p )
					i++;
#pragma omp section
				while ( cpmas[j] > p )
					j--;
		}
		if (i <= j) {
			temp = cpmas[i];
			cpmas[i] = cpmas[j];
			cpmas[j] = temp;
			i++; j--;
		}
	} while ( i<=j );
#pragma omp parallel sections
	{
			// рекурсивные вызовы, если есть, что сортировать 
#pragma omp section
			if ( j > 0 )
			{
				quickSortR(mas,cpmas, j);
			}
#pragma omp section
			if ( N > i )
			{
				quickSortR(mas,cpmas+i, N-i);
			}
		}
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	double *mas,*cpmas;
	setlocale(0,"");
	srand(time(0));
	int N;
	bool answer = true;
	double start;
	double end;
	cout<<"Введите количество элементов массива"<<endl;
	cin>>N;
	/*Выделение дин. памяти*/ 
	mas=new double [N];
	cpmas=new double [N];
	for (int i = 0; i < N ; i++)
	{
		mas[i]=0.0;
		cpmas[i]=0.0;
	}
	char selection;
	do
	{
		cout << "  ====================================\n";
		cout << "  1.  Заполнить массивы\n";
		cout << "  2.  Таблица \n";
		cout << "  3.  Выход\n";
		cout << "  ====================================\n";
		cout << "  Выберите действие : ";
		cin >> selection;
		cout << endl;
		switch (selection)
		{
		case '1':
			cout<<"Заполнение осуществляется паралеллельным методом For"<<endl;
			Fill_Mas_Red(mas,N);
			break;
		case '2':
			for(int p=1;p<2;p++)
			{
				//omp_set_num_threads(p);
				cout<<"Количество потоков = "<<p<<endl;
				for(int r=0;r<10;r++)
				{
					omp_set_num_threads(p);
					start = omp_get_wtime();
					if(r==0)
					{
						start = omp_get_wtime();
						for(int i=0;i<10;i++)
							Bubble_Sort(mas,cpmas,N);
						end = omp_get_wtime();
						printf_s("Затрачено %f сек Bubble_Послед \n", (end-start)/10);
						start = omp_get_wtime();
					}
					if(r==1)
					{
						start = omp_get_wtime();
						for(int i=0;i<10;i++)
							Bubble_Sort_Par_For(mas,cpmas,N);
						end = omp_get_wtime();
						printf_s("Затрачено %f сек Bubble_Par_For \n", (end-start)/10);
						start = omp_get_wtime();
					}
					if(r==2)
					{
						start = omp_get_wtime();
						for(int i=0;i<10;i++)
							Bubble_Sort_Par_Shedule_Dynamic(mas,cpmas,N);
						end = omp_get_wtime();
						printf_s("Затрачено %f сек Bubble_Par_Shedule_Dynamic \n", (end-start)/10);
						start = omp_get_wtime();
					}
					if(r==3)
					{
						start = omp_get_wtime();
						for(int i=0;i<10;i++)
							Bubble_Sort_Par_Shared(mas,cpmas,N);
						end = omp_get_wtime();
						printf_s("Затрачено %f сек Bubble_Par_Shared\n", (end-start)/10);
						start = omp_get_wtime();
					}
					if(r==4)
					{
						start = omp_get_wtime();
						for(int i=0;i<10;i++)
							Sort_Shell(mas,cpmas,N);
						end = omp_get_wtime();
						printf_s("Затрачено %f сек Shell_Sort(Послед)\n", (end-start)/10);
						start = omp_get_wtime();
					}
					if(r==5)
					{
						start = omp_get_wtime();
						for(int i=0;i<10;i++)
							Sort_Shell_Shared(mas,cpmas,N);
						end = omp_get_wtime();
						printf_s("Затрачено %f сек Shell_Sort(Shared)\n", (end-start)/10);
						start = omp_get_wtime();
					}
					if(r==6)
					{
						start = omp_get_wtime();
						for(int i=0;i<10;i++)
							quickSortR(mas,cpmas,N);
						end = omp_get_wtime();
						printf_s("Затрачено %f сек QuickSort(Послед)\n", (end-start)/10);
						start = omp_get_wtime();
					}
					if(r==7)
					{
						start = omp_get_wtime();
						for(int i=0;i<10;i++)
							quickSortSec(mas,cpmas,N);
						end = omp_get_wtime();
						printf_s("Затрачено %f сек QuickSort(Sec)\n", (end-start)/10);
						start = omp_get_wtime();
					}
					if(r==8)
					{
						start = omp_get_wtime();
						for(int i=0;i<10;i++)
							OddEvenSort(mas,cpmas,N);
						end = omp_get_wtime();
						printf_s("Затрачено %f сек OddEvenSort(Послед)\n", (end-start)/10);
						start = omp_get_wtime();
					}
					if(r==9)
					{
						start = omp_get_wtime();
						for(int i=0;i<10;i++)
							OddEvenSortParal(mas,cpmas,N);
						end = omp_get_wtime();
						printf_s("Затрачено %f сек OddEvenSortParal(Shared)\n", (end-start)/10);
						start = omp_get_wtime();
					}

				}
			}
			break;
		case '3':
			cout << "Пока!! .\n";
			break;
		default: cout <<selection <<"Не известное действие.\n";
			cout<<endl;
		}
	}
	while (selection != 0 );
	delete[] mas;
	delete[] cpmas;
	system("Pause");
	return 0;
}
