#add_subdirectory( RenderableObject )

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/RenderableObject.cpp
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/RenderableObject.hpp
   PARENT_SCOPE
)
