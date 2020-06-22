//
// Created by shahar on 08/06/2020.
//
#pragma once
#include "Itertool.hpp"
#include <vector>
using namespace std;
#include <iostream>



namespace itertools {
//    class plus
//    {
//    public:
//        template <typename T>
//        T operator()(const T a, const T b)const{
//            return a + b;
//        }
//
//    };


    template<typename T,typename F>
    class filterfalse {  //function
        T collect;   //range /vector<int>
         F lambda;

    public:

        filterfalse(   F lambda,T collect):lambda(lambda),collect(collect){}

        auto operator[]( typename T::iterator nIndex) const //  const T &
        {
            if(lambda(*nIndex)){
                return *nIndex;
            }
            else {
            return operator[](nIndex++);
            }

        }


        class iterator {
        private:
              filterfalse *myaccumulate;
            typename T::iterator it;   //moves
            // decltype(collect.begin()) sum;

//            int myindex = -1;
        public:
            iterator(   filterfalse *Accumulate,typename T::iterator place) {
                this->it=place;
                myaccumulate = Accumulate;
                // sum=fnc()
                //myindex = nIndex;
            }

            auto  operator*()  {  //const T&
                return myaccumulate->operator[](it);
            }

            iterator& operator++() {
                ++it;
                return *this;
            }

            iterator& operator++(int) {
                iterator tmp= *this;
                ++it;
                return tmp;
            }

            bool operator!=(const iterator &other) const { return this->it != other.it; }

             bool operator==(const iterator &other) const { return !this!=other; }


        };

         iterator begin() {
            return iterator{this, this->collect.begin()};
        }

        iterator end() {
            return iterator{this, this->collect.end()};
        }

    };
}
