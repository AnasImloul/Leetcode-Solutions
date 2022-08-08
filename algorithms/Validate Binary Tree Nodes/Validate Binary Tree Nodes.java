import java.util.Arrays;

class Solution {
  static class UF {
    int[] parents;
    int size;
    UF(int n) {
      parents = new int[n];
      size = n;
      Arrays.fill(parents, -1);
    }
    
    int find(int x) {
      if (parents[x] == -1) {
        return x;
      }
      return parents[x] = find(parents[x]);
    }

    boolean union(int a, int b) {
      int pA = find(a), pB = find(b);
      if (pA == pB) {
        return false;
      }
      parents[pA] = pB;
      size--;
      return true;
    }

    boolean connected() {
      return size == 1;
    }
  }
  public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
    UF uf = new UF(n);
    int[] indeg = new int[n];
    for (int i = 0; i < n; i++) {
      int l = leftChild[i], r = rightChild[i];
      if (l != -1) {
        /**
         * i: parent node
         * l: left child node
         * if i and l are already connected or the in degree of l is already 1
         */
        if (!uf.union(i, l) || ++indeg[l] > 1) {
          return false;
        }
      }
      if (r != -1) {
        // Same thing for parent node and the right child node
        if (!uf.union(i, r) || ++indeg[r] > 1) {
          return false;
        }
      }
    }
    return uf.connected();
  }
}
