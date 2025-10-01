#pragma once

#include "Core.h"

namespace Flute
{
	class FLUTE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}
