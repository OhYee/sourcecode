/*
By:OhYee
Email:oyohyee@oyohyee.com
QQ:896817156
GitHub:OhYee
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <memory>
#include <cstdlib>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

const int maxn=105;
int L,M,N;
int stone[maxn];

int main(){
	//freopen("2015stone.in","r",stdin);
	//freopen("2015stone.out","w",stdout);

	scanf("%d%d%d",&L,&N,&M);
	REP(N)
		scanf("%d",&stone[o]);
	stone[N]=L;
	sort(stone,stone+N+1);

	int l=0,mid=0,cnt=0;
	REP(N){
		if(cnt==M)break;
		if(mid>min(stone[o]-l,L-stone[o])){
			cnt++;
			continue;
		}
		mid=min(stone[o]-l,L-stone[o]);
		l=stone[o]-l;
	}
	printf("%d",mid);

	return 0;
}