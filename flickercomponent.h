// Oleg Kotov

#pragma once

#include "entitycomponent.h"

class FlickerComponent : public EntityComponent
{
	using Super = EntityComponent;

public:

	void setLightStyle( const std::string& lightstyle );
	float updateValue( float time ) const;

private:

	std::string m_lightstyle;
	float m_lightValue = 0.0f;
};

