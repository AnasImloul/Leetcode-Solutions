<h3 align="left"> 2343. Query Kth Smallest Trimmed Number</h3>
<div><p>You are given a <strong>0-indexed</strong> array of strings <code>nums</code>, where each string is of <strong>equal length</strong> and consists of only digits.</p>

<p>You are also given a <strong>0-indexed</strong> 2D integer array <code>queries</code> where <code>queries[i] = [k<sub>i</sub>, trim<sub>i</sub>]</code>. For each <code>queries[i]</code>, you need to:</p>

<ul>
	<li><strong>Trim</strong> each number in <code>nums</code> to its <strong>rightmost</strong> <code>trim<sub>i</sub></code> digits.</li>
	<li>Determine the <strong>index</strong> of the <code>k<sub>i</sub><sup>th</sup></code> smallest trimmed number in <code>nums</code>. If two trimmed numbers are equal, the number with the <strong>lower</strong> index is considered to be smaller.</li>
	<li>Reset each number in <code>nums</code> to its original length.</li>
</ul>

<p>Return <em>an array </em><code>answer</code><em> of the same length as </em><code>queries</code>,<em> where </em><code>answer[i]</code><em> is the answer to the </em><code>i<sup>th</sup></code><em> query.</em></p>

<p><strong>Note</strong>:</p>

<ul>
	<li>To trim to the rightmost <code>x</code> digits means to keep removing the leftmost digit, until only <code>x</code> digits remain.</li>
	<li>Strings in <code>nums</code> may contain leading zeros.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = ["102","473","251","814"], queries = [[1,1],[2,3],[4,2],[1,2]]
<strong>Output:</strong> [2,2,1,0]
<strong>Explanation:</strong>
1. After trimming to the last digit, nums = ["2","3","1","4"]. The smallest number is 1 at index 2.
2. Trimmed to the last 3 digits, nums is unchanged. The 2<sup>nd</sup> smallest number is 251 at index 2.
3. Trimmed to the last 2 digits, nums = ["02","73","51","14"]. The 4<sup>th</sup> smallest number is 73.
4. Trimmed to the last 2 digits, the smallest number is 2 at index 0.
   Note that the trimmed number "02" is evaluated as 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = ["24","37","96","04"], queries = [[2,1],[2,2]]
<strong>Output:</strong> [3,0]
<strong>Explanation:</strong>
1. Trimmed to the last digit, nums = ["4","7","6","4"]. The 2<sup>nd</sup> smallest number is 4 at index 3.
   There are two occurrences of 4, but the one at index 0 is considered smaller than the one at index 3.
2. Trimmed to the last 2 digits, nums is unchanged. The 2<sup>nd</sup> smallest number is 24.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i].length &lt;= 100</code></li>
	<li><code>nums[i]</code> consists of only digits.</li>
	<li>All <code>nums[i].length</code> are <strong>equal</strong>.</li>
	<li><code>1 &lt;= queries.length &lt;= 100</code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>1 &lt;= k<sub>i</sub> &lt;= nums.length</code></li>
	<li><code>1 &lt;= trim<sub>i</sub> &lt;= nums[i].length</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you use the <strong>Radix Sort Algorithm</strong> to solve this problem? What will be the complexity of that solution?</p>
</div>