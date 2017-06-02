file(GLOB FILES
    "./src/*.cpp"
)
cmake_minimum_required(VERSION 2.8)


include_directories(include)
project( Controle )
find_package(Threads)
find_package( OpenCV REQUIRED )
add_executable(main ${FILES})
target_link_libraries( main ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})