CXXFLAGS += -I ./ -std=c++98
CCFLAGS += -I ./ -std=c98

#Builds to pick from:
all		:	release



#C++ Compiler Flags
release	: CXXFLAGS += -O3
#C Compiler Flags
release : CCFLAGS  += -O3
release	: executable



#Debug settings:
debug	:	clean
#C++ Compiler Flags
#unused: -fno-access-control -Q
debug	:	CXXFLAGS += -DDEBUG -Wchar-subscripts -pedantic -g -Wmain -Wuninitialized -Wall -Wextra -fexceptions -O
#C Compiler Flags
debug	:	CCFLAGS  += -DDEBUG -Wchar-subscripts -pedantic -g -Wmain -Wuninitialized -Wall -Wextra -fexceptions -O

#debug 	:	clean
debug	:	executable

#Actual build requirments

#Cleanup! Deletes old exe and object files
clean	:	#program02.exe
		del *.o 
		del Program3.exe




#File dependencies and how they are created
#if any of the files listed has been altered since the last compile, generate a new .o file

#program02.exe : executable

Driver.o	:	Driver.cpp
				$(CXX) $(CXXFLAGS) -c Driver.cpp

Timer.o	:	Timer.cpp
				$(CXX) $(CXXFLAGS) -c Timer.cpp

Text.o	:	Text.cpp
				$(CXX) $(CXXFLAGS) -c Text.cpp

Movies.o	:	Movies.cpp
				$(CXX) $(CXXFLAGS) -c Movies.cpp

Movie.o	:	Movie.cpp
				$(CXX) $(CXXFLAGS) -c Movie.cpp
				
executable	:	Movie.o Movies.o Text.o Timer.o Driver.o 
			$(CXX) $(CXXFLAGS) -o Program3.exe Movie.o Movies.o Text.o Timer.o Driver.o 
				
				