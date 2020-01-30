add_executable(main main.cpp)

target_link_libraries(main PRIVATE say_hello Eigen3::Eigen)
