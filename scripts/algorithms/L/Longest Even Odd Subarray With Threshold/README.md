<h3 align="left"> 2760. Longest Even Odd Subarray With Threshold</h3>
<div><p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> and an integer <code>threshold</code>.</p>

<p>Find the length of the <strong>longest subarray</strong> of <code>nums</code> starting at index <code>l</code> and ending at index <code>r</code> <code>(0 &lt;= l &lt;= r &lt; nums.length)</code> that satisfies the following conditions:</p>

<ul>
	<li><code>nums[l] % 2 == 0</code></li>
	<li>For all indices <code>i</code> in the range <code>[l, r - 1]</code>, <code>nums[i] % 2 != nums[i + 1] % 2</code></li>
	<li>For all indices <code>i</code> in the range <code>[l, r]</code>, <code>nums[i] &lt;= threshold</code></li>
</ul>

<p>Return <em>an integer denoting the length of the longest such subarray.</em></p>

<p><strong>Note:</strong> A <strong>subarray</strong> is a contiguous non-empty sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,2,5,4], threshold = 5
<strong>Output:</strong> 3
<strong>Explanation:</strong> In this example, we can select the subarray that starts at l = 1 and ends at r = 3 =&gt; [2,5,4]. This subarray satisfies the conditions.
Hence, the answer is the length of the subarray, 3. We can show that 3 is the maximum possible achievable length.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2], threshold = 2
<strong>Output:</strong> 1
<strong>Explanation:</strong> In this example, we can select the subarray that starts at l = 1 and ends at r = 1 =&gt; [2]. 
It satisfies all the conditions and we can show that 1 is the maximum possible achievable length.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,3,4,5], threshold = 4
<strong>Output:</strong> 3
<strong>Explanation:</strong> In this example, we can select the subarray that starts at l = 0 and ends at r = 2 =&gt; [2,3,4]. 
It satisfies all the conditions.
Hence, the answer is the length of the subarray, 3. We can show that 3 is the maximum possible achievable length.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100 </code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100 </code></li>
	<li><code>1 &lt;= threshold &lt;= 100</code></li>
</ul>
</div>
