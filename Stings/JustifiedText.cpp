//  Example:
//  I/P - words: ["This", "is", "an", "example", "of", "text", "justification."]
//        L: 16
//  O/P - Return the formatted lines as:
//      [
//      "This    is    an",
//      "example  of text",
//      "justification.  "
//      ]

vector<string> Solution::fullJustify(vector<string> &words, int L) 
{
    vector<string> res;
    int l = 0, i=0, j, start;
    while(i < words.size() ) 
    { 
      l=0, start=i;
      while( i<words.size() && l+i-start+words[i].size()<=L ) 
          l += words[i++].size();
    
      string temp = words[start];
      int space_left = L-l, space_count = i-start-1;
      for(j = 0; j < space_count; j++) 
      {
        if(i < words.size())     // space left = L-l, space count = i-start-1
            temp+=string( space_left/space_count + ( j<(space_left%space_count) ), ' ');
        else          //last string 
            temp+=" ";         
        temp += words[start+j+1];
      }
      temp += string(L - temp.size(), ' '); // last string
      res.push_back(temp);
    }
    return res;
}
