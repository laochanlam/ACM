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
	int dp[MAX];
	
	
	void findPrime()
	{
		memset( dp, 0, sizeof(dp));
	    memset( isPrime, 1, sizeof(isPrime));
	    isPrime[0] = isPrime[1] = false;
	    
	    for ( i=2; i<= sqrt(MAX); i++) {
	    	if (isPrime[i]) {
	    		dp[i] = dp[i] + i ;
	    	    for ( j =i*i; j < MAX; j=j+i ) {
	    	        isPrime[j] = 0;
	    	        dp[j] = dp[j] + i;
	    	    }
	    		primes.push_back(i);
			} 	
		}
		for ( i = sqrt(MAX)+1 ; i < MAX ; i ++)
			if (isPrime[i])
				primes.push_back(i); 
		
	}
	
	int main(){
		
		long long int a,b;
		findPrime();
		
		for (i=0;i<=50;i++)
			cout<<dp[i]<<" ";
		
		for (i=0;i<MAX;i++) {
			if ( isPrime[dp[i]]  ) dp[i] = dp[i-1] + 1 ;
			else dp[i] = dp[i-1]; 
		}
		
		cout<<endl<<endl;
		
				for (i=0;i<50;i++)
			cout<<dp[i]<<" ";
		
		/* 
	//		for (i=0; i<primes.size();i++)
	//		cout<<primes[i]<<" ";
	//		cout<<endl;			 
	    while (cin>>a) {
	    	if (a == 0) return 1;
	    	cin >> b;
	    	bool bango = 0;
			long long int count = 0;
			
			
			for (int num = a; num <=b ; num++)
			{
				// binary search
				if (isPrime[num]) {
					count++; 
				} else
				
				{

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
//						cout<<num - primes[i]<< " ";
						if ( num-primes[i] - primes[i] !=0 ) {
							bango = true;
							if ( isPrime[primes[i] + num-primes[i]])
							count++;	
						}
					}
				}
				}
			}
			cout<<count<<endl;
		} */ 
}
