set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
      AsioGenericServer.hpp  )


find_package( Threads )



add_library(libAsioGenericServer ${SOURCE_FILES})

set_target_properties(libAsioGenericServer PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries( libAsioGenericServer ${CMAKE_THREAD_LIBS_INIT} )

add_subdirectory(TestApps)