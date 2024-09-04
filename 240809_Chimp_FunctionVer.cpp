//uva 10611 The Playboy Chimp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> ladies(n);
    for (int i = 0; i < n; i++) {
        cin >> ladies[i];
    }

    cin >> q;
    while (q--) {
        int luchu;
        cin >> luchu;
        //不需要自己手刻二分搜尋其實，如果是在已經排列好的數列搜尋數字的話！
        auto lower = lower_bound(ladies.begin(), ladies.end(), luchu);
        auto upper = upper_bound(ladies.begin(), ladies.end(), luchu);

        if (lower == ladies.begin()) {
            cout << "X ";
        } else {
            cout << *(lower - 1) << " ";
        }

        if (upper == ladies.end()) {
            cout << "X\n";
        } else {
            cout << *upper << "\n";
        }
    }
    return 0;
}