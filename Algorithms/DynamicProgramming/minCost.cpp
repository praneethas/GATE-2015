#include <iostream>
using namespace std;

char arrow[3][3];

int min(int x, int y, int z)
{
 if(x<y&&x<z) return x;
 else if(y<x&&y<z) return y;
 else return z;
}

int tcp(int c[][3], int m,int n)
{
 int t[3][3]={0},p;
 int i,j;
 t[0][0]=c[0][0];
 arrow[0][0]='0';
 for(i=1;i<=m;i++)
  {
  t[i][0]=t[i-1][0]+c[i][0];
  arrow[i][0]='b';
  }
  
 for(j=1;j<=n;j++)
  {
  t[0][j]=t[0][j-1]+ c[0][j];
  arrow[0][j]='l';
  }
  
 for(i=1;i<=m;i++)
 {
  for(j=1;j<=n;j++)
  {
   t[i][j]= c[i][j];
   p= min(t[i-1][j-1], t[i-1][j], t[i][j-1]);
   t[i][j]+=p;
   if(p==t[i-1][j-1])
    arrow[i][j]='d';
   else if(p==t[i][j-1])
    arrow[i][j]='l';
   else arrow[i][j]='b';
  }
 }
 
 return t[m][n];
}

int main() {
	// your code goes here
	int cost[3][3], m,n,path;
	int i,j;
	for(i=0;i<3;i++)
	{
	 for(j=0;j<3;j++)
	 {
	  cin>>cost[i][j];
	 }
	}
	cin>>m>>n;
	path=tcp(cost,m,n);
	cout<<path<<endl;
	/*cout<<"the path array  is \n";
	for(i=0;i<3;i++)
	{
	 for(j=0;j<3;j++)
	 cout<<arrow[i][j];
	 cout<<endl;
	}*/
	cout<<"the path as per cell is \n";
	int trav1=m,trav2=n;
	while(arrow[trav1][trav2]!='0')
	{
	cout<<"("<<trav1<<","<<trav2<<") ";
	 if(arrow[trav1][trav2]=='b')
	 {
	  trav1--;
	 }
	 else if(arrow[trav1][trav2]=='d')
	 {
	  trav1--; trav2--;
	 }
	 else
	  trav2--;
	}
	cout<<"(0,0)";
	return 0;
}