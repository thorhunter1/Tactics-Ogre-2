#add_subdirectory( Preset )

set(SOURCE
   ${SOURCE}
   # ${CMAKE_CURRENT_SOURCE_DIR}/IsometricObject.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/IsometricTile.cpp
   #${CMAKE_CURRENT_SOURCE_DIR}/AnimatedObject.cpp
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/IsometricObject.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/IsometricTile.hpp
   #${CMAKE_CURRENT_SOURCE_DIR}/AnimatedObject.hpp
   PARENT_SCOPE
)
