
class Solution {
public:
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot,bool checkDirect=false) {
        if(subRoot==NULL and root==NULL) return true;
        if(subRoot==NULL or root==NULL) return false;
        
        if(checkDirect){
            
            if(root->val==subRoot->val){
                // if current Element is matches then check for left and right subtrees separately
                return (isSubtree(root->left,subRoot->left,true) and isSubtree(root->right,subRoot->right,true));
            }else{
                //If some prev elements are matched but current element is not matched
                return false;
            }
            
        }else{
           if(root->val==subRoot->val){
               // if previous elements are not matched but current element is matched
               // then find answers for left,right separately along with simulatneously
               return (isSubtree(root->left,subRoot->left,true) and isSubtree(root->right,subRoot->right,true)) or isSubtree(root->left,subRoot,false) or isSubtree(root->right,subRoot,false);
           }else{
               // else check for only left and right subtrees
               
               return isSubtree(root->left,subRoot,false) or isSubtree(root->right,subRoot,false);
           }
        }
        
    }
};