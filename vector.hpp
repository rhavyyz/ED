#pragma once

#include <malloc.h>

template<typename T>
class vector
{
    private:
        T * arr;
        int maxSize, currentIndex;

        void alloc_more()
        {
            maxSize += 12;
            arr = (T*) realloc((void *) arr, maxSize );
        }

    public:

        vector()
        {
            arr = (T*) malloc(sizeof(T) * 5);
            maxSize = 5;
            currentIndex = 0;
        }

        vector(int size)
        {
            arr = malloc(sizeof(T) * size);
            maxSize = size;
            currentIndex = size;
        }

        void push_back(T el)
        {
            if(currentIndex == maxSize)
                alloc_more();

            arr[currentIndex++] = el;
        }

        T pop_back()
        {
            currentIndex--;
            if(currentIndex < 0)
                throw "vetor vazio";

            return arr[currentIndex];
        }

        T front()
        {
            if(currentIndex == 0)
                throw "vetor vazio";
            return arr[0];
        }

        T back()
        {
            if(currentIndex == 0)
                throw "vetor vazio";
            return arr[currentIndex - 1];
        }

        T& operator [] (int index)
        {
            if(index < 0 || index >= currentIndex)
                throw "Posicao invalida do vetor";

            return arr[index];
        }
        
        int size()
        {
            return currentIndex;
        }
};