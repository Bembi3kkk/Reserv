#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Reservoir {
private:
    const string name;
    double width;
    double length;
    double max_depth;

public:
    explicit Reservoir(const string& reservoir_name)
        : name(reservoir_name), width(0), length(0), max_depth(0) {}
    Reservoir(const string& reservoir_name, double reservoir_width, double reservoir_length, double reservoir_max_depth)
        : name(reservoir_name), width(reservoir_width), length(reservoir_length), max_depth(reservoir_max_depth) {}
    double approximateVolume() const {
        return width * length * max_depth;
    }
    double surfaceArea() const {
        return width * length;
    }
    const string& getName() const {
        return name;
    }
    double getWidth() const {
        return width;
    }
    double getLength() const {
        return length;
    }
    double getMaxDepth() const {
        return max_depth;
    }
    void setWidth(double reservoir_width) {
        width = reservoir_width;
    }
    void setLength(double reservoir_length) {
        length = reservoir_length;
    }
    void setMaxDepth(double reservoir_max_depth) {
        max_depth = reservoir_max_depth;
    }
};

int main() {
    Reservoir lake("Озеро ", 50, 100, 5);
    Reservoir pond("Пруд ", 10, 10, 2);

    cout << "Информация о водоемах:\n";
    cout << "Название: " << lake.getName() << ", Площадь поверхности: " << lake.surfaceArea() << endl;
    cout << "Название: " << pond.getName() << ", Площадь поверхности: " << pond.surfaceArea() << endl;


    vector<Reservoir> reservoirs;
    reservoirs.push_back(lake);
    reservoirs.push_back(pond);


    ofstream outFile("reservoirs.txt");
    if (outFile.is_open()) {
        for (const auto& reservoir : reservoirs) {
            outFile << "Название: " << reservoir.getName() << ", Площадь поверхности: " << reservoir.surfaceArea() << "\n";
        }
        outFile.close();
        cout << "Данные записаны в файл reservoirs.txt\n";
    }
    else {
        cerr << "Ошибка открытия файла\n";
    }

    return 0;
}
