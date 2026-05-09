#include <bits/stdc++.h>
using namespace std;

class Bank {
private:
    unordered_map<string, long long> accounts;

public:
    bool CREATE(string X, long long Y) {
        if (accounts.find(X) == accounts.end()) {
            accounts[X] = Y;
            return true;
        } else {
            accounts[X] += Y;
            return false;
        }
    }

    bool DEBIT(string X, long long Y) {
        if (accounts.find(X) == accounts.end() || accounts[X] < Y) {
            return false;
        }
        accounts[X] -= Y;
        return true;
    }

    bool CREDIT(string X, long long Y) {
        if (accounts.find(X) == accounts.end()) {
            return false;
        }
        accounts[X] += Y;
        return true;
    }

    long long BALANCE(string X) {
        if (accounts.find(X) == accounts.end()) {
            return -1;
        }
        return accounts[X];
    }
};

int main() {
    int Q;
    cin >> Q;
    cin.ignore();

    Bank bank;

    while (Q--) {
        string query;
        getline(cin, query);

        stringstream ss(query);
        string type, X;
        long long Y;

        ss >> type;

        if (type == "CREATE") {
            ss >> X >> Y;
            cout << (bank.CREATE(X, Y) ? "true" : "false") << endl;
        }
        else if (type == "DEBIT") {
            ss >> X >> Y;
            cout << (bank.DEBIT(X, Y) ? "true" : "false") << endl;
        }
        else if (type == "CREDIT") {
            ss >> X >> Y;
            cout << (bank.CREDIT(X, Y) ? "true" : "false") << endl;
        }
        else if (type == "BALANCE") {
            ss >> X;
            cout << bank.BALANCE(X) << endl;
        }
    }

    return 0;
}
