set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
      AsioGenericServer.hpp  )

add_library(libAsioGenericServer ${SOURCE_FILES})

set_target_properties(libAsioGenericServer PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(TestApps)