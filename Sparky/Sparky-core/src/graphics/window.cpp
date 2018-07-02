#include "window.h"

namespace sparky
{
	namespace graphics
	{
		void windowResize(GLFWwindow * window, int width, int height);

		Window::Window(const char *name, int width, int height)
		{
			m_Title = name;
			m_Width = width;
			m_Height = height;
			if (!init())
				glfwTerminate();
		}

		Window::~Window()
		{
			glfwTerminate();
		}
		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Failed to initialize GLFW!" << std::endl;
				return false; 
			}
			else
				std::cout << "Success to initialize GLFW!" << std::endl;
			m_Window = glfwCreateWindow(m_Width,m_Height,m_Title ,NULL,NULL);
			if (!m_Window)
			{
				glfwTerminate();
				std::cout << "Failed to create GLFW window!" << std::endl;
				return false ;
			}
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowSizeCallback(m_Window,windowResize);
			return true;
		}
		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
		void Window::update() 
		{
			glfwPollEvents();
	//		glfwGetFramebufferSize(m_Window,&m_Width,&m_Height);
			
			glfwSwapBuffers(m_Window);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window);
		}

		void windowResize(GLFWwindow * window, int width, int height)
		{
			glViewport(0,0,width,height);
		}
	}
}