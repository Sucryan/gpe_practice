#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    while (cin >> k && k) {
        // 從 k+1 開始嘗試，因為從1開始嘗試沒意義！
        int m = k + 1;  
        while (true) {
            // 宣告在這裡才是合理的
            int p = 0;
            bool valid = true;
            // 總共應該切k刀！
            for (int i = 0; i < k; i++) {
                // 下一個位置應該會在 p+m-1(因為本來的位置也會被算一次)，然後% 2k - i(因為人會越來越少)
                p = (p + m - 1) % (2 * k - i);
                if (p < k) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                cout << m << endl;
                break;
            }
            m++;
        }
    }
    return 0;
}