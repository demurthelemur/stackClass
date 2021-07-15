//
// Created by Demir Dereli on 15.07.2021.
//

#ifndef UNTITLED_STACK_H
#define UNTITLED_STACK_H

using namespace std;

template <class Object>
class Stack {
public:
    Stack();
    Stack(const Stack &rhs);
    ~Stack();
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] bool isFull() const;
    void makeEmpty();
    void pop();
    void push(const Object &x);
    Object topAndPop();
    const Object &top() const;
    const Stack &operator=(const Stack &rhs);

private:
    struct ListNode
    {
        Object   element;
        ListNode *next;

        explicit ListNode( const Object & theElement, ListNode * n = NULL )
                : element( theElement ), next( n ) { }
    };

    ListNode *topOfStack;

};

template<class Object>
Stack<Object>::Stack() {
    topOfStack = NULL;
}

template<class Object>
bool Stack<Object>::isFull() const {
    return false;
}

template<class Object>
bool Stack<Object>::isEmpty() const {
    return topOfStack == NULL;
}

template <class Object>
const Object & Stack<Object>::top( ) const
{
    if ( isEmpty( ) )
        cout << "This stack is empty" << endl;
    return topOfStack->element;
}


template <class Object>
void Stack<Object>::pop( )
{
    if ( isEmpty( ) )
        cout << "This stack is empty" << endl;
    ListNode *oldTop = topOfStack;
    topOfStack = topOfStack->next;
    delete oldTop;
}

template<class Object>
void Stack<Object>::push(const Object &x) {
    topOfStack = new ListNode( x, topOfStack );
}

template<class Object>
Object Stack<Object>::topAndPop() {
    Object topItem = top( );
    pop( );
    return topItem;
}

template<class Object>
void Stack<Object>::makeEmpty() {
    while ( ! isEmpty( ) )
        pop( );
}

template<class Object>
Stack<Object>::~Stack() {
    makeEmpty();
}

template<class Object>
const Stack<Object> &Stack<Object>::operator=(const Stack &rhs) {
    if(this != &rhs){
        makeEmpty();
        if(rhs.isEmpty()){
            return *this;
        }
        ListNode *rptr = rhs.topOfStack;
        ListNode *ptr = new ListNode(rptr->element);
        topOfStack = ptr;

        for ( rptr = rptr->next; rptr != NULL; rptr = rptr->next )
            ptr = ptr->next = new ListNode( rptr->element );

    }
    return *this;
}

template<class Object>
Stack<Object>::Stack(const Stack &rhs) {
    topOfStack = NULL;
    *this = rhs;
}


#endif //UNTITLED_STACK_H
