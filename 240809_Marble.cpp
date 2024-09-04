//uva 10474
// AI錯誤 -> 使用unorder map -> 錯誤原因，因為unordered map只會記錄第一次出現這個數字的位置->假設有多個重複數字就會錯誤！
// 並且題目要求的是排序後的順序而不是排序前的！
#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, Q;
    int caseNumber = 1;

    while (true) {
        cin >> N >> Q;
        if (N == 0 && Q == 0) break;

        vector<int> marbles(N);
        for (int i = 0; i < N; i++) {
            cin >> marbles[i];
        }

        sort(marbles.begin(), marbles.end());

        cout << "CASE# " << caseNumber << ":" << endl;

        for (int i = 0; i < Q; i++) {
            int query;
            cin >> query;

            //其實底下是使用二分搜尋！ -> 在已排列好的數列中尋找指定數字 -> 不要自己手刻二分艘，直接使用lower_bound
            auto it = lower_bound(marbles.begin(), marbles.end(), query);
            
            if (it != marbles.end() && *it == query) {
                cout << query << " found at " << (it - marbles.begin() + 1) << endl;
            } else {
                cout << query << " not found" << endl;
            }
        }

        caseNumber++;
    }

    return 0;
}