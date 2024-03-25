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


// 콘솔에 색상을 설정하는 함수
void setConsoleColour(ForeColour colour) {
    std::cout << "\x1b[" << static_cast<int>(colour) << "m";
}

// 네모를 그리는 함수
void drawSquare(ForeColour colour) {
    setConsoleColour(colour);
    std::cout << "▣" << std::endl;
    // 기본 색상으로 돌아감
    setConsoleColour(Default);
}

int main() {
    std::cout << "화면에 그릴 네모의 색상을 선택하세요." << std::endl;
    std::cout << "유효한 색상 키코드: Black(30), Red(31), Green(32), Yellow(33), Blue(34), Magenta(35), Cyan(36), White(37)" << std::endl;
    std::cout << "프로그램을 종료하려면 64를 입력하세요." << std::endl;

    int userInput;
    bool isValidInput;

    while (true) {
        std::cout << "색상 키코드를 입력하세요: ";
        std::cin >> userInput;

       
        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "올바르지 않은 입력입니다. 다시 시도하세요." << std::endl;
            continue;
        }

        // 유효한 키코드인지 확인
        isValidInput = (userInput == Black || userInput == Red || userInput == Green ||
            userInput == Yellow || userInput == Blue || userInput == Magenta ||
            userInput == Cyan || userInput == White || userInput == 64);

        if (!isValidInput) {
            std::cout << "올바르지 않은 색상 키코드입니다. 다시 시도하세요." << std::endl;
            continue;
        }

        
        if (userInput == 64) {
            std::cout << "프로그램을 종료합니다." << std::endl;
            break;
        }

        drawSquare(static_cast<ForeColour>(userInput));
    }

    return 0;
}