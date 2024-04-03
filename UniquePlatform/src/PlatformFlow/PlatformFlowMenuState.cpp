#include "PlatformFlowMenuState.h"

void PlatformFlowMenuState::Enter(PlatformLayer* layer)
{
	GameBlock* spaceShooter = new GameBlock(std::string("SpaceShooter"), sf::Vector2f(-250, -275));
	m_GameBlockVector.push_back(spaceShooter);
	GameBlock* Shooter = new GameBlock(std::string("Shooter"), sf::Vector2f(150, -275));
	m_GameBlockVector.push_back(Shooter);
	GameBlock* Test1 = new GameBlock(std::string("Test1"), sf::Vector2f(-250, -50));
	m_GameBlockVector.push_back(Test1);
	GameBlock* Test2 = new GameBlock(std::string("Test2"), sf::Vector2f(150, -50));
	m_GameBlockVector.push_back(Test2);
	GameBlock* Test3 = new GameBlock(std::string("Test3"), sf::Vector2f(-250, 175));
	m_GameBlockVector.push_back(Test3);
	GameBlock* Test4 = new GameBlock(std::string("Test4"), sf::Vector2f(150, 175));
	m_GameBlockVector.push_back(Test4);
}

void PlatformFlowMenuState::OnUpdate(PlatformLayer* layer, Unique::Timestep ts)
{
	for (size_t i = 0; i < m_GameBlockVector.size(); i++)
	{
		m_GameBlockVector[i]->OnUpdate(ts);
	}
}

void PlatformFlowMenuState::OnRender(PlatformLayer* layer)
{
	for (size_t i = 0; i < m_GameBlockVector.size(); i++)
	{
		m_GameBlockVector[i]->OnRender();
	}
}

void PlatformFlowMenuState::OnImGuiRender(PlatformLayer* layer)
{
	for (size_t i = 0; i < m_GameBlockVector.size(); i++)
	{
		m_GameBlockVector[i]->OnImGuiRender();
	}
}

void PlatformFlowMenuState::OnEvent(Event& e)
{
	for (size_t i = 0; i < m_GameBlockVector.size(); i++)
	{
		m_GameBlockVector[i]->OnEvent(e);
	}
}

void PlatformFlowMenuState::Exit(PlatformLayer* layer)
{
}
