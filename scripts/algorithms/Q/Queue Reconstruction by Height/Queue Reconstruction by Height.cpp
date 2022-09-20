// Runtime: 33 ms (Top 97.97%) | Memory: 12 MB (Top 60.85%)
#include <bits/stdc++.h>

using namespace std;
struct node {
  int h, k;
  node *next;
  node(int h, int k) : h(h), k(k), next(nullptr){}
};

bool cmp(vector<int>& p1, vector<int>& p2) {
  return (p1[0] != p2[0]) ? (p1[0] > p2[0]) : (p1[1] < p2[1]);
}

void insert(vector<int>& p, node **target) {
  node *new_p = new node(p[0], p[1]);
  new_p->next = (*target)->next;
  (*target)->next = new_p;
}

class Solution {
  public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
      sort(people.begin(), people.end(), cmp);
      vector<int>& first = people[0];
      node *head = new node(0, 0);//pseu
      node **target;
      int step;
      for (int i = 0; i < people.size(); i++) {
        vector<int>& p = people[i];
        for (target = &head, step=p[1]; step > 0; target=&((*target)->next), step--);
        insert(p, target);
      }
      vector<vector<int>> ans;
      ans.resize(people.size());
      int i = 0;
      for(node *cur = head->next; cur != nullptr; cur = cur->next)
        ans[i++] = vector<int>({cur->h, cur->k});
      //formally, we should free the list later.
      return ans;
    }
};