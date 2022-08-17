class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
      vector<string>vc;
      unordered_map<string,int>umap,umap1;
      
      for(int i=0;i<list1.size();i++)
      {
        
        
        umap[list1[i]]=i;
        
      }
      

      for(int i=0;i<list2.size();i++)
      {
        
        
        umap1[list2[i]]=i;
        
      }
      int min=10000;
for(auto i:umap)
{
  int k=0;
  for(auto j :umap1)
  {
    
    if(i.first==j.first)
    {
      k=i.second+j.second;
      if(min>k)
      {vc.clear();
        min=k;
       vc.push_back(j.first);
      }
      else if(k==min)
      {
        vc.push_back(j.first);
      }
        
    }
  }
}
  
  
  return vc;
}
};
