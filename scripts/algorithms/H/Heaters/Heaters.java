// Runtime: 15 ms (Top 66.0%) | Memory: 46.54 MB (Top 44.7%)

class Solution {
  public boolean can(int r, int[] houses, int[] heaters) {
    int prevHouseIdx = -1;
    for(int i = 0; i < heaters.length; i++) {
      int from = heaters[i]-r;
      int to   = heaters[i]+r;
      for(int j = prevHouseIdx+1; j < houses.length; j++){
        if(houses[j]<=to && houses[j]>=from){
          prevHouseIdx++;
        }
        else break;
      }
      if(prevHouseIdx >= houses.length-1)return true;
    }
    return prevHouseIdx>= houses.length-1;
  }
  public int findRadius(int[] houses, int[] heaters) {
    Arrays.sort(houses);
    Arrays.sort(heaters);
    int lo = 0, hi = 1000000004;
    int mid, ans = hi;
    while(lo <= hi) {
      mid = (lo+hi)/2;
      if(can(mid, houses, heaters)){
        ans = mid;
        hi = mid - 1;
      } else lo = mid + 1;
    }
    return ans;
  }
}