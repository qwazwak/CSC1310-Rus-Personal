#this is a comment

all			:		KrustyKrab

KrustyKrab	:		BinaryTree_KK.o KrustyKrab.o 
					g++ -std=c++11 -o KrustyKrab.exe BinaryTree_KK.o KrustyKrab.o

#here is how to generate the .o file
#if any of the files listed has been altered since the last compile, generate a new .o file
BinaryTree_KK.o	:	BinaryTree_KK.cpp
					g++ -std=c++11 -I ./ -c BinaryTree_KK.cpp
				
KrustyKrab.o	:	KrustyKrab.cpp
					g++ -std=c++11 -I ./ -c KrustyKrab.cpp
		

clean			:	KrustyKrab.exe
					del *.o 
					del KrustyKrab.exe