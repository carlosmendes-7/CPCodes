//LIS in any partially ordered domain
//https://www.quora.com/How-can-the-SPOJ-problem-LIS2-be-solved
//https://csit.am/2009/proceedings/2DMCA/5.pdf
//https://core.ac.uk/download/pdf/82062831.pdf
#include <iostream>
#include <map>
using namespace std;

struct NiceDay{
	map<int,int> M;
	bool find(int x, int y){
		map<int,int>::iterator lb = M.lower_bound(x);
		if (lb == M.begin())
			return false;
		lb--;
		if (lb->second < y)
			return true;
		else
			return false;
	}
	void add(int x, int y){
		map<int,int>::iterator lb = M.lower_bound(x);
		map<int,int>::iterator i2 = lb;
		while (i2 != M.end() && i2->second >= y)
			i2++;
		M.erase(lb,i2);
		M.insert(pair<int,int>(x,y));
	}
};
int main(){
	static NiceDay a[100010];
	int N, x, y;
	cin >> N >> x >> y;
	a[1].add(x,y);
	int L = 1;
	for(int i = 0; i < N-1; ++i){
		cin >> x >> y;
		int l = 0;
		int u = L;
		int m = 0;
		while(u > l){
			m = (l+u+1)/2;
			if(a[m].find(x,y))
				l = m;
			else
				u = m-1;
		}
		if (L <= l)
			L = l+1;
		a[l+1].add(x,y);
	}
	printf("%d\n", L);
}