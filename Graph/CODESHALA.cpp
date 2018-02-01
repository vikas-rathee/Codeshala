#include<bits/stdc++.h>
using namespace std;

bool isVisited[41][41] = {false},ans = false;
int ch_index;
char ch[] = "CODESHALA";

void dfs(int rows, int columns, char a[][41], int i, int j)
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
        if(!isVisited[k][l] && a[k][l] == ch[ch_index]  && ( k >= 0 && k <= rows-1) && (l >=0 && l <= columns-1))
        {
            ch_index++;
            dfs(rows, columns, a, k, l);
            if(ch_index == 9)
                {
                    ans = true;
                }
            ch_index--;
        }
       }
   }
}

int main()
{
  int rows,columns;
  cin >> rows >> columns;
  char a[41][41];
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
          if(a[i][j] == 'C' && !isVisited[i][j])
          {
              ch_index = 1;
              dfs(rows, columns, a, i,j);
          }
      }
  }
  if(ans)
    cout << "YES";
  else
    cout << "NO";
}
