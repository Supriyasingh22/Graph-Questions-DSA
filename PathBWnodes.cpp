#include<iostream>
#include<unordered_map>
#include<map>
#include<queue>
#include<list> 

using namespace std ;

class graph{

    public :
    map<int,list<int>> adjL ;
   

    void createGraph(int v ,int edegs[][4])
    {   

        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(edegs[i][j]==1)
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
            for(auto j : i.second)
            {
                cout<<"->"<<j;
            }
            cout<<endl ;
        }
    }

    void Dfs(int u ,bool visited[])
    {
        if(visited[u]==true )return;

        visited[u]=1 ;
        cout<<u<<"->";

        for(auto v : adjL[u])
        {
            if(!visited[v])
            {
                Dfs(v,visited);
            }
        }
    }

    bool checkPath(int s,int d)
    {
        queue<int>q ;
      bool  visited[4]={0};

        q.push(s);
        visited[0]=1 ;

        while(!q.empty())
        {
            int r = q.front();
            if(r==d){
                return 1 ;
            }
            q.pop();
            for(auto j : adjL[r])
            {  
                if(!visited[j])
                {
                    q.push(j);
                    visited[j]=1;
                }
            }

        }
         return 0 ;
    }



};



int main()
{
    int v ;
    cout<<"Enter the number of vertices : ";
    cin>>v ;

    // forming edegs in terms of adjacency matrix 
    cout<<"Enter the edges : ";
    int edges[4][4]={{0,1,1,0},
                    {0,0,1,1},
                    {0,0,0,0},
                    {0,0,0,0}};

    

   
    // 0 represent undirected and 1 represe4nt directed 
    graph g ;

    g.createGraph(v,edges);
    g.printGraph();

    cout<<"DFS Traversal of a graph : ";
    
    bool visited[4]={0};
    g.Dfs(0,visited);


    bool r = g.checkPath(2,1);
    if(r==1)
    cout<<"Yes path exists ";
    else
    cout<<"No such path exists ";
    return 0 ;

}