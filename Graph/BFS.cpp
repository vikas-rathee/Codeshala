#include<bits/stdc++.h>
using namespace std;

vector < vector<int> > v(10005);
queue <int> q;
bool isVisited[10005] = {false};
void bfs()
{
    q.push(1);
    isVisited[1] =1;
    while(!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for(int i =0; i < v[node].size(); i++)
        {
            if(!isVisited[v[node][i]])
            {
                q.push(v[node][i]);
                isVisited[v[node][i]] = 1;
            }
        }
    }

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
        bfs();
        for(int i = 0;i < 10005; i++)
        {
            v[i].clear();
        }
        memset(isVisited,false,10005);
        cout << endl;
    }
}
