set(SOURCE_FILES
        main.cpp )

find_package( Threads )

add_executable(AsioGenericServerTestApp ${SOURCE_FILES})

target_link_libraries( AsioGenericServerTestApp ${CMAKE_THREAD_LIBS_INIT} )