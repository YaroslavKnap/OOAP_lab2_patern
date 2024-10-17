#include <iostream>
#include <vector>

// реалізований Клас для прямокутника
class Rectangle {
private:
    //значення
    int x, y;    // Координати
    int width, height; // Розміри

public:
    // Конструктор
    Rectangle(int x, int y, int width, int height)
        : x(x), y(y), width(width), height(height) {
        std::cout << "Об'єкт створено: (" << x << ", " << y << "), "
            << "ширина: " << width << ", висота: " << height << std::endl;
    }

    // ці Метод для отримання нового прямокутника з новими координатами
    Rectangle move(int newX, int newY) const {
        return Rectangle(newX, newY, width, height);
    }

    // Метод для отримання нового прямокутника з новими розмірами
    Rectangle resize(int newWidth, int newHeight) const {
        return Rectangle(x, y, newWidth, newHeight);
    }

    // Метод для виведення інформації про прямокутник
    void draw() const {
        std::cout << "Прямокутник: координати (" << x << ", " << y
            << "), ширина: " << width << ", висота: " << height << std::endl;
    }
};

// Клас для управління ланцюжком прямокутників
class RectangleChain {
private:
    std::vector<Rectangle> rectangles; // Колекція всіх прямокутників

public:
    // Додати новий прямокутник до ланцюжка
    void addRectangle(const Rectangle& rect) {
        rectangles.push_back(rect);
    }

    // Оновлення - прорисувати всі прямокутники
    void update() const {
        std::cout << "Оновлення прорисовки всіх прямокутників:" << std::endl;
        for (const auto& rect : rectangles) {
            rect.draw();
        }
    }
};

int main() {
    setlocale(LC_ALL, "ukr");
    // Створюємо ланцюжок прямокутників
    RectangleChain chain;

    // Створюємо початковий прямокутник
    Rectangle rect1(10, 20, 100, 200);
    chain.addRectangle(rect1); // Додаємо в ланцюжок

    // Створюємо новий прямокутник з новими координатами (незмінний об'єкт)
    Rectangle rect2 = rect1.move(30, 40);
    chain.addRectangle(rect2); // Додаємо новий об'єкт

    // Створюємо новий прямокутник з новими розмірами
    Rectangle rect3 = rect2.resize(120, 240);
    chain.addRectangle(rect3); // Додаємо новий об'єкт

    // Прорисовуємо всі створені прямокутники
    chain.update();

    return 0;
}
