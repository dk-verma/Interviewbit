/*
There are two sorted arrays A and B of size m and n respectively.
Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).
The overall run time complexity should be O(log (m+n)).
- Sample Input
A : [1 4 5]
B : [2 3]
- Sample Output
3
*/

double Solution::findMedianSortedArrays(const vector<int> &a, const vector<int> &b) 
{
    int n1 = a.size(), n2 = b.size();
    if(n1 > n2)
        return findMedianSortedArrays(b, a);  // time complexity = O(log(min(n1,n2)
    int start = 0, end = n1;
    while(start <= end)
    {
      int partX = (start+end)/2;
      int leftX = partX == 0 ? INT_MIN: a[partX-1];
      int rightX = partX == n1 ? INT_MAX: a[partX];
    
      int partY = (n1 + n2 + 1)/2 - partX;
      int leftY = partY == 0 ? INT_MIN: b[partY-1];
      int rightY = partY == n2 ? INT_MAX: b[partY];
        
      if(leftX <= rightY && leftY <= rightX)
      {
          if((n1+n2)&1)
              return double(max(leftX, leftY));
          else 
              return double( max(leftX, leftY) + min(rightX, rightY) )*(0.5);
      }
      else if(leftX > rightY)
          end = partX-1;
      else 
          start = partX+1;
    }
    return 0.0;
}
