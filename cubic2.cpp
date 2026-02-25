#include <iostream>
#include <vector>
using namespace std;

int nextPos(const vector<int>& v, int last) {
    for (int x : v)
        if (x > last) return x;
    return -1;
}

int main() {

    //string S = "pzzqqqqqyyyyypzzpzza";
    string S = "abxxyeabdxabyex";
    int n = S.size();

    vector<int> pos[26];
    int freq[26] = {0};

    for (int i = 0; i < n; i++) {
        int id = S[i] - 'a';
        pos[id].push_back(i);
        freq[id]++;
    }

    bool used[26] = {false};

    for (int i = 0; i < n; i++) {

        int c = S[i] - 'a';

        if (used[c]) continue;
        used[c] = true;

        if (freq[c] < 3) continue;

        int last1 = pos[c][0];
        int last2 = pos[c][1];
        int last3 = pos[c][2];

        string X;
        X += char(c + 'a');

        while (true) {

            bool extended = false;

            for (int j = last1 + 1; j < n; j++) {

                int d = S[j] - 'a';

                if (d == c) continue;          // ❗ DO NOT reuse start letter
                if (freq[d] < 3) continue;

                int n1 = nextPos(pos[d], last1);
                int n2 = nextPos(pos[d], last2);
                int n3 = nextPos(pos[d], last3);

                if (n1 != -1 && n2 != -1 && n3 != -1) {

                    if (n1 < n2 && n2 < n3) {

                        X += char(d + 'a');

                        last1 = n1;
                        last2 = n2;
                        last3 = n3;

                        extended = true;
                        break;
                    }
                }
            }

            if (!extended)
                break;
        }

        cout << X << endl;
    }

    return 0;
}
