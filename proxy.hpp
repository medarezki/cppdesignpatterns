#include <iostream>
#include <deque>

//Proxy Design Pattern (Basic)

template<class U>

class Object{

 public:

    Object();
    Object(std::deque<U >& values_, U& value_);
    virtual ~Object<U>();

    void setvalue(U);
    void resetvalue();

    void displayvalue(){

        std::cout<<value<<std::endl;
    }

 private:
    std::deque<U > values;
    U value;


};

template<class T >

class ProxyPattern{

 public:

     ProxyPattern();
     ProxyPattern(Object<T>& candidate);
     virtual ~ProxyPattern<T>();

     void work1();
     void work2();



 private:

     Object<T>* object;

};


template<class T>

ProxyPattern<T>::ProxyPattern(){


}


template<class T>

ProxyPattern<T>::ProxyPattern(Object<T>& candidate){


    object = &candidate;

}


template <class T>

ProxyPattern<T>::~ProxyPattern(){

    delete object;

}

template<class T>

void ProxyPattern<T>::work1(){

    object->setvalue(42);

}

template<class T>

void ProxyPattern<T>::work2(){

    object->resetvalue();

}



//
template<class U>

Object<U>::Object():value(0){}

template<class U>

Object<U>::Object(std::deque<U>& values_, U& value_){


}


template <class U>
Object<U>::~Object(){
}

template<class U>

void Object<U>::setvalue(U value_){

    value =value_;

}


template<class U>

void Object<U>::resetvalue(){

    value= 0;

}

int main(){

    std::deque<int> values{1,2,3};
    int value{2};
    int setting_val{42};

    Object<int> obj(values, value);
    ProxyPattern<int> proxy(obj);

    proxy.work1();

    obj.displayvalue();


    return 0;
}
