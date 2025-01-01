#pragma once

//---------3rd Vendor-----
#include <SDL3/SDL.h>
#include <SDL3/SDL_gpu.h>
#include <SDL3_image/SDL_image.h>
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>  // for pointer to matrix or vector
//------------------------

//----------Misc----------
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <vector>
#include <string>
//------------------------

//---------event def------
#define BIT(x) (1 << (x))
//------------------------

#include "Application.h"

#include "Window.h"

#include "Renderer.h"

#include "Shader.h"

#include "Texture.h"

//#include "Events/Event.h"

//#include "Events/EventManager.h"

//#include "Events/KeyEvent.h"

//#include "Events/ApplicationEvent.h"

//#include "Events/MouseEvent.h"