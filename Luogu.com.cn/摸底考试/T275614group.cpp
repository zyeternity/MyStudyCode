// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;


long long a[10000+10];
int main(){
	int t;
	cin>>t;
	for (int ks = 0; ks < t; ks++)
	{
		int n,m;
		cin>>n>>m;
		for (int i = 0; i < n; i++)
		{
			cin>>a[i];
		}
		sort(a,a+n,
			[&](int a,int b)
			{
				return a<b;
			}
		);
		bool can = true;
		for (int i = 0; i < n/3; i++)
		{
			int las;
			for (int j = 0; j < m; j++)
			{
				if(j == 0)
				{
					las = a[i * 3 + j];
				}
				else
				{
					if(a[i * 3 + j] != las + 1)
					{
						can = false;
					}
					else
					{
						las = a[i * 3 + j];
					}
				}
				if(!can){
					break;
				}
			}
			if(!can){
				break;
			}
		}
		cout<<(can ? "true\n" : "false\n");
	}
	

	return 0;
}










// #include<iostream>
// #include<cstdio>
// #include<cstring>
// #include<string>
// #include<cmath>
// #include<algorithm>
// using namespace std;
// int n,k,t,x,w;
// bool flag=0,ok;
// long long d[11000],v[11000];
// int main() {
// 	scanf("%d",&t);
// 	while(t--) {
// 		memset(v,0,sizeof(v));
// 		scanf("%d%d",&n,&k);
// 		for(int i=1; i<=n; i++)
// 			scanf("%lld",&d[i]);
// 		if(k==1)
// 		{
// 			printf("true\n");
// 			continue;
// 		}
// 		sort(d+1,d+n+1);
// 		flag=0;
// 		for(int i=1; i<=n; i++) {
// 			x=i,w=0,ok=0;
// 			if(!v[x])
// 			{
// 				v[x]=1;
// 				for(int j=i+1; j<=n; j++) 
// 				{
// 					if(!v[j]&&d[j]-d[x]==1) 
// 					{
// 						w++;
// 						v[j]=1;
// 						x=j;
// 						if(w==k-1)
// 						{
// 							ok=1;
// 							break;
// 						}
// 					}
// 				}
// 				if(!ok)
// 				{
// 					flag=1;
// 					printf("false\n");
// 					break;
// 				}
// 			}
// 		}
// 		if(!flag)printf("true\n");		
// 	}
// }

