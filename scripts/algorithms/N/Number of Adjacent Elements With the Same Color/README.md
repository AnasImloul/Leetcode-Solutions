<h3 align="left"> 2672. Number of Adjacent Elements With the Same Color</h3>
<div><p>You are given an integer <code>n</code> representing an array <code>colors</code> of length <code>n</code> where all elements are set to 0&#39;s meaning <strong>uncolored</strong>. You are also given a 2D integer array <code>queries</code> where <code>queries[i] = [index<sub>i</sub>, color<sub>i</sub>]</code>. For the <code>i<sup>th</sup></code> <strong>query</strong>:</p>

<ul>
	<li>Set <code>colors[index<sub>i</sub>]</code> to <code>color<sub>i</sub></code>.</li>
	<li>Count the number of adjacent pairs in <code>colors</code> which have the same color (regardless of <code>color<sub>i</sub></code>).</li>
</ul>

<p>Return an array <code>answer</code> of the same length as <code>queries</code> where <code>answer[i]</code> is the answer to the <code>i<sup>th</sup></code> query.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 4, queries = [[0,2],[1,2],[3,1],[1,1],[2,1]]</span></p>

<p><strong>Output:</strong> <span class="example-io">[0,1,1,0,2]</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Initially array colors = [0,0,0,0], where 0 denotes uncolored elements of the array.</li>
	<li>After the 1<sup>st</sup> query colors = [2,0,0,0]. The count of adjacent pairs with the same color is 0.</li>
	<li>After the 2<sup>nd</sup> query colors = [2,2,0,0]. The count of adjacent pairs with the same color is 1.</li>
	<li>After the 3<sup>rd</sup> query colors = [2,2,0,1]. The count of adjacent pairs with the same color is 1.</li>
	<li>After the 4<sup>th</sup> query colors = [2,1,0,1]. The count of adjacent pairs with the same color is 0.</li>
	<li>After the 5<sup>th</sup> query colors = [2,1,1,1]. The count of adjacent pairs with the same color is 2.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 1, queries = [[0,100000]]</span></p>

<p><strong>Output:</strong> <span class="example-io">[0]</span></p>

<p><strong>Explanation:</strong></p>

<p>After the 1<sup>st</sup> query colors = [100000]. The count of adjacent pairs with the same color is 0.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length&nbsp;== 2</code></li>
	<li><code>0 &lt;= index<sub>i</sub>&nbsp;&lt;= n - 1</code></li>
	<li><code>1 &lt;=&nbsp; color<sub>i</sub>&nbsp;&lt;= 10<sup>5</sup></code></li>
</ul>
</div>
