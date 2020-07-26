#include <bits/stdc++.h>
#include <sstream>
#include <dir.h>
#define task "/liftovi"
using namespace std;
const int nmax=int(1e5)+10;
const int nv[10]={20,200,341,521,100,800253,801021,910212,964231,1000000};
int ok[1001][1001];
int main()
{
	srand(time(0));
	string s;
	for(int t=0;t<20;t++)
	{
		stringstream ss;
		ss<<t;
		s=ss.str();
		if(t<10) s='0'+s;
		s="test"+s;
		cout<<s<<"..."<<endl;
		mkdir(s.c_str());
		string si=s+task".inp";
		string so=s+task".out";
		ofstream fi(si.c_str());
		ofstream fo(so.c_str());
		//print input/output below
		int k=rand()%((t+1)*50)+1;
		if(t>=18) k=1000;
		if(t==0) k=10;
		if(t==1) k=15;
		memset(ok,0,sizeof(ok));
		int n=0;
		int x=1,tmp=1;
		while(x<k)
        {
            int y=rand()%max((k/10),3)+1;
            ok[x][x+y]=1;
            tmp=x;
            x+=y;
        }
        ok[tmp][k]=1;
		for(int i=1;i<=k;i++)
            for(int j=i+1;j<=k;j++)
                if(rand()%10==0) ok[i][j]=1;
        for(int i=1;i<=k;i++)
            for(int j=i+1;j<=k;j++) n+=ok[i][j];
        fi<<k<<" "<<n<<endl;
        for(int i=1;i<=k;i++)
            for(int j=i+1;j<=k;j++)
                if(ok[i][j]) fi<<i<<" "<<j<<endl;
		fi.close();
		fo.close();
	}
}
