/** Returns LCS of two strings
 *  
 * @param a,b strings
 * @return lcs LCS of a and b or empty string  
 *  		   if either is empty
 */
 

string lcs(string &a, string &b){
	int a_size = a.size(), b_size = b.size();
	
	if(a_size==0||b_size==0)
		return " ";
	
	int dp[a_size+1][b_size+1];
	
	/*
	 TC : O(n*m)
	 SC : O(n*m) as we are storing each state
	*/
	for(int i=0;i<=a_size;i++){
		for(int j=0;j<=b_size;j++){
			if(i==0||j==0) dp[i][j] = 0;
			else if(a[i-1]==b[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	
	
	//cout<<dp[a_size][b_size]<<"\n";
	
	string lcs;
	lcs.reserve(dp[a_size][b_size]);
	
	int i = a_size, j = b_size;
	while(i>0&&j>0){
		if(a[i-1]==b[j-1]){
			lcs=a[i-1]+lcs;
			i--;j--;
		}
		else if(dp[i-1][j]>dp[i][j-1])
			i--;
		else j--;
			
	}
	
	return lcs;
	
}

/* Space Optimised LCS of two strings
   
   As are only using states of one row above to calculate current row, we can use only
   two rows, first for prev and second for current and vice versa.
   
   TC : O(n*m) 
   SC : O(2*min(n,m)) = O(min(n,m))
*/

int lcs(string &a, string &b) {
  if (a.size() < b.size()) return lcs(b, a);
  
  vector<vector<short>> dp(2, vector<short>(b.size() + 1));

  for (int i = 1; i <= (int)a.size(); ++i){
    for (int j = 1; j <= (int)b.size(); ++j){
    	
      	if (a[i - 1] == b[j - 1])
       		dp[i % 2][j] = dp[(i -1) % 2][j - 1] + 1;
       		
      	else dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
      	}
      }
  return dp[a.size() % 2][b.size()];
}
