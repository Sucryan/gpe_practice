#include <bits/stdc++.h>
using namespace std;
// gcd記得背起來！
/*
思考案例：
ex1. gcd(0, 1) -> gcd(1, 0) -> return 0;
ex2. gcd(0, 0) -> return 0;
ex3. gcd(11, 13) -> gcd(13, 11) -> gcd(11, 2) -> gcd(2, 1) -> gcd(1, 0) -> return 1;
ex4. gcd(15, 20) -> gcd(20, 15) -> gcd(15, 5) -> gcd(5, 0) -> return 5; 
*/
int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a%b);
}

struct Point{
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y){}
    Point() : x(0), y(0){};
};

struct Line{
    int a, b, c;
    Line(const Point& p1, const Point& p2){
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = p1.x * p2.y - p2.x * p1.y;
        int g = gcd(abs(a), gcd(abs(b), abs(c)));
        if(g > 0){
            a /= g;
            b /= g;
            c /= g;
        }
        if(a < 0 || (a == 0 && b < 0)){
            a = -a;
            b = -b;
            c = -c;
        }
    }
    // operator overloading! 要練習怎麼寫！
    // 給set讓他知道怎麼比較！
    // 如何撰寫？
    bool operator<(const Line& other) const{
        if(a != other.a) return a < other.a;
        else if(b != other.b) return b < other.b;
        else return c < other.c;
    }
};

int countUniqueLines(const vector<Point>& v){
    set<Line> s;
    for(int i = 0; i < v.size(); i++){
        for(int j = i+1; j < v.size(); j++){
            Line l(v[i], v[j]);
            s.insert(l);
        }
    }
    return s.size();
}

int main(){
    int num;
    cin >> num;
    while(num--){
        vector<Point> p;
        int pNum;
        cin >> pNum;
        for(int i = 0; i < pNum; i++){
            Point tmp;
            scanf("%d %d", &tmp.x, &tmp.y);
            p.push_back(tmp);
        }    
        printf("%d\n", countUniqueLines(p));
    }
}