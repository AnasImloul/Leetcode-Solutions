<h3 align="left"> 1115. Print FooBar Alternately</h3>
<div class="content__u3I1 question-content__JfgR"><div><p>Suppose you are given the following code:</p>

<pre>class FooBar {
  public void foo() {
    for (int i = 0; i &lt; n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i &lt; n; i++) {
      print("bar");
    }
  }
}
</pre>

<p>The same instance of <code>FooBar</code> will be passed to two different threads:</p>

<ul>
	<li>thread <code>A</code> will call <code>foo()</code>, while</li>
	<li>thread <code>B</code> will call <code>bar()</code>.</li>
</ul>

<p>Modify the given program to output <code>"foobar"</code> <code>n</code> times.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> "foobar"
<strong>Explanation:</strong> There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
"foobar" is being output 1 time.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> "foobarfoobar"
<strong>Explanation:</strong> "foobar" is being output 2 times.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>
</div></div>