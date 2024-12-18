#pragma once

#include "Soma/Core.h"
#include "Soma/Events/Event.h"

namespace Soma {
    class SOMA_API Layer {
    public:
        Layer(const std::string& debugName = "Layer");
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event& event) {}

        inline const std::string& GetName() const { return m_DebugName; }

    protected:
        std::string m_DebugName;
    };
}
