# STLSoft-1.10-delta

## Update (April 2019)

**NOTE:** Users of **STLSoft** should now use the [latest beta](https://github.com/synesissoftware/STLSoft-1.10/releases) of [STLSoft, v 1.10](https://github.com/synesissoftware/STLSoft-1.10)

## Prior instructions

Git access to the final days/weeks/months of the delta-form of the 1.10.x versions of the [STLSoft](http://sourceforge.net/projects/stlsoft) libraries. STLSoft 1.12 is in preparation, and should be out by the end of 2015.

STLSoft 1.10 contains many new features, but has only ever been, and will only ever be, in the form of partial supplement (delta) improvements/enhancements to STLSoft 1.9. As such, if you want to use STLSoft 1.10 you must first/also use STLSoft 1.9 and use include path interpositioning to ensure that files from the STLSoft 1.10 delta distribution are seen before (and therefore override) any same named ones from your (complete) STLSoft 1.9 distribution.

On UNIX, this interpositioning might look like:

```$ g++ -I ~/downloads/STLSoft-1.10/delta/include -I ~/downloads/STLSoft/1.9/include . . .```

On Windows, it might look like:

```$ cl -I C:\3rdparty\downloads\STLSoft-1.10\delta\include -I C:\3rdparty\downloads\1.9\include . . .```

This is, obviously, a nasty hack, but it is reliable if done properly, and commercial software has been being built in this manner for a while. Naturally, STLSoft 1.12 will do away with all this nonsense.
