// Created on iPad.

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.length(), n2 = s2.length();
    int dp[n1+1][n2+1];
    for(int i = 0; i <=  n1; i++){
        for(int j = 0; j <=  n2; j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 1; i <=  n1; i++){
        for(int j = 1; j <=  n2; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    string ans = "";
    int it1 = n1, it2 = n2;
    while(it1 > 0 && it2 > 0){
        if(s1[it1-1] == s2[it2-1]){
            ans += s1[it1-1];
            it1--;
            it2--;
        }
        else if(dp[it1-1][it2] > dp[it1][it2-1]){
            it1--;
        }
        else it2--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
