

#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std ;

class Graph{
    int v ;
    vector<vector<pair<int,int>>>adjL ;
    vector<int>result;
   

    public : 
    Graph(int v)
    {
        this->v = v ;
        adjL = vector<vector<pair<int,int>>>(v);
        result = vector<int>(v,INT_MAX);
    }
     
// To make adjacency list from Distance matrix 
    void adjacencyList(vector<vector<int>>Distance)
    {
        for(int i = 0 ;i<v;i++)
        {
            for(int j = 0 ;j<v;j++)
            {
                if(Distance[i][j]!=0)
                {
                    adjL[i].push_back({j,Distance[i][j]});
                   
            }
        }
    }
    }

//     To find shortest Path 
    void ShortestPath(int S)
    {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minHeap ;

        minHeap.push({0,S});
        result[S]=0 ;

        while(!minHeap.empty())
        {
            int d = minHeap.top().first ;
            int node = minHeap.top().second;

            minHeap.pop();

            for(auto adjNode : adjL[node])
            {
                int u = adjNode.first;
                int wt = adjNode.second;
                if(d+wt<result[u])
                {
                    result[u]=d+wt;
                    minHeap.push({d+wt,u}) ;
                }
            }
        }

    }

    void print()
    {
        for(int i = 0 ;i<result.size();i++)
        {
            cout<<i<<" ->"<<result[i]<<endl ;
        }
    }


};

int main()
{
    int v ;
    cout<<"Enter the no. of friend's house : ";
    cin>>v ;

    vector<vector<int>> Distance(v,vector<int>(v));
    cout<<"Enter the distance between houses : ";
    for(int i = 0 ;i<v;i++)
    {
        for(int j = 0 ;j<v;j++)
        {
            cin>>Distance[i][j];
        }
    }

    Graph g(v);


    // to convert it into adjacency list ;
   g.adjacencyList(Distance);

    int S ;
    cout<<"Enter the value for Akshay's House : ";
    cin>>S ;

    // to find minimum distance from Akshay's house to friends's house 

    g.ShortestPath(S);
    g.print();
    return 0 ;

}
