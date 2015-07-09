#add_subdirectory( Debug )

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/SpriteUtils.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/ImageUtils.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/TextureUtils.cpp
   
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/SpriteUtils.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/ImageUtils.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/TextureUtils.hpp
   PARENT_SCOPE
)
