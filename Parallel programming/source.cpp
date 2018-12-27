
#include <cilk\cilk.h>
#include <cilk\cilk_api.h>
#include <omp.h>
#include <iostream>
#include <math.h>
#include <cilk\reducer.h>
#include <cilk\reducer_opadd.h>
#include <fstream>

using namespace std;

int Mul_Cilk_IntAxB(int thread, int** MasA, int n, int** MasB, int** MasC)
{/*Ïåðåìíîæåíèå öåëî÷èñëåííûõ ìàòðèö ñ ïîìîùüþ òåõíîëîãèè Cilk */
	double start, endt;
	double x;
	if (thread == 1)     __cilkrts_set_param("nworkers", "1");
	if (thread == 2)     __cilkrts_set_param("nworkers", "2");
	if (thread == 3)     __cilkrts_set_param("nworkers", "3");
	if (thread == 4)     __cilkrts_set_param("nworkers", "4");
	ofstream out("output.txt", ios::out | ios::app);
	start = omp_get_wtime();
	for (int k = 0; k < 50; k++)
	{
		cilk_for(int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				MasC[i][j] = MasA[i][j] * MasB[i][j];
			}
		}
	}
	endt = omp_get_wtime();
	out << "Cilk_for time " << thread << " thread - " << (endt - start) / 50.0 << endl;
	start = omp_get_wtime();
	cilk_for(int k = 0; k < 50; k++)
	{
		MasC[0:n][0:n] = MasA[0:n][0:n] * MasB[0:n][0:n];
	}
	endt = omp_get_wtime();
	out << "Cilk_for time (full index) " << thread << " thread - " << (endt - start) / 50.0 << endl;
	__cilkrts_end_cilk();
	return;
}

double sum_intel(int thread, double** MasA, int n)
{/*Ñóììèðîâàíèå öåëî÷èñëåííûõ ìàòðèö ñ ïîìîùüþ òåõíîëîãèè Cilk */
	double start, endt;
	double x, sum = 0.0;
	if (thread == 1)     __cilkrts_set_param("nworkers", "1");
	if (thread == 2)     __cilkrts_set_param("nworkers", "2");
	if (thread == 3)     __cilkrts_set_param("nworkers", "3");
	if (thread == 4)     __cilkrts_set_param("nworkers", "4");
	ofstream out("output.txt", ios::out | ios::app);
	sum = 0.0;
	start = omp_get_wtime();
	for (int k = 0; k < 50; k++){
		cilk_for(int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				sum += MasA[i][j];
			}
		}
	}
	endt = omp_get_wtime();
	out << "Cilk_for time " << thread << " thread - " << (endt - start) / 50.0 << endl;
	sum = 0.0;
	start = omp_get_wtime();
	cilk_for(int k = 0; k < 50; k++){
		sum = __sec_reduce_max(MasA[0:n][0:n]);
	}
	endt = omp_get_wtime();
	out << "Cilk_for time (full index) " << thread << " thread - " << (endt - start) / 50.0 << endl;
	__cilkrts_end_cilk();
	return;
}

int sum_intel(int thread, int** MasA, int n)
{/*Ñóììèðîâàíèå öåëî÷èñëåííûõ ìàòðèö ñ ïîìîùüþ òåõíîëîãèè Cilk */
	double start, endt;
	double x;
	int sum = 0;
	if (thread == 1)     __cilkrts_set_param("nworkers", "1");
	if (thread == 2)     __cilkrts_set_param("nworkers", "2");
	if (thread == 3)     __cilkrts_set_param("nworkers", "3");
	if (thread == 4)     __cilkrts_set_param("nworkers", "4");
	ofstream out("output.txt", ios::out | ios::app);
	sum = 0;
	start = omp_get_wtime();
	for (int k = 0; k < 50; k++){
		cilk_for(int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				sum += MasA[i][j];
			}
		}
	}
	endt = omp_get_wtime();
	out << "Cilk_for time " << thread << " thread - " << (endt - start) / 50.0 << endl;
	sum = 0;
	start = omp_get_wtime();
	cilk_for(int k = 0; k < 50; k++){
		sum = __sec_reduce_max(MasA[0:n][0:n]);
	}
	endt = omp_get_wtime();
	out << "Cilk_for time (full index) " << thread << " thread - " << (endt - start) / 50.0 << endl;
	__cilkrts_end_cilk();
	return;
}

