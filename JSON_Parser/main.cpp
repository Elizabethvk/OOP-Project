#include "JSONCheck/JSONCheck.hpp"

int main() {
    JsonCheck testClass;
    string testStr = "{\"menu\": {\
                        \"id\": \"file\",\
                        \"value\": \"File\",\
                        \"popup\": {\
                            \"menuitem\": [\
                            {\"value\": \"New\", \"onclick\": \"CreateNewDoc()\"},\
                            {\"value\": \"Open\", \"onclick\": \"OpenDoc()\"},\
                            {\"value\": \"Close\", \"onclick\": \"CloseDoc()\"}\
                            ]\
                        }\
                        }}";

    stringstream ss;

    ss << testStr;

    try
    {
        testClass.inputJson(ss)->print();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}