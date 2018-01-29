#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    int graph[100][100] = {0};
    for(int i=0;i<edges;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a-1][b-1] = 1;
    }
    for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<nodes;j++)
        {
                cout<<graph[i][j]<<" ";
        }
            cout<<endl;
    }

}
