#add_subdirectory( RenderableObject )

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/UnitFactory.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/TileFactory.cpp
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/UnitFactory.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/TileFactory.hpp
   PARENT_SCOPE
)
