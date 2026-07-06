class MyCircularQueue {
private:
    vector<int> q;
    int front, rear, cnt, cap;

public:
    MyCircularQueue(int k) {
        q.resize(k);
        cap = k;
        front = 0;
        rear = 0;
        cnt = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        q[rear] = value;
        rear = (rear + 1) % cap;
        cnt++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % cap;
        cnt--;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : q[front];
    }

    int Rear() {
        return isEmpty() ? -1 : q[(rear - 1 + cap) % cap];
    }

    bool isEmpty() {
        return cnt == 0;
    }

    bool isFull() {
        return cnt == cap;
    }
};
