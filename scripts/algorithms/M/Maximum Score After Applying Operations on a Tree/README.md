<h3 align="left"> 2925. Maximum Score After Applying Operations on a Tree</h3>
<div><p>There is an undirected tree with <code>n</code> nodes labeled from 0 to <code>n - 1</code>, and rooted at node 0. You are given&nbsp;a 2D integer array <code>edges</code> of length <code>n - 1</code>, where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is an edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> in the tree.</p>

<p>You are also given a <strong>0-indexed</strong> integer array <code>values</code> of length <code>n</code>, where <code>values[i]</code> is the <strong>value</strong> associated with the <code>i<sup>th</sup></code> node.</p>

<p>You start with a score of 0. In one operation, you choose a node <code>i</code>, <strong>add</strong> <code>values[i]</code> to your score, and then <strong>set</strong> <code>values[i]</code> to 0. All three steps happen together as a single operation.</p>

<p>A tree is <strong>healthy</strong> if, for <strong>every</strong> leaf node, the sum of the <strong>current</strong> values on the path from the root to that leaf is <strong>not equal</strong> to 0.</p>

<p>Return the <strong>maximum score</strong> you can obtain by performing this operation on the tree any number of times, so that the tree remains <strong>healthy</strong> at the end.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/10/11/graph-13-1.png" style="width: 515px; height: 443px;" />
<pre>
<strong>Input:</strong> edges = [[0,1],[0,2],[0,3],[2,4],[4,5]], values = [5,2,5,2,1,1]
<strong>Output:</strong> 11
<strong>Explanation:</strong> We apply the operation to nodes 1, 2, 3, 4, and 5, so the values become [5,0,0,0,0,0]. The leaves are nodes 1, 3, and 5.
- The sum of values on the path from 0 to 1 is equal to 5.
- The sum of values on the path from 0 to 3 is equal to 5.
- The sum of values on the path from 0 to 5 is equal to 5.
Every leaf has a non-zero path sum, so the tree is healthy. The score is the sum of the original values of the chosen nodes: 2 + 5 + 2 + 1 + 1 = 11.
It can be shown that 11 is the maximum score obtainable by performing any number of operations on the tree.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/10/11/graph-14-2.png" style="width: 522px; height: 245px;" />
<pre>
<strong>Input:</strong> edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], values = [20,10,9,7,4,3,5]
<strong>Output:</strong> 40
<strong>Explanation:</strong> We apply the operation to nodes 0, 2, 3, and 4, so the values become [0,10,0,0,0,3,5]. The leaves are nodes 3, 4, 5, and 6.
- The sum of values on the path from 0 to 3 is equal to 10.
- The sum of values on the path from 0 to 4 is equal to 10.
- The sum of values on the path from 0 to 5 is equal to 3.
- The sum of values on the path from 0 to 6 is equal to 5.
Every leaf has a non-zero path sum, so the tree is healthy. The score is the sum of the original values of the chosen nodes: 20 + 9 + 7 + 4 = 40.
It can be shown that 40 is the maximum score obtainable by performing any number of operations on the tree.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>values.length == n</code></li>
	<li><code>1 &lt;= values[i] &lt;= 10<sup>9</sup></code></li>
	<li>The input is generated such that <code>edges</code> represents a valid tree.</li>
</ul>
</div>
