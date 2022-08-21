<h3 align="left"> 2249. Count Lattice Points Inside a Circle</h3>
<div><p>Given a 2D integer array <code>circles</code> where <code>circles[i] = [x<sub>i</sub>, y<sub>i</sub>, r<sub>i</sub>]</code> represents the center <code>(x<sub>i</sub>, y<sub>i</sub>)</code> and radius <code>r<sub>i</sub></code> of the <code>i<sup>th</sup></code> circle drawn on a grid, return <em>the <strong>number of lattice points</strong> </em><em>that are present inside <strong>at least one</strong> circle</em>.</p>

<p><strong>Note:</strong></p>

<ul>
	<li>A <strong>lattice point</strong> is a point with integer coordinates.</li>
	<li>Points that lie <strong>on the circumference of a circle</strong> are also considered to be inside it.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/02/exa-11.png" style="width: 300px; height: 300px;">
<pre><strong>Input:</strong> circles = [[2,2,1]]
<strong>Output:</strong> 5
<strong>Explanation:</strong>
The figure above shows the given circle.
The lattice points present inside the circle are (1, 2), (2, 1), (2, 2), (2, 3), and (3, 2) and are shown in green.
Other points such as (1, 1) and (1, 3), which are shown in red, are not considered inside the circle.
Hence, the number of lattice points present inside at least one circle is 5.</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/02/exa-22.png" style="width: 300px; height: 300px;">
<pre><strong>Input:</strong> circles = [[2,2,2],[3,4,1]]
<strong>Output:</strong> 16
<strong>Explanation:</strong>
The figure above shows the given circles.
There are exactly 16 lattice points which are present inside at least one circle. 
Some of them are (0, 2), (2, 0), (2, 4), (3, 2), and (4, 4).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= circles.length &lt;= 200</code></li>
	<li><code>circles[i].length == 3</code></li>
	<li><code>1 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 100</code></li>
	<li><code>1 &lt;= r<sub>i</sub> &lt;= min(x<sub>i</sub>, y<sub>i</sub>)</code></li>
</ul>
</div>