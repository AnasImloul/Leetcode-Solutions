<h3 align="left"> 1850. Minimum Adjacent Swaps to Reach the Kth Smallest Number</h3>
<div><p>You are given a string <code>num</code>, representing a large integer, and an integer <code>k</code>.</p>

<p>We call some integer <strong>wonderful</strong> if it is a <strong>permutation</strong> of the digits in <code>num</code> and is <strong>greater in value</strong> than <code>num</code>. There can be many wonderful integers. However, we only care about the <strong>smallest-valued</strong> ones.</p>

<ul>
	<li>For example, when <code>num = "5489355142"</code>:

	<ul>
		<li>The 1<sup>st</sup> smallest wonderful integer is <code>"5489355214"</code>.</li>
		<li>The 2<sup>nd</sup> smallest wonderful integer is <code>"5489355241"</code>.</li>
		<li>The 3<sup>rd</sup> smallest wonderful integer is <code>"5489355412"</code>.</li>
		<li>The 4<sup>th</sup> smallest wonderful integer is <code>"5489355421"</code>.</li>
	</ul>
	</li>
</ul>

<p>Return <em>the <strong>minimum number of adjacent digit swaps</strong> that needs to be applied to </em><code>num</code><em> to reach the </em><code>k<sup>th</sup></code><em><strong> smallest wonderful</strong> integer</em>.</p>

<p>The tests are generated in such a way that <code>k<sup>th</sup></code>&nbsp;smallest wonderful integer exists.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> num = "5489355142", k = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong> The 4<sup>th</sup> smallest wonderful number is "5489355421". To get this number:
- Swap index 7 with index 8: "5489355<u>14</u>2" -&gt; "5489355<u>41</u>2"
- Swap index 8 with index 9: "54893554<u>12</u>" -&gt; "54893554<u>21</u>"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = "11112", k = 4
<strong>Output:</strong> 4
<strong>Explanation:</strong> The 4<sup>th</sup> smallest wonderful number is "21111". To get this number:
- Swap index 3 with index 4: "111<u>12</u>" -&gt; "111<u>21</u>"
- Swap index 2 with index 3: "11<u>12</u>1" -&gt; "11<u>21</u>1"
- Swap index 1 with index 2: "1<u>12</u>11" -&gt; "1<u>21</u>11"
- Swap index 0 with index 1: "<u>12</u>111" -&gt; "<u>21</u>111"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> num = "00123", k = 1
<strong>Output:</strong> 1
<strong>Explanation:</strong> The 1<sup>st</sup> smallest wonderful number is "00132". To get this number:
- Swap index 3 with index 4: "001<u>23</u>" -&gt; "001<u>32</u>"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= num.length &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= 1000</code></li>
	<li><code>num</code> only consists of digits.</li>
</ul>
</div>