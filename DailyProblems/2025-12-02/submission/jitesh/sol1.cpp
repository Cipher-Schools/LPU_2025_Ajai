//method 1--
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;

        int x = 0, y = 1, z;
        for(int i = 2; i <= n; i++) {
            z = x + y;
            x = y;
            y = z;
        }
        return y;
    }
};

//method 2--
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;

        return fib(n-1) + fib(n-2);
    }
}