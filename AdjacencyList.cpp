// to implement the graph using adjacency lists 

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std ;

class graph{
    public :
    unordered_map<int,list<int>>adjL ;

    void addEdge(int u,int v,bool dir)
    {
        // if dir = 0 , undrected 
        // if dir = 1 , directed ;

        adjL[u].push_back(v);

        if(dir==0)
        {
            adjL[v].push_back(u);
        }
    }

    // fo rprinting graph 

    void printGraph()
    {
        for(auto i : adjL)
        {
            cout<<i.first ;
            for(auto j:i.second)
            {
                cout<<"->"<<j ;
            }
            cout<<endl ;
        }
    }


};

int main()
{
    int n ;
    cout<<"enter the no . of nodes : ";
    cin>> n ;

    int m ;
    cout<<"enter the no. of edges : ";
    cin>>m ;
    graph g ;

    for(int i = 0 ;i<m;i++)
    {
        int u,v ;
        cout<<"enter value of edge"<<i+1 ;
        cin>>u>>v ;

        g.addEdge(u,v,0);//for undirected 
        
    }
    g.printGraph();
    return 0 ;

}