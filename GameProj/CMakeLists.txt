set(HEADER_FILES
	PiguEntity.h
	GameApp.h
)

set(SOURCE_FILES
	GameApp.cpp
	main.cpp
	PiguEntity.cpp
)

add_executable(GameProj ${HEADER_FILES} ${SOURCE_FILES})

include_directories(../Pigu)

target_link_libraries(GameProj Pigu)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/GameProj)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)