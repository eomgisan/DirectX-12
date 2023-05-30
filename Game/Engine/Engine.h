#pragma once

#include "Device.h"
#include "CommandQueue.h"
#include "SwapChain.h"
#include "RootSignature.h"
#include "TableDescriptorHeap.h"
#include "Texture.h"
#include "DepthStencilBuffer.h"
#include "ConstantBuffer.h"

#include "Mesh.h"
#include "Shader.h"


#include "Input.h"
#include "Timer.h"

class Engine
{
public:

	void Init(const WindowInfo& info);
	void Render();

public:
	void Update();

public:
	inline shared_ptr<Device> GetDevice() { return _device; }
	inline shared_ptr<CommandQueue> GetCmdQueue() { return _cmdQueue; }
	inline shared_ptr<SwapChain> GetSwapChain() { return _swapChain; }
	inline shared_ptr<RootSignature> GetRootSignature() { return _rootSignature; }
	inline shared_ptr<ConstantBuffer> GetConstantBuffer(CONSTANT_BUFFER_TYPE type) { return _constantBuffers[static_cast<uint8>(type)]; }
	inline shared_ptr<TableDescriptorHeap> GetTableDescHeap() { return _tableDescHeap; }
	inline shared_ptr<DepthStencilBuffer> GetDepthStencilBuffer() { return _depthStencilBuffer; }

	inline shared_ptr<Input> GetInput() { return _input; }
	inline shared_ptr<Timer> GetTimer() { return _timer; }

public:
	void RenderBegin();
	void RenderEnd();

	void ResizeWindow(int32 width, int32 height);


private:
	void ShowFPS();
	void CreateConstantBuffer(CBV_REGISTER reg, uint32 buffersize, uint32 count);


private:
	// 그려질 화면 크기 관련
	WindowInfo		_window;
	D3D12_VIEWPORT	_viewport = {};
	D3D12_RECT		_scissorRect = {};

	shared_ptr<Device> _device;
	shared_ptr<CommandQueue> _cmdQueue;
	shared_ptr<SwapChain> _swapChain;
	shared_ptr<RootSignature> _rootSignature;
	shared_ptr<TableDescriptorHeap> _tableDescHeap;
	shared_ptr<DepthStencilBuffer> _depthStencilBuffer;
	vector<shared_ptr<ConstantBuffer>> _constantBuffers;


	shared_ptr<Input> _input;
	shared_ptr<Timer> _timer;
};

