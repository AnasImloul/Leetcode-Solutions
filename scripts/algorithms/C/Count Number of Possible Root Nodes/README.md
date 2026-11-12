<h3 align="left"> 2581. Count Number of Possible Root Nodes</h3>
<div><p>Alice has an undirected tree with <code>n</code> nodes labeled from <code>0</code> to <code>n - 1</code>. The tree is represented as a 2D integer array <code>edges</code> of length <code>n - 1</code> where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is an edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> in the tree.</p>

<p>Alice wants Bob to find the root of the tree. She allows Bob to make several <strong>guesses</strong> about her tree. In one guess, he does the following:</p>

<ul>
	<li>Chooses two <strong>distinct</strong> integers <code>u</code> and <code>v</code> such that there exists an edge <code>[u, v]</code> in the tree.</li>
	<li>He tells Alice that <code>u</code> is the <strong>parent</strong> of <code>v</code> in the tree.</li>
</ul>

<p>Bob&#39;s guesses are represented by a 2D integer array <code>guesses</code> where <code>guesses[j] = [u<sub>j</sub>, v<sub>j</sub>]</code> indicates Bob guessed <code>u<sub>j</sub></code> to be the parent of <code>v<sub>j</sub></code>.</p>

<p>Alice being lazy, does not reply to each of Bob&#39;s guesses, but just says that <strong>at least</strong> <code>k</code> of his guesses are <code>true</code>.</p>

<p>Given the 2D integer arrays <code>edges</code>, <code>guesses</code> and the integer <code>k</code>, return <em>the <strong>number of possible nodes</strong> that can be the root of Alice&#39;s tree</em>. If there is no such tree, return <code>0</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/12/19/ex-1.png" style="width: 727px; height: 250px;" /></p>

<pre>
<strong>Input:</strong> edges = [[0,1],[1,2],[1,3],[4,2]], guesses = [[1,3],[0,1],[1,0],[2,4]], k = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
Root = 0, correct guesses = [1,3], [0,1], [2,4]
Root = 1, correct guesses = [1,3], [1,0], [2,4]
Root = 2, correct guesses = [1,3], [1,0], [2,4]
Root = 3, correct guesses = [1,0], [2,4]
Root = 4, correct guesses = [1,3], [1,0]
Considering 0, 1, or 2 as root node leads to 3 correct guesses.

</pre>

<p><strong class="example">Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/12/19/ex-2.png" style="width: 600px; height: 303px;" /></p>

<pre>
<strong>Input:</strong> edges = [[0,1],[1,2],[2,3],[3,4]], guesses = [[1,0],[3,4],[2,1],[3,2]], k = 1
<strong>Output:</strong> 5
<strong>Explanation:</strong> 
Root = 0, correct guesses = [3,4]
Root = 1, correct guesses = [1,0], [3,4]
Root = 2, correct guesses = [1,0], [2,1], [3,4]
Root = 3, correct guesses = [1,0], [2,1], [3,2], [3,4]
Root = 4, correct guesses = [1,0], [2,1], [3,2]
Considering any node as root will give at least 1 correct guess. 

</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>edges.length == n - 1</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= guesses.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub>, u<sub>j</sub>, v<sub>j</sub> &lt;= n - 1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>u<sub>j</sub> != v<sub>j</sub></code></li>
	<li><code>edges</code> represents a valid tree.</li>
	<li><code>guesses[j]</code> is an edge of the tree.</li>
	<li><code>guesses</code> is unique.</li>
	<li><code>0 &lt;= k &lt;= guesses.length</code></li>
</ul>
</div>
