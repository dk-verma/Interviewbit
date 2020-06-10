//1, 11, 21, 1211, 111221, ...
//Example: if n = 2, the sequence is 11.

string Solution::countAndSay(int A)
{
    string ans1 = "1";
    if(A==1) 
        return ans1;
    string pre = countAndSay(A-1);    // call prev string for A-1 & then use that for A
    string ans;
    for(int i=0; i<pre.size(); i++)
    {
        int count =1;
        if( i==pre.size()-1 || pre[i]!=pre[i+1] )
            ans+=to_string(count)+pre[i];
            
        if(pre[i]==pre[i+1])
        {
          while( i<pre.size() && pre[i]==pre[i+1])
            count++,i++;
          ans+=to_string(count)+pre[i];
        }
    }
    return ans;
}
