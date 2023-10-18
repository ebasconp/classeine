
CXX = g++
CXXFLAGS = -O0 -g3
OUTPUT = -o
OUTPUTFILES = ../bin/debug/classeine-demo
CLASSEINELIBPATH = classeine-lib
RM = rm -Rf

INPUTFILES = \
	classeine-lib/clsn/gfx/Dimension.cpp \
	\
	classeine-lib/clsn/ui/Control.cpp \
	\
	classeine-demo/Main.cpp

INCLUDEDIRCMD = -I
INCLUDEDIRS = $(INCLUDEDIRCMD)$(CLASSEINELIBPATH)

all:
	$(CXX) $(CXXFLAGS) $(INPUTFILES) $(INCLUDEDIRS) $(OUTPUT) $(OUTPUTFILES)

clean:
	$(RM) $(OUTPUTFILES)

run: all
	$(OUTPUTFILES)