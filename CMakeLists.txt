
cmake_minimum_required(VERSION 3.3)

project(sulfurdb VERSION 0.0.1)

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

# Options
option(WITH_testing "Allows tests to be run" ON)
option(WITH_openssl "Uses openssl for communication of varirous tasks" OFF)

if(WITH_testing MATCHES ON)
   enable_testing()
endif(WITH_testing MATCHES ON)

# Option to install targets to env location
if(DEFINED ENV{SULFURDB_HOME})
     message("-- Will install TEMPLATE binaries and libraries to location: " $ENV{SULFURDB_HOME})
     set(CMAKE_INSTALL_PREFIX $ENV{SULFURDB_HOME})
else(DEFINED ENV{SULFURDB_HOME})
     message("-- Will install TEMPLATE binaries and libraries to location: " ${CMAKE_INSTALL_PREFIX})
endif(DEFINED ENV{SULFURDB_HOME})


if(WITH_openssl MATCHES ON)
    set(OPENSSL_USE_STATIC_LIBS TRUE)
    if(DEFINED ENV{OPENSSL_ROOT_DIR})
        message(STATUS "SSL Root Dir is $ENV{OPENSSL_ROOT_DIR}")
    else(DEFINED ENV{OPENSSL_ROOT_DIR})
        message(ERROR "No ssl root dir!")
    endif(DEFINED ENV{OPENSSL_ROOT_DIR})
    find_package(OpenSSL 3.0.0 REQUIRED)

    if(OPENSSL_FOUND)
         message(STATUS "Found ssl, include=${OPENSSL_INCLUDE_DIR} libs=${OPENSSL_SSL_LIBRARY}, vers=${OPENSSL_VERSION
    }")
    else(OPENSSL_FOUND)
         message(FATAL "Cannot find openssl!")
    endif(OPENSSL_FOUND)

    include_directories(${OPENSSL_INCLUDE_DIR})

    # add_executable(server server.c)
    # target_link_libraries(server ${OPENSSL_CRYPTO_LIBRARIES} ${OPENSSL_SSL_LIBRARIES})
endif(WITH_openssl MATCHES ON)

include(CheckCSourceRuns)

check_c_source_runs("int main(void){short int number = 0x1; char *numPtr = (char*)&number; return (numPtr[0] == 1) ? 0 : 3;}" USE_LITTLE_ENDIAN)
check_c_source_runs("int main(void){short int number = 0x1; char *numPtr = (char*)&number; return (numPtr[0] == 0) ? 0: 1 ;}" USE_BIG_ENDIAN)

if(USE_LITTLE_ENDIAN)
    message(STATUS "Detected little endian architecture")
    add_definitions(-DSPECTRA_ENDIAN_LIT)
else()
    if(USE_BIG_ENDIAN)
        message(STATUS "Detetcted big endian architecture")
        add_definitions(-DSPECTRA_ENDIAN_BIG)
    else()
        message(FATAL "Cannot determine endian type")
    endif()
endif()

add_subdirectory(sulfur_core)

# include_directories(${PROJECT_SOURCE_DIR}/include)


