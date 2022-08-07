class Solution {
public:
    typedef vector<int>::iterator vecIt;
    TreeNode* buildTree(vector<int>& listToVec, vecIt start, vecIt end)
    {
        if (start >= end)
            return NULL;
        vecIt midIt = start + (end - start) / 2;
        TreeNode* newNode = new TreeNode(*midIt);
        newNode->left = buildTree(listToVec, start, midIt);
        newNode->right = buildTree(listToVec, midIt + 1, end);
        return (newNode);
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> listToVec;
        while (head)
        {
            listToVec.push_back(head->val);
            head = head->next;
        }
        return (buildTree(listToVec, listToVec.begin(), listToVec.end()));
    }
};