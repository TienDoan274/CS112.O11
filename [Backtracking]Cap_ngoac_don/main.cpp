#include<iostream>
#include<vector>
#include<string>
using namespace std;

int check(char ngoac) {
    if (ngoac == ')') return -1;
    return 1;
}

int checkmo(char ngoac) {
    if (ngoac == '(') return 1;
    return 0;
}


void tien(int k, vector<char>& result, vector<char> ngoac, int countmo, int count, int n) {
    for (int i = 0; i < 2; i++) {
        if (countmo + check(ngoac[i]) >= 0 && count + checkmo(ngoac[i]) <= n) {
            countmo += check(ngoac[i]);
            count += checkmo(ngoac[i]);
            result.push_back(ngoac[i]);

            if (k == 2 * n - 1) {
                for (int j = 0; j < result.size(); j++) {
                    cout << result[j];
                }
                cout << endl;
            }
            else {
                tien(k + 1, result, ngoac, countmo, count, n);
            }

            countmo -= check(ngoac[i]);
            count -= checkmo(ngoac[i]);
            result.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;

    int countmo = 0;
    int count = 0;
    vector<char> result;
    vector<char> ngoac;
    ngoac.push_back('(');
    ngoac.push_back(')');

    tien(0, result, ngoac, countmo, count, n);

    return 0;
}