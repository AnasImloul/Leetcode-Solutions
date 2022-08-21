<h3 align="left"> 1195. Fizz Buzz Multithreaded</h3>
<div class="content__u3I1 question-content__JfgR"><div><p>You have the four functions:</p>

<ul>
	<li><code>printFizz</code> that prints the word <code>"fizz"</code> to the console,</li>
	<li><code>printBuzz</code> that prints the word <code>"buzz"</code> to the console,</li>
	<li><code>printFizzBuzz</code> that prints the word <code>"fizzbuzz"</code> to the console, and</li>
	<li><code>printNumber</code> that prints a given integer to the console.</li>
</ul>

<p>You are given an instance of the class <code>FizzBuzz</code> that has four functions: <code>fizz</code>, <code>buzz</code>, <code>fizzbuzz</code> and <code>number</code>. The same instance of <code>FizzBuzz</code> will be passed to four different threads:</p>

<ul>
	<li><strong>Thread A:</strong> calls <code>fizz()</code> that should output the word <code>"fizz"</code>.</li>
	<li><strong>Thread B:</strong> calls <code>buzz()</code> that should output the word <code>"buzz"</code>.</li>
	<li><strong>Thread C:</strong> calls <code>fizzbuzz()</code> that should output the word <code>"fizzbuzz"</code>.</li>
	<li><strong>Thread D:</strong> calls <code>number()</code> that should only output the integers.</li>
</ul>

<p>Modify the given class to output the series <code>[1, 2, "fizz", 4, "buzz", ...]</code> where the <code>i<sup>th</sup></code> token (<strong>1-indexed</strong>) of the series is:</p>

<ul>
	<li><code>"fizzbuzz"</code> if <code>i</code> is divisible by <code>3</code> and <code>5</code>,</li>
	<li><code>"fizz"</code> if <code>i</code> is divisible by <code>3</code> and not <code>5</code>,</li>
	<li><code>"buzz"</code> if <code>i</code> is divisible by <code>5</code> and not <code>3</code>, or</li>
	<li><code>i</code> if <code>i</code> is not divisible by <code>3</code> or <code>5</code>.</li>
</ul>

<p>Implement the <code>FizzBuzz</code> class:</p>

<ul>
	<li><code>FizzBuzz(int n)</code> Initializes the object with the number <code>n</code> that represents the length of the sequence that should be printed.</li>
	<li><code>void fizz(printFizz)</code> Calls <code>printFizz</code> to output <code>"fizz"</code>.</li>
	<li><code>void buzz(printBuzz)</code> Calls <code>printBuzz</code> to output <code>"buzz"</code>.</li>
	<li><code>void fizzbuzz(printFizzBuzz)</code> Calls <code>printFizzBuzz</code> to output <code>"fizzbuzz"</code>.</li>
	<li><code>void number(printNumber)</code> Calls <code>printnumber</code> to output the numbers.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> n = 15
<strong>Output:</strong> [1,2,"fizz",4,"buzz","fizz",7,8,"fizz","buzz",11,"fizz",13,14,"fizzbuzz"]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> n = 5
<strong>Output:</strong> [1,2,"fizz",4,"buzz"]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code></li>
</ul>
</div></div>