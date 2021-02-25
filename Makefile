CXXFLAGS=-g -std=c++11 -Wall -Wshadow -Wconversion -pedantic -I .

test: test.cpp prefix.o postfix.o
	${CXX} ${CXXFLAGS} -o $@ $^ -lgtest -lgtest_main -lpthread

prefix.o: prefix.cpp prefix.hpp operators.hpp
postfix.o: postfix.cpp postfix.hpp operators.hpp

clean:
	rm -f fixcalc test prefix.o postfix.o
