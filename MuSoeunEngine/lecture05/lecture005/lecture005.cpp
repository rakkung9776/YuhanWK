#pragma comment(lib, "Opengl32.lib")

#include<GLFW/glfw3.h>
#include<iostream>

float moveFactor = 0.0f;
float scaleFactor = 1.0f;
double lastX, lastY;
bool isLeftMouseButtonPressed = false;
bool isRightMouseButtonPressed = false;

void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
    if (isLeftMouseButtonPressed)
    {
        float newY = (float)(ypos - lastY) / 384;
        moveFactor += newY;
        lastY = ypos;
    }
    if (isRightMouseButtonPressed)
    {
        float newX = (float)(xpos - lastX) / 640;
        scaleFactor += newX;
        lastX = xpos;
    }
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT)
    {
        if (action == GLFW_PRESS)
        {
            isLeftMouseButtonPressed = true;
            glfwGetCursorPos(window, &lastX, &lastY);
        }
        else if (action == GLFW_RELEASE)
        {
            isLeftMouseButtonPressed = false;
        }
    }
    if (button == GLFW_MOUSE_BUTTON_RIGHT)
    {
        if (action == GLFW_PRESS)
        {
            isRightMouseButtonPressed = true;
            glfwGetCursorPos(window, &lastX, &lastY);
        }
        else if (action == GLFW_RELEASE)
        {
            isRightMouseButtonPressed = false;
        }
    }
}

int render()
{
    glBegin(GL_TRIANGLES);

    // 첫 번째 삼각형
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0f, 0.5f * scaleFactor + moveFactor);
    glVertex2f(-0.1f * scaleFactor, 0.1f * scaleFactor + moveFactor);
    glVertex2f(0.1f * scaleFactor, 0.1f * scaleFactor + moveFactor);

    // 두 번째 삼각형
    glVertex2f(-0.4f, 0.1f * scaleFactor + moveFactor);
    glVertex2f(-0.1f * scaleFactor, -0.1f * scaleFactor + moveFactor);
    glVertex2f(0.05f * scaleFactor, 0.1f * scaleFactor + moveFactor);

    // 세 번째 삼각형
    glVertex2f(-0.1f, -0.1f * scaleFactor + moveFactor);
    glVertex2f(0.0f * scaleFactor, 0.1f * scaleFactor + moveFactor);
    glVertex2f(0.4f * scaleFactor, 0.1f * scaleFactor + moveFactor);

    // 네 번째 삼각형
    glVertex2f(-0.3f, -0.4f * scaleFactor + moveFactor);
    glVertex2f(0.0f * scaleFactor, 0.3f * scaleFactor + moveFactor);
    glVertex2f(0.0f * scaleFactor, -0.1f * scaleFactor + moveFactor);

    // 다섯 번째 삼각형
    glVertex2f(-0.09f, -0.1f * scaleFactor + moveFactor);
    glVertex2f(0.3f * scaleFactor, -0.4f * scaleFactor + moveFactor);
    glVertex2f(0.1f * scaleFactor, 0.0f * scaleFactor + moveFactor);

    glEnd();

    return 0;
}

int main(void)
{
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetCursorPosCallback(window, cursorPositionCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        render();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}