double Sum_Cilk_DoubleAxB(int thread, double** MasA, int n, double** MasB, double** MasC)
{/*Ñëîæåíèå äâóõ âåùåñòâåííûõ ìàññèâîâ ñ ïîìîùüþ òåõíîëîãèè Cilk */
	double start, endt;
	double x;
	if (thread == 1)     __cilkrts_set_param("nworkers", "1");
	if (thread == 2)     __cilkrts_set_param("nworkers", "2");
	if (thread == 3)     __cilkrts_set_param("nworkers", "3");
	if (thread == 4)     __cilkrts_set_param("nworkers", "4");
	ofstream out("output.txt", ios::out | ios::app);
	start = omp_get_wtime();
	for (int k = 0; k < 50; k++){
		cilk_for(int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				MasC[i][j] = MasA[i][j] + MasB[i][j];
			}
		}
	}
	endt = omp_get_wtime();
	out << "Cilk_for time " << thread << " thread - " << (endt - start) / 50.0 << endl;
	start = omp_get_wtime();
	cilk_for (int k = 0; k < 50; k++){
		MasC[0:n][0:n] = MasA[0:n][0:n] + MasB[0:n][0:n];
	}
	endt = omp_get_wtime();
	out << "Cilk_for time (full index) "  << thread << " thread - " << (endt - start) / 50.0 << endl;
	__cilkrts_end_cilk();
	return ;
}

int Sum_Cilk_IntAxB(int thread, int** MasA, int n, int** MasB, int** MasC)
{/*Ñëîæåíèå äâóõ öåëî÷èñëåííûõ ìàññèâîâ ñ ïîìîùüþ òåõíîëîãèè Cilk */
	double start, endt;
	double x;
	if (thread == 1)     __cilkrts_set_param("nworkers", "1");
	if (thread == 2)     __cilkrts_set_param("nworkers", "2");
	if (thread == 3)     __cilkrts_set_param("nworkers", "3");
	if (thread == 4)     __cilkrts_set_param("nworkers", "4");
	ofstream out("output.txt", ios::out | ios::app);
	start = omp_get_wtime();
	for (int k = 0; k < 50; k++){
		cilk_for(int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				MasC[i][j] = MasA[i][j] + MasB[i][j];
			}
		}
	}
	endt = omp_get_wtime();
	out << "Cilk_for time" << thread << " thread - " << (endt - start) / 50.0 << endl;
	start = omp_get_wtime();
	cilk_for(int k = 0; k < 50; k++){
		MasC[0:n][0:n] = MasA[0:n][0:n] + MasB[0:n][0:n];
	}
	endt = omp_get_wtime();
	out << "Cilk_for time (full index) " << thread << " thread - " << (endt - start) / 50.0 << endl;
	__cilkrts_end_cilk();
	return;
}

double Mul_Cilk_IntAxB(int thread, double** MasA, int n, double** MasB, double** MasC)
{/*Ïðîèçâåäåíèå äâóõ âåùåñòâåííûõ ìàññèâîâ ñ ïîìîùüþ òåõíîëîãèè Cilk */
	double start, endt;
	double x;
	if (thread == 1)     __cilkrts_set_param("nworkers", "1");
	if (thread == 2)     __cilkrts_set_param("nworkers", "2");
	if (thread == 3)     __cilkrts_set_param("nworkers", "3");
	if (thread == 4)     __cilkrts_set_param("nworkers", "4");
	ofstream out("output.txt", ios::out | ios::app);
	start = omp_get_wtime();
	for (int k = 0; k < 50; k++){
		cilk_for(int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				MasC[i][j] = MasA[i][j] * MasB[i][j];
			}
		}
	}
	endt = omp_get_wtime();
	out << "Cilk_for time " << thread << " thread - " << (endt - start) / 50.0 << endl;
	start = omp_get_wtime();
	cilk_for(int k = 0; k < 50; k++){
		MasC[0:n][0:n] = MasA[0:n][0:n] * MasB[0:n][0:n];
	}
	endt = omp_get_wtime();
	out << "Cilk_for time (full index) " << thread << " thread - " << (endt - start) / 50.0 << endl;
	__cilkrts_end_cilk();
	return;
}

