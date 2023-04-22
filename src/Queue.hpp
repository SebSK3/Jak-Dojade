#pragma once

template <typename T> struct QueueNode {
    T element;
    QueueNode<T> *next = nullptr;
    explicit QueueNode(T el) : element(el) {}
};

template <typename T> struct Queue {
    QueueNode<T> *head = nullptr;
    QueueNode<T> *tail = nullptr;
    int length = 0;
    ~Queue() {
        QueueNode<T> *temp = head;
        while (temp != nullptr) {
            QueueNode<T> *deletingNode = temp;
            temp = temp->next;
            delete deletingNode;
        }
    }
    const bool empty() const { return length == 0 ? true : false; }
    void push(T element) {

        length++;
        QueueNode<T> *nextElement = new QueueNode<T>(element);
        if (length == 1) {
            head = nextElement;
            tail = nextElement;
            return;
        }
        tail->next = nextElement;
        tail = nextElement;
    }
    const T front() const { return head->element; }
    void pop() {
        QueueNode<T> *temp = head;
        head = head->next;
        length--;
        delete temp;
    }
};