// 主要是在練習set的用法！
// 注意！：這個算法會WA...，請見錯題練習區看正確算法！
#include <bits/stdc++.h>
using namespace std;

const double inf = 1e9-1;

struct Point{
    int x, y;
    Point(): x(0), y(0){};
    Point(int _x, int _y) : x(_x), y(_y){};
};

int main(){
    int num, pNum;
    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> pNum;
        set<pair<double, double>> s;
        vector<Point> v;
        
        for(int j = 0; j < pNum; j++){
            Point a;
            cin >> a.x >> a.y;
            v.push_back(a);
        }

        for(int j = 0; j < pNum; j++){
            for(int k = j+1; k < pNum; k++){
                double dy = v[j].y - v[k].y;
                double dx = v[j].x - v[k].x;
                if(dx == 0){
                    //這行要記住一下！
                    s.insert({inf, v[j].x});    
                }
                else{
                    double slope = dy / dx;
                    double intersect = v[j].y - slope * v[j].x;
                    s.insert({slope, intersect});
                }
            }
        }
        cout << s.size() << endl;
    }
    
}