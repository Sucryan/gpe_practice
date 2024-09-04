//dfs迷宮
#include <bits/stdc++.h>
using namespace std; 

int m, n;

bool dfs(vector<vector<int>>& map, pair<int, int> startP, pair<int, int> endP){
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int sx = startP.first;
    int sy = startP.second;
    visited[sx][sy] = true;
    stack<pair<int, int>> s;
    s.push(startP);

    while(!s.empty()){
        auto cur = s.top();
        s.pop();
        //應該寫在迴圈內！
        if(cur == endP) return true;  // 找到終點

        for(int i = 0; i < 4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && map[nx][ny] != 1){
                s.push({nx, ny});
                visited[nx][ny] = true;
            }
        }

        // 打印當前訪問狀態
        cout << "Current state:" << endl;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++){
                if(make_pair(i, j) == cur) cout << "C ";
                else if(visited[i][j]) cout << "V ";
                else if(map[i][j] == 1) cout << "# ";
                else cout << ". ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return false;  // 沒找到路徑
}

int main(){
    cin >> m >> n;
    vector<vector<int>> map(m, vector<int>(n, 0));
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    pair<int, int> startP, endP;
    cin >> startP.first >> startP.second;
    cin >> endP.first >> endP.second;

    if(dfs(map, startP, endP)){
        cout << "We found the Path!!!" << endl;
    }
    else cout << "Path not found :(" << endl;

    return 0;
}