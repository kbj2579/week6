#ifndef CACHE_H
#define CACHE_H

#include <string>

#define CACHE_SIZE 10

using namespace std;
class Cache {
private:
  // TODO: private inner struct/class 선언 가능
  // TODO: private 멤버 변수와 함수 추가 가능
  class Node{
      private:

      public:
        int Ival_;
        double Dval_;
        bool isDouble = true;
        string key_;
        Node* prev;
        Node* next;
      
        friend class DoubleLinkedList;
        Node(string key, int i){
          key_ = key;
          Ival_ = i;
          Dval_ = i;
          next = nullptr;
          isDouble = false;
        };
        Node(string key, double d){
          key_ = key;
          Ival_ = d;
          Dval_ = d;
          next = nullptr;
          isDouble = true;
        };
    
    };
    class DoubleLinkedList{
      public:
        int size;
        Node* head = NULL;
        Node* tail = NULL;
        DoubleLinkedList();
        friend class Node;
    };

    int hashFunc(string key);
    int hashSize = 100;
    Node** hashTable;
    DoubleLinkedList* list;

public:
  Cache();
  ~Cache();
  // int를 cache에 추가한다
  void add(std::string key, int value);
  // double을 cache에 추가한다
  void add(std::string key, double value);
  // key에 해당하는 value를 cache에서 가져온다
  // 타입과 key가 동일한 원소가 없다면 false를 반환한다.
  bool get(std::string key, int &value);
  // key에 해당하는 value를 cache에서 가져온다.
  // 타입과 key가 동일한 원소가 없다면 false를 반환한다.
  bool get(std::string key, double &value);

  // 디버그 및 채점 용: 연결 리스트를 문자열로 표현하여 반환한다
  // 다음과 같이 표현된 문자열을 반환한다
  // [key1: value1] -> [key2: value2] -> ... -> [keyN: valueN]
  std::string toString();
};

#endif