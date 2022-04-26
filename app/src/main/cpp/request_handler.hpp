#pragma once
#include "json.hpp"
#include "phone_book.hpp"
#include <map>

using nlohmann::json;

class RequestHandler {
    using Dict = std::multimap<std::string, std::string>;

public:
    // return std::string in JSON style
    std::string getFoundNames(std::string name);
    // return std::string in JSON style
    std::string getFullDictionary();

    void addNewContact(std::string name, std::string phone);

private:
    // convert phonebook to std::string in JSON style
    std::string dictToJSONString(Dict dictionary);
};
