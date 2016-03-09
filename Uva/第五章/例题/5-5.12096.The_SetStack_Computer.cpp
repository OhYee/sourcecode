#include <cstdio>
#include <set>
#include <stack>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class LOVE{
	private:
		int n;
		typedef set<int> element;
		stack <int> s;

		map<element,int> ID_cache;
		vector<element> ID_cache2;

		int ID(element x){
			if(ID_cache.count(x))return ID_cache[x];
			ID_cache2.push_back(x);
			return ID_cache[x]=ID_cache2.size()-1;
		}

	public:
		void start(){
			scanf("%d",&n);
			char com[10];
			while(n--){
				scanf("%s",com);
				element temp1,temp2,temp3;
				element::iterator it1,it2,it;
				switch(com[0]){
					case 'P':
						s.push(ID(element()));
						break;
					case 'D':
						s.push(s.top());
						break;
					case 'U':
						temp1=ID_cache2[s.top()];
						s.pop();
						temp2=ID_cache2[s.top()];
						s.pop();
						for(it=temp2.begin();it!=temp2.end();it++)
							temp1.insert(*it);
						s.push(ID(temp1));
						break;
					case 'I':
						temp1=ID_cache2[s.top()];
						s.pop();
						temp2=ID_cache2[s.top()];
						s.pop();
						for(it1=temp1.begin();it1!=temp1.end();it1++){
							for(it2=temp2.begin();it2!=temp2.end();it2++){
								if(*it1==*it2){
									temp3.insert(*it1);
									temp2.erase(*it2);
									break;
								}
							}
						}
						s.push(ID(temp3));
						break;
					case 'A':
						temp1=ID_cache2[s.top()];
						s.pop();
						temp2=ID_cache2[s.top()];
						s.pop();
						temp2.insert(ID(temp1));
						s.push(ID(temp2));
						break;
				}
				cout<<ID_cache2[s.top()].size()<<endl;
			}
		}
};


int main(){
	//freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	while(n--){
		LOVE LIVE;
		LIVE.start();
		printf("***\n");
	}
	return 0;
}