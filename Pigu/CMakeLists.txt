set(HEADER_FILES 
	Pigu.h
	PiguApp.h
	PiguUtil.h
	GWindow.h
	WindowImplement.h
	piguGLFW/PiguGlfwWindow.h
	PiguSprite.h
	PiguShader.h
	PiguRenderer.h
	PiguSpriteImplementation.h
	PiguShaderImplementation.h
	PiguRendererImplementation.h
	piguOpenGL/PiguOpenGLSprite.h
	piguOpenGL/PiguOpenGLShader.h
	piguOpenGL/PiguOpenGLRenderer.h
	PiguEvents.h
	PiguKeyCodes.h
	)

set(SOURCE_FILES 
	PiguApp.cpp
	GWindow.cpp
	piguGLFW/PiguGlfwWindow.cpp
	PiguSprite.cpp
	PiguShader.cpp
	PiguRenderer.cpp
	piguOpenGL/PiguOpenGLSprite.cpp
	piguOpenGL/PiguOpenGLShader.cpp
	piguOpenGL/PiguOpenGLRenderer.cpp
	PiguEvents.cpp
	)

add_library(Pigu SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DPIGU_LIB)
add_definitions(-DPIGU_DEBUG)
add_definitions(-DPIGU_OPENGL)

include_directories(../glfw/include)
include_directories(../Pigu)
include_directories(../Pigustbi)
include_directories(../PiguGlad/include)

target_precompile_headers(Pigu PRIVATE pchPigu.h)

target_link_libraries(Pigu glfw PiguGlad Pigustbi)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Pigu)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)