#pragma once



class Engine
{
public:
	void Init(const WindowInfo& _window);
	void Render();

	void ResizeWindow(int32 _width, int32 _height);

public:
	void RenderBegin();
	void RenderEnd();

private:
	WindowInfo		m_window;
	D3D12_VIEWPORT	m_viewprot = {};
	D3D12_RECT		m_scissorRect = {};

	shared_ptr<class Device>			m_device;
	shared_ptr<class CommandQueue>		m_cmdQueue;
	shared_ptr<class SwapChain>			m_swapChain;
	shared_ptr<class DescriptorHeap>	m_descHeap;
};

