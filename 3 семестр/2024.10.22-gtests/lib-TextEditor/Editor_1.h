#include <iostream>
#include <string>

class TextEditor
{
	private:
	std::string textBefore;
	std::string textAfter;

	public:
	TextEditor();
	~TextEditor();
	TextEditor(const TextEditor &t);
	TextEditor& operator= (const TextEditor &t);
	void addText(std::string text);
	void print();
	int deleteText(int k);
	std::string cursorLeft(int k);
	std::string cursorRight(int k);
	std::string GettextBefore();
};
