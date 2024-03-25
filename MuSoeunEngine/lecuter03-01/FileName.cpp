#include <iostream>
#include <limits> // For std::numeric_limits

enum ForeColour {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
};


// �ֿܼ� ������ �����ϴ� �Լ�
void setConsoleColour(ForeColour colour) {
    std::cout << "\x1b[" << static_cast<int>(colour) << "m";
}

// �׸� �׸��� �Լ�
void drawSquare(ForeColour colour) {
    setConsoleColour(colour);
    std::cout << "��" << std::endl;
    // �⺻ �������� ���ư�
    setConsoleColour(Default);
}

int main() {
    std::cout << "ȭ�鿡 �׸� �׸��� ������ �����ϼ���." << std::endl;
    std::cout << "��ȿ�� ���� Ű�ڵ�: Black(30), Red(31), Green(32), Yellow(33), Blue(34), Magenta(35), Cyan(36), White(37)" << std::endl;
    std::cout << "���α׷��� �����Ϸ��� 64�� �Է��ϼ���." << std::endl;

    int userInput;
    bool isValidInput;

    while (true) {
        std::cout << "���� Ű�ڵ带 �Է��ϼ���: ";
        std::cin >> userInput;

       
        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "�ùٸ��� ���� �Է��Դϴ�. �ٽ� �õ��ϼ���." << std::endl;
            continue;
        }

        // ��ȿ�� Ű�ڵ����� Ȯ��
        isValidInput = (userInput == Black || userInput == Red || userInput == Green ||
            userInput == Yellow || userInput == Blue || userInput == Magenta ||
            userInput == Cyan || userInput == White || userInput == 64);

        if (!isValidInput) {
            std::cout << "�ùٸ��� ���� ���� Ű�ڵ��Դϴ�. �ٽ� �õ��ϼ���." << std::endl;
            continue;
        }

        
        if (userInput == 64) {
            std::cout << "���α׷��� �����մϴ�." << std::endl;
            break;
        }

        drawSquare(static_cast<ForeColour>(userInput));
    }

    return 0;
}