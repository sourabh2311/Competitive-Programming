#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include<set>
#include<bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 10000010
ii s;
vi result;
vector<int> prime;
ll _sieve_size,lm; // ll is defined as: typedef long long ll;
bitset<10000010> bs; // 10^7 + small extra bits should be enough for most prime-related problems
void sieve(ll upperbound) { // create list of primes in [0 .. upperbound]
_sieve_size = upperbound + 1; // add 1 to include upperbound
bs.reset(); bs.flip(); // set all numbers to 1
bs.set(0, false); bs.set(1, false); // except index 0 and 1
for (ll i = 2; i <= _sieve_size; i++) if (bs.test((size_t)i)) {
// cross out multiples of i starting from i * i!
for (ll j = i * i; j <= _sieve_size; j += i) bs.set((size_t)j, false);
prime.push_back((int)i); // also add this vector containing list of primes
}
}
bool isPrime(unsigned long long int n) {
    if (n < _sieve_size) return bs.test(n);
    for (int i=0, lm=(int)sqrt(n); i<prime.size() && prime[i]<=lm; i++)
        if (n%prime[i]==0) return false;
    return true;
}
vii primeFactors(unsigned long long int N) {
vii factors; 
bool divide = false;
int t;// vi "primes" (generated by sieve) is optional
unsigned long long int PF_idx = 0, PF = prime[PF_idx]; // using PF = 2, 3, 4, ..., is also ok.
while (N != 1 && (PF * PF <= N)) {
t=0; // stop at sqrt(N), but N can get smaller
while (N % PF == 0) {t++; N /= PF; divide = true; } 
if(divide)
{
	s.first=PF;
	s.second=t;
	factors.push_back(s);
}
divide=false;
PF = prime[++PF_idx]; 
}
if (N != 1){
 s.first=N;
 s.second=1;
 factors.push_back(s);}
return factors;
}
int main() 
{
	sieve(10000); // can go up to 10^7
	//freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int t,m,n,cases=0,ratio,min=10000;
	bool divide;
	vii::iterator it,it2;
	scanf("%d",&t);
	while(t--)
	{
		divide=true;
		min=10000;
		//result.push_back(1);
		result.clear();
		result.resize(10001);
		vii truefactors;
		vii factors;
		cases++;
		scanf("%d %d",&m,&n);
		printf("Case %d:\n", cases);
		truefactors=primeFactors(m);
		while(n>0)
		{
			factors=primeFactors(n);
			for(it=factors.begin();it!=factors.end();it++)
			{
				result[it->first]+=it->second;
			}
			n--;
		}
		for(it=truefactors.begin();it!=truefactors.end();it++)
		{
			if(result[it->first]!=0)
			{
				if(it->second<=result[it->first])
				{
					ratio=result[it->first]/(it->second);
				}
				if(ratio<min)
				{
					min=ratio;
				}
			}
			else
			{
				printf("Impossible to divide\n");
				divide=false;
				break;
			}
		}
		if(divide)
		printf("%d\n",min);
	}
		return 0;
}
