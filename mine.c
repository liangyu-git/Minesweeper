#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define Nmax 30
void printpos(int n, int a[2][n][n], int i, int j)
{
  int num;
  if(i == 0)
  {
    if(j == 0)
    {
      num = a[1][i+1][j+1]+a[1][i][j+1]+a[1][i+1][j];
      if(num == 0)
        printf("_ ");
      else
        printf("%d ",-num);
    }
    else if(j == n-1)
    {
      num = a[1][i][j-1]+a[1][i+1][j-1]+a[1][i+1][j];
      if(num == 0)
        printf("_ ");
      else
        printf("%d ",-num);
    }
    else
    {
      num = a[1][i][j-1]+a[1][i+1][j-1]+a[1][i+1][j]+a[1][i+1][j+1]+a[1][i][j+1];
      if(num == 0)
        printf("_ ");
      else
        printf("%d ",-num);
    }
  }else if(i == n-1)
  {
    if(j == 0)
    {
      num = a[1][i-1][j+1]+a[1][i-1][j]+a[1][i][j+1];
      if(num == 0)
        printf("_ ");
      else
        printf("%d ",-num);
    }
    else if(j == n-1)
    {
      num = a[1][i][j-1]+a[1][i-1][j-1]+a[1][i-1][j];
      if(num == 0)
        printf("_ ");
      else
        printf("%d ",-num);;
    }
    else
    {
      num = a[1][i][j-1]+a[1][i-1][j-1]+a[1][i-1][j]+a[1][i-1][j+1]+a[1][i][j+1];
      if(num == 0)
        printf("_ ");
      else
        printf("%d ",-num);
    }
  }else if(j == 0&&i != 0&&i != n-1)
  {
    num = a[1][i-1][j]+a[1][i-1][j+1]+a[1][i][j+1]+a[1][i+1][j+1]+a[1][i+1][j];
    if(num == 0)
      printf("_ ");
    else
      printf("%d ",-num);
  }else if(j == n-1&&i != 0&&i != n-1)
  {
    num = a[1][i-1][j]+a[1][i-1][j-1]+a[1][i][j-1]+a[1][i+1][j-1]+a[1][i+1][j];
    if(num == 0)
      printf("_ ");
    else
      printf("%d ",-num);
  }else
  {
    num = a[1][i-1][j]+a[1][i-1][j-1]+a[1][i][j-1]+a[1][i+1][j-1]+a[1][i+1][j]+a[1][i-1][j+1]+a[1][i][j+1]+a[1][i+1][j+1];
    if(num == 0)
      printf("_ ");
    else
      printf("%d ",-num);
  }
}
void checknum(int n, int a[2][n][n], int i, int j)
{
  int num;
  if(i == 0)
  {
    if(j == 0)
    {
      num = a[1][i+1][j+1]+a[1][i][j+1]+a[1][i+1][j];
    }
    else if(j == n-1)
    {
      num = a[1][i][j-1]+a[1][i+1][j-1]+a[1][i+1][j];
    }
    else
    {
      num = a[1][i][j-1]+a[1][i+1][j-1]+a[1][i+1][j]+a[1][i+1][j+1]+a[1][i][j+1];
    }
  }else if(i == n-1)
  {
    if(j == 0)
    {
      num = a[1][i-1][j+1]+a[1][i-1][j]+a[1][i][j+1];
    }
    else if(j == n-1)
    {
      num = a[1][i][j-1]+a[1][i-1][j-1]+a[1][i-1][j];
    }
    else
    {
      num = a[1][i][j-1]+a[1][i-1][j-1]+a[1][i-1][j]+a[1][i-1][j+1]+a[1][i][j+1];
    }
  }else if(j == 0&&i != 0&&i != n-1)
  {
    num = a[1][i-1][j]+a[1][i-1][j+1]+a[1][i][j+1]+a[1][i+1][j+1]+a[1][i+1][j];
  }else if(j == n-1&&i != 0&&i != n-1)
  {
    num = a[1][i-1][j]+a[1][i-1][j-1]+a[1][i][j-1]+a[1][i+1][j-1]+a[1][i+1][j];
  }else
  {
    num = a[1][i-1][j]+a[1][i-1][j-1]+a[1][i][j-1]+a[1][i+1][j-1]+a[1][i+1][j]+a[1][i-1][j+1]+a[1][i][j+1]+a[1][i+1][j+1];
  }
  //printf("i = %d  j = %d  num = %d\n",i,j,num);
  //return;
  if(num == 0)
  {
    if(i == 0)
    {
      if(j == 0)
      {
        if(a[0][i+1][j+1] == 1&&a[0][i][j+1] == 1&&a[0][i+1][j] == 1)
          return;
        a[0][i+1][j+1] = 1;
        a[0][i][j+1] = 1;
        a[0][i+1][j] = 1;
        checknum(n,a,i,j+1);
        checknum(n,a,i+1,j+1);
        checknum(n,a,i+1,j);
      }
      else if(j == n-1)
      {
        if(a[0][i][j-1] == 1&&a[0][i+1][j-1] == 1&&a[0][i+1][j] == 1)
          return;
        a[0][i][j-1] = 1;
        a[0][i+1][j-1] = 1;
        a[0][i+1][j] = 1;
        checknum(n,a,i,j-1);
        checknum(n,a,i+1,j-1);
        checknum(n,a,i+1,j);
      }
      else
      {
        if(a[0][i][j-1] == 1&&a[0][i+1][j-1] == 1&&a[0][i+1][j] == 1&&a[0][i+1][j+1] == 1&&a[0][i][j+1] == 1)
          return;
        a[0][i][j-1] = 1;
        a[0][i+1][j-1] = 1;
        a[0][i+1][j] = 1;
        a[0][i+1][j+1] = 1;
        a[0][i][j+1] = 1;
        checknum(n,a,i,j-1);
        checknum(n,a,i+1,j-1);
        checknum(n,a,i+1,j);
        checknum(n,a,i+1,j+1);
        checknum(n,a,i,j+1);
      }
    }else if(i == n-1)
    {
      if(j == 0)
      {
        if(a[0][i-1][j+1] == 1&&a[0][i-1][j] == 1&&a[0][i][j+1] == 1)
          return;
        a[0][i-1][j+1] = 1;
        a[0][i-1][j] = 1;
        a[0][i][j+1] = 1;
        checknum(n,a,i-1,j+1);
        checknum(n,a,i-1,j);
        checknum(n,a,i,j+1);
      }
      else if(j == n-1)
      {
        if(a[0][i][j-1] == 1&&a[0][i-1][j-1] == 1&&a[0][i-1][j] == 1)
          return;
        a[0][i][j-1] = 1;
        a[0][i-1][j-1] = 1;
        a[0][i-1][j] = 1;
        checknum(n,a,i,j-1);
        checknum(n,a,i-1,j-1);
        checknum(n,a,i-1,j);
      }
      else
      {
        if(a[0][i][j-1] == 1&&a[0][i-1][j-1] == 1&&a[0][i-1][j] == 1&&a[0][i-1][j+1] == 1&&a[0][i][j+1] == 1)
          return;
        a[0][i][j-1] = 1;
        a[0][i-1][j-1] = 1;
        a[0][i-1][j] = 1;
        a[0][i-1][j+1] = 1;
        a[0][i][j+1] = 1;
        checknum(n,a,i,j-1);
        checknum(n,a,i-1,j-1);
        checknum(n,a,i-1,j);
        checknum(n,a,i-1,j+1);
        checknum(n,a,i,j+1);
      }
    }else if(j == 0&&i != 0&&i != n-1)
    {
      if(a[0][i-1][j] == 1&&a[0][i-1][j+1] == 1&&a[0][i][j+1] == 1&&a[0][i+1][j+1] == 1&&a[0][i+1][j] == 1)
        return;
      a[0][i-1][j] = 1;
      a[0][i-1][j+1] = 1;
      a[0][i][j+1] = 1;
      a[0][i+1][j+1] = 1;
      a[0][i+1][j] = 1;
      checknum(n,a,i-1,j);
      checknum(n,a,i-1,j+1);
      checknum(n,a,i,j+1);
      checknum(n,a,i+1,j+1);
      checknum(n,a,i+1,j);
    }else if(j == n-1&&i != 0&&i != n-1)
    {
      if(a[0][i-1][j] == 1&&a[0][i-1][j-1] == 1&&a[0][i][j-1] == 1&&a[0][i+1][j-1] == 1&&a[0][i+1][j] == 1)
        return;
      a[0][i-1][j] = 1;
      a[0][i-1][j-1] = 1;
      a[0][i][j-1] = 1;
      a[0][i+1][j-1] = 1;
      a[0][i+1][j] = 1;
      checknum(n,a,i-1,j);
      checknum(n,a,i-1,j-1);
      checknum(n,a,i,j-1);
      checknum(n,a,i+1,j-1);
      checknum(n,a,i+1,j);
    }else
    {
      if(a[0][i-1][j] == 1&&a[0][i-1][j-1] == 1&&a[0][i][j-1] == 1&&a[0][i+1][j-1] == 1&&a[0][i+1][j] == 1&&a[0][i-1][j+1] == 1&&a[0][i][j+1] == 1&&a[0][i+1][j+1] == 1)
        return;
      a[0][i-1][j] = 1;
      a[0][i-1][j-1] = 1;
      a[0][i][j-1] = 1;
      a[0][i+1][j-1] = 1;
      a[0][i+1][j] = 1;
      a[0][i-1][j+1] = 1;
      a[0][i][j+1] = 1;
      a[0][i+1][j+1] = 1;
      checknum(n,a,i-1,j);
      checknum(n,a,i-1,j-1);
      checknum(n,a,i,j-1);
      checknum(n,a,i+1,j-1);
      checknum(n,a,i+1,j);
      checknum(n,a,i-1,j+1);
      checknum(n,a,i,j+1);
      checknum(n,a,i+1,j+1);      
    }
  }
}