double max_intel(int thread, double** MasA, int n)
{/*Íàõîæäåíèå ìàêñèìàëüíîãî ýëåìåíòà âåùåñòâåííîãî ìàññèâà ñ ïîìîùüþ òåõíîëîãèè Cilk */
	double start, endt;
	double x, max;
	if (thread == 1)     __cilkrts_set_param("nworkers", "1");
	if (thread == 2)     __cilkrts_set_param("nworkers", "2");
	if (thread == 3)     __cilkrts_set_param("nworkers", "3");
	if (thread == 4)     __cilkrts_set_param("nworkers", "4");
	ofstream out("output.txt", ios::out | ios::app);
	max = MasA[0][0];
	start = omp_get_wtime();
	for (int k = 0; k < 50; k++){
		cilk_for(int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (max < MasA[i][j]){
					max = MasA[0][0];
				}
			}
		}
	}
	endt = omp_get_wtime();
	out << "Cilk_for time " << thread << " thread - " << (endt - start) / 50.0 << endl;
	max = MasA[0][0];
	start = omp_get_wtime();
	cilk_for(int k = 0; k < 50; k++){
		max = __sec_reduce_max(MasA[0:n][0:n]);//Íàõîæäåíèå ìàêñèìàëüíîãî çíà÷åíèÿ
	}
	endt = omp_get_wtime();
	out << "Cilk_for time (full index) " << thread << " thread - " << (endt - start) / 50.0 << endl;
	__cilkrts_end_cilk();
	return;
}

int max_intel(int thread, int** MasA, int n)
{/*Íàõîæäåíèå ìàêñèìàëüíîãî ýëåìåíòà öåëî÷èñëåííîãî ìàññèâà ñ ïîìîùüþ òåõíîëîãèè Cilk */
	double start, endt;
	double x;
	int max;
	if (thread == 1)     __cilkrts_set_param("nworkers", "1");
	if (thread == 2)     __cilkrts_set_param("nworkers", "2");
	if (thread == 3)     __cilkrts_set_param("nworkers", "3");
	if (thread == 4)     __cilkrts_set_param("nworkers", "4");
	ofstream out("output.txt", ios::out | ios::app);
	max = MasA[0][0];
	start = omp_get_wtime();
	for (int k = 0; k < 50; k++)
	{cilk_for(int i = 0; i < n; i++)
		{for (int j = 0; j < n; j++){
				if (max < MasA[i][j])
				{
					max = MasA[0][0];
				}
			}
		}
	}
	endt = omp_get_wtime();
	out << "Cilk_for time " << thread << " thread : " << (endt - start) / 50.0 << endl;
	max = MasA[0][0];
	start = omp_get_wtime();
	cilk_for(int k = 0; k < 50; k++){
		max = __sec_reduce_max(MasA[0:n][0:n]);
	}
	endt = omp_get_wtime();
	out << "Cilk_for time (full index) " << thread << " thread : " << (endt - start) / 50.0 << endl;
	__cilkrts_end_cilk();
	return;
}

int Sum_OMP_IntAxB(int** MasA, int n, int** MasB, int** MasC)
{/*Ñëîæåíèå äâóõ öåëî÷èñëåííûõ ìàòðèö A è B OMP*/
	int sum = 0;
	int i, j;
#pragma omp parallel for shared (MasA) private(i)\
	firstprivate(sum)
	for (i = 0; i < n; i++){
#pragma omp parallel for private(j) \
	firstprivate(i) reduction(+:sum)
		for (j = 0; j < n; j++){
			MasC[i][j] = MasA[i][j] + MasB[i][j];
		}
	}
	return sum;
}

double Sum_OMP_DoubleAxB(double** MasA, int n, double** MasB, double** MasC)
{/*Ñëîæåíèå äâóõ âåùåñòâåííûõ ìàòðèö A è B ñ ïîìîùüþ òåõíîëîãèè OMP*/
	double sum = 0.0;
	int i, j;
#pragma omp parallel for shared (MasA) private(i)\
	firstprivate(sum)
	for (i = 0; i < n; i++){
#pragma omp parallel for private(j) \
	firstprivate(i) reduction(+:sum)
		for (j = 0; j < n; j++){
			MasC[i][j] = MasA[i][j] + MasB[i][j];
		}
	}
	return sum;
}

double mul_omp_AxB(double** MasA, int n, double** MasB, double** MasC)
{/*Ïðîèçâåäåíèå äâóõ âåùåñòâåííûõ ìàòðèö A è B ñ ïîìîùüþ òåõíîëîãèè OMP*/
	double sum = 0.0;
	int i, j;
#pragma omp parallel for shared (MasA) private(i)\
	firstprivate(sum)
	for (i = 0; i < n; i++){
#pragma omp parallel for private(j) \
	firstprivate(i) reduction(+:sum)
		for (j = 0; j < n; j++)	{
			MasC[i][j] = MasA[i][j] * MasB[i][j];
		}
	}
	return sum;
}

