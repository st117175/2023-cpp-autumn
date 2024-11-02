#include "Editor_1.h"


TextEditor::TextEditor()
{
	std::string textBefore = "";
	std::string textAfter = "";
}

TextEditor::~TextEditor()
{
	textBefore.clear();
	textAfter.clear(); 
}

TextEditor::TextEditor(const TextEditor &t)
{
	textBefore = t.textBefore;
	textAfter = t.textAfter;
}

TextEditor& TextEditor::operator= (const TextEditor &t)
{
	textBefore = t.textBefore;
	textAfter = t.textAfter;
	return *this;
}

std::string TextEditor::GettextBefore()
{
	return textBefore;
}

void TextEditor::addText(std::string text)
{
	textBefore += text;
}

void TextEditor::print()
{
	std::cout << textBefore << "|";
	for(int i = textAfter.length(); i > 0; --i)
	{
	std::cout << textAfter[i - 1];
	}
	std::cout << std::endl;
}

int TextEditor::deleteText(int k)
{
	if(k > textBefore.length())
	{
		textBefore.erase(0);
		return textBefore.length();
	}
	else
	{
		textBefore.erase(textBefore.length() - k);
		return k;
	}
}

std::string TextEditor::cursorLeft(int k)
{
	if(k > textBefore.length())
	{
		return (*this).cursorLeft(textBefore.length());
	}

	else
	{
		int sizeTextAfter = textAfter.length();
		int sizeTextBefore = textBefore.length();
		textAfter.resize(k + sizeTextAfter);
		for(int i = 0; i < k; ++i)
		{
			textAfter[i + sizeTextAfter] = textBefore[sizeTextBefore - i - 1];
		}
		deleteText(k);
		return textBefore;
	}
}

std::string TextEditor::cursorRight(int k)
{
	int sizeTextAfter = textAfter.length();
	int sizeTextBefore = textBefore.length();
	textBefore.resize(sizeTextBefore + k);
	for(int i = 0; i < k; ++i)
	{
		textBefore[sizeTextBefore + i] = textAfter[sizeTextAfter - i - 1];
	}
	textAfter.erase(sizeTextAfter - k);
	return textAfter;
}	
