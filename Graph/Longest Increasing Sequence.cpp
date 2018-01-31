#include<bits/stdc++.h>
using namespace std;

bool isVisited[100][100] = {false};

int temp_count,ans;

void dfs(int rows, int columns, char a[][100], int i, int j, char ch)
{
   if(rows <= 0 || columns <= 0 || i < 0 || j < 0)
    return;
   if(isVisited[i][j])
   {
        return;
   }

   isVisited[i][j] = true;
   for(int k = i-1; k <= i+1; k++)
   {
       for(int l = j-1; l <= j+1; l++)
       {
        if(!isVisited[k][l] &&  (a[k][l] == ch+1) && ( k >= 0 && k <= rows-1) && (l >=0 && l <= columns-1))
        {
            temp_count++;
            dfs(rows, columns, a, k, l,a[k][l]);
            if(temp_count > ans)
                {
                    ans = temp_count;
                }
            temp_count--;

        }
       }
   }
}

int main()
{
  int rows,columns;
  memset(isVisited,false,sizeof(char)*100*100);
  cin >> rows >> columns;
  char a[100][100];
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
          if(a[i][j] == 'A' && !isVisited[i][j])
          {
              temp_count = 1;
              dfs(rows, columns, a, i,j,a[i][j]);
              temp_count=0;
          }
      }
  }
  cout<<ans<<endl;
}
