

class Base {
public:
    virtual void calculate(double initialHeight, double growthRate, int days) = 0;
};

class PlantGrowth : virtual public Base {
public:
    void calculate(double initialHeight, double growthRate, int days) {
        double totalHeight = initialHeight + (growthRate * days);
        cout << "Total height is " << fixed << setprecision(2) << totalHeight << " cm" << endl;
    }
};

class Final : public PlantGrowth {
public:
    void calculate(double initialHeight, double growthRate, int days) {
        PlantGrowth::calculate(initialHeight, growthRate, days);
    }
};

