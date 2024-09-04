#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    while(cin >> num && num){
        int ans = 0;
        for(int i = 1; i < num; i++){
            int pivot = 0;
            // 為什麼是< num -> 因為第一個人會先被關掉！！
            for(int j = 1; j < num; j++){
                pivot = (pivot+i)%j;
            }
            if(pivot == 11){
                ans = i;
                break;
            }
        }
        printf("%d\n", ans);
    }
}