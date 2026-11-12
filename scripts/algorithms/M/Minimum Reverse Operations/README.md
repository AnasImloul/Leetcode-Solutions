<h3 align="left"> 2612. Minimum Reverse Operations</h3>
<div><p>You are given an integer <code>n</code> and an integer <code>p</code> representing an array <code>arr</code> of length <code>n</code> where all elements are set to 0&#39;s, except position <code>p</code> which is set to 1. You are also given an integer array <code>banned</code> containing restricted positions. Perform the following operation on <code>arr</code>:</p>

<ul>
	<li>Reverse a <span data-keyword="subarray-nonempty"><strong>subarray</strong></span> with size <code>k</code> if the single 1 is not set to a position in <code>banned</code>.</li>
</ul>

<p>Return an integer array <code>answer</code> with <code>n</code> results where the <code>i<sup>th</sup></code> result is<em> </em>the <strong>minimum</strong> number of operations needed to bring the single 1 to position <code>i</code> in <code>arr</code>, or -1 if it is impossible.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 4, p = 0, banned = [1,2], k = 4</span></p>

<p><strong>Output:</strong> <span class="example-io">[0,-1,-1,1]</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Initially 1 is placed at position 0 so the number of operations we need for position 0 is 0.</li>
	<li>We can never place 1 on the banned positions, so the answer for positions 1 and 2 is -1.</li>
	<li>Perform the operation of size 4 to reverse the whole array.</li>
	<li>After a single operation 1 is at position 3 so the answer for position 3 is 1.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 5, p = 0, banned = [2,4], k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">[0,-1,-1,-1,-1]</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Initially 1 is placed at position 0 so the number of operations we need for position 0 is 0.</li>
	<li>We cannot perform the operation on the subarray positions <code>[0, 2]</code> because position 2 is in banned.</li>
	<li>Because 1 cannot be set at position 2, it is impossible to set 1 at other positions in more operations.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 4, p = 2, banned = [0,1,3], k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">[-1,-1,0,-1]</span></p>

<p><strong>Explanation:</strong></p>

<p>Perform operations of size 1 and 1 never changes its position.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= p &lt;= n - 1</code></li>
	<li><code>0 &lt;= banned.length &lt;= n - 1</code></li>
	<li><code>0 &lt;= banned[i] &lt;= n - 1</code></li>
	<li><code>1 &lt;= k &lt;= n&nbsp;</code></li>
	<li><code>banned[i] != p</code></li>
	<li>all values in <code>banned</code>&nbsp;are <strong>unique</strong>&nbsp;</li>
</ul>
</div>
