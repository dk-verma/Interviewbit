/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
void Solution::connect(TreeLinkNode* A) 
{
    if(!A)
      return;
    
    queue<TreeLinkNode*>q1;
    TreeLinkNode * temp;
    q1.push(A);
    int size;
    
    while(!q1.empty())
    {
        size=q1.size();
        while(size>0)
        {
            temp = q1.front();
            q1.pop();
            
            if(temp->left)
              q1.push(temp->left);
            
            if(temp->right)
              q1.push(temp->right);
              
            if(size>1)
              temp->next = q1.front();
            else
              temp->next = NULL;
            
            size--;
        }
    }
 
    free(temp);
    return;
}
