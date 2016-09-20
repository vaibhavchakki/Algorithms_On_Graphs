//
//  main.cpp
//  Graph-BFS
//
//  Created by Vaibhav Chakki on 9/19/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int numVertex;
    vector<int> *adj;
public:
    Graph(int num) {
        numVertex = num;
        adj = new vector<int>[num];
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void Print() {
        for (int i = 0; i < numVertex; i++) {
            for(int j = 0; j < adj[i].size(); j++) {
                cout << i << " -> " << adj[i][j]<< endl;
            }
        }
    }
    
    
    void BFS(int s) {
        bool *visited = new bool[numVertex];
        int  *d = new int[numVertex];
        
        for (int i = 0; i < numVertex; i++) {
            visited[i] = false;
            d[i] = -1;
        }
        vector<int> Q;
        Q.push_back(s);
        visited[s] = true;
        d[s] = 0;
        
        while (!Q.empty()) {
            int top = Q.front();
            Q.erase(Q.begin());
            
            for (int i = 0; i < adj[top].size(); i++) {
                int v = adj[top][i];
                if (!visited[v]) {
                    Q.push_back(v);
                    visited[v] = true;
                    d[v] = d[top] + 1;
                }
            }
        }
        
        for (int i = 0; i < numVertex; i++) {
            cout << d[i] << "\t";
        }
        cout << endl;
    }
};

int main(int argc, const char * argv[]) {

    int numVertex, numEdge;
    cin >> numVertex >> numEdge;
    
    Graph G(numVertex);
    
    for (int i = 0; i < numEdge; i++) {
        int u, v;
        cin >> u >> v;
        G.addEdge(u, v);
    }
    
    G.BFS(0);
    return 0;
}
