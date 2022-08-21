<h3 align="left"> 1319. Number of Operations to Make Network Connected</h3>
<div><p>There are <code>n</code> computers numbered from <code>0</code> to <code>n - 1</code> connected by ethernet cables <code>connections</code> forming a network where <code>connections[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> represents a connection between computers <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code>. Any computer can reach any other computer directly or indirectly through the network.</p>

<p>You are given an initial computer network <code>connections</code>. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.</p>

<p>Return <em>the minimum number of times you need to do this in order to make all the computers connected</em>. If it is not possible, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/01/02/sample_1_1677.png" style="width: 500px; height: 148px;">
<pre><strong>Input:</strong> n = 4, connections = [[0,1],[0,2],[1,2]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> Remove cable between computer 1 and 2 and place between computers 1 and 3.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/01/02/sample_2_1677.png" style="width: 500px; height: 129px;">
<pre><strong>Input:</strong> n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
<strong>Output:</strong> 2
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There are not enough cables.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= connections.length &lt;= min(n * (n - 1) / 2, 10<sup>5</sup>)</code></li>
	<li><code>connections[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>There are no repeated connections.</li>
	<li>No two computers are connected by more than one cable.</li>
</ul>
</div>