#add_subdirectory( Debug )

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/AnimationSetParser.cpp
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/AnimationSetParser.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/TilesetEnum.hpp
   PARENT_SCOPE
)
