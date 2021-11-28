#ifndef MYTEST_H
#define MYTEST_H

#include <iostream>
#include <string>

class MyTest {
public:
    MyTest();
    virtual ~MyTest();
    static void parseMsgA(void *msg);
    static void parseMsgB(void *msg);
protected:

private:

};

#endif
