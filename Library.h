#pragma once
#include "Book.h"
#include <vector>
#include <string>
#include <fstream>

class Library {
public:
    void addBook(const std::string& title, const std::string& author, int year);
    void saveToFile(std::ofstream& outFile) const; // Исправлено: передача ссылки на ofstream

private:
    std::vector<Book> books;
};
