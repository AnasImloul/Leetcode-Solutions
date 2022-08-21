<h3 align="left"> 2242. Maximum Score of a Node Sequence</h3>
<div><p>There is an <strong>undirected</strong> graph with <code>n</code> nodes, numbered from <code>0</code> to <code>n - 1</code>.</p>

<p>You are given a <strong>0-indexed</strong> integer array <code>scores</code> of length <code>n</code> where <code>scores[i]</code> denotes the score of node <code>i</code>. You are also given a 2D integer array <code>edges</code> where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> denotes that there exists an <strong>undirected</strong> edge connecting nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code>.</p>

<p>A node sequence is <b>valid</b> if it meets the following conditions:</p>

<ul>
	<li>There is an edge connecting every pair of <strong>adjacent</strong> nodes in the sequence.</li>
	<li>No node appears more than once in the sequence.</li>
</ul>

<p>The score of a node sequence is defined as the <strong>sum</strong> of the scores of the nodes in the sequence.</p>

<p>Return <em>the <strong>maximum score</strong> of a valid node sequence with a length of </em><code>4</code><em>. </em>If no such sequence exists, return<em> </em><code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/04/15/ex1new3.png" style="width: 290px; height: 215px;">
<pre><strong>Input:</strong> scores = [5,2,9,8,4], edges = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
<strong>Output:</strong> 24
<strong>Explanation:</strong> The figure above shows the graph and the chosen node sequence [0,1,2,3].
The score of the node sequence is 5 + 2 + 9 + 8 = 24.
It can be shown that no other node sequence has a score of more than 24.
Note that the sequences [3,1,2,0] and [1,0,2,3] are also valid and have a score of 24.
The sequence [0,3,2,4] is not valid since no edge connects nodes 0 and 3.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/17/ex2.png" style="width: 333px; height: 151px;">
<pre><strong>Input:</strong> scores = [9,20,6,4,11,12], edges = [[0,3],[5,3],[2,4],[1,3]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> The figure above shows the graph.
There are no valid node sequences of length 4, so we return -1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == scores.length</code></li>
	<li><code>4 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= scores[i] &lt;= 10<sup>8</sup></code></li>
	<li><code>0 &lt;= edges.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>There are no duplicate edges.</li>
</ul>
</div>