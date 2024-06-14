#pragma comment(lib, "Opengl32.lib")

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <cmath>
#include "object.h"

void errorCallback(int error, const char* description)
{
    printf("GLFW 오류: %s\n", description);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // 키 입력 콜백 함수 (현재 아무 동작 안 함)
}

int Physics()
{
    // 물리 처리 함수 (현재 아무 동작 안 함)
    return 0;
}

int Initialize()
{
    // 초기화 함수 (현재 아무 동작 안 함)
    return 0;
}

int Update()
{
    // 업데이트 함수 (현재 아무 동작 안 함)
    return 0;
}

int Render()
{
    // 렌더링 함수 (현재 아무 동작 안 함)
    return 0;
}

void RenderObjects() {
    RenderEnemyBlocks();
    RenderFloor();
}

int main(void)
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // glfw 라이브러리 초기화
    if (!glfwInit())
        return -1;

    // 윈도우 생성
    GLFWwindow* window;
    window = glfwCreateWindow(800, 600, "Google Dino Run Copy Game", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // 컨텍스트를 현재 쓰레드의 주 컨텍스트로 만듦
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);

    // 초기화 함수 호출
    Initialize();

    // 메인 루프
    while (!glfwWindowShouldClose(window))
    {
        // 이벤트 처리
        glfwPollEvents();

        // 물리 처리
        Physics();

        // 업데이트
        Update();

        // 화면 지우기 (배경색: 하늘색)
        glClearColor(0.0f, 0.1176f, 0.3922f, 1.0f); // R: 0, G: 30/255, B: 100/255
        glClear(GL_COLOR_BUFFER_BIT);

        // 렌더링
        RenderObjects();

        // 버퍼 교체
        glfwSwapBuffers(window);
    }

    // GLFW 종료
    glfwTerminate();
    return 0;
}



