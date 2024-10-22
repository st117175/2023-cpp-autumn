#include "Editor1.h"

int main()
{
	TextEditor editor;
	editor.addText("hello world");
	editor.print();
	editor.cursorLeft(5);
	editor.print();
	editor.addText("Andrey");
	editor.print();
	editor.cursorRight(5);
	editor.print();
	editor.deleteText(5);
	editor.print();
}
