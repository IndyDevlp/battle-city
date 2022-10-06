#include "Ice.h"

#include "../../Renderer/Sprite.h"
#include "../../Resources/ResourceManager.h"


Ice::Ice(const glm::vec2& position, const glm::vec2& size, const float rotation)
	: IGameObject(position, size, rotation)
	, m_sprite(ResourceManager::getSprite("ice"))
	, m_blockOffsets{ 
						glm::vec2(0.f, m_size.y / 2.f),
						glm::vec2(m_size.x / 2.f, m_size.y / 2.f),
						glm::vec2(0.f, 0.f),
						glm::vec2(m_size.x / 2.f, 0.f) }
{}

void Ice::renderBlock(const EBlockLocation eBlocklocation) const
{
	m_sprite->render(m_position + m_blockOffsets[static_cast<size_t>(eBlocklocation)], m_size / 2.f, m_rotation);
}


void Ice::render() const
{
	renderBlock(EBlockLocation::BottomLeft);
	renderBlock(EBlockLocation::BottomRight);
	renderBlock(EBlockLocation::TopLeft);
	renderBlock(EBlockLocation::TopRight);
}