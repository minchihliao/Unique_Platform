#include "Enemy.h"

Enemy::Enemy()
{
}

void Enemy::LoadAssets()
{
	m_Sprite.SetTexture(Unique::Texture2D::Create("assets/textures/enemy.png"));
	m_Sprite.SetScale(sf::Vector2f(0.1, 0.1));
}

void Enemy::OnUpdate()
{
	m_Position += sf::Vector2f(0, 5.f);

	collision();
}

void Enemy::OnRender()
{
	Unique::Renderer2D::DrawSprite(m_Sprite, GetPosition());
}

void Enemy::OnImGuiRender()
{
}

void Enemy::Reset()
{
	auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
	m_Position = sf::Vector2f(rand() % (int)(window->getSize().x - m_Sprite.GetGlobalBounds().width), 10);

	
}

bool Enemy::IsOutofBounds()
{
	auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
	if (GetPosition().y >= window->getSize().y - m_Sprite.GetGlobalBounds().height)
	{
		return true;
	}
	return false;
}

void Enemy::collision()
{
	if (IsOutofBounds()) {
		m_Dead = true;
	}
	
}
