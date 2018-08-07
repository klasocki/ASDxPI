#include <iostream>
#include <cstddef>

using namespace std;

typedef struct Node {
    int n;
    struct Node* next;
} Node;

enum color {
    white,
    gray,
    black
};

bool find_cycle_from(Node** graph, color* visited, int n, int x) {
    // gray color means "we already processed this node in current lookup" - once x is gray, we are sure we've got a cycle
    if(visited[x]==gray) return true;
    // mark x grey
    visited[x]=gray;

    // iterate over each neighbour and proceed with DFS (recursively or using stack)
    Node* tmp=graph[x];
    while(tmp!=NULL) {
        if(find_cycle_from(graph,visited,n,tmp->n)) return true;
        tmp=tmp->next;
    }
        // once you found cycle - return immediately
    visited[x]=black;
    // black means "ok, we finally processed that node" - mark x black

    // found nothing? Return
    return false;
}

bool has_cycle(Node** graph, int n) {
    color visited[n];
    for (int i=0; i<n; i++) visited[i] = white;
    for(int i = 0; i<n; i++) {
        if (visited[i] == white) {
            if (find_cycle_from(graph, visited, n, i)) return true;
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n;
    Node **graph = new Node*[n];
    for(int i=0; i<n; i++) graph[i]=NULL;

    cin >> k;
    for(int i=0; i<k; i++) {
        Node* tmp = new Node;
        int x, y;
        cin >> x;
        cin >> y;
        tmp->n = y;
        tmp->next = graph[x];
        graph[x] = tmp;
    }
    cout << (has_cycle(graph, n) ? "CYKL" : "OK") << endl;
}
