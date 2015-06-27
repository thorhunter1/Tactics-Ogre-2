#add_subdirectory( RenderableObject )

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/RenderableObject.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/Renderer.cpp
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/RenderableObject.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/Renderer.hpp
   PARENT_SCOPE
)
