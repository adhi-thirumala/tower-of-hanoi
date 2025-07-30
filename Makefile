CXX=clang
CXXFLAGS=-std=c23 -Wall -Wextra -Werror -pedantic -g -O2
INCLUDES=-I./include
# gets sources from src directory
SOURCES=$(wildcard src/*.c)

exec: out/tower-of-hanoi

out/tower-of-hanoi: $(SOURCES)
	@mkdir -p out
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^



clean:
	rm -rf out/*
