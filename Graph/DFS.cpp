#include<bits/stdc++.h>
using namespace std;

bool isVisited[1000] = {false};
vector<vector<int> > v(1000);

void dfs(int node)
{
    if(node < 1 )
        return;
    if(isVisited[node])
        return;
    cout << node << endl;
    isVisited[node] = true;
    for(int i = 0; i < v[node].size(); i++)
    {
        if(!isVisited[v[node][i]])
            dfs(v[node][i]);
    }
}
int main()
{
    int nodes,edges;
    cin >> nodes >> edges;
    for(int i = 0; i < edges; i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
}
