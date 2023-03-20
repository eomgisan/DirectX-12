#include "pch.h"
#include "Device.h"

void Device::Init()
{
	//D3D12 ������� Ȱ��ȭ
	// - VC++ ���â�� ���� ����� �޼��� ���
	// - riid : ����̽��� COM ID
	// - ppDevice : ������ ��ġ�� �Ű������� ����
#ifdef _DEBUG
	::D3D12GetDebugInterface(IID_PPV_ARGS(&m_debugController));
	m_debugController->EnableDebugLayer();

#endif

	// DXGI(DirectX Graphics Infrastructure)
	// Direct3D �� �Բ� ���̴� API
	// - ��üȭ�� ��� ��ȯ
	// - �����Ǵ� ���÷��� ��� ����
	// CreateDXGIFactory
	// - riid : ����̽��� COM ID
	// - ppDevice : ������ ��ġ�� �Ű������� ����
	::CreateDXGIFactory(IID_PPV_ARGS(&m_dxgi));

	// CreateDevice
	// - �𽺺��� �����( �׷���ī�� ) �� ��Ÿ���� ��ü
	// - pAdapter : nullptr �����ϸ� �ý��� �⺻ ���÷��� �����
	// - MinimunFeatureLevel : ���� ���α׷��� �䱸�ϴ� �ּ� ��� ����
	// - riid : ����̽��� COM ID
	// - ppDevice : ������ ��ġ�� �Ű������� ����
	::D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&m_device));
}