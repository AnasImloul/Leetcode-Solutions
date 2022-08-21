<h3 align="left"> 640. Solve the Equation</h3>
<div><p>Solve a given equation and return the value of <code>'x'</code> in the form of a string <code>"x=#value"</code>. The equation contains only <code>'+'</code>, <code>'-'</code> operation, the variable <code>'x'</code> and its coefficient. You should return <code>"No solution"</code> if there is no solution for the equation, or <code>"Infinite solutions"</code> if there are infinite solutions for the equation.</p>

<p>If there is exactly one solution for the equation, we ensure that the value of <code>'x'</code> is an integer.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> equation = "x+5-3+x=6+x-2"
<strong>Output:</strong> "x=2"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> equation = "x=x"
<strong>Output:</strong> "Infinite solutions"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> equation = "2x=x"
<strong>Output:</strong> "x=0"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= equation.length &lt;= 1000</code></li>
	<li><code>equation</code> has exactly one <code>'='</code>.</li>
	<li><code>equation</code> consists of integers with an absolute value in the range <code>[0, 100]</code> without any leading zeros, and the variable <code>'x'</code>.</li>
</ul>
</div>