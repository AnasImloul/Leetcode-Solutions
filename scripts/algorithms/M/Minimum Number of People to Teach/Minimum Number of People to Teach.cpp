// Runtime: 310 ms (Top 93.88%) | Memory: 61.5 MB (Top 78.57%)
class Solution {
public:
    bool checkinvalid( int a, int b, vector<vector<int>>& languages){ //helper func., checks if a and b can communicate or not
        a--; b--;
        for( int i=0;i<languages[a].size();i++){
            if(find(languages[b].begin(), languages[b].end(), languages[a][i]) != languages[b].end()) return false;
        }
        return true;
    }

    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m= languages.size();
        vector<vector<int>> g(m+1, vector<int>(0)); // graph to store adjacency list with people as nodes & friendships as edges
        // create graph
        for( int i=0;i<friendships.size();i++){
            g[friendships[i][0]].push_back(friendships[i][1]);
            g[friendships[i][1]].push_back(friendships[i][0]);
        }

        vector<int> voters(m+1,0); // to store people who cant communicate with atleast a friend
        int voterscount=0;
        for( int i=1;i<m+1;i++){
             for( int j=0;j<g[i].size();j++){
                if( checkinvalid(i, g[i][j], languages)){ // ith can vote
                    voters[i]=1;
                    voterscount++;
                    break;
                }
            }
        }
        unordered_map<int,int> mappy; // language -> votes
        int maxvotes=0;

        for( int i=1;i<m+1;i++){
            if(voters[i]==1){
                for( int j: languages[i-1]){
                    mappy[j]++;

                    if(maxvotes<mappy[j]){
                        maxvotes= mappy[j];
                    }
                }
            }
        }
        return voterscount - maxvotes; // # who need to be taught the language
    }
};