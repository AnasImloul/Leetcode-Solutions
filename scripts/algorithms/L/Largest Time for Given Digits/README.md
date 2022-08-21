<h3 align="left"> 949. Largest Time for Given Digits</h3>
<div><p>Given an array <code>arr</code> of 4 digits, find the latest 24-hour time that can be made using each digit <strong>exactly once</strong>.</p>

<p>24-hour times are formatted as <code>"HH:MM"</code>, where <code>HH</code> is between <code>00</code> and <code>23</code>, and <code>MM</code> is between <code>00</code> and <code>59</code>. The earliest 24-hour time is <code>00:00</code>, and the latest is <code>23:59</code>.</p>

<p>Return <em>the latest 24-hour time in <code>"HH:MM"</code> format</em>. If no valid time can be made, return an empty string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [1,2,3,4]
<strong>Output:</strong> "23:41"
<strong>Explanation:</strong> The valid 24-hour times are "12:34", "12:43", "13:24", "13:42", "14:23", "14:32", "21:34", "21:43", "23:14", and "23:41". Of these times, "23:41" is the latest.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [5,5,5,5]
<strong>Output:</strong> ""
<strong>Explanation:</strong> There are no valid 24-hour times as "55:55" is not valid.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>arr.length == 4</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 9</code></li>
</ul>
</div>