cmake_minimum_required(VERSION 3.0)

add_executable(test main.cpp lib-TextEditor/Editor_1.cpp lib-BankAccounts/Bank_.cpp lib-BankAccounts/BankAccount_.cpp)
target_link_libraries(test gtest pthread)
