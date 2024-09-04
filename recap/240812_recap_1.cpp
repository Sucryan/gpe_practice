// 約瑟夫環問題
// Uva 151 power crisis 
#include <bits/stdc++.h>
using namespace std;

int main(){
    int input;
    while(cin >> input && input){
        // 用迴圈去模擬隔幾個關閉
        int alive = 0;
        for(int i = 1; i < input; i++){
            // 這個迴圈可以顯示出剩下幾個人時候的狀況 +i 讓活著的人可以繼續活著，並顯示他在下一個增加一人的前提下他要是幾號，並且%j => 因為是環狀序列！
            for(int j = 1; j < input; j++){
                alive = (alive+i)%j;
            }
            // 從0開始數第一個然後第一台一定會被關閉 -> alive == 11 就代表是第13台
            if(alive == 11){
                printf("%d\n", i);
                break;
            }
        }
    }
}