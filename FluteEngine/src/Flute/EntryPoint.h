#pragma once

#ifdef FL_PLATFORM_WINDOWS
extern Flute::Application* Flute::CreateApplication();
int main(int argc,char** argv)
{
	auto app = Flute::CreateApplication();
	app->Run();
	delete app;
}

#endif