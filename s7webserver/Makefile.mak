
all:
	clang-mingw -c s7.c -o s7.o
	clang-mingw -shared -o s7.dll s7.o -Wl,--out-implib,s7.a
	clang-mingw -c add1.c -o add1.o
	clang-mingw -shared -o add1.dll s7.o add1.o -Wl,-rpath=.,--out-implib,add1.a -ls7 -L.
	
clean:
	del *.o
	del *.dll
	del *.a
	
	
.PHONY: clean
.PHONY: all