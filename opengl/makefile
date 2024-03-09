CC = g++
LDC = g++
LD_FLAGS = -std=c++20 -O2 -fopenmp -g
FLAGS = -std=c++20 -O2 -fopenmp -MMD -MP -g
NOWARN = -Wno-deprecated-declarations -Wno-enum-compare
PROG = prog.x
SRCDIR = src
OBJDIR = obj
BINDIR = bin
EXDIR = external/
RM = /bin/rm


#for logging library (if there is one)
ifdef LOGLEVEL
FLAGS:=$(FLAGS) -DLOGLEVEL=$(LOGLEVEL)
LD_FLAGS:=$(LD_FLAGS) -DLOGLEVEL=$(LOGLEVEL)
endif
#platform raylib library 
uname_p := $(shell uname -p)
uname_s := $(shell uname -s)
ifeq ($(uname_s),Darwin)
ifeq ($(uname_p),arm)
GLFWLIB=${EXDIR}GLFW/lib/libglfw3ARMmac.a
LDLIBS= -L./${EXDIR}GLFW/lib -lglfw3ARMmac
LDFRAMEWORKS = -framework CoreVideo -framework IOKit -framework Cocoa
else
GLFWLIB=${EXDIR}GLFW/lib/libglfw3x64mac.a
LDLIBS= -L./${EXDIR}GLFW/lib -lglfw3x64mac
LDFRAMEWORKS = -framework CoreVideo -framework IOKit -framework Cocoa
endif
else ifeq ($(uname_s),Linux)
GLFWLIB=${EXDIR}GLFW/lib/libglfw3x64linux.a
LDLIBS= -L./${EXDIR}GLFW/lib -lglfw3x64linux -ldl
LDFRAMEWORKS = 
endif
#using all of the above variables:
#setup generic vars for libraries, includes, and linker flags
INC=-I./ -I./${EXINCDIR} -I./${EXDIR}
LD_FLAGS:=${LD_FLAGS} $(LDLIBS)
#and setup all the needed files, objs, and sources
FILES = $(shell find $(SRCDIR)/*.cpp)
OBJS = $(FILES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
OBJS := $(OBJS) $(OBJDIR)/glad.o
DEPS = $(patsubst %.o,%.d,$(OBJS))

#get operating system using uname
OS := $(shell uname)



ifdef DEBUG
LD_FLAGS=-g -O0 -Wall -fopenmp -DDEBUG --std=c++23
CPPFLAGS=-g -O0 -Wall -fopenmp -DDEBUG --std=c++23
endif


ifdef LOGLEVEL
CPPFLAGS:=$(CPPFLAGS) -DLOGLEVEL=$(LOGLEVEL)
endif

GLADSRC=$(EXDIR)GLAD/src/glad.c
GLADINC=$(EXDIR)GLAD/include/

INC=-I$(GLADINC)
STAT= $(GLFWLIB)

LIBS= $(STAT)


#########
#RULES
#########

#all the phonys
.PHONY: all clean view

#default rule
all: $(PROG)

#link rule
$(PROG): $(OBJS)
	$(LDC) ${LIBS} $^ $(LD_FLAGS)  -o $(BINDIR)/$(PROG) $(LDFRAMEWORKS)

#rule fo compiling src and imgui src
$(OBJDIR)/%.o:$(SRCDIR)/%.cpp
	$(CC) -c $< $(FLAGS) $(INC) $(NOWARN) -o $@
$(OBJDIR)/%.o:$(IMGUIDIR)/%.cpp
	$(CC) -c $< $(FLAGS) $(INC) $(NOWARN) -o $@
$(OBJDIR)/glad.o:$(GLADSRC)
	$(CC) -c $< $(CPPFLAGS) $(INC) -o $@

#include all dependency rules from *.d files in OBJDIR
-include $(DEPS)


clean:
	-$(RM) $(OBJDIR)/*.o $(OBJDIR)/*.d $(BINDIR)/$(PROG) $(BINDIR)/*.ini $(PROG) 2>/dev/null || true
	
view:
	@echo $(FILES)
	@echo $(IMGUIFILES)
	@echo $(OBJS)
