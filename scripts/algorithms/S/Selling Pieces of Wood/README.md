<h3 align="left"> 2312. Selling Pieces of Wood</h3>
<div><p>You are given two integers <code>m</code> and <code>n</code> that represent the height and width of a rectangular piece of wood. You are also given a 2D integer array <code>prices</code>, where <code>prices[i] = [h<sub>i</sub>, w<sub>i</sub>, price<sub>i</sub>]</code> indicates you can sell a rectangular piece of wood of height <code>h<sub>i</sub></code> and width <code>w<sub>i</sub></code> for <code>price<sub>i</sub></code> dollars.</p>

<p>To cut a piece of wood, you must make a vertical or horizontal cut across the <strong>entire</strong> height or width of the piece to split it into two smaller pieces. After cutting a piece of wood into some number of smaller pieces, you can sell pieces according to <code>prices</code>. You may sell multiple pieces of the same shape, and you do not have to sell all the shapes. The grain of the wood makes a difference, so you <strong>cannot</strong> rotate a piece to swap its height and width.</p>

<p>Return <em>the <strong>maximum</strong> money you can earn after cutting an </em><code>m x n</code><em> piece of wood</em>.</p>

<p>Note that you can cut the piece of wood as many times as you want.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/04/27/ex1.png" style="width: 239px; height: 150px;">
<pre><strong>Input:</strong> m = 3, n = 5, prices = [[1,4,2],[2,2,7],[2,1,3]]
<strong>Output:</strong> 19
<strong>Explanation:</strong> The diagram above shows a possible scenario. It consists of:
- 2 pieces of wood shaped 2 x 2, selling for a price of 2 * 7 = 14.
- 1 piece of wood shaped 2 x 1, selling for a price of 1 * 3 = 3.
- 1 piece of wood shaped 1 x 4, selling for a price of 1 * 2 = 2.
This obtains a total of 14 + 3 + 2 = 19 money earned.
It can be shown that 19 is the maximum amount of money that can be earned.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/04/27/ex2new.png" style="width: 250px; height: 175px;">
<pre><strong>Input:</strong> m = 4, n = 6, prices = [[3,2,10],[1,4,2],[4,1,3]]
<strong>Output:</strong> 32
<strong>Explanation:</strong> The diagram above shows a possible scenario. It consists of:
- 3 pieces of wood shaped 3 x 2, selling for a price of 3 * 10 = 30.
- 1 piece of wood shaped 1 x 4, selling for a price of 1 * 2 = 2.
This obtains a total of 30 + 2 = 32 money earned.
It can be shown that 32 is the maximum amount of money that can be earned.
Notice that we cannot rotate the 1 x 4 piece of wood to obtain a 4 x 1 piece of wood.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>1 &lt;= prices.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>prices[i].length == 3</code></li>
	<li><code>1 &lt;= h<sub>i</sub> &lt;= m</code></li>
	<li><code>1 &lt;= w<sub>i</sub> &lt;= n</code></li>
	<li><code>1 &lt;= price<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
	<li>All the shapes of wood <code>(h<sub>i</sub>, w<sub>i</sub>)</code> are pairwise <strong>distinct</strong>.</li>
</ul>
</div>