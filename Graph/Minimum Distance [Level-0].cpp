#include<bits/stdc++.h>
using namespace std;

vector < vector<int> > v(10005);
queue < pair<int, int> > q;
bool isVisited[10005] = {false};


int bfs(int N)
{
    q.push(make_pair(1,0));
    isVisited[1] = true;
    while(!q.empty())
    {
        pair <int, int> P = q.front();
        q.pop();
         int node = P.first;
        if(node == N)
            return (P.second);
        for(int i = 0; i < v[node].size(); i++)
        {

            if(!isVisited[v[node][i]])
            {
                q.push(make_pair(v[node][i], P.second+1));
                isVisited[v[node][i]] = true;
            }
        }
    }
    return -1;
}
 int main()
{
     int test_cases;
    cin >> test_cases;
    while(test_cases--)
    {
        int nodes, edges;
        cin >> nodes >> edges;
        for(int i = 0; i < edges; i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        cout << bfs(nodes) << endl;
        for(int i = 0; i < 10005; i++)
        {
            v[i].clear();
        }
        memset(isVisited, false, 10005);
        while(!q.empty())
        {
            q.pop();
        }

    }
}
