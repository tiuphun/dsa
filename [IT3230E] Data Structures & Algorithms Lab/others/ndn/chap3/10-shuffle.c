#include <stdio.h>
typedef struct Node
{
    int info;
    struct Node* next;
}Node;
Node* list; //pointer to head

void traverse(Node* head){
    Node* cur;
    for(cur = head; cur != NULL; cur = cur->next) printf("%d ", cur->info);
}

void Shuffle(Node* list){
    int position = 0;
    Node* newHead;
    for(Node* cur = list; cur != NULL; cur = cur->next){
        Node* tmp = cur; //alternative pointer for cur to be kept running forward in original list rather than being updated
        position++;
        if (position == 2) {
            Node* prev = list;
            prev->next = tmp->next;
            tmp->next = list; 
            newHead = tmp;
            cur = list;
        }
        else if (position % 2 == 0){
            Node* prev = list;
            while (prev->next != tmp) prev = prev->next;
            prev->next = tmp->next;
            cur = prev;
            prev = newHead;
            while (prev->next != list) prev = prev->next;
            prev->next = tmp;
            tmp->next = list;
        };
    }
    traverse(newHead);
}
/* NOTES:
    Tớ tự nghĩ ra cơ mà rắc rối phết đấy. Phải vẽ sơ đồ ra mới hình dung được. Chú ý mấy cái:
    1. newHead là con trỏ tới phần tử đầu tiên của danh sách mới. Tức là phần tử thứ hai của danh sách gốc đấy.
    2. Tớ đặt ra con trỏ cur là để chạy theo danh sách cũ, nhưng vì sau mỗi lần đảo các phần tử cur vốn trỏ tới không còn ở chỗ cũ nữa, 
    nên để chính xác (cur = cur->next) thì phải chú ý update lại cur vào vị trí của danh sách cũ.
    3. Con trỏ tmp để phục vụ việc không xào bác cur lên khiến cho mọi thứ hỏng bét.
    4. Phải implement mới biết đúng hay sai nhé. Chậc, bài khoai v...
*/