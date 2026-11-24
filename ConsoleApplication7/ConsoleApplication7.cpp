#include <iostream>
#include <string>

using namespace std;

// Структура Вагон
struct Vagon {
    int number;
    int seats;
    int passengers;
};

class Train {
private:
    string model;
    int countVagons;
    Vagon* vagons;

public:

    // Конструктор за замовчуванням
    Train() {
        model = "Unknown";
        countVagons = 0;
        vagons = nullptr;
    }

    // Перевантажений конструктор
    Train(string model, int count) {
        this->model = model;
        this->countVagons = count;

        vagons = new Vagon[count];

        for (int i = 0; i < count; i++) {
            vagons[i].number = i + 1;
            vagons[i].seats = 50;
            vagons[i].passengers = 0;
        }
    }

    // Конструктор копіювання
    Train(const Train& other) {
        model = other.model;
        countVagons = other.countVagons;

        vagons = new Vagon[countVagons];

        for (int i = 0; i < countVagons; i++) {
            vagons[i] = other.vagons[i];
        }
    }

    // Деструктор
    ~Train() {
        delete[] vagons;
    }

    // Виведення інформації
    void Show() {
        cout << "\nМодель потяга: " << model << endl;
        cout << "Кількість вагонів: " << countVagons << endl;

        for (int i = 0; i < countVagons; i++) {
            cout << "\nВагон №" << vagons[i].number << endl;
            cout << "Місць: " << vagons[i].seats << endl;
            cout << "Пасажирів: " << vagons[i].passengers << endl;
        }
    }

    // Додати вагон
    void AddVagon(int seats) {
        Vagon* temp = new Vagon[countVagons + 1];

        for (int i = 0; i < countVagons; i++) {
            temp[i] = vagons[i];
        }

        temp[countVagons].number = countVagons + 1;
        temp[countVagons].seats = seats;
        temp[countVagons].passengers = 0;

        delete[] vagons;
        vagons = temp;

        countVagons++;
    }

    // Додати пасажира у вагон
    void AddPassenger(int wagonNumber) {
        for (int i = 0; i < countVagons; i++) {

            if (vagons[i].number == wagonNumber) {

                if (vagons[i].passengers < vagons[i].seats) {
                    vagons[i].passengers++;
                    cout << "Пасажира додано.\n";
                }
                else {
                    cout << "У вагоні немає вільних місць!\n";
                }

                return;
            }
        }

        cout << "Вагон не знайдено!\n";
    }
};

int main() {

    Train train1("Hyundai Rotem", 2);

    train1.Show();

    cout << "\nДодаємо новий вагон...\n";
    train1.AddVagon(60);

    cout << "\nДодаємо пасажирів...\n";
    train1.AddPassenger(1);
    train1.AddPassenger(1);
    train1.AddPassenger(3);

    train1.Show();

    cout << "\nПеревірка конструктора копіювання:\n";

    Train train2 = train1;

    train2.Show();

    return 0;
}