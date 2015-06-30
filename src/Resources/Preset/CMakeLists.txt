add_subdirectory( SpritePreset )

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/SpritePreset.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/AnimationSetPreset.cpp
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/SpritePreset.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/AnimationSetPreset.hpp
   PARENT_SCOPE
)
