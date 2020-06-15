/*
Input 1:
    A = "{A:"B",C:{D:"E",F:{G:"H",I:"J"}}}"
Output 1:
    { 
        A:"B",
        C: 
        { 
            D:"E",
            F: 
            { 
                G:"H",
                I:"J"
            } 
        } 
    }
*/

vector<string> Solution::prettyJSON(string A) 
{
    int i,start=0,space=0;
    vector<string>ans;
    string temp;
    
    for(i=0;i<A.length();i++)
    {
        if(A[i]!='{' && A[i]!='[' && A[i]!='}' && A[i]!=']' & A[i]!=',')
          continue;
        
        if(A[i]==',')
        {
            temp=string(space,'\t')+A.substr(start,i-start+1);
            ans.push_back(temp);
            temp.clear();
            start=i+1;
            continue;
        }
                
        if(start!=i)                      // old string like 'sdvs[' or 'asdas}'
        {
            temp=string(space,'\t')+A.substr(start,i-start);
            ans.push_back(temp);
            temp.clear();
        }
           
        if(A[i]=='{' || A[i]=='[')               //opening bracket '{' || '['
        {
            temp=string(space,'\t')+A[i];
            space+=1;
        }
        else                                     //closing bracket '}' || ']'
        {
            space-=1;
            temp=string(space,'\t')+A[i];
            if(A[i+1]==',')                      // }, || ],
                temp+=A[++i];
        }
        
        ans.push_back(temp);
        temp.clear();
        start=i+1;
    }
    return ans;
}
