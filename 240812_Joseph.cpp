// 經典約瑟夫問題變化！
//題目
/*
問題背景：
    有 2k 個人站成一個圓圈，編號從 1 到 2k。
    淘汰規則：
    從 1 號開始報數。
    每數到 m 的人就會被淘汰出局。
    被淘汰的人離開圓圈，剩下的人繼續從 1 開始報數。
特殊要求：
    我們希望前 k 個被淘汰的人恰好是編號 k+1 到 2k 的人。
    換句話說，最後剩下的 k 個人應該是編號 1 到 k 的人。
任務：
    對於給定的 k（1 ≤ k ≤ 13），找出滿足上述條件的最小的 m 值。
輸入輸出：
    輸入包含多個測試用例，每個用例是一個整數 k。
    當 k = 0 時，表示輸入結束。
    對於每個非零的 k，輸出對應的最小 m 值。
例子：
    如果 k = 3，那麼我們有 6 個人（1, 2, 3, 4, 5, 6）。
    我們需要找到一個 m，使得 4, 5, 6 先被淘汰，最後剩下 1, 2, 3。
*/

// 基本上這題目只有暴力解，因為他基本上沒辦法使用數學解去解出答案，要快的話因為他只有1~13，你可以偷吃步把1~13先算出來存進arr裡面！
#include <bits/stdc++.h>
using namespace std;
// f(n, k) = (f(n-1, k)+k) % n;
int main(){
    int input;
    while(cin >> input && input){
        int m = input+1;
        //找到一刀切多大才會過！
        while(true){
            //pivot!
            int p = 0;
            //總共要切 input(k) 刀
            bool valid = true;
            for(int k = 0; k < input; k++){
                p += m-1;
                p %= input*2 - k;
                if(p < input){
                    valid = false;
                    break;
                }
            }
            if(valid){
                break;
            }
            m++;
        }
        printf("%d\n", m);
    }    
}