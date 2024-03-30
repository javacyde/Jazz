# Jazz
#### An (incredibly) upgraded version of brainfrick

Jazz is an extension of brainf**k, run on a 2D matrix with various upgrades to make it easier to understand and program.

It basically adds a whole load of syntactic sugar, defeating the whole purpose of brainf**k while making for a fun programming project -- and a strange experience for anyone bored enough to test it.

Overview of commands can be found in [DOCS.md](DOCS.md).

To sum it up:
 - Matrix is 256x256, and it wraps.
 - Both stacks are one dimensional arrays of length 10.
 - Flow and memory stack are static, and are passed through to *all* functions, regardlass of how they are called.
 - No floating points.
