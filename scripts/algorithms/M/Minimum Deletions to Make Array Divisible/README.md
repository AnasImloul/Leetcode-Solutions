<h3 align="left"> 2344. Minimum Deletions to Make Array Divisible</h3>
<div><p>You are given two positive integer arrays <code>nums</code> and <code>numsDivide</code>. You can delete any number of elements from <code>nums</code>.</p>

<p>Return <em>the <strong>minimum</strong> number of deletions such that the <strong>smallest</strong> element in </em><code>nums</code><em> <strong>divides</strong> all the elements of </em><code>numsDivide</code>. If this is not possible, return <code>-1</code>.</p>

<p>Note that an integer <code>x</code> divides <code>y</code> if <code>y % x == 0</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,3,2,4,3], numsDivide = [9,6,9,3,15]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
The smallest element in [2,3,2,4,3] is 2, which does not divide all the elements of numsDivide.
We use 2 deletions to delete the elements in nums that are equal to 2 which makes nums = [3,4,3].
The smallest element in [3,4,3] is 3, which divides all the elements of numsDivide.
It can be shown that 2 is the minimum number of deletions needed.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [4,3,6], numsDivide = [8,2,6,10]
<strong>Output:</strong> -1
<strong>Explanation:</strong> 
We want the smallest element in nums to divide all the elements of numsDivide.
There is no way to delete elements from nums to allow this.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length, numsDivide.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], numsDivide[i] &lt;= 10<sup>9</sup></code></li>
</ul>
</div>