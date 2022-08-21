<h3 align="left"> 638. Shopping Offers</h3>
<div><p>In LeetCode Store, there are <code>n</code> items to sell. Each item has a price. However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.</p>

<p>You are given an integer array <code>price</code> where <code>price[i]</code> is the price of the <code>i<sup>th</sup></code> item, and an integer array <code>needs</code> where <code>needs[i]</code> is the number of pieces of the <code>i<sup>th</sup></code> item you want to buy.</p>

<p>You are also given an array <code>special</code> where <code>special[i]</code> is of size <code>n + 1</code> where <code>special[i][j]</code> is the number of pieces of the <code>j<sup>th</sup></code> item in the <code>i<sup>th</sup></code> offer and <code>special[i][n]</code> (i.e., the last integer in the array) is the price of the <code>i<sup>th</sup></code> offer.</p>

<p>Return <em>the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers</em>. You are not allowed to buy more items than you want, even if that would lower the overall price. You could use any of the special offers as many times as you want.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> price = [2,5], special = [[3,0,5],[1,2,10]], needs = [3,2]
<strong>Output:</strong> 14
<strong>Explanation:</strong> There are two kinds of items, A and B. Their prices are $2 and $5 respectively. 
In special offer 1, you can pay $5 for 3A and 0B
In special offer 2, you can pay $10 for 1A and 2B. 
You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> price = [2,3,4], special = [[1,1,0,4],[2,2,1,9]], needs = [1,2,1]
<strong>Output:</strong> 11
<strong>Explanation:</strong> The price of A is $2, and $3 for B, $4 for C. 
You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C. 
You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), and $3 for 1B, $4 for 1C. 
You cannot add more items, though only $9 for 2A ,2B and 1C.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == price.length == needs.length</code></li>
	<li><code>1 &lt;= n &lt;= 6</code></li>
	<li><code>0 &lt;= price[i], needs[i] &lt;= 10</code></li>
	<li><code>1 &lt;= special.length &lt;= 100</code></li>
	<li><code>special[i].length == n + 1</code></li>
	<li><code>0 &lt;= special[i][j] &lt;= 50</code></li>
</ul>
</div>