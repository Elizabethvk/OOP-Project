#include "JSONCheck/JSONCheck.hpp"

int main() {
    JsonCheck testClass;
    // string testStr = "{\"menu\": {\
    //                     \"id\": \"file\",\
    //                     \"value\": \"File\",\
    //                     \"popup\": {\
    //                         \"menuitem\": [\
    //                         {\"value\": \"New\", \"onclick\": \"CreateNewDoc()\"},\
    //                         {\"value\": \"Open\", \"onclick\": \"OpenDoc()\"},\
    //                         {\"value\": \"Close\", \"onclick\": \"CloseDoc()\"}\
    //                         ]\
    //                     }\
    //                     }}";

    string testStr = "{\n"
                        "    \"id\": \"okdok\",\n"
                        "    \"name\": \"Foo\",\n"
                        "    \"tags\": [ \"Fighters\", \"Five\" ],\n"
                        "    \"type\": {\n"
                        "        \"rock\": \"100\",\n"
                        "        \"roll\": \"30\"\n"
                        "    }\n"
                        "}";

    stringstream ss;

    ss << testStr;

    try
    {
        testClass.inputJson(ss)->print();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}