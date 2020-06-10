// Given a string containing only digits, restore it by returning all possible valid IP address combinations.

// A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

// Example: Given “25525511135”, return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)
    
bool  isValid(string s)
{
    int i, n=s.length(), number, start=0;
    string temp="";
    
    while(start < n)
    {
        i=start;
        temp="";
        
        while(i<n && s[i]!='.')
          i++;
        
        if(i-start >3) // digit of number > 3
            return false;
            
        temp=s.substr(start,i-start);
        
        number=stoi(temp);
        
        // if(number > 255)
        //     return false;
        // if(number == 0 && temp.length()>1)
        //     return false;
        // if(temp.length() > 1 && s[start]=='0')
        //     return false;
         
        if(number>255 || ( number==0 || s[start]=='0') && temp.length()>1 )
            return false;
        start=i+1;
    }
    return true;
}
vector<string> Solution::restoreIpAddresses(string A) 
{
    vector <string> B;
    int i,j,k,l=A.length();
    string s;
    for(i=1;i<l-2;i++) 
      for(j=i+1;j<l-1;j++)
        for(k=j+1;k<l;k++)
        {
          s=A;  // assign str s = A
              
          s.insert(k,".");  // inserting '.' in reverse order
          s.insert(j,".");
          s.insert(i,".");
              
          if(isValid(s))
            B.push_back(s);
        }
    return B;
}
