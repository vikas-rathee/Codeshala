#include<bits/stdc++.h>
using namespace std;

bool isVisited[501][501] = {false};

void dfs(int rows, int columns, int a[][500], int i, int j)
{
   if(rows <= 0 || columns <= 0 || i < 0 || j < 0)
    return;
   if(isVisited[i][j])
    return;
   isVisited[i][j] = true;
   for(int k = i-1; k <= i+1; k++)
   {
       for(int l = j-1; l <= j+1; l++)
       {
        if(!isVisited[k][l] && a[k][l] && (k >=0 && k <= rows-1) && (l >=0 && l <= columns-1))
        {
            dfs(rows, columns, a, k, l);
        }
       }
   }
}

int main()
{
  int rows,columns,ans=0;
  cin >> rows >> columns;
  int a[500][500];
  memset(a,0,sizeof(int)*500*500);
  for(int i = 0; i < rows; i++)
  {
      for(int j = 0; j < columns; j++)
      {
          scanf("%1d", &a[i][j]); //There is no space between the distinct integers so have to stop reading after each 1 digit
      }
  }
  for(int i = 0; i < rows; i++)
  {
      for(int j = 0; j < columns; j++)
      {
          if(a[i][j] && !isVisited[i][j])
          {
              dfs(rows, columns, a, i,j);
              ans++;
          }
      }
  }
  cout<<ans;
}
