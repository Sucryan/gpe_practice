#include <bits/stdc++.h>
using namespace std;

int main(){
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    vector<set<int> > v(n1);
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2-i; j++){
            int tmp;
            scanf("%d", &tmp);
            v[i].insert(tmp);
        }
    }
    for(int i = 0; i < n1-1; i++){
        for(int num : v[i]){
            if(v[i+1].find(num) == v[i+1].end()) {
                printf("%d\n", num);
                break;
            }
        }
    }

}