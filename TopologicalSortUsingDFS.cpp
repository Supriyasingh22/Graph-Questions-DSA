// to print elements in graph in topological order 

#include<iostream>
#include<vector>
#include<unordered_map> 
#include<stack>
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

    void topologicalSort(int u ,vector<bool>&visited,stack<int>&s)
    {
        visited[u]=true ;
        for(auto v : adjL[u])
        {
            if(!visited[v])
            topologicalSort(v,visited,s);
        }

        s.push(u);
    }
    
};


int main()
{
    int v ;
    cout<<"Enter the vertices : ";
    cin>>v ;
    vector<bool>visited(v,false);
   stack<int>s ;

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

    // to print nodes in topological sorting technique 

    for(int i = 0 ;i<v;i++)
    {

        if(!visited[i])
        g.topologicalSort(i,visited,s);

    }
       
       while(!s.empty())
       {
        cout<<s.top()<<" ";
        s.pop();
       }
    return 0 ;
}



