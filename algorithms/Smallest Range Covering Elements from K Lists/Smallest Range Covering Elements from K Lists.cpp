class Node{
  public:
    int data;
    int x;
    int y;
    Node(int data,int x,int y){
        this->data=data;
        this->x=x;
        this->y=y;
    }
};

class Comparator{
    public:
    bool operator()(Node *a,Node *b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int>ans;
       //min heap
        int ans_min{},ans_max{};
        priority_queue<Node*,vector<Node*>,Comparator>pq;
        
        int maxi=nums[0][0];
        //storing each list's starting element in pq and checking the max element
        for(int i=0;i<nums.size();i++){
            maxi = maxi>nums[i][0]? maxi : nums[i][0];
            Node *temp=new Node(nums[i][0],i,0);
            pq.push(temp);
        }
        ans_min=pq.top()->data;
        ans_max=maxi;
        int tempMin(ans_min),tempMax(ans_max);
        while(pq.size()==nums.size()){
            Node *temp = pq.top();
            pq.pop();
            int i=temp->x;
            int j=temp->y;
            if(j+1 < nums[i].size()){
                Node *nNode = new Node(nums[i][j+1],i,j+1);
                pq.push(nNode);
                tempMin=pq.top()->data;
                tempMax=tempMax > nums[i][j+1] ? tempMax : nums[i][j+1];
                if(tempMax-tempMin < ans_max-ans_min){
                    ans_min=tempMin;
                    ans_max=tempMax;
                }
            }
        }
        
        ans.push_back(ans_min);
        ans.push_back(ans_max);
        return ans;
    }
};
