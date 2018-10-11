CPPFLAGS += -I ./ -std=c++98
CXXFLAGS += -I ./ -std=c++98
CCFLAGS += -I ./ -std=c98

#Builds to pick from:
all		:	release



#C++ Compiler Flags
release	: CXXFLAGS += -O3
#C Compiler Flags
release : CCFLAGS  += -O3
release	: Program2.exe



#Debug settings:
#C++ Compiler Flags
#unused: -fno-access-control -Q
debug	:	CXXFLAGS += -DDEBUG -Wchar-subscripts -pedantic -g -Wmain -Wuninitialized -Wall -Wextra -fexceptions -O
#C Compiler Flags
debug	:	CCFLAGS  += -DDEBUG -Wchar-subscripts -pedantic -g -Wmain -Wuninitialized -Wall -Wextra -fexceptions -O

debug 	:	clean
debug	:	Program2.exe



#Cleanup! Deletes old exe and object files
clean	:	#program02.exe
		del *.o 
		del Program2.exe




#File dependencies and how they are created
#if any of the files listed has been altered since the last compile, generate a new .o file

#program02.exe : executable
Program2.exe	:	Program2.o
			$(CXX) $(CXXFLAGS) -o Program2.exe Program2.o

Program2.o	:	Program2.cpp
				$(CXX) $(CXXFLAGS) -c Program2.cpp
				
				