#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

float M_PI = 3.14159265358979323846f;

void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}

// �¾�� ���̵��� ���� �ӵ� (1ȸ���� �ɸ��� �ð�)
const float sunRotationPeriod = 30.0f;
const float earthRevolutionPeriod = 60.0f; // ������ ���� �ֱ�
const float earthRotationPeriod = 10.0f; // ������ ���� �ֱ�
// ���� ���� �ֱ�� ���� �ֱ�
const float moonRevolutionPeriod = 3.0f;
const float moonRotationPeriod = 3.0f;

void rotatePoint(float& x, float& y, float angle)
{
    float newX = x * cos(angle) - y * sin(angle);
    float newY = x * sin(angle) + y * cos(angle);
    x = newX;
    y = newY;
}

void drawRotatedEllipse(float x, float y, float radiusX, float radiusY, int segments, float angle, float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Ÿ���� �߽�

    for (int i = 0; i <= segments; ++i)
    {
        float ellipseAngle = 2.0f * M_PI * float(i) / float(segments);
        float dx = radiusX * cos(ellipseAngle);
        float dy = radiusY * sin(ellipseAngle);
        rotatePoint(dx, dy, angle); // ȸ��
        glVertex2f(x + dx, y + dy);
    }

    glEnd();
}

void drawCircle(float x, float y, float radius, int segments, float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // ���� �߽�
    for (int i = 0; i <= segments; i++)
    {
        float angle = 2.0f * M_PI * float(i) / float(segments);
        float dx = radius * cosf(angle);
        float dy = radius * sinf(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void drawSquare(float x, float y, float size, float rotationAngle, float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_QUADS);

    float halfSize = size / 2.0f;

    // �׸��� �� ���� ȸ����Ű�鼭 �׸���
    for (int i = 0; i < 4; ++i)
    {
        float dx = (i == 0 || i == 3) ? -halfSize : halfSize;
        float dy = (i < 2) ? -halfSize : halfSize;
        rotatePoint(dx, dy, rotationAngle);
        glVertex2f(x + dx, y + dy);
    }

    glEnd();
}

void drawStar(float x, float y, float size, float rotationAngle, float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // ���� �߽�

    float outerRadius = size / 2.0f;
    float innerRadius = outerRadius * 0.382f; // ���� ���� ������

    for (int i = 0; i < 11; ++i)
    {
        float angle = rotationAngle + i * M_PI / 5.0f;
        float radius = (i % 2 == 0) ? outerRadius : innerRadius;
        float dx = radius * cos(angle);
        float dy = radius * sin(angle);
        glVertex2f(x + dx, y + dy);
        angle += M_PI / 10.0f; // ���� ������ �ʵ��� ������ �����մϴ�.
    }

    glEnd();
}

void drawMoon(float x, float y, float size, float rotationAngle)
{
    drawStar(x, y, size, rotationAngle, 1.0f, 1.0f, 1.0f);
}

float sunAngle = 0.0f;
float earthAngle = 0.0f;
float earthRotationAngle = 0.0f;
float moonAngle = 0.0f;
float moonRotationAngle = 0.0f;

double previousTime = 0.0;

void render(double deltaTime)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // �¾��� ����
    sunAngle += (2.0f * M_PI) / sunRotationPeriod * deltaTime;

    // �¾� �׸���
    drawCircle(0.0f, 0.0f, 0.3f, 100, 1.0f, 0.65f, 0.0f); // �¾�

    // ���̵� �׸���
    float patternRotationSpeed = (2.0f * M_PI) / sunRotationPeriod;

    // ���� 1��
    float pattern1X = -0.15f;
    float pattern1Y = 0.0f;
    rotatePoint(pattern1X, pattern1Y, sunAngle);
    drawCircle(pattern1X, pattern1Y, 0.12f, 50, 1.0f, 0.76f, 0.54f);

    // ���� 2��
    float pattern2X = 0.2f;
    float pattern2Y = -0.15f;
    rotatePoint(pattern2X, pattern2Y, sunAngle);
    drawRotatedEllipse(pattern2X, pattern2Y, 0.02f, 0.1f, 50, -M_PI / 4 + sunAngle, 1.0f, 0.55f, 0.0f);

    // ������ ����
    earthAngle += (2.0f * M_PI) / earthRevolutionPeriod * deltaTime;

    // ������ ����
    earthRotationAngle += (2.0f * M_PI) / earthRotationPeriod * deltaTime;

    // ���� �׸���
    float earthX = 0.6f;
    float earthY = 0.0f;
    rotatePoint(earthX, earthY, earthAngle);
    drawSquare(earthX, earthY, 0.1f, earthRotationAngle, 0.0f, 0.0f, 1.0f); // �׸� ����

    // ���� ����
    moonAngle += (2.0f * M_PI) / moonRevolutionPeriod * deltaTime;

    // ���� ����
    moonRotationAngle -= (2.0f * M_PI) / moonRotationPeriod * deltaTime;

    // �� �׸���
    float moonX = 0.15f;
    float moonY = 0.0f;
    rotatePoint(moonX, moonY, moonAngle);
    moonX += earthX; // ������ ��ġ�� �������� ���� ��ġ ���
    moonY += earthY;
    drawMoon(moonX, moonY, 0.08f, moonRotationAngle); // ���� �� ������� �׸���
}


int main(void)
{
    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(800, 800, "Solar System Simulation", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);

    glViewport(0, 0, 800, 800);

    previousTime = glfwGetTime();

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        double currentTime = glfwGetTime();
        double deltaTime = currentTime - previousTime;
        previousTime = currentTime;

        render(deltaTime);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
