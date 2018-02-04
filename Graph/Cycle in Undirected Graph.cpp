#include<bits/stdc++.h>
using namespace std;

bool isVisited[1000] ={false}, ans = false;
vector <vector<int> > v(1000);

void dfs(int node, int parent)
{
    if(node < 1)
        return;
    if(isVisited[node])
    {
        return;
    }
    isVisited[node] = true;
    for(int i = 0; i < v[node].size(); i++)
    {
        if((isVisited[v[node][i]] && v[node][i] != parent) || (node == v[node][i]))
            {
                ans = true;
            }
        if(!isVisited[v[node][i]])
            dfs(v[node][i], node);
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
    dfs(1, 0);
    if(ans == true)
        cout << "YES";
    else
        cout << "NO";
}
