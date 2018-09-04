#pragma once

//
// Created by connor on 7/26/18.
//

#include <Sova/References/Ref.h>
#include <Sova/References/Refable.h>
#include <Sova/App.h>

namespace SovaTestApp
{
    class Global : public Sova::Refable
    {
    public:
        Ref<Sova::App> app = Null<Sova::App>();
        Ref<Viewport> viewport = Null<Viewport>();
        Ref<Camera> camera = Null<Camera>();
        Ref<Container> world = Null<Container>();
        Ref<Sprite> owlSprite = Null<Sprite>();
        Ref<Point> owlVelocity = Null<Point>();
    };
}