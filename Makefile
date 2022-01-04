path_to_project = "/Users/wildmac/stuff/github/Pigne"
name = pigne
exec = lib$(name).so
test_exec = test.out
flags = -g -Wall -lm -ldl -fPIC -rdynamic -framework "OpenGL" -framework "GLUT"

tests_files := $(shell find test/ -name *.cpp)
source_files := $(shell find src/ -name *.cpp)
objects_files := $(patsubst src/%.cpp, build/%.o, $(source_files))
tests_objects_files := $(patsubst test/%.cpp, build/test/%.o, $(tests_files))

$(objects_files): build/%.o : src/%.cpp
	mkdir -p $(dir $@) && \
	g++ -arch x86_64 -c -I inc $(patsubst build/%.o, src/%.cpp, $@) -o $@

$(tests_objects_files): build/test/%.o : test/%.cpp
	mkdir -p $(dir $@) && \
	g++ -arch x86_64 -c -I inc $(patsubst build/test/%.o, test/%.cpp, $@) -o $@

clean:
	-rm -rf build && \
	mkdir build

run_test: build $(tests_objects_files)
	g++ -arch x86_64 -I inc -L$(path_to_project) -l$(name) $(tests_objects_files) -o $(test_exec)

all: clean build

build: $(objects_files)
	g++ -arch x86_64 -shared -o $(exec) $(objects_files) $(flags)
