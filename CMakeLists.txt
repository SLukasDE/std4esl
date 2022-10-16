cmake_minimum_required(VERSION 3.23)

project(std4esl VERSION 1.5.0
            LANGUAGES CXX)
            
#include(FetchContent)
#FetchContent_Declare(
#  catch
#  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#  GIT_TAG        v2.13.6
#)
#FetchContent_MakeAvailable(catch)


# The compiled library code is here
#add_subdirectory(src/main)
# STATIC, SHARED, MODULE, INTERFACE
add_library(std4esl STATIC
      ./src/main/std4esl/Plugin.cpp
      ./src/main/std4esl/Plugin.h
      ./src/main/std4esl/object/String.h
      ./src/main/std4esl/object/VectorString.h
      ./src/main/std4esl/object/Int.h
      ./src/main/std4esl/object/SetInt.h
      ./src/main/std4esl/object/SetString.cpp
      ./src/main/std4esl/object/VectorPairStringString.cpp
      ./src/main/std4esl/object/VectorPairStringString.h
      ./src/main/std4esl/object/SetString.h
      ./src/main/std4esl/object/MapStringString.cpp
      ./src/main/std4esl/object/VectorInt.cpp
      ./src/main/std4esl/object/SetInt.cpp
      ./src/main/std4esl/object/MapStringString.h
      ./src/main/std4esl/object/String.cpp
      ./src/main/std4esl/object/VectorString.cpp
      ./src/main/std4esl/object/VectorInt.h
      ./src/main/std4esl/object/Int.cpp
      ./src/main/std4esl/Logger.h
)

target_include_directories(std4esl PUBLIC ./src/main)
target_compile_features(std4esl PUBLIC cxx_std_11)
set_property(TARGET std4esl PROPERTY POSITION_INDEPENDENT_CODE ON)

find_package(esl REQUIRED)

target_link_libraries(std4esl PRIVATE esl::esl)

install(TARGETS std4esl
        EXPORT std4esl-export
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)

install(EXPORT      std4esl-export
        FILE        std4eslTargets.cmake
        NAMESPACE   std4esl::
        DESTINATION lib/cmake
)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/std4eslConfig.cmake
        DESTINATION "lib/cmake"
)




# The compiled test code is here
#add_subdirectory(src/test)
