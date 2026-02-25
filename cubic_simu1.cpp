#include <iostream>
using namespace std;

// check if X X X is subsequence of S
bool isCubic(string S, string X) {
    int n = S.size();
    int k = X.size();
    int index = 0;   // position in S

    for (int copy = 0; copy < 3; copy++) {
        int j = 0;   // position in X

        while (index < n && j < k) {
            if (S[index] == X[j])
                j++;
            index++;
        }

        if (j < k) return false;  // failed to build one copy
    }

    return true;
}

int main() {

    string S = "pzzqqqqqyyyyypzzpzz";
    int n = S.size();

    // Try base length from 1 to n/3
    for (int len = 1; len <= n/3; len++) {

        for (int i = 0; i + len <= n; i++) {

            string X = S.substr(i, len);

            if (isCubic(S, X)) {
                cout << X << endl;
            }
        }
    }

    return 0;
}
