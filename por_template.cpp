#include <cstdio>
#include <queue>
// #define DEBUG 1

using namespace std;

struct point{
int x;
int y;
};

struct edge
{
    point u, v;
    int s;
};

bool operator< (edge a, edge b)
{
    if (a.s < b.s)
        return true;
    else
        return false;
}

void print_map(int **map, int n) {
    #ifdef DEBUG
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    #endif
}

int finding (point a, int** parent)
{
    /**********************
    * PLACE FOR YOUR CODE *
    **********************/
    return parent[a.x][a.y];
}

void unia (int x, int y, int* parent, int* ranking)
{
    /**********************
    * PLACE FOR YOUR CODE *
    **********************/
    if(ranking[x]<ranking[y]) {
        ranking[x]=ranking[y];
        parent[x]=parent[y];
    }
    else {
        ranking[y]=ranking[x];
        parent[y]=parent[x];
    }
}

int draught_calculator(int **mapa, int n, int k) {

    /**********************
    * PLACE FOR YOUR CODE *
    **********************/
}

int main ()
{
    int Z;
    scanf("%d", &Z);
    while(Z--)
    {
        int n, k;
        scanf ("%d %d", &n, &k);
        int **map = new int*[n];
        for (int i = 0; i < n; i++)
            map[i] = new int[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        print_map(map, n);

        int result = draught_calculator(map, n, k);

        printf ("%d\n", result);

        for (int i = 0; i < n; i++)
            delete[] map[i];
        delete[] map;

    }
    return 0;
}
