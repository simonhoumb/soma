#include "smpch.h"
#include "LayerStack.h"

namespace Soma {
    LayerStack::LayerStack() {
        m_LayerInsert = m_Layers.begin();
    }

    LayerStack::~LayerStack() {
        for (Layer* layer : m_Layers) {
            delete layer;
        }
    }

    // Adds layers behind the last layer, but before all overlays
    void LayerStack::PushLayer(Layer* layer) {
        m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
    }

    void LayerStack::PopLayer(Layer* layer) {
        auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
        if (it != m_Layers.end()) {
            m_Layers.erase(it);
            m_LayerInsert--;
        }
    }

    // Adds overlays to the bottom of the stack
    void LayerStack::PushOverlay(Layer* overlay) {
        m_Layers.emplace_back(overlay);
    }
    
    void LayerStack::PopOverlay(Layer* overlay) {
        auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
        if (it != m_Layers.end()) {
            m_Layers.erase(it);
        }
    }
}