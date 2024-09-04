#include <bits/stdc++.h>
using namespace std;

int findFirst(const vector<int>& num){
    for(int i = 1; i < num.size(); i++){
        if(num[i-1] > num[i]) return i;
    }
    return 0;
}

int BinarySearch(const vector<int>& num, int target, int left, int right){
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (num[mid] == target) return mid;
        if (num[mid] < target) {
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int search(const vector<int>& num, int target){
    int pivot = findFirst(num);
    if(target >= num[num.size()-1]){
        return BinarySearch(num, target, 0, pivot-1);
    }
    else{
        return BinarySearch(num, target, pivot, num.size()-1);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    vector<int> num;
    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        num.push_back(tmp);
    }
    int target;
    cin >> target;
    printf("%d\n", search(num, target));
}
