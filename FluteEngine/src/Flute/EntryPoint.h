#pragma once

#ifdef FL_PLATFORM_WINDOWS
extern Flute::Application* Flute::CreateApplication();
int main(int argc,char** argv)
{
	Flute::Log::Init();
	FL_CORE_WARN("Initialized Log!");
	int a = 5;
	FL_INFO("Hello Var={0}",a);

	auto app = Flute::CreateApplication();
	app->Run();
	delete app;
}

#endif