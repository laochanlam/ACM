#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int num;
	while (cin>>num, num) {
		vector <int> v;
		v.push_back(num);
		while (cin>>num, num) v.push_back(num); // till zero
		int sec_num = 0;
		for (int i = 0; i < v.size(); i++) {
			if ( sec_num == 0 ) {
				sec_num = abs( v[i] - v[0] );
			} else {
				int as = abs( v[i] - v[0] );
				while ( as%=sec_num ) swap(as, sec_num); //GCD!!!
			}
		}
		cout <<sec_num<<endl;
	}
	
} 
