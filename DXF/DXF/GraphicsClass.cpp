#include "GraphicsClass.h"


GraphicsClass::GraphicsClass()
{
}

GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}

GraphicsClass::~GraphicsClass()
{
}

// �ι�° �������� Initialize �Լ��̴�.
// ���⼭ D3DClass ��ü�� �����ϰ� Initialize�� ȣ���Ѵ�.
// �� �Լ��� ȭ�� �ʺ�, ����, �ڵ�� GraphicsClass.h�� �������� 4���� ������.
bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;

	// Create the Direct3D object.
	m_Direct3D = new D3DClass;
	if (!m_Direct3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_Direct3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D", L"Error", MB_OK);
		return false;
	}

	return true;
}

// ���� �������� ShutDown �Լ��̴�.
// D3DClass�� ���ᵵ ���⿡�� ȣ���Ѵ�.
// �����Ͱ� �ʱ�ȭ�Ǿ� ������ �ʿ��� ��ȿ �������� Ȯ���ϰ� �����ϴ� ���� �߿��ϴ�.
void GraphicsClass::Shutdown()
{
	// Release the Direct3D object.
	if (m_Direct3D)
	{
		m_Direct3D->Shutdown();
		delete m_Direct3D;
		m_Direct3D = 0;
	}

	return;
}

// �������� Render �Լ��� ȣ���ϵ��� ����Ǿ���.
bool GraphicsClass::Frame()
{
	bool result;

	// Render the graphics scene.
	result = Render();
	if (!result)
	{
		return false;
	}

	return true;
}

// ȭ���� ����� ���� m_Direct3D ��ü�� ȣ���ϰ� EndScene�� ȣ���� ȸ�� â�� ǥ�õǵ��� �Ѵ�.
bool GraphicsClass::Render()
{
	// Clear the buffers to begin the scene.
	m_Direct3D->BeginScene(1.0f, 0.0f, 0.0f, 1.0f);


	// Present the rendered scene to the screen.
	m_Direct3D->EndScene();

	return true;
}