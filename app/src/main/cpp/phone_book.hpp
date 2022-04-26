#pragma once

#include <memory>
#include <string>
#include <map>

class PhoneBookDestroyer;

class PhoneBook {
    using Dict = std::multimap<std::string, std::string>;
public:
    static PhoneBook *getInstance();
    const Dict &getAllDict() const {
        return names_to_phone_;
    }

    void addNewContact(std::string name, std::string phone);
    Dict findByName(const std::string &str) const;
    size_t getBookSize() const;

protected:
    PhoneBook() {
        makeExamples();
    }

    PhoneBook(const PhoneBook &) = delete;
    PhoneBook(PhoneBook &&) = delete;

    PhoneBook &operator=(const PhoneBook &) = delete;
    PhoneBook &operator=(PhoneBook &&) = delete;

    ~PhoneBook() {};

private:
    void makeExamples();

    static PhoneBook *book_ptr_;
    static PhoneBookDestroyer destroyer_;

    friend class PhoneBookDestroyer;


    Dict names_to_phone_;

};

class PhoneBookDestroyer {
public:
    ~PhoneBookDestroyer() {
        delete book_ptr_;
    }

    void initialize(PhoneBook *book_ptr) {
        book_ptr_ = book_ptr;
    }

private:
    PhoneBook *book_ptr_;
};