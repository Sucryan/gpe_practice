#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    while(cin >> num && num){
        int arr[num];
        for(int i = 0; i < num; i++){
            cin >> arr[i];
        }
        // a + b + c = d;
        set<int> xSet;
        for(int i = 0; i < num; i++){
            for(int j = i; j < num; j++){
                for(int k = j; k < num; k++){
                    int tmp = arr[i]+arr[j]+arr[k];
                    xSet.insert(tmp);
                }
            }
        }
        int maxD = -536870913;
        for(int i = 0; i < num; i++){
            if(xSet.find(arr[i]) != xSet.end()){
                maxD = max(maxD, arr[i]);
            }
        }
        if(maxD == -536870913) printf("no solution\n");
        else printf("%d\n", maxD);
    }    
}