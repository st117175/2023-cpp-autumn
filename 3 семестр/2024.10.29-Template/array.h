#include <iostream>

template <class T>
class Array
{
private:
    static const int size = 5;
    T array[size];

public:
    Array() {}
    Array(T* b); 
    void show(); 
    T minimum();    
    T minimum(Array<T>& other);
};

template <class T>
Array<T>::Array(T* b) 
{
    for (int i = 0; i < size; ++i) {
        array[i] = b[i];
    }
}

template <class T>
void Array<T>::show() 
{
    std::cout << "[";
    for (int i = 0; i < size; ++i) 
    {
        std::cout << array[i];
        if (i < size - 1) 
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

template <class T>
T Array<T>::minimum() 
{
    if(size == 0)
    {
        std::cout << "empty" << std::endl;
    } 
    T min_val = array[0];
    for(int i = 1; i < size; ++i)
    {
        if(array[i] < min_val)
        {
            min_val = array[i];
        }
    }
    return min_val;
}

template <class T>
T Array<T>::minimum(Array<T>& other)
{
    T min_val = (*this).minimum();
    T other_min = other.minimum();
    return min_val < other_min ? min_val : other_min;
}