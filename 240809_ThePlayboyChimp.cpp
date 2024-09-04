//uva 10611 The Playboy Chimp
//建議寫法：看Chimp_FunctionVer!
#include <bits/stdc++.h>
using namespace std;

char ans1, ans2;
void binarySearch(const vector<int>& lady, int Luchu){
    int left = 0;
    int right = lady.size()-1;
    int mid = 0;
    // printf("check!\n");
    // for(auto print:lady){
    //     printf("%d ", print);
    // }
    //printf("lady_left:%d, lady_right:%d, Luchu:%d\n", lady[left], lady[right], Luchu);
    if(Luchu > lady[right]){
        ans1 = lady[right]+'0';
        ans2 = 'X';
        return;
    }
    if(Luchu < lady[left]){
        ans1 = 'X';
        ans2 = lady[left]+'0';
        return;
    }
    while(left < right){
        mid = (left+right)/2;
        if(Luchu > lady[mid]){
            left = mid+1;
        }
        else if(Luchu < lady[mid]){
            right = mid;
        }
        else if(Luchu == lady[mid]){
            ans1 = lady[mid-1]+'0';
            ans2 = lady[mid+1]+'0';
            break;
        }
    }
    if(left >= right){
        ans1 = lady[right-1]+'0';
        ans2 = lady[right]+'0';
    }
    
}

int main(){
    int num, Q;
    vector<int> lady, Luchu;
    cin >> num;
    for(int i = 0; i < num; i++){
        int a = 0;
        cin >> a;
        lady.push_back(a);
    }
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int a = 0;
        cin >> a;
        Luchu.push_back(a);
    }
    for(auto q : Luchu){
        binarySearch(lady, q);
        printf("%c %c\n", ans1, ans2);
    }
}