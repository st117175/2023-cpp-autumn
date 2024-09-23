#include <iostream>
#include <string>
using namespace std;

class TextEditor
{
	private:
	string textBefore;
	string textAfter;

	public:
	TextEditor()
	{
	string textBefore = "";
	string textAfter = "";
	}

	~TextEditor()
	{
		textBefore.clear();
		textAfter.clear(); 
	}

	TextEditor(const TextEditor &t)
	{
		textBefore = t.textBefore;
		textAfter = t.textAfter;
	}

	TextEditor& operator= (const TextEditor &t)
	{
		textBefore = t.textBefore;
		textAfter = t.textAfter;
		return *this;
	}

	void addText(string text)
	{
	textBefore += text;
	}

	void print()
	{
	std::cout << textBefore << "|";
	for(int i = textAfter.length(); i > 0; --i)
	{
	std::cout << textAfter[i - 1];
	}
	std::cout << std::endl;
	}

	int deleteText(int k)
	{
	textBefore.erase(textBefore.length() - k);
	return k;
	}

	string cursorLeft(int k)
	{
		string cursorLef_t;
		cursorLef_t.resize(k);
		int sizeTextAfter = textAfter.length();
		int sizeTextBefore = textBefore.length();
		textAfter.resize(k + sizeTextAfter);
		for(int i = 0; i < k; ++i)
		{
			textAfter[i + sizeTextAfter] = textBefore[sizeTextBefore - i - 1];
		}
		for(int j = 0; j < k; ++j)
	    {
	    cursorLef_t[j] = textAfter[textAfter.length() - j - 1];
	    }
		deleteText(k);
		return cursorLef_t;
	}

	string cursorRight(int k)
	{
		string cursorRigh_t;
		int sizeTextAfter = textAfter.length();
		int sizeTextBefore = textBefore.length();
		textBefore.resize(sizeTextBefore + k);
		for(int i = 0; i < k; ++i)
		{
			textBefore[sizeTextBefore + i] = textAfter[sizeTextAfter - i - 1];
		}
		cursorRigh_t.resize(k);
		for(int j = 0; j < k; ++j)
		{
			cursorRigh_t[j] = textBefore[textBefore.length() - k + j];
		}
		textAfter.erase(sizeTextAfter - k);
		return cursorRigh_t;
	}

};