int mul_omp_AxB(int** MasA, int n, int** MasB, int** MasC)
{/*Ïðîèçâåäåíèå äâóõ öåëî÷èñëåííûõ ìàòðèö A è B ñ ïîìîùüþ òåõíîëîãèè OMP*/
	int sum = 0;
	int i, j;
#pragma omp parallel for shared (MasA) private(i)\
	firstprivate(sum)
	for (i = 0; i < n; i++){
#pragma omp parallel for private(j) \
	firstprivate(i) reduction(+:sum)
		for (j = 0; j < n; j++){
			MasC[i][j] = MasA[i][j] * MasB[i][j];
		}
	}
	return sum;
}

double sum_omp(double** MasA, int n)
{/*Ñóììèðîâàíèå ýëåìåíòîâ ìàññèâà À âåùåñòâåííîãî ñ ïîìîùüþ òåõíîëîãèè OMP*/
	double sum = 0.0;
	int i, j;
#pragma omp parallel for shared (MasA) private(i)\
	firstprivate(sum)
	for (i = 0; i < n; i++){
#pragma omp parallel for private(j) \
	firstprivate(i) reduction(+:sum)
		for (j = 0; j < n; j++){
			sum += MasA[i][j];
		}
	}
	return sum;
}

int sum_omp(int** MasA, int n)
{/*Ñóììèðîâàíèå ýëåìåíòîâ ìàññèâà À öåëî÷èñëåííîãî òèïà ñ ïîìîùüþ òåõíîëîãèè OMP*/
	int sum = 0;
	int i, j;
#pragma omp parallel for shared (MasA) private(i)\
	firstprivate(sum)
	for (i = 0; i < n; i++){
#pragma omp parallel for private(j) \
	firstprivate(i) reduction(+:sum)
		for (j = 0; j < n; j++){
			sum += MasA[i][j];
		}
	}
	return sum;
}

double max_omp(double** MasA, int n)
{/*Íàõîæäåíèå ìàêñèìàëüíîãî ýëåìåíòà ìàññèâà À âåùåñòâåííîãî òèïà ñ ïîìîùüþ òåõíîëîãèè OMP*/
	double max = MasA[0][0];
	int i, j;
#pragma omp parallel for shared (MasA) private(i)\
	firstprivate(max)
	for (i = 0; i < n; i++){
#pragma omp parallel for private(j) \
	firstprivate(i)
		for (j = 0; j < n; j++){
			if (max < MasA[i][j]){
				max = MasA[i][j];
			}
		}
	}
	return max;
}

int max_omp(int** MasA, int n)
{/*Íàõîæäåíèå ìàêñèìàëüíîãî ýëåìåíòà À öåëî÷èñëåííîãî òèïà ñ ïîìîùüþ òåõíîëîãèè OMP*/
	int max = MasA[0][0];
	int i, j;
#pragma omp parallel for shared (MasA) private(i)\
	firstprivate(max)
	for (i = 0; i < n; i++){
#pragma omp parallel for private(j) \
	firstprivate(i)
		for (j = 0; j < n; j++){
			if (max < MasA[i][j]){
				max = MasA[i][j];
			}
		}
	}
	return max;
}


