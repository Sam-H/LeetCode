#include"stdafx.h" 
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <complex>

using std::vector;
using std::cin;
using std::cout;

double norm(vector<double>& vect1, vector<double>& vect2)
{
	double norm = 0;
	for (int i = 0; i < vect2.size(); ++i)
	{
		norm += pow(vect1[i] - vect2[i], 2);
	}
	return sqrt(norm);
}

vector<double> one_round(vector<double>& numb_zombies, vector<vector<int>>& roads, int n, int m, int nb_tours) {

	vector<int> nb_adj(n);
	vector<double> new_numb_zombies(n);

	for (int i = 0; i<n; i++) {
		nb_adj[i] = 0;
	}

	for (int i = 0; i<m; i++) {
		nb_adj[roads[i][0]] += 1;
		nb_adj[roads[i][1]] += 1;
	}

	int max_adj = nb_adj[0];

	for (int i = 1; i<n; i++) {
		if (nb_adj[i] > max_adj) {
			max_adj = nb_adj[i];
		}
	}

	vector<vector<double>> incomingProbability(n, vector<double>(max_adj));
	vector<vector<int>> incomingSource(n, vector<int>(max_adj));

	for (int k = 0; k < m; ++k)
	{
		int i = roads[k][0];
		int j = roads[k][1];

		incomingSource[i].push_back(j);
		incomingProbability[i].push_back(1.0 / nb_adj[j]);

		incomingSource[j].push_back(i);
		incomingProbability[j].push_back(1.0 / nb_adj[i]);
	}

	for (int q = 0; q < nb_tours; q++) {
		for (int i = 0; i<n; i++) {
			new_numb_zombies[i] = 0;
			for (int k = 0; k < incomingSource[i].size(); k++) {
				new_numb_zombies[i] += incomingProbability[i][k]*numb_zombies[incomingSource[i][k]];
			}
		}
		if (norm(new_numb_zombies, numb_zombies) < 1e-6) break;
		numb_zombies = new_numb_zombies;
	}

	return numb_zombies;
}

int main() {

	std::istream* input_stream;
	std::ifstream input("C:\\Users\\Samy\\Documents\\Visual Studio 2015\\Projects\\Programming Challenges\\HackerRank\\input06.txt");
	input_stream = &input;
	//input_stream = &cin;


	int t, n, m, k, p;
	int i;
	*input_stream >> t;
	for (p = 0; p<t; p++) {
		*input_stream >> n >> m >> k;
		vector<vector<int>> roads(m, vector<int>(2));
		vector<double> numb_zombies(n);
		vector<int> nb_zombies(n);

		for (i = 0; i<m; i++) {
			*input_stream >> roads[i][0] >> roads[i][1];
		}
		for (i = 0; i<n; i++) {
			*input_stream >> numb_zombies[i];
		}

		numb_zombies = one_round(numb_zombies, roads, n, m, k);

		std::sort(numb_zombies.begin(), numb_zombies.end(), std::greater<double>());

		for (i = 0; i<n; i++) {
			nb_zombies[i] = (int)round(numb_zombies[i]);
		}

		for (i = 0; i< 5; i++) {
			cout << nb_zombies[i] << " ";
		}
		cout << std::endl;
	
	}

	return 0;
}