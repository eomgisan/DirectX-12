#include "pch.h"
#include "Engine.h"
#include "Device.h"
#include "SwapChain.h"
#include "DescriptorHeap.h"
#include "CommandQueue.h"



void Engine::Init(const WindowInfo& _window)
{
	m_window = _window;

	ResizeWindow(m_window.width, m_window.height);

	// 그려질 화면 크기를 설정
	m_viewprot = { 0,0,static_cast<FLOAT>(_window.width), static_cast<FLOAT>(_window.height), 0.0f, 1.0f };
	m_scissorRect = CD3DX12_RECT(0, 0, _window.width, _window.height);


	m_device	= make_shared<Device>();
	m_cmdQueue	= make_shared<CommandQueue>();
	m_swapChain	= make_shared<SwapChain>();
	m_descHeap	= make_shared<DescriptorHeap>();

	m_device->Init();
	m_cmdQueue->Init(m_device->GetDevice(), m_swapChain, m_descHeap);
	m_swapChain->Init(m_window, m_device->GetDXGI(), m_cmdQueue->GetCmdQueue());
	m_descHeap->Init(m_device->GetDevice(), m_swapChain);
}

void Engine::Render()
{
	RenderBegin();

		// TODO : 나머지 물체들 그려준다.

	RenderEnd();
}

void Engine::ResizeWindow(int32 _width, int32 _height)
{
	m_window.width = _width;
	m_window.height = _height;
	RECT rect = { 0, 0, _width, _height };
	::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
	::SetWindowPos(m_window.hwnd, 0, 100, 100, _width, _height, 0);
}

void Engine::RenderBegin()
{
	m_cmdQueue->RenderBegin(&m_viewprot, &m_scissorRect);
}

void Engine::RenderEnd()
{
	m_cmdQueue->RenderEnd();
}
