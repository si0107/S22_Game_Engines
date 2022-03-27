set(HEADER_FILES 
	Pigu.h
	PiguApp.h
	PiguUtil.h
	GWindow.h
	WindowImplement.h
	specificGLFW/GlfwWindow.h
	)

set(SOURCE_FILES 
	PiguApp.cpp
	GWindow.cpp
	specificGLFW/GlfwWindow.cpp
	)

add_library(Pigu SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DPIGU_LIB)
add_definitions(-DPIGU_DEBUG)

include_directories(../glfw/include)
include_directories(../Pigu)

target_precompile_headers(Pigu PRIVATE pch.h)

target_link_libraries(Pigu glfw)