#pragma once

template <typename Type>
class darray {
public:
	darray(int numElem);
	darray()
	{
		data = nullptr;
		size = 0;
		capacity = 0;
		elem = 0;
	}
	
	~darray()
	{
		if (!data) //data != nullptr
		{
			delete[] data;
		}
	}

	void push_back(Type element);
	void print() const
	{
		for (int i = 0; i < elem; i++)
		{
			std::cout << *(data + i) << " ";
		}
	}
private:
	Type* data;
	int size;
	int elem;
	int capacity;
};

//klasa szablonowa tylko w pliku .h
template<typename Type>
darray<Type>::darray(int numElem)
{
	data = new Type[numElem];
	size = numElem;
	elem = 0;
	capacity = numElem * sizeof(Type);
}

template<typename Type>
void darray<Type>::push_back(Type element)
{
	if (elem < size)
		*(data + elem) = element;
	else
	{
		size = (size+1)* 3;
		Type* newdata = new Type[size];
		capacity = size * sizeof(Type);
		for (int i = 0; i < elem; i++)
		{
			*(newdata + i) = *(data + i);
		}
		*(newdata + elem) = element;
		delete[] data;
		data = newdata;
		
	}
	elem++;
}
// #1
// utworz nieszablonowa funkcje z if - zwraca coś 
// przy jednym warunku coś jedno, w innym coś inne
// #2
// klasa szablonowa w pliku .h {BEZ WSZKAŻNIKÓW}
// #3
// klasa nie szablonowa: w dwóch plikach .h i .cpp:  
// destruktor, konstruktor(x2), pola wskażnika(dynamiczna alokacja pamięci)
// może być pole typu string
// #4
// Nad mainem szablonowa struktura vec3 iloraz wektorowy lub skalarny
// implementacja poza klasą

// podsyłamy tylko pliki .h and .cpp 