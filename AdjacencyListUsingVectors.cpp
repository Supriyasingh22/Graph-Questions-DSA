// to implement grpah using vectors 

#include<iostream>
#include<vector>
using namespace std ;

class graph{

    public : 
    
    void final(int n,int m ,int dir, vector<vector<int>> &edges)
    {
        vector<int> ans[10];

        for(int i = 0 ;i<m;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            ans[u].push_back(v);
            if(dir==0)
            {
                ans[v].push_back(u);
            }
        }
    }
};

int main()
{
    int n ;
    cout<<"enter the number of nodes ";
    cin>>n ;
    int m ;
    cout<<"enter the number of edges : ";
    cin>>m ;

    vector<vector<int>> edges(m,vector<int>(2));

    int dir ;
    cout<<"Enter the direction : ";
    cin>>dir ;

    for(int i=0;i<m;i++)
    {
        cout<<"enter edge "<<i+1<<" ";
        int u , int v ;
        cin>>u>>v ;

        edges[i].push_back(u) ;
        edges[i].push_back(v);

    }

    graph g ;

    g.


}
