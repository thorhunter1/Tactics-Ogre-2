#include "Unit/Unit.hpp"

int Unit::loadPresets()
{
	int ret = 0;
	char* ret_msg = "";

	// Load sprite preset
	if( spritePreset_ != NULL )
	{
		spritePreset_->load();
		bindRenderImage( *sPreset_->getImage() );
		updateTexture();
	}
	else
	{
		ret = -1;
		ret_msg = "Unit has no sprite preset to load";
	}

	// Load animation preset

	TraceReturn( ret, ret_msg );


}

int Unit::unloadPresets()
{
	if( spritePreset_ != NULL )
		spritePreset_->unload();
}

