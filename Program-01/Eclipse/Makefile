CPPFLAGS += -I ./ -std=c++98
CXXFLAGS += -I ./ -std=c++11
CCFLAGS += -I ./ -std=c11

#Builds to pick from:
all		:	release
#Program-01-Movies.exe : executable
executable	:	Driver.o Movies.o Movie.o Text.o
			$(CXX) $(CXXFLAGS) -o Program-01-Movies.exe Driver.o Movies.o Movie.o Text.o

#C++ Compiler Flags
release	: CXXFLAGS += -O3
#C Compiler Flags

release : CCFLAGS  += -O3
release	: executable

#Debug settings:
#C and C++ Preprocessor flags
#C++ Compiler Flags
#unused: -fno-access-control -Q
debug	:	CXXFLAGS += -DDEBUG -Wchar-subscripts -pedantic -g -Wmain -Wuninitialized -Wall -Wextra -fexceptions -O
#C Compiler Flags
debug	:	CCFLAGS  += -DDEBUG -Wchar-subscripts -pedantic -g -Wmain -Wuninitialized -Wall -Wextra -fexceptions -O

debug	:	executable



#Cleanup! Deletes old exe and object files
clean	:	#Program-01-Movies.exe
		del *.o 
		del Program-01-Movies.exe



#File dependencies and how they are created
#if any of the files listed has been altered since the last compile, generate a new .o file
Driver.o	:	Driver.cpp
				$(CXX) $(CXXFLAGS) -c Driver.cpp
				
				
Movies.o	:	Movies.cpp
				$(CXX) $(CXXFLAGS) -c Movies.cpp
				
				
Movie.o	:	Movie.cpp
				$(CXX) $(CXXFLAGS) -c Movie.cpp
				
				
Text.o	:	Text.cpp
				$(CXX) $(CXXFLAGS) -c Text.cpp
				