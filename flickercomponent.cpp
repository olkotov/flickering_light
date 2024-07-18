// Oleg Kotov

#include "flickercomponent.h"

void FlickerComponent::setLightStyle( const std::string& lightstyle )
{
	m_lightstyle = lightstyle;
}

float FlickerComponent::updateValue( float time ) const
{
	if ( m_lightstyle.empty() ) return 1.0f;

	static const int8_t diffmax = 25; // 'z' - 'a';

	int32_t time_scaled = (int32_t)( time * 10.0f );
	int32_t frame = time_scaled % m_lightstyle.length();

	char lightchar = m_lightstyle[frame];
	assert( lightchar >= 'a' && lightchar <= 'z' );
	
	int8_t diff = lightchar - 'a';

	return diff / (float)diffmax * 2.0f;
}

