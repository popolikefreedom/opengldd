#ifndef IMGUILAYER_H
#define IMGUILAYER_H

#pragma once
#include "../Layers.h"

namespace CC
{

    class ImguiLayer : public Layers
    {
    public:
        ImguiLayer();
        ~ImguiLayer() = default;
        
        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(Event& event) override;

        void begin();
        void end();

        void BlockEvents(bool block) { m_BlockEvents = block; }
		void SetDarkThemeColors();
    private:
        bool m_BlockEvents = true;
    };

}
#endif