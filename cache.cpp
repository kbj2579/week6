#include "cache.h"

#include <string>
#include <iostream>
using namespace std;

// TODO: 필요한 함수 구현
    Cache:: Cache():Ival(0), Dval(0), key(""), next(NULL) {};

    Cache:: ~Cache(){
        delete this->nodes;
    }

    void Cache::add(std::string key, int value){
        Cache::Node* newNode = new Cache::Node(value);
        Cache::Node* cur = Cache::LinkedList::nodes;
        Cache::Node* pre = Cache::LinkedList::nodes;
        //if 순회하여 value 가 존재한다면 이 value 를 맨앞으로 보냄.
        if(cur != nodes){
            while(cur->getNext() != NULL){
                if(cur != nodes){
                    pre = pre->getNext();
                }
                cur = cur->getNext();
            }
            pre->setNext(newNode);
        }
        //////////////////////////////
        
        //if 순회하여 value 가 존재하지 않는다면 이 value 를 맨 앞에 추가
        newNode->setNext(nodes);
        nodes = newNode;
        key_ = key;
        if(size == 10){ // 맨앞에 value를 추가할때 size가 10인경우 마지막 노드를 제거.
            while(cur->getNext() != NULL){
                if(cur != nodes){
                pre = pre->getNext();
                }
                cur = cur->getNext();
            }
            delete cur;
        }
        size++;
        /////////////////////////////
        while(cur!=NULL){
            if(cur != nodes){
                pre = pre->getNext();
            }
            cur = cur->getNext();
        }

        else{
            if(cur == NULL){ //would be the last
                pre->setNext(newNode);
            }
            else{
                pre->setNext(newNode);
                newNode->setNext(cur);
            }
        }
        size++;
        return;
    }
    // double을 cache에 추가한다
    void Cache::add(std::string key, double value){

    }
    // key에 해당하는 value를 cache에서 가져온다
    // 타입과 key가 동일한 원소가 없다면 false를 반환한다.
    bool Cache::get(std::string key, int &value){

    }
    // key에 해당하는 value를 cache에서 가져온다.
    // 타입과 key가 동일한 원소가 없다면 false를 반환한다.
    bool Cache::get(std::string key, double &value);

    // 디버그 및 채점 용: 연결 리스트를 문자열로 표현하여 반환한다
    // 다음과 같이 표현된 문자열을 반환한다
    // [key1: value1] -> [key2: value2] -> ... -> [keyN: valueN]
    std::string toString();
