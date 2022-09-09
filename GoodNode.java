/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class GoodNode {
    public int goodNodes(TreeNode root) 
    {
        TreeNode stack[] = new TreeNode[45];
        int levelStack[] = new int[45];
        int path[] = new int[45];
        TreeNode temp = root;
        int k = -1, t = -1, count = 0, flag = 0;
        while(temp != null)
        {
            path[++t] = temp.val;
            
            for(int i = t-1; i >= 0; i--)                 // validating the path from root to leaf with criteria
                    if(path[i] > path[t])
                        flag = 1;                         // flag is 1 if criteria is violated
                
                if(flag == 0 && t >= 0)                    // incr. count if criteria is met else reseting flag.
                     ++count;
                else
                    flag = 0;
            
            
            //System.out.format("count = %d, temp.val = %d\n", count, temp.val);  //Debug
            
            
            if(temp.left == null && temp.right == null)   // temp is pointing to leaf node
            {                  
                if(k == -1)                               // Condition: Entire tree is traversed if yes then exit
                    break;
                else
                {
                    temp = stack[k];                      // temp points to last node pushed to stack - preorder
                    t = levelStack[k--];                  // path index is set to corresponding level of tree.
                }
            }
            else if(temp.left != null)                    // Check: existence of left node.
            {
                if(temp.right != null)                    // Push: Right node to stack if exists
                {
                    stack[++k] = temp.right;
                    levelStack[k] = t;
                }
                
                temp = temp.left;                         // temp points to left node.
            }
            else if(temp.right != null)                   // Point to right node if left doesn't exists.
                temp = temp.right;
            
                
        }
        
        
        return count;
    }
}
