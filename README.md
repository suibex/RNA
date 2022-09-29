# RNA
RNA is a message-digest algorithm that is cryptographically undecryptable (atleast for now) but still lightweight at it's core.


<h1>How this came to be?</h1>

<p>I was at a biology class and teacher was showing us the iRNA and Ribosomes.I was so tired i couldn't even recognize his words anymore.<br>
But then this image hit me.<br>
<br>
<img width="601" alt="image" src="https://user-images.githubusercontent.com/59802817/193108898-d9d3010c-508d-4d0e-a00f-2071c5b1e18f.png">
<br>
Now you won't really see anything useful here. But he explained it like this:
<br>
Ribosomes are grabbing the info from informational RNA (iRNA) and using them to create Protein.
<br>
So then I somehow woke up and taught. Wait. Can I use this to create a hashing algorithm?
<br>
Maybe not a good one, but still it would be hella fun to do so.
<br>
<h1>How it works?</h1>
RNA hashing works by using prefixed random values.<br>
Just like iRNA has prefixed info.<br>
Those values are then calculated with this formulas that I came up with:
<br>
<br>
<img width="628" alt="image" src="https://user-images.githubusercontent.com/59802817/193109793-a769c2f7-f0d2-4115-a60a-019c53fb37cf.png">
<br>
And as far as I tested , new hashes everytime, always different. This is fun!
<br>Also, as a coincidence , this hashing is really fast, so thats neat too.<br>

<br>
<h1>Example:</h1>
<br>
<p>This example can be found in repo as well as the implementation of RNA hashing in C.<br>
<h2>The quick brown fox jumps over the lazy dog.</h2>

<img width="634" alt="image" src="https://user-images.githubusercontent.com/59802817/193110097-9f0d817e-5bf8-44ea-9b4b-1f1a58356b51.png">
<br>
so I guess Biology is not that boring, huh?
