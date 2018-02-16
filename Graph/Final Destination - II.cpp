#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, num, steps = 0, flag = 0;
    cin >> n >> num;
    queue < int > q;
    q.push(n);
    while(q.front() != num)
    {
        int width = q.size();
        while(width--)
        {
            if(q.front() == num)
                {
                    flag = 1;
                    break;
                }
            int temp = q.front();
            q.pop();
            if(temp * 2 != n)
                q.push(temp * 2);
            if( temp >=2 && temp-1 != n )
                q.push(temp-1);
        }
        if(flag == 1)
            break;
            steps++;
    }
    cout << steps;
}
