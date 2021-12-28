name = pigne
exec = build/$(name).out
flags = -g -Wall -lm -ldl -fPIC -rdynamic -framework "OpenGL" -framework "GLUT"

source_files := $(shell find src/ -name *.cpp)
objects_files := $(patsubst src/%.cpp, build/%.o, $(source_files))

$(objects_files): build/%.o : src/%.cpp
	mkdir -p $(dir $@) && \
	g++ -c -I inc $(patsubst build/%.o, src/%.cpp, $@) -o $@

.PHONY: build
build: $(objects_files)
	g++ $(objects_files) $(flags) -o $(exec)

