// Runtime: 73 ms (Top 21.98%) | Memory: 32.7 MB (Top 81.48%)
class Solution {
public:

    TreeNode *loc;
    TreeNode *par;

    TreeNode *smallestbst(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        TreeNode *next = smallestbst(root->left);
        if (next == NULL)
            return root;
        else if (root->val < next->val)
            return root;
        return next;
    }

    TreeNode *largestbst(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        TreeNode *next = largestbst(root->right);
        if (next == NULL)
            return root;
        else if (root->val > next->val)
            return root;
        return next;
    }

    void searchanodebst(TreeNode *root, int item)
    {
        TreeNode *trav = root;
        TreeNode *trail = NULL;
        while (true)
        {
            if ((trav == NULL) || (trav->val == item))
            {
                if (trav == NULL)
                    loc = NULL;
                break;
            }
            trail = trav;
            if (item < trav->val)
                trav = trav->left;
            else
                trav = trav->right;
        }
        loc = trav;
        par = trail;
    }

    TreeNode *deleteanodebst(TreeNode *root, int item)
    {
        searchanodebst(root, item);
        // cout << " " << loc->val << "-" << par->val << " ";
        if (par == NULL)
        {
            if (root->right == NULL)
                return root->left;
            if (root->left == NULL)
                return root->right;

            TreeNode *tmp = largestbst(root->left);
            tmp->right = root->right;
            tmp = root->left;
            root->left = NULL;
            root->right = NULL;
            return tmp;
        }

        if (loc->left == NULL && loc->right == NULL)
        {
            if (par->right == loc)
                par->right = NULL;
            else
                par->left = NULL;

            return root;
        }

        if (loc->left == NULL)
        {
            if (par->right == loc)
            {
                par->right = loc->right;
                loc->right = NULL;
            }
            else
            {
                par->left = loc->right;
                loc->right = NULL;
            }
            return root;
        }

        if (loc->right == NULL)
        {
            if (par->right == loc)
            {
                par->right = loc->left;
                loc->left = NULL;
            }
            else
            {
                par->left = loc->left;
                loc->left = NULL;
            }
            return root;
        }

        // cout << " DEBUG 01 ";

        if (par->right == loc)
        {
            par->right = loc->left;
            TreeNode *tmp = largestbst(loc->left);
            // cout << " '" << tmp->val << "' ";
            tmp->right = loc->right;
            loc->left = NULL;
            loc->right = NULL;
            return root;
        }

        par->left = loc->left;
        TreeNode *tmp = largestbst(loc->left);
        // cout << " '" << tmp->val << "' ";
        tmp->right = loc->right;
        loc->left = NULL;
        loc->right = NULL;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        while(true)
        {
            loc = NULL;
            par = NULL;
            searchanodebst(root, key);
            if(loc != NULL)
            {
                loc = NULL;
                par = NULL;
                root = deleteanodebst(root, key);
            }
            else
            {
                break;
            }
        }

        return root;
    }
};