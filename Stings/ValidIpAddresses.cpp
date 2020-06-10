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
