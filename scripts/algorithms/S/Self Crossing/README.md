<h3 align="left"> 335. Self Crossing</h3>
<div><p>You are given an array of integers <code>distance</code>.</p>

<p>You start at point <code>(0,0)</code> on an <strong>X-Y</strong> plane and you move <code>distance[0]</code> meters to the north, then <code>distance[1]</code> meters to the west, <code>distance[2]</code> meters to the south, <code>distance[3]</code> meters to the east, and so on. In other words, after each move, your direction changes counter-clockwise.</p>

<p>Return <code>true</code> if your path crosses itself, and <code>false</code> if it does not.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/selfcross1-plane.jpg" style="width: 400px; height: 435px;">
<pre><strong>Input:</strong> distance = [2,1,1,2]
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/selfcross2-plane.jpg" style="width: 400px; height: 435px;">
<pre><strong>Input:</strong> distance = [1,2,3,4]
<strong>Output:</strong> false
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/selfcross3-plane.jpg" style="width: 400px; height: 435px;">
<pre><strong>Input:</strong> distance = [1,1,1,1]
<strong>Output:</strong> true
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;distance.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;=&nbsp;distance[i] &lt;= 10<sup>5</sup></code></li>
</ul>
</div>