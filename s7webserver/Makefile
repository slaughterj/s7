
release:
	clang -target x86_64-w64-mingw64 -DDLL_EXPORT -c  s7.c -o s7.o -DWITH_MAIN -DUSE_SND=0
	clang -target x86_64-w64-mingw64 -shared -o s7.dll s7.o -Wl,--out-implib,s7.a
	clang -target x86_64-w64-mingw64 -c  add1.c -o add1.o 
	clang -target x86_64-w64-mingw64 -shared -o add1.dll s7.o add1.o -Wl,-rpath=.,--out-implib,add1.a -ls7 -L.
	clang -target x86_64-w64-mingw64 -o repl.exe s7.o   -Wl,-rpath=. -L.
	
debug:
	clang -target x86_64-w64-mingw64 -DDLL_EXPORT -c -g s7.c -o s7.o -DWITH_MAIN -DUSE_SND=0
	clang -target x86_64-w64-mingw64 -shared -o s7.dll s7.o -Wl,--out-implib,s7.a
	clang -target x86_64-w64-mingw64 -c -g add1.c -o add1.o 
	clang -target x86_64-w64-mingw64 -shared -o add1.dll s7.o add1.o -Wl,-rpath=.,--out-implib,add1.a -ls7 -L.
	clang -target x86_64-w64-mingw64 -o repl.exe s7.o   -Wl,-rpath=. -L.
	
clean:
	del *.o
	del *.dll
	del *.a
	del repl.exe
	
	
.PHONY: clean
.PHONY: release
.PHONY: debug