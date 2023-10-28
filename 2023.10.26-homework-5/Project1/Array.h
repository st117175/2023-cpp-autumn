#pragma once
#include <iostream>

void printMenu();
void unwrapArray(int*& a, int& tyu);
void printArray(int* a, int& tyu);
void addElement(int*& a, int& tyu, int newElement);
void expandArray(int*& a, int& tyu);
void deleteElement(int*& a, int& tyu, int& num);
void ascending(int*& a, int& tyu);
int searchMin(int* a, int& tyu);
int searchMax(int* a, int& tyu);
void changeMaxMin(int*& a, int& tyu);
void deleteDuplicate(int*& a, int& tyu);
void addRandomElements(int*& a, int& tyu, int count);
