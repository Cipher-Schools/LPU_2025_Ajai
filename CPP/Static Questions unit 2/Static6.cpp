#include <iostream>
using namespace std;

class Matrix {
public:
    int rows, cols;
    int elements[10][10]; // as per constraints (1 ≤ r,c ≤ 10)

    void inputMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> elements[i][j];
            }
        }
    }

    int calculateSum() {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                sum += elements[i][j];
            }
        }
        return sum;
    }
};

int main() {
    Matrix m;
    cin >> m.rows >> m.cols;

    m.inputMatrix();

    cout << "Sum: " << m.calculateSum();
    return 0;
}
