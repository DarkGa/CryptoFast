all:
	gcc -o cryptor src/cryptor.cpp -lstdc++
	install cryptor ~/../usr/bin/
	rm cryptor
