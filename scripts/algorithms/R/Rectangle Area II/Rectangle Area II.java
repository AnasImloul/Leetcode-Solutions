class Solution {
      public int rectangleArea(int[][] rectangles) {
          int n = rectangles.length;
          Set<Integer> coorx = new HashSet<>();
          Set<Integer> coory = new HashSet<>();
          for (int[] rec : rectangles) {
              coorx.add(rec[0]); coorx.add(rec[2]);
              coory.add(rec[1]); coory.add(rec[3]);
          }
          
          Integer[] compressx = coorx.toArray(new Integer[0]);
          Arrays.sort(compressx);
          Integer[] compressy = coory.toArray(new Integer[0]);
          Arrays.sort(compressy);
          
          Map<Integer, Integer> mapx = new HashMap<>();
          for(int i = 0; i < compressx.length; i++) {
              mapx.put(compressx[i], i);
          }
          Map<Integer, Integer> mapy = new HashMap<>();
          for(int i = 0; i < compressy.length; i++) {
              mapy.put(compressy[i], i);
          }
          
          boolean[][] grid = new boolean[compressx.length][compressy.length];
          for (int[] rec: rectangles) {
              for (int x = mapx.get(rec[0]); x < mapx.get(rec[2]); x++) {
                  for (int y = mapy.get(rec[1]); y < mapy.get(rec[3]); y++) {
                      grid[x][y] = true;
                  }
              }
          }
          
          long res = 0L;
          for (int i = 0; i < grid.length; i++) {
              for (int j = 0; j < grid[0].length; j++) {
                  if (grid[i][j]) {
                      res += (long)(compressx[i + 1] - compressx[i]) * (compressy[j + 1] - compressy[j]);
                  }
              }
          }
          res %= 1000000007;
          return (int)res;
      }
  }
