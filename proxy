#include <iostream>

class Subject{ //RAII Subject

public:

    Subject(){}
    Subject(int data):mdata(data){

        std::cout<<"Subject "<< mdata <<" constructed "<<std::endl;
         nInstances++;
    }
    virtual~Subject(){
        std::cout<<"Subject "<< mdata <<" destroyed "<<std::endl;
         nInstances--;
    }

    Subject (Subject const& subject):mdata(subject.mdata){
          std::cout<<"Data copied"<<std::endl;
    }
    Subject& operator=(Subject const& subject){

       if(this != &subject){

         mdata = subject.mdata;

         std::cout<<"Data copied"<<std::endl;

       }
       return *this;
    }

    Subject (Subject const&& subject):mdata(subject.mdata){
          std::cout<<"Data moved"<<std::endl;
    }
    Subject& operator=(Subject const&& subject){

       if(this != &subject){

         mdata = std::move(subject.mdata);

         std::cout<<"Data moved"<<std::endl;

       }

       return *this;
    }

    void incrementInstances(){
        nInstances++;
    }

    void doWork(){

       std::cout<<"Processing ..."<<std::endl;
       std::cout<<"Data : "<<mdata<<std::endl;

    }
protected:
    int mdata;
    static int nInstances;

};


class Proxy{

public:

    Proxy(){}
    Proxy(int data):mdata(data){
          subject=NULL;
    }
    virtual~Proxy(){
    delete subject;
    }


    void work(){

        if(!subject){
        subject = new Subject{mdata};
        if(subject){
                subject->doWork();

        }
        }
    }

protected:
    Subject *subject;
    int mdata;

};

int Subject::nInstances = 0;

int main()
{
    Proxy subject{1};

    subject.work();

    return 0;
}
