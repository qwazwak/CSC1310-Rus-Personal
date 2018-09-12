CPPFLAGS += -I ./ -std=c++98
CXXFLAGS += -I ./ -std=c++98
CCFLAGS += -I ./ -std=c98

#Builds to pick from:
all		:	release
executable	:	Driver.o Movies.o Movie.o Text.o
			$(CXX) -o Program-01-Movies.exe Driver.o Movies.o Movie.o Text.o

#C++ Compiler Flags
release	: CXXFLAGS += -03
#C Compiler Flags

release : CCFLAGS  += -O3
release	: executable

#Debug settings:
#C and C++ Preprocessor flags
#C++ Compiler Flags
debug	:	CXXFLAGS += -DDEBUG -g -fno-access-control -pedantic -Wchar-subscripts -Wmain -Wuninitialized -Wall -Wextra -g -Q -O -fexceptions
#C Compiler Flags
debug	:	CCFLAGS  += -DDEBUG -g -fno-access-control -pedantic -Wchar-subscripts -Wmain -Wuninitialized -Wall -Wextra -g -Q -O -fexceptions

debug	:	executable



#Cleanup! Deletes old exe and object files
clean	:	Program-01-Movies.exe
		del *.o 
		del Program-01-Movies.exe



#File dependencies and how they are created
#if any of the files listed has been altered since the last compile, generate a new .o file
Driver.o	:	Driver.cpp
				$(CXX) -c Driver.cpp
				
				
Movies.o	:	Movies.cpp
				$(CXX) -c Movies.cpp
				
				
Movie.o	:	Movie.cpp
				$(CXX) -c Movie.cpp
				
				
Text.o	:	Text.cpp
				$(CXX) -c Text.cpp
				