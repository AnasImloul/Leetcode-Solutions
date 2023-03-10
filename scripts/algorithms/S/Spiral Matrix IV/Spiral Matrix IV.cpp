
class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) 
    {
		// Create a matrix of n x m with values filled with -1.
        vector<vector<int>> spiral(n, vector<int>(m, -1));
        int i = 0, j = 0;
		// Traverse the matrix in spiral form, and update with the values present in the head list.
		// If head reacher NULL pointer break out from the loop, and return the spiral matrix.
        while (head != NULL)
        {
            if (j < m)
            {
                while (head != NULL && j < m && spiral[i][j] == -1)
                {
                    spiral[i][j] = head->val;
                    head = head->next;
                    j++;
                }
                if (head == NULL)
                    break;
                i++;
                j--;
            }
            if (i < n)
            {
                while (head != NULL && i < n && spiral[i][j] == -1)
                {
                    spiral[i][j] = head->val;
                    head = head->next;
                    i++;
                }
                i--;
                j--;
            }
            if (j >= 0)
            {
                while (head != NULL && j >= 0 && spiral[i][j] == -1)
                {
                    spiral[i][j] = head->val;
                    head = head->next;
                    j--;
                }
                j++;
                i--;
            }
            if (i >= 0)
            {
                while (head != NULL && i >= 0 && spiral[i][j] == -1)
                {
                    spiral[i][j] = head->val;
                    head = head->next;
                    i--;
                }
                i++;
                j++;
            }
            n--;
            m++;
        }
		// Rest values are itself -1.
        return spiral;
    }
};