<h3 align="left"> 2259. Remove Digit From Number to Maximize Result</h3>
<div><p>You are given a string <code>number</code> representing a <strong>positive integer</strong> and a character <code>digit</code>.</p>

<p>Return <em>the resulting string after removing <strong>exactly one occurrence</strong> of </em><code>digit</code><em> from </em><code>number</code><em> such that the value of the resulting string in <strong>decimal</strong> form is <strong>maximized</strong></em>. The test cases are generated such that <code>digit</code> occurs at least once in <code>number</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> number = "123", digit = "3"
<strong>Output:</strong> "12"
<strong>Explanation:</strong> There is only one '3' in "123". After removing '3', the result is "12".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> number = "1231", digit = "1"
<strong>Output:</strong> "231"
<strong>Explanation:</strong> We can remove the first '1' to get "231" or remove the second '1' to get "123".
Since 231 &gt; 123, we return "231".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> number = "551", digit = "5"
<strong>Output:</strong> "51"
<strong>Explanation:</strong> We can remove either the first or second '5' from "551".
Both result in the string "51".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= number.length &lt;= 100</code></li>
	<li><code>number</code> consists of digits from <code>'1'</code> to <code>'9'</code>.</li>
	<li><code>digit</code> is a digit from <code>'1'</code> to <code>'9'</code>.</li>
	<li><code>digit</code> occurs at least once in <code>number</code>.</li>
</ul>
</div>