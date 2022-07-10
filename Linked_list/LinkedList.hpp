#ifndef linkedlist_h
#define linkedlist_h

namespace GT {

    struct Node {
        Node* next; //pointer that points to the next node...
        int  value; // hold int value

        Node(int aValue) : value(aValue) {
            next = nullptr;
        }

        ~Node() { }
        Node(const Node& aCopy) { *this = aCopy; }
        Node& operator = (const Node& aCopy) {
            value = aCopy.value; 
            next = new Node(*aCopy.next);
            return *this; 
        }
    };

    class LinkedList {
    protected:
        Node* root;// points to the first Node in the list, if one exists.
        
    public:
        LinkedList() { root = nullptr; }
        LinkedList(const LinkedList& aCopy) { *this = aCopy; }
        LinkedList& operator = (const LinkedList& aCopy) { 
            root = new Node(*aCopy.root);
            return *this; 
        }
        ~LinkedList() {
            while (root) {
                auto temp = root;
                root = root->next;
                delete temp;
            }
            //delete root; 
        }

        Node* first() const { //retrieve first node in the list.
        //if LinkedList is empty, root pointer will be a nullptr, we initialized this on const
            return root;
        }

        size_t  size() {//return # of nodes in the list...

            Node* temp = root;
            int count = 0;

            while (temp!= nullptr) { // traverse
                count++;
                temp = temp->next; // update temp 
            }
            return count;
        }

        //find a Node that contains a given value
        Node* find(const int& aValue, Node* anOrigin = nullptr) {

            // in case anOrigin is not nullptr, start at specified node
            if (anOrigin != nullptr) {
                Node* temp = anOrigin; // temp is specified node
                while (temp!= nullptr) {//traverse
                    if (temp->value == aValue) {
                        //If element found return index
                        return temp; 
                    }
                    temp = temp->next; // update temp, still in while

                }
            }
            //default case
            //anOrigin == nullptr
            Node* temp = root;
            while (temp!= nullptr) {//traverse
                if (temp->value == aValue) {
                    return temp; 
                }
                temp = temp->next;
            }

            return temp; //must return a value error
            // should return the last node, which is nullptr
            // value was not found 
        }
        // append node at the end 
        Node* append(const int& aValue) {
            Node* newNode = new Node(aValue);// allocated newNode
            newNode->value = aValue;
            newNode->next = nullptr;

            // check if linked list is empty
            if (root == nullptr) {
                root = newNode; // first node, last node, the only node
                return root;

            }
            // if linked list is not empty
            // find the last node first
            Node* temp = root;
            while (temp->next!= nullptr) {//traverse
                temp = temp->next;
            }
            //why we must do next in the while? we want to find the last node, not the nullptr

            temp->next = newNode; // make that last node a new node
            return newNode;
            delete newNode; 

        }

        Node* insertAfter(const int& aValue, Node* anOrigin = nullptr) {
            Node* newNode = new Node(aValue);
            newNode->value = aValue;
            newNode->next = nullptr; 

            // if Node *anOrigin = nullptr then insert new item in front of list
            if (anOrigin == nullptr) {
                newNode->next = root;
                root = newNode;
            }

            //insert after
            else {
                newNode->next = anOrigin->next;
                anOrigin->next = newNode;
            }

            return newNode;
            delete newNode; 
        }

        Node* remove(const int& aValue) {

            Node* temp = root;
            Node* prev = nullptr;
            Node* holdvalue = find(aValue);
            

            if (holdvalue == temp) {
                root = temp->next; 
                temp->next = nullptr; 
                return temp; 
            }

            // if item not in list, find should return null
            //by default just search, remember to made connection before unlinking
            
            while (temp != nullptr && temp!=holdvalue)
            {
                prev = temp;
                temp = temp->next;
            }

            // Unlink the node from linked list
            prev->next = temp->next;

            temp->next = nullptr;
            return temp; 
        }

    };

    ///////Outside of class but under namespace

} // end of namespace 

#endif /*linkedlist_h*/
