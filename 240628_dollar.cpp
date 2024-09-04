#include <bits/stdc++.h>
using namespace std;
//Making Change - basic
// int arr[7] = {1, 5, 10 , 50, 100, 500, 1000};
// int main(){
//     int num;
//     cin >> num;
//     vector<int> calculator;
//     for(int i = 0; i < 10000; i++){
//         calculator.push_back(i);
//     }
//     for(int i = 0; i < 10000; i++){
//         for(int j = 0; j < 7; j++){
//             if(i-arr[j] >= 0){    
//                 calculator[i] = min(calculator[i-arr[j]], calculator[i])+1;
//             }
//         }
//     }
//     printf("%d\n", calculator[num]);
// }