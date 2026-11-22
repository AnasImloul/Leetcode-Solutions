<h3 align="left"> 2917. Find the K-or of an Array</h3>
<div><p>You are given an integer array <code>nums</code>, and an integer <code>k</code>. Let&#39;s introduce&nbsp;<strong>K-or</strong> operation by extending the standard bitwise OR. In K-or, a bit position in the result is set to <code>1</code>&nbsp;if at least <code>k</code> numbers in <code>nums</code> have a <code>1</code> in that position.</p>

<p>Return <em>the K-or of</em> <code>nums</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1: </strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>Input:</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> nums = [7,12,9,8,9,15], k = 4 </span></p>

<p><strong>Output:</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> 9 </span></p>

<p><strong>Explanation: </strong></p>

<p>Represent numbers in binary:</p>

<table style="text-indent:10px; margin-bottom=20px;">
	<tbody>
		<tr>
			<th><b>Number</b></th>
			<th>Bit 3</th>
			<th>Bit 2</th>
			<th>Bit 1</th>
			<th>Bit 0</th>
		</tr>
		<tr>
			<td><b>7</b></td>
			<td>0</td>
			<td>1</td>
			<td>1</td>
			<td>1</td>
		</tr>
		<tr>
			<td><b>12</b></td>
			<td>1</td>
			<td>1</td>
			<td>0</td>
			<td>0</td>
		</tr>
		<tr>
			<td><b>9</b></td>
			<td>1</td>
			<td>0</td>
			<td>0</td>
			<td>1</td>
		</tr>
		<tr>
			<td><b>8</b></td>
			<td>1</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
		</tr>
		<tr>
			<td><b>9</b></td>
			<td>1</td>
			<td>0</td>
			<td>0</td>
			<td>1</td>
		</tr>
		<tr>
			<td><b>15</b></td>
			<td>1</td>
			<td>1</td>
			<td>1</td>
			<td>1</td>
		</tr>
		<tr>
			<td><b>Result = 9</b></td>
			<td>1</td>
			<td>0</td>
			<td>0</td>
			<td>1</td>
		</tr>
	</tbody>
</table>

<p>Bit 0 is set in 7, 9, 9, and 15. Bit 3 is set in 12, 9, 8, 9, and 15.<br />
Only bits 0 and 3 qualify. The result is <code>(1001)<sub>2</sub> = 9</code>.</p>
</div>

<p><strong class="example">Example 2: </strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>Input:</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> nums = [2,12,1,11,4,5], k = 6 </span></p>

<p><strong>Output:</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> 0 </span></p>

<p><strong>Explanation:&nbsp;</strong>No bit appears as 1 in all six array numbers, as required for K-or with <code>k = 6</code>. Thus, the result is 0.</p>
</div>

<p><strong class="example">Example 3: </strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>Input:</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> nums = [10,8,5,9,11,6,8], k = 1 </span></p>

<p><strong>Output:</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> 15 </span></p>

<p><strong>Explanation: </strong> Since <code>k == 1</code>, the 1-or of the array is equal to the bitwise OR of all its elements. Hence, the answer is <code>10 OR 8 OR 5 OR 9 OR 11 OR 6 OR 8 = 15</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>0 &lt;= nums[i] &lt; 2<sup>31</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>
</div>
