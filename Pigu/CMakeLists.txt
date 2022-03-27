add_library(Pigu SHARED Pigu.h PiguApp.h PiguUtil.h PiguApp.cpp)

add_definitions(-DPIGU_LIB)
add_definitions(-DPIGU_DEBUG)