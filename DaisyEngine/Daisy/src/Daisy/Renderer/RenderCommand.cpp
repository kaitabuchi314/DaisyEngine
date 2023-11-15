#include "hzpch.h"
#include "Daisy/Renderer/RenderCommand.h"

namespace Daisy {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}