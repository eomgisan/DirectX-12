#pragma once


// ��ȯ�罽
// [���� ����]
// - ���� ���� ���� �ִ� ��Ȳ�� ����
// - � �������� ��� ������� ������
// - GPU�� ������ ��� ( ���� )
// - ������� �޾Ƽ� ȭ�鿡 �׷��ش�.

// [ ���� ����� ] �� ��� ����?
// - � ����( Buffer )�� �׷��� �ǳ��޶�����
// - Ư�� ���̸� ���� -> ó���� �ǳ��ְ� -> ������� �ش� ���̿� �޴´�.
// - �츮 ȭ�鿡 Ư�� ���̸� ����Ѵ�.

// [?]
// - �׷��� ȭ�鿡 ���� ����� ����ϴ� ���߿�, ���� ȭ�鵵 ���� �ðܾ���
// - ���� ȭ�� ������� �̹� ȭ�� ��¿� �����
// - Ư������ 2�� ���� �ϳ��� �׸��� �ϳ��� ���� ����
// - �̰� �ٷ� double buffering

// - [1~2]
// ����ȭ�� [1] <-> GPU �۾��� [2] BackBuffer


class SwapChain
{
public:
	void Init(const WindowInfo& _info, ComPtr<IDXGIFactory> _dxgi, ComPtr<ID3D12CommandQueue> _cmdQueue);
	void Present();
	void SwapIndex();

	ComPtr<IDXGISwapChain> GetSwapChain() { return m_swapChain; }
	ComPtr<ID3D12Resource> GetRenderTarget(int32 index) { return m_renderTargets[index]; }

	uint32 GetCurrentBackBufferIndex() { return m_backBufferIndex; }
	ComPtr<ID3D12Resource> GetCurrentBackBufferResource() { return m_renderTargets[m_backBufferIndex]; }
private:

	ComPtr<IDXGISwapChain>	m_swapChain;
	ComPtr<ID3D12Resource>	m_renderTargets[SWAP_CHAIN_BUFFER_COUNT];
	uint32					m_backBufferIndex = 0;
};

