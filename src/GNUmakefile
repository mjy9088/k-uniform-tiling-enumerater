TARGET := k-uniform-enumerator

CLANGPP := clang++
MODULES := $(wildcard *.cppm)
SRCS := $(wildcard *.cpp)

all: $(TARGET)
.PHONY: all

$(TARGET): $(MODULES:.cppm=.pcm) $(SRCS:.cpp=.o)
	$(CLANGPP) -o $@ $^
%.o: %.cpp
	$(CLANGPP) -std=c++20 -fprebuilt-module-path=. -MMD -MF $@.d -c -o $@ $^
%.pcm: %.cppm
	$(CLANGPP) -std=c++20 -fprebuilt-module-path=. -MMD -MF $@.d --precompile -x c++-module -o $@ $<

.PHONY: clean
clean:
	rm -f *.o *.d *.pcm $(TARGET)

include $(wildcard *.d)
