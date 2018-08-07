#include <iostream>
#include <climits>
#include <vector>
#include <utility>

using namespace std;

const int INF = INT_MAX;

typedef struct Node {
    Node *parent;
    vector <pair<Node *, int> > neighbours;
    int val, dist;
} Node;

Node *newNode(int val) {
    Node *n = new Node;
    n->val = val;
    n->dist = INF;
    n->parent = NULL;
}

void addEdge(Node *u, Node *v, int w) {
    pair <Node *, int> edge(v, w);
    u->neighbours.push_back(edge);
}

void relax(Node *u, Node *v, int weight) {
    // put your code here
    if(v->dist > u->dist + weight) {
        v->dist=u->dist+weight;
        v->parent=u;
    }
}

bool bellmann_ford(Node **nodes, int n, Node *start) {
    // put your code here
    start->dist=0;
    for(int k=0; k<n; k++)
    for(int i=0; i<n; i++) {
        for(int j=0; j<nodes[i]->neighbours.size(); j++) {
            relax(nodes[i], nodes[i]->neighbours[j].first , nodes[i]->neighbours[j].second );
        }

    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<nodes[i]->neighbours.size(); j++) {
            if(nodes[i]->neighbours[j].first->dist > nodes[i]->dist + nodes[i]->neighbours[j].second) return false;
        }

    }

    return true;
}

int main() {
    int N, k, start, ending;
    cin >> N >> k;
    Node *nodes[N];
    for (int i = 0; i < N; i++) nodes[i] = newNode(i);
   

    for (int i = 0; i < k; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(nodes[u], nodes[v], w);
    }
     

    cin >> start >> ending;
    
    if (!bellmann_ford(nodes, N, nodes[start])) cout << "CYKL" << endl;
    else if (nodes[ending]->dist < INF) cout << nodes[ending]->dist << endl;
    else cout << "NIE" << endl;

    for(int i=0; i<N; i++) delete nodes[i];
}
