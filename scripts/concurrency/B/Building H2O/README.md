<h3 align="left"> 1117. Building H2O</h3>
<div class="content__u3I1 question-content__JfgR"><div><p>There are two kinds of threads: <code>oxygen</code> and <code>hydrogen</code>. Your goal is to group these threads to form water molecules.</p>

<p>There is a barrier where each thread has to wait until a complete molecule can be formed. Hydrogen and oxygen threads will be given <code>releaseHydrogen</code> and <code>releaseOxygen</code> methods respectively, which will allow them to pass the barrier. These threads should pass the barrier in groups of three, and they must immediately bond with each other to form a water molecule. You must guarantee that all the threads from one molecule bond before any other threads from the next molecule do.</p>

<p>In other words:</p>

<ul>
	<li>If an oxygen thread arrives at the barrier when no hydrogen threads are present, it must wait for two hydrogen threads.</li>
	<li>If a hydrogen thread arrives at the barrier when no other threads are present, it must wait for an oxygen thread and another hydrogen thread.</li>
</ul>

<p>We do not have to worry about matching the threads up explicitly; the threads do not necessarily know which other threads they are paired up with. The key is that threads pass the barriers in complete sets; thus, if we examine the sequence of threads that bind and divide them into groups of three, each group should contain one oxygen and two hydrogen threads.</p>

<p>Write synchronization code for oxygen and hydrogen molecules that enforces these constraints.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> water = "HOH"
<strong>Output:</strong> "HHO"
<strong>Explanation:</strong> "HOH" and "OHH" are also valid answers.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> water = "OOHHHH"
<strong>Output:</strong> "HHOHHO"
<strong>Explanation:</strong> "HOHHHO", "OHHHHO", "HHOHOH", "HOHHOH", "OHHHOH", "HHOOHH", "HOHOHH" and "OHHOHH" are also valid answers.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 * n == water.length</code></li>
	<li><code>1 &lt;= n &lt;= 20</code></li>
	<li><code>water[i]</code> is either <code>'H'</code> or <code>'O'</code>.</li>
	<li>There will be exactly <code>2 * n</code> <code>'H'</code> in <code>water</code>.</li>
	<li>There will be exactly <code>n</code> <code>'O'</code> in <code>water</code>.</li>
</ul>
</div></div>