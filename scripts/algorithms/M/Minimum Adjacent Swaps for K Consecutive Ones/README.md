<h3 align="left"> 1703. Minimum Adjacent Swaps for K Consecutive Ones</h3>
<div><p>You are given an integer array, <code>nums</code>, and an integer <code>k</code>. <code>nums</code> comprises of only <code>0</code>'s and <code>1</code>'s. In one move, you can choose two <strong>adjacent</strong> indices and swap their values.</p>

<p>Return <em>the <strong>minimum</strong> number of moves required so that </em><code>nums</code><em> has </em><code>k</code><em> <strong>consecutive</strong> </em><code>1</code><em>'s</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,0,0,1,0,1], k = 2
<strong>Output:</strong> 1
<strong>Explanation:</strong> In 1 move, nums could be [1,0,0,0,<u>1</u>,<u>1</u>] and have 2 consecutive 1's.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,0,0,0,0,0,1,1], k = 3
<strong>Output:</strong> 5
<strong>Explanation:</strong> In 5 moves, the leftmost 1 can be shifted right until nums = [0,0,0,0,0,<u>1</u>,<u>1</u>,<u>1</u>].
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,0,1], k = 2
<strong>Output:</strong> 0
<strong>Explanation:</strong> nums already has 2 consecutive 1's.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> is <code>0</code> or <code>1</code>.</li>
	<li><code>1 &lt;= k &lt;= sum(nums)</code></li>
</ul>
</div>