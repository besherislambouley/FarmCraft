/*
 * let dp [i] = the answer of the subtree of node i , sz [i] the number of roads in the subtree of node i 
 * to calculate dp [i] you should know the best order of visiting your children for every node
 * we sort the children according to dp [i] - 2 * sz [i] and find our answer paying attention to some other details
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
//#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
int n ;
vi v  [500009] ;
int a [500009] , dp [500009] , sz [500009] ;
bool cmp ( pi x , pi y ) {
	return ( x .fi - x.se ) > ( y.fi - y .se ) ;
}
void dfs ( int node , int p ) {
	if ( node ) dp [node] = a [node] ;
	vpi ret ; 
	for ( auto u : v [node] ) {
		if ( u == p ) C ;
		dfs ( u , node ) ;
		sz [node] += sz [u] + 1 ;
		ret .pb ( { dp [u] , 2 * sz [u] } ) ;
	}
	sort ( ret .begin() , ret .end() , cmp ) ;
	int sum = 0 ;
	for ( int i = 0 ; i < ret.size() ; i ++ ) {
		dp [node]  = max ( dp [node] , ret [i].fi + sum + 1 ) ;
		sum += ret [i].se + 2 ; 
	}
}
int main () {
	scanf("%d",&n);
	for ( int i = 0 ; i < n ; i ++ ) scanf("%d",&a[i]) ;
	for ( int i = 0 ; i < n -1 ; i ++ ) {
		int a , b ;
		scanf("%d%d",&a,&b);
		a -- , b -- ;
		v [a] .pb ( b ) ;
		v [b] .pb ( a ) ; 
	}
	dfs ( 0 , 0 ) ;
	printf("%d\n",max ( dp [0] , a [0] + 2 * sz [0] ) ); 
}
