#include <iostream>
#include <utility>
template<typename T=int>
struct Node {
    T data;
    Node* next;
    Node* prev;

    Node(){
        next = nullptr;
        prev = nullptr;
    }

    explicit Node(T value){
        next = nullptr;
        prev = nullptr;
        data = value;
    }

    [[maybe_unused]] void killSelf(){
        delete this;
    }
};
using namespace std;
template <typename T=int>
class DoubleList  {



private:
    Node<T>* head;
    Node<T>* tail;
    int nodes;

public:
    DoubleList() {
        head = nullptr;
        tail = nullptr;
        nodes = 0;
    }

    ~DoubleList(){
        delete head;
        delete tail;
        // TODO
    }

    [[maybe_unused]] T front(){
        throw head->data;
    }

    [[maybe_unused]] T back(){
        throw tail->data;
    }

    void push_front(T data){
        if (is_empty()){
            auto temp = new Node<T>(data);
            temp->next = nullptr;
            temp->prev = nullptr;
            head = temp;
            tail = temp;
            nodes++;
//                throw ;
        }
        else{
            auto temp = new Node<T>(data);
            temp->prev = nullptr;
            temp->next = head;
            head->prev = temp;
            head = temp;
            nodes++;
//                throw ;
        }
    }

    void push_back(T data){
        if (is_empty()){
            auto temp = new Node<T>(data);
            temp->data = data;
            temp->next = nullptr;
            temp->prev = nullptr;
            head = temp;
            tail = temp;
            nodes++;
//                throw ;
        }
        else{
            auto temp = new Node<T>(data);
            temp->prev = tail;
            temp->next = nullptr;
            tail->next = temp;
            tail = temp;
            nodes++;
//                throw ;
        }
    }

    T pop_front(){
        if (is_empty()){
            throw ;
        }
        else if (head->next == nullptr && head->prev == nullptr){
            T val = head->data;
            delete head;
            head = nullptr;
            tail = nullptr;
            nodes--;
            return val;
        }
        else{
            T val = head->data;
            head=head->next;
            delete head->prev;
            head->prev = nullptr;
            nodes--;
            return val;
        }
    }

    T pop_back(){
        if (is_empty()){
            throw ;
        }
        else if(tail->next== nullptr && tail->prev == nullptr){
            T val = tail->data;
            delete tail;
            head = nullptr;
            tail = nullptr;
            nodes--;
            return val;
        }
        else{
            T val = tail->data;
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
            nodes--;
            return val;
        }
    }

    [[maybe_unused]] T insert(T data, int pos){
        if (is_empty() || pos>=size()){
            push_back(data);
            return data;
        }
        else if (pos == 1){
            T val = head->data;
            push_front(data);
            nodes++;
            return val;
        }
        else{
            auto nodo = new Node<T>(data);
            Node<T>* temp  = head;
            int i = 1;
            while (i++<pos-1){
                temp = temp->next;
            }
            nodo->next = temp->next;
            nodo->prev = temp;
            temp->next->prev = nodo;
            temp->next = nodo;
            nodes++;
            return 0;
        }
        //            throw ("sin definir");
    }

    [[maybe_unused]] bool remove(int pos){
        if (pos>size()){
            return false;
        }
        else if (pos == 1){
            pop_front();
            return true;
        }
        else if (pos == size()){
            pop_back();
            nodes--;
            return true;
        }
        else{
            Node<T>* temp  = head;
            int i = 1;
            while (i++<pos-1){
                temp = temp->next;
            }
            temp->next = temp->next->next;
            nodes--;
            return true;
        }
        //            throw ("sin definir");
    }

    T& operator[](int pos){
        if (pos == 0){
            return head->data;
        }
        else if (pos == size()-1){
            return tail->data;
        }
        else{
            Node<T>* temp  = head;
            int i=0;
            while (i<=pos){
                temp = temp->next;
                i++;
            }
            return temp->data;
        }
        //            throw ("sin definir");
    }

    bool is_empty(){
        return head== nullptr && tail== nullptr;
        //            throw ("sin definir");
    }

    virtual int size(){
        return nodes;
//            throw ("sin definir");
    }

    [[maybe_unused]] void clear(){
        delete head;
        delete tail;
        head = nullptr;
        tail = nullptr;
        nodes = 0;
//            throw ("sin definir");
    }
    void display(){
        Node<T>* temp = head;
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }


};

template<typename T=int>
class stack:private DoubleList<T>
{
public:
    stack(): DoubleList<T>()
    {}

    void push(T data)
    {
        DoubleList<T>::push_back(data);

    }

    T pop()
    {

        return DoubleList<T>::pop_back();
    }


