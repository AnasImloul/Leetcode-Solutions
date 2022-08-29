// Runtime: 34 ms (Top 56.25%) | Memory: 16.3 MB (Top 48.44%)
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1->isLeaf && quadTree2->isLeaf) {
            return new Node(quadTree1->val || quadTree2->val, true);
        }
        if (quadTree1->isLeaf) {
            if (quadTree1->val) return quadTree1;
            return quadTree2;
        }
        if (quadTree2->isLeaf) {
            if (quadTree2->val) return quadTree2;
            return quadTree1;
        }

        Node *topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node *topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        Node *bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node *bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);

        Node *newnode = new Node();

        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && topLeft->val == topRight->val && bottomLeft->val == bottomRight->val && topLeft->val == bottomRight->val) {
            newnode->isLeaf = true;
            newnode->val = topLeft->val;
        } else {
            newnode->topLeft = topLeft;
            newnode->topRight = topRight;
            newnode->bottomLeft = bottomLeft;
            newnode->bottomRight = bottomRight;
        }

        return newnode;
    }
};