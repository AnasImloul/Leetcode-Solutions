<h3 align="left"> 2232. Minimize Result by Adding Parentheses to Expression</h3>
<div><p>You are given a <strong>0-indexed</strong> string <code>expression</code> of the form <code>"&lt;num1&gt;+&lt;num2&gt;"</code> where <code>&lt;num1&gt;</code> and <code>&lt;num2&gt;</code> represent positive integers.</p>

<p>Add a pair of parentheses to <code>expression</code> such that after the addition of parentheses, <code>expression</code> is a <strong>valid</strong> mathematical expression and evaluates to the <strong>smallest</strong> possible value. The left parenthesis <strong>must</strong> be added to the left of <code>'+'</code> and the right parenthesis <strong>must</strong> be added to the right of <code>'+'</code>.</p>

<p>Return <code>expression</code><em> after adding a pair of parentheses such that </em><code>expression</code><em> evaluates to the <strong>smallest</strong> possible value.</em> If there are multiple answers that yield the same result, return any of them.</p>

<p>The input has been generated such that the original value of <code>expression</code>, and the value of <code>expression</code> after adding any pair of parentheses that meets the requirements fits within a signed 32-bit integer.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> expression = "247+38"
<strong>Output:</strong> "2(47+38)"
<strong>Explanation:</strong> The <code>expression</code> evaluates to 2 * (47 + 38) = 2 * 85 = 170.
Note that "2(4)7+38" is invalid because the right parenthesis must be to the right of the <code>'+'</code>.
It can be shown that 170 is the smallest possible value.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> expression = "12+34"
<strong>Output:</strong> "1(2+3)4"
<strong>Explanation:</strong> The expression evaluates to 1 * (2 + 3) * 4 = 1 * 5 * 4 = 20.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> expression = "999+999"
<strong>Output:</strong> "(999+999)"
<strong>Explanation:</strong> The <code>expression</code> evaluates to 999 + 999 = 1998.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= expression.length &lt;= 10</code></li>
	<li><code>expression</code> consists of digits from <code>'1'</code> to <code>'9'</code> and <code>'+'</code>.</li>
	<li><code>expression</code> starts and ends with digits.</li>
	<li><code>expression</code> contains exactly one <code>'+'</code>.</li>
	<li>The original value of <code>expression</code>, and the value of <code>expression</code> after adding any pair of parentheses that meets the requirements fits within a signed 32-bit integer.</li>
</ul>
</div>