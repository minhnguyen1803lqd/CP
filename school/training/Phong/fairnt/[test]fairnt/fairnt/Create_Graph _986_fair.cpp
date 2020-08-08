#include <bits/stdc++.h>
#include <dir.h>
#define Nmax (int) 1E5+1
#define maxval (int) 1E9+1
#define so_test (int) 20
using namespace std;
long n,m;
long dinh[so_test];
long canh[so_test];
long ka[so_test];
vector <long> Edges[Nmax];
stack <long>S;
int BFS(long n, long m)
{

    queue <long> Q;
    long ok[Nmax];
    for(long u=1;u<=n;u++) ok[u]=0;
    Q.push(1); ok[1]=1;

    while(!Q.empty())
    {
        long u=Q.front();
        //cout<<u<<endl;
        Q.pop();
        for(long v=0; v<Edges[u].size();v++)
        if(!ok[Edges[u][v]])
            {
                Q.push(Edges[u][v]);
                ok[Edges[u][v]]=1;
            }
    }
   for(long u=1;u<=n;u++)
    if(!ok[u]) return 0;
    return 1;
}
int check(long x,long y)
{
    for(long i=0;i<Edges[x].size();i++)
        if(Edges[x][i]==y) return 1;
    return 0;
}
//================
void create_G(long n, long m)
{
      cout<<"---Number Of V= ";cout<<n<<endl;
      cout<<"---Number Of E= ";cout<<m<<endl;
      //if((0)||(m>(n*(n-1)/2))) cout<<"ERROR DATA. PLEASE TRY AGIAN:"<<endl;
    while(true)
    {
       while(!S.empty()) S.pop();
       for(long x=1;x<=n;x++) S.push(x);
       for(long x=1;x<=n;x++) Edges[x].clear();
       for(long i=1;i<=m;i++)
          {
            long x,y;
            while(true)
              {
                if(!S.empty()){x=S.top();S.pop();}
                   else  x=1+(rand()%n);
                y=1+(rand()%n);
                if((x!=y)&&(!check(x,y))) break;
              }
           Edges[x].push_back(y);
           Edges[y].push_back(x);
         }

        if(BFS(n,m)) break;
    }
}
void output(char test_file[],int n, int m)
{
    ofstream fo(test_file);
    fo<<n<<" "<<m<<" ";
    int k=rand()%min(n,100)+1;
    int a[Nmax],dem[Nmax];
    memset(dem,0,sizeof(a));
    for(int i=1;i<=n;i++)
        {
            a[i]=rand()%k+1;
            dem[a[i]]++;
        }
    int s=0;
    for(int i=1;i<=k;i++)
            if(dem[i]>0) s++;
    s=rand()%s+1;
    fo<<k<<" "<<s<<endl;
    for(int i=1;i<=n;i++) fo<<a[i]<<" ";
    fo<<endl;
    for(long x=1;x<=n;x++)
        for(long y=0;y<Edges[x].size();y++)
        if(x<Edges[x][y]) fo<<x<<" "<<Edges[x][y]<<endl;//" "<<1+rand()%maxval<<endl;
     fo.close();
}
int main()
{

    srand(time(NULL));
    ios :: sync_with_stdio(false);
    ifstream cin("test.txt");
    char test_file[20]="fairnt.inp";
    int i=0;
    while(cin>>dinh[i]&&cin>>canh[i]&&cin>>ka[i]) i++;
    cin.close();

    for(int k=12;k<13;k++)
    {
     cout<<"Test "<<k<<endl;
     create_G(dinh[k],canh[k]);
     cout<<"---done!"<<endl;
     char st[100]="TEST";
     char test[100];
     itoa(k,test,10);
     char t0[20]="0";
     if(strlen(test)==1) { strcat(t0,test); strcpy(test,t0);}
     strcat(st,test);
     mkdir(st);
     strcat(st,"/");
     strcat(st,test_file);
     output(st,dinh[k],canh[k]);
    }
    return 1;
}
