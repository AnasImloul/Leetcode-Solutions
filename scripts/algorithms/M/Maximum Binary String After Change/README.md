<h3 align="left"> 1702. Maximum Binary String After Change</h3>
<div><p>You are given a binary string <code>binary</code> consisting of only <code>0</code>'s or <code>1</code>'s. You can apply each of the following operations any number of times:</p>

<ul>
	<li>Operation 1: If the number contains the substring <code>"00"</code>, you can replace it with <code>"10"</code>.

	<ul>
		<li>For example, <code>"<u>00</u>010" -&gt; "<u>10</u>010</code>"</li>
	</ul>
	</li>
	<li>Operation 2: If the number contains the substring <code>"10"</code>, you can replace it with <code>"01"</code>.
	<ul>
		<li>For example, <code>"000<u>10</u>" -&gt; "000<u>01</u>"</code></li>
	</ul>
	</li>
</ul>

<p><em>Return the <strong>maximum binary string</strong> you can obtain after any number of operations. Binary string <code>x</code> is greater than binary string <code>y</code> if <code>x</code>'s decimal representation is greater than <code>y</code>'s decimal representation.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> binary = "000110"
<strong>Output:</strong> "111011"
<strong>Explanation:</strong> A valid transformation sequence can be:
"0001<u>10</u>" -&gt; "0001<u>01</u>" 
"<u>00</u>0101" -&gt; "<u>10</u>0101" 
"1<u>00</u>101" -&gt; "1<u>10</u>101" 
"110<u>10</u>1" -&gt; "110<u>01</u>1" 
"11<u>00</u>11" -&gt; "11<u>10</u>11"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> binary = "01"
<strong>Output:</strong> "01"
<strong>Explanation:</strong>&nbsp;"01" cannot be transformed any further.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= binary.length &lt;= 10<sup>5</sup></code></li>
	<li><code>binary</code> consist of <code>'0'</code> and <code>'1'</code>.</li>
</ul>
</div>