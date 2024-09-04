//Bachet's games
#include <bits/stdc++.h>
using namespace std;

using namespace std;

string solve_bachet_game(int n, const vector<int>& moves) {
    vector<bool> dp(n + 1, false);
    
    for (int i = 1; i <= n; ++i) {
        for (int move : moves) {
            //取dp[i-move]的反過來的狀態 -> 也就是假設你在dp[i-move]會贏，那你在dp[i]這個狀態下就會輸
            //反之亦然：所以假設!dp[i-move] -> 代表在dp[i]的情況下你會贏！
            //而且直接初始化從0開始就好，因為輪到stan時如果直接是0那他秒輸！
            if (i >= move && !dp[i - move]) {
                dp[i] = true;
                break;
            }
        }
    }
    
    return dp[n] ? "Stan wins" : "Ollie wins";
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<int> moves(m);
        for (int i = 0; i < m; ++i) {
            cin >> moves[i];
        }
        cout << solve_bachet_game(n, moves) << endl;
    }
    return 0;
}