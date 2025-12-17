
class FoodOrder : public VegetarianMenu, public NonVegetarianMenu {
public:
    double calculateTotalCost(int vegQuantity, double vegPrice, int nonVegQuantity, double nonVegPrice, double discountThreshold, double discountRate) {
        double vegCost = VegetarianMenu::calculateCost(vegQuantity, vegPrice);
        double nonVegCost = NonVegetarianMenu::calculateCost(nonVegQuantity, nonVegPrice);
        double totalCost = vegCost + nonVegCost;

        if (totalCost > discountThreshold) {
            totalCost -= totalCost * discountRate;
        }
        return totalCost;
    }
};

