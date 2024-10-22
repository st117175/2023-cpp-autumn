#include <iostream>
#include <cstddef>  // size_t
#include <cstring>
#include <utility> 

struct String {
    public:
        String(const char *str = "");
        String(size_t n, char c);
        ~String();

        String(const String &other);
        String &operator=(const String &other);

        void append(const String &other);

        String operator[](int index);

        void print();  

    private:
        size_t size;
        char *str;

};