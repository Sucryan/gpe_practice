// Uva 10038 diskTree
#include <bits/stdc++.h>
using namespace std;

struct Node {
	string c;
    map<string, int> next;
    Node() {
    	next.clear();
    }
    void init(string s) {
    	c = s;
    	next.clear();
    }
} nodes[1048576];//claim it as array!

int TrieSize = 0;

void insertTrie(vector<string> s) {
	int p = 0;
	for (int i = 0; i < s.size(); i++) {
		// if that string does not exist
        if (nodes[p].next.find(s[i]) == nodes[p].next.end()) {
			nodes[++TrieSize].init(s[i]);
			nodes[p].next[s[i]] = TrieSize;
		}
		p = nodes[p].next[s[i]];
	}
}

void dfs(int u, int depth) {
	if (u) {
		for (int i = 1; i < depth; i++)
			printf(" ");
		//c_str()是為了將string這個c++型別，使用c_str()將它轉成c的char* 格式的string -> 可以用 strlen, strcpy...
		printf("%s\n", nodes[u].c.c_str());
	}
	for (map<string, int>::iterator it = nodes[u].next.begin();
		it != nodes[u].next.end(); it++)
		dfs(it->second, depth + 1);
}

int main() {
	int n;
	char s[1024];
	string token;
    //if there is there is any number to input!
	while (scanf("%d", &n) == 1) {
		//make "" as root!
        nodes[0].init("");
		TrieSize = 0;
		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			for (int j = 0; s[j]; j++)
				if (s[j] == '\\') s[j] = ' ';
			stringstream sin(s); //will be pushed with every ''
			vector<string> d;
			while (sin >> token)
				d.push_back(token);
			insertTrie(d);
		}
		dfs(0, 0);
		puts("");
	}
	return 0;
}