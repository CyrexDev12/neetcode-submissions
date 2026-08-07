class MinStack {
private:
    vector<int> arr;

public:
    MinStack() {}

    void push(int val) {
        arr.resize(arr.size() + 1);

        for (int i = arr.size() - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = val;
    }

    void pop() {
        if (arr.empty())
            return;

        for (int i = 1; i < arr.size(); i++) {
            arr[i - 1] = arr[i];
        }

        arr.resize(arr.size() - 1);
    }

    int top() {
        return arr[0];
    }

    int getMin() {
        int currMin = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < currMin) {
                currMin = arr[i];
            }
        }

        return currMin;
    }
};