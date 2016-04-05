#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

		int ans[9][9];
		int n;
		int print[9][9];
		int ass;
		int i,j;
		
		void readIn();
		void printAns();
		void solve();
		int soluation;
		void DFS(int i,int j);
		bool NineTest(int i,int j,int k,int aa);
		bool NineTest2(int si,int ei,int sj,int ej,int k,int aa);
		bool RowColTest(int i,int j,int k);
		int Counter(int i);
bool fourTest(int i,int j,int k,int aa);

int pascal,python;




int Counter(int i ){
	int last = 0;
	for (int eden = 0;eden<n*n;eden++)
		last = last + print[eden][8];
	return (45 - last);
}


int Counter2(int i ){
	int last = 0;
	for (int eden = 0;eden<n*n;eden++)
		last = last + print[eden][3];
	return (10 - last);
}



void readIn(){
	for (i = 0;i<9;i++)
		for (j = 0;j<9;j++)
			scanf("%d",&ans[i][j]);
}

void printAns(){
	for (i=0;i<n*n;i++)
	{
		for (j=0;j<n*n;j++)
        {
            if (j!=0) cout<<" ";
			printf("%d",print[i][j]);
        } 	
		printf("\n");
	}
}



bool NineTest(int i,int j,int k,int aa){
	if ( i>=0 && i<=2 && j>=0 && j<=2)
		return NineTest2(0,2,0,2,k,aa);
	if ( i>=0 && i<=2 && j>=3 && j<=5)
		return NineTest2(0,2,3,5,k,aa);
	if ( i>=0 && i<=2 && j>=6 && j<=8)
		return NineTest2(0,2,6,8,k,aa);
	if ( i>=3 && i<=5 && j>=0 && j<=2)
		return NineTest2(3,5,0,2,k,aa);
	if ( i>=3 && i<=5 && j>=3 && j<=5)
		return NineTest2(3,5,3,5,k,aa);
	if ( i>=3 && i<=5 && j>=6 && j<=8)
		return NineTest2(3,5,6,8,k,aa);
	if ( i>=6 && i<=8 && j>=0 && j<=2)
		return NineTest2(6,8,0,2,k,aa);
	if ( i>=6 && i<=8 && j>=3 && j<=5)
		return NineTest2(6,8,3,5,k,aa);
	if ( i>=6 && i<=8 && j>=6 && j<=8)
		return NineTest2(6,8,6,8,k,aa);

}

bool NineTest2(int si,int ei,int sj,int ej,int k,int aa){
		//cout<<endl;
	for (int cc = si;cc<=ei;cc++)
		for (int dd = sj;dd<=ej;dd++)
		{
			//cout<<ans[cc][dd]<<" ";
			if (ans[cc][dd] == k) aa++;
			if (aa>=2) return false;
		}
	return true;
}

bool RowColTest(int i,int j,int k){
	for (int test = 0; test <n*n ;test++)
	{
		if ( test != i)
			if (ans[test][j] == k) return false;
		if ( test != j)
			if (ans[i][test] == k) return false;
	}
	return true;
}

void DFS(int i,int j){
	bool poss = true;
	bool flag = false;
	int row,col;
	int p;
	int yo,ya; 
	int correct = 0;
	for (int k=1;k<=9;k++)
	{
			if (soluation == 1) return;
			poss = true; flag = false;
			poss = NineTest(i,j,k,1);
			if (poss == true) poss = RowColTest(i,j,k);
			if (poss == true) 
			{
				ans[i][j] = k;

				row = i; col = j+1;
				if ( col == 9) { col = 0; row++;}
				while (flag == false)
				{
					if ( ans[row][col] == 0)
					{  DFS(row,col); flag = true; };
					col++;
						
					if (col == 9) {col = 0;row++;}
					if (col == 0 && row == 9) 
					{
						{
								soluation ++;
					   	 	for (int x=0;x<9;x++)
								for (int y=0;y<9;y++)
									print[x][y] = ans[x][y];	

						}
					}
					
					
				}
			}
	}
	ans[i][j] = 0;
}



