#add_subdirectory( UnitSpritePreset )

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/SmallUnitSpritePreset.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/SmallUnitSpritePreset2.cpp
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/SmallUnitSpritePreset.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/SmallUnitSpritePreset2.hpp
   PARENT_SCOPE
)