    bool empty()
    {
        return DoubleList<T>::is_empty();
    }

    int size() override
    {
        return DoubleList<T>::size();
    }

};





struct Result{
    double result{};
    bool error{};
};
bool priority(const string& a , const string& b) // prioridad de a sobre a
{
    if(a==b)
        return false;

    if((a=="*" or a=="/") and (b =="+" or b=="-" or b=="(" or b.empty()) )
        return true;

    if((a=="+" or a=="-") and (b=="(" or b.empty()))
        return true;


    return false;

}

bool is_symbol(const string& cosa)
{

    return (cosa=="("  or cosa =="+" or cosa=="*" or cosa=="/" or cosa=="-" or cosa.empty());

}

bool is_digit(char d )
{
    return (d>='0' and d<='9');

}
string value(const string& key)
{
    if(key=="(")
        return ")";
    if(key==")")
        return "(";
    else return "";

}

string operations( const string& a ,  const string& b , const string& op)
{
    if(is_symbol(a) or is_symbol(b))
        return "";

    double an= stod(a);

    double bn= stod(b);


 if(op=="+")
       return to_string(an+bn);
    if(op=="-")
        return to_string(an-bn);
    if(op=="*")
        return to_string(an*bn);
    if(op=="/")
        return to_string(an/bn);
    else return "";

}

DoubleList<string> transform(string input)
{
    DoubleList<string> pos_fix;

    for (int i = 0; i < input.size(); ++i) {
        string s ;
        int j=i;

        if(is_digit(input[i]) )
        {

            while (is_digit(input[j])  and j<input.size() )
            {


                if(is_digit(input[j]))
                    s.push_back(input[j]);
                j++;
            }

            pos_fix.push_back(s);
            i+=static_cast<int>(s.size())-1;
            s.clear();





        }else {

            if(input[i]!=' ' )
            {

                s.push_back(input[i]);
                pos_fix.push_back(s);

            }
            s.clear();


        }

    }
    return pos_fix;
}
void infix_to_posfix(DoubleList<string>  otra , DoubleList<string>& pos_fix)
{
    stack<string> signos;
    while (!otra.is_empty())
    {
        string  temp = otra.pop_front();

        if(is_symbol(temp))
        {
            if(temp=="(")
                signos.push(temp);
            else {
                string temp2;
                if (!signos.empty())
                    temp2 = signos.pop();


                if (priority(temp, temp2)) {
                    if(!temp2.empty())
                        signos.push(temp2);

                    if(!temp.empty())
                        signos.push(temp);
                }else {
                    if(signos.empty())
                        pos_fix.push_back(temp2);
                    else{

                        while (!priority(temp,temp2) and !signos.empty())
                        {
                            pos_fix.push_back(temp2);
                            temp2=signos.pop();

                        }
                    }

                    signos.push(temp);



                }
            }

        }else if(temp==")") {
            string temp1;
            if(!signos.empty())
                temp1=signos.pop();
            while (value(temp)!=temp1)
            {
                if(temp1!="(")
                    pos_fix.push_back(temp1);
                temp1=signos.pop();

            }

        }else {
            pos_fix.push_back(temp);
        }
    }

    if(signos.size()>0)
    {

        while (!signos.empty())
            pos_fix.push_back(signos.pop());
    }




}
[[maybe_unused]] void validate(DoubleList<string>& pos_fix)
{
    stack<string> validation;
    while (!pos_fix.is_empty())
    {

        cout<<pos_fix.pop_front();
    }


}
Result evaluate(const string& input)
{

    auto evaluacion = new Result();


    DoubleList<string> otra= transform(input);
    DoubleList<string> pos_fix;
    stack<string> valor;
    infix_to_posfix(transform(input),pos_fix);
//    pos_fix.display();

    while (!pos_fix.is_empty())
    { string temp=pos_fix.pop_front();
        if(is_symbol(temp)){
            string operand1;
            string operand2;

               if(!valor.empty())
                 operand1=valor.pop();
            if(!valor.empty())
                operand2=valor.pop();


            if(!is_symbol(operand1) and !is_symbol(operand2) and temp != "(" and valor.size() < 2)
            {

                valor.push(operations(operand2,operand1,temp));

            }else {
                evaluacion->error= true;
                break;
            }


        }else {

            valor.push(temp);
        }
    }


    if(!evaluacion->error){
        evaluacion->result=stod(valor.pop());
    }
    else{
        evaluacion->result=-1;
    }

    return *evaluacion;

    // 1- descomponer el input y validar

    // 2- convertir de Infijo a Postfijo
    
    // 3- resolver la expresion

    //* Si no cumple la validacion retornar Result.error = true;

    //return Result();
}
