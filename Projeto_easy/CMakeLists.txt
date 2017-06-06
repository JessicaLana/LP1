file(GLOB FILES
    "./src/*.cpp"
)
cmake_minimum_required(VERSION 2.8)
project( Controle )

include(/home/vinicius/Downloads/dlib-19.4/dlib/cmake)
include_directories(include)
find_package(Threads)
find_package( OpenCV REQUIRED )
add_executable(main ${FILES})
target_link_libraries( main dlib::dlib ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})