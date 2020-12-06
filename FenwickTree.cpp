//двумерное дерефо фенвика, операции: увеличение элемента на 1, взятие суммы в прямоугольнике
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back

ll const INF = 1e13;

vector < vector < ll > > v;
ll n, k;
	
struct point{
	ll x, y;
};

istream& operator>>( istream &in, point &p ){
	in >> p.x >> p.y;
	return in;
}

void add( point p ){
	for( ll x = p.x; x <= n; x = ( x | (x+1) )){
		for( ll y = p.y; y <= n; y = ( y | (y+1) )){
			v[ x ][ y ]++;
		}
	}
}

ll get( point p ){
	if( p.x < 0 || p.y < 0 )
		return 0;
	ll ans = 0;
	for( ll x = p.x; x >= 0; x = ( x & (x+1) ) - 1 ){
		for( ll y = p.y; y >= 0; y = ( y & (y+1) ) - 1 ){
			ans += v[ x ][ y ];
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	v.resize( n + 1 );
	for( auto &i : v ){
		i.resize( n + 1 );
	}

	for( ll i = 0; i < k; ++i ){
		string str;
		point p1, p2;
		cin >> str;
		if( str == "ADD" ){
			cin >> p1;
			add( p1 );
		}
		else{
			cin >> p1 >> p2;
			if( p1.x >= p2.x && p1.y >= p2.y ){
				swap( p1, p2 );
			}

			if( p1.x > p2.x && p1.y < p2.y ){
				point pc;
				pc = { p2.x, p1.y };
				p2 = { p1.x, p2.y };
				p1 = pc;
			}
			if( p1.x < p2.x && p1.y > p2.y ){
				point pc;
				pc = { p1.x, p2.y };
				p2 = { p2.x, p1.y };
				p1 = pc;
			}
			
			cout << get( p2 ) - get( point{ p1.x - 1, p2.y } )  - get( point{ p2.x, p1.y - 1 } ) + get( point{ p1.x-1, p1.y-1 } ) << endl;
		}
	}

	return 0;
}
