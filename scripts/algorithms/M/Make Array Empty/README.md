<h3 align="left"> 2659. Make Array Empty</h3>
<div><p>You are given an integer array <code>nums</code> containing <strong>distinct</strong> numbers, and you can perform the following operations <strong>until the array is empty</strong>:</p>

<ul>
	<li>If the first element has the <strong>smallest</strong> value, remove it</li>
	<li>Otherwise, put the first element at the <strong>end</strong> of the array.</li>
</ul>

<p>Return <em>an integer denoting the number of operations it takes to make </em><code>nums</code><em> empty.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,4,-1]
<strong>Output:</strong> 5
</pre>

<table style="border: 2px solid black; border-collapse: collapse;">
	<thead>
		<tr>
			<th style="border: 2px solid black; padding: 5px;">Operation</th>
			<th style="border: 2px solid black; padding: 5px;">Array</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">1</td>
			<td style="border: 2px solid black; padding: 5px;">[4, -1, 3]</td>
		</tr>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">2</td>
			<td style="border: 2px solid black; padding: 5px;">[-1, 3, 4]</td>
		</tr>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">3</td>
			<td style="border: 2px solid black; padding: 5px;">[3, 4]</td>
		</tr>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">4</td>
			<td style="border: 2px solid black; padding: 5px;">[4]</td>
		</tr>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">5</td>
			<td style="border: 2px solid black; padding: 5px;">[]</td>
		</tr>
	</tbody>
</table>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,4,3]
<strong>Output:</strong> 5
</pre>

<table style="border: 2px solid black; border-collapse: collapse;">
	<thead>
		<tr>
			<th style="border: 2px solid black; padding: 5px;">Operation</th>
			<th style="border: 2px solid black; padding: 5px;">Array</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">1</td>
			<td style="border: 2px solid black; padding: 5px;">[2, 4, 3]</td>
		</tr>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">2</td>
			<td style="border: 2px solid black; padding: 5px;">[4, 3]</td>
		</tr>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">3</td>
			<td style="border: 2px solid black; padding: 5px;">[3, 4]</td>
		</tr>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">4</td>
			<td style="border: 2px solid black; padding: 5px;">[4]</td>
		</tr>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">5</td>
			<td style="border: 2px solid black; padding: 5px;">[]</td>
		</tr>
	</tbody>
</table>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 3
</pre>

<table style="border: 2px solid black; border-collapse: collapse;">
	<thead>
		<tr>
			<th style="border: 2px solid black; padding: 5px;">Operation</th>
			<th style="border: 2px solid black; padding: 5px;">Array</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">1</td>
			<td style="border: 2px solid black; padding: 5px;">[2, 3]</td>
		</tr>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">2</td>
			<td style="border: 2px solid black; padding: 5px;">[3]</td>
		</tr>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">3</td>
			<td style="border: 2px solid black; padding: 5px;">[]</td>
		</tr>
	</tbody>
</table>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9&nbsp;</sup>&lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li>All values in <code>nums</code> are <strong>distinct</strong>.</li>
</ul>
</div>
