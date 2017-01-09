//
//  Header.h
//  Lab 6
//
//  Created by Brian Lykes on 11/5/16.
//  Copyright © 2016 Brian Lykes. All rights reserved.
//

/* Graph.h */
#include <iostream>
using namespace std;
#ifndef __GRAPH_H_INCLUDED__
#define __GRAPH_H_INCLUDED__

int n, e, i, j, k, intitialVertex;
int weight[10][10];
int weightedEdge;
bool * Visited;
bool cycles=false;

struct Vertex
{
    int vertexNum;
    Vertex *next;
};

class Graph
{
public:
    Vertex *headVertexs;
    Graph ( int Vertexs )
    {
        n=Vertexs;
        headVertexs= new Vertex [n];
        for (i=0; i < n; i++)
        {
            headVertexs[i].vertexNum=i;
            headVertexs[i].next=0;
        }
    }
    
    void Create()
    {
        Vertex *previousVertex;
        Vertex *newVertex;
        cout<<"Number of edges: ";
        cin>>e;
        cout << endl;
        cout << "NOTE: Edges are in the form [Edge = (v1,v2)]"<<endl<<endl;
        for(i=1; i<=e; i++)
        {
            cout << "Edge " << i << endl;
            cout << "v1: ";
            cin>> v1;
            cout<< "v2: ";
            cin>> v2;
            cout<<"Edge Weight: ";
            cin>>weightedEdge;
            weight[v1][v2]=weightedEdge;
            weight[v2][v1]=weightedEdge;
            cout<<endl;
            
            newVertex= new Vertex;
            newVertex->vertexNum=v2;
            
            if(headVertexs[v1].next==NULL)
            {
                newVertex->next= NULL;
                headVertexs[v1].next=newVertex;
            }
            else
            {
                previousVertex =&headVertexs[v1];
                while(previousVertex->next != NULL)
                {
                    previousVertex= previousVertex->next;
                }
                newVertex->next = NULL;
                previousVertex ->next = newVertex;
            }
            
            newVertex= new Vertex;
            newVertex->vertexNum= v1;
            
            if (headVertexs[v2].next== NULL)
            {
                newVertex->next= NULL;
                headVertexs[v2].next=newVertex;
            }
            else
            {
                previousVertex= &headVertexs[v2];
                while(previousVertex->next != NULL)
                {
                    previousVertex=previousVertex->next;
                }
                newVertex->next= NULL;
                previousVertex->next= newVertex;
            }
        }
    }
    void ShortestPath(int intitialvertexNum,int n)
    {
        int min;
        int distance[20];
        int S[20];
        int path[20];
        int index = 0;
        cout << "DIJKSTRA'S SHORTEST PATH ON WEIGHTED GRAPH G" <<endl;
        
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                if(weight[i][j]==0)
                    weight[i][j]=31999;
        cout<<"Starting Vertex: ";
        cin>>intitialvertexNum;
        
        for(i=0;i<=n;i++)
        {
            S[i]=0;
            distance[i]=weight[intitialvertexNum][i];
        }
        path[++index]=intitialvertexNum;
        S[intitialvertexNum]=1;
        distance[intitialvertexNum]=0;
        for(i=0;i<n-1;i++)
        {
            k=0;
            min=31999;
            for(j=0; j<n; j++)
            {
                if(distance[j]< min && S[j]!= 1)
                {
                    min= distance[j];
                    k=j;
                }
            }
            if(weight[intitialvertexNum][k] <= distance[k])
                index=1;
            path[++index]=k;
            
            S[k]=1;
            for(j=0; j<n; j++)
                if(weight[k][j]!=31999 && distance[j]>=distance[k]+weight[k][j] && S[j]!=1)
                    distance[j]=distance[k]+weight[k][j];
        }
        cout<<endl;
        for(j=0; j<n; j++)
        {
            cout<<"The shortest distance from ("<<intitialvertexNum<<")-->("<<j<<") = ";
            cout<<distance[j]<<endl;
        }
        cout << endl;
    }
    
    void DFS(int parent, int v)
    {
        Visited[v]=true;
        Vertex* adjacentVertex=headVertexs[v].next;
        while(adjacentVertex)
        {
            if(!Visited[adjacentVertex->vertexNum])
            {
                DFS(v, adjacentVertex->vertexNum);
            }
            else if(parent != adjacentVertex->vertexNum)
            {
                cycles=true;
            }
            adjacentVertex= adjacentVertex->next;
        }
    }
    
    void print()
    {
        Vertex *tempVertex;
        for(i=0; i<n; i++)
        {
            tempVertex = &headVertexs[i];
            while(tempVertex != NULL)
            {
                cout<< "(" << tempVertex->vertexNum << ")" << "-->";
                tempVertex=tempVertex->next;
            }
            cout<<endl;
        }
        cout << endl << endl;
    }
private:
    int v1;
    int v2;
};

#endif
