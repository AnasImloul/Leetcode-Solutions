<h3 align="left"> 1250. Check If It Is a Good Array</h3>
<div><p>Given an array <code>nums</code> of&nbsp;positive integers. Your task is to select some subset of <code>nums</code>, multiply each element by an integer and add all these numbers.&nbsp;The array is said to be&nbsp;<strong>good&nbsp;</strong>if you can obtain a sum of&nbsp;<code>1</code>&nbsp;from the array by any possible subset and multiplicand.</p>

<p>Return&nbsp;<code>True</code>&nbsp;if the array is <strong>good&nbsp;</strong>otherwise&nbsp;return&nbsp;<code>False</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [12,5,7,23]
<strong>Output:</strong> true
<strong>Explanation:</strong> Pick numbers 5 and 7.
5*3 + 7*(-2) = 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [29,6,10]
<strong>Output:</strong> true
<strong>Explanation:</strong> Pick numbers 29, 6 and 10.
29*1 + 6*(-3) + 10*(-1) = 1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [3,6]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^9</code></li>
</ul>
</div>