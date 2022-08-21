<h3 align="left"> 1840. Maximum Building Height</h3>
<div><p>You want to build <code>n</code> new buildings in a city. The new buildings will be built in a line and are labeled from <code>1</code> to <code>n</code>.</p>

<p>However, there are city restrictions on the heights of the new buildings:</p>

<ul>
	<li>The height of each building must be a non-negative integer.</li>
	<li>The height of the first building <strong>must</strong> be <code>0</code>.</li>
	<li>The height difference between any two adjacent buildings <strong>cannot exceed</strong> <code>1</code>.</li>
</ul>

<p>Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array <code>restrictions</code> where <code>restrictions[i] = [id<sub>i</sub>, maxHeight<sub>i</sub>]</code> indicates that building <code>id<sub>i</sub></code> must have a height <strong>less than or equal to</strong> <code>maxHeight<sub>i</sub></code>.</p>

<p>It is guaranteed that each building will appear <strong>at most once</strong> in <code>restrictions</code>, and building <code>1</code> will <strong>not</strong> be in <code>restrictions</code>.</p>

<p>Return <em>the <strong>maximum possible height</strong> of the <strong>tallest</strong> building</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/ic236-q4-ex1-1.png" style="width: 400px; height: 253px;">
<pre><strong>Input:</strong> n = 5, restrictions = [[2,1],[4,1]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The green area in the image indicates the maximum allowed height for each building.
We can build the buildings with heights [0,1,2,1,2], and the tallest building has a height of 2.</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/ic236-q4-ex2.png" style="width: 500px; height: 269px;">
<pre><strong>Input:</strong> n = 6, restrictions = []
<strong>Output:</strong> 5
<strong>Explanation:</strong> The green area in the image indicates the maximum allowed height for each building.
We can build the buildings with heights [0,1,2,3,4,5], and the tallest building has a height of 5.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/ic236-q4-ex3.png" style="width: 500px; height: 187px;">
<pre><strong>Input:</strong> n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The green area in the image indicates the maximum allowed height for each building.
We can build the buildings with heights [0,1,2,3,3,4,4,5,4,3], and the tallest building has a height of 5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= restrictions.length &lt;= min(n - 1, 10<sup>5</sup>)</code></li>
	<li><code>2 &lt;= id<sub>i</sub> &lt;= n</code></li>
	<li><code>id<sub>i</sub></code>&nbsp;is <strong>unique</strong>.</li>
	<li><code>0 &lt;= maxHeight<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>
</div>