void printall(int n, int a[2][n][n])
{
  int i, j, row, num;
  printf("     ");
  for(row = 0;row<n;row++)
    printf("%-2d",row);
  printf("\n\n");
  for(i = 0; i<n; i++)
  {
    printf("%2d   ",i);
    for(j = 0; j<n; j++)
    {
      if(a[0][i][j] == -1)
      {
        printf("* ");
      }else
      {
        printpos(n,a,i,j);
      }
    }
    printf("\n");
  }
}
int find0(int n, int a[2][n][n])
{
  int i, j;
  for(i = 0;i<n;i++)
    for(j = 0;j<n;j++)
      if(a[0][i][j] == 0)
        return 0;
  return 1;
}
void printUI(int n, int a[2][n][n], int x, int y)
{
  int i, j, row, num;
  system("clear");
  if(x>=n||y>=n)
  {
    printf("\n\nError : number is too large.\n\n");
    return;
  }
  if(a[0][x][y] == -1)
  {
    printf("\n\nYOU LOST!\n\n");
    printall(n,a);
    return;
  }
  a[0][x][y] = 1;
  checknum(n,a,x,y);
  printf("     ");
  for(row = 0;row<n;row++)
    printf("%-2d",row);
  printf("\n\n");
  for(i = 0; i<n; i++)
  {
    printf("%2d   ",i);
    for(j = 0; j<n; j++)
    {
      if(a[0][i][j] == 1)
      {
        printpos(n,a,i,j);
      }else
      {
        printf("? ");
      }
    }
    printf("\n");
  }
  printf("\n");
  if(find0(n,a))
  {
    system("clear");
    printf("\n\nYOU WIN!\n\n");
    printall(n,a);
    return;
  }
  int nx, ny;
  printf("Enter the position : row column\n");
  scanf("%d%d",&nx,&ny);
  printUI(n,a,nx,ny);
}

