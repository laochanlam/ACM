	#include <cstdio> 
	#include <iostream>
	#include <cmath>
	#include <cstdlib> 
	#include <cstring>
	#include <vector>
	#include <algorithm>
	using namespace std;
	#define MAX 100000011	
	
	bool isPrime[MAX]; 
	long long int i,j;
	vector<long long int> primes;
	
	void findPrime()
	{
	    memset( isPrime, 1, sizeof(isPrime));
	    isPrime[0] = isPrime[1] = false;
	    
	    for ( i=2; i<= sqrt(MAX); i++) {
	    	if (isPrime[i])
	    	{
	    	    for ( j =i*i; j < MAX; j=j+i )
	    	        isPrime[j] = 0;
	    		primes.push_back(i);
			} 	
		}
		for ( i = sqrt(MAX)+1 ; i < MAX ; i ++)
			if (isPrime[i])
				primes.push_back(i); 
		
	}
	
	int main(){
		
		long long int num;
		findPrime();
		
	//		for (i=0; i<primes.size();i++)
	//		cout<<primes[i]<<" ";
	//		cout<<endl;			 
	    while (cin>>num) {
	    	bool bango = 0;
	    	if ( num % 2 != 0) {
	    		if ( isPrime[num-2] ) {
	    		    cout << num << " is the sum of " << "2" << " and " << num-2 << "." <<endl ;
	    		    bango = true;
	    	    }
			} else {
		
				// binary search
				
				long long int low = 0;
				long long int high = primes.size();
				long long int mid;
//				cout << "binary search start!" << endl;
				while (low < high) {
//					cout << primes[high] << " ";
					mid = (low + high) / 2;
//		
					if ( primes[mid] > num / 2 ) {
						high = mid - 1;  
					}
					else {
						low = mid + 1;
					}
				} 
//				cout << "the middle one is " << primes[high] << endl; 
				
				for ( i = high; i <primes.size(); i++ ) {
					if (num - primes[i] > 0)
					{
//					cout<<num - primes[i]<< " ";
					if (isPrime[num-primes[i]] && num-primes[i] - primes[i] !=0 ) {
						bango = true;
						cout << num << " is the sum of " << min( primes[i] , (num-primes[i]) ) << " and " << max( primes[i] , num-primes[i] ) << "." <<endl ;
						break;
					}
					}
				}
			}
			if (!bango)
		    cout << num << " is not the sum of two primes!" << endl;
		    }
		}
