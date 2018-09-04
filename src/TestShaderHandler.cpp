//
// Created by connor on 7/9/18.
//

#include "TestShaderHandler.h"
#include <Modules/Gfx/Gfx.h>
#include "shaders.h"

using namespace Oryol;

namespace SovaTestApp
{
    Oryol::Id TestShaderHandler::getScreenShader()
    {
        return Gfx::CreateResource(ScreenShader::Setup());
    }
    Oryol::Id TestShaderHandler::getBackScreenShader()
    {
        return Gfx::CreateResource(BackScreenShader::Setup());
    }
    Oryol::Id TestShaderHandler::getCanvasShader()
    {
        return Gfx::CreateResource(CanvasShader::Setup());
    }
    Oryol::Id TestShaderHandler::getShapeShader()
    {
        return Gfx::CreateResource(ShapeShader::Setup());
    }
}