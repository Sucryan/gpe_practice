// Fill the container
#include <bits/stdc++.h>
using namespace std;
bool canFill(const vector<int>& vessels, int n, int capacity){
    int curSum = 0;
    int containerNum = 1;
    for(int vessel : vessels){
        //printf("vessel: %d, containerNum: %d, curSum: %d, capacity: %d\n", vessel, containerNum, curSum, capacity);
        if(curSum + vessel > capacity){
            containerNum++;
            curSum = vessel;
            if(containerNum > n) return false;
        }
        else curSum += vessel;
    }
    return true;
}
int binarySearch(const vector<int>& vessels, int n){
    int ans;
    int left = *max_element(vessels.begin(), vessels.end());
    int right = 0;
    for(auto vessel : vessels) right += vessel;
    int mid = 0;
    while(left < right) {
        printf("left:%d right:%d\n", left, right);
        mid = (left+right)/2;
        printf("mid: %d\n", mid);
        if(canFill(vessels, n, mid)) {
            right = mid;
        }
        else {
            left = mid+1;
        }
    }
    
    ans = left;
    return ans;
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<int> vessels;
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        vessels.push_back(a);
    }
    printf("%d\n", binarySearch(vessels, n));
}