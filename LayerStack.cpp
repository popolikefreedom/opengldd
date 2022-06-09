#include "LayerStack.h"
#include "logging.h"

namespace CC
{

    LayerStack::LayerStack()
    {
    }

    LayerStack::~LayerStack()
    {
        for (Layers* layer : m_Layers)
		{
			layer->OnDetach();
			delete layer;
		}
    }

    void LayerStack::PushLayer(Layers* layer)
	{
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
		m_LayerInsertIndex++;
	}

    void LayerStack::PushOverlay(Layers* overlay)
	{
		m_Layers.emplace_back(overlay);
		LOGI("PushOverlay {}", m_Layers.size());
	}

    void LayerStack::PopLayer(Layers* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerInsertIndex, layer);
		if (it != m_Layers.begin() + m_LayerInsertIndex)
		{
			layer->OnDetach();
			m_Layers.erase(it);
			m_LayerInsertIndex--;
		}
	}

	void LayerStack::PopOverlay(Layers* overlay)
	{
		auto it = std::find(m_Layers.begin() + m_LayerInsertIndex, m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			overlay->OnDetach();
			m_Layers.erase(it);
		}
	}
}