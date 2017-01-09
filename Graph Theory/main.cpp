//
//  main.cpp
//  Lab 6
//
//  Created by Brian Lykes on 11/4/16.
//  Copyright © 2016 Brian Lykes. All rights reserved.
//

// Description: DFS and Dijkstra's shortest path - lab will determine if an
// undirected graph is cyclic using Dijkstra's shortest path

/* Main.cpp */
#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
    cout<<"CREATING GRAPH G" <<endl;
    cout<< "Number of vertices: ";
    cin>>n;
    Visited=new bool [n];
    int components = 0;
    
    Graph G(n);
    G.Create();
    G.print();
    G.ShortestPath(intitialVertex, n);
    for(i=0; i<=n; i++)
    {
        Visited[i]=false;
    }
    for(i=0; i<n; i++)
    {
        Visited[i]=false;
        for(k=0; k<n; k++)
        {
            if(!Visited[k])
            {
                G.DFS(0,k);
                components++;
            }
        }
        
        if(cycles)
        {
            cout<< "This graph is cyclic" << endl;
        }
        else
        {
            cout<<"This graph does NOT contain any cycles" << endl;
        }
        cout<<"Number of components in the undirected graph G = " << components << endl <<endl;
        return 0;
    }
}

