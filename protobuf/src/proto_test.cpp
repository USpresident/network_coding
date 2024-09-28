#include "proto_test.h"
#include "Person.pb.h"
#include "complex_sample.pb.h"
#include "students.pb.h"

void TestProto::test_proto()
{
    Person person;
    person.set_id(1001);
    person.set_name("lyc");
    person.set_sex(Sex::male);
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
    ClassInfo classInfo;
    classInfo.set_class_no(11);

    std::string name[] = {"lyc", "lyy", "lc", "lily", "lucy"};
    Sex sex[]  = {Sex::male, Sex::female, Sex::male, Sex::female, Sex::female};
    for (int i = 0; i < 5; ++i) {
        auto student = classInfo.add_stus();
        student->set_id(1001 + i);
        student->set_name(name[i]);
        student->set_sex(sex[i]);
        student->set_age(20 + i);
    }

    std::string outInfo;
    classInfo.SerializeToString(&outInfo);

    ClassInfo classInfo2;
    classInfo2.ParseFromString(outInfo);

    std::cout << "Class " << classInfo2.class_no()
        << " has " << classInfo2.stus_size() << " students. As follow:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << classInfo2.stus(i).id() << ", "
                  << classInfo2.stus(i).name() << ", "
                  << classInfo2.stus(i).sex() << ", "
                  << classInfo2.stus(i).age() << std::endl;
    }
}
