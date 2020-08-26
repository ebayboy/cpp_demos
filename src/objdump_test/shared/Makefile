
TARGET := libtest.so

CC		:= g++

DEFINES :=

INCLUDE := -I.
LIBS	:= -L.

LDFLAGS := -shared
CFLAGS	:= -fPIC -Wall $(DEFINES) $(INCLUDE)

DEBUG=n
CONV=n

ifeq ($(DEBUG),y)
	CFLAGS += -g2 -O0
else
	CFLAGS += -O2
endif

ifeq ($(CONV),y)
	INCLUDE+= -I /usr/local/libiconv/include
	LIBS+= -L /usr/local/libiconv/lib

	CFLAGS += -fprofile-arcs -ftest-coverage
	LDFLAGS += -lgcov
endif

CXXFLAGS:= $(CFLAGS) -DHAVE_CONFIG_H

SOURCE	:= $(wildcard *.c) $(wildcard *.cpp)
OBJS	:= $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

#$(warning SOURCE=$(SOURCE))

.PHONY : everything objs clean veryclean rebuild

everything : $(TARGET)

all : $(TARGET)

objs : $(OBJS)

rebuild: veryclean everything

clean :
	rm -fr *.o 

veryclean : clean
	rm -fr $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)


