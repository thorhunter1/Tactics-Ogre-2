#add_subdirectory( Preset )

set(SOURCE
   ${SOURCE}
   # ${CMAKE_CURRENT_SOURCE_DIR}/IsometricObject.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/IsometricTile.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/IsometricTileComposite.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/IsometricMap.cpp
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/IsometricObject.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/IsometricTile.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/IsometricTileComposite.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/IsometricMap.hpp
   PARENT_SCOPE
)
