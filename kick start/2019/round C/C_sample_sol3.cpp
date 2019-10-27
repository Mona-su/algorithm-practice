#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int N=1100;
int n,K,A[N],p[N],f[N][N][2];
const int inf=1e9;
vector<int> x[1100];
const int m=1000;
void update(int &k1,int k2){
	k1=min(k1,k2);
}
void solve(){
	scanf("%d%d",&n,&K);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	for (int i=1;i<=m;i++) x[i].clear();
	for (int i=1;i<=n;i++) x[A[i]].push_back(p[i]);
	for (int i=1;i<=m;i++) sort(x[i].begin(),x[i].end());
	memset(f,0x3f,sizeof f);
	f[0][0][0]=0;
	for (int i=1;i<=m;i++)
		for (int j=0;j<=K;j++)
			for (int k=0;k<2;k++)
				if (f[i-1][j][k]<inf){
					update(f[i][j][k],f[i-1][j][k]);
					for (int a=1;a+j<=K&&a-1<x[i].size();a++){
						update(f[i][j+a][k],f[i-1][j][k]+x[i][a-1]*2);
						if (k==0) update(f[i][j+a][1],f[i-1][j][k]+x[i][a-1]);
					}
				}
	printf("%d\n",f[m][K][1]);
}
int main(){
	int t; scanf("%d",&t);
	for (int i=1;i<=t;i++){
		printf("Case #%d: ",i); solve();
	}
}