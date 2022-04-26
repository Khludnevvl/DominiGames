#pragma once

#include <memory>
#include <string>
#include <map>

class PhoneBook {
    using Dict = std::multimap<std::string, std::string>;
public:
    static PhoneBook *getInstance();

    const Dict &getAllDict() const {
        return names_to_phone_;
    }

    Dict findByName(const std::string &str) const;

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

    Dict names_to_phone_;
};
