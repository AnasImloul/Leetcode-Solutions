						**	#Vote if u like ❤️**
							
	class Solution {
	public:
		void fun(TreeNode *root , int l , map<int , vector<int>> &m)
		{
			if(root == NULL) return; //If root is NULL it will return 
			m[l].push_back(root -> val); //With level as key inserting the value to the vector
			fun(root -> left, l + 1, m); // passing the left with level + 1 
			fun(root -> right, l + 1 , m); // passing right with level + 1
		}
		int deepestLeavesSum(TreeNode* root) {
			map<int , vector<int>> m;  // Map with key as level and value of vector for storing the values
			fun(root , 0 , m); // A void fun with map and level as 0
		   auto itr = m.rbegin(); //Hence we need the leaves node the nodes are present in last level 
			int sum = 0; // Sum Variable 
			for(int i = 0; i < itr-> second.size(); i++) {sum += itr -> second[i];}
			return sum;
		}
	};
	
														-Yash:)