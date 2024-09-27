#include "proto_test.h"
#include "Person.pb.h"
#include "complex_sample.pb.h"


void TestProto::test_proto()
{
    Person person;
    person.set_id(1001);
    person.set_name("lyc");
    person.set_sex("man");
    person.set_age(20);

    // 序列化
    std::string outPut;
    person.SerializeToString(&outPut);

    // 反序列化
    Person person2;
    person2.ParseFromString(outPut);

    std::cout << person2.id() << ", "
              << person2.name() << ", "
              << person2.sex() << ", "
              << person2.age() << std::endl;
}

void TestProto::test_proto2()
{
    Person2 person;
    person.set_id(1001);
    person.set_name("lyc");
    person.set_sex("man");
    person.set_age(20);
    
    Address *addr = person.mutable_addr();
    addr->set_door_num(101);
    addr->set_addr("shenzhen futian");


    // 序列化
    std::string outPut;
    person.SerializeToString(&outPut);

    // 反序列化
    Person2 person2;
    person2.ParseFromString(outPut);

    std::cout << person2.id() << ", "
              << person2.name() << ", "
              << person2.sex() << ", "
              << person2.age() << ", "
              << person2.addr().door_num() << ", "
              << person2.addr().addr() << std::endl;
}

void TestProto::test_proto_array()
{
    
}