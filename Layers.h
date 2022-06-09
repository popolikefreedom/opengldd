#ifndef LAYERS_H
#define LAYERS_H

#pragma once

#include <string>
#include "event/Event.h"

namespace CC
{

    class Layers
    {
    public:
        Layers(const std::string& name = "Layer");
        virtual ~Layers();

        virtual void OnAttach() = 0;
        virtual void OnDetach() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnEvent(Event& event) = 0;

        inline const std::string& getName() const { return m_DebugName;}
    private:
    protected:
        std::string m_DebugName;
    };

}
#endif