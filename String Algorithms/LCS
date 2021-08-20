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
