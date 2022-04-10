#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class file {
    ifstream in;
    ofstream out;

public:

    vector <vector <int>> numbers;
    file();
    ~file();

    void positive();
    void oneLine();
    void biggest();

};

file::file() {
    in.open("C:\\wspolrzedne.txt");


    int temp;
    for (int j = 0; j < 100; j++) {

        numbers.push_back(vector <int>());
        for (int i = 0; i < 6; i++) {
            in >> temp;
            numbers[j].push_back(temp);
        }

    }

}

file::~file() {
    in.close();
    out.close();
}

void file::positive() {
    int counter = 0;
    for (int i = 0; i < numbers.size(); i++) {
        
        if (numbers[i][0] > 0 && numbers[i][1] > 0 && numbers[i][2] > 0 && numbers[i][3] > 0 && numbers[i][4] > 0 && numbers[i][5] > 0 ) {
            counter++;
        }   
        
    }
    cout << counter << endl;
}

void file::oneLine() {
    int counter = 0;
    for (int i = 0; i < numbers.size(); i++) {
    
        if ((numbers[i][2] - numbers[i][0])*(numbers[i][5]- numbers[i][1]) == (numbers[i][3] - numbers[i][1])*(numbers[i][4] - numbers[i][0])){
            counter++;
        }

    }
    cout << counter<<endl;
}

void file::biggest() {
    double max = sqrt(pow(numbers[0][0] - numbers[0][2], 2) + pow(numbers[0][1] - numbers[0][3], 2)) + sqrt(pow(numbers[0][2] - numbers[0][4], 2) + pow(numbers[0][3] - numbers[0][5], 2)) + sqrt(pow(numbers[0][0] - numbers[0][4], 2) + pow(numbers[0][1] - numbers[0][5], 2));
    int maxxa = numbers[0][0], maxya = numbers[0][1], maxxb = numbers[0][2], maxyb = numbers[0][3], maxxc = numbers[0][4], maxyc = numbers[0][5];
    for (int i = 0; i < numbers.size(); i++) {
        double ab = sqrt(pow(numbers[i][0] - numbers[i][2], 2) + pow(numbers[i][1] - numbers[i][3], 2));
        double bc = sqrt(pow(numbers[i][2] - numbers[i][4], 2) + pow(numbers[i][3] - numbers[i][5], 2));
        double ac = sqrt(pow(numbers[i][0] - numbers[i][4], 2) + pow(numbers[i][1] - numbers[i][5], 2));
        
        if ((ab + bc > ac) || (ab+ac > bc) || (ac + bc > ab)) {
            if (ab + bc + ac > max) {
                max = ab + bc + ac;
                maxxa = numbers[i][0], maxya = numbers[i][1], maxxb = numbers[i][2], maxyb = numbers[i][3], maxxc = numbers[i][4], maxyc = numbers[i][5];

            }
        }

        
    }
    cout << max<<endl;
    cout << maxxa << "," << maxya << " " << maxxb << "," << maxyb << " " << maxyb << "," << maxyc << endl;
}

int main()
{
    file f;
    f.positive();
    f.oneLine();
    f.biggest();
}
