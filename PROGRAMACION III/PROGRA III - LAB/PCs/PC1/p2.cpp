#include "iostream"

using namespace std;

template<typename T=int>
class MatVector{
    int size = int{};
protected:
    T* arr = nullptr;
public:
    explicit MatVector(int size_){
        size = size_;
        arr = new T[size_];
        for (int i = 0; i < size_; ++i) {
            T temp = rand()%90;
            arr[i] = temp/10;
        }
    };
    friend ostream& operator<<(ostream& os, const MatVector& v){
        os << "[ ";
        for (int i = 0; i < v.size; ++i) {
            os << v.arr[i] << " ";
        }
        os << "]" << endl;
        return os;
    }
    ~MatVector(){
        delete[] arr;
    }
    T operator[](int i) const{
        return arr[i];
    }
    T& operator[](int i){
        return arr[i];
    }
    MatVector(const MatVector& other){
        size = other.size;
        arr = new T[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = other[i];
        }
    }
    int get_size(){ return size;}
    friend float operator*(const MatVector& other1, const MatVector& other2) noexcept{
        if (other1.size == other2.size){
            float prod = 0;
            for (int i = 0; i < other1.size; ++i) {
                prod = other1.arr[i]*other2.arr[i] + prod;
            }
            return prod;
        }
        return 0;
    }
    friend float operator*(MatVector<> other1, const MatVector& other2) noexcept{
        if (other1.get_size() == other2.size){
            float prod = 0;
            for (int i = 0; i < other1.get_size(); ++i) {
                prod = other1[i]*other2[i] + prod;
            }
            return prod;
        }
        return 0;
    }
};

int main () {
    MatVector <> v1 (4) ;
    MatVector<float> v2 (4) ;
    cout << v1[2] << endl ;
    cout << v1 << endl ;
    cout << v2 << endl ;
    v2 [3] = 7.1;
    cout << v2 << endl ;
    cout << v1*v2  << endl ;

    return 0;
}
