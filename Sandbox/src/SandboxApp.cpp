#include <Shade.h>

class Sandbox : public Shade::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}



};

Shade::Application* Shade::CreateApplication()
{
	return new Sandbox();
}