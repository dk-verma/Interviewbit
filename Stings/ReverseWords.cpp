/*
Input 1:
    A = "the sky is blue"
Output 1:
    "blue is sky the"
*/

void Solution::reverseWords(string &A) 
{
    stringstream str(A);
    A.clear();
    string temp;
    
    if(str>>temp)
    {  
       A=temp;
       temp.clear();
    }
    while(str>>temp)
    {  
       temp+=" ";
       A=temp+A;
       temp.clear();
    }
    A+="\0";
}
