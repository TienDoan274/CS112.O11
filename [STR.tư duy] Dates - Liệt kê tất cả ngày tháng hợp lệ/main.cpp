#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

bool isSpecialLeapYear(int year) {
    return (year > 0) && (year % 3328 == 0);
}

bool isLeapYear(int year) {
    return (year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0));
}

bool ngayhople(const string& date) {
    if (date.length() != 8) {
        return false;
    }

    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(4, 2));
    int day = stoi(date.substr(6, 2));

    if (year <= 0 || month <= 0 || day <= 0 || month > 12) {
        return false;
    }

    int daysInMonth = 31;

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    }
    else if (month == 2) {
        if (isLeapYear(year) || isSpecialLeapYear(year)) {
            daysInMonth = 29;
        }
        else {
            daysInMonth = 28;
        }
    }

    return day <= daysInMonth;
}

void tien(int i, string date, string& permu, vector<bool>& used, set<string>& result) {
    if (i == date.length()) {
        if (ngayhople(permu)) {
            result.insert(permu);
        }
        return;
    }

    for (int j = 0; j < date.length(); j++) {
        if (!used[j]) {
            permu[i] = date[j];
            used[j] = true;

            tien(i + 1, date, permu, used, result);

            used[j] = false;
        }
    }
}

int main() {
    string date;
    getline(cin, date);

    date = date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2);

    string permu = "        ";

    vector<bool> used(8, false);

    set<string> result;

    tien(0, date, permu, used, result);

    cout << result.size() << "\n";

    for (string s : result) {
        s.insert(6, " ");
        s.insert(4, " ");
        cout << s << endl;
    }

    return 0;
}