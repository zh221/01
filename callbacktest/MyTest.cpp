#include "MyTest.h"
#include <iostream>
#include <string>
#include "json/json.h"

static std::map<std::string, std::string> IP_A = {{"IP1",""},{"IP2",""},{"IP3",""}};
static std::map<std::string, std::string> IP_B;

MyTest::MyTest()
{
}

MyTest::~MyTest()
{
}

template<typename T>
static void debug(T data)
{
    std::cout<<data<<std::endl;
}

void MyTest::parseMsgA(void *msg)
{
    std::string *str = static_cast<std::string *>(msg);
    std::string msgStr(*str);
    Json::Reader reader;
    Json::Value value;
    reader.parse(msgStr, value);

    Json::Value ipListObj = value["msgBody"]["dataList"];
    Json::Value::Members objItem;
    for (Json::Value &item : ipListObj) {
        objItem = item.getMemberNames();
        IP_A[objItem.front()]=item[objItem.front()].asString();
    }
    debug("Print msg data");
    for (auto &item : IP_A) {
        debug(item.first + "\t" + item.second);
    }
    return;
}

void MyTest::parseMsgB(void *msg)
{
    std::string *str = static_cast<std::string *>(msg);
    std::string msgStr(*str);
    Json::Reader reader;
    Json::Value value;
    reader.parse(msgStr, value);

    Json::Value ipListObj = value["msgBody"]["dataList"];
    for (Json::Value &item : ipListObj) {
        IP_B[item["ID"].asString()] = item["type"].asString();
    }
    debug("Print msg data");
    for (auto &item : IP_B) {
        debug(item.first + "\t" + item.second);
    }
    return;
}
