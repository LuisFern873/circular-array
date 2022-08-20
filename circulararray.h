#include <iostream>
using namespace std;

template <class T>
class CircularArray {
private:
    T *array;
    int capacity;
    int sz;
    int back = -1;
    int front = -1;
    int next(int);
    int prev(int);
public:
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();

    void resize() {
        int new_size = capacity *= 2;
        T* temp = new int[new_size];
        for (int i = front; i < capacity; i++) {
            temp[i] = array[i]; 
        }
        delete[] array;
        capacity = new_size;
        array = temp;
	}

    void push_front(T data) {
        if (is_full()){
            resize();
        }
        else if (is_empty()) {
            front = back = 0;
        }
        front = prev(front);
        array[front] = data;
        sz++;
    }

    void push_back(T data) {
        if (is_full()) {
            resize(); 
        }
        else if (is_empty()) {
            front = back = 0;
        }
        array[back] = data;
        back = next(back);
        sz++;
    }

    void insert(T data, int pos) {}

    T pop_front() {
        throw "No esta implementado";
    }

    T pop_back() {
        throw "No esta implementado";
    }

    bool is_full() {
        if (prev(front) == back) {
            return true;
        } else {
            return false;
        }
    }

    bool is_empty() {
    	if (back == -1 & front == -1) {
            return true;
        } else return false;
    }

    int size();
    void clear();
    T &operator[](int);
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");
    void display();
};

template <class T>
CircularArray<T>::CircularArray() {
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity) {
    this -> array = new T[_capacity];
    this -> capacity = _capacity;
    this -> front = this -> back = -1;
}

template <class T>
CircularArray<T>::~CircularArray() {
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index) {
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index) {
    return (index + 1) % capacity;
}

template <class T>
string CircularArray<T>::to_string(string sep) {
    string result = ""; 
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;    
}

template <class T>
void CircularArray<T>::display() {
    for (int i = front; i < back; i++) {
        cout << array[i] << ' ';
    }
    cout<<endl;        
}

template <class T>
int CircularArray<T>::size() {    
    return sz;      
}

template <class T>
void CircularArray<T>::clear() {    
    back = -1;
    front = -1;  
    sz = 0;    
}

