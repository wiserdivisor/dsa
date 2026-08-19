#include<iostream>

struct ListNode{
  int val;
  ListNode* next;
  ListNode(): val(0), next(nullptr) {}
  ListNode(int x): val(x), next(nullptr) {}
  ListNode(int x, ListNode* next): val(x), next(next) {}
};

int main(){

  ListNode* l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
  ListNode* l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
//  ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
//  ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

  int co = 0;
  ListNode* fnode = new ListNode();
  ListNode* ans = fnode;
  while(l1 || l2 || co){
    int sumval=0;
    if(l1){
      sumval += l1->val;
      l1 = l1->next;
    }
    if(l2){
      sumval += l2->val;
      l2 = l2->next;
    }
    sumval += co;
    ans->next = new ListNode(sumval % 10);
    co = sumval / 10;
    ans = ans->next;
  }

  ListNode* node = fnode->next;
  std::cout<<"\n";
  while(node!=nullptr){
    std::cout<<node->val;
    node = node->next;
  }
  std::cout<<"\n";

  return 0;
}
