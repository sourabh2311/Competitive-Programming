/** Once we reach 1, then all the following elements would neccessarily be 1 and
thus cycle length would be 1 **/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<int,int> mii;
typedef map<string, int> msi;
typedef map<int,pair<int,int> > miii;
typedef complex<double> point;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef vector<vi > vvi;
#define X real()
#define Y imag()
#define FileIn(file) freopen(file".txt", "r", stdin)
#define FileOut(file) freopen(file".txt", "w", stdout)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 10000010
#define VISITED 1
#define UNVISITED -1
#define P(p) const point &p
#define L(p0, p1) P(p0), P(p1)
int f(int x)
{
    int sq=0,temp;
    while(x>0)
    {
        temp=x%10;
        sq+=temp*temp;
        x/=10;
    }
    return sq;
}
int floydCycleFinding(int x0) { // function int f(int x) is defined earlier
// 1st part: finding k*mu, hare�s speed is 2x tortoise�s
    int tortoise = f(x0), hare = f(f(x0)); // f(x0) is the node next to x0
    while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }
// 2nd part: finding mu, hare and tortoise move at the same speed
    int mu = 0; hare = x0;
    while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); mu++;}
// 3rd part: finding lambda, hare moves, tortoise stays
    int lambda = 1; hare = f(tortoise);
    while (tortoise != hare) { hare = f(hare); lambda++; }
    return (lambda);
}


int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int N,T;
    cin>>T;
    for(int cases=1;cases<=T;cases++)
    {
        cin>>N;
        cout<<"Case #"<<cases<<": "<<N<<" is ";
        if(floydCycleFinding(N)==1) cout<<"a Happy number.\n";
        else cout<<"an Unhappy number.\n";
    }

    return 0;
}

