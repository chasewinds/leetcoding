class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> data;

    MedianFinder() {

    }

    void addNum(int num) {
        if (data.empty()) {
            data.push_back(num);
        }
        int left = 0;
        int right = data.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (data[mid] < num) {
                left = mid + 1;
            } else if (data[mid] > num) {
                right = mid - 1;
            } else {
                break;
            }
        }
        cout << "num" << num << "data[left]" << data[left] << endl;
        cout << "match" << endl;
        data.push_back(num);
        for (int i = left; i < data.size() - 1; i++) {
            swap(data[i], data[data.size() - 1]);
        }
        return;
    }

    double findMedian() {
        for (auto x: data) {
            cout << x << " ";
        }
        cout << endl;
        int n = data.size();
        if (n % 2 == 0) {
            return (data[n / 2] + data[(n + 1) / 2]) / 2.0;
        }
        return data[(n + 1) / 2];
    }
};