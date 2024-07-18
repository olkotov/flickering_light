// Oleg Kotov

#include "glow_sphere.h"
#include "staticmeshcomponent.h"
#include "flickercomponent.h"
#include "material.h"
#include "gameplay.h"

LINK_ENTITY_TO_CLASS( glow_sphere, GlowSphere )

GlowSphere::GlowSphere()
{
	m_meshComponent = createComponent<StaticMeshComponent>();
	m_meshComponent->setMesh( "models/primitives/sphere.json" );
	m_meshComponent->setMaterial( "materials/yellow.mat" );

	setRootComponent( m_meshComponent );

	m_flickerComponent = createComponent<FlickerComponent>();
	m_flickerComponent->setLightStyle( "mmamammmmammamamaaamammma" );

	m_material = m_meshComponent->getMaterial();
	m_color = Color( 204, 182, 2 );
}

void GlowSphere::tick( float deltaTime )
{
	Super::tick( deltaTime );

	float value = m_flickerComponent->updateValue( getTimeSinceStartup() );

	Color newColor = m_color;
	newColor.r = m_color.r * value;
	newColor.g = m_color.g * value;
	newColor.b = m_color.b * value;

	m_material->setColorParameter( "_Color", newColor );
}

