
cmake_minimum_required(VERSION 3.3)

project(proj VERSION 0.0.1)

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

# Options
option(WITH_testing "Allows tests to be run" ON)
option(WITH_openssl "Uses openssl for communication of varirous tasks" OFF)

if(WITH_testing MATCHES ON)
   enable_testing()
endif(WITH_testing MATCHES ON)

if(DEFINED ENV{OPENSSL_ROOT_DIR})
    message(STATUS "SSL Root Dir is $ENV{OPENSSL_ROOT_DIR}")
else(DEFINED ENV{OPENSSL_ROOT_DIR})
    message(ERROR "No ssl root dir!")
endif(DEFINED ENV{OPENSSL_ROOT_DIR})


if(WITH_openssl MATCHES ON)
    set(OPENSSL_USE_STATIC_LIBS TRUE)
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
