// Oleg Kotov

#pragma once

#include "entity.h"
#include "color.h"

class GlowSphere : public Entity
{
	using Super = Entity;

public:

	GlowSphere();

	void tick( float deltaTime ) override;

private:

	class StaticMeshComponent* m_meshComponent = nullptr;
	class FlickerComponent* m_flickerComponent = nullptr;

	class Material* m_material = nullptr;
	Color m_color;
};

