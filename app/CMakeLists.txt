# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

set(OPENCV_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)

#include_directories(E:/sdk/ndk-bundle/sources/cxx-stl/llvm-libc++/include)
#add_library(
#            c++_shared
#            SHARED
#            IMPORTED )
#set_target_properties(
#                        c++_shared
#                        PROPERTIES IMPORTED_LOCATION
#                        E:/sdk/ndk-bundle/sources/cxx-stl/llvm-libc++/libs/${ANDROID_ABI}/c++_shared.so)

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/native-lib.cpp src/main/cpp/first.cpp)


#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

include_directories(src/main/cpp/include)#包含OpenCv的头文件目录
add_library( lib_opencv
             SHARED
             IMPORTED )
set_target_properties( lib_opencv
                       PROPERTIES IMPORTED_LOCATION
                       ${OPENCV_DIR}/${ANDROID_ABI}/libopencv_java3.so )
                       #包含libopencv_java3.so这个库  ${ANDROID_ABI}

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib lib_opencv

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )