//Input : "aaaabaaa", Output : "aaabaaa"

string Solution::longestPalindrome(string A) 
{
    int start = 0, left, right, maxLen = 1, length = A.size();
    string sol; //string sol = "";
    
    for(int i = 0; i < length; i++)
    {
        left = i-1;
        right = i;
        while( left >= 0 && right < length && A[left] == A[right] )
        {
            if((right - left + 1) > maxLen)
            {
                maxLen = right-left+1;
                start = left;
            }        
            left--;
            right++;
        }
        
        left = i-1;
        right = i+1;
        while( left >= 0 && right < length && A[left] == A[right] )
        {
            if((right - left + 1) > maxLen)
            {
                maxLen = right-left+1;
                start = left;
            }        
            left--;
            right++;
        }
    }
    
    sol=A.substr(start,maxLen);
    
    /*
    high = start+maxLen;
    while(start != high)
    {
        sol = sol + A[start];
        start++;
    }*/
    
    return sol;
}
