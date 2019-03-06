# version configuration
cmake_minimum_required(VERSION 2.6)

project (WHHAudio)

# Turn on the ability to create folders to organize projects 
# It creates "CMakePredefinedTargets" folder by default and adds CMake 
# defined projects like INSTALL.vcproj and ZERO_CHECK.vcproj 
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

IF(WIN32)
    MESSAGE(STATUS "Build lib for Windows")
ELSEIF(APPLE)
    MESSAGE(STATUS "Build lib for Apple System")
ELSEIF(UNIX)
    MESSAGE(STATUS "Build lib for UNIX-like OS")
ENDIF()

add_subdirectory("libWHHaudio")
