#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>

// ���� ����
#define BLACK   0.0f, 0.0f, 0.0f, 1.0f
#define RED     1.0f, 0.0f, 0.0f, 1.0f
#define GREEN   0.0f, 1.0f, 0.0f, 1.0f
#define BLUE    0.0f, 0.0f, 1.0f, 1.0f
#define MAGENTA 1.0f, 0.0f, 1.0f, 1.0f

// ���� ���� ����
float currentColor[4] = { BLACK };

void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // ������ ���콺 ��ư
    if (key == GLFW_MOUSE_BUTTON_RIGHT)
    {
        // ����
        if (action == GLFW_PRESS)
        {
            // ������
            glClearColor(RED);
            currentColor[0] = RED;
            currentColor[1] = RED;
            currentColor[2] = RED;
            currentColor[3] = RED;
        }
        // ��
        else if (action == GLFW_RELEASE)
        {
            // ���� ���� ����
            glClearColor(currentColor[0], currentColor[1], currentColor[2], currentColor[3]);
        }
    }
    // ���� ���콺 ��ư
    else if (key == GLFW_MOUSE_BUTTON_LEFT)
    {
        // ����
        if (action == GLFW_PRESS)
        {
            // ���
            glClearColor(GREEN);
            currentColor[0] = GREEN;
            currentColor[1] = GREEN;
            currentColor[2] = GREEN;
            currentColor[3] = GREEN;
        }
        // ��
        else if (action == GLFW_RELEASE)
        {
            // ���� ���� ����
            glClearColor(currentColor[0], currentColor[1], currentColor[2], currentColor[3]);
        }
    }
}

int main(void)
{
    //glfw���̺귯�� �ʱ�ȭ
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