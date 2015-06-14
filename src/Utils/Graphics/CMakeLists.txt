#add_subdirectory( Debug )

set(SOURCE
   ${SOURCE}
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/SpriteUtils.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/ImageUtils.hpp
   PARENT_SCOPE
)
