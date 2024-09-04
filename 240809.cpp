//迴文題 
#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(const string& pattern) {
    int n = pattern.length();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

string extendToPalindrome(const string& s) {
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    string pattern = s + "#" + reversed;
    vector<int> lps = computeLPS(pattern);

    int palindromeLength = lps.back();
    string suffix = s.substr(palindromeLength);
    reverse(suffix.begin(), suffix.end());

    return s + suffix;
}

int main() {
    string s;
    while (cin >> s) {
        cout << extendToPalindrome(s) << endl;
    }
    return 0;
}