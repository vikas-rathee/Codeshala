#include<bits/stdc++.h>
using namespace std;

void min_steps()
{
    int n;
    cin >> n;
    int choice[30], steps = 0, flag = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> choice[i];
    }
    queue < int > q;
    q.push(0);
    while(q.front() != n && !q.empty())
    {
        int width = q.size();
        while(width--)
        {
            if(q.front() == n)
                {
                    flag = 1;
                    break;
                }
            int pos = q.front();
            q.pop();
            q.push(pos + 1);
            if(pos < n && choice[pos] != 1 && choice[pos] != 0)
                q.push(pos + choice[pos]);
        }
        if(flag == 1)
            break;
            steps++;
    }
    cout << steps << endl;
}
int main()
{
    int test_cases;
    cin >> test_cases;
    while(test_cases--)
    {
        min_steps();
    }
}
