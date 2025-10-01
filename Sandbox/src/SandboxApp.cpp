#include <Flute.h>

class Sandbox : public Flute::Application 
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Flute::Application* Flute::CreateApplication()
{
	return new Sandbox();
}