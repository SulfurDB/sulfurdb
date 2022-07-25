# Cmake for core C part of sulfur data set handling


set(SULFUR_CORE_SOURCES
    sulfur_data_set.c
)

add_library(sulfur_core STATIC "${SULFUR_CORE_SOURCES}")

add_subdirectory(core_tests)