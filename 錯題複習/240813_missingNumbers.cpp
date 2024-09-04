#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    vector<set<int> > lists(M);
    
    // Read all numbers into sets
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N - i; j++) {
            int num;
            scanf("%d", &num);
            lists[i].insert(num);
        }
    }
    
    // Find and print missing numbers
    for (int i = 0; i < M - 1; i++) {
        for (int num : lists[i]) {
            if (lists[i+1].find(num) == lists[i+1].end()) {
                printf("%d\n", num);
                break;
            }
        }
    }

    return 0;
}