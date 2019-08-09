cmake_minimum_required(VERSION 3.8.0)
set(CMAKE_CXX_STANDARD 17)
project(tvirus)
include_directories(third_party/bsdiff)
file(GLOB srcs ${CMAKE_SOURCE_DIR}/src/*.cpp ./third_party/bsdiff/*.cpp)
add_subdirectory(third_party/bsdiff)
add_executable(${PROJECT_NAME} ${srcs})
find_package(Poco REQUIRED COMPONENTS Foundation Net)
if(Poco_FOUND)
  include_directories(${Poco_INCLUDE_DIRS})
  link_directories(${Poco_LIBRARY_DIRS})
  target_link_libraries(${PROJECT_NAME} ${Poco_LIBRARIES} )
endif()
find_library(bzip2 bz2)
target_link_libraries(${PROJECT_NAME} ${bzip2})

find_package(LUA 5.3)
if(LUA_FOUND)
  include_directories(${LUA_INCLUDE_DIR})
  target_link_libraries(${PROJECT_NAME} ${LUA_LIBRARIES} )
elseif()
  message("Lua53 not found")
  exit(-1)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -D_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

#add git revision in source file
find_program(GIT_SCM git DOC "Git version control")
mark_as_advanced(GIT_SCM)
find_file(GITDIR NAMES .git PATHS ${PROJECT_SOURCE_DIR} NO_DEFAULT_PATH)
add_dependencies(${PROJECT_NAME} gitrev)
add_custom_target(gitrev
  COMMAND ${CMAKE_COMMAND} -E echo_append "const char *GIT_REVISION = " > ${CMAKE_SOURCE_DIR}/src/gitrevision.h
  COMMAND ${GIT_SCM} log -1 "--pretty=format:\"%h %ai\"" >> ${CMAKE_SOURCE_DIR}/src/gitrevision.h
  DEPENDS ${GITDIR}/logs/HEAD
  VERBATIM                                              #portability wanted
)
