// Runtime: 69 ms (Top 94.92%) | Memory: 29.1 MB (Top 88.14%)
class Solution {
    struct Node {
        unique_ptr<Node> left;
        unique_ptr<Node> right;
        int val = 0;

        void insert(int x) {
            if (x < val) {
                if (left) {
                    left->insert(x);
                } else {
                    left = make_unique<Node>();
                    left->val = x;
                }
            } else {
                if (right) {
                    right->insert(x);
                } else {
                    right = make_unique<Node>();
                    right->val = x;
                }
            }
        }

        bool isLeaf() const {
            return !left && !right;
        }
    };

    constexpr static const int ModBase = 1'000'000'007;

    /// the number of ways to interleave two sequences of length x and y respectively.
    /// this feels like very similar to combinations C(x+y, x).
    static int interleaves(int x, int y) {
        static int memo[1001][1001] = {-123};
        if (memo[0][0] == -123) {
            // initialize the memo elements to non-zero,
            // because zero can be a valid value after the modulo op.
            memset(memo, -1, sizeof(memo));
        }
        // todo: or just compute this table bottom-up.
        if (x == 0 || y == 0) {
            return 1;
        }
        if (x > y) {
            swap(x, y);
        }
        if (memo[x][y] != memo[0][0]) {
            return memo[x][y];
        }
        return memo[x][y] = (interleaves(x - 1, y) + interleaves(x, y - 1)) % ModBase;
    }

    /// return a tuple which represents <CountOfNodes, Combinations>
    tuple<int, int> traverseNode(Node* node) {
        if (!node) {
            return {0, 0};
        }
        if (node->isLeaf()) {
            return {1, 1};
        }
        if (node->left) {
            auto [leftNodeCount, leftCombos] = traverseNode(node->left.get());
            if (node->right) {
                auto [rightNodeCount, rightCombos] = traverseNode(node->right.get());
                int totalCombos = ((int64_t)leftCombos * rightCombos) % ModBase;
                totalCombos = ((int64_t)totalCombos * interleaves(leftNodeCount, rightNodeCount))
                        % ModBase;
                return {1 + leftNodeCount + rightNodeCount, totalCombos};
            } else { // right side is empty
                return {1 + leftNodeCount, leftCombos};
            }
        } else { // left side is empty, but it must have the right side, because it's not a leaf.
            auto [rightNodeCount, rightCombos] = traverseNode(node->right.get());
            return {1 + rightNodeCount, rightCombos};
        }
    }

public:
    int numOfWays(vector<int>& nums) {
        // create the BST.
        auto root = make_unique<Node>();
        root->val = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            root->insert(nums[i]);
        }

        auto [nodeCount, combos] = traverseNode(root.get());
        return combos - 1;
    }
};