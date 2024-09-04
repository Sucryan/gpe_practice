// disk tree
#include <bits/stdc++.h>
using namespace std;

int TrieSize = 0;

struct Node{
    string c;
    map<string, int> next;
    Node() {
        next.clear();
    }
    void init(string s){
        c = s;
        next.clear();
    }   
} nodes[100000];

void insertTrie(vector<string> s){
    //pivot!
    int p = 0;
    for(int i = 0; i < s.size(); i++){
        //如果沒有找到的話
        if(nodes[p].next.find(s[i]) == nodes[p].next.end()){
            // 先去TrieArray裡面init一個空間給他用
            nodes[++TrieSize].init(s[i]);
            // 利用map標示這個字位在第幾號位置（因為是新插入的位置一定是在TrieSize處）
            nodes[p].next[s[i]] = TrieSize;
        }
        //通過上面的if，不論存不存在，現在一定可以在next裡面找到他！
        p = nodes[p].next[s[i]];
    }
}

void dfs(int u, int depth){
    if(u){
        for(int i = 1; i < depth; i++){
            printf(" ");
        }
        printf("%s\n", nodes[u].c.c_str());
    }
    for(auto it = nodes[u].next.begin(); it != nodes[u].next.end(); it++){
        //概念：利用迴圈一個一個跑
        /* ex. 
            /home/games/a
            /home/games/b
            首先會先跑到 "", 也就是root
            然後在root底下只會有home這個目錄 -> 存在1裡面 -> dfs(1, 1)
            接下來跑去home一樣下面只有games -> dfs(2,2)
            但是games下面會有兩個，所以
            接下來先跑去a -> 存在3裡面 -> dfs(3,3)
            然後再跑去b -> 存在4裡面 -> dfs(4,3)
            然後他們的for都跑不下去 因為裡面的next會是空的！
            
        */
        dfs(it->second, depth+1);
    }
}

int main(){
    // 控制輸入的數量
    int num;
    while(cin >> num && num){
        TrieSize = 0;
        nodes[0].init("");
        for(int i = 0; i < num; i++){
            string input;
            cin >> input;
            stringstream ss(input);
            string token = "";
            vector<string> d;
            // std::getline(input_stream, string_variable, delimiter);
            // input_stream: 可以是cin 或者 stringstream
            // delimiter: 看到什麼就變成 "\n"
            // 遇到EOF就會結束迴圈
            while(getline(ss, token, '\\')){
                if(!token.empty()){
                    d.push_back(token);
                }
            }
            insertTrie(d);
        }
        dfs(0, 0);
    }
}