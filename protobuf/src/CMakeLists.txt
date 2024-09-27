include_directories(../head)

aux_source_directory(./ SRC)

# set(SRC complex_sample.pb.cc demo.cpp proto_test.cpp)

add_executable(demo_proto ${SRC})

target_link_libraries(demo_proto protobuf)