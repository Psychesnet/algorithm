SRCS := QuickSort.cpp MergeSort.cpp InsertSort.cpp BubbleSort.cpp \
	SelectSort.cpp
TARGETS := $(SRCS:%.cpp=%)

.PHONY: all clean
all: $(TARGETS)

CC=g++
CXX=g++
CFLAGS+=-std=c++11 -Wall
LDFLAGS+=-lstdc++

%.d: %.c
	$(CC) -MM $(CFLAGS) $< | sed -re 's,^.*:,$*.o $*.d:,g' > $@
%.d: %.cpp
	$(CXX) -MM $(CFLAGS) $< | sed -re 's,^.*:,$*.o $*.d:,g' > $@
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
%.o: %.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

DEPENDS := $(SRCS:%.c=%.d)
DEPENDS := $(DEPENDS:%.cpp=%.d)
ifneq ($(MAKECMDGOALS),clean)
-include $(DEPENDS)
endif

clean:
	rm -f *.d *.o
