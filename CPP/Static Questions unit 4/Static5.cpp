
class Image {
private:
    int width;
    int height;
    
public:
    Image(int w, int h) : width(w), height(h) {}

    Image operator+(const Image& img) {
        int newWidth = width + img.width;
        int newHeight = height + img.height;
        return Image(newWidth, newHeight);
    }

    void display() {
        cout << "Image dimensions: " << width << "x" << height << endl;
    }
};

