#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool hople(string a) {
    return a.length() > 0 && (a[0] != '0' || a.length() == 1) && stoi(a) < 256 && a.length() < 4;
}

void tien(int last, string s, vector<string>& result, int& countPhan) {
    for (int i = 1; i <= 3; ++i) {
        if (last + i <= s.length() && hople(s.substr(last, i))) {
            result.push_back(s.substr(last, i));
            countPhan++;
            if (countPhan == 4 && last + i == s.length()) {
                for (int i = 0; i < result.size(); i++) {
                    cout << result[i];
                    if (i != result.size() - 1) cout << ".";
                }
                cout << endl;
            }
            else { 
                tien(last + i, s, result, countPhan);
                
            }
            countPhan--;
            result.pop_back();
        }
    }
}

int main() {
    string s;
    cin >> s;
    vector<string> result;
    int countPhan = 0;
    tien(0, s, result, countPhan);

    return 0;
}