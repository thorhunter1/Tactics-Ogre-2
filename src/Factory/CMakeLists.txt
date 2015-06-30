#add_subdirectory( RenderableObject )

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/UnitFactory.cpp
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/UnitFactory.hpp
   PARENT_SCOPE
)