void print3Darr(int n, int a[2][n][n])
{
  int i, j;
  printf("level 1\n");
  for(i = 0; i<n; i++)
  {
    for(j = 0; j<n; j++)
      printf("%d ",-a[0][i][j]);
    printf("\n");
  }
  printf("level 2\n");
  for(i = 0; i<n; i++)
  {
    for(j = 0; j<n; j++)
      printf("%d ",-a[1][i][j]);
    printf("\n");
  }
}
void print1Darr(int n, int *a)
{
  int *p;
  for(p = a; p<a+n; p++)
    printf("%d ",*p);
}
int check_array_repeat(int *a, int x, int m)
{
  int i;
  for(i = 0; i<m; i++)
    if(a[i] == x)
      return 0;
  return 1;
}
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
void sort(int *a, int n)
{
  int i;
  if(n<2)
    return;
  for(i = 0; i<n-1; i++)
    if(a[i]>a[i+1])
      swap(&a[i],&a[i+1]);
  sort(a,n-1);
}
void setfield(int n, int m, int a[2][n][n])
{
  int *p, *q, i, r[m], x;
  for(i = 0; i<m; i++)
    r[i] = -1;
  srand(time(NULL));
  for(i = 0; i<m;)
  {
    x = rand()%(n*n);
    if(check_array_repeat(r,x,m))
    {
      r[i] = x;
      i++;
    }
  }
  sort(r,m);
  //printf("rand = ");
  //print1Darr(m,r);
  //printf("\n");
  for(i = 0,p = &a[0][0][0],q = &a[0][0][0]; p<&a[0][0][0]+n*n; p++)
  {
    if(p-q == r[i])
    {
      *p = -1;
      i++;
    }
    else
      *p = 0;
  }
  for(p = &a[0][0][0],q = &a[1][0][0]; p<&a[0][0][0]+n*n; p++,q++)
    *q = *p;
}
int main(int argc, char **argv)
{
  int n = atoi(argv[1]), m = atoi(argv[2]), mine[2][n][n], x, y, i, j, row;
  if(n>Nmax)
  {
    printf("\n\nYour number is too large\n\n");
    return 0;
  }
  setfield(n,m,mine);
  //printall(n,mine);
  printf("\n");
  printf("     ");
  for(row = 0;row<n;row++)
    printf("%-2d",row);
  printf("\n\n");
  for(i = 0; i<n; i++)
  {
    printf("%2d   ",i);
    for(j = 0; j<n; j++)
    {
      printf("? ");
    }
    printf("\n");
  }
  //print3Darr(n,mine);
  printf("Enter the position : row column\n");
  scanf("%d%d",&x,&y);
  //printf("UI\n");
  printUI(n,mine,x,y);
  printf("\n");
  return 0;
}

