// to detect cycle in an undirected  grpah using BFS (also for graphs which are not connected )

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

    bool detectCycle(int u,int parent,vector<bool>& visited)
    {
        queue<pair<int,int>> q ;

        q.push({u,parent});
        visited[u]=true ;

        while(!q.empty())
        {
            pair<int,int> p = q.front();

            int node = p.first ;
            int pr = p.second ;

            q.pop();
            for(auto v : adjL[node])
            {
                if(v==pr)
                continue ;

                if(visited[v])
                return true ;

                q.push({v,node});
                visited[v]=true ;
            }

        }
        return false ;
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

    // to detect cycle in an undirected graph 
    int parent = -1 ;
    int flag = 0 ;

    for(int i = 0 ;i<v;i++)
    {
        if(!visited[i])
        {
            if(g.detectCycle(i,parent,visited))
            {
                cout<<"Yes Cycle Exists ";
                flag = 1 ;
                break ;
            }
        }
    }
    if(flag == 0)
    {
        cout<<"No Cycle Exists ";
    }

   
    return 0 ;
}



