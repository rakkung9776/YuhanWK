#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

float moveFactor = 0.0f;
float scaleFactor = 1.0f;

struct Vector2 {
    float x, y;
    Vector2(float _x, float _y) : x(_x), y(_y) {}
};

float randomFloat(float min, float max) {
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

// 랜덤한 색상 생성
float randomStarColor() {
    return randomFloat(0.0f, 1.0f); // 0과 1 사이의 랜덤한 값으로 설정
}

void drawStar(float x, float y, float r, float g, float b) {
    glBegin(GL_TRIANGLES);
    glColor3f(r, g, b);

    // 첫 번째 삼각형
    glVertex2f(x, y + 0.25f * scaleFactor + moveFactor);
    glVertex2f(x - 0.05f * scaleFactor, y + 0.05f * scaleFactor + moveFactor);
    glVertex2f(x + 0.05f * scaleFactor, y + 0.05f * scaleFactor + moveFactor);

    // 두 번째 삼각형
    glVertex2f(x - 0.2f, y + 0.05f * scaleFactor + moveFactor);
    glVertex2f(x - 0.05f * scaleFactor, y - 0.05f * scaleFactor + moveFactor);
    glVertex2f(x + 0.025f * scaleFactor, y + 0.05f * scaleFactor + moveFactor);

    // 세 번째 삼각형
    glVertex2f(x - 0.05f, y - 0.05f * scaleFactor + moveFactor);
    glVertex2f(x + 0.0f * scaleFactor, y + 0.05f * scaleFactor + moveFactor);
    glVertex2f(x + 0.2f * scaleFactor, y + 0.05f * scaleFactor + moveFactor);

    // 네 번째 삼각형
    glVertex2f(x - 0.15f, y - 0.2f * scaleFactor + moveFactor);
    glVertex2f(x + 0.0f * scaleFactor, y + 0.15f * scaleFactor + moveFactor);
    glVertex2f(x + 0.0f * scaleFactor, y - 0.05f * scaleFactor + moveFactor);

    // 다섯 번째 삼각형
    glVertex2f(x - 0.045f, y - 0.05f * scaleFactor + moveFactor);
    glVertex2f(x + 0.15f * scaleFactor, y - 0.2f * scaleFactor + moveFactor);
    glVertex2f(x + 0.05f * scaleFactor, y + 0.0f * scaleFactor + moveFactor);

    glEnd();
}

void renderStars(const std::vector<Vector2>& stars, const std::vector<float>& colors) {
    for (size_t i = 0; i < stars.size(); ++i) {
        float r = colors[i * 3];
        float g = colors[i * 3 + 1];
        float b = colors[i * 3 + 2];
        drawStar(stars[i].x, stars[i].y, r, g, b);
    }
}

int main() {
    // GLFW 초기화
    if (!glfwInit()) {
        std::cerr << "GLFW 초기화 실패" << std::endl;
        return -1;
    }

    // 윈도우 생성
    GLFWwindow* window = glfwCreateWindow(800, 600, "별 랜더링", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // OpenGL 컨텍스트를 현재 윈도우로 설정
    glfwMakeContextCurrent(window);

    // 별 랜더링을 위해 프레임 버퍼 크리어
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    std::srand(std::time(nullptr)); // 난수 생성기 시드 설정

    std::vector<Vector2> stars;
    std::vector<float> colors;
    bool starsGenerated = false;

    while (!glfwWindowShouldClose(window)) {
        // 이벤트 처리
        glfwPollEvents();

        // 프레임 버퍼 지우기
        glClear(GL_COLOR_BUFFER_BIT);

        // 별 렌더링
        if (!starsGenerated && stars.size() < 50) {
            // 새로운 별 생성
            stars.push_back(Vector2(randomFloat(-1.0f, 1.0f), randomFloat(-1.0f, 1.0f)));
            // 랜덤한 색상 생성
            colors.push_back(randomStarColor());
            colors.push_back(randomStarColor());
            colors.push_back(randomStarColor());
        }
        else {
            starsGenerated = true;
            // 이후 별 렌더링은 이전에 사용한 색상으로 고정
            renderStars(stars, colors);
        }

        // 프레임 버퍼 스왑
        glfwSwapBuffers(window);
    }

    // GLFW 종료
    glfwTerminate();
    return 0;
}




