
CC := g++

SOURCE	:= $(wildcard *.c) $(wildcard *.cpp)
OBJS	:= $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

#$(warning SOURCE=$(SOURCE))

TARGET	:= test

DEFINES :=

LIBS	:= -L.
INCLUDE := -I.

LDFLAGS :=
CFLAGS	:= -std=c++17 -Wall $(DEFINES) $(INCLUDE)

DEBUG=n
CONV=n

ifeq ($(DEBUG),y)
	CFLAGS += -g -O0
else
	CFLAGS += -O3
endif

ifeq ($(CONV),y)
	INCLUDE+= -I /usr/local/libiconv/include
	LIBS+= -L /usr/local/libiconv/lib

	CFLAGS += -fprofile-arcs -ftest-coverage
	LDFLAGS += -lgcov
endif

CXXFLAGS:= $(CFLAGS) -DHAVE_CONFIG_H

 #$(warning OBJS=$(OBJS))

.PHONY : everything objs clean veryclean rebuild

everything : $(TARGET)

all : $(TARGET)

objs : $(OBJS)

rebuild: veryclean everything

clean:
	rm -fr $(TARGET) $(OBJS)

veryclean : clean
	rm -rf *.so *.gcno *.gcda

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)

