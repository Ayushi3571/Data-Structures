#include <iostream>
#include <fstream>
#include <map>
#include <string>

struct Book {
    std::string title;
    std::string author_first;
    std::string author_last;
    int word_count;
    std::map<char, double> letter_frequency;
    int line_count;
};

int main() {
    while (true) {
        std::string filename;
        std::cout << "Enter the name of the file to be processed: ";
        std::cin >> filename;

        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cout << "Error opening file, please try again." << std::endl;
            continue;
        }

        Book book;
        std::string line;
        int word_count = 0;
        std::map<char, int> letter_count;
        int line_count = 0;
        while (std::getline(file, line)) {
            ++line_count;
            for (char c : line) {
                if (isalpha(c)) {
                    ++letter_count[tolower(c)];
                }
                if (c == ' ') {
                    ++word_count;
                }
            }
        }
        file.close();

        book.line_count = line_count;
        book.word_count = word_count + line_count; // +1 for last word in the file
        int total_letter_count = 0;
        for (auto& pair : letter_count) {
            total_letter_count += pair.second;
        }
        for (auto& pair : letter_count) {
            book.letter_frequency[pair.first] =
                (double)pair.second / total_letter_count * 100;
        }
        file.open(filename);
        std::string line2;

        // Extract the title and author information from the file name
        std::getline(file, line2);
        book.title = line2;
        std::getline(file, line2);
        std::size_t first_space = line2.find(' ');
        book.author_first = line2.substr(0, first_space);
        std::size_t second_space = line2.find(' ', first_space + 1);
        book.author_last = line2.substr(first_space + 1, second_space - first_space - 1);


        std::ofstream catalog("CardCatalog.txt", std::ios::app);
        catalog << "Title: " << book.title << std::endl;
        catalog << "Full Author: " << book.author_first << " " << book.author_last << std::endl;
        catalog << "Author First Name: " << book.author_first << std::endl;
        catalog << "Author Last Name: " << book.author_last << std::endl;
        catalog << "Word count: " << book.word_count << std::endl;
        catalog << "Line count: " << book.line_count << std::endl << std::endl;
        catalog.close();

        std::cout << "Do you want to see the letter frequency (y/n)? ";
        char answer;
        std::cin >> answer;
        if (answer == 'y') {
            std::cout << book.title << " letter frequency:" << std::endl;
            for (auto& pair : book.letter_frequency) {
                std::cout << pair.first << ": " << pair.second << "%" << std::endl;
            }
        }

        std::cout << "Do you wish to process another book (y/n)? ";
        std::cin >> answer;
        if (answer != 'y') break;
    }
    return 0;
}