/*Title: CSC1310-Lab-7
  Author: Rus Hoffman
  Date: 10-24-2018*/
#include <fstream>
#include "Stack.h"
int main(){
	MyStack<char> stk;
	char buf;
	std::ifstream in("file1.txt");
	do{
		in.get(buf);
		stk.push(buf);
	}while(!in.eof());
	in.close();
	stk.pop();
	stk.pop();
	std::ofstream o("file2.txt");
	while(!stk.empty())
		o.put(stk.pop());
	o.close();
	return 0;
}
