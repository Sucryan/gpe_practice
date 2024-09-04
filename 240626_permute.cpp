#include <bits/stdc++.h>
using namespace std;

// 輔助函數，用於生成所有排列
void permute(string s, int start, int end, vector<string>& result) {
    if (start == end) {
        result.push_back(s);
    } else {
        for (int i = start; i <= end; ++i) {
            swap(s[start], s[i]);    // 交換字符
            permute(s, start + 1, end, result); // 遞歸調用
            swap(s[start], s[i]);    // 還原字符
        }
    }
}

// 主函數，用於初始化排列過程
vector<string> getPermutations(string s) {
    vector<string> result;
    permute(s, 0, s.size() - 1, result);
    return result;
}

int main() {
    string s = "abc";
    vector<string> permutations = getPermutations(s);

    for (const string& permutation : permutations) {
        cout << permutation << endl;
    }

    return 0;
}
