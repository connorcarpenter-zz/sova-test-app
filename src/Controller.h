#pragma once

//
// Created by connor on 4/9/18.
//

#include <iostream>

#include <Sova/References/Refable.h>
#include <Sova/References/Ref.h>
#include <Modules/Core/Time/TimePoint.h>
#include <Modules/Core/Time/Clock.h>
#include "Sova/SovaMain.h"

#include "TestShaderHandler.h"
#include "Global.h"

using namespace Sova;

namespace SovaTestApp
{
    class Controller : public Sova::Refable
    {
    public:

        Controller();
        virtual const char* getClassName() { return "Controller"; }

        void onLoadFinish();
        void onGameStart();
        void onGameUpdate(float deltaFrameMs);

        Ref<Global> g = Null<Global>();
    };

    Controller::Controller() = default;

    void Controller::onGameStart()
    {
        {
            g = New<Global>();
            g->app = New<App>(640, 480, New<String>("Demo"), New<TestShaderHandler>());
            g->app->setGlobal(g.obj);

            Ref<List<String>> resources = New<List<String>>();

            resources->Add(New<String>("images/owl.png"));
            resources->Add(New<String>("sounds/hello.wav"));

            g->app->load(resources)
                    ->onFinish(
                            [&]() {
                                onLoadFinish();
                            });
        }

        g->app->start(); // code continues processing within this function, which is why it should be outside the above scope
    }

    void Controller::onLoadFinish()
    {
        // after loading is done
        g->world = New<Container>();
        g->camera = New<Camera>(0, 0, g->app->width, g->app->height, g->world);
        g->viewport = g->app->createViewport(0, 0, g->app->width, g->app->height, g->camera);
        g->owlSprite = New<Sprite>(New<String>("images/owl.png"));
        g->world->AddChild(g->owlSprite);

        g->owlSprite->position->set(128,128);
        g->owlVelocity = New<Point>(5,5);
        g->owlSprite->OnUpdate([&](float deltaMs){
            g->owlSprite->position->x += g->owlVelocity->x;
            g->owlSprite->position->y += g->owlVelocity->y;

            if (g->owlSprite->position->x < 0) { g->owlVelocity->x = 5; }
            if (g->owlSprite->position->y < 0) { g->owlVelocity->y = 5; }
            if (g->owlSprite->position->x + g->owlSprite->getWidth() > g->camera->width) { g->owlVelocity->x = -5; }
            if (g->owlSprite->position->y + g->owlSprite->getHeight() > g->camera->height) { g->owlVelocity->y = -5; }
        });

        g->helloSound = New<Sound>(New<String>("sounds/hello.wav"));

        g->app->onUpdate(
                [&](float deltaFrameMs) {
                    onGameUpdate(deltaFrameMs);
                });
    }

    int gcCount = 0;
    bool playedSound = false;

    void Controller::onGameUpdate(float deltaFrameMs)
    {
        if (g->app->keyPressed(Key::Space)){
            if (!playedSound) {
                g->helloSound->Play();
                playedSound = true;
            }
        }
        else playedSound = false;

        // this is the game loop
        g->world->UpdateChildren(deltaFrameMs);

        //when enough time has passed, do this
        if (gcCount > 1000) {
            Sova::GarbageCollector::getGC()->collect(this);
            gcCount = 0;
        }

        gcCount += 1;
    }
}
