#include<bits/stdc++.h>
using namespace std;

int ans;
void dfs(char a[][50], int rows, int columns, int i, int j)
{
    if(rows <= 0 || columns <= 0 || i < 0 || j < 0)
        return;
    for(int k = i-1; k <= i+1; k++)
    {
        for(int l = j-1; l <= j+1; l++)
        {
            if(k == i && l == j)
                continue;

            if(k >= 0 && k < rows && l >=0 && l < columns && a[k][l] == a[i][j]+1)
            {
                if(a[k][l]-64 > ans)
                    {
                        ans = a[k][l]-64;
                    }
                if(ans == 26 || a[k][l] == 'Z')
                    return;
                dfs(a, rows, columns, k, l);
            }

        }
    }

}
int main()
{
    int rows, columns;
    char a[50][50];
    cin >> rows >> columns;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(a[i][j] == 'A')
            {
                if(ans==0)
                    ans = 1;
                dfs(a, rows, columns, i, j);
            }
        }
    }

    cout << ans;
}