void solve(){
	bool tester;
	int doo = 0;
    int rowcounter = 0,colcounter = 0;
    int rowrecord = 0,colrecord = 0;
    int rowzero = 0,colzero = 0;
	for (i=0;i<9;i++)
    {
        rowcounter=0;colcounter=0;
        rowrecord =0;colrecord =0;
        rowzero = 0;colzero = 0;
		for (j=0;j<9;j++)
		{
            if (ans[i][j] == 0) {rowrecord = j; rowzero++;}
            if (ans[j][i] == 0) {colrecord = j; colzero++;}
            rowcounter += ans[i][j];
            colcounter += ans[j][i];
			if (ans[i][j] != 0)
			{
				tester = true;
				tester = RowColTest(i,j,ans[i][j]);
				if (tester == true)
				{tester = NineTest(i,j,ans[i][j],0);}
				else { doo = 1; break;}
				if (tester == false){ soluation = 0; doo  = 1; break;}
			}
		}
        if (45-rowcounter <= 9 && 45-rowcounter >=1 && rowzero == 1)
            ans[i][rowrecord] = 45-rowcounter;
        if (45-colcounter <= 9 && 45-colcounter >=1 && colzero == 1)
            ans[colrecord][i] = 45-colcounter;

 
    }

	if (doo == 0)
	{
	i=0; j=0;
	int help = 0; 
	while ( i<9 )
	{
		if ( ans[i][j] == 0)
		{
			DFS(i,j);
			break;
		} else { help++; }
		j++;
		if ( j == 9) { i++; j=0; }
	}

	if (soluation == 1)
		if (print[8][8] == 0)
			print [8][8] = Counter(8);
	
	if (help == 81)
	{
		for (pascal=0;pascal<9;pascal++)
			for (python=0;python<9;python++)
				print[pascal][python] = ans[pascal][python];
		soluation++;
	}

	}

	if (soluation == 1)
	{
    		printAns();
	}
	if (soluation == 0)
		printf("NO SOLUTION\n");
}

void DFS2(int i,int j){
	bool poss = true;
	bool flag = false;
	int row,col;
	int p;
	int yo,ya; 
    int correct = 0;
	for (int k=1;k<=4;k++)
	{
			if (soluation == 1) return;
			poss = true; flag = false;
			poss = fourTest(i,j,k,1);
			if (poss == true) poss = RowColTest(i,j,k);
			if (poss == true) 
			{
				ans[i][j] = k;

				row = i; col = j+1;
				if ( col == 4) { col = 0; row++;}
				while (flag == false)
				{
					if ( ans[row][col] == 0)
					{  DFS2(row,col); flag = true; };
					col++;
						
					if (col == 4) {col = 0;row++;}
					if (col == 0 && row == 4) 
					{
						{
								soluation ++;
					   	 	for (int x=0;x<4;x++)
								for (int y=0;y<4;y++)
									print[x][y] = ans[x][y];	

						}
					}
					
					
				}
			}
	}
	ans[i][j] = 0;
}

bool fourTest(int i,int j,int k,int aa){
	if ( i>=0 && i<=1 && j>=0 && j<=1)
		return NineTest2(0,1,0,1,k,aa);
	if ( i>=0 && i<=1 && j>=2 && j<=3)
		return NineTest2(0,1,2,3,k,aa);
	if ( i>=2 && i<=3 && j>=0 && j<=1)
		return NineTest2(2,3,0,1,k,aa);
	if ( i>=2 && i<=3 && j>=2 && j<=3)
		return NineTest2(2,3,2,3,k,aa);
	}


int main(){
	int lam = 0;
	while (scanf("%d",&n)!=EOF)
	{
        if (lam !=0) printf("\n");
        lam++;
		soluation = 0;
		for (pascal=0;pascal<9;pascal++)
			for (python=0;python<9;python++)
			{
				print[pascal][python] = 0 ;
				ans[pascal][python] = 0 ;
			}
        if (n==3)
        {
		readIn();
		solve();
        }

        if (n==2)
        {
            for (i=0;i<4;i++)
                for(j=0;j<4;j++)
                    scanf("%d",&ans[i][j]);
        

	bool tester;
	int doo = 0;
    int rowcounter = 0,colcounter = 0;
    int rowrecord = 0,colrecord = 0;
    int rowzero = 0,colzero = 0;
	for (i=0;i<4;i++)
    {
      
		for (j=0;j<4;j++)
		{
   
			if (ans[i][j] != 0)
			{
				tester = true;
				tester = RowColTest(i,j,ans[i][j]); 
				if (tester == true)
                		{tester = fourTest(i,j,ans[i][j],0); }
				else { doo = 1;break;}
				
				if (tester == false){ soluation = 0; doo  = 1; break;}
			}
		}
     
    }
 




        if (doo ==0)
{
	i=0; j=0;
	int help = 0; 
	while ( i<4 )
	{
		if ( ans[i][j] == 0)
		{
			DFS2(i,j);
			break;
		}  { help++; }
		j++;
		if ( j == 4) { i++; j=0; }
	}

	if (help == 16)
	{
		for (pascal=0;pascal<4;pascal++)
			for (python=0;python<4;python++)
				print[pascal][python] = ans[pascal][python];
		soluation++;
	}





}
	if (soluation == 1)
		if (print[3][3] == 0)
			print [3][3] = Counter2(3);

	if (soluation == 1)
	{
		printAns();
	}
	if (soluation == 0)
		printf("NO SOLUTION\n");
    	
        }   


        if (n==1)
        {
            scanf("%d",&n);
            printf("1\n");
        }
	}

}
