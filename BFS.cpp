#include<iostream>
#include<vector>
#include<unordered_map> 
#include<queue>
using namespace std ;

class graph{

    public : 
    int v ;
    
    

    graph(int v)
    {
        this->v = v ;
               
    }
    unordered_map<int,vector<int>> adjL;


     void  createGraph(vector<vector<int>> edges)// this constructor will create a graph 
    {   
        for(int i = 0 ;i<v;i++)
        {   
            int flag = 0 ;
            for(int j = 0 ;j<v;j++)
            {
                if(edges[i][j]==1)
                {
                    adjL[i].push_back(j);
                    flag =1 ;
                }
                
           }
            
        }
    }

    void printGraph()
    {
        for(int i = 0 ;i<v;i++)
        {
           cout<<i;
            for(auto& j : adjL[i])
            {
                 cout<<"->"<<(j) ;
            }
            cout<<endl;
        }
    }

    void Bfs(int u,vector<bool> &visited)
    {   
        queue<int>q ;

        q.push(u);
        visited[u]=true ;
        cout<<u<<" " ;

        while(!q.empty())
        { 
              int f = q.front();
            q.pop();

            for(auto v : adjL[f])
            {   
                if(!visited[v])
                {
                    q.push(v);
                    visited[v]=true ;
                    cout<<"->"<<v ;
                }

            }
        }
        

    }

};


int main()
{
    int v ;
    cout<<"Enter the vertices : ";
    cin>>v ;
    vector<bool>visited(v,false);

    graph g(v) ;
      

    // relation of edegs through matrix 
    vector<vector<int>> edges(v,vector<int>(v));
    cout<<"enter the relation betweem edges : ";
    for(int i = 0 ;i<v;i++)
    {
        for(int j = 0 ;j<v;j++)
        {
            cin>>edges[i][j];
        }
    }
    
    // create object of graph 
     g.createGraph(edges) ; 

    g.printGraph();

    g.Bfs(0,visited);

    return 0 ;
}



