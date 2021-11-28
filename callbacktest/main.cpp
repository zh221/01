#include <iostream>
#include "MyTest.h"

using callFunc = void(*)(void *msg);

void registCallFunc(callFunc func, void *msg)
{
    func(msg);
    return;
}

std::string jsonStrA = "{\"msgType\":\"TYPE1\",\"msgBody\":{\"dataList\":[{\"ID1\":\"12345\"},{\"ID2\":\"23456\"},{\"ID3\":\"34567\"}]}}";
std::string jsonStrB = "{\"msgType\":\"TYPE2\",\"msgBody\":{\"dataList\":[{\"ID\":\"12345\",\"type\":\"a\"},{\"ID\":\"23456\",\"type\":\"b\"},{\"ID\":\"34567\",\"type\":\"c\"}]}}";
int main()
{
    MyTest t;
    registCallFunc(t.parseMsgA, &jsonStrA);
    registCallFunc(t.parseMsgB, &jsonStrB);
    return 0;
}
