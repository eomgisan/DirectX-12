#pragma once

class SwapChain;
class DescriptorHeap;


class CommandQueue
{
public:

	void Init(ComPtr<ID3D12Device> _device, shared_ptr<SwapChain> _swapChain, shared_ptr<DescriptorHeap> _descHeap);
	void WaitSync();

	void RenderBegin(const D3D12_VIEWPORT* _vp, const D3D12_RECT* _rect);
	void RenderEnd();

	ComPtr<ID3D12CommandQueue> GetCmdQueue() { return m_cmdQueue; }

	~CommandQueue();

private:

	// Command Queue : DX12�� ����
	// ���ָ� ��û�� ��, �ϳ��� ��û�ϸ� ��ȿ����
	// [���� ���]�� �ϰ��� �������� ����ߴ� �ѹ��� ��û����

	ComPtr<ID3D12CommandQueue>			m_cmdQueue;
	ComPtr<ID3D12CommandAllocator>		m_cmdAlloc;
	ComPtr<ID3D12GraphicsCommandList>	m_cmdList;


	// Fence : ��Ÿ�� ( ����� ��� �����Ҷ����� ��ٷ��ְڴ� )
	// CPU / GPU ����ȭ�� ���� ������ ����
	ComPtr<ID3D12Fence>					m_fence;
	uint32								m_fenceValue = 0;
	HANDLE								m_fenceEvent = INVALID_HANDLE_VALUE;

	shared_ptr<SwapChain>				m_swapChain;
	shared_ptr<DescriptorHeap>			m_descHeap;

};

