<h3 align="left"> 2280. Minimum Lines to Represent a Line Chart</h3>
<div><p>You are given a 2D integer array <code>stockPrices</code> where <code>stockPrices[i] = [day<sub>i</sub>, price<sub>i</sub>]</code> indicates the price of the stock on day <code>day<sub>i</sub></code> is <code>price<sub>i</sub></code>. A <strong>line chart</strong> is created from the array by plotting the points on an XY plane with the X-axis representing the day and the Y-axis representing the price and connecting adjacent points. One such example is shown below:</p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/30/1920px-pushkin_population_historysvg.png" style="width: 500px; height: 313px;">
<p>Return <em>the <strong>minimum number of lines</strong> needed to represent the line chart</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/30/ex0.png" style="width: 400px; height: 400px;">
<pre><strong>Input:</strong> stockPrices = [[1,7],[2,6],[3,5],[4,4],[5,4],[6,3],[7,2],[8,1]]
<strong>Output:</strong> 3
<strong>Explanation:</strong>
The diagram above represents the input, with the X-axis representing the day and Y-axis representing the price.
The following 3 lines can be drawn to represent the line chart:
- Line 1 (in red) from (1,7) to (4,4) passing through (1,7), (2,6), (3,5), and (4,4).
- Line 2 (in blue) from (4,4) to (5,4).
- Line 3 (in green) from (5,4) to (8,1) passing through (5,4), (6,3), (7,2), and (8,1).
It can be shown that it is not possible to represent the line chart using less than 3 lines.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/30/ex1.png" style="width: 325px; height: 325px;">
<pre><strong>Input:</strong> stockPrices = [[3,4],[1,2],[7,8],[2,3]]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
As shown in the diagram above, the line chart can be represented with a single line.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= stockPrices.length &lt;= 10<sup>5</sup></code></li>
	<li><code>stockPrices[i].length == 2</code></li>
	<li><code>1 &lt;= day<sub>i</sub>, price<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li>All <code>day<sub>i</sub></code> are <strong>distinct</strong>.</li>
</ul>
</div>