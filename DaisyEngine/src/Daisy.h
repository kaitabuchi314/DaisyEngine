#pragma once

#define GLEW_STATIC
#include <include/GL/glew.h>
#include <Window.h>

//#include <include/GL/glew.h>

#include <iostream>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include <Log.h>
#include <Defines_Renderer.h>
#include <Model.h>
#include <ShaderProgram.h>
#include <Texture.h>
#include <Renderer.h>
#include <Camera.h>
#include <SampleCamera.h>
#include <TextureFragmentShader.h>
#include <DfVertexShader.h>
#include <GameLayer.h>
#include <Entity.h>
#include <Transform.h>
#include <SpriteComponent.h>
#include <ECS.h>
#include <Scene.h>
#include <Defines.h>