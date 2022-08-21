<h3 align="left"> 818. Race Car</h3>
<div><p>Your car starts at position <code>0</code> and speed <code>+1</code> on an infinite number line. Your car can go into negative positions. Your car drives automatically according to a sequence of instructions <code>'A'</code> (accelerate) and <code>'R'</code> (reverse):</p>

<ul>
	<li>When you get an instruction <code>'A'</code>, your car does the following:

	<ul>
		<li><code>position += speed</code></li>
		<li><code>speed *= 2</code></li>
	</ul>
	</li>
	<li>When you get an instruction <code>'R'</code>, your car does the following:
	<ul>
		<li>If your speed is positive then <code>speed = -1</code></li>
		<li>otherwise <code>speed = 1</code></li>
	</ul>
	Your position stays the same.</li>
</ul>

<p>For example, after commands <code>"AAR"</code>, your car goes to positions <code>0 --&gt; 1 --&gt; 3 --&gt; 3</code>, and your speed goes to <code>1 --&gt; 2 --&gt; 4 --&gt; -1</code>.</p>

<p>Given a target position <code>target</code>, return <em>the length of the shortest sequence of instructions to get there</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> target = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
The shortest instruction sequence is "AA".
Your position goes from 0 --&gt; 1 --&gt; 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> target = 6
<strong>Output:</strong> 5
<strong>Explanation:</strong> 
The shortest instruction sequence is "AAARA".
Your position goes from 0 --&gt; 1 --&gt; 3 --&gt; 7 --&gt; 7 --&gt; 6.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= target &lt;= 10<sup>4</sup></code></li>
</ul>
</div>