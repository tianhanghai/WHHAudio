# version configuration
cmake_minimum_required(VERSION 2.6)

project (all_examples)

# Turn on the ability to create folders to organize projects 
# It creates "CMakePredefinedTargets" folder by default and adds CMake 
# defined projects like INSTALL.vcproj and ZERO_CHECK.vcproj 
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

IF(WIN32)
    MESSAGE(STATUS "Build all examples for Windows")
ELSEIF(APPLE)
    MESSAGE(STATUS "Build all examples for Apple System")
ELSEIF(UNIX)
    MESSAGE(STATUS "Build all examples for UNIX-like OS")
ENDOF()

add_subdirectory("..\simple_device_manage")