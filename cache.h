#ifndef CACHE_H
#define CACHE_H

#include <string>

#define CACHE_SIZE 10

class Cache {
private:
  // TODO: private inner struct/class 선언 가능
  // TODO: private 멤버 변수와 함수 추가 가능
  int Ival;
  double Dval;
  int size;
  
  class Hash {
    pritvate:
      int hashSize = 100;
      Cache* hashTable = new Cache[hashSize];
    public:  
      int hashFunc();

  }
  class Node{
    public:
      string key_;
      double val;
      Node* next;
      Node(double d):val(d), next(NULL){}
      double& getVal(){
        return val;
      }
      Node* getNext(){
        return next;
      }
      void setNext(Node* node){
        next = node;
      }
  };
  class LinkedList{
    public:
      Node* nodes; //pointing to the first node
      int size;
      LinkedList():size(0),nodes(NULL){};
      void insert(double);
      void printList();
  };
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