#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void tien(vector<int>& result,vector<vector<int>> times, int n,int m,vector<int> &machine) 
{
	for (int i = 0; i < n; i++) {
		int min = machine[0] + times[0][i];
		int iMin = 0;
		for (int j = 1; j < m; j++) {
			if (machine[j] + times[j][i] < min) {
				min = machine[j] + times[j][i];
				iMin = j;
			}
		}
		machine[iMin] += times[iMin][i];
		result.push_back(iMin);
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> result;
	vector<vector<int>> times;
	vector<int> machine(m,0);
	for (int i = 0; i < m; i++) {
		vector<int> tempvec;
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			tempvec.push_back(temp);
		}
		times.push_back(tempvec);
	}
	tien(result, times, n, m, machine);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}