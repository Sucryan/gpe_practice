//UVa 11413 - Fill the Containers

//解題思路：為什麼會想到要使用binary search
/*
因為有“單調性” -> 也就是說在某一個臨界點以後，所有大於（也可以是小於，但以這題來說是大於）這個數值的都會符合答案，並且我們想要知道這個臨界值的數值是多少！
=> 所以一開始會先取left是單個最大值，因為這是所有解的lower bound，right取全部加總，這個是upper bound。
*/
#include <bits/stdc++.h>

using namespace std;

bool canFill(const vector<int>& vessels, int m, long long capacity) {
    //手刻時發生的錯誤：記得是從第一杯開始算！
    int containers = 1;
    //為什麼要long long
    long long currentSum = 0;
    // 為什麼需要照順序 -> 題目說他們是放在輸送帶上，需要按照順序加上去！
    for (int vessel : vessels) {
        if (currentSum + vessel > capacity) {
            //換一杯
            containers++;
            //下一杯從這個開始倒入
            currentSum = vessel;
            //杯子不夠！-> 代表這個條件不可能達成
            if (containers > m) return false;
        } 
        else {
            currentSum += vessel;
        }
    }
    
    return true;
}

int findMinCapacity(const vector<int>& vessels, int m) {
    //left: 取最大值
    long long left = *max_element(vessels.begin(), vessels.end());
    long long right = 0;
    //right: 取全部加總
    for (int vessel : vessels) right += vessel;
    
    while (left < right) {
        long long mid = left + (right - left) / 2;
        //capacity塞的是mid -> 也就是當前預設的答案
        if (canFill(vessels, m, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    //手刻時的錯誤：需要取left:
    //解題關鍵
    /*
    因為你的right代表的是最大的解（一開始是加總，後來會存入只要大於或者==這個數值一定都可以（因為所有mid都會跑過canFill，且right不是所有加總就是確定可以的mid））
    也就是說以
    5 3
    1 2 3 4 5
    為例：
    一開始mid = (5 + 15) /2 = 10 -> 7 -> 6，在此時, mid == 6 => right == 6
    接下來進入下一個迴圈，mid = 5 -> 進入canFill發現錯誤，則left = mid+1
    最後在while發現這個left == right -> 代表這個left一定會對
    所以最後return left!

    */
    return left;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<int> vessels(n);
        for (int i = 0; i < n; i++) {
            cin >> vessels[i];
        }
        
        cout << findMinCapacity(vessels, m) << endl;
    }
    return 0;
}