#pragma once

#include <iostream>

class Object {
public:
    virtual void OnCollisionEnter(Object& other) {
        std::cout << "기본 충돌 처리\n";
    }
};

class Player : public Object {
public:
    void OnCollisionEnter(Object& other) override {
        std::cout << "플레이어가 다른 오브젝트와 충돌했습니다\n";
    }
};

class EnemyBlock : public Object {
public:
    void OnCollisionEnter(Object& other) override {
        std::cout << "적 블록이 다른 오브젝트와 충돌했습니다\n";
    }
};

class Floor : public Object {
public:
    void OnCollisionEnter(Object& other) override {
        std::cout << "바닥이 다른 오브젝트와 충돌했습니다\n";
    }
};

class Star : public Object {
public:
    void OnCollisionEnter(Object& other) override {
        std::cout << "별이 다른 오브젝트와 충돌했습니다\n";
    }
};

int PhysicsAABB(Object& A, Object& B);

// Render 함수 선언
void RenderEnemyBlocks();
void RenderFloor();


