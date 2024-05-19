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

// 두번째 변경점은 Initialize 함수이다.
// 여기서 D3DClass 객체를 생성하고 Initialize를 호출한다.
// 이 함수로 화면 너비, 높이, 핸들과 GraphicsClass.h의 전역변수 4개를 보낸다.
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

// 다음 변경점은 ShutDown 함수이다.
// D3DClass의 종료도 여기에서 호출한다.
// 포인터가 초기화되어 삭제가 필요한 유효 상태인지 확인하고 삭제하는 것이 중요하다.
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

// 매프레임 Render 함수를 호출하도록 변경되었다.
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

// 화면을 지우기 위해 m_Direct3D 개체를 호출하고 EndScene을 호출해 회색 창이 표시되도록 한다.
bool GraphicsClass::Render()
{
	// Clear the buffers to begin the scene.
	m_Direct3D->BeginScene(1.0f, 0.0f, 0.0f, 1.0f);


	// Present the rendered scene to the screen.
	m_Direct3D->EndScene();

	return true;
}