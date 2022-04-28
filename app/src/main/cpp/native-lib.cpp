#include <jni.h>
#include <string>

#include "request_handler.hpp"

extern "C" JNIEXPORT jstring JNICALL
Java_com_domini_phone_1book_MainActivity_getAllContacts(
        JNIEnv* env,
        jobject /* this */) {
    RequestHandler handler;
    std::string allContacts = handler.getFullDictionary();
    return env->NewStringUTF(allContacts.c_str());
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_domini_phone_1book_MainActivity_getContactsByName(
        JNIEnv* env,
        jobject /* this */, jstring name){
    RequestHandler handler;
    const std::string cpp_name = std::string{env->GetStringUTFChars(name, nullptr)};
    std::string foundContacts = handler.getFoundNames(std::move(cpp_name));
    return env->NewStringUTF(foundContacts.c_str());
}
extern "C" JNIEXPORT void JNICALL
Java_com_domini_phone_1book_AddContactActivity_addNewContact(
        JNIEnv* env,
        jobject /* this */, jstring name, jstring phone){
    RequestHandler handler;
    const std::string cpp_name = std::string{env->GetStringUTFChars(name, NULL)};
    const std::string cpp_phone = std::string{env->GetStringUTFChars(phone, NULL)};
    handler.addNewContact(std::move(cpp_name), std::move(cpp_phone));
}
