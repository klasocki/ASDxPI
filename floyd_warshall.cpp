#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX / 2;

typedef struct Segment {
    int town, travel_time;
} Segment;

typedef struct Line {
    Segment* segments;
    int number, length, start_town;
} Line;

Line* newLine(int number, int length, int start_town) {
    Line* l = new Line;
    l->number = number;
    l->length = length;
    l->start_town = start_town;
    l->segments = new Segment[length];
    return l;
}

typedef struct Node {
    int town, id;
    vector< pair<Node*, int> > neighbours;
} Node;

int** calculateTimesMatrix(Line** lines, int lines_no, int towns) {
    // put your code here
    int **result = new int*[towns];
    for(int i=0; i<towns; i++)
        result[i]=new int[towns];
    for(int i=0; i<towns; i++)
        for(int j=0; j<towns; j++)
        result[i][j]=INF;

    for(int i=0; i<towns; i++) result[i][i]=0;

    for(int i=0; i<lines_no; i++) {
        Line* tmp=lines[i];
        int prev=tmp->start_town;
        for(int j=0; j<tmp->length; j++) {
            int curr_town=tmp->segments[j].town;
            if (result[prev][curr_town]>tmp->segments[j].travel_time)
             result[prev][curr_town]=result[curr_town][prev]=tmp->segments[j].travel_time;
            prev=curr_town;
        }
    }

    for(int i=0; i<towns; i++)
        for(int j=0; j<towns; j++)
            for(int k=0; k<towns; k++){
                result[j][k]=result[k][j]=min( result[j][k] , result[j][i]+result[i][k]);
            }
            
    return result;
}

int main() {
    int towns, lines_no, queries;
    cin >> towns >> lines_no >> queries;
    Line** lines = new Line*[lines_no];
    for (int i=0; i<lines_no; i++) {
        int len, start;
        cin >> len >> start;
        lines[i] = newLine(i, len-1, start);
        for (int j=0; j<len-1; j++) {
            int next, time;
            cin >> time >> next;
            lines[i]->segments[j].town = next;
            lines[i]->segments[j].travel_time = time;
        }
    }

    int** times = calculateTimesMatrix(lines, lines_no, towns);
    

    for (int i=0; i<queries; i++) {
        int u, v;
        cin >> u >> v;
        cout << times[u][v] << endl;
    }

    for (int i=0; i<towns; i++) delete[] times[i];
    delete[] times;
    for (int i=0; i<lines_no; i++) {
        delete[] lines[i]->segments;
        delete lines[i];
    }
    delete[] lines;
}