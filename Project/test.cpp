#include <iostream>
using namespace std;

// tools class
class tool
{
public:
    int toolID;
    string toolName;
    int price;
    int quantity;

    tool()
    {
    }

    tool(int id, string name, int p, int q)
    {
        toolID = id;
        toolName = name;
        price = p;
        quantity = q;
    }
};

// linked list for tools
class NodeTool
{
public:
    tool val;
    NodeTool *Next;

    NodeTool(tool v)
    {
        val = v;
        Next = NULL;
    }
};

class toolList
{
public:
    void insertAtTail(NodeTool *&head, tool value)
    {
        NodeTool *newNodeTool = new NodeTool(value);
        if (head == NULL)
        {
            head = newNodeTool;
            return;
        }
        NodeTool *temp = head;
        while (temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = newNodeTool;
    }
};

// customers class
class customer
{
public:
    string customerName;
    string phone;

    customer()
    {
    }
    customer(string name, string ph)
    {
        customerName = name;
        phone = ph;
    }
};

// Queue for customers
class NodeQueue
{
public:
    customer data;
    NodeQueue *Next;

    NodeQueue(customer val)
    {
        data = val;
        Next = NULL;
    }
};

class customerQueue
{
public:
    NodeQueue *front;
    NodeQueue *back;

    customerQueue()
    {
        front = NULL;
        back = NULL;
    }

    void enQueue(customer x)
    {
        NodeQueue *newNode = new NodeQueue(x);
        if (front == NULL)
        {
            front = newNode;
            back = newNode;
        }
        back->Next = newNode;
        back = newNode;
    }

    void deQueue()
    {
        if (front == NULL)
        {
            cout << "There is no customer!" << endl;
            return;
        }
        NodeQueue *toDelete = front;
        front = front->Next;
        delete toDelete;
    }

    customer peek()
    {
        if (front == NULL)
        {
            cout << "No element in Queue." << endl;
        }
        return front->data;
    }
};

// stack
class NodeStak
{
public:
    tool data;
    NodeStak *next;

    NodeStak(tool data)
    {
        this->data = data;
        next = NULL;
    }
};

// creat a stack
class toolStack
{
public:
    NodeStak *head;
    int size;

    toolStack()
    {
        head = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void push(tool x)
    {
        NodeStak *newNode = new NodeStak(x);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "No element to pop." << endl;
            return;
        }
        NodeStak *temp = head;
        head = head->next;

        delete temp;
        size--;
    }

