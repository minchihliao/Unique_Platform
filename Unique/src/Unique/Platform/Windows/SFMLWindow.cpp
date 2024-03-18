
#include "uqpch.h"
#include "SFMLWindow.h"

#include "Unique/Events/ApplicationEvent.h"
#include "Unique/Events/MouseEvent.h"
#include "Unique/Events/KeyEvent.h"

namespace Unique
{

	Window* Window::Create(const WindowProps& props)
	{
		return new SFMLWindow(props);
	}

	SFMLWindow::SFMLWindow(const WindowProps& props)
	{
		Init(props);
	}

	SFMLWindow::~SFMLWindow()
	{
		Shutdown();
	}



	void SFMLWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		UQ_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);


		m_Window = new sf::RenderWindow(sf::VideoMode((int)props.Width, (int)props.Height), m_Data.Title);
		m_Window->setFramerateLimit(60);
		//m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		//glfwMakeContextCurrent(m_Window);
		//glfwSetWindowUserPointer(m_Window, &m_Data);
		auto circle = std::make_shared<sf::CircleShape>(50);
		circle->setFillColor(sf::Color::Green);
		AddGameObject(circle);
		
	}

	void SFMLWindow::Shutdown()
	{
		m_Window->close();
	}

	

	void SFMLWindow::OnUpdate()
	{
		if (m_Window->isOpen())
		{
			OnEvent();
			m_Window->clear();
			if (!m_Objs.empty()) {
				for (auto& obj : m_Objs)
				{
					m_Window->draw(*obj);
				}
			}
			m_Window->display();
		}

	}

	void SFMLWindow::OnEvent()
	{
		sf::Event event;
		while (m_Window->pollEvent(event))
		{
			if (event.type == sf::Event::Resized) {
				m_Data.Width = event.size.width;
				m_Data.Height = event.size.height;
				WindowResizeEvent event(m_Data.Width, m_Data.Height);
				m_Data.EventCallback(event);
			}

			if (event.type == sf::Event::Closed) {
				WindowCloseEvent event;
				m_Data.EventCallback(event);
			}

			//Keyboard
			if (event.type == sf::Event::KeyPressed) 
			{
				KeyPressedEvent event(event.key.code, 0);
				m_Data.EventCallback(event);
			}

			if (event.type == sf::Event::KeyReleased)
			{
				KeyReleasedEvent  event(event.key.code);
				m_Data.EventCallback(event);
			}

			//Mouse
			if (event.type == sf::Event::MouseButtonPressed)
			{
				MouseButtonPressedEvent event(event.mouseButton.button);
				m_Data.EventCallback(event);
			}

			if (event.type == sf::Event::MouseButtonReleased)
			{
				MouseButtonReleasedEvent event(event.mouseButton.button);
				m_Data.EventCallback(event);
			}

			if (event.type == sf::Event::MouseWheelScrolled)
			{
				MouseScrolledEvent event((float)event.mouseWheelScroll.x, (float)event.mouseWheelScroll.y);
				m_Data.EventCallback(event);
			}

			//Cursor
			if (event.type == sf::Event::MouseMoved)
			{
				MouseMovedEvent event((float)event.mouseMove.x, (float)event.mouseMove.y);
				m_Data.EventCallback(event);
			}


		}
	}

	void SFMLWindow::SetBackgroundColor(sf::Color color)
	{
		m_Background = color;
	}

	void SFMLWindow::AddGameObject(const std::shared_ptr<sf::Drawable>& drawable)
	{
		m_Objs.push_back(drawable);
	}

	void SFMLWindow::SetVSync(bool enabled)
	{
	}

	bool SFMLWindow::IsVSync() const
	{
		return m_Data.VSync;
	}





}