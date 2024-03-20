#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <set>
#include <math.h>

#define MAXNUM  10001
#define MAXMATCHNUM 2

using namespace std;

struct Edge {

    int start;
    int end;
    
    int w;
};

vector<Edge> edges;
int parent[MAXNUM];


bool compare(const Edge &e1, const Edge &e2) {

    if (e1.w < e2.w)
        return true;
    else
        return false;

}

int find(int v) {

    if (parent[v] == v) return v;

    return find(parent[v]);
}


bool same_parent(int v1, int v2) {

    int p1 = find(v1);
    int p2 = find(v2);

    if (p1 == p2) return true;
    else return false;
}


void Union(int v1, int v2){

    int p1 = find(v1);
    int p2 = find(v2);

    if (p1 != p2)
        parent[v2] = v1;
}



int kruskal(int V) {

    for (int i = 1; i <= V; i++)
        parent[i] = i;

    // add each edge in ascending order. 
    // each time, check whether it creates a tree and not make cycle
    int weight_sum = 0;

    for (int i = 0; i < edges.size(); i++) {

        if (same_parent(edges[i].start, edges[i].end) == false) {

            Union(edges[i].start, edges[i].end);
            weight_sum += edges[i].w;
        }

    }

    return weight_sum;
}


void prim() {






}



int main()
{
    int V, E;
    scanf("%d %d", &V, &E);
    
    int A, B, C;
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &A, &B, &C);

        Edge edge = { A,B,C };
        edges.push_back(edge);
    }
    
    // sort all edges of G
    sort(edges.begin(), edges.end(), compare);

    cout << kruskal(V) << endl;

    /*for (int i = 0; i < E; i++) {

        cout << edges[i].start << " " << edges[i].end << " " << edges[i].w << endl;
    }*/
    

    return 0;
}
