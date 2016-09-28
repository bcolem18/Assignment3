all: hello-cpp-world hello-c-world Assign3

%: %.cc
	g++ -std=c++11 $< -o $@

%: %.c
	gcc $< -o $@

