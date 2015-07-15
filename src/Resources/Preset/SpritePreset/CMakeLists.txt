add_subdirectory( UnitSpritePreset )
add_subdirectory( TilesetSpritePreset )
add_subdirectory( CliffsetSpritePreset )

set(SOURCE
   ${SOURCE}
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/UnitSpritePreset.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/TilesetSpritePreset.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/CliffsetSpritePreset.hpp
   PARENT_SCOPE
)
