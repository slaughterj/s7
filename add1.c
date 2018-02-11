
#include <stdlib.h>

#include "add1.h"
#include "s7.h"

static s7_pointer add1(s7_scheme *sc, s7_pointer args)
{

  if (s7_is_integer(s7_car(args)))
  {
    return(s7_make_integer(sc, 1 + s7_integer(s7_car(args))));
  }
  return(s7_wrong_type_arg_error(sc, "add1", 1, s7_car(args), "an integer"));
}


void add1_init(s7_scheme *sc)
{
#if defined(_WIN32)
  s7_init(); /* Must add this or segfault when call small_int. For some reason small_ints is
			  * set back to NULL as if s7_init had never been called in main. Other
			  * globals may also be affected. Maybe something
			  * to do with the DLL and threading? Race condtion? */
#endif
  s7_define_function(sc, "add1", add1, 1, 0, false, "(add1 int) adds 1 to int");
}

/*** Mingw with clang ***
*   clang -target x86_64-w64-mingw64 -DDLL_EXPORT -c  s7.c -o s7.o -DWITH_MAIN -DUSE_SND=0
*	clang -target x86_64-w64-mingw64 -shared -o s7.dll s7.o -Wl,--out-implib,s7.a
*	clang -target x86_64-w64-mingw64 -c  add1.c -o add1.o 
*	clang -target x86_64-w64-mingw64 -shared -o add1.dll s7.o add1.o -Wl,-rpath=.,--out-implib,add1.a -ls7 -L.
*	clang -target x86_64-w64-mingw64 -o repl.exe s7.o   -Wl,-rpath=. -L.
*/


/* gcc -fpic -c add1.c
 * gcc -shared -Wl,-soname,libadd1.so -o libadd1.so add1.o -lm -lc
 * gcc s7.c -o repl -fpic -DWITH_MAIN -I. -ldl -lm -Wl,-export-dynamic -DUSE_SND=0
 * repl
 *   (load "libadd1.so" (inlet 'init_func 'add1_init))
 *   (add1 2)
 */
 
 