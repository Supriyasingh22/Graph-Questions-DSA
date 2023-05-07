// to detect cycle in a directed graph 

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

    bool isCycle(int u,vector<bool>&visited,vector<bool>&inRec)
    {
        visited[u]=true ;
        inRec[u]=true ;

        for(auto v : adjL[u])
        {
            if(!visited[v])
            {
                if(isCycle(v,visited,inRec))
                return true ;
            }
            else
            {
                if(inRec[v]==true)
                return true ;
            }
        }
        
        inRec[u]=false;
        return false ;
    }
    
};


int main()
{
    int v ;
    cout<<"Enter the vertices : ";
    cin>>v ;
    vector<bool>visited(v,false);
    vector<bool>inRec(v,false);

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

    // to detect cycle in a directed graph 
    int flag = 0 ;
    for(int i = 0 ;i<v;i++)
    {
        if(!visited[i] && g.isCycle(i,visited,inRec))
        {
        cout<<"Cycle Exists ";
        return 0 ;
        }
    }
    cout<<"No Such Cycle ";

   
    return 0 ;
}



