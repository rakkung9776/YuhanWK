#include "object.h"
#include <GLFW/glfw3.h>

// 렌더링 함수 정의
void RenderEnemyBlocks() {
    // Render enemy blocks
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glBegin(GL_QUADS);
    glVertex2i(300, 100); // Assume position and dimensions
    glVertex2i(350, 100);
    glVertex2i(350, 200);
    glVertex2i(300, 200);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(500, 100); // Assume position and dimensions
    glVertex2i(550, 100);
    glVertex2i(550, 400);
    glVertex2i(500, 400);
    glEnd();
}
void RenderFloor() {
    // Render floor
    glColor3f(1.0f, 0.7843f, 0.0588f); // Yellow color
    glBegin(GL_QUADS);
    glVertex2i(-25, -75); // Bottom left corner
    glVertex2i(25, -75);  // Bottom right corner
    glVertex2i(-25, -0.);   // Top right corner
    glVertex2i(-25, -1);  // Top left corner
    glEnd();
}







int PhysicsAABB(Object& A, Object& B) {
    // AABB 충돌 감지 구현
    return 0;
}
