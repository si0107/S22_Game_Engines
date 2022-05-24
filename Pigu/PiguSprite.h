#pragma once

#include "PiguSpriteImplementation.h"
#include "PiguUtil.h"

namespace Pigu {
	
	class PIGU_API PiguSprite
	{
	public:
		PiguSprite(const std::string& filename);
		int GetWidth() const;
		int GetHeight() const;

		void Bind();

	private:
		PiguSpriteImplementation* mImplementation;

	};

}

