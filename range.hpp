//
// Created by shahar on 08/06/2020.
//
#pragma once
#include <vector>
using namespace std;
#include <iostream>
#include "Itertool.hpp"
namespace itertools {
    class range {
    public:
        int start;
        int endd;

        // int size;
        range() {
            this->start = 0;
            this->endd = 0;
            //this->size=0;
        }

        range(int a, int b) {
            //cout<<"in range"<<" start="<<start<<" end="<<endd<<endl;
            this->start = a;
            this->endd = b;
            //this->size=b-a;
        }

        range(range &other){
            this->start = other.start;
            this->endd = other.endd;
        }

        int size() {
            return this->endd;
        }

//        const int &operator[](int nIndex) const {
//
//            //cout<<"range"<<range[0]<<range[1]<<endl;
//            if (nIndex >= endd)
//                throw std::out_of_range("Index out of range");
//
//            else
//                return nIndex;
////        T i=start;
////        while(i<nIndex){
////            i++;
////        }
////        return i;
//        }

        range operator+=(int number) {
            range temp = range(number, number);
        }

//    int operator<<(range number){
//        return number.start;
//    }

//    ostream& operator<<(ostream& os, int& number)
//    {
//
//        os << number;
//
//        return os;
//    }

        class iterator {
        public:
            iterator( int nIndex) {//const range *Range,
               // myrange = Range;
                myindex = nIndex;
            }

            iterator(){
                myindex=-1;
            }


             int &operator*()  {   //const int& operator*()
                return myindex;
            }

            iterator &operator++() {
                ++myindex;
                return *this;
            }

            iterator &operator++(int) {
                iterator tmp= *this;
                ++myindex;
                return tmp;
            }


            bool operator!=(const iterator &other) const { return myindex != other.myindex; }

            int get() {
                return this->myindex;
            }

            int myindex = -1;
//        private:
//
//
//            const range *myrange;


        };

        iterator begin() const;
        iterator end() const;



    };

//template <typename int>
    typename range::iterator range::begin() const {
        return range::iterator{ this->start};
    }

//template <typename T>
    typename range::iterator range::end() const {
        return range::iterator{ this->endd};
    }
}




