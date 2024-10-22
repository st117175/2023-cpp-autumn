#include "Editor1.h"


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
	textBefore.erase(textBefore.length() - k);
	return k;
}

std::string TextEditor::cursorLeft(int k)
{
	std::string cursorLef_t;
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

std::string TextEditor::cursorRight(int k)
{
	std::string cursorRigh_t;
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
