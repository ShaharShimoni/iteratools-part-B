//
// Created by shahar on 08/06/2020.
//

//
// Created by shahar on 08/06/2020.
//
#pragma once
#include "Itertool.hpp"
#include <vector>
using namespace std;
#include <iostream>



namespace itertools {
        class plus
    {
    public:
        template <typename U>
         U operator()(const U a, const U b)const{
            return a + b;
        }

    };
//    class plus
//    {
//    public:
//        template <typename T>
//        T operator()(const T a, const T b)const{
//            return a + b;
//        }
//
//    };

//    typedef struct {
//        template <typename U>
//        U operator()( U& a, U& b) const{
//            return a+b;
//        }
//
//    } plus_default;

    template<typename T,typename F=plus>
    class compress {  //function
        T collect;   //range /vector<int>
        vector<bool> vec;


//        int start;
//        int endd; // U-in

    public:
        static int count;
        compress(T collect , vector<bool> vec):collect(collect),vec(vec){}

        auto operator[]( typename T::iterator nIndex) const //  const T &
        {

            int count=0;
            auto temp=collect.begin();
            while(temp!=nIndex){
                ++temp;
                count++;
            }
            if(vec[count]){
                cout<<"yes"<<endl;
                return *nIndex;
            }
            else{
                ++nIndex;
            }


          //  auto t=*nIndex;


//            else{
//                *nIndex=0;
//                return *nIndex;
//            }
//             auto t=0;
//             return t;






        }


        class iterator {
        private:
            const compress *myaccumulate;
            typename T::iterator it;   //moves
            // decltype(collect.begin()) sum;

//            int myindex = -1;
        public:
            iterator( const compress *Accumulate,typename T::iterator place) {
                this->it=place;
                myaccumulate = Accumulate;
            }

            auto  operator*()  {  //const T&
                return myaccumulate->operator[](it);

            }

            iterator& operator++() {
                ++it;
                //count++;
                return *this;
            }

            iterator& operator++(int) {
                iterator tmp= *this;
               // count++;
                ++it;
                return tmp;
            }

            bool operator!=(const iterator &other) const { return this->it != other.it; }

            bool operator==(const iterator &other) const { return !this!=other; }


        };

         iterator begin()  {
            return iterator{this, this->collect.begin()};
        }

        iterator end()  {
            return iterator{this, this->collect.end()};
        }

    };
}



//
//    accumulate(vector<string> list) {
//
//        cout<<"in string"<<endl;
//        vector <string> answer;
//        string sum = list[0];
//        int i = 1;
//        while (i <= list.size()) {
//            answer.push_back(sum);
//            sum = sum + list[i];
//
//            i++;
//        }
//
//    }




//
//vector<string> accumulate(vector<char> list) {   //more spesific cause to change from char to string is problem
//    vector <string> answer;
//    string sum = "";
//    sum+= list[0];
//    int i = 1;
//    while (i <= list.size()) {
//        answer.push_back(sum);
//        sum = sum + list[i];
//
//        i++;
//    }
//
//    return answer;
//}
//
//template <typename T>
//vector<T> accumulate(vector<T> list,int (*fcn)(int x,int y)) {
//
//    vector <T> answer;
//    T sum = list[0];
//    int i = 1;
//    while (i <= list.size()) {
//        answer.push_back(sum);
//
//        // cout<<"i="<<list[i]<<endl;
//        sum= fcn(sum,list[i]);
//        i++;
//
//    }
//
//
//    return answer;
//}














//#pragma once
//#include <vector>
//using namespace std;
//#include <iostream>
//#include "Itertool.hpp"
//
//
//template <typename T>
//class compress{  //function
//    T collect;   //range /vector<int>
//    vector<bool> whois;
//    int start;
//    int endd; // U-in
//
//
//public:
//    compress(){
//        this->collect= nullptr;
//        this->whois= nullptr;
//        this->start=0;
//        this->endd=0;
//    }
//    compress(T collect,vector<bool> whois){
//        cout<<"banay"<<endl;
//        this->collect=collect;
//        this->whois=whois;
//        this->start=0;
//        this->endd=whois.size();
//
//    }
//
//    //template <typename U>
//
//    T operator[](int nIndex) const  //  const U&
//    {
//       // cout<<"operator []"<<endl;
//
//        if (nIndex >= this->endd)
//            throw std::out_of_range("Index out of range");
//        T sum;
//
//        if(whois[nIndex]==true){
//            //cout<<collect[nIndex]<<endl;
//            sum+=collect[nIndex];
//
//        }
//        return sum;
//
//
//
//    }
//
//    class Iterator{
//    private:
//        const compress<T> *myrange;
//        int myindex=-1;
//    public:
//        Iterator(const  compress<T> *Accumulate, int nIndex){
//            myrange=Accumulate;
//            myindex=nIndex;
//        }
//        //
//       // template<typename U>
//        const T& operator*() const {  //const T&
//           // cout<<"operator *"<<endl;
//            return myrange->operator [](myindex);
//            //return a[0];
//        }
//
//        Iterator operator ++(){++myindex; return *this;}
//        bool operator!=(const Iterator &other)const {return myindex!=other.myindex;}
//
//    };
//    Iterator begin() const{
//        //cout<<"begin"<<endl;
//        return Iterator{ this, this->start };
//    }
//    Iterator end() const{
//        //cout<<"end"<<endl;
//
//        return Iterator{ this,this->endd };
//    }
//
//
//
//};
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////not from today
////template <typename T>
////
////vector<T> accumulate(vector<T> list) {
////
////    vector <T> answer;
////    T sum = list[0];
////    int i = 1;
////    while (i <= list.size()) {
////        answer.push_back(sum);
////        sum = sum + list[i];
////
////        i++;
////    }
////
////
////    return answer;
////}
////
////vector<string> accumulate(vector<char> list) {   //more spesific cause to change from char to string is problem
////    vector <string> answer;
////    string sum = "";
////    sum+= list[0];
////    int i = 1;
////    while (i <= list.size()) {
////        answer.push_back(sum);
////        sum = sum + list[i];
////
////        i++;
////    }
////
////    return answer;
////}
////
////template <typename T>
////vector<T> accumulate(vector<T> list,int (*fcn)(int x,int y)) {
////
////    vector <T> answer;
////    T sum = list[0];
////    int i = 1;
////    while (i <= list.size()) {
////        answer.push_back(sum);
////
////        // cout<<"i="<<list[i]<<endl;
////        sum= fcn(sum,list[i]);
////        i++;
////
////    }
////
////
////    return answer;
////}








































//template <typename T>
//
//vector<T> compress(T vec, vector<bool>vecbool){
//    if(vec.size()!=vecbool.size()){
//        throw exception();
//    }
//    T temp;
//    vector<T>save;
//    for (int i = 0; i < vec.size(); i++) {
//        if(vecbool[i]==true){
//            //cout<<"yes"<<vec[i]<<endl;
//            temp=vec[i];
//            save.push_back(temp);
//        }
//
//    }
//    return save;
//
//}
//
//template <typename T>
//
//vector<T> compress(vector<T> vec, vector<bool>vecbool){
//    if(vec.size()!=vecbool.size()){
//        throw exception();
//    }
//    vector<T>save;
//    for (int i = 0; i < vec.size(); i++) {
//        if(vecbool[i]==true){
//           // cout<<"yes"<<vec[i]<<endl;
//           // temp=vec[i];
//            save.push_back(vec[i]);
//        }
//
//    }
//    return save;
//
//}