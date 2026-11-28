<h3 align="left"> 2967. Minimum Cost to Make Array Equalindromic</h3>
<div><p>You are given an integer array <code>nums</code>.</p>

<p>In one <strong>operation</strong>, you may choose an index <code>i</code> and either increment or decrement <code>nums[i]</code> by 1.</p>

<p>Return the <strong>minimum</strong> number of operations required to make every element in <code>nums</code> <strong>equal </strong>to the <strong>same </strong>positive <span data-keyword="palindrome-integer">palindromic integer</span>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4,5]
<strong>Output:</strong> 6
<strong>Explanation:</strong> Increment nums[0] twice and nums[1] once, then decrement nums[3] once and nums[4] twice. After 6 operations, nums becomes [3,3,3,3,3], and 3 is a positive palindromic integer.
It can be shown that this is the minimum number of operations required.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [10,12,13,14,15]
<strong>Output:</strong> 11
<strong>Explanation:</strong> Increment nums[0] once, then decrement nums[1], nums[2], nums[3], and nums[4] by 1, 2, 3, and 4, respectively. After 11 operations, nums becomes [11,11,11,11,11], and 11 is a positive palindromic integer.
It can be shown that this is the minimum number of operations required.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [22,33,22,33,22]
<strong>Output:</strong> 22
<strong>Explanation:</strong> Decrement nums[1] and nums[3] by 11 each. After 22 operations, nums becomes [22,22,22,22,22], and 22 is a positive palindromic integer.
It can be shown that this is the minimum number of operations required.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>
</div>
