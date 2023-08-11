#include <functional>
#include <iostream>
#include <math.h>
#include "linked_list.hpp"

class HashF
{
    private:
    LinkedList * arr;
    int size = 400;
    int hashNumber = 0;

    int  a, b, p;

    int randomNumber(int min, int max)
    {
        srand((unsigned) time(NULL));    
        return min + (rand() % (max - min));
    }

    void calcConsts()
    {
        int choice = size;
        if(choice % 2)
            choice--;

        while(choice+=2,true)
        {
            int root = sqrt(size);
            
            bool val = false;

            for(int i = 3; i < root; i+= 2)
            {
                if(choice % i == 0)
                {
                    val = true;
                    break;
                }
            }

            if (val)
                continue;

            p = choice;

            a = randomNumber(1, p);
            b = randomNumber(0, p);

            break;
        }
    }

    int multiplication(int key)
    {
        float a = 0.6180339887; // constante fracionaria
        float val = key * a;
        val -= (int) val;
        return size * val;
    }
    
    int division(int key)
    {
        return (key & 0x7FFFFFFF) % size;
    }

    int fold(int key)
    {
        int k = 5;

        int parte1 = key >> k,
            parte2 = key & (size - 1);

        return parte1 ^ parte2;
    }

    int universal(int key)
    {
        return ((a*key + b) % p) % size;
        // return 1;
    }

    std::function<int(int)> hashMethods[4] = { 
            [this](int key) { return multiplication(key); }, 
            [this](int key) { return division(key); }, 
            [this](int key) { return division(key); }, 
            [this](int key) { return division(key); }
        };

    public:

    Hash()
    {
        arr = new LinkedList[size];

        calcConsts();
    }

    Hash(int size)
    {
        this->size = size;
        arr = new LinkedList[size];
        calcConsts(); 
    }
    
    void insert(int key, int value)
    {
        int pos = hashMethods[hashNumber](key);

        arr[pos].addElement(key, value);
    }

    int find(int key)
    {
        int pos = hashMethods[hashNumber](key);

        return arr->findValue(key);
    }       

    ~Hash()
    {
        delete[] arr;
    }

    std::string toString()
    {
        std::string str = "";
        for(int i = 0; i < size; i++)
            str += arr[i].toString();
           
        return str;
    }
     

};

class HashA
{
    private:
    LinkedList * arr;
    int size = 400;
    int hashNumber = 0;

    int  a, b, p;

    int randomNumber(int min, int max)
    {
        srand((unsigned) time(NULL));    
        return min + (rand() % (max - min));
    }

    void calcConsts()
    {
        int choice = size;
        if(choice % 2)
            choice--;

        while(choice+=2,true)
        {
            int root = sqrt(size);
            
            bool val = false;

            for(int i = 3; i < root; i+= 2)
            {
                if(choice % i == 0)
                {
                    val = true;
                    break;
                }
            }

            if (val)
                continue;

            p = choice;

            a = randomNumber(1, p);
            b = randomNumber(0, p);

            break;
        }
    }

    int multiplication(int key)
    {
        float a = 0.6180339887; // constante fracionaria
        float val = key * a;
        val -= (int) val;
        return size * val;
    }
    
    int division(int key)
    {
        return (key & 0x7FFFFFFF) % size;
    }

    int fold(int key)
    {
        int k = 5;

        int parte1 = key >> k,
            parte2 = key & (size - 1);

        return parte1 ^ parte2;
    }

    int universal(int key)
    {
        return ((a*key + b) % p) % size;
        // return 1;
    }

    std::function<int(int)> hashMethods[4] = { 
            [this](int key) { return multiplication(key); }, 
            [this](int key) { return division(key); }, 
            [this](int key) { return division(key); }, 
            [this](int key) { return division(key); }
        };

    public:

    Hash()
    {
        arr = new LinkedList[size];

        calcConsts();
    }

    Hash(int size)
    {
        this->size = size;
        arr = new LinkedList[size];
        calcConsts(); 
    }
    
    void insert(int key, int value)
    {
        int pos = hashMethods[hashNumber](key);

        arr[pos].addElement(key, value);
    }

    int find(int key)
    {
        int pos = hashMethods[hashNumber](key);

        return arr->findValue(key);
    }       

    ~Hash()
    {
        delete[] arr;
    }

    std::string toString()
    {
        std::string str = "";
        for(int i = 0; i < size; i++)
            str += arr[i].toString();
           
        return str;
    }
     

};


int main()
{
    Hash h(40);

    for (int i = 0; i < 35; i++)
    {
        h.insert(i , i + 12);
        std::cout << h.toString() << "\n=======================\n";
    }   
    

    auto op1 = [](std::string& data) {
    // process data
    return true;
    };

    
    int i = 0;

    std::string str = "";

    std::cout << str;


    return 0;
}