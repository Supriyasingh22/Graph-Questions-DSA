// to detect cycle in an undirected graph using BFS 

#include<iostream>
#include<unordered_map>
#include<vector> 
#include<queue>
using namespace std ;


class Graph{

    int v ;
    unordered_map<int,vector<int>>adjL;

    public : 
    Graph(int v)
    {
        this->v = v ;
    }

    void CreateGraph(vector<vector<int>>edges)
    {
        for(int i = 0 ;i<v;i++)
        {
            for(int j =0 ;j<v;j++)
            {
                if(edges[i][j]==1)
                {
                    adjL[i].push_back(j);
                }
            }
        }
    }

    void printGraph()
    {
        for(auto i : adjL)
        {
            cout<<i.first;
            for(auto v : adjL[i.first])
            {
                cout<<"->"<<v ;
            }
            cout<<endl ;
        }
    }

    bool isCycleBFS(int u ,vector<bool>&visited, vector<bool>&inRec)
    {
        queue<int>q ;
        visited[u]=true ;
        

        q.push(u);

        while(!q.empty())
        {
            int node = q.front();
            inRec[node]=true ;
            q.pop();

            for(auto v : adjL[node])
            {

                if(visited[v])
                {
                    if(inRec[v]==true)
                    {
                        return true ;
                    }
                }
                else
                {
                    q.push(v);
                    visited[v]=true ;
                    

                }
            }
           
        }
         for(int i = 0 ;i<v;i++)
         {
            inRec[i]=false ;
         }
        return false ;

    }

};


int main()
{
    int v ;
    cout<<"Enter The No. of vertices : ";
    cin>> v ;

    vector<vector<int>>edges(v,vector<int>(v)) ;
    cout<<"Enter relation between nodes : ";
    for(int i = 0 ;i<v;i++)
    {
        for(int j = 0 ;j<v;j++)
        {
            cin>>edges[i][j];
        }
    }
    Graph g(v);

    // creating and printing graph 
    g.CreateGraph(edges);
    g.printGraph();

    // Detect Cycle Using BFS 
    vector<bool>visited(v,false);
    vector<bool>inRec(v, false);
    for(int i = 0 ;i<v ;i++)
    {
        if(!visited[i] && g.isCycleBFS(i,visited,inRec))
        {
            cout<<"Cycle Exists";
            return 0 ;
        }
    }
    cout<<"NO Cycle Exists ";
     return 0 ;
}