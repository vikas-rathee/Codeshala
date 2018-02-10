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
        if(!isVisited[v[node][i]])
            dfs(v[node][i], node);
        else
        {
            ans = true;
            return;
        }
        isVisited[v[node][i]] = false;
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
    }
    for(int i = 1; i <= nodes; i++)
        {
            dfs(i,0);
            isVisited[i] = false;
        

    if(ans)
        cout << "YES";
    else
        cout << "NO";
}
