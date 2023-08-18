TARGET := k-uniform-enumerator

CLANGPP := clang++-13
MODULES := $(wildcard *.cppm)
SRCS := $(wildcard *.cpp)

all: $(TARGET)
.PHONY: all

$(TARGET): $(MODULES:.cppm=.pcm) $(SRCS:.cpp=.o)
	$(CLANGPP) -o $@ $^
%.pcm: %.cppm
	$(CLANGPP) -std=c++20 -fprebuilt-module-path=. -MMD -MF $@.d --precompile -x c++-module -o $@ $<
main.o: main.cpp $(MODULES:.cppm=.pcm)
	$(CLANGPP) -std=c++20 -fprebuilt-module-path=. -MMD -MF $@.d -c -o $@ $<

define DEFINE_MODULE_RULES
$(1).%.o: $(1).%.cpp $(1).pcm
	$$(CLANGPP) -std=c++20 -fprebuilt-module-path=. -MMD -MF $$@.d -c -o $$@ -fmodule-file=$(1).pcm $$<
endef
$(foreach i,$(MODULES:.cppm=),$(eval $(call DEFINE_MODULE_RULES,$(i))))
%.o: $(MODULES:.cppm=.pcm)
polygon.pcm: types.pcm

.PHONY: clean
clean:
	rm -f *.o *.d *.pcm $(TARGET)

include $(wildcard *.d)
