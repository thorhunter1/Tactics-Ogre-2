add_subdirectory( UnitSpritePreset )
add_subdirectory( TilesetSpritePreset )

set(SOURCE
   ${SOURCE}
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/UnitSpritePreset.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/TilesetSpritePreset.hpp
   PARENT_SCOPE
)
