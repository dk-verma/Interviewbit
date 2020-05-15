https://www.interviewbit.com/problems/min-xor-value/

int Solution::findMinXor(vector<int> &A) 
{
    
    vector <int > arr(A) ;
    
    sort(arr.begin(), arr.end());
 
    int minXor = INT_MAX;
    int val = 0;
 
    for (int i = 0; i < arr.size()- 1; i++) 
    {
        val = arr[i] ^ arr[i + 1];
        minXor = min(minXor, val);
    }
 
    return minXor;
}
