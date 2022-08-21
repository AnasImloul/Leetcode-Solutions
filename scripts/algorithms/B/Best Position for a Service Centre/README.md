<h3 align="left"> 1515. Best Position for a Service Centre</h3>
<div><p>A delivery company wants to build a new service center in a new city. The company knows the positions of all the customers in this city on a 2D-Map and wants to build the new center in a position such that <strong>the sum of the euclidean distances to all customers is minimum</strong>.</p>

<p>Given an array <code>positions</code> where <code>positions[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> is the position of the <code>ith</code> customer on the map, return <em>the minimum sum of the euclidean distances</em> to all customers.</p>

<p>In other words, you need to choose the position of the service center <code>[x<sub>centre</sub>, y<sub>centre</sub>]</code> such that the following formula is minimized:</p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/25/q4_edited.jpg">
<p>Answers within <code>10<sup>-5</sup></code> of the actual value will be accepted.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/25/q4_e1.jpg" style="width: 377px; height: 362px;">
<pre><strong>Input:</strong> positions = [[0,1],[1,0],[1,2],[2,1]]
<strong>Output:</strong> 4.00000
<strong>Explanation:</strong> As shown, you can see that choosing [x<sub>centre</sub>, y<sub>centre</sub>] = [1, 1] will make the distance to each customer = 1, the sum of all distances is 4 which is the minimum possible we can achieve.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/25/q4_e3.jpg" style="width: 419px; height: 419px;">
<pre><strong>Input:</strong> positions = [[1,1],[3,3]]
<strong>Output:</strong> 2.82843
<strong>Explanation:</strong> The minimum possible sum of distances = sqrt(2) + sqrt(2) = 2.82843
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= positions.length &lt;= 50</code></li>
	<li><code>positions[i].length == 2</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 100</code></li>
</ul>
</div>