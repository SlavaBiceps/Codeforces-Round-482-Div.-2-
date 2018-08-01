#include <bits/stdc++.h>
using namespace std;

long long n,pp,cn,res;
long long mas[300002],gor[300002];
vector<long long>graph[300002];

void dfs(long long x, long long p) {
	gor[x] = 1;
	for(long long v: graph[x])
	{
		if(v==p) {
			continue;
		}
		mas[v]=x;
		dfs(v,x);
		gor[x]+=gor[v];
	}
}

void up(long long x)
{
	if(x==cn) return;
	res=x;
	up(mas[x]);
}

int main()
{
	cin >> n >> cn >> pp;
	for(long long i = 1, a, b; i < n; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(cn,cn);
	up(pp);
	cout<<(n*(n - 1)) - (gor[cn] - gor[res])*gor[pp]<<"\n";
}