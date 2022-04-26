#include "request_handler.hpp"
#include <string>


std::string RequestHandler::getFoundNames(std::string name) {
    PhoneBook* phoneBook  = PhoneBook::getInstance();
    Dict result_dict = phoneBook->findByName(std::move(name));
    return dictToJSONString(std::move(result_dict));;
}

std::string RequestHandler::getFullDictionary() {
    PhoneBook* phoneBook = PhoneBook::getInstance();
    Dict result_dict = phoneBook->getAllDict();
    return dictToJSONString(std::move(result_dict));;
}

void RequestHandler::addNewContact(std::string name, std::string phone){
    PhoneBook* phoneBook  = PhoneBook::getInstance();
    phoneBook->addNewContact(std::move(name), std::move(phone));
}

std::string  RequestHandler::dictToJSONString(Dict dictionary) {
    json main_dict;
    if (dictionary.size() == 0) {
        main_dict = json::array();
    }
    for (const auto &[name, phone] : dictionary) {
        json cur_contact;
        cur_contact["name"] = name;
        cur_contact["phone"] = phone;
        main_dict.push_back(cur_contact);
    }

    return main_dict.dump();
}