    tool top()
    {
        if (isEmpty())
        {
            cout << "No element in stack." << endl;
            //  return;
        }
        return head->data;
    }
};

// main function

int main()
{
    cout << "\t\tShop Open!" << endl;
    cout << "\t-----------------" << endl;
    int n;

    int totalSell = 0;

    // object for toolList
    toolList TL;
    NodeTool *headtool = NULL;
    int sizeToolList = 0;

    NodeTool *tempTool = headtool;

    // object for customers
    customerQueue CQ;
    int customerQueueSize = 0;

    // object for stack
    toolStack TS;

    // allready added tools
    int P_id = 1;
    string P_name = "Ammeter";
    int P_price = 100;
    int P_quantitys = 10;
    tool t(P_id, P_name, P_price, P_quantitys);
    TL.insertAtTail(headtool, t);
    sizeToolList++;

    P_id = 2;
    P_name = "Voltmeter";
    P_price = 120;
    P_quantitys = 10;
    tool t1(P_id, P_name, P_price, P_quantitys);
    TL.insertAtTail(headtool, t1);
    sizeToolList++;

    P_id = 3;
    P_name = "Multimeter";
    P_price = 300;
    P_quantitys = 10;
    tool t3(P_id, P_name, P_price, P_quantitys);
    TL.insertAtTail(headtool, t3);
    sizeToolList++;

    P_id = 4;
    P_name = "Screwdriver";
    P_price = 50;
    P_quantitys = 10;
    tool t4(P_id, P_name, P_price, P_quantitys);
    TL.insertAtTail(headtool, t4);
    sizeToolList++;

    P_id = 5;
    P_name = "Hexagon";
    P_price = 80;
    P_quantitys = 10;
    tool t5(P_id, P_name, P_price, P_quantitys);
    TL.insertAtTail(headtool, t5);
    sizeToolList++;

    P_id = 6;
    P_name = "Tape Measure";
    P_price = 90;
    P_quantitys = 5;
    tool t6(P_id, P_name, P_price, P_quantitys);
    TL.insertAtTail(headtool, t6);
    sizeToolList++;

    P_id = 7;
    P_name = "Torpedo Level";
    P_price = 220;
    P_quantitys = 10;
    tool t7(P_id, P_name, P_price, P_quantitys);
    TL.insertAtTail(headtool, t7);
    sizeToolList++;

    P_id = 8;
    P_name = "Wire Strippers";
    P_price = 250;
    P_quantitys = 7;
    tool t8(P_id, P_name, P_price, P_quantitys);
    TL.insertAtTail(headtool, t8);
    sizeToolList++;

    P_id = 9;
    P_name = "Fish Tape";
    P_price = 100;
    P_quantitys = 5;
    tool t9(P_id, P_name, P_price, P_quantitys);
    TL.insertAtTail(headtool, t9);
    sizeToolList++;

    P_id = 10;
    P_name = "Hammer";
    P_price = 100;
    P_quantitys = 15;
    tool t10(P_id, P_name, P_price, P_quantitys);
    TL.insertAtTail(headtool, t10);
    sizeToolList++;

    bool run = true;
    while (run)
    {
        cout << "\t1. Add tools." << endl;
        cout << "\t2. Add customers." << endl;
        cout << "\t3. Display all tools." << endl;
        cout << "\t4. Display all customers." << endl;
        cout << "\t5. Make payment slip." << endl;
        cout << "\t6. Total sell." << endl;
        cout << "\t7. Exit." << endl
             << endl;

        cout << "Enter your input: ";
        cin >> n;

        if (n == 7)
            break;

        while (1)
        {
            if (n == 1)
            { // add tools
                cout << "Enter product Id: ";
                int id;
                cin >> id;
                cout << "Enter product Name: ";
                string name;
                cin >> name;
                cout << "Enter price: ";
                int price;
                cin >> price;
                cout << "Enter quantity: ";
                int qua;
                cin >> qua;

                tool t(id, name, price, qua);
                TL.insertAtTail(headtool, t);
                cout << "Tool Added Successful!";
                sizeToolList++;
                cout << endl;
                cout << "----------------------" << endl
                     << endl;
                break;
            }
            else if (n == 2)
            { // add customar
                cout << "Enter customer Name: ";
                string cName;
                cin >> cName;
                cout << "Enter customer Mobile Number: ";
                string cMobile;
                cin >> cMobile;

                customer c(cName, cMobile);
                CQ.enQueue(c);
                cout << "Customer added successful!" << endl;
                customerQueueSize++;
                cout << "--------------------------" << endl
                     << endl;
                break;
            }
            else if (n == 3)
            { // display all tools
                tempTool = headtool;
                for (int i = 1; i <= sizeToolList; i++)
                {
                    // while(headtool != NULL){

                    cout << "ID: " << tempTool->val.toolID << endl;
                    cout << "\tName: " << tempTool->val.toolName << endl;
                    cout << "\tQuantity: " << tempTool->val.quantity << endl;
                    cout << "\tPrice: " << tempTool->val.price << endl;
                    tempTool = tempTool->Next;

                    //  }
                    cout << endl;
                }
                cout << "--------------------" << endl
                     << endl;
                break;
            }
            else if (n == 4)
            { // display all customar
                if (customerQueueSize == 0)
                {
                    cout << "There is no customer for buy." << endl;
                    cout << "----------------------------" << endl
                         << endl;
                    break;
                }
                NodeQueue *temp = CQ.front;
                for (int i = 1; i <= customerQueueSize; i++)
                {

                    // while(temp != NULL){
                    cout << "Name: " << temp->data.customerName << endl;
                    cout << "Mobile: " << temp->data.phone << endl;
                    temp = temp->Next;
                    //  }
                    cout << endl;
                }
                cout << "---------------------" << endl
                     << endl;
                break;
            }
            else if (n == 5)
            { // make payment slip
                if (customerQueueSize == 0)
                {
                    cout << "There is no customer for buy." << endl;
                    cout << "----------------------------" << endl
                         << endl;
                    break;
                }

                cout << "Add Product for: " << endl;
                cout << "Name: " << CQ.peek().customerName << " Phone: " << CQ.peek().phone << endl;
                int tk = 0;
                int n;
                cout << "Enter how many product customer want to buy: ";
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                    cout << "Enter Product ID: ";
                    int pID;
                    cin >> pID;
                    tempTool = headtool;
                    for (int i = 1; i <= sizeToolList; i++)
                    {
                        if (tempTool->val.toolID == pID)
                        {
                            if (tempTool->val.quantity == 0)
                            {
                                cout << "Stock not avleble!" << endl;
                                cout << "------------------" << endl
                                     << endl;
                                break;
                            }
                            tk += tempTool->val.price;
                            tempTool->val.quantity--;
                        }
                        tempTool = tempTool->Next;
                    }
                }
                totalSell += tk;
                cout << "Name: " << CQ.peek().customerName << " Phone: " << CQ.peek().phone << endl;
                cout << "Total payable amount: " << tk << endl;
                CQ.deQueue();
                customerQueueSize--;
                cout << "------------------------" << endl
                     << endl;
                break;
            }
            else if (n == 6)
            {
                cout << "Total Sell: " << totalSell << endl;
                cout << "---------------" << endl
                     << endl;
                break;
            }
            else
            {
                cout << "Wrong input! Try Again." << endl;
                cout << "-----------------------" << endl
                     << endl;
                break;
            }
        }
    }
    return 0;
}