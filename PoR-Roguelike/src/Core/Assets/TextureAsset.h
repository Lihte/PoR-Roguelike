#pragma once
#include <SFML\Graphics.hpp>
#include "Core\Core_types.h"
#include "Core\Interfaces\IAsset.h"

class TextureHandler;

class TextureAsset : public IAsset
{
public:
	TextureAsset(const TextureHandler& handler);
	~TextureAsset();

protected:


private:
	const TextureHandler& m_handler;

	sf::Texture* m_textureAsset;

	typeAssetID m_textureId;
};

