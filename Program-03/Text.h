#if !defined(TEXT_H)
#define TEXT_H

#include <iostream>
using namespace std;

class Text {
	private:
		const char* textArray;
		size_t textLength;

	public:
		
		/*
		 Function Name:  Text (constructor)
		 Parameters:  Send a pointer to a constant character array or a string literal to this function
		 Purpose:  called automatically when Text object is created, dynamically allocates a character array which
		 contains the character array passed to the function.
		 */
		Text(const char*);
		Text(string&);

		/*
		 Function Name:  ~Text (destructor)
		 Purpose: release dynamically allocated memory for the c-string in the Text object
		 */
		~Text();

		/*
		 Function Name:  displayText()
		 Parameters:  none
		 Returns:  none (void)
		 Purpose:  prints out the string (character array)
		 */
		void displayText() const;

		/*
		 Function Name:  getText() (accessor function)
		 Parameters:  none
		 Returns:  pointer to a constant character array
		 */
		string getString() const;
		const char* getText() const;

		/*
		 Function Name:  getLength() (accessor function)
		 Parameters:  none
		 Returns:  the length of the string
		 */
		size_t getLength() const;

		/*
		 Function Name:  editText()
		 Parameters:  pointer to a constant character array
		 Returns:  none
		 Purpose:  This function first deletes the DMA string that it was pointing to and then
		 dynamically allocates a new character array, places the c-string passed
		 to this function inside this new character array and then makes the textArray pointer
		 point to this new array.
		 */
		void editText(const char*);
		void editText(string);


};
//end of Text class

//Overload so that it is possible to use the text class directly with stream operators
std::ostream &operator<<(std::ostream &os, const Text &theText);
std::ostream &operator>>(std::ostream &os, const Text &theText);
//Overload for comparing alphabetical ordering

/*
bool operator==(Text &thisText, Text &otherText);
bool operator!=(Text &thisText, Text &otherText);
bool operator<(Text &thisText, Text &otherText);
bool operator>(Text &thisText, Text &otherText);
bool operator<=(Text &thisText, Text &otherText);
bool operator>=(Text &thisText, Text &otherText);
*/

#endif
