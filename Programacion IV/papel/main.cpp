template <typename T>
class arraysss {
    T* array;
    int capacity;
    int back, front;
public:
    arraysss(int size);
    virtual ~arraysss(){
        delete[] array;
    }
    T& operator[](int x) {
        return array[(front+x)%capacity];
    }
    const T& operator[](int x) const {
        return array[(front+x)%capacity];
    }

    template<typename U>
    friend void some_function(const arraysss<U>* arr);
    template<typename U>
    friend void some_function(const arraysss<U>& arr);
};

template<typename T>
arraysss<T>::arraysss(int _capacity) {
    this->capacity = _capacity;
    this->array = new T[_capacity];
    this->front = this->back = -1; // empty
}

template <typename T>
T& operator[](arraysss<T>* arr, int x) {
    return (*arr)[x];
}

template <typename T>
const T& operator[](const arraysss<T>* arr, int x) {
    return (*arr)[x];
}

template<typename U>
void some_function(const arraysss<U>* arr) {
    // some code
}

template<typename U>
void some_function(const arraysss<U>& arr) {
    // some code
}

int main() {
    arraysss<int>* array = new arraysss<int>(7);
    ASSERT(array[2] == 2, "The operator [] is not working");
    some_function(array);
    delete array;
    return 0;
}
