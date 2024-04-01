#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>

// 색깔 정의
#define BLACK   0.0f, 0.0f, 0.0f, 1.0f
#define RED     1.0f, 0.0f, 0.0f, 1.0f
#define GREEN   0.0f, 1.0f, 0.0f, 1.0f
#define BLUE    0.0f, 0.0f, 1.0f, 1.0f
#define MAGENTA 1.0f, 0.0f, 1.0f, 1.0f

// 현재 색깔 저장
float currentColor[4] = { BLACK };

void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // 오른쪽 마우스 버튼
    if (key == GLFW_MOUSE_BUTTON_RIGHT)
    {
        // 누름
        if (action == GLFW_PRESS)
        {
            // 빨간색
            glClearColor(RED);
            currentColor[0] = RED;
            currentColor[1] = RED;
            currentColor[2] = RED;
            currentColor[3] = RED;
        }
        // 뗌
        else if (action == GLFW_RELEASE)
        {
            // 원래 색깔 복구
            glClearColor(currentColor[0], currentColor[1], currentColor[2], currentColor[3]);
        }
    }
    // 왼쪽 마우스 버튼
    else if (key == GLFW_MOUSE_BUTTON_LEFT)
    {
        // 누름
        if (action == GLFW_PRESS)
        {
            // 녹색
            glClearColor(GREEN);
            currentColor[0] = GREEN;
            currentColor[1] = GREEN;
            currentColor[2] = GREEN;
            currentColor[3] = GREEN;
        }
        // 뗌
        else if (action == GLFW_RELEASE)
        {
            // 원래 색깔 복구
            glClearColor(currentColor[0], currentColor[1], currentColor[2], currentColor[3]);
        }
    }
}

int main(void)
{
    //glfw라이브러리 초기화
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetMouseButtonCallback(window, keyCallback);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}