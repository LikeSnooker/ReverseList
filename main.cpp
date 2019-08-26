//
//  main.cpp
//  翻转链表
//
//  Created by 张雨 on 2019/8/21.
//  Copyright © 2019 张雨. All rights reserved.
//

#include <iostream>

struct ListNode
{
    ListNode * next_;
    int        data_;
    ListNode(int _data)
    {
        data_ = _data;
        next_ = NULL;
    }
};

typedef ListNode * List;

void appen(List _list,int _data)
{
    if(_list == NULL)
        return;
    while(_list->next_ != NULL)
    {
        _list = _list->next_;
    }
    _list->next_ = new ListNode(_data);
}


List reverse(List _lst)
{
    List next = NULL;
    List cur  = _lst;
    List last = NULL;
    while(cur != NULL)
    {
        next = cur->next_;
        cur->next_ = last;
        last = cur;
        cur  = next;
    }
    return last;
}
void printList(List _lst)
{
    while (_lst != NULL) {
        printf("%d ",_lst->data_);
        _lst = _lst->next_;
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    // insert code here...

    List lst1   = new ListNode(1);
    appen(lst1, 2);
    appen(lst1, 3);
    appen(lst1, 4);
    appen(lst1, 5);
    appen(lst1, 6);
    appen(lst1, 7);
    appen(lst1, 8);
    appen(lst1, 9);
    
    printList(lst1);
    
    lst1 = reverse(lst1);
    printList(lst1);
    
    List lst2 = new ListNode(1);
    appen(lst2, 2);
    
    printList(lst2);
    lst2 = reverse(lst2);
    printList(lst2);
    std::cout << "Hello, World!\n";
    return 0;
}
