<h3 align="left"> 2449. Minimum Number of Operations to Make Arrays Similar</h3>
<div><p>You are given two positive integer arrays <code>nums</code> and <code>target</code>, of the same length.</p>

<p>In one operation, you can choose any two <strong>distinct</strong> indices <code>i</code> and <code>j</code> where <code>0 &lt;= i, j &lt; nums.length</code> and:</p>

<ul>
	<li>set <code>nums[i] = nums[i] + 2</code> and</li>
	<li>set <code>nums[j] = nums[j] - 2</code>.</li>
</ul>

<p>Two arrays are considered to be <strong>similar</strong> if the frequency of each element is the same.</p>

<p>Return <em>the minimum number of operations required to make </em><code>nums</code><em> similar to </em><code>target</code>. The test cases are generated such that <code>nums</code> can always be similar to <code>target</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [8,12,6], target = [2,14,10]
<strong>Output:</strong> 2
<strong>Explanation:</strong> It is possible to make nums similar to target in two operations:
- Choose i = 0 and j = 2, nums = [10,12,4].
- Choose i = 1 and j = 2, nums = [10,14,2].
It can be shown that 2 is the minimum number of operations needed.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,5], target = [4,1,3]
<strong>Output:</strong> 1
<strong>Explanation:</strong> We can make nums similar to target in one operation:
- Choose i = 1 and j = 2, nums = [1,4,3].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,1,1,1], target = [1,1,1,1,1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The array nums is already similiar to target.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length == target.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], target[i] &lt;= 10<sup>6</sup></code></li>
	<li>It is possible to make <code>nums</code> similar to <code>target</code>.</li>
</ul>
</div>
