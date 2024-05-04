#include "cache.h"

#include <string>
#include <iostream>
using namespace std;

#define hashSize 100
// TODO: 필요한 함수 구현
    Cache::DoubleLinkedList::DoubleLinkedList(){
        size = 10;
        head = new Cache::Node("", 0);
        tail = new Cache::Node("", 0);
        head->next = tail;
        tail->prev = head;
    }
    Cache:: Cache(){
        hashTable = new Node*[hashSize](); 
        list = new DoubleLinkedList();
        for (int i = 0; i < hashSize; ++i) {
            hashTable[i] = nullptr;
        }
    }

    Cache:: ~Cache(){
        delete[] hashTable;
        delete list;
    }

    int Cache::hashFunc(string key){
        int sum = 0;
        for(int i = 0; i< key.length(); i++){
          sum += key[i];
        }
        return sum%hashSize;
    }

 
    void Cache::add(std::string key, int value){
        Cache::Node* newNode = new Cache::Node(key, value);

        // 캐시사이즈가 0인경우
        if(list->size == 0){
            list -> head -> next = newNode;
            newNode -> prev = list->head;
            newNode -> next = list->tail;
            list->tail -> prev = newNode;
            list->size++;
            return;
        }

        // 캐시 miss 인경우 맨 앞에 value 추가
        newNode->next = list->head->next;
        newNode->prev = list->head;
        list->head->next = list->head->next->prev = newNode; 
        if (list->size == CACHE_SIZE) { // size가 10이면 마지막 노드제거
            Cache::Node* lastNode = list->tail;
            list->tail = lastNode->prev;
            list->tail->next = nullptr;
            delete lastNode;
            return;
        } 
        else{ // size가 10미만이면 사이즈를 늘림
            list->size++;
            return;
        }
    }

        
    // double을 cache에 추가한다
    void Cache::add(std::string key, double value){
        Cache::Node* newNode = new Cache::Node(key, value);

        // 캐시사이즈가 0인경우
        if(list->size == 0){
            list -> head -> next = newNode;
            newNode -> prev = list->head;
            newNode -> next = list->tail;
            list->tail -> prev = newNode;
            list->size++;
            return;
        }

        // 캐시 miss 인경우 맨 앞에 value 추가
        newNode->next = list->head->next;
        newNode->prev = list->head;
        list->head->next = list->head->next->prev = newNode; 
        if (list->size == CACHE_SIZE) { // size가 10이면 마지막 노드제거
            Cache::Node* lastNode = list->tail;
            list->tail = lastNode->prev;
            list->tail->next = nullptr;
            delete lastNode;
            return;
        } 
        else{ // size가 10미만이면 사이즈를 늘림
            list->size++;
            return;
        }
    }
    // key에 해당하는 value를 cache에서 가져온다
    // 타입과 key가 동일한 원소가 없다면 false를 반환한다.
    bool Cache::get(std::string key, int &value){
         Cache::Node* sameNode = list->head;
         for (int i = 0; i < list->size - 1; i++){
            if (sameNode->next->key_ == key && !sameNode->isDouble){
                Cache::Node* preNode = sameNode;
                Cache::Node* nextNode = sameNode -> next -> next;
                value = sameNode->next->Ival_;
                preNode->next = nextNode;
                nextNode -> prev = preNode;
                delete sameNode -> next;
            }
            sameNode = sameNode -> next;
        }

        int index = hashFunc(key);
        bool check = false;
        if (hashTable[index] != nullptr) { 
            Cache::Node* current = hashTable[index];
            while (current->next != nullptr) {
                if(current->key_ == key && !current->isDouble){
                    
                    check = true; // hit
                    value = current->Ival_;
                    return check;
                }
                current = current->next;
            }
            return check;
        } 
        else { 
            return check;
        }
    }
    // key에 해당하는 value를 cache에서 가져온다.
    // 타입과 key가 동일한 원소가 없다면 false를 반환한다.
    bool Cache::get(std::string key, double &value){
        int index = hashFunc(key);
        bool check = false;
        if (hashTable[index] != nullptr) { 
            Cache::Node* current = hashTable[index];
            while (current->next != nullptr) {
                if(current->key_ == key && current->isDouble){
                    check = true; // hit
                    value = current->Dval_;
                    return check;
                }
                current = current->next;
            }
            return check;
        } 
        else { 
            return check;
        }
    }


    // 디버그 및 채점 용: 연결 리스트를 문자열로 표현하여 반환한다
    // 다음과 같이 표현된 문자열을 반환한다
    // [key1: value1] -> [key2: value2] -> ... -> [keyN: valueN]
    string Cache::toString(){
        std::string result;
        Cache::Node* checkNode = list->head;
    for (int i = 0; i < list->size; i++)
    {
        checkNode = checkNode->next;
        if (checkNode->isDouble) 
        {
            result += "[" + checkNode->key_ + ": " + to_string(checkNode->Dval_) + "] -> ";
        }

        else 
        {
            result += "[" + checkNode->key_ + ": " + to_string(checkNode->Ival_) + "] -> ";
        }
    }

    if (!result.empty()) 
    {
        result = result.substr(0, result.size() - 4);
    }

    return result;
    }
