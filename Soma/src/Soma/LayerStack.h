#pragma once

#include "Soma/Core.h"
#include "Soma/Layer.h"

namespace Soma {
    class SOMA_API LayerStack {
    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer* layer);
        void PopLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopOverlay(Layer* overlay);

        std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
        std::vector<Layer*>::iterator end() { return m_Layers.end(); }

    private:
        std::vector<Layer*> m_Layers;

        // Points to the last layer, i.e. before the first overlay if any
        std::vector<Layer*>::iterator m_LayerInsert;
    };
}

