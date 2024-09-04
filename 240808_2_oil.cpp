//oil deposite
#include <bits/stdc++.h>
using namespace std;
int m, n;
const int dxs[] = {1, 0, 1, -1, 0, -1, 1, -1};
const int dys[] = {0, 1, 1, 0, -1, -1, -1, 1};
void dfs(int x, int y, const vector<vector<char>>& map, vector<vector<bool>>& visited){
    stack<pair<int, int>> s;
    s.push({x, y});
    while(!s.empty()){
        auto cur = s.top();
        s.pop();
        int cx = cur.first;
        int cy = cur.second;
        visited[cx][cy] = true;
        for(int i = 0; i < 8; i++){
            int nx = cx + dxs[i];
            int ny = cy + dys[i];
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny] && map[nx][ny] == '@'){
                s.push({nx, ny});
            }
        }
    }
}

int main(){
    while(cin >> m >> n){
        if(!m && !n) break;
        int sum = 0;
        vector<vector<char>> map(m, vector<char>(n));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> map[i][j];
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(map[i][j] == '@' && !visited[i][j]){
                    dfs(i, j, map, visited);
                    sum += 1;
                } 
            }
        }
        cout << sum << endl;
    }

}