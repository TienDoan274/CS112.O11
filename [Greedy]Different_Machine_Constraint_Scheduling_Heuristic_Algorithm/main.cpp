#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void tien(vector<int>& result, vector<vector<int>> times, int n, int m, vector<int>& machine)
{
	for (int i = 0; i < n; i++) {
		int min = -1;
		int iMin = -1;
		for (int k = 0; k < m; k++) {
			if (times[k][i] != -1) {
				min = machine[k] + times[k][i];
				iMin = k;
				break;
			}
		}
		for (int j = 0; j < m; j++) {
			if (machine[j] + times[j][i] < min && times[j][i]!=-1) {
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
	vector<int> machine(m, 0);
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