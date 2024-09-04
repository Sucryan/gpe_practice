// Uva 10416 Last Digit
#include <bits/stdc++.h>
using namespace std;
// 題目觀察 
/*
    -> 大小是2*10^100 -> 遠大於long long的 64 位元 (2^63 - 1 ~ - 2^63 + 1)
    -> 而且時間壓在3sec -> 有特殊解法！
        -> 發現他只要處理最後一個位 -> 而只需要處理特定位元 -> 可以%10!
            -> 並且因為1^2的%10會跟11^2%10, 21^2%10...一樣 -> 代表1~10, 11~20, 31~40 這幾些區段加起來都一樣，
            -> 代表每100一定會重新循環一次！(A(某個尾數)*10 % 10 == 0)
            -> 反言之，我只要知道一個指定數字的最後兩位，就可以知道他的last digit!
            (ex 一個超大的數字（2*10^90 + 95）,其實就會跟1~95的總和一樣，因為前面是十的倍數的都會被%給處理掉！)
*/
int main(){
    string oNum = ""; //originalNumber!
    int allAns[101] = {0};
    int tenNum[11] = {0, 1, 4, 7, 6, 5, 6, 3, 6, 9};
    for(int i = 1; i <= 100; i++){
        allAns[i] = (allAns[i-1]+tenNum[i%10]) % 10;
    }
    int s = oNum.size();
    while(cin >> oNum){
        if(oNum == "0") break;
        int num = 0;
        if(s >= 2) num = (oNum[s-2]-'0') * 10 + (oNum[s-1]-'0');
        else num = oNum[0]-'0';
        cout << allAns[num] << endl;
    }
}