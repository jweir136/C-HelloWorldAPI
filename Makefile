build:
	g++ $(CPPFLAGS) $(CFLAGS) -I. HelloWorldAPI/*.cpp -o app

check:
	g++ $(CPPFLAGS) $(CFLAGS) -I. test/*.test.cpp -o test/testapp
	./test/testapp
	rm ./test/testapp
run:
	g++ $(CPPFLAGS) $(CFLAGS) --std=c++17 -I. HelloWorldAPI/*.cpp -o app -lserved
	./app
docs:
	doxygen doc/Doxygen