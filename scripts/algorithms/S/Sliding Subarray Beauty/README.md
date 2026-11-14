<h3 align="left"> 2653. Sliding Subarray Beauty</h3>
<div><p>Given an integer array <code>nums</code> containing <code>n</code> integers, find the <strong>beauty</strong> of each subarray of size <code>k</code>.</p>

<p>The <strong>beauty</strong> of a subarray is the <code>x<sup>th</sup></code><strong> smallest integer </strong>in the subarray if it is <strong>negative</strong>, or <code>0</code> if there are fewer than <code>x</code> negative integers.</p>

<p>Return <em>an integer array containing </em><code>n - k + 1</code> <em>integers, which denote the </em><strong>beauty</strong><em> of the subarrays <strong>in order</strong> from the first index in the array.</em></p>

<ul>
	<li>
	<p>A subarray is a contiguous <strong>non-empty</strong> sequence of elements within an array.</p>
	</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,-1,-3,-2,3], k = 3, x = 2
<strong>Output:</strong> [-1,-2,-2]
<strong>Explanation:</strong> There are 3 subarrays with size k = 3. 
The first subarray is <code>[1, -1, -3]</code> and the 2<sup>nd</sup> smallest negative integer is -1.&nbsp;
The second subarray is <code>[-1, -3, -2]</code> and the 2<sup>nd</sup> smallest negative integer is -2.&nbsp;
The third subarray is <code>[-3, -2, 3]&nbsp;</code>and the 2<sup>nd</sup> smallest negative integer is -2.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [-1,-2,-3,-4,-5], k = 2, x = 2
<strong>Output:</strong> [-1,-2,-3,-4]
<strong>Explanation:</strong> There are 4 subarrays with size k = 2.
For <code>[-1, -2]</code>, the 2<sup>nd</sup> smallest negative integer is -1.
For <code>[-2, -3]</code>, the 2<sup>nd</sup> smallest negative integer is -2.
For <code>[-3, -4]</code>, the 2<sup>nd</sup> smallest negative integer is -3.
For <code>[-4, -5]</code>, the 2<sup>nd</sup> smallest negative integer is -4.&nbsp;</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [-3,1,2,-3,0,-3], k = 2, x = 1
<strong>Output:</strong> [-3,0,-3,-3,-3]
<strong>Explanation:</strong> There are 5 subarrays with size k = 2<strong>.</strong>
For <code>[-3, 1]</code>, the 1<sup>st</sup> smallest negative integer is -3.
For <code>[1, 2]</code>, there is no negative integer so the beauty is 0.
For <code>[2, -3]</code>, the 1<sup>st</sup> smallest negative integer is -3.
For <code>[-3, 0]</code>, the 1<sup>st</sup> smallest negative integer is -3.
For <code>[0, -3]</code>, the 1<sup>st</sup> smallest negative integer is -3.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length&nbsp;</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
	<li><code>1 &lt;= x &lt;= k&nbsp;</code></li>
	<li><code>-50&nbsp;&lt;= nums[i] &lt;= 50&nbsp;</code></li>
</ul>
</div>
