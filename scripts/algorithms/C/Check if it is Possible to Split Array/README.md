<h3 align="left"> 2811. Check if it is Possible to Split Array</h3>
<div><p>You are given an array <code>nums</code> of length <code>n</code> and an integer <code>m</code>. You need to determine if it is possible to split the array into <code>n</code> arrays of size 1 by performing a series of steps.</p>

<p>An array is called <strong>good</strong> if:</p>

<ul>
	<li>The length of the array is <strong>one</strong>, or</li>
	<li>The sum of the elements of the array is <strong>greater than or equal</strong> to <code>m</code>.</li>
</ul>

<p>In each step, you can select an existing array (which may be the result of previous steps) with a length of <strong>at least two</strong> and split it into <strong>two </strong>arrays, if both resulting arrays are good.</p>

<p>Return true if you can split the given array into <code>n</code> arrays, otherwise return false.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2, 2, 1], m = 4</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Split <code>[2, 2, 1]</code> to <code>[2, 2]</code> and <code>[1]</code>. The array <code>[1]</code> has a length of one, and the array <code>[2, 2]</code> has the sum of its elements equal to <code>4 &gt;= m</code>, so both are good arrays.</li>
	<li>Split <code>[2, 2]</code> to <code>[2]</code> and <code>[2]</code>. both arrays have the length of one, so both are good arrays.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2, 1, 3], m = 5</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p><strong>Explanation:</strong></p>

<p>The first move has to be either of the following:</p>

<ul>
	<li>Split <code>[2, 1, 3]</code> to <code>[2, 1]</code> and <code>[3]</code>. The array <code>[2, 1]</code> has neither length of one nor sum of elements greater than or equal to <code>m</code>.</li>
	<li>Split <code>[2, 1, 3]</code> to <code>[2]</code> and <code>[1, 3]</code>. The array <code>[1, 3]</code> has neither length of one nor sum of elements greater than or equal to <code>m</code>.</li>
</ul>

<p>So as both moves are invalid (they do not divide the array into two good arrays), we are unable to split <code>nums</code> into <code>n</code> arrays of size 1.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2, 3, 3, 2, 3], m = 6</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li><span class="example-io">Split <code>[2, 3, 3, 2, 3]</code> to <code>[2]</code> and <code>[3, 3, 2, 3]</code>.</span></li>
	<li><span class="example-io">Split <code>[3, 3, 2, 3]</code> to <code>[3, 3, 2]</code> and <code>[3]</code>.</span></li>
	<li><span class="example-io">Split <code>[3, 3, 2]</code> to <code>[3, 3]</code> and <code>[2]</code>.</span></li>
	<li><span class="example-io">Split <code>[3, 3]</code> to <code>[3]</code> and <code>[3]</code>.</span></li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>1 &lt;= m &lt;= 200</code></li>
</ul>
</div>
