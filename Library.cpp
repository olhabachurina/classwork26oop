#include "Library.h"
#include <fstream>
#include <stdexcept>

void Library::addBook(const std::string& title, const std::string& author, int year) {
    if (year <= 0) {
        throw std::invalid_argument("Invalid year. Year must be a positive number.");
    }

    Book newBook(title, author, year);
    books.push_back(newBook);
}

void Library::saveToFile(std::ofstream& outFile) const { // Исправлено: принимаем ссылку на ofstream
    if (!outFile) {
        throw std::runtime_error("Error opening the file.");
    }

    for (const auto& book : books) {
        outFile << book.getTitle() << "," << book.getAuthor() << "," << book.getYear() << "\n";
    }
}