template <typename T>
class Node
{
  public:
    T item;
    Node<T> *next;

    Node() : item(0), next(nullptr){};
    Node(T value) : item(value), next(nullptr){};
};