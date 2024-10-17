#include <iostream>
#include <vector>

// ����������� ���� ��� ������������
class Rectangle {
private:
    //��������
    int x, y;    // ����������
    int width, height; // ������

public:
    // �����������
    Rectangle(int x, int y, int width, int height)
        : x(x), y(y), width(width), height(height) {
        std::cout << "��'��� ��������: (" << x << ", " << y << "), "
            << "������: " << width << ", ������: " << height << std::endl;
    }

    // �� ����� ��� ��������� ������ ������������ � ������ ������������
    Rectangle move(int newX, int newY) const {
        return Rectangle(newX, newY, width, height);
    }

    // ����� ��� ��������� ������ ������������ � ������ ��������
    Rectangle resize(int newWidth, int newHeight) const {
        return Rectangle(x, y, newWidth, newHeight);
    }

    // ����� ��� ��������� ���������� ��� �����������
    void draw() const {
        std::cout << "�����������: ���������� (" << x << ", " << y
            << "), ������: " << width << ", ������: " << height << std::endl;
    }
};

// ���� ��� ��������� ��������� ������������
class RectangleChain {
private:
    std::vector<Rectangle> rectangles; // �������� ��� ������������

public:
    // ������ ����� ����������� �� ��������
    void addRectangle(const Rectangle& rect) {
        rectangles.push_back(rect);
    }

    // ��������� - ����������� �� ������������
    void update() const {
        std::cout << "��������� ���������� ��� ������������:" << std::endl;
        for (const auto& rect : rectangles) {
            rect.draw();
        }
    }
};

int main() {
    setlocale(LC_ALL, "ukr");
    // ��������� �������� ������������
    RectangleChain chain;

    // ��������� ���������� �����������
    Rectangle rect1(10, 20, 100, 200);
    chain.addRectangle(rect1); // ������ � ��������

    // ��������� ����� ����������� � ������ ������������ (�������� ��'���)
    Rectangle rect2 = rect1.move(30, 40);
    chain.addRectangle(rect2); // ������ ����� ��'���

    // ��������� ����� ����������� � ������ ��������
    Rectangle rect3 = rect2.resize(120, 240);
    chain.addRectangle(rect3); // ������ ����� ��'���

    // ����������� �� ������� ������������
    chain.update();

    return 0;
}
