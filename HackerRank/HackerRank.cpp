#include"stdafx.h" 
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <time.h>
#include <vector>

double* one_round(double* numb_zombies, int roads[][2],const int n, const int m, const int nb_tours) {

	std::vector<int> nb_adj(n);
	int i, a, b, k, j;
	double *new_numb_zombies = malloc(n * sizeof(double));
	// Calcul du nombre de sommets adjacents pour chaque sommet
	for (i = 0; i<n; i++) {
		nb_adj[i] = 0;
	}

	for (i = 0; i<m; i++) {
		a = roads[i][0];
		b = roads[i][1];
		nb_adj[a] += 1;
		nb_adj[b] += 1;
	}

	int max_adj = nb_adj[0];

	for (i = 1; i<n; i++) {
		if (nb_adj[i] > max_adj) {
			max_adj = nb_adj[i];
		}
	}
	int adj[n][max_adj];

	// Construction de la liste d'adjacence
	for (i = 0; i<n; i++) {
		k = 0;
		for (j = 0; j < m; j++) {
			if (roads[j][0] == i) {
				adj[i][k] = roads[j][1];
				k++;
			}
			else if (roads[j][1] == i) {
				adj[i][k] = roads[j][0];
				k++;
			}
			if (k == nb_adj[i]) {
				break;
			}
		}
	}

	int q, w;
	double* aux;
	clock_t start = clock(), diff;

	for (q = 0; q < nb_tours; q++) {
		for (i = 0; i<n; i++) {
			new_numb_zombies[i] = 0;
			for (k = 0; k < nb_adj[i]; k++) {
				w = adj[i][k];
				new_numb_zombies[i] += numb_zombies[w] / nb_adj[w];
			}
		}
		aux = numb_zombies;
		numb_zombies = new_numb_zombies;
		new_numb_zombies = aux;
	}

	diff = clock() - start;
	int msec = diff * 1000 / CLOCKS_PER_SEC;
	/*    printf("Time taken %d seconds %d milliseconds\n", msec/1000, msec%1000);*/
	free(new_numb_zombies);
	return numb_zombies;
}

void insertionSort(double a[], int array_size)
{
	int i, j;
	double index;
	for (i = 1; i < array_size; ++i)
	{
		index = a[i];
		for (j = i; j > 0 && a[j - 1] < index; j--)
			a[j] = a[j - 1];

		a[j] = index;
	}
}

int min(int a, int b) {

	int min;
	if (a < b) {
		min = a;
	}
	else {
		min = b;
	}
	return min;
}
int main() {

	/*    FILE *fp;
	FILE *fp2;
	fp = freopen ("logfile", "a+", stdout);
	fp2 = freopen ("input", "a+", stdin);*/
	int t, n, m, k, p;
	int i;
	scanf("%d", &t);
	for (p = 0; p<t; p++) {
		scanf("%d %d %d", &n, &m, &k);
		int roads[m][2];
		double *numb_zombies = malloc(sizeof(double)*n);
		int nb_zombies[n];
		for (i = 0; i<m; i++) {
			scanf("%d %d", &(roads[i][0]), &(roads[i][1]));
		}
		for (i = 0; i<n; i++) {
			scanf("%lf", &(numb_zombies[i]));
		}
		double sum = 0;
		for (i = 0; i<n; i++) {
			sum += numb_zombies[i];
		}
		numb_zombies = one_round(numb_zombies, roads, n, m, k);
		sum = 0;
		for (i = 0; i<n; i++) {
			sum += numb_zombies[i];
		}
		insertionSort(numb_zombies, n);

		for (i = 0; i<n; i++) {
			nb_zombies[i] = (int)round(numb_zombies[i]);
		}

		for (i = 0; i< 4; i++) {
			printf("%d ", nb_zombies[i]);
		}
		printf("%d", nb_zombies[4]);
		printf("\n");

		free(numb_zombies);
	}


	return 0;
}