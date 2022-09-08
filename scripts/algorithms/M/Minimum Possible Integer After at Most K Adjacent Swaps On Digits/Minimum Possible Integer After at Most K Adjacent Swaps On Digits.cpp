// Runtime: 107 ms (Top 58.06%) | Memory: 12.5 MB (Top 32.26%)
/*
    Time: O(nlogn)
    Space: O(n)
    Tag: Segment Tree, Greedy (put the possible feasible smallest index in place of cur index), Queue
    Difficulty: H (Both Logic and Implementation)
*/

class SegmentTree {
    vector<int> tree;

public:
    SegmentTree(int size) {
        tree.resize(4 * size + 1, 0);
    }

    void printTree() {
        for (int num : tree) cout << num << "";
        cout << endl;
    }

    void updateTree(int lo, int hi, int index, int upd) {
        if (upd < lo || upd > hi) return;
        if (lo == hi) {
            tree[index]++;
            return;
        }
        int mid = lo + (hi - lo) / 2;
        updateTree(lo, mid, 2 * index, upd);
        updateTree(mid + 1, hi, 2 * index + 1, upd);
        tree[index] = tree[2 * index] + tree[2 * index + 1];
    }

    int queryTree(int lo, int hi, int index, int qs, int qe) {
        if (qe < lo || qs > hi) return 0;
        if (qe >= hi && qs <= lo) return tree[index];

        int mid = lo + (hi - lo) / 2;

        int left = queryTree(lo, mid, 2 * index, qs, qe);
        int right = queryTree(mid + 1, hi, 2 * index + 1, qs, qe);
        return left + right;
    }
};

class Solution {
public:
    string minInteger(string num, int k) {
        queue<int> pos[10];
        for (int i = 0; i < num.length(); i++) {
            pos[num[i] - '0'].push(i);
        }
        string res = "";
        SegmentTree *seg = new SegmentTree((int)num.length());
        for (int i = 0; i < num.length(); i++) {
            if (num[i] == '-') continue;
            int digit = num[i] - '0';

            bool swapped = false;
            for (int j = 0; j < digit; j++) {
                if (pos[j].size() > 0) {
                    int curNumIndex = pos[j].front();
                    int shifts = seg->queryTree(0, num.length() - 1, 1, i, pos[j].front());

                    if (curNumIndex - i - shifts <= k) {
                        seg->updateTree(0, num.length() - 1, 1, curNumIndex);
                        k -= curNumIndex - i - shifts;
                        pos[j].pop();
                        res += num[curNumIndex];
                        num[curNumIndex] = '-';
                        swapped = true;
                        i--;
                        break;
                    }
                }
            }
            if (!swapped) {
                res += num[i];
                pos[digit].pop();
            }
        }
        return res;
    }
};