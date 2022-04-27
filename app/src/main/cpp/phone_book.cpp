#include "phone_book.hpp"
#include <algorithm>

PhoneBook* PhoneBook::book_ptr_ = nullptr;
PhoneBookDestroyer PhoneBook::destroyer_;

//return trimmed copy of str
std::string trimString(std::string str) {
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
}

PhoneBook *PhoneBook::getInstance() {
    if(book_ptr_ == nullptr){
        book_ptr_ = new PhoneBook();
        destroyer_.initialize(book_ptr_);
    }
    return book_ptr_;
}

void PhoneBook::addNewContact(std::string name, std::string phone) {
    if (trimString(name).empty())
        return;
    names_to_phone_.emplace(std::move(name), std::move(phone));
}

bool PhoneBook::findInclude(std::string text, std::string prefix) const {

    std::string trimmed_prefix = trimString(std::move(prefix));

    if (trimmed_prefix.empty()) {
        return true;
    }

    size_t text_pos = text.find_first_not_of(' ');
    size_t match = 0;

    for (; text_pos < text.size(); text_pos++) {
        if (std::tolower(text[text_pos]) == std::tolower(trimmed_prefix[match])) {
            match++;
        } else {
            match = 0;
            text_pos = text.find(' ', text_pos);
            text_pos = text.find_first_not_of(' ', text_pos) - 1;
            if (text_pos == std::string::npos)
                return false;
        }

        if (match == trimmed_prefix.size()) {
            return true;
        }
    }
    return false;
}

PhoneBook::Dict PhoneBook::findByName(const std::string &str) const {
    Dict result_dict;

    for (const auto &[name, phone] : names_to_phone_) {
        if (findInclude(name, str))
            result_dict.insert({name, phone});
    }
    return result_dict;
}

size_t PhoneBook::getBookSize() const {
    return names_to_phone_.size();
}

void PhoneBook::makeExamples() {
    names_to_phone_.emplace("Gosha", "+732131232131");
    names_to_phone_.emplace("AGosha", "+732131232131");
    names_to_phone_.emplace("Balance", "*102#");
    names_to_phone_.emplace("Misha", "+3211231231231");
    names_to_phone_.emplace("Misha", "+893123112312");
    names_to_phone_.emplace("Sasha", "89123123123123");
    names_to_phone_.emplace("Emergency", "112");
    names_to_phone_.emplace("Police", "02");
    names_to_phone_.emplace("MoM", "904534535343");
    names_to_phone_.emplace("DaD", "4002312131123");
    names_to_phone_.emplace("Brother", "23467354634534");
    names_to_phone_.emplace("John smith jr", "5555555555555");
    names_to_phone_.emplace("         to many spaces       ", "*102#");
    names_to_phone_.emplace("    to       many    spaces2    ", "100");
    names_to_phone_.emplace("      BAnk", "8800555555");
    names_to_phone_.emplace("Маша реснички", "88005553535");
    names_to_phone_.emplace("Wife", "9854544531");
}