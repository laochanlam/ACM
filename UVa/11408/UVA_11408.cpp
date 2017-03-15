	#include <cstdio> 
	#include <iostream>
	#include <cmath>
	#include <cstdlib> 
	#include <cstring>
	#include <vector>
	#include <algorithm>
	using namespace std;
	#define MAX 6000000
	
	
	
	bool isPrime[MAX]; 
	long long int i,j;
 	int dp[MAX];
	
	
	void findPrime()
	{
		memset( dp, 0, sizeof(dp));
	    memset( isPrime, 1, sizeof(isPrime));
	    isPrime[0] = isPrime[1] = false;
	    
	    for ( i=2; i<MAX; i++) {
	    	if (isPrime[i]) {
	    		dp[i] = dp[i] + i ;
	    	    for ( j =i*2; j < MAX; j=j+i ) {
	    	        isPrime[j] = 0;
	    	        dp[j] = dp[j] + i;
	    	    }
//	    		primes.push_back(i);
			} 	
		}
//		for ( i = sqrt(MAX)+1 ; i < MAX ; i ++)
//			if (isPrime[i])
//				primes.push_back(i); 
//		
	}
	
	int main(){
		
		long long int a,b;
		findPrime();
		
//		for (i=0;i<=50;i++)
//			cout<<dp[i]<<" ";
		
		for (i=2;i<MAX;i++) {
			if ( isPrime[dp[i]]  ) dp[i] = dp[i-1] + 1 ;
			else dp[i] = dp[i-1]; 
		} // dp here.
		
//		cout<<endl<<endl;
//		
//				for (i=0;i<50;i++)
//			cout<<dp[i]<<" ";
		
		while ( cin>>a,a ) {
			cin >> b;
			printf("%lld\n", dp[b] - dp[a-1] );
			
		}
		
}
