
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

    int checkPath(int s,int d,vector<bool>&visited)
    {   
        
        if(s==d)
        return 1;

        visited[s]=true ;

        for(auto v : adjL[s])
        {
            if(!visited[v])
            {
                if(checkPath(v,d,visited))
                {
                    return 1 ;
                }
            }
        }
    return 0 ;
    
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

    // to find if path exists between two nodes or not 
    int s ,d ;
    cout<<"To find if path exists enter two nodes ";
    cin>>s>>d ;

    int r = g.checkPath(s,d,visited) ;
    if(r==1)
    {
        cout<<"Yes Path Exists ";
    }else
    {
        cout<<"No such Path Exists ";
    }
    return 0 ;
}



