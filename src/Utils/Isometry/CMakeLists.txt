#add_subdirectory( Debug )

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/IsometricMapUtils.cpp
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/IsometricMapUtils.hpp
   PARENT_SCOPE
)
