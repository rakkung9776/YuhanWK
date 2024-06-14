#pragma once

#include <iostream>

class Object {
public:
    virtual void OnCollisionEnter(Object& other) {
        std::cout << "�⺻ �浹 ó��\n";
    }
};

class Player : public Object {
public:
    void OnCollisionEnter(Object& other) override {
        std::cout << "�÷��̾ �ٸ� ������Ʈ�� �浹�߽��ϴ�\n";
    }
};

class EnemyBlock : public Object {
public:
    void OnCollisionEnter(Object& other) override {
        std::cout << "�� ����� �ٸ� ������Ʈ�� �浹�߽��ϴ�\n";
    }
};

class Floor : public Object {
public:
    void OnCollisionEnter(Object& other) override {
        std::cout << "�ٴ��� �ٸ� ������Ʈ�� �浹�߽��ϴ�\n";
    }
};

class Star : public Object {
public:
    void OnCollisionEnter(Object& other) override {
        std::cout << "���� �ٸ� ������Ʈ�� �浹�߽��ϴ�\n";
    }
};

int PhysicsAABB(Object& A, Object& B);

// Render �Լ� ����
void RenderEnemyBlocks();
void RenderFloor();


