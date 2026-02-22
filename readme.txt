
VML is a Register-based virtual machine. And it is a
  template there. It can use a array and the
  length of the array is 1024B as 1KB. It describe as
  "registers". Use it through make a
  std::array<ui8, registerSize>. Among, registerSize
  generally defined as 0x0400. Its realization is in
  ./libs/stddef.cpp.

Among, the VML is divided into BVML and CVML.
  In the fact, CVML has a exceptional function. It is 
  the CAPI. Enlargement of CAPI is "C Plusplus API".
  complie can provide an interface like stddef.h in C
  and algorithm in C++. I decided to let it name stdapi.
  For example of CAPI,
  
  import stdio as *;
  import stdapi as *;
  import stdstring as *;
  import stdarg as *;
  
  fn main(STDARG_FOR_MAIN)
  {
    println(f64tostring(sqrt(3)));
    ret 0;
  }
  Although actually, stdmath has the sqrt function too,
  it also import the stdapi. In the fact, the f64tostring is a stdapi
  too. CAPI let function execute into C Plusplus codes,
  There is no cost. Actually, CAPI can use
  most of variables in VML. It can make most of programs run faster.
