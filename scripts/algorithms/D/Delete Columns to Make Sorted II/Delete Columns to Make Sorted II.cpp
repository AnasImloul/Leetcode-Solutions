// Runtime: 12 ms (Top 58.21%) | Memory: 10.9 MB (Top 12.31%)
// in this i have iterated for every column and then for every string
// i have used array arr[101] in order to store wich indices are valid and which are not
// i have taken an array of positions(vector) done[101] to find at which previous locations i found this particular (jth index string ) to be smaller than its successor

class Solution {
public:
     int arr[101]={0}; // arr is to check which columns are valid(0) and invalid(-1)
    vector<int> done[101]; // where u found string j was greater than string j+1 ,u put it into vector

 // below is a helper function in order to check all the locations (at which string j has been classified as done ) are still present or not
    bool check(vector<int>& a){
      for(int i:a){
          if(arr[i]!=-1){
              return 1;
          }
      }
        return 0;
    }
int minDeletionSize(vector<string>& strs) {

        int ans=0;
// for iterating columns
     for(int i=0;i<strs[0].size();i++){
   // for iterating the strings
         for(int j=0;j<strs.size()-1;j++){

           if((done[j].size()==0 || check(done[j])==0) && strs[j][i]>strs[j+1][i]){

                ans++;
               arr[i]=-1; // make the column invalid
                break;
            }
             if(strs[j][i]<strs[j+1][i]){

                 done[j].push_back(i); // here we are storing at which index (i) said string j is ok
             }
         }

     }

        return ans;
    }

};