void main()
{
	setlocale(0, "");
	ofstream out("output.txt", ios::out | ios::app);
	double start, end;
	int n = 2000;
	double** masA = new double*[n];
	for (int i = 0; i < n; i++){
		masA[i] = new double[n];
	}
	double** masC = new double*[n];
	for (int i = 0; i < n; i++){
		masC[i] = new double[n];
	}
	double** masB = new double*[n];
	for (int i = 0; i < n; i++){
		masB[i] = new double[n];}
	///////////////////////////////////////////////////
	int** masA_int = new int*[n];
	for (int i = 0; i < n; i++){
		masA_int[i] = new int[n];}

	int** masC_int = new int*[n];
	for (int i = 0; i < n; i++){
		masC_int[i] = new int[n];}

	int** masB_int = new int*[n];
	for (int i = 0; i < n; i++){
		masB_int[i] = new int[n];}

	//Çàïîëíåíèå ìàññèâîâ
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			masA[i][j] = rand() % 15;
			masB[i][j] = rand() % 15;
			masA_int[i][j] = rand() % 15;
			masB_int[i][j] = rand() % 15;
		}
	}
	out << "**********\n";
	out << "Double sum AxB\n";
	for (int p = 1; p < 5; p++)
	{
		omp_set_num_threads(p);
		start = omp_get_wtime();
		for (int i = 0; i < 50; i++)
			Sum_OMP_DoubleAxB(masA, n, masB, masC);
		end = omp_get_wtime();
		out << "OMP time " << p << " theard - " << (end - start) / 50.0 << endl;
	}

	for (int p = 1; p < 5; p++){
		double time = Sum_Cilk_DoubleAxB(p, masA, n, masB, masC);
	}

	out << "**********\n";
	out << "Int sum AxB\n";
	for (int p = 1; p < 5; p++){
		omp_set_num_threads(p);
		start = omp_get_wtime();
		for (int i = 0; i < 50; i++)
			Sum_OMP_IntAxB(masA_int, n, masB_int, masC_int);
		end = omp_get_wtime();
		out << "OMP time " << p << " theard - " << (end - start) / 50.0 << endl;
	}

	for (int p = 1; p < 5; p++)
	{
		double time = Sum_Cilk_IntAxB(p, masA_int, n, masB_int, masC_int);
	}
	out << "**********\n";
	out << "Double mul AxB\n";
	for (int p = 1; p < 5; p++){
		omp_set_num_threads(p);
		start = omp_get_wtime();
		for (int i = 0; i < 50; i++)
			mul_omp_AxB(masA, n, masB, masC);
		end = omp_get_wtime();
		out << "OMP time " << p << " theard - " << (end - start) / 50.0 << endl;
	}

	for (int p = 1; p < 5; p++){
		double time = Mul_Cilk_IntAxB(p, masA, n, masB, masC);
	}
	out << "**********\n";
	out << "Int mul AxB\n";
	for (int p = 1; p < 5; p++){
		omp_set_num_threads(p);
		start = omp_get_wtime();
		for (int i = 0; i < 50; i++)
			mul_omp_AxB(masA_int, n, masB_int, masC_int);
		end = omp_get_wtime();
		out << "OMP time " << p << " theard - " << (end - start) / 50.0 << endl;
	}

	for (int p = 1; p < 5; p++){
		double time = Mul_Cilk_IntAxB(p, masA_int, n, masB_int, masC_int);
	}
	out << "**********\n";
	out << "Double sum of elements\n";
	for (int p = 1; p < 5; p++){
		omp_set_num_threads(p);
		start = omp_get_wtime();
		for (int i = 0; i < 50; i++)
			sum_omp(masA, n);
		end = omp_get_wtime();
		out << "OMP time " << p << " theard - " << (end - start) / 50.0 << endl;
	}

	for (int p = 1; p < 5; p++)
	{
		double time = sum_intel(p, masA, n);
	}
	out << "**********\n";
	out << "Int sum of elements\n";
	for (int p = 1; p < 5; p++){
		omp_set_num_threads(p);
		start = omp_get_wtime();
		for (int i = 0; i < 50; i++)
			sum_omp(masA_int, n);
		end = omp_get_wtime();
		out << "OMP time " << p << " theard - " << (end - start) / 50.0 << endl;
	}

	for (int p = 1; p < 5; p++){
		double time = sum_intel(p, masA_int, n);
	}
	out << "**********\n";
	out << "Max double\n";
	for (int p = 1; p < 5; p++){
		omp_set_num_threads(p);
		start = omp_get_wtime();
		for (int i = 0; i < 50; i++)
			max_omp(masA, n);
		end = omp_get_wtime();
		out << "OMP time " << p << " theard - " << (end - start) / 50.0 << endl;
	}

	for (int p = 1; p < 5; p++){
		double time = max_intel(p, masA, n);
	}
	out << "**********\n";
	out << "Max int\n";
	for (int p = 1; p < 5; p++){
		omp_set_num_threads(p);
		start = omp_get_wtime();
		for (int i = 0; i < 50; i++)
			max_omp(masA_int, n);
		end = omp_get_wtime();
		out << "OMP time " << p << " theard - " << (end - start) / 50.0 << endl;
	}
	for (int p = 1; p < 5; p++){
		double time = max_intel(p, masA_int, n);
	}
	cout<<"Done!"<<endl;
	system("pause");
	delete masA;
	delete masB;
	delete masC; 
	delete masA_int;
	delete masB_int;
	delete masC_int;
}
