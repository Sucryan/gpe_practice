#include <bits/stdc++.h>
using namespace std;
//第一份
int require = 0, ans = 0, visited[3][100];
void search(int n){
    if(n == require) ans++;
    else for(int i = 0; i < require; i++){
        if(!visited[0][i] && !visited[1][n+i] && !visited[2][n-i+require]){
            visited[0][i] = visited[1][n+i] = visited[2][n-i+require] = 1;
            search(n+1);
            visited[0][i] = visited[1][n+i] = visited[2][n-i+require] = 0;
        }
    }
}
int main(){
    cin >> require;
    search(0);
    printf("%d\n", ans);
}
/*
//第二份
int n, ans=0, put[100], visited[3][100];
void search(int now){
    if(now == n) ans++; //跑到最後一行了，代表這組解ok
    else for(int i=0; i<n; i++){
        if(!visited[0][i] && !visited[1][now+i] && !visited[2][now-i+n]){
            //比直的；比x+y對角線(x是now,y是i)；比x-y對角線(因為會出現負值所以+n)
            put[now] = i; //把第now行的皇后放在第i列
            visited[0][i] = visited[1][now+i] = visited[2][now-i+n] = 1;
            search(now+1);
            visited[0][i] = visited[1][now+i] = visited[2][now-i+n] = 0; //改回來
        }
    }
}

int main(){
    cin >> n;
    search(0);
    cout << ans << '\n';
}
//[input] 8 [output] 92
*/