# VML


# What is the VML?

## What kinds name do VML have?
### BVML (Basic Virtual Machine Language).
### CVML (Complex Virtual Machine Language).

## What the CVML has more than the BVML?
## First: CAPI is important.
- The CAPI is an important part of the CVML.
  *Do not try to use the CAPI to commit sabotage.*

The CAPI isn't too safe in most cases. And In special cases, it even can cause large problems. But the CAPI is very useful and can make the programs fast.

## Second: Full name of the CAPI.
CAPI look like C language API, just like Python3. But actually, Full name of CAPI is "C Plusplus API".

## How should the languages compiler?
Actually, The languages compiler the code into "compile of VML" first.
compile of VML is a compile like x86_64 Compile. Many codes are a symbol of many bytes. The VML Virtual Machine can get the bytes and execute them. Most of the time, There is a file on your OS.

Then the compile of VML can open the file and translate it into bytes. When this compile start translation, it is very slow. Because the compile need to deal with many things. For example:

```vmlcompile
start:
 mov8 #6 r0
 mov8 #7 r1
 add88 r0 r1
 ret

```

compile needs to let it has a data field. It means:

```vmlcompilemid
start:
 mov8 #a r0
 mov8 #b r1
 add88 r0 r1
 ret

#:
 as a 6
 as b 7.

```

- if you want to read more, please read readme.txt
