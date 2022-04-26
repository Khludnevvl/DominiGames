#include "phone_book.hpp"

#include <algorithm>

PhoneBook* PhoneBook::book_ptr_ = nullptr;

PhoneBook *PhoneBook::getInstance() {
    if(book_ptr_ == nullptr){
        book_ptr_ = new PhoneBook();
    }
    return book_ptr_;
}

void PhoneBook::addNewContact(std::string name, std::string phone) {
    names_to_phone_.emplace(std::move(name), std::move(phone));
}

PhoneBook::Dict PhoneBook::findByName(const std::string &str) const {
    Dict result_dict;

    for (const auto &[name, phone] : names_to_phone_) {
        if (name.find(str) != std::string::npos){
            result_dict.insert({name,phone});
        }
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