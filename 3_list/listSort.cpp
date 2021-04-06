#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node* next;
    node(int d) : data(d), next(nullptr) {}
};

void print_list(struct node *head)
{
    while(head)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "null" << endl;
}


struct node* create_list(int n)
{
    struct node *head = nullptr;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;

        if (!head)
        {
            head = new node(d);
            continue;
        }
        struct node *new_node = new node(d);
        new_node->next = head;
        head = new_node;
    }
    return head;
}

//O(n^2)
struct node* sort_list(struct node* head)
{
    if (!head || !head->next)
        return head;

    struct node head_node(-1);
    head_node.next = head;

    struct node* p = &head_node;
    while (p->next) {
        struct node* q = p;
        int min_data = q->next->data;
        struct node* min_node_prev = p;
        // find the prev node of the min node
        while (q->next)
        {
            if (q->next->data < min_data)
            {
                min_node_prev = q;
                min_data = q->next->data;
            }
            q = q->next;
        }
        // move the min node
        if (min_node_prev != p)
        {
            struct node* min_node = min_node_prev->next;
            min_node_prev->next = min_node->next;
            min_node->next = p->next;
            p->next = min_node;
        }
        //print_list(head_node.next);
        p = p->next;
    }
    return head_node.next;
}


int main()
{
    int N;
    cin >> N;
    struct node* head = create_list(N);
    head = sort_list(head);
    print_list(head);
    return 0;
}
