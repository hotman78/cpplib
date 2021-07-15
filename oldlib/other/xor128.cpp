unsigned long xor128() {
  static unsigned long x=123456789, y=362436069, z=521288629, w=88675123;
  unsigned long t=(xˆ(x<<11));
  x=y; y=z; z=w;
  return ( w=(wˆ(w>>19))ˆ(tˆ(t>>8)